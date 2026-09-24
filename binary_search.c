#include <assert.h>
#include <stddef.h>
#include <stdio.h>

size_t binary_search(const int *data, size_t len, int target)
{
	size_t start;
	size_t end;
	size_t mid;

	assert(data != NULL || len == 0);
	start = 0;
	end = len;
	while (start < end) {
		mid = start + (end - start) / 2;
		if (data[mid] == target)
			return mid;
		if (data[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return len;
}

int main(void)
{
	const int data[] = {-5, -1, 0, 3, 7, 9, 12, 15, 20};
	const int targets[] = {7, -5, 20, 8, -10};
	size_t len;
	size_t index;
	size_t i;

	len = sizeof data / sizeof data[0];
	printf("Values: ");
	for (i = 0; i < len; ++i)
		printf("%d ", data[i]);
	printf("\n\n");

	for (i = 0; i < sizeof targets / sizeof targets[0]; ++i) {
		index = binary_search(data, len, targets[i]);
		if (index < len)
			printf("Target %d found at index: %lu\n",
			       targets[i], (unsigned long)index);
		else
			printf("Target %d not found\n", targets[i]);
	}
	return 0;
}
