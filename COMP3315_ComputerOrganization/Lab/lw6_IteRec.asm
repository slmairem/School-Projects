.data

.text
.globl main
	main:
	addi $t0, $0, 4 # $t0 => n=4
	addi $t1, $0, 1 # $t1 => temp=1
	addi $t2, $0, 4 # $t3 => i=n
	
	funcloop: 
	slt $t3, $t2, $0
	beq $t3, 1, tempret
	
	beq $t2, 0, tempret
	beq $t2, 1, tempret

	mul $t1, $t1, $t2 # temp *= i
	addi $t2, $t2, -2 #i=i-2
	j funcloop
	
	tempret:
	add $v0, $0, $t1
	j exit
	
	exit:
	add $a0, $0, $v0
	addi $v0, $0, 1           
	syscall
    
	addi $v0, $0, 10 #exit program
	syscall