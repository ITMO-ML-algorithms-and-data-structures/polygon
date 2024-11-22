#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>

using namespace std; 


// O(1) - �������� ��������
uint64_t rol64(uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}


// ��������� ��� �������� ���� �������������
struct xoshiro256pp_state {
	uint64_t s[4]; // 8*4 ���� ��� ������� ������ state
};


// ��� ��� �������� ��������, �� ��� ����� ���������� +- O(1) �������� 10 ������
uint64_t xoshiro256pp(struct xoshiro256pp_state *state) {
	// ��������� �������� ����������, �������� ��������� ������� �������� ��������
	// �������� ���� �� ����� ������� PRNG
	uint64_t *s = state->s;
	uint64_t const result = rol64(s[0] + s[3], 23) + s[0];
	uint64_t const t = s[1] << 17;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;
	s[3] = rol64(s[3], 45);

	return result;
}

// O(N) + O(K)
vector<long int> sampling(long int inp_size, long int out_size, vector <long int> data){ // ��������� ������ ���������� -> 
//  4 ����� + 4 ����� + 4 * n ����
	xoshiro256pp_state seed;
	uint64_t* s = seed.s; // 32 �����
	
	// ���������� seed 
	for (int i=0; i<4; i++){ // 2 �����   O(1)
		s[i] = time(nullptr); 
	}
	
	
	// �������� �� ���� ��������� � ������ ������� i � ���������
	
	for (long int i=0; i<inp_size; i++){ // 4 �����   O(N)
		uint64_t rdm = xoshiro256pp(&seed)%inp_size;
		swap(data[i], data[rdm]);
	}
	
	
	// ������� ������ ������ � ��������� ��� K ������� ���������� �� ������������ �������� �������
	vector <long int> ans(out_size); // 4 * k ����
	for (long int i=0; i<out_size; i++){// 4 �����  O(K)
		ans[i] = data[i];
	}
	
	// ������� �� ������ ����������
	data.clear();
	data.shrink_to_fit();
	
	
	return ans;
}

void test(){
	long int n, k; // 4 + 4 �����
	
	string a = "0input.txt";
	ofstream fout("Test_output.txt");
	
	for (int i=0; i<2; i++){
		
		a[0] = static_cast<char>(i+65);
		ifstream fin(a);
		
		fin >> n;
		vector <long int> data(n);
		for (long int i = 0; i<n; i++) // 4 �����  O(N)
			fin >> data[i];
		fin >> k;
		fin.close();
		
		vector <long int> ans = sampling(n, k, data); 
		bool flag = false;
		fout << "���� ����� " <<  i << endl;
		
		
		for (long int i=0; i<k; i++) // 4 �����  O(K)
			fout << ans[i] << ' ';
		
		fout << endl;
		
		fout << "�� ��������� � ����������� " << endl;
		for (long int i=0; i<k; i++) // 4 �����  O(K)
			if ( not(data[i] == ans[i])){
				flag = true;
			}
		fout << flag << endl;
		
		flag = false;
		fout << "��� �������� ���� � data " << endl;
		for (long int i=0; i<k; i++) // 4 �����  O(K)
			for (long int j=0; j<n; j++){
				if (data[j] == ans[i]){
					flag = true;
				}
			}
			if (not flag){
				break;
			}
		
				
		fout << flag << endl;
		
		
	}
	
	fout.close();
	
}


int main(){
	long int n, k; // 4 + 4 �����
	
	cout << "Start testing \" yes \" ";
	string s; 
	cin >> s;
	if (s == "yes"){
		test();
	}
	else{
		
		// ���� �����
		ifstream fin("input.txt");
		
		fin >> n;
		vector <long int> data(n);
		for (long int i = 0; i<n; i++) // 4 �����  O(N)
			fin >> data[i];
		
		fin >> k;
		
		fin.close();
		
		// ���� ������
		ofstream fout("output.txt");
		
		vector <long int> ans = sampling(n, k, data); 
		for (long int i=0; i<k; i++) // 4 �����  O(K)
			fout << ans[i];
			
		fout.close();
		
		// ������ ������
		data.clear();
		data.shrink_to_fit();
		
		ans.clear();
		ans.shrink_to_fit();
	}
	
	
	return 0;
}
