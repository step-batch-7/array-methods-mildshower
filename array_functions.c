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