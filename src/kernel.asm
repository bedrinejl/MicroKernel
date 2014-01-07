BITS 32

EXTERN kmain

GLOBAL _start
GLOBAL gdtFlush
GLOBAL EnablePaging

MULTIBOOT_PAGE_ALIGN		equ 1
MULTIBOOT_MEMORY_INFO		equ 2
MULTIBOOT_AOUT_KLUDGE		equ 10000h
MULTIBOOT_HEADER_MAGIC		equ 1BADB002h
MULTIBOOT_HEADER_FLAGS		equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO
MULTIBOOT_CHECKSUM		equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
MULTIBOOT_BOOTLOADER_MAGIC	equ 2BADB002h

KERNEL_STACK_SIZE		equ 8192

SECTION .text

ALIGN 4
multiboot_header:
    dd		MULTIBOOT_HEADER_MAGIC
    dd		MULTIBOOT_HEADER_FLAGS
    dd		MULTIBOOT_CHECKSUM

_start:
    cmp		eax, MULTIBOOT_BOOTLOADER_MAGIC
	je 	.next
    je		.multibootOK	
    mov		edi, 0B8000h
    mov		esi, szNoMultiboot
    mov		ecx, 13
    rep		movsw
    jmp		.end

.multibootOK:
    lgdt	[gdtdesc]
    mov		ax, 10h
    mov		ds, ax
    mov		es, ax
    mov		fs, ax
    mov		gs, ax
    mov		ss, ax
    jmp		0x08:.next

.next:
    mov		esp, _stack
    call	kmain

.end:
    cli
    hlt
    jmp		$

; cf gdt.h
; void __fastcall gdtFlush(t_gdtdesc *pdesc)
gdtFlush:
    lgdt	[ecx] ; pdesc
    mov		ax, 10h
    mov		ds, ax
    mov		es, ax
    mov		fs, ax
    mov		gs, ax
    mov		ss, ax
    jmp		0x08:.flush
.flush:
    ret

; cf paging.c
; VOID __fastcall EnablePaging(VOID)
EnablePaging:
    xor		eax, eax
    mov		cr3, eax
    mov		eax, cr0
    or		eax, 80000000h
    mov		cr0, eax
    ret










SECTION .bss
ALIGN 16
    resb KERNEL_STACK_SIZE
_stack:

SECTION .rodata
szNoMultiboot: db 'N', 4, 'o', 4, ' ', 4, 'M', 4, 'u', 4, 'l', 4, 't', 4, 'i', 4, 'b', 4, 'o', 4, 'o', 4, 't', 4, '!', 4, 0

SECTION .ldr
gdtdesc:
	dw gdt_end - gdt - 1
	dd gdt

gdt:
	dd 0, 0
	db 0xFF, 0xFF, 0, 0, 0, 10011010b, 11001111b, 0x40 ; code selector 0x08: base 0x40000000, limit 0xFFFFFFFF, type 0x9A, granularity 0xCF
	db 0xFF, 0xFF, 0, 0, 0, 10010010b, 11001111b, 0x40 ; code selector 0x10: base 0x40000000, limit 0xFFFFFFFF, type 0x92, granularity 0xCF
gdt_end:


