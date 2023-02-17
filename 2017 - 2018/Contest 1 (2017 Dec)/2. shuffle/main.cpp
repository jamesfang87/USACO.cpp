#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int n; fin >> n;
    int shuffle[n], end_pos[n], start_pos[n];
    for (int i = 0; i < n; i++) {
        fin >> shuffle[i];
    }

    for (int i = 0; i < n; i++) {
        fin >> end_pos[i];
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            start_pos[j] = end_pos[shuffle[j] - 1];
        }
        for (int j = 0; j < n; j++) {
            end_pos[j] = start_pos[j];
        }
    }

    for (int i = 0; i < n; i++) {
        fout << end_pos[i] << '\n';
    }
}
