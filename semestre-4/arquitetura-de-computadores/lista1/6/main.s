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
    call copy_string
    call print_string
    call new_line

    # 2
    call cmp_string

    cmp $0, %al
    je print_false

    movb $'T', %al
    jmp print

print_false:
    movb $'F', %al

print:
    movb $0x0e, %ah
    int $0x10
    call new_line

    # 3
    call concat_string
    lea string_concat_buffer, %bp
    movw $23, %si
    movb (%bp, %si, 1), %al
    movb $0x0e, %ah
    int $0x10
    jmp loop_final

copy_string:
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
    ret

print_string:
    movb $0x0e, %ah
    lea string_buffer, %bp
    movw $0, %si

print_string_loop:
    cmp $12, %si
    je print_string_loop_end

    movb (%bp, %si, 1), %al     # Move value at buffer index to %al
    int $0x10
    incw %si
    jmp print_string_loop

print_string_loop_end:
    ret

cmp_string:
    movw $0, %si

loop_cmp_string:
    # Check if reached final char
    cmp $12, %si
    je loop_cmp_string_true

    # Compare two chars
    lea string1, %bp
    movb (%bp, %si, 1), %al
    lea string2, %bp
    movb (%bp, %si, 1), %ah

    cmp %al, %ah
    jne loop_cmp_string_false

    # If chars are the same, continue loop
    incw %si
    jmp loop_cmp_string

loop_cmp_string_false:
    # If reached here, strings are not equal
    movb $0, %al
    ret

loop_cmp_string_true:
    # If reached here, strings are not equal
    movb $1, %ah
    ret

concat_string:
    movw $0, %si

concat_string_loop:
    cmp $12, %si
    je concat_string_loop_end

    # Read string1[%si] into %al
    lea string1, %bp
    movb (%bp, %si, 1), %al

    # Write %al into string_concat_buffer[%si]
    lea string_concat_buffer, %bp
    movb %al, (%bp, %si, 1)

    incw %si
    jmp concat_string_loop

concat_string_loop_end:
    movw $12, %di
    movw $0, %si  # Reset %si to start at the beginning of string2

concat_string_loop2:
    cmp $12, %si
    je concat_string_loop2_end

    # Read string2[%si] into %al
    lea string2, %bp
    movb (%bp, %si, 1), %al

    # Write %al at the end of string_concat_buffer
    lea string_concat_buffer, %bp
    movb %al, (%bp, %di, 1)

    incw %si
    incw %di
    jmp concat_string_loop2

concat_string_loop2_end:
    ret

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
    .asciz "Hello world$"

# String buffer for storing
string_buffer:
    .zero 12

# String buffer for concatenation
string_concat_buffer:
    .zero 24

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
