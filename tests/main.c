#include "test_array.c"
#include "test_array_void.c"

int main(void)
{
  test_copy_to_dynamic_array();
  test_map();
  test_reduce();
  test_filter();
  test_create_int_object_array();
  test_map_void();
  test_filter_void();

  return 0;
}