.data
  array1:
    .align 2
    .space 60

  array2:
    .align 2
    .space 60
    
  newLine:
  	.asciiz "\n"

.text

.globl main

main:

  li $t7, 0 # getNumbersLoop counter
  li $t2, 60 # limit of 15 numbers
  getNumbersLoop: 
    beq $t7, $t2, outGetNumbersLoop
		
    li $v0, 5
    syscall
    move $t6, $v0
		
    sw $t6, array1($t7)
		
		addi $t7, $t7, 4
		
		j getNumbersLoop
		
  	outGetNumbersLoop:


	li $t0, 0 # fisrt loop counter
  loop1:
    beq $t0, $t2, resultVariables
    
    li $s3, 0 # x = 0
		lb $t3, array1($t0)
		
		addi $t0, $t0, 4
		
		
		li $t1, 0 # second loop counter
    loop2:
      beq $t1, $t2, setNumber
      
      lb $t4, array1($t1)
      
      bgt $t3, $t4, xSum
			
      underXSumCall:
      
      addi $t1, $t1, 4
      j loop2
			
  xSum:
    addi $s3, $s3, 4
    
    j underXSumCall

  
  setNumber: # Set the number in the right position of array2
    sw $t3, array2($s3)
    
    j loop1


	resultVariables:
		li $t0, 0
		li $t1, 60
		
		j printResult
	
	printResult:  # Prints array from beginning to the end	
		beq $t0, $t1, end
		
		lw $t2, array2($t0)
		
		li $v0, 1
		move $a0, $t2
		syscall
		
		li $v0, 4 # Prints new line
		la $a0, newLine
		syscall
		
		addi $t0, $t0, 4
		
		j printResult
	
end:
	li $v0, 10
	syscall