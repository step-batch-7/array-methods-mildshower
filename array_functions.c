#include <stdlib.h>
#include "array_functions.h"

Dynamic_Int_Array_Ptr copy_to_dynamic_array(int source_array[], unsigned length)
{
  Dynamic_Int_Array_Ptr target_array = malloc(sizeof(Dynamic_Int_Array));
  target_array->length = length;
  target_array->values = malloc(sizeof(int) * length);

  for (unsigned index = 0; index < length; index++)
  {
    target_array->values[index] = source_array[index];
  }

  return target_array;
}

Dynamic_Int_Array_Ptr map(Dynamic_Int_Array_Ptr numbers, Mapper mapper)
{
  Dynamic_Int_Array_Ptr mapped_numbers = malloc(sizeof(Dynamic_Int_Array));
  mapped_numbers->length = numbers->length;
  mapped_numbers->values = malloc(sizeof(int) * numbers->length);

  for (unsigned index = 0; index < mapped_numbers->length; index++)
  {
    mapped_numbers->values[index] = (*mapper)(numbers->values[index]);
  }

  return mapped_numbers;
}

Dynamic_Int_Array_Ptr filter(Dynamic_Int_Array_Ptr numbers, Predicate predicate)
{
  Dynamic_Int_Array_Ptr filtered_numbers = malloc(sizeof(Dynamic_Int_Array));
  filtered_numbers->values = malloc(sizeof(int) * numbers->length);
  filtered_numbers->length = 0;

  for (unsigned index = 0; index < numbers->length; index++)
  {
    if ((*predicate)(numbers->values[index]))
    {
      filtered_numbers->values[filtered_numbers->length] = numbers->values[index];
      filtered_numbers->length++;
    }
  }

  filtered_numbers->values = realloc(filtered_numbers->values, sizeof(int) * filtered_numbers->length);
  return filtered_numbers;
}

int reduce(Dynamic_Int_Array_Ptr numbers, int initial_context, Reducer reducer)
{
  int context = initial_context;

  for (unsigned index = 0; index < numbers->length; index++)
  {
    context = (*reducer)(context, numbers->values[index]);
  }

  return context;
}