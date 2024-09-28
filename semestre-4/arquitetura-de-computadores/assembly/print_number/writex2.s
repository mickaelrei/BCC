# Generate 16-bit code
.code16

# Executable code location
.text

# Make symbol visible to linker
.globl _start

# Entry point
_start:
    # Initial value for ax (hardcoded for testing)
    mov $57, %ax

    # Call print num
    call print_num

    # End label
    jmp loop_final

# This function will print the 16-bit sized value saved in %ax register
print_num:
    # Move ax to bx to avoid losing data when setting al and ah to output characters
    mov %ax, %bx

    # Clear dx which will be used as remainder
    mov $0, %dx

# div_algo:
    # Divide %bx by 10 if it's not zero
    cmp $0, %bx
    je print_pass

    # Divide value in %bx by 10
    mov %bx, %ax       # Load numerator in %ax
    mov $10, %cx       # Load denominator (in this case always 10) in %cx
    div %cx            # Divide %ax by %cx

    # NOTE: Quotient is in %ax, remainder is in %dx

    # Return quotient to %bx
    mov %ax, %bx

print_pass:
    # Move remainder to cl for printing
    movb %dl, %cl

    # Print digit in cl
    call print_digit

    # If quotient is not zero, go back to div_algo
    # cmp $0, %bx
    # jne div_algo






    # Divide %bx by 10 if it's not zero
    cmp $0, %bx
    je print_pass_2

    # Divide value in %bx by 10
    mov %bx, %ax       # Load numerator in %ax
    mov $10, %cx       # Load denominator (in this case always 10) in %cx
    div %cx            # Divide %ax by %cx

    # NOTE: Quotient is in %ax, remainder is in %dx

    # Return quotient to %bx
    mov %ax, %bx

print_pass_2:
    # Move remainder to cl for printing
    movb %dl, %cl

    # Print digit in cl
    call print_digit








    # Return
    ret

# This function will print the digit stored in %cl
print_digit:
    # Move value to al to print
    movb %cl, %al

    # Add 0x30 so that zero outputs the '0' char
    addb $0x30, %al

    # Instruct to output a character
    movb $0x0e, %ah

    # Output character interrupt
    int $0x10

    # Return
    ret

loop_final:
    # Keep halting
    hlt
    jmp loop_final

# this line will move the current location to counter to the 510th byte
# counting from 0
. = _start + 510

# this program will be loaded by BIOS. This code will be loaded at position
# 0x7c00, in order to this program be recognized as a MBR signature it will
# be necessary to have two bytes at 510 and 511 position with values 0x55 and
# 0xaa

# MBR boot signature
.byte 0x55
.byte 0xaa
