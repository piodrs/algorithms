#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

std::size_t Partition(std::vector<int>& values, std::size_t start, std::size_t end) noexcept {
    assert(start < end && end <= values.size());

    const int pivot = values[end - 1];
    std::size_t pivotIndex = start;

    for (std::size_t current = start; current < end - 1; ++current) {
        if (values[current] <= pivot) {
            std::swap(values[pivotIndex], values[current]);
            ++pivotIndex;
        }
    }

    std::swap(values[pivotIndex], values[end - 1]);

    return pivotIndex;
}

void QuickSort(std::vector<int>& values, std::size_t start, std::size_t end) noexcept {
    assert(start <= end && end <= values.size());

    if (end - start < 2) return;
    
    const std::size_t pivotIndex = Partition(values, start, end);

    QuickSort(values, start, pivotIndex);
    QuickSort(values, pivotIndex + 1, end);
}

void QuickSort(std::vector<int>& values) noexcept {
    QuickSort(values, 0, values.size());
}

int main() {
    std::vector<int> values = {10, 7, 8, 9, 1, 5, -3, 7};

    std::cout << "Before: ";
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    QuickSort(values);

    std::cout << "After: ";
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    return 0;
}
