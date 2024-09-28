# Generate 16-bit code
.code16

# Executable code location
.text

# Make symbol visible to linker
.globl _start

# Entry point
_start:
    # Initial value for ax (hardcoded for testing)
    mov $17, %ax

    # Call print ax
    call print_ax

    # End label
    jmp loop_final

# This function will print the 16-bit sized value saved in %ax register
print_ax:
    # Move ax to bx to avoid losing data when setting al and ah to output characters
    mov %ax, %bx

print_algo:
    # Check if %bx is not zero
    cmp $0, %bx

    # If zero, skip division
    jne recursion_pass

    # If greater than zero, call division
    call divide_bx

recursion_pass:
    # If %bx is not zero, go back to print_algo
    cmp $0, %bx
    jne print_pass
    call print_algo

print_pass:
    # Print digit in dl
    movb %dl, %bl
    call print_digit

    # Return
    ret

# This function will divide the value in %bx by 10 and store the quotient in %bx and remainder in %dx
divide_bx:
    # Divide value in %bx by 10
    mov %bx, %ax       # Load numerator in %ax
    mov $10, %cx       # Load denominator (in this case always 10) in %cx
    div %cx            # Divide %ax by %cx

    # NOTE: Quotient is in %ax, remainder is in %dx

    # Set quotient back to bx
    mov %ax, %bx

    ret

# This function will print the digit stored in %bl
print_digit:
    # Move value to al to print
    movb %bl, %al

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
