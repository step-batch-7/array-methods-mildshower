#ifndef __ARRAY_FUNCTIONS_H_
#define __ARRAY_FUNCTIONS_H_

typedef int *Int_Ptr;

typedef struct
{
  Int_Ptr values;
  unsigned length;
} Dynamic_Int_Array;

typedef Dynamic_Int_Array *Dynamic_Int_Array_Ptr;

typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);

typedef Bool (*Predicate)(int);

typedef int (*Reducer)(int, int);

Dynamic_Int_Array_Ptr copy_to_dynamic_array(int source_array[], unsigned length);

Dynamic_Int_Array_Ptr map(Dynamic_Int_Array_Ptr numbers, Mapper mapper);

Dynamic_Int_Array_Ptr filter(Dynamic_Int_Array_Ptr numbers, Predicate predicate);

int reduce(Dynamic_Int_Array_Ptr numbers, int initial_context, Reducer reducer);

#endif