.data

.text
	addi $t0, $zero, 5000		#Moves value 5000 into register $t0
	addi $t1, $zero, 5		#Moves value 5 into register $t1
	mult $t1, $t0			#Multiplys values in $t1 & $t0 and stores in register LO
	
	mflo $t1			#Moves value from LO into $t1
	#^ Use mfhi instead IF the value is too big, not sure what that means yet or what the threshold is.
	li $v0, 1			#Loads the 'Print integer' command into $v0
	add $a0, $zero, $t1		#Moves value in $t1 into $a0 to prepare to print
	syscall				#Executes command
	
					#Complete