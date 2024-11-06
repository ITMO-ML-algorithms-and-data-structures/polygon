

    {
        std::vector<double> array3 = { 1.0, 2.5, 3.5, 8.0, 20.0, 25.0, 30.0,1.0,-1.9, 12.3, 1.7 };
        auto start = chrono::high_resolution_clock::now();
        std::vector<std::vector<double>> result3 = make_cluster(array3, 6);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        assert(result3.size() == 6);
        for (const auto& cluster : result3) {
            assert(!cluster.empty()); // Каждый кластер должен иметь хотя бы один элемент
        }
        std::cout << "Тест 3. \nКластеры: ";
        for (const auto& cluster : result3) {
            print_vector(cluster);
        }
        std::cout << "\n";
        std::cout << "Время: " << duration.count() / 1e6 << " секунд\n";
    }

    {
        std::vector<double> array4 = { -1.5, 0.0, 1.7,0.6,0.9, 8.0, -1.0, 4.0, 5.0, 7.0, 99.0,-12.0 };
        auto start = chrono::high_resolution_clock::now();
        std::vector<std::vector<double>> result4 = make_cluster(array4, 6);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        assert(result4.size() == 6);
        std::cout << "Тест 4.\nКластеры: ";
        for (const auto& cluster : result4) {
            print_vector(cluster);
        }
        std::cout << "\n";
        std::cout << "Время: " << duration.count() / 1e6 << " секунд\n";
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    test();
}
