#include <stdio.h>
#include <assert.h>
#include "../array.h"

int increment(int number)
{
  return number + 1;
}

int add(int number1, int number2)
{
  return number1 + number2;
}

Bool is_even(int number)
{
  return !(number % 2);
}

void test_copy_to_dynamic_array(void)
{
  printf("\n\nTesting copy_to_dynamic_array\n\n");

  printf("\tShould copy the whole int array to a dynamic array and give it back\n");
  int source1[] = {1, 2};
  Array_Ptr target1 = copy_to_dynamic_array(source1, 2);
  assert(target1->array[0] == 1);
  assert(target1->array[1] == 2);
  assert(target1->length == 2);
  printf("\t\t--passed\n\n");
}

void test_map(void)
{
  printf("\n\nTesting map\n\n");

  printf("\tShould map the array according to the given mapper\n");
  int numbers[] = {1, 2};
  Array_Ptr mapped_numbers = map(copy_to_dynamic_array(numbers, 2), &increment);
  assert(mapped_numbers->array[0] == 2);
  assert(mapped_numbers->array[1] == 3);
  assert(mapped_numbers->length == 2);
  printf("\t\t--passed\n\n");
}

void test_filter(void)
{
  printf("\n\nTesting filter\n\n");

  printf("\tShould filter the array according to the given predicate\n");
  int numbers[] = {-1, 2, 3};
  Array_Ptr filtered_numbers = filter(copy_to_dynamic_array(numbers, 3), &is_even);
  assert(filtered_numbers->length == 1);
  assert(filtered_numbers->array[0] == 2);
  printf("\t\t--passed\n\n");

  printf("\tShould return empty array if no element passes the predicate\n");
  int numbers1[] = {-1, 3};
  Array_Ptr filtered_numbers1 = filter(copy_to_dynamic_array(numbers1, 2), &is_even);
  assert(filtered_numbers1->length == 0);
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
  test_filter();

  return 0;
}
