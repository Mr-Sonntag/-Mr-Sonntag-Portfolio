.data

.text
	addi $t0, $zero, 5	#Load 5 to register $t0 byb using the add method
	sll $t0, $t0, 4		#Multiplys 5 in register $t0 by 2^4 which is 16 and stores in register $t0 by shiftinng binary digits to the left 4 times
	
	li $v0, 1		#Loads 'Print Integer' to $v0 and prepare to do so
	add $a0, $zero, $t0	#Moves the value from register $t0 to $a0 and prepare to print
	syscall			#Executes the 'Print Integer' command

				#Complete