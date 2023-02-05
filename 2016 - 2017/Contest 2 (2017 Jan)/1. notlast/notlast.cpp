#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
    int n; fin >> n;


    map<string, int> cow_values = {{"Bessie", 0},
                                    {"Elsie",  0}, 
                                    {"Daisy", 0},
                                    {"Gertie", 0},
                                    {"Annabelle", 0},
                                    {"Maggie", 0},
                                    {"Henrietta", 0}};
    
    for (int i = 0; i < n; i++) {
        string cow; int increase;
        fin >> cow >> increase;
        cow_values[cow] += increase;
    }

    int least = 9999999;
    for (auto x : cow_values) {
	    least = min(least, x.second);
    }


    int second_least = 99999;
    int num = 0;
    string cow = "Tie";
    for (auto x : cow_values) {
        if (x.second != least && x.second <= second_least) {
            second_least = x.second;
            cow = x.first;
        }
    }
    

    for (auto x : cow_values) {
        if (x.second == second_least) {
            num ++;
        }
    }


    if (num > 1) {
        fout << "Tie";
    }
    else {
        fout << cow;
    }
}