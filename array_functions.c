#include <stdlib.h>
#include "array_functions.h"

Dynamic_Int_Array_Ptr copy_to_dynamic_array(int source_array[], unsigned length)
{
  Dynamic_Int_Array_Ptr target_array = malloc(sizeof(Dynamic_Int_Array));
  target_array->length = length;
  target_array->values = length ? malloc(sizeof(int) * length) : NULL;

  for (unsigned index = 0; index < length; index++)
  {
    target_array->values[index] = source_array[index];
  }

  return target_array;
}

Dynamic_Int_Array_Ptr map(Dynamic_Int_Array_Ptr numbers, Mapper mapper)
{
  Dynamic_Int_Array_Ptr mapped_array = malloc(sizeof(Dynamic_Int_Array));
  mapped_array->length = numbers->length;
  mapped_array->values = numbers->length ? malloc(sizeof(int) * numbers->length) : NULL;

  for (unsigned index = 0; index < mapped_array->length; index++)
  {
    mapped_array->values[index] = (*mapper)(numbers->values[index]);
  }

  return mapped_array;
}