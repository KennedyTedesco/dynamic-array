#include <stdlib.h>

#include "d_array.h"

array_t *array_new() {
  array_t *array = malloc(sizeof(array_t));

  array->length = 0;
  array->free = NULL;
  array->capacity = DEFAULT_STARTING_CAPACITY;
  array->data = malloc(array->capacity * sizeof(void *));

  return array;
}

void array_add(array_t *array, void *element) {
  if (array->length >= array->capacity) {
	array->capacity *= DEFAULT_GROW_FACTOR;
	array->data = realloc(array->data, array->capacity * sizeof(void *));
  }
  array->data[array->length++] = element;
}

void *array_get(array_t *array, size_t index) {
  if (index <= array->length) {
	return array->data[index];
  }
  return NULL;
}

void array_destroy(array_t *array) {
  if (array->free != NULL) {
	while (array->length > 0) {
	  array->free(array->data[--array->length]);
	}
  }
  free(array->data);
  free(array);
}
