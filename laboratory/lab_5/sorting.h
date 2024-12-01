// sorting.h
#ifndef SORTING_H
#define SORTING_H

#include <vector>

#define ll long long
using namespace std;


void shaker_sort(vector <ll> &ass);
void merge(vector<ll> &ass, int l, int r);
void merge_sort(vector <ll> &ass, int left, int right);
void heap(vector <ll> &ass, int n, int jj);
void heap_sort(vector <ll> &ass);


#endif
