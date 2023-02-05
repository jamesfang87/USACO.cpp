#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("crossroad.in");
    ofstream fout("crossroad.out");
    int n; fin >> n;

    int seen[10];
    fill(seen, seen + 10, -1);


    int num = 0;
    for (int i = 0; i < n; i++) {
        int cow, side; fin >> cow >> side;
        if (seen[cow - 1] >= 0 and side != seen[cow - 1]) {
            num++;
        }
        seen[cow - 1] = side;
    }
    fout << num;
}