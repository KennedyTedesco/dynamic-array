#include "unity.h"
#include <stdlib.h>

#include "../d_array.h"

void setUp(void) {}
void tearDown(void) {}

typedef struct car {
  int year;
  char name;
} car_t;

car_t *makeCar(int year, const char *name) {
  car_t *car = malloc(sizeof(car_t));
  car->name = *name;
  car->year = year;
  return car;
}

void test_free(void) {
  array_t *array = array_new();
  array->free = (array_free_func_t)&free;

  array_add(array, makeCar(1990, "car_a"));
  array_add(array, makeCar(1991, "car_b"));
  array_add(array, makeCar(1992, "car_c"));
  array_add(array, makeCar(1993, "car_d"));

  TEST_ASSERT_EQUAL_INT(4, array->capacity);

  array_add(array, makeCar(1994, "car_e"));

  TEST_ASSERT_EQUAL_INT(8, array->capacity);

  for (size_t i = 0; i < array->length; ++i) {
	TEST_ASSERT_EQUAL_INT(1990 + i, ((car_t *)array_get(array, i))->year);
  }

  array_destroy(array);
}

void test_push_and_pop(void) {
  array_t *array = array_new();
  array_add(array, (int *)1);
  array_add(array, (int *)2);
  array_add(array, (int *)3);
  array_add(array, (int *)4);

  TEST_ASSERT_EQUAL_INT(4, array->capacity);

  for (size_t i = 0; i < array->length - 1; ++i) {
	TEST_ASSERT_EQUAL_INT(i + 1, (int *)array_get(array, i));
  }

  array_add(array, (int *)5);
  array_add(array, (int *)6);
  TEST_ASSERT_EQUAL_INT(8, array->capacity);

  TEST_ASSERT_EQUAL_INT(5, (int *)array_get(array, 4));
  TEST_ASSERT_EQUAL_INT(6, (int *)array_get(array, 5));

  array_add(array, (int *)7);
  array_add(array, (int *)8);
  array_add(array, (int *)9);
  TEST_ASSERT_EQUAL_INT(16, array->capacity);

  array_destroy(array);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_free);
  RUN_TEST(test_push_and_pop);

  return UNITY_END();
}
