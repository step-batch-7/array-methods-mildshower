#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_int_object_array(Int_Ptr src, unsigned length)
{
  ArrayVoid_ptr object_array = malloc(sizeof(ArrayVoid));
  object_array->array = malloc(sizeof(Object) * length);
  object_array->length = length;

  for (unsigned index = 0; index < length; index++)
  {
    object_array->array[index] = malloc(sizeof(int));
    *(Int_Ptr)object_array->array[index] = src[index];
  }

  return object_array;
}

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

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr filtered_array = malloc(sizeof(ArrayVoid));
  filtered_array->array = malloc(sizeof(Object) * src->length);
  filtered_array->length = 0;

  for (unsigned index = 0; index < src->length; index++)
  {
    if ((*predicate)(src->array[index]))
    {
      filtered_array->array[filtered_array->length] = src->array[index];
      filtered_array->length++;
    }
  }

  filtered_array->array = realloc(filtered_array->array, sizeof(Object) * filtered_array->length);
  return filtered_array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  Object context = init;

  for (unsigned index = 0; index < src->length; index++)
  {
    context = (*reducer)(context, src->array[index]);
  }

  return context;
}