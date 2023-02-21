#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    int a, b, c;
    fin >> a >> b >> c;


    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);


    if (a + 1 == b && b + 1 == c && a + 2 == c) {
        fout << 0 << '\n';
    }
    else if (a + 2 == b || b + 2 == c) {
        fout << 1 << '\n';
    }
    else {
        fout << 2 << '\n';
    }

    fout << max(b - a, c - b) - 1 << "\n";
    return 0;
}
