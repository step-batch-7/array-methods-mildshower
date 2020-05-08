#ifndef __ARRAY_FUNCTIONS_H_
#define __ARRAY_FUNCTIONS_H_

typedef int *Int_Ptr;

typedef struct
{
  Int_Ptr values;
  unsigned length;
} Dynamic_Int_Array;

typedef Dynamic_Int_Array *Dynamic_Int_Array_Ptr;

Dynamic_Int_Array_Ptr copy_to_dynamic_array(int source_array[], unsigned length);

#endif