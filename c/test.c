#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"

int main (void) {

	/* Test matrix functions are working */

	/* Test matrix initialization */
	Matrix A = create_matrix(7, 4, ROWWISE);
	
	printf("Matrix A:\n");
	show_matrix(A, " %6.2f");  
	
	printf("\n");

	/* Test matrix setters/getters */
	set_value_matrix(A, 0, 0, 1);
	set_value_matrix(A, 1, 2, 2);
	set_value_matrix(A, 5, 3, 3);
	set_value_matrix(A, 6, 3, 4);
	printf("Matrix A:\n");
	show_matrix(A, " %6.2f");

	printf("Value at 0, 0: %6.2f \n", get_value_matrix(A,0,0));
	printf("Value at 1, 2: %6.2f \n", get_value_matrix(A,1,2));
	printf("Value at 5, 3: %6.2f \n", get_value_matrix(A,5,3));
	printf("Value at 6, 3: %6.2f \n", get_value_matrix(A,6,3));

	printf("\n");

	/* Matrix coyping */
	Matrix B;
	B = create_copy_of_matrix(A);
	printf("Matrix B:\n");
	show_matrix(B, " %6.2f");
	set_value_matrix(B, 0, 0, -1.);
	printf("Setting  B[0,0] =      %6.2f\n", -1.);
	printf("Value of A[0,0] still: %6.2f \n", get_value_matrix(A,0,0));
	
	printf("\n");

	/* Test matrix destruction */
	free_matrix(&A);
	free_matrix(&B);
	printf("Matrix A:\n");
	show_matrix(A, " %6.2f");

	return  EXIT_SUCCESS;
}
/* output

Matrix A:                                                                                                               
m = 7, n = 4                                                                                                            
Rowwise Memory Ordering                                                                                                    
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                            
Matrix A:                                                                                                               
m = 7, n = 4                                                                                                            
Rowwise Memory Ordering                                                                                                    
1.00   0.00   0.00   0.00                                                                                               
0.00   0.00   2.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   0.00                                                                                               
0.00   0.00   0.00   3.00                                                                                               
0.00   0.00   0.00   4.00 
Value at 0, 0:   1.00
Value at 1, 2:   2.00
Value at 5, 3:   3.00
Value at 6, 3:   4.00                                                                                           
Matrix A:                                                                                                               
m = 0, n = 0                                                                                                            
No memory allocated!

*/

