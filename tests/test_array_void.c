#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../array_void.h"

Object int_increment(Object number)
{
  Object incremented_value = malloc(sizeof(int));
  *(int *)incremented_value = *(int *)number + 1;
  return incremented_value;
}

Bool is_int_even(Object number)
{
  return !(*(int *)number % 2);
}

void test_create_int_object_array(void)
{
  printf("\n\nTesting create_int_object_array\n\n");

  printf("\tShould crete an Object Array(array of void pointers) from int array\n");
  int src[] = {1, 2};
  ArrayVoid_ptr object_array = create_int_object_array(src, 2);
  assert(*(int *)object_array->array[0] == 1);
  assert(*(int *)object_array->array[1] == 2);
  assert(object_array->length == 2);
  printf("\t\t--passed\n\n");
}

void test_map_void(void)
{
  printf("\n\nTesting map_void\n\n");

  printf("\tShould map the array with element\n");
  int src1[] = {1, 2};
  ArrayVoid_ptr mapped_array1 = map_void(create_int_object_array(src1, 2), &int_increment);
  assert(*(int *)mapped_array1->array[0] == 2);
  assert(*(int *)mapped_array1->array[1] == 3);
  assert(mapped_array1->length == 2);
  printf("\t\t--passed\n\n");

  printf("\tShould map empty array\n");
  int src2[] = {};
  ArrayVoid_ptr mapped_array2 = map_void(create_int_object_array(src2, 0), &int_increment);
  assert(mapped_array2->length == 0);
  printf("\t\t--passed\n\n");
}

void test_filter_void(void)
{
  printf("\n\nTesting filter_void\n\n");

  printf("\tShould filter the array with element\n");
  int src1[] = {1, 2};
  ArrayVoid_ptr filtered_array1 = filter_void(create_int_object_array(src1, 2), &is_int_even);
  assert(filtered_array1->length == 1);
  assert(*(int *)filtered_array1->array[0] == 2);
  printf("\t\t--passed\n\n");

  printf("\tShould map empty array\n");
  int src2[] = {};
  ArrayVoid_ptr filtered_array2 = filter_void(create_int_object_array(src2, 0), &is_int_even);
  assert(filtered_array2->length == 0);
  printf("\t\t--passed\n\n");
}