#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int n, m; // n is the number of pastures, m is the number of cows
    fin >> n >> m;
    vector<int> adjacent[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b; fin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    int answer[n + 1]; fill(answer, answer + n + 1, 0);

    for (int i = 1; i <= n; i++) {
        vector<int> possible = {1, 1, 1, 1};

        for (int p : adjacent[i]) {
            if (answer[p] != 0) possible[answer[p] - 1] = 0;
        }

        for (int j = 1; j <= 4; j++) {
            if (possible[j - 1] == 1)  {
                answer[i] = j;
                break;
            }

        }

    }

    for (int i = 1; i <= n; i++) {
        fout << answer[i];
    }

}