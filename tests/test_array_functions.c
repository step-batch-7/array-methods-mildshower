#include <stdio.h>
#include <assert.h>
#include "../array_functions.h"

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

int main(void)
{
  test_copy_to_dynamic_array();

  return 0;
}
