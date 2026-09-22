#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "array.h"
#include "defs.h"

typedef struct {
	int found;
	size_t index;
} SearchResult;

static SearchResult binary_search_range(const IntArray *values, int target, size_t start, size_t end)
{
	SearchResult result = {
		.found = FALSE,
		.index = 0,
	};
	size_t mid;

	assert(values != NULL);
	assert(values->data != NULL || values->len == 0);
	assert(start <= end && end <= values->len);

	while (start < end) {
		mid = start + (end - start) / 2;
		if (values->data[mid] == target) {
			result.found = TRUE;
			result.index = mid;
			return result;
		}
		if (values->data[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return result;
}

static SearchResult binary_search(const IntArray *values, int target)
{
	assert(values != NULL);
	return binary_search_range(values, target, 0, values->len);
}

int main(void)
{
	int data[] = {-5, -1, 0, 3, 7, 9, 12, 15, 20};
	const int targets[] = {7, -5, 20, 8, -10};
	IntArray values = {
		.data = data,
		.len = ARRAY_LEN(data),
	};
	SearchResult result;
	size_t i;

	printf("Values: ");
	for (i = 0; i < values.len; ++i)
		printf("%d ", values.data[i]);
	printf("\n\n");

	for (i = 0; i < ARRAY_LEN(targets); ++i) {
		result = binary_search(&values, targets[i]);
		if (result.found)
			printf("Target %d found at index: %zu\n", targets[i], result.index);
		else
			printf("Target %d not found\n", targets[i]);
	}
	return 0;
}
