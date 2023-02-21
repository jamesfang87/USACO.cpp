#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    int n; fin >> n;
    int order[n];

    for (int i = 0; i < n; i++) {
        fin >> order[i];
    }

    int answer = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (order[i] < order[i + 1]) {
            answer = i;
        }
        else {
            break;
        }
    }
    fout << answer;
}
