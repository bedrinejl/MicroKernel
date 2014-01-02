# Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Allocate room for a small temporary stack as a global variable called stack.
.section .bootstrap_stack
stack_bottom:
.skip 16384 # 16 KiB
stack_top:


	
# The linker script specifies _start as the entry point to the kernel and the
# bootloader will jump to this position once the kernel has been loaded.
.section .text
.global _start
_start:
	# Set up the stack, set the esp register to point to the top of our stack 
	movl $stack_top, %esp

	# call kmain C function
	call kmain

	# Create infinite loop
	cli
hang:
	hlt
	jmp hang
	