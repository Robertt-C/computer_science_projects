# Lázaro Robert da Silva Cunha. 163885
# Lucas Alves Nascimento Marques. 163911
# Marcelo de Carvalho Machado. 163934


.text
	
.globl main

main:
	 
	li $s0, 5 # 4 chances stored in $s0
	li $s1, 0 # Counts used chances
	

	addi $a1, $zero, 11 # Sets the upper bound
	addi $v0, $zero, 42 # Generates the random number between 0 and 11, not including 11
	syscall
	
	move $s2, $a0 # Stores the random number in $s2

		loop:
			# Add to chances count
			addi $s1, $s1, 1
			
			beq $s1, $s0, sadEndGame
			
			# Print tbe askForNumber string
			la $a0, askForNumber
			li $v0, 4
			syscall
			
			# Ask for number input
			li $v0, 5
			syscall
			
			# If number is correct, it goes to happyEnd
			beq $v0, $s2, happyEndGame
			
			j loop
			
			
			
			
		happyEndGame:
			la $a0, happyEndText # Prints happyEndText
			li $v0, 4
			syscall
			
			move $a0, $s2 # Prints the correct number
			li $v0, 1
			syscall
			
			li $v0, 10 # End session
			syscall
			
			
		sadEndGame:
			la $a0, sadEndText # Prints sadEndText
			li $v0, 4
			syscall
			
			move $a0, $s2 # Prints the correct number
			li $v0, 1
			syscall
			
			li $v0, 10 # End session
			syscall
			
			
.data 
	askForNumber: .asciiz "Guess a number: \n"
	happyEndText: .asciiz "You Win!!!\n The number was: \n"
	sadEndText: .asciiz "You Lose!!!\n The number was: \n"	
