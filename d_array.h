#ifndef D_ARRAY_H
#define D_ARRAY_H

#define DEFAULT_GROW_FACTOR 2
#define DEFAULT_STARTING_CAPACITY 4

typedef void (*array_free_func_t)(const void *data);

typedef struct array {
  void **data;
  size_t length;
  size_t capacity;
  array_free_func_t free;
} array_t;

array_t *array_new();
void array_destroy(array_t *array);

void array_add(array_t *array, void *element);
void *array_get(array_t *array, size_t index);

#endif
