.data
greaterNumber: .asciiz "Maior: "

.text
.globl main

main:

li $v0, 5
syscall
move $t0, $v0

li $v0, 5
syscall
move $t1, $v0

li $v0, 5
syscall
move $t2, $v0




move $t3, $t0




bgt $t0, $t1, compareT0T2
j compareT1T2


compareT0T2:
  bgt $t0, $t2, t0IsGreater
  move $t3, $t2
  j result

compareT1T2:
  bgt $t1, $t2, t1IsGreater
  move $t3, $t2
  j result


t0IsGreater:
  move $t3, $t0 
  j result

t1IsGreater:
  move $t3, $t1
  j result


result:
  li $v0, 4
  la $a0, greaterNumber
  syscall
  
  li $v0, 1
  move $a0, $t3
  syscall


end:
  li $v0, 10
  syscall