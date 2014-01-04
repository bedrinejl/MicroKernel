BITS 32

GLOBAL _start
EXTERN kmain

    MULTIBOOT_PAGE_ALIGN    equ 1
    MULTIBOOT_MEMORY_INFO   equ 2
    MULTIBOOT_AOUT_KLUDGE   equ 10000h
    MULTIBOOT_HEADER_MAGIC  equ 1BADB002h
    MULTIBOOT_HEADER_FLAGS  equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO
    MULTIBOOT_CHECKSUM	    equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
    MULTIBOOT_BOOTLOADER_MAGIC  equ 2BADB002h

SECTION .bss
    resb 8192
_stack:

SECTION .rodata
szNoMultiboot: db 'N', 4, 'o', 4, ' ', 4, 'M', 4, 'u', 4, 'l', 4, 't', 4, 'i', 4, 'b', 4, 'o', 4, 'o', 4, 't', 4, '!', 4, 0

SECTION .text

_start:
	mov	esp, _stack
	jmp	_entry
	
ALIGN 4
_multiboot_header:
	dd	MULTIBOOT_HEADER_MAGIC
	dd	MULTIBOOT_HEADER_FLAGS
	dd	MULTIBOOT_CHECKSUM

_entry:
	cmp	eax, MULTIBOOT_BOOTLOADER_MAGIC
	je	_multibootOK
	mov	edi, 0B8000h
	mov	esi, szNoMultiboot
	mov	ecx, 13
	rep	movsw
	jmp	_end

_multibootOK:
	call	kmain

_end:	
	cli

_loop:	
	hlt
	jmp	_loop
