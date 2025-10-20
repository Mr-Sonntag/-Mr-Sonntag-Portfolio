.data
	myFloat: .float 15.4
	X: .word 20 
.text
	li $v0, 2
	lwc1 $f12, myFloat
	syscall 
	li $v0, 1
	lw $a0, X
	syscall