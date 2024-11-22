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
    mov $1234, %ax
    add $2345, %ax

    # 2
    mov $250, %al
    mov $200, %ah
    mul %ah

    # 3
    mov $48, %bx
    mov $35250, %ax
    div %bx

    # 4
    and $0b10011011, %al
    xor %al, %al
    or $0b11110101, %al
    not %al
    
loop_final:
    hlt
    jmp loop_final

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
