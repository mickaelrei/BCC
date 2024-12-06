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
    movb (value), %bl   # Move o valor do label "value" para o bl

    # 2
    movb $0x7, (value)  # Move um novo valor para o endereço label "value"

    # 3
    movb $0, %cl        # Contador do loop
    movw $0, %ax        # Soma dos valores do array
    movw $array, %si     # "si" contém o endereço do índice atual na memória

loop_sum:
    cmp $5, %cl         # Se "cl" chegou a 5, acabou o loop
    je loop_end
    addb (%si), %al     # Adiciona o valor na posição atual à soma total
    incb %cl            # Incrementa o contador
    inc %si             # Incrementa o endereço do índice
    jmp loop_sum

loop_end:
    # Print value of "al"
    movb $0x0e, %ah
    addb $0x30, %al
    int $0x10

loop_final:
    hlt
    jmp loop_final

# Single value
. = _start + 400
value:
    .byte 0x9

# Array of 5 numbers
array:
    .byte 0x1
    .byte 0x2
    .byte 0x3
    .byte 0x2
    .byte 0x1


# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
