#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

bool are_isomorph(std::string* line_1, std::string* line_2, std::unordered_map<char, char>* saved_letters) { // 8 + 4 * 2 = 12 ���� (���������) 
	int length1 = (*line_1).size(); // 4 �����
	int length2 = (*line_2).size(); // 4 �����
	if (length2 != length1) { return false; }
	for (int i = 0; i < length1; i++) { // 24 + 2 * K ���� (max K = 94, ��� K - ���������� ���������� �������� � ������) ��� 24 + 80 ���� ��� K <= 40
		auto search = (*saved_letters).find((*line_1)[i]); // �� ����� 24 �����
		if (search != (*saved_letters).end()) {
			if (search->second != (*line_2)[i]) {
				return false;
			}
		}
		else {
			(*saved_letters).insert({ (*line_1)[i], (*line_2)[i] });
		}
	}
	return true;
}
//int main(){
//	std::string line_1,line_2; // 80 ����
//	std::cin >> line_1 >> line_2; // N + M ���� (max N, M = 10000, ��� N, M - ���������� �������� � �������) ��� 80 ���� ��� N � M <= 40
//	std::unordered_map<char, char> saved_letters; // 80 ����
//  std::cout << are_isomorph(&line_1, &line_2, &saved_letters) << std::endl;
//}

// �������� ������� ������: max(M+N, 80) + 16 + 4 + 4 + max(2*K, 80) + 24 = max(M+N, 80) + max(2*K, 80) + 44 ����


// ���� �� �������
void TEST_1() {
	std::string line_1{ "foo" }, line_2{ "dff" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 1);

}

// ���� � ������������� ��������
void TEST_2() {
	std::string line_1{ "foo" }, line_2{ "dfd" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 0);

}

// ���� �� �������� ������ ����� (a > b)
void TEST_3() {
	std::string line_1{ "food" }, line_2{ "dff" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 0);

}

// ���� �� �������� ������ ����� (a < b)
void TEST_4() {
	std::string line_1{ "foo" }, line_2{ "dfff" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 0);

}

// ���� � ������� ��������
void TEST_5() {
	std::string line_1{ "" }, line_2{ "" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 1);

}

// ���� � ����������� ��������, ����������� ��� ���������� �������

void TEST_6() {
	std::string line_1{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890��������������������������������qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890��������������������������������" };
	std::string line_2{ "�qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890��������������������������������qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890�������������������������������" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 1);

}

// ���� � ������������� ��������, ����������� ��� ���������� �������
void TEST_7() {
	std::string line_1{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890��������������������������������qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890��������������������������������" };
	std::string line_2{ "�qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890��������������������������������qwertyuiopasdfghjkldfcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890�������������������������������" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 0);

}

int main() {
	TEST_1();
	TEST_2();
	TEST_3();
	TEST_4();
	TEST_5();
	TEST_6();
	TEST_7();
	std::cout << "All tests completed successfully" << std::endl;
}