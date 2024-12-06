#include <fstream> 
#include <vector>
#include <iostream>
#include <ctime>
#include <string>
using namespace std; 

// У алгоритма для работы очень много ограничений, чтобы работать эффективно.
// 1) Распределение данных. очень желательно нормальное распределение
// 2) Может работать и вообще придуман для сортировки значений [0, 1)
// Данная реализация для чисел в диапозоне от 0 до 1

// сложность стремиться к O(n/log(n))
// Так как данные очень малые, то происходит довольно быстро
void combSort(vector<double> &data){
  double factor = 1.247;
  long int gap = data.size() - 1; 
  bool swaped = false;
  while (gap > 1 or swaped){
    swaped = false;
    for (long int i=0; i+gap<data.size(); i++){
      if (data[i] > data[i + gap]){
        swap(data[i], data[i+gap]);
        swaped = true;
      } 
    }
    if (gap > 1)
      gap /= factor;
  }
   for (long int i=1; i<data.size(); i++){
    if (data[i-1] > data[i]){
      swap(data[i-1], data[i]);
    }
  }

}
 
// суть сортировки 
// 1) разделяем на n одинаковых подмассивов buckets
// 2) так как задействуем не все эти подмассивы, то асимптотика стремиться к O(N)
//
// Затраты по памяти ~O(n)
void BucketSort(vector<double> &data){
  long int n = data.size(); 
  vector <vector <double>> bucket(n, vector<double>()); 
  for (long int i=0; i<n; i++){
    long int index = n * data[i];
    bucket[index].push_back(data[i]);
  }

  for (long int i=0; i<n; i++){
    combSort(bucket[i]);
  }
  
  long int index = 0;
  for (long int i=0; i<n; i++){
    for (int j=0; j<bucket[i].size(); j++){
      data[index] = bucket[i][j];
      index ++;
    }
  }

}



void tests(){
	ofstream fout("output_test_bucket.txt");
	ofstream fout_time("output_time_bucket.txt");
	for (int i=0; i<7; i++){
		if (i == 3)
			continue;
		long int n;  
		clock_t start, end;
		start = clock();
		string a = to_string(i) + "input.txt";
		fstream fin(a);
		fin >> n; 
		vector <double> data(n); 
		for (long int i=0; i<n; i++){
			fin >> data[i]; 
		}
		BucketSort(data);
		
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		fout_time << time_taken << ' ';
		
//		for (long int i=0; i<n; i++)
//			fout << data[i] << ' ';
		fin.close();
	}
	fout_time.close();
	fout.close();
	
}

int main(){
  tests();
  long int n; 
  ifstream fin("input.txt"); 

  fin >> n; 
  vector <double> data(n);

  for (long int i=0; i<n; i++ ){
    fin >> data[i];
  }

  fin.close();
  BucketSort(data);
  ofstream fout("bucketOutput.txt");
  for (long int i=0; i<n; i++){
    fout << data[i] << ' ';
  }
  fout.close();
  return 0; 
}
