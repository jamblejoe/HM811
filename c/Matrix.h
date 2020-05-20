#ifndef Header_Matrix
#define Header_Matrix

#include "Tuple.h"
#include "Vector.h"

/* Modelling m x n - matrices. 
 * These are essentially tuples of length m * n. 
 * Two orderings are implemented:
 * 		ROWISE
 * 		COLUMNWISE
 */

enum tmp_MatrixMemoryOrdering {ROWWISE, COLUMNWISE};
typedef enum tmp_MatrixMemoryOrdering MatrixMemoryOrdering;

struct tmp_Matrix {  
  unsigned int m;        
  unsigned int n;        
  Tuple value;   
  
  MatrixMemoryOrdering order;  
};
typedef struct tmp_Matrix Matrix;


/* Matrix constructor
 * creates a matrix of size m x n
 * all values are initialized with zero
 *
 * return: pointer
 * usage:
 * 		A = create_matrix (m, n, ROWWISE);
 * 		A = create_matrix (4, 5, COLUMNWISE);  
 *
 * memory allocated: m * n * sizeof(double)
 */
Matrix create_matrix(unsigned int, unsigned int, MatrixMemoryOrdering);  /* Level 1 function */

/* Frees the memory of the matrix
 * 
 * usage:
 * 		free_matrix(&A)
 */
void free_matrix(Matrix *); 

/* Creates a new matrix and initializes it with the values of the old
 * Matrix.
 *
 * return: new Matrix
 * usage:
 *		B = create_copy_of_matrix(A)
 */
Matrix create_copy_of_matrix(Matrix);

/* Getter and Setter functions for the entries of a Matrix.
 * An assertion error is raised if the indices are out of bounds.
 *
 * usage:
 * 		x = get_value_matrix(A, i, j)
 * 		set_value_matrix(A, i, j, x)
 */ 
double get_value_matrix(Matrix, unsigned int, unsigned int); 
void set_value_matrix(Matrix, unsigned int, unsigned int, double); 

/* Pretty printing for a Matrix.
 * fmt can be used to set how many coefficients will be printed.
 *
 * usage: 
 *		show_matrix(A, fmt)
 *		show_matrix(A, "%4.2f")
 *
 */
void show_matrix(Matrix, char *); 

Vector mul_matrix_vector(Matrix, Vector);

#endif
