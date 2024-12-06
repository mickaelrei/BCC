/**
    * \author: Éder Augusto Penharbel
    * \modifier: Mickael Reichert
    * \date: February, 2022
    * \version: September 6, 2024     
**/

# generate 16-bit code
.code16
# executable code location
.text
# start point
.globl _start

# default entry
_start:
    # 1
    movw $0, %si

copy_string_loop:
    cmp $12, %si
    je copy_string_loop_end

    # Read char at string1[%si] into %al
    lea string1, %bp
    movb (%bp, %si, 1), %al

    # Store char at %al into string_buffer[%si]
    lea string_buffer, %bp
    movb %al, (%bp, %si, 1)

    incw %si
    jmp copy_string_loop

copy_string_loop_end:
    # Print whole string after reading it
    movb $0x0e, %ah
    lea string_buffer, %bp
    movw $0, %si

loop_print:
    cmp $12, %si
    je loop_print_end

    movb (%bp, %si, 1), %al     # Move value at buffer index to %al
    int $0x10
    incw %si
    jmp loop_print

loop_print_end:
    jmp loop_final

new_line:
    push %ax
    movb $0x0e, %ah
    movb $'\n', %al
    int $0x10
    movb $'\r', %al
    int $0x10
    pop %ax
    ret    

loop_final:
    hlt
    jmp loop_final

# String 1
string1:
    .asciz "Hello world!"

# String 2
string2:
    .asciz "Hello world!"

# String buffer for storing
string_buffer:
    .zero 12

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
