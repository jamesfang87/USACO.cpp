#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");
    int n; fin >> n;

    vector<string> field (n);
    for (int i = 0; i < n; i++) {
        fin >> field[i];
    }

    int flips = 0;
    for (int y = n - 1; y >= 0; y--) {
        for (int x = n - 1; x >= 0; x--) {
            if (field[y][x] == '1') {
                //flip the field

                flips++;
                for (int i = 0; i <= y; i++) {
                    for (int j = 0; j <= x; j++) {
                        if (field[i][j] == '0') field[i][j] = '1';
                        else field[i][j] = '0';
                    }
                }
            }
        }
    }
    fout << flips;
}