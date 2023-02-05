#include <bits/stdc++.h>
using namespace std;


int check(vector<pair<int, int>> logs, vector<pair<int, int>> win_key) {
    int num = 0;
    for (auto x : logs) {
        for (auto key : win_key) {
            if (x == key) num++;
        }
    }
    return num;
}


int main() {
    // 1 beats 3 and 3 beats 2 and 2 beats 1
    // 1 beats 2 and 2 beats 3 and 3 beats 1

    ifstream fin("hps.in");
    ofstream fout("hps.out");
    
    int n; fin >> n;

    vector<pair<int, int>> logs (n);
    for (int i = 0; i < n; i++) {
        fin >> logs[i].first >> logs[i].second;
    }

    fout << max(check(logs, {{1, 3}, {3, 2}, {2, 1}}), check(logs, {{1, 2}, {2, 3}, {3, 1}}));
}