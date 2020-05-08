#include <stdio.h>
#include <assert.h>
#include "../array_functions.h"

int increment(int number)
{
  return number + 1;
}

int add(int number1, int number2)
{
  return number1 + number2;
}

void test_copy_to_dynamic_array(void)
{
  printf("\n\nTesting copy_to_dynamic_array\n\n");

  printf("\tShould copy the whole int array to a dynamic array and give it back\n");
  int source1[] = {1, 2};
  Dynamic_Int_Array_Ptr target1 = copy_to_dynamic_array(source1, 2);
  assert(target1->values[0] == 1);
  assert(target1->values[1] == 2);
  assert(target1->length == 2);
  printf("\t\t--passed\n\n");

  printf("\tShould work for empty arrat also\n");
  int source2[] = {};
  Dynamic_Int_Array_Ptr target2 = copy_to_dynamic_array(source2, 0);
  assert(target2->values == NULL);
  assert(target2->length == 0);
  printf("\t\t--passed\n\n");
}

void test_map(void)
{
  printf("\n\nTesting map\n\n");

  printf("\tShould map the array according to the given mapper\n");
  int numbers[] = {1, 2};
  Dynamic_Int_Array_Ptr mapped_numbers = map(copy_to_dynamic_array(numbers, 2), &increment);
  assert(mapped_numbers->values[0] == 2);
  assert(mapped_numbers->values[1] == 3);
  assert(mapped_numbers->length == 2);
  printf("\t\t--passed\n\n");
}

void test_reduce(void)
{
  printf("\n\nTesting reduce\n\n");

  printf("\tShould reduce the array according to the given reducer\n");
  int numbers[] = {1, 2};
  assert(reduce(copy_to_dynamic_array(numbers, 2), 0, &add) == 3);
  printf("\t\t--passed\n\n");
}

int main(void)
{
  test_copy_to_dynamic_array();
  test_map();
  test_reduce();

  return 0;
}
