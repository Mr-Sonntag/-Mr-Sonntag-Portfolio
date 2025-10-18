.data
	myArray: .space 360
	newLine: .asciiz "\n"
.text

main:
	addi $s0, $zero, 1000
	addi $t0, $zero, 0
	addi $s2, $zero, 11
	
	addi $t4, $zero, 0
	addi $t5, $zero, 360
	
	FILLARRAY: 
		slt $t1, $s2, $s0
		beq $t1, $zero, PRINTARRAY
		
		sw $s2, myArray($t0)
		addi $t0, $t0, 4
		addi $s2, $s2, 11
		
		j FILLARRAY
	
	PRINTARRAY:
		sne $t1, $t4, $t5
		beq $t1, $zero, DONE
		
		lw $t6, myArray($t4)
	
		li $v0, 1
		addi $a0, $t6, 0
		syscall
		
		addi $t4, $t4, 4
		
		li $v0,4
		la $a0, newLine
		syscall
		
		j PRINTARRAY
	DONE:
	
li $v0, 10
syscall
