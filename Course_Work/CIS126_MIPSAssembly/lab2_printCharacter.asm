.data
	myCharacter: .byte 'P'
	mySecondCharacter: .byte 'A'
.text
	li $v0, 4
	la $a0, myCharacter
	li $v1, 4
	la $a1, mySecondCharacter
	syscall
