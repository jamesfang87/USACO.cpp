#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int n, k; fin >> n >> k;
    int sizes[n];

    for (int i = 0; i < n; i++) {
        fin >> sizes[i];
    }



    int maximum = 0;
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (sizes[i] >= sizes[j] && sizes[i] - sizes[j] <= k) {
                count++;
            }
        }
        maximum = max(count, maximum);
    }
    fout << maximum;
}