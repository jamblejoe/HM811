#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tuple.h"
#include "Matrix.h"

Matrix create_matrix(unsigned int m, unsigned int n, MatrixMemoryOrdering order) {

  Matrix V;
  
  assert (m >= 1);
  assert (n >= 1);
  
  V.m = m;
  V.n = n;
  V.value = create_tuple(m*n);
  assert(V.value != NULL);
  
  V.order = order;
  return V;
}  


void free_matrix(Matrix * V) {
   free_tuple(&(V->value));
   V->m = 0;
   V->n = 0;
}

Matrix create_copy_of_matrix(Matrix A){
	unsigned int m = A.m;
	unsigned int n = A.n;
	MatrixMemoryOrdering order = A.order;
	Matrix B;
	
	B = create_matrix(m, n, order);
	
	memcpy(B.value, A.value, m * n * sizeof(double));
	return B;
}

double get_value_matrix(Matrix A, unsigned int i, unsigned int j) {
  assert(i < A.m);
  assert(j < A.n);
  return (A.order == ROWWISE) ? A.value[A.n*i+j] : A.value[A.m*j+i];
}

void set_value_matrix(Matrix A, unsigned int i, unsigned int j, double x) {
  assert(i < A.m);
  assert(j < A.n);
  A.value[(A.order == ROWWISE) ? A.n*i+j : A.m*j+i ] = x;
}

void show_matrix(Matrix A, char * fmt) {

  unsigned int m = A.m;
  unsigned int n = A.n;
 
  unsigned int i, j;
  
  /* printf ("m = %d, n = %d\n", m, n); */
  
  if (A.value == NULL) {printf ("No memory allocated!\n");} 
  else {

    /*if (A.order == ROWWISE) {printf ("Rowwise Memory Ordering\n");}
    else   					{printf ("Columnwise Memory Ordering\n");}	*/
	
    for (i=0; i<m; i++) {
      for (j=0; j<n; j++) {
         printf (fmt, get_value_matrix(A, i, j));
      }
      printf ("\n");    
    }
  }
}


Vector mul_matrix_vector(Matrix A, Vector x){
  	unsigned int m = A.m;
  	unsigned int n = A.n;
  	unsigned int i, j;
	Vector y; 

	assert(x.n == n);
	
	y = create_vector(m);
	for (i=0;i<m;i++){
			set_value_vector(y, i, 0.0);
	}
	
	if (A.order == ROWWISE){
		for (i=0; i<m; i++) {
			double y_i = 0.0;
			for (j=0; j<n; j++) {
				y_i += get_value_vector(x, j) * get_value_matrix(A, i, j);
			}
			set_value_vector(y, i, y_i);
    	}
	}
	else {		
		for (i=0; i<n; i++) {
			  for (j=0; j<m; j++) {
				 set_value_vector(y, j, get_value_vector(y, j) + get_value_vector(x, i) * get_value_matrix(A, j, i));
			  }
    	}
	}

	return y;
	
}

