int most_frequent_element()
{
	int size = 0;
	std::cin >> size;
	int* arr = new int[size];
	
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
	int most_frequent_element = 0;
	int max_count = 0;
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int k = 0; k < size; k++) {
			if (arr[i] == arr[k])
			{
				count = count + 1;
			}
		}
		if (count > max_count) {
			max_count = count;
			most_frequent_element = arr[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) {
			arr[i] = most_frequent_element;
		}
	}
	return arr;
}
	