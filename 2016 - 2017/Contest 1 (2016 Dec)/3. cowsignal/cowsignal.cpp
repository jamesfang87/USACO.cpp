#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");

    int y, x, k;
    fin >> y >> x >> k;


    string original[y];
    for (int i = 0; i < y; i++) {
        fin >> original[i];
    }

    for (int i = 0; i < y; i++) {
        string line(x * k, '.');
        for (int j = 0; j < x; j++) {
            string asdf = original[i].substr(j,  1);
            if (asdf.compare("X") == 0) {
                for (int a = j * k; a < (j + 1) * k; a++) {
                    line[a] = 'X';
                }
            }
        }
        for (int b = 0; b < k; b++) {
            fout << line << '\n';
        }
    }
}