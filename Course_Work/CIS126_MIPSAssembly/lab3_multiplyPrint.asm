.data
 
.text
	addi $t0, $zero, 13		#Moves a constant value 13 into register $t0
	addi $t1, $zero, 11		#Moves a constant value 11 into register $t1
	mul $t1, $t1, $t0		#Multiplys value in $t0 & $t1 and stores in $t1
	#^ This instruction only can multiply integers thats product is up to 32 bits. 
	li $v0, 1			#Loads the 'print integer' command into $v0
	add $a0, $zero, $t1		#Moves value in $t1 into register $a0 to get ready to print
	syscall				#Executes command
	
					#Complete