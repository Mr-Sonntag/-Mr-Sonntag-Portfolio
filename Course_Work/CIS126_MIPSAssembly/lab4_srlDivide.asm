.data

.text

	addi $t0, $zero, 2000	#Loads 2000 to register $t0 using the add method
	srl $t0, $t0, 2		#Divides the value in register $t0 by 2^2 which is 4 by shifting the binary digits to the right 2 times
	
	li $v0, 1		#Loads 'Print Integer' to $v0
	add $a0, $zero, $t0	#Moves the value in $t0 to $a0 to prepare to print
	syscall 		#Executes the 'Print Integer' command
				
				#Complete