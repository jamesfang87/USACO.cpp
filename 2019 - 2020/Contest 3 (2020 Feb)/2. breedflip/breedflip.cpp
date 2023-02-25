#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    int n; fin >> n;

    string needed; fin >> needed;
    string current; fin >> current;


    bool needs_change[n];

    for (int i = 0; i < n; i++) {
        if (needed[i] != current[i]) needs_change[i] = true;
        else needs_change[i] = false;
    }

    int answer = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        
        if (needs_change[i] == true) {
            needs_change[i] = false;
            count++;
            
        }
        else {
            if (count > 0) {
                count = 0;
                answer++;
            }
        }
    }
    fout << answer;
}