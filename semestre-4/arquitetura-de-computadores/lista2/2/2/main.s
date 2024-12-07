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
    # Serviço de posicionar o cursor 0x02
    movb $0x02, %ah
    movb $0x0, %bh

    # Coordenadas do cursor
    movb $40, %dl
    movb $12, %dh
    int $0x10
    
loop_final:
    hlt
    jmp loop_final

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
