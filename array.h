#ifndef __ARRAY_H_
#define __ARRAY_H_

typedef int *Int_Ptr;

typedef enum
{
  False,
  True
} Bool;

typedef struct
{
  Int_Ptr array;
  int length;
} Array;

typedef Array *Array_Ptr;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

Array_Ptr copy_to_dynamic_array(int source_array[], unsigned length);
Array_Ptr map(Array_Ptr src, Mapper mapper);
Array_Ptr filter(Array_Ptr src, Predicate predicate);
int reduce(Array_Ptr src, int init, Reducer reducer);

#endif