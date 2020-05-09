#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr mapped_array = malloc(sizeof(ArrayVoid));
  mapped_array->array = malloc(sizeof(Object) * src->length);
  mapped_array->length = src->length;

  for (unsigned index = 0; index < src->length; index++)
  {
    mapped_array->array[index] = (*mapper)(src->array[index]);
  }

  return mapped_array;
}