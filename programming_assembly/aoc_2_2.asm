.data
	evenValuesMessage: .asciiz " valor(es) par(es)"
	oddValuesMessage: .asciiz " valor(es) impar(es)"
	positiveValuesMessage: .asciiz " valor(es) positivo(s)"
	negativeValuesMessage: .asciiz " valor(es) negativo(s)"
	newLine: .asciiz "\n"

.text

.globl  main

main:
	li $t3, 0
	li $t4, 0
	li $t5, 0
	li $t6, 0
	li $t7, 0
	li $t8, 0

read:
  addi $t4, $t4, 1
  beq $t4, 6, end

continue:    
	li  $v0,5   
	syscall 
	move $t0,$v0
	bgt $t0, 0, countPositive

goPositive:   
  blt $t0, 0, countNegative
goNegative:
  andi $t6, $t0, 1
  beq $t6, 0, countOdd
goOdd:    
  beq $t6, 1, countEven
goEven:   
  j read

countEven:
  addi $t8, $t8, 1
  j goEven
    
countOdd:
  addi $t7, $t7, 1
  j goOdd
    
countNegative:
  addi $t3, $t3, 1
  j goNegative
    
countPositive:
  addi $t5, $t5, 1
  j goPositive
    
end:

printEven:    
	li $v0,1   
	move $a0, $t7
	syscall
	
	li  $v0,4
	la  $a0, evenValuesMessage    
	syscall
	
	li $v0,4
	la $a0, newLine 
	syscall

printOdd:    
	li  $v0,1   
	move $a0, $t8
	syscall
	
	li $v0,4
	la $a0, oddValuesMessage
	syscall
	
	li $v0,4
	la $a0, newLine 
	syscall
	
printPositive:    
	li $v0,1   
	move $a0, $t5
	syscall
	
	li $v0,4
	la $a0, positiveValuesMessage
	syscall
	
	li $v0,4
	la $a0, newLine 
	syscall
    
printNegative:    
	li $v0,1   
	move $a0, $t3
	syscall
	
	li $v0,4 
	la $a0, negativeValuesMessage
	syscall
	
	li $v0,4
	la $a0, newLine 
	syscall

	li $v0,10      
	syscall