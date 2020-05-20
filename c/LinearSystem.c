#include <assert.h>
#include "Matrix.h"
#include "Tuple.h"	
#include "LinearSystem.h"

																			
void LR_decomposition_inplace(Matrix A){													

	unsigned int n=A.n;																				
	unsigned int i=0,j,k;
	
	assert(A.n==A.m);
	
	for(i=0;i<n-1;i=i+1){																	

		assert(get_value_matrix(A,i,i)!=0.0);
																					
		/** calculate the column L_i **/
		for(j=i+1;j<n;j=j+1){																
		
			set_value_matrix(A,j,i, 
				get_value_matrix(A,j,i) / get_value_matrix(A,i,i)
			);
		}
		/** update the R matrix **/
		for(j=i+1;j<n;j=j+1){							
			for(k=i+1;k<n;k=k+1){
				set_value_matrix(A,j,k, 
					get_value_matrix(A,j,k) - (get_value_matrix(A,j,i) * get_value_matrix(A,i,k))
				);
			}
		}
	}
}


void LR_solve_inplace(Matrix A, Vector b){													

	unsigned int j,i,n=A.n;
	
	assert(A.n==A.m);																		
	assert(n==b.n); 				
	
	/** Solves Ly=b. y is saved into b. **/
	for(j=0;j<n;j=j+1){																	
		for(i=j+1;i<n;i=i+1){																
			set_value_vector(b,i,
				get_value_vector(b,i) - (get_value_matrix(A,i,j) * get_value_vector(b,j))
			); 	
		}
	}
	
	/** Solves Rx=y. x is saved into y **/
	for(j=n-1;j+1>0;j=j-1){																	
		set_value_vector(b,j,
			get_value_vector(b,j) / get_value_matrix(A,j,j)
		);  			
		
		for(i=0;i<j;i=i+1){
			set_value_vector(b,i,
				get_value_vector(b,i) - (get_value_matrix(A,i,j) * get_value_vector(b,j))
			); 
		}																					
	}
}

