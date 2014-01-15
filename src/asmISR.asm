BITS 32

EXTERN InterruptServiceRoutineCHandler

%macro ISR_ERROR 1
  GLOBAL _isr%1
_isr%1:
    cli
    push	byte %1
    jmp		_isrDefaultHandler
%endmacro

%macro ISR_NOERROR 1
  GLOBAL _isr%1
_isr%1:
    cli
    push	0
    push	byte %1
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
    push	esp	; push ptr of t_context struct
    call	InterruptServiceRoutineCHandler ; __stdcall
    pop		eax	; reload the original data segment descriptor
    mov		ds, ax
    mov		es, ax
    mov		fs, ax
    mov		gs, ax
    popa
    add		esp, 8 		; remove error code and ISR number
    sti
    iret
