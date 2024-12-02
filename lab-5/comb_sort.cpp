#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// средняя немного лучше O(N^2)
void combSort(vector<long int> &data){
  double factor = 1.247; // шаг вычесленный математически
  long int gap = data.size() - 1; 
  bool swaped = false;
  while (gap > 1 || swaped){
    swaped = false;
    for (long int i=0; i+gap<data.size(); i++){
      if (data[i] > data[i + gap]){
        swap(data[i], data[i+gap]);
        swaped = true;
      } 
    }
    if (gap > 1)
      gap /= factor;
    else if(gap <= 1)
      gap = 1;
  }
}

void tests(){
	ofstream fout("output_test_comb.txt");
	ofstream fout_time("output_time_comb.txt");
	for (int i=0; i<7; i++){
		long int n;  
		clock_t start, end;
		start = clock();
		string a = to_string(i) + "input.txt";
		fstream fin(a);
		fin >> n; 
		vector <long int> data(n); 
		for (long int i=0; i<n; i++){
			fin >> data[i]; 
		}
		combSort(data);
		
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		fout_time << time_taken << ' ';
		
		for (long int i=0; i<n; i++)
			fout << data[i] << ' ';
		fin.close();
	}
	fout_time.close();
	fout.close();
	
}


int main(){
  long int n;  
//  tests();
  fstream fin("input.txt");
  fin >> n; 
  vector <long int> data(n); 
  for (long int i=0; i<n; i++){
    fin >> data[i]; 
  }
  combSort(data);
  ofstream fout("output.txt");
  for (long int i=0; i<n; i++)
    fout << data[i] << ' ';
  fout.close();
  fin.close();
  return 0; 
}
