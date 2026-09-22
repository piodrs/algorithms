#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "array.h"
#include "defs.h"

static void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static size_t partition(IntArray *values, size_t start, size_t end)
{
	int pivot;
	size_t pos;
	size_t i;

	assert(start < end && end <= values->len);
	pivot = values->data[end - 1];
	pos = start;
	for (i = start; i < end - 1; ++i) {
		if (values->data[i] <= pivot) {
			swap(&values->data[pos], &values->data[i]);
			++pos;
		}
	}
	swap(&values->data[pos], &values->data[end - 1]);
	return pos;
}

static void quicksort_range(IntArray *values, size_t start, size_t end)
{
	size_t pos;

	assert(values != NULL);
	assert(values->data != NULL || values->len == 0);
	assert(start <= end && end <= values->len);
	if (end - start < 2)
		return;
	pos = partition(values, start, end);
	quicksort_range(values, start, pos);
	quicksort_range(values, pos + 1, end);
}

static void quicksort(IntArray *values)
{
	assert(values != NULL);
	quicksort_range(values, 0, values->len);
}

int main(void)
{
	int data[] = {10, 7, 8, 9, 1, 5, -3, 7};
	IntArray values = {
		.data = data,
		.len = ARRAY_LEN(data),
	};
	size_t i;

	printf("Before: ");
	for (i = 0; i < values.len; ++i)
		printf("%d ", values.data[i]);
	printf("\n");

	quicksort(&values);

	printf("After: ");
	for (i = 0; i < values.len; ++i)
		printf("%d ", values.data[i]);
	printf("\n");
	return 0;
}
