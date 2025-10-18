.data

.text
	addi $t0, $zero, 9	#Adds all these numbers together into $t0
	addi $t0, $t0, 18
	addi $t0, $t0, 21
	addi $t0, $t0, 28
	addi $t0, $t0, 35
	
	li $v0, 1		#Print integer
	add $a0, $zero, $t0
	syscall
	
				#Complete
