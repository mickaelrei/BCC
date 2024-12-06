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
    push $3        # Pushes number into stack as an argument
    call factorial

    # 2
    call bubble_sort

    jmp loop_final

# Calculates and returns factorial of a number
factorial:
    push %bp                # Save old base pointer
    mov %sp, %bp            # Use current stack pointer as new base pointer

    # bp + 0 = old base pointer
    # bp + 2 = return address
    # bp + 4 = parameter
    mov 4(%bp), %bx         # Get parameter into ax
    movw $1, %ax            # Result starts as 1

loop_factorial:
    cmp $0, %bx             # Check if bx reached zero
    je loop_factorial_end
    mul %bl                 # Multiply al by bl and decrement it
    decb %bl
    jmp loop_factorial

loop_factorial_end:
    pop %bp                 # Restore old base pointer
    ret                     # Return popping the extra 2 bytes of the arguments

# Sorts the array at label (array)
bubble_sort:
    movw $0, %cx

bubble_sort_loop_1:
    cmp $5, %ch             # Check if outer loop finished
    je bubble_sort_end
    movb $0, %cl

bubble_sort_loop_2:
    movb $4, %dh            # Check if inner loop finished
    subb %ch, %dh
    cmp %cl, %dh
    je bubble_sort_loop_2_end

    # Check if needs to swap
    lea array, %bp            # Loads array pointer in bp
    movw $0, %dx
    mov %cl, %dl
    mov %dx, %si              # Load value (cl) into si and (cl + 1) into di
    inc %dx
    mov %dx, %di

    # Load into registers and compare
    mov (%bp, %si, 1), %al
    mov (%bp, %di, 1), %ah
    cmp %al, %ah
    jge bubble_sort_loop_2_noswap
    mov %ah, (%bp, %si, 1)
    mov %al, (%bp, %di, 1)

bubble_sort_loop_2_noswap:
    incb %cl
    jmp bubble_sort_loop_2

bubble_sort_loop_2_end:
    incb %ch
    jmp bubble_sort_loop_1

bubble_sort_end:
    ret

loop_final:
    hlt
    jmp loop_final

# Defines array
array:
    .byte 0x2
    .byte 0x3
    .byte 0x1
    .byte 0x5
    .byte 0x4

# MBR boot signature
. = _start + 510
.byte 0x55
.byte 0xaa
