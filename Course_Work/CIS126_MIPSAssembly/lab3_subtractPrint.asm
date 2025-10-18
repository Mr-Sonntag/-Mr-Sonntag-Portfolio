.data
	num1: .word 3844
	num2: .word 791
.text
	lw $t0, num1($zero)		#Loads num1 into register $t0
	lw $t1, num2($zero)		#Loads num2 into register $t1
	sub $t1, $t0, $t1		#Subtracts value in $t1 from value in $t0 and stores in $t1
	
	li $v0, 1			#Loads the 'print integer' command into $v0
	add $a0, $zero, $t1		#Moves value from $t1 to $a0 to prepare to be printed
	syscall				#Executes command
	
					#Complete