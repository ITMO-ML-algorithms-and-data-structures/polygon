#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>

using namespace std; 


// O(1) - бинарные операции
uint64_t rol64(uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}


// Структура для хранения шага рандомизатора
struct xoshiro256pp_state {
	uint64_t s[4]; // 8*4 байт для каждого такого state
};


// Так как операции бинарные, то они будут выполнятся +- O(1) примерно 10 тактов
uint64_t xoshiro256pp(struct xoshiro256pp_state *state) {
	// Кастомный алгоритм шифрования, работает благодаря теореме Джорджем Марсалья
	// Является одим из самых быстрых PRNG
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
vector<long int> sampling(long int inp_size, long int out_size, vector <long int> data){ // Дублируем каждую переменную -> 
//  4 байта + 4 байта + 4 * n байт
	xoshiro256pp_state seed;
	uint64_t* s = seed.s; // 32 байта
	
	// Генерируем seed 
	for (int i=0; i<4; i++){ // 2 байта   O(1)
		s[i] = time(nullptr); 
	}
	
	
	// Проходим по всем элементам и меняем местами i и рандомный
	
	for (long int i=0; i<inp_size; i++){ // 4 байта   O(N)
		uint64_t rdm = xoshiro256pp(&seed)%inp_size;
		swap(data[i], data[rdm]);
	}
	
	
	// Создаем вектор ответа и заполняем его K первыми элементами из премешанного входного массива
	vector <long int> ans(out_size); // 4 * k байт
	for (long int i=0; i<out_size; i++){// 4 байта  O(K)
		ans[i] = data[i];
	}
	
	// Удаляем не нужные переменные
	data.clear();
	data.shrink_to_fit();
	
	
	return ans;
}

void test(){
	long int n, k; // 4 + 4 байта
	
	string a = "0input.txt";
	ofstream fout("Test_output.txt");
	
	for (int i=0; i<2; i++){
		
		a[0] = static_cast<char>(i+65);
		ifstream fin(a);
		
		fin >> n;
		vector <long int> data(n);
		for (long int i = 0; i<n; i++) // 4 байта  O(N)
			fin >> data[i];
		fin >> k;
		fin.close();
		
		vector <long int> ans = sampling(n, k, data); 
		bool flag = false;
		fout << "Тест номер " <<  i << endl;
		
		
		for (long int i=0; i<k; i++) // 4 байта  O(K)
			fout << ans[i] << ' ';
		
		fout << endl;
		
		fout << "Не совпадает с изначальным " << endl;
		for (long int i=0; i<k; i++) // 4 байта  O(K)
			if ( not(data[i] == ans[i])){
				flag = true;
			}
		fout << flag << endl;
		
		flag = false;
		fout << "Все элементы есть в data " << endl;
		for (long int i=0; i<k; i++) // 4 байта  O(K)
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
	long int n, k; // 4 + 4 байта
	
	cout << "Start testing \" yes \" ";
	string s; 
	cin >> s;
	if (s == "yes"){
		test();
	}
	else{
		
		// блок ввода
		ifstream fin("input.txt");
		
		fin >> n;
		vector <long int> data(n);
		for (long int i = 0; i<n; i++) // 4 байта  O(N)
			fin >> data[i];
		
		fin >> k;
		
		fin.close();
		
		// блок вывода
		ofstream fout("output.txt");
		
		vector <long int> ans = sampling(n, k, data); 
		for (long int i=0; i<k; i++) // 4 байта  O(K)
			fout << ans[i];
			
		fout.close();
		
		// Чистим паямть
		data.clear();
		data.shrink_to_fit();
		
		ans.clear();
		ans.shrink_to_fit();
	}
	
	
	return 0;
}
