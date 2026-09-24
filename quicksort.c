#include <assert.h>
#include <stddef.h>
#include <stdio.h>

void quicksort_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int *data, size_t len)
{
	int pivot;
	size_t pos;
	size_t i;

	assert(data != NULL || len == 0);
	while (len > 1) {
		pivot = data[len - 1];
		pos = 0;
		for (i = 0; i < len - 1; ++i) {
			if (data[i] <= pivot) {
				quicksort_swap(&data[pos], &data[i]);
				++pos;
			}
		}
		quicksort_swap(&data[pos], &data[len - 1]);
		if (pos < len - pos - 1) {
			quicksort(data, pos);
			data += pos + 1;
			len -= pos + 1;
		} else {
			quicksort(data + pos + 1, len - pos - 1);
			len = pos;
		}
	}
}

int main(void)
{
	int data[] = {10, 7, 8, 9, 1, 5, -3, 7};
	size_t len;
	size_t i;

	len = sizeof data / sizeof data[0];
	printf("Before: ");
	for (i = 0; i < len; ++i)
		printf("%d ", data[i]);
	printf("\n");

	quicksort(data, len);

	printf("After: ");
	for (i = 0; i < len; ++i)
		printf("%d ", data[i]);
	printf("\n");
	return 0;
}
