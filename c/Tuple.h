#ifndef Header_Tuple
#define Header_Tuple

/* Modelling n-tuples of type double
 */
typedef double * Tuple; 

/* Tuple constructor
 * Creates a tuple of length n, where all values are initialized to zero.
 * 
 * return: pointer
 * usage:
 * 		t = Tuple_Create (n);
 * 		t = Tuple_Create (1234);
 * 
 * memory allocated: n * sizeof(double)
 */
Tuple create_tuple(unsigned int);

/* Frees the memory of a tuple
 * Usage: 
 * 		free_tuple(&t)
 */
void free_tuple(Tuple *);



#endif
