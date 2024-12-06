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
    movb $0x0, %ah
    int $0x16           # Interruption 0x16 is for keyboard input

    # Display char stored in %al
    movb $0x0e, %ah
    int $0x10
    call new_line

    # 2
    lea string_buffer, %bp      # Loads array pointer in bp
    movw $0, %cx                # Start counter at zero, read up to 14 chars

loop_read_char:
    # Check counter to exit loop
    cmp $14, %cl
    je loop_read_char_end

    # Read char 
    movb $0x0, %ah
    int $0x16

    # Store in buffer
    movw %cx, %si
    movb %al, (%bp, %si, 1)

    # Continue loop
    incb %cl
    jmp loop_read_char

loop_read_char_end:
    # Print whole string after reading it
    movb $0x0e, %ah
    lea string_buffer, %bp
    movw $0, %si

loop_print:
    cmp $14, %si
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

# Buffer for 14 chars
string_buffer:
    .zero 14

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
