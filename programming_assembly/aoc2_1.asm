.text
  loopCounter: .word 0
  loopIterations: .word 6
  positiveCounter: .word 0

.globl main

main:
  lw $t0, loopCounter
  lw $t1, loopIterations
  lw $t2, positiveCounter
  
  loop:
    beq $t0, $t1, end  #-- Check loop condition 
    addi $t0, 1  #-- Add 1 to loop counter
    
    li $v0, 5 # Receives a number
    syscall
    move $t3, $v0
    
    bgt $t3, $zero, countPositive # If it is positive go to countPositive
    
    j loop


  # Utility functions
  countPositive:
  addi $t2, 1
  j loop
  
  
end:
  li $v0, 1
  move $a0, $t2
  syscall