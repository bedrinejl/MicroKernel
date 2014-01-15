BITS	32

EXTERN InterruptRequestCHandler

GLOBAL RemapPIC
GLOBAL GetScanCode
GLOBAL SendEndOfInterrupt
GLOBAL outb
GLOBAL inb

%macro IRQ 2
  GLOBAL _irq%1
_irq%1:
    cli
    push	byte %2
    jmp		_irqDefaultHandler
%endmacro

IRQ	0, 32
IRQ	1, 33
IRQ	2, 34
IRQ	3, 35
IRQ	4, 36
IRQ	5, 37
IRQ	6, 38
IRQ	7, 39
IRQ	8, 40
IRQ	9, 41
IRQ	10, 42
IRQ	11, 43
IRQ	12, 44
IRQ	13, 45
IRQ	14, 46
IRQ	15, 47

_irqDefaultHandler:
    pusha
    mov		ax, ds
    push	eax	    
    mov		ax, 10h	; load the kernel data segmment descriptor
    mov		ds, ax
    mov		es, ax
    mov		fs, ax
    mov		gs, ax
    push	esp	; push ptr of t_context struct
    call	InterruptRequestCHandler ; __stdcall
    pop		eax	; reload the original data segment descriptor
    mov		ds, ax
    mov		es, ax
    mov		fs, ax
    mov		gs, ax
    popa
    add		esp, 4 		; remove IRQ number
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
    in		al, PIC1_DATA	;
    mov		ah, al		;
    in		al, PIC2_DATA	;
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

; VOID __fastcall SendEndOfInterrupt(DWORD dwIRQ)
SendEndOfInterrupt:
    ; ecx = dwIRQ
    mov		al, PIC_EOI
    cmp		ecx, 8
    jb		.pic1
    out		PIC2_COMMAND, al
.pic1:
    out		PIC1_COMMAND, al
    ret

;  VOID __fastcall outb(BYTE btValue, WORD wPort)
outb:
    ; ecx=btValue, edx=wPort
    mov		al, cl
    out		dx, al
    ret

; BYTE __fastcall inb(WORD wPort)
inb:
    xor		eax, eax
    mov		dx, cx
    in		al, dx
    ret

KEYBOARD_COMMAND	equ 64h
KEYBOARD_DATA		equ 60h
KEYBOARD_IS_BUFFER_FULL	equ 1
	
; BYTE __fastcall GetScanCode(void) 
GetScanCode:
    xor		eax, eax
    mov		dx, KEYBOARD_COMMAND
.loop:
    in		al, dx
    test	al, KEYBOARD_IS_BUFFER_FULL
    jz		.loop
    mov		dx, KEYBOARD_DATA
    in		al, dx
    ret
