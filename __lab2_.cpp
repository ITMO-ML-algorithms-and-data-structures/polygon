#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
	int n;
	std::cin >> n; //4 byte

	std::vector<std::string> begin_list(n); 
	
	for (int i = 0; i < n; i++) {//������ � ��������� ������
		std::cin >> begin_list[i];
	}
	std::cout << begin_list.capacity() * sizeof(std::string) << std::endl;

	std::unordered_map<std::string, int> countRep;//��� �������

	for (std::string num : begin_list) {
		countRep[num]++;
	}

	std::cout << sizeof(countRep) << std::endl;

	std::vector<int> end_list;

	for (std::string num : begin_list) {//���-�� ���������� ������� ��������
		if (countRep.find(num) != countRep.end()) {
			end_list.push_back(countRep[num]);
		}
	}
	std::cout << sizeof(int)*n << std::endl;
	for (int num : end_list) {//����� ��������� ������ � ���-��� ��������
		std::cout << num << " ";
	}
	// ����� ���-�� ���������� ������: 4 byte + 40*n byte + 80 byte + 4*n byte
	return 0;
}




