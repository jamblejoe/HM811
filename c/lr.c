#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"
#include "LinearSystem.h"

int main (void) {

	char fmt[] = " %6.2f";
	unsigned int n = 3;
	unsigned int i,j = 0;
	Matrix A = create_matrix(n, n, ROWWISE);
	Matrix B;
	Vector b = create_vector(n);
	Vector x;
	
	/* Initialize A */
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			set_value_matrix(A,i,j,1 + 0.5*n*i+0.1*n*j);
		}
	}

	/* Initialize b */
	for(i=0;i<n;i++){
		set_value_vector(b, i, 1);
	}
	
	/* Create a copy of A for later verification */
	B = create_copy_of_matrix(A); 

	/* Greeitng */ 
	printf("\n");
	printf("Solves a linear system Ax=b with given A and b for x. \n");
	printf("The matrix A is given by:\n");
	show_matrix(A, fmt);
	printf("\n");
	printf("The vector b is given by:\n");
	show_vector(b, fmt);
	printf("\n");
	
		

	/* LR decomposition of A */
	LR_decomposition_inplace(A);
	printf("LR decomposition of A:\n");
	show_matrix(A, fmt);
	printf("\n");

	/* Solve the linear system Ax=b */
	LR_solve_inplace(A,b);
	printf("The solution to Ax=b is: \n");
	show_vector(b, fmt);
	printf("\n");

	/* Testing solution */
	printf("Testing the solution by calculating Ax: \n");
	x = mul_matrix_vector(B, b);
	show_vector(x, fmt);
	
	

	free_matrix(&A);
	return  EXIT_SUCCESS;
}
