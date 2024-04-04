.data

.text
.globl main
	main:
	
	addi $v0, $0, 5
	syscall
	
	add $t0,$0,$v0 
	add $t1,$0,$t0 
	
	mul $t2,$t1,$t0 
	
	addi $t3,$0,7 
	addi $t4,$0,3
	addi $t5,$0,6 
	
	mul $t6,$t2,$t3 
	mul $t7,$t4,$t0 
	
	add $t0,$t6,$t7
	add $t1,$t0,$t5 
	
	addi $v0,$0,1
	add $a0 $0, $t1
	syscall
