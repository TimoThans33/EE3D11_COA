
		.data
		testArray: .word 5, 4, 3, 2, 1 		#define an array, only for testing purposes			
		.text

		
		j 	insert	
		
insert:		#begin code only used for testing
		la 	$a0, testArray 			# $a0 has the address of testArray
		addi 	$a1, $zero, 5			# let's say for now that length = 5
		addi 	$a2, $zero, 12			# elem, value of a[i] from the main
		addi 	$a3, $zero, 2			# let's say that i = 2
		#end code only used for testing					
		
		# first, lets save the to be used s registers and the return address to the stack
		addi	$sp, $sp, -4				# make room for 5 registers
		sw 	$s0, 0($sp)
		# now we can safely use these registers in this procedure.

		addi	$s0, $a1, -1			# j = length - 1
for_insert:	blt 	$s0, $a3, exit_insert		# if j<i go to exit

		#body of loop
		
		sll 	$t1, $s0, 2				# t1 = j*4
		add 	$t1, $a0, $t1			# t1 = t1 + address of array, t1 has address a[j]
		
		lw 	$t0, 0($t1)				# t4 has value of a[j]
		sw 	$t0, 4($t1)				# store t4 (a[j]) into a[j+1]
						
		#end body of loop
		
		addi	$s0, $s0, -1			# j = j-1
		j	for_insert			#jump back to start of for loop		

exit_insert:	sll 	$t2, $a3, 2			# t2 = i*4
		add 	$t2, $a0, $t2			# t2 = address of a[i]
		sw	$a2, 0($t2)			# a[i] = elem 
		
				
		# finally, before returing to caller, we restore the stack
		lw	$s0, 0($sp)
		addi 	$sp, $sp, 4				# restore stack pointer
		# now we can return to caller
				
		#jr	$ra				#jump back to calller, uncomment in main
		
		
		#begin code only for testing, not part of function
		addi	$t4, $zero, 24			# t4 holds a position that will be printed 
		lw 	$t3, testArray($t4)		# load content of array at position t4 into t6
		move	$a0, $t3 			# move to a0 to be printed
		li	$v0, 1				# print of the element a[i]
		syscall					# 
		#end code only used for testing
