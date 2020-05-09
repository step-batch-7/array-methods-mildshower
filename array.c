#include <stdlib.h>
#include "array.h"

Array_Ptr copy_to_dynamic_array(int source_array[], unsigned length)
{
  Array_Ptr target_array = malloc(sizeof(Array));
  target_array->length = length;
  target_array->array = malloc(sizeof(int) * length);

  for (unsigned index = 0; index < length; index++)
  {
    target_array->array[index] = source_array[index];
  }

  return target_array;
}

Array_Ptr map(Array_Ptr src, Mapper mapper)
{
  Array_Ptr mapped_numbers = malloc(sizeof(Array));
  mapped_numbers->length = src->length;
  mapped_numbers->array = malloc(sizeof(int) * src->length);

  for (unsigned index = 0; index < mapped_numbers->length; index++)
  {
    mapped_numbers->array[index] = (*mapper)(src->array[index]);
  }

  return mapped_numbers;
}

Array_Ptr filter(Array_Ptr src, Predicate predicate)
{
  Array_Ptr filtered_numbers = malloc(sizeof(Array));
  filtered_numbers->array = malloc(sizeof(int) * src->length);
  filtered_numbers->length = 0;

  for (unsigned index = 0; index < src->length; index++)
  {
    if ((*predicate)(src->array[index]))
    {
      filtered_numbers->array[filtered_numbers->length] = src->array[index];
      filtered_numbers->length++;
    }
  }

  filtered_numbers->array = realloc(filtered_numbers->array, sizeof(int) * filtered_numbers->length);
  return filtered_numbers;
}

int reduce(Array_Ptr src, int init, Reducer reducer)
{
  int context = init;

  for (unsigned index = 0; index < src->length; index++)
  {
    context = (*reducer)(context, src->array[index]);
  }

  return context;
}