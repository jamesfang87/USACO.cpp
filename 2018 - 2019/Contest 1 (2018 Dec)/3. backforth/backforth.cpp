#include <iostream>
#include <fstream>
#include <iterator>
#include <unordered_set>
#include <vector>
#include <set>
using namespace std;


unordered_set<int> possible_answers;


void friday(vector<int> a, vector<int> b, int amount) {
    for (int i = 0; i < b.size(); i++) {
        int x = b[i];
        possible_answers.insert(amount + x);
    }
}


void thursday(vector<int> a, vector<int> b, int amount) {
    for (int i = 0; i < a.size(); i++) {
        int temp = amount - a.at(i);
        vector<int> new_a = a;
        vector<int> new_b = b;
        new_a.erase(new_a.begin() + i);
        new_b.push_back(a.at(i));
        friday(new_a, new_b, temp);
    }
}


void wednesday(vector<int> a, vector<int> b, int amount) {
    for (int i = 0; i < b.size(); i++) {
        int temp = amount + b.at(i);
        vector<int> new_a = a; 
        vector<int> new_b = b; 
        new_a.push_back(b.at(i));
        new_b.erase(new_b.begin() + i);
        thursday(new_a, new_b, temp);
    }
}


void tuesday(vector<int> a, vector<int> b, int amount) {
    for (int i = 0; i < a.size(); i++) {
        int temp = a[i];
        vector<int> new_a = a; 
        vector<int> new_b = b; 
        new_a.erase(new_a.begin() + i);
        new_b.push_back(temp);
        wednesday(new_a, new_b, amount - temp);
    }
}


int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");

    vector<int> a, b;
    int amountA = 1000;

	for (int i = 0; i < 10; i++) {
		int temp; fin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i < 10; i++) {
		int temp; fin >> temp;
		b.push_back(temp);
	}

    tuesday(a, b, 1000);

    fout << possible_answers.size();
    return 0;
}