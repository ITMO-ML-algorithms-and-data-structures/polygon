#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <chrono>

void comb_sort(std::vector<int>& vec)
{
    size_t gap = vec.size();
    bool swapped = true;
    while (gap != 1 || swapped) // Суммарно(рассчитывая как геометрическую прогрессию) получим константу умноженную на O(n) и по мере уменьшения step в итоге получим O(n) * O(n) = O(n^2)
    {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (size_t i = 0; i < vec.size() - gap; i++) // O(n / gap)
        {
            if (vec[i] > vec[i + gap])
            {
                std::swap(vec[i], vec[i + gap]);
                swapped = true;
            }
        }
    }
    // Time Complexity O(n^2)
    // Average Time Complexity Ω(n^2/2^p), where p is the number of increments. Или примерно O(3*log2(n)*n) (Из интернета) 
    // Space Complexity O(1)
}

void intro_sort(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    // Worst Time Complexity O(n log n)
    // Average Time Complexity O(n log n)
    // Space Complexity Варьируется
}

void pigeon_hole_sort(std::vector<int>& vec) {
	auto [min_it, max_it] = std::minmax_element(vec.begin(), vec.end()); // O(n)
	const int min_value = *min_it;
	const int range = *max_it - min_value + 1;

	std::vector<int> holes(range, 0); // O(range) | O(range)

	for (const int& x: vec) { // O(n)
		holes[x - min_value]++;
	}

	size_t i = 0;
	for (int count = 0; count < range; count++) { // Суммарно O(n)
		while (holes[count] > 0) {
			holes[count]--;
			vec[i] = count + min_value;
			i++;
		}
	}
    // Time Complexity O(n + range) 
    // Space Complexity O(range)
}


template<typename T>
bool is_sorted(const std::vector<T>& vec) {
	return std::is_sorted(vec.begin(), vec.end());
}

std::vector<int> generate_random_vector(size_t size) {
	std::vector<int> vec(size);
    srand(time(0));
	std::generate(vec.begin(), vec.end(), std::rand);
	return vec;
}

void run_tests() {
    // comb_sort
    {
        // Лучший случай (уже отсортированный массив)
        std::vector<int> best_case(1000);
        std::iota(best_case.begin(), best_case.end(), 1);
        comb_sort(best_case);
        assert(is_sorted(best_case));
        std::cout << "comb_sort best case passed!\n";

        // Средний случай (случайный массив)
        auto average_case = generate_random_vector(1000);
        comb_sort(average_case);
        assert(is_sorted(average_case));
        std::cout << "comb_sort average case passed!\n";

        // Худший случай (массив в обратном порядке)
        std::vector<int> worst_case(1000);
        std::iota(worst_case.rbegin(), worst_case.rend(), 1);
        comb_sort(worst_case);
        assert(is_sorted(worst_case));
        std::cout << "comb_sort worst case passed!\n";
    }

    // introsort
    {
        // Лучший случай (уже отсортированный массив)
        std::vector<int> best_case(1000);
        std::iota(best_case.begin(), best_case.end(), 1);
        intro_sort(best_case);
        assert(is_sorted(best_case));
        std::cout << "introsort best case passed!\n";

        // Средний случай (случайный массив)
        auto average_case = generate_random_vector(1000);
        intro_sort(average_case);
        assert(is_sorted(average_case));
        std::cout << "introsort average case passed!\n";

        // Худший случай (массив в обратном порядке)
        std::vector<int> worst_case(1000);
        std::iota(worst_case.rbegin(), worst_case.rend(), 1);
        intro_sort(worst_case);
        assert(is_sorted(worst_case));
        std::cout << "introsort worst case passed!\n";
    }

    // pigeon_hole_sort
    {
        // Лучший случай (уже отсортированный массив)
        auto best_case = generate_random_vector(1000);
        std::sort(best_case.begin(), best_case.end());
        std::reverse(best_case.begin(), best_case.end());
        pigeon_hole_sort(best_case);
        assert(is_sorted(best_case));
        std::cout << "pigeon_hole_sort best case passed!\n";

        // Средний случай (случайный массив)
        auto average_case = generate_random_vector(1000);
        pigeon_hole_sort(average_case);
        assert(is_sorted(average_case));
        std::cout << "pigeon_hole_sort average case passed!\n";

        // Худший случай (массив с одинаковыми значениями)
        std::vector<int> worst_case(1000, 5); // Все элементы равны
        pigeon_hole_sort(worst_case);
        assert(is_sorted(worst_case));
        std::cout << "pigeon_hole_sort worst case passed!\n";
    }
}

int main() {
	run_tests();
}
