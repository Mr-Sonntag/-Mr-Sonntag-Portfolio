.data
	num1: .word 272
	num2: .word 86
.text
	lw $t0, num1($zero)		#Load num1+$zero to register $t0
	lw $t1, num2($zero)		#Load num2+$zero to register $t1
	sub $t1, $t1, $t0		#Add register $t0 & $t1 and store into $t1

	li $v0, 1			#Loading the 'print integer' syscall to register
	add $a0, $zero, $t1		#Loads the variable in $t1 to $a0 to prepare to take action
	syscall				#Executes the 'print integer' command onto register $a0
					
					#Complete
	
	
