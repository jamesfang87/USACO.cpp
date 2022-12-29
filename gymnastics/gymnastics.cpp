// Source: https://usaco.guide/general/io

#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;



int cows, days; 

vector<vector<int>> info;



bool check(int i, int j) {
	for (int day = 0; day < days; day++) {
		if (find(info[day].begin(), info[day].end(), i) > find(info[day].begin(), info[day].end(), j)) {
			return false;
		}
	}
	return true;
}


int main() {
	ifstream fin("gymnastics.in");
	ofstream fout("gymnastics.out");
	fin >> days >> cows;

	for (int i = 0; i < days; i++) {
		vector<int> temp (cows);
		for (int j = 0; j < cows; j++) {
			fin >> temp[j];
		}
		info.push_back(temp);
	}
	/*
	for (vector<int> day : info) {
		for (int place : day) {
			cout << place << ' ';
		}
		cout << '\n';
	}
	*/
	
	int answer = 0;
	for (int i = 1; i <= cows; i++) {
		for (int j = 1; j <= cows; j++) {
			if (i != j) {
				
				if (check(i, j)) {
					answer++;
				}
				
			}
		}
	}
	fout << answer;
}
