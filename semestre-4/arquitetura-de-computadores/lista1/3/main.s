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
    movb $1, %cl        # Inicia contador com 1

loop:
    cmp $10, %cl        # Verifica se chegou em 10 e sai, ou incrementa o contador
    je loop_end
    incb %cl

loop_end:
    # 2
    movw $32521, %ax    # Valor a verificar se é par ou ímpar
    call is_even
    jmp exer_3

is_even:
    mov $2, %bx
    div %bx             # Divide ax por 2; se "ah" for 1, é ímpar; se 0, par
    ret

exer_3:
    # 3
    movb $0, %bl
    cmp $0, %bl
    jg loop_final
    jl loop_final
    jne loop_final

    # Nenhum dos jumps condicionais acima foram realizados, então a próxima instrução é executada
    movb $0x9, %al

loop_final:
    hlt
    jmp loop_final

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
