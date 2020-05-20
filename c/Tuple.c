#include <assert.h>
#include <stdlib.h>
#include "Tuple.h"

Tuple create_tuple(unsigned int n) {

  Tuple t;
  
  assert(n >= 1);
  t = (Tuple) calloc(n, sizeof(double));
  assert(t != NULL);
  return t;
}

void free_tuple(Tuple * v) {

  assert(*v != NULL);
  free(*v);
  *v = NULL;
}

