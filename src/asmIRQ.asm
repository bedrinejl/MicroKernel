BITS	32

EXTERN InterruptRequestCHandler

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