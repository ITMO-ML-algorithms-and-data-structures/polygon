#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <functional>
#include <cassert>
#include <unordered_set>

std::vector<uint64_t> remove_duplicates(const std::string& filename) {
    // На вход 8 байт

    std::vector<uint64_t> nums;

    std::ifstream file_stream(filename, std::ios::binary); // Открываем поток чтения файла в бинарном режиме
    if (!file_stream)
        return nums; // Возращаем пустой вектор, если не удалось прочитай файл

    file_stream.seekg(0, std::ios::end); // Перемещаем указатель чтения в конец
    std::streamsize size = file_stream.tellg(); // Получаем размер файла (текущую позицию указателя) size весит 8 байт
    file_stream.seekg(0, std::ios::beg); // Возвращаем указатель чтения в начало

    nums.resize(size / sizeof(uint64_t)); // n * 8 байт

    file_stream.read(reinterpret_cast<char*>(nums.data()), size); // Читаем данные из файла в вектор
    file_stream.close();

    std::sort(nums.begin(), nums.end()); // Сортируем вектор, работает за o(n*log(n))
    auto end = std::unique(nums.begin(), nums.end()); // 8 байт на end, std::unique доп памяти не требует и работает за o(n)
    nums.erase(end, nums.end()); // Удаляем ненужные числа из вектора

    // Используем n * 8 + 8 * 3 байт памяти не считая размер самого вектора (его метаданных и тд)
    // Работает за o(n*log(n))
    return nums;
}

void write_to_file(const std::string& filename, const std::vector<uint64_t>& data) {
    std::ofstream file_stream(filename, std::ios::binary);
    file_stream.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(uint64_t));
    file_stream.close();
}

bool vectors_equal_ignore_order(const std::vector<uint64_t>& a, const std::vector<uint64_t>& b) {
    if (a.size() != b.size()) return false;
    std::unordered_set<uint64_t> set_a(a.begin(), a.end());
    std::unordered_set<uint64_t> set_b(b.begin(), b.end());
    return set_a == set_b;
}

// Simple unit test framework
class TestFramework {
public:
    static void registerTest(const std::string& name, std::function<void()> test) {
        tests.push_back({ name, test });
    }

    static void runTests() {
        for (const auto& t : tests) {
            try {
                t.test();
                std::cout << "Test passed: " << t.name << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Test failed: " << t.name << " - " << e.what() << std::endl;
            }
        }
    }

private:
    struct Test {
        std::string name;
        std::function<void()> test;
    };

    static std::vector<Test> tests;
};

std::vector<TestFramework::Test> TestFramework::tests;

void test_remove_duplicates() {
    const std::string filename = "test_file.bin";
    {
        std::vector<uint64_t> result = remove_duplicates("non_existent_file.bin");
        assert(result.empty());
    }
    {
        write_to_file(filename, {});
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(result.empty());
    }
    {
        write_to_file(filename, { 1, 2, 3, 4, 5 });
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(vectors_equal_ignore_order(result, { 1, 2, 3, 4, 5 }));
    }
    {
        write_to_file(filename, { 1, 2, 2, 3, 3, 3, 4, 5 });
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(vectors_equal_ignore_order(result, { 1, 2, 3, 4, 5 }));
    }
    {
        write_to_file(filename, { 42 });
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(vectors_equal_ignore_order(result, { 42 }));
    }

    {
        write_to_file(filename, { 7, 7, 7, 7, 7 });
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(vectors_equal_ignore_order(result, { 7 }));
    }

    {
        write_to_file(filename, { 5, 3, 1, 3, 2, 5, 4 });
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(vectors_equal_ignore_order(result, { 1, 2, 3, 4, 5 }));
    }
    {
        write_to_file(filename, { 1, 2, 1, 4, 5, 0, 0, 2 });
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(vectors_equal_ignore_order(result, { 0, 1, 2, 4, 5 }));
    }
    {
        write_to_file(filename, { 10, 20, 30, 20, 10, 40 });
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(vectors_equal_ignore_order(result, { 10, 20, 30, 40 }));
    }
    {
        write_to_file(filename, { 10000000000000000000, 200000, 10000000000000000000, 200000, 10000000000000000000 });
        std::vector<uint64_t> result = remove_duplicates(filename);
        assert(vectors_equal_ignore_order(result, { 10000000000000000000, 200000}));
    }
    std::remove(filename.c_str());
}

int main() {
    TestFramework::registerTest("Removing duplicates", test_remove_duplicates);
    TestFramework::runTests();
    return 0;
}
