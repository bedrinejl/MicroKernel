BITS 32

EXTERN InterruptServiceRoutineCHandler

GLOBAL RemapPIC
	
%macro ISR_ERROR 1
  GLOBAL _isr%1
_isr%1:
    cli
    push	%1
    jmp		_isrDefaultHandler
%endmacro

%macro ISR_NOERROR 1
  GLOBAL _isr%1
_isr%1:
    cli
    push	0
    push	%1
    jmp		_isrDefaultHandler
%endmacro

ISR_NOERROR	0
ISR_NOERROR	1
ISR_NOERROR	2
ISR_NOERROR	3
ISR_NOERROR	4
ISR_NOERROR	5
ISR_NOERROR	6
ISR_NOERROR	7
ISR_ERROR	8
ISR_NOERROR	9
ISR_ERROR	10
ISR_ERROR	11
ISR_ERROR	12
ISR_ERROR	13
ISR_ERROR	14	
ISR_NOERROR	15
ISR_NOERROR	16
ISR_NOERROR	17
ISR_NOERROR	18
ISR_NOERROR	19
ISR_NOERROR	20
ISR_NOERROR	21
ISR_NOERROR	22
ISR_NOERROR	23
ISR_NOERROR	24
ISR_NOERROR	25
ISR_NOERROR	26
ISR_NOERROR	27
ISR_NOERROR	28
ISR_NOERROR	29
ISR_NOERROR	30
ISR_NOERROR	31

; void _isrDefaultHandler(void)
_isrDefaultHandler:
    pusha
    mov		ax, ds
    push	eax
    mov		ax, 10h	; load the kernel data segmment descriptor
    mov		ds, ax
    mov		es, ax
    mov		fs, ax
    mov		gs, ax
    call	InterruptServiceRoutineCHandler
    pop		eax	; reload the original data segment descriptor
    mov		ds, ax
    mov		es, ax
    mov		fs, ax
    mov		gs, ax
    popa
    add		esp, 8 		; remove error code and ISR number
    sti
    iret

PIC1		equ 20h
PIC2		equ 0A0h
PIC1_COMMAND	equ PIC1
PIC1_DATA	equ PIC1+1
PIC2_COMMAND	equ PIC2
PIC2_DATA	equ PIC2+1

PIC_EOI		equ 20h

ICW1_INIT	equ 10h
ICW1_ICW4	equ 1

ICW4_8086	equ 1

; VOID __fastcall RemapPIC(DWORD dwOffset1, DWORD dwOffset2)
RemapPIC:
; ecx=dwOffset1, edx=dwOffset2
    in		al, PIC1_DATA
    mov		ah, al
    in		al, PIC2_DATA
    push	eax	; save masks

    mov		al, ICW1_INIT + ICW1_ICW4
    out		PIC1_COMMAND, al; starts the initialization sequence (in cascade mode)
    mov		al, ICW1_INIT + ICW1_ICW4
    out		PIC2_COMMAND, al

    mov		al, cl
    out		PIC1_DATA, al	; ICW2: Master PIC vector offset
    mov		al, dl
    out		PIC2_DATA, al	; ICW2: Slave PIC vector offset
    mov		al, 4
    out		PIC1_DATA, al	; ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
    mov		al, 2
    out		PIC2_DATA, al	; ICW3: tell Slave PIC its cascade identity (0000 0010)

    mov		al, ICW4_8086
    out		PIC1_DATA, al
    out		PIC2_DATA, al

    pop		eax		; restore saved masks
    out		PIC2_DATA, al
    mov		al, ah
    out		PIC1_DATA, al
    ret
