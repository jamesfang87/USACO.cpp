#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");

    int a, b, c;
    fin >> a >> b >> c;

    int answer = 0;
    for (int i = 0; i <= c / a; i++) {
        int diffModB = (c - i * a) % b;
        int total = c - diffModB;
        answer = max(answer, total);
    }
    fout << answer;
}
