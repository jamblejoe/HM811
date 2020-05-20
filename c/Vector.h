#ifndef Header_Vector
#define Header_Vector

#include "Tuple.h"

/* Vector of n doubles 
 */

struct tmp_Vector {   
  unsigned int n;       
  Tuple value;  
};
typedef struct tmp_Vector Vector; 

/* Vector constructor
 * All values are initialized to zero.
 * Allocates n * sizeof(double) memory.
 * 
 * usage:
 * 		x = create_vector(n);      
 * 		x = create_vector(8);
 */
Vector create_vector(unsigned int);


/* Frees the memory of the vector.
 * 
 * usage:
 * 		free_vector(&v)
 */
void free_vector(Vector *); 

/* Getter and Setter functions for entries of a Vector.
 * An assertion error is raised, if the indices are out of bounds.
 * 
 * usage:
 * 		set_value_vector(v, i, x)
 * 		x = get_value_vector(v, i) 
 */
double get_value_vector(Vector, unsigned int); 
void set_value_vector(Vector, unsigned int, double);


/* Pretty printing for a Vector.
 * fmt can be used to set how many coefficients will be printed.
 *
 * usage: 
 *		show_vector(v, fmt)
 *		show_vector(v, "%4.2f")
 *
 */
void show_vector(Vector, char *); 


#endif
