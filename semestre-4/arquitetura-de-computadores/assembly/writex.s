# Generate 16-bit code
.code16

# Executable code location
.text

# Make symbol visible to linker
.globl _start

# Entry point
_start:
    # Start bx with 0
    mov $100, %bx

    # New line before start
    call print_newline

for:
    # Increment bx and check if it hit end
    inc %bx
    cmp $561, %bx
    je for_end

    # Save value of bx
    push %bx

    # Move bx to ax to print it
    mov %bx, %ax

    # Call print num
    call print_num

    # Print space
    movb $' ', %al
    movb $0x0e, %ah
    int $0x10

    # Retrieve last value of bx
    pop %bx

    # Go back to loop start
    jmp for

for_end:
    # End label
    jmp loop_final

# This function will print the 16-bit sized value saved in %ax register
print_num:
    # Move ax to bx to avoid losing data when setting al and ah to output characters
    mov %ax, %bx

div_algo:
    # Clear dx which will be used as remainder
    mov $0, %dx

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
    # Push value of dx into stack to keep original value after
    # rewrite on next recursion call
    push %dx

    # If quotient is not zero, go back to div_algo
    cmp $0, %bx
    je skip_recursion

    call div_algo

skip_recursion:
    # Get value from stack back again
    pop %dx

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

print_newline:
    # New line
    movb $'\n', %al
    movb $0x0e, %ah
    int $0x10
    
    # Carry return
    movb $'\r', %al
    movb $0x0e, %ah
    int $0x10

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
