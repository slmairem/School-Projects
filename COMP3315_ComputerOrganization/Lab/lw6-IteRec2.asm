.data

.text
.globl main
	main:
	addi $t0, $0, 7 # $t0 => n
	addi $t3, $0, 2
	add $a0,$0,$t0 
	
	jal func
	
	add $a0, $0, $v0
	addi $v0, $0, 1 #print	
	syscall
	
	addi $v0, $0, 10 #exit
	syscall
	
	temp:
	addi $v0, $0, 1

	jr $ra
	
	func:
	slt $t2, $a0, $t3
	beq $t2, 1, temp
	
	addi $sp, $sp, -8
  	sw $ra, 0($sp)
  	sw $a0, 4($sp)
  	
  	add $a0, $a0, -2
  	jal func
  	lw $a0, 4($sp) #non-change n
  	mul $v0, $a0, $v0
  	  	
  	lw $ra, 0($sp)
  	lw $a0, 4($sp)
  	addi $sp, $sp, 8
  	
  	jr $ra
  
	