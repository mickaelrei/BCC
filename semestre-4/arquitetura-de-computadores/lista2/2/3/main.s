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
    # Serviço de troca de cor 0x0b
    movb $0x0b, %ah

    # %bh define a subfunção (0 = paleta de cores, 1 = brilho do texto)
    movb $0x0, %bh

    # como %bh = 0, %bl define qual paleta (0 ou 1)
    movb $0x1, %bl

    int $0x10
    
loop_final:
    hlt
    jmp loop_final

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
