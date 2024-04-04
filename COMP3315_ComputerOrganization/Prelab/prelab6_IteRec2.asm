.data

.text
.globl main
	main:
	addi $t0, $0, 0 # sum = 0
	addi $t1, $0, 7 # a = 7
	addi $t2, $0, 15 # b = 15

	add $a0,$0,$t0 
	add $a1,$0,$t1
	add $a2,$0,$t2
	
	jal func
	add $t0, $0, $v0 # sum=func
	
	addi $v0, $0, 1 #print
	add $a0, $0, $t0
	syscall
	
	addi $v0, $0, 10 #exit
	syscall
	
	
  	func:
  	addi $sp, $sp, 16
  	sw $ra, 0($sp)
  	sw $a0, -4($sp)
  	sw $a1, -8($sp)
  	sw $a2, -12($sp)
  	
  	bne $a1, $a2, funequal
  	add $v0, $a1, $0
  	addi $sp, $sp, -16
  	jr $ra
  	
  	jump:
  	addi $a1, $a1, 1
  	jal func
  	
  	lw $ra, 0($sp)
  	lw $a0, -4($sp)
  	lw $a1, -8($sp)
  	lw $a2, -12($sp)
  	addi $sp, $sp, -16
  	add $v0, $v0, $a1
  	jr $ra
  	