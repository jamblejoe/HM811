#ifndef Header_LinearSystem
#define Header_LinearSystem

#include "Vector.h"
#include "Matrix.h"

/* LR decomposition, LU decomposition, Gaussian elimination
 * Decomposes a Matrix M into an upper triangle matrix R and a normed, lower
 * triangle matrix L such that L * R = M.
 * This decomposition is INPLACE. The Matrix M will be overriden with L
 * R. No additional memory is needed.
 * 
 * This algorithm does not do pivoting.
 * This algorithm is only implemented for quadratic matrices.
 * The implementation is very naive and does not take the memory ordering 
 * into account.
 *
 * usage:
 * 		LR_decomposition_inplace(A)
 */
void LR_decomposition_inplace(Matrix);


/* Solves a linear system Ax=b, where A is LR-factorised already,
 * e.g. by calling LR_decomposition_inplace(A).
 * This function is INPLACE! It will override b with x.
 * No additional memory is needed.
 *
 * usage:
 *		LR_solve_inplace(A, b)
 */
void LR_solve_inplace (Matrix, Vector);


#endif
