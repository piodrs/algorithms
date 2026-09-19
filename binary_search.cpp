#include <cassert>
#include <cstddef>
#include <iostream>
#include <optional>
#include <vector>

std::optional<std::size_t> BinarySearch(const std::vector<int>& values, int target, std::size_t start, std::size_t end) noexcept {
    assert(start <= end && end <= values.size());

    while (start < end) {
        const std::size_t mid = start + (end - start) / 2;

        if (values[mid] == target) return mid;
        
        if (values[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return std::nullopt;
}

std::optional<std::size_t> BinarySearch(const std::vector<int>& values, int target) noexcept {
    return BinarySearch(values, target, 0, values.size());
}

int main() {
    const std::vector<int> values = {-5, -1, 0, 3, 7, 9, 12, 15, 20};

    std::cout << "Values: ";
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << "\n\n";

    const std::vector<int> targets = {7, -5, 20, 8, -10};

    for (int target : targets) {
        const auto index = BinarySearch(values, target);
        if (index.has_value()) {
            std::cout << "Target " << target << " found at index: " << *index << '\n';
        } else {
            std::cout << "Target " << target << " not found\n";
        }
    }

    return 0;
}
