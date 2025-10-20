.data
	prompt: .asciiz "Please enter your first number (WARNING: You MUST enter a WHOLE POSITIVE number):  "
	prompt2: .asciiz "\nPlease enter your second number (WARNING: You MUST enter a WHOLE POSITIVE number): "
	
	addition: .asciiz " + "
	subtraction: .asciiz " - "
	equal: .asciiz " = "
	
	whenAdd: .asciiz "\nWhen you add both your numbers together you get: "
	whenSub: .asciiz "\nWhen you subtract the smallest from the largest you get: "
	whenSummation: .asciiz "\nThe summation of the subtraction result is: "
.text

	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	
	move $s0, $v0
	
	li $v0, 4
	la $a0, prompt2
	syscall
	
	li $v0, 5
	syscall
	
	move $s1, $v0
	
	li $v0, 4
	la $a0, whenAdd
	syscall
	
	slt $s2, $s0, $s1
	
	beq $s2, $zero, Else
	
		li $v0, 1
		addi $a0, $s0, 0
		syscall
		
		li $v0, 4
		la $a0, addition
		syscall
		
		li $v0, 1
		addi $a0, $s1, 0
		syscall
		
		li $v0, 4
		la $a0, equal
		syscall
		
		li $v0, 1
		add $a0, $s0, $s1
		syscall
		
		j Exit
Else:
	
		li $v0, 1
		addi $a0, $s1, 0
		syscall
		
		li $v0, 4
		la $a0, addition
		syscall
		
		li $v0, 1
		addi $a0, $s0, 0
		syscall
		
		li $v0, 4
		la $a0, equal
		syscall
		
		li $v0, 1
		add $a0, $s0, $s1
		syscall
		
Exit: 

	li $v0, 4
	la $a0, whenSub
	syscall
	
	beq $s2, $zero, Else1
		
		li $v0, 1
		addi $a0, $s1, 0
		syscall
		
		li $v0, 4
		la $a0, subtraction
		syscall
		
		li $v0, 1
		addi $a0, $s0, 0
		syscall
		
		li $v0, 4
		la $a0, equal
		syscall
		
		sub $s3, $s1, $s0
		
		li $v0, 1
		addi $a0, $s3, 0
		syscall
		
		j Exit1

Else1:
		li $v0, 1
		addi $a0, $s0, 0
		syscall
		
		li $v0, 4
		la $a0, subtraction
		syscall
		
		li $v0, 1
		addi $a0, $s1, 0
		syscall
		
		li $v0, 4
		la $a0, equal
		syscall
		
		sub $s3, $s0, $s1
		
		li $v0, 1
		addi $a0, $s3, 0
		syscall
		
Exit1:

	li $v0, 4
	la $a0, whenSummation
	syscall
	
	addi $s5, $zero, 1
	
LOOP: 	beq $s5, $s3, DONE

	add $s6, $s5, $s6
	
	li $v0, 1
	move $a0, $s5
	syscall
	
	li $v0, 4
	la $a0, addition
	syscall
	
	addi $s5, $s5, 1
	
	j LOOP

DONE:
	
	li $v0, 1
	addi $a0, $s5, 0
	syscall
	
	li $v0, 4
	la $a0, equal
	syscall
	
	li $v0, 1
	add $a0, $s6, $s5
	syscall