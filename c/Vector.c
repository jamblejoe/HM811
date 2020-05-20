#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Tuple.h"
#include "Vector.h"

Vector create_vector(unsigned int n) {

  Vector x;
  
  assert (n >= 1);
  x.n = n;
  x.value = create_tuple(x.n);
  
  return x;
}  

void free_vector(Vector * x) {
  
  free_tuple(&(x->value));
  x->n = 0;
}

double get_value_vector(Vector x, unsigned int i) {
  assert (i < x.n);
  return x.value[i];
}
void set_value_vector(Vector x, unsigned int i, double alpha) {
  assert (i < x.n);
  x.value[i] = alpha;
}

void show_vector(Vector x, char * fmt) {

  unsigned int n = x.n;
  unsigned int i;
  
  if (x.value == NULL) {printf ("No memory allocated!\n"); 
  }
  else {
    for (i=0; i<n; i=i+1) {
      printf ("%3d", i); 
      printf (fmt, get_value_vector(x, i));
      printf ("\n");
    }
  }
}
