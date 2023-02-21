#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("factory.in");
    ofstream fout("factory.out");
    int n;
    read >> n;

    vector<vector<int>> adjacent(n);
    for (int w = 0; w < n - 1; w++) {
        int s1, s2;
        read >> s1 >> s2;
        adjacent[--s2].push_back(--s1);
    }


    int answer = -1;

    for (int s = 0; s < n; s++) {
        vector<bool> visited(n);
        visited[s] = true;

        vector<int> todo{s};
        while (!todo.empty()) {
            int curr = todo.back();
            todo.pop_back();
            for (int a : adjacent[curr]) {
                if (!visited[a]) {
                    visited[a] = true;
                    todo.push_back(a);
                }
            }
        }

        if (count(visited.begin(), visited.end(), false) == 0) {
            answer = s + 1;
        }
    }
    fout << answer;
}
