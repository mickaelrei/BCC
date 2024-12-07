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
    # Serviço de rolagem de tela 0x06
    movb $0x06, %ah

    # Coordenadas da janela
    movw $0, %cx
    movb $79, %dl
    movb $24, %dh

    # Cor de fundo e texto
    movb $0x07, %bh

    movb $0, %al
    int $0x10
    
loop_final:
    hlt
    jmp loop_final

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
