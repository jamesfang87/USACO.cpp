#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");

    int x, y; fin >> x >> y;
    int dir = 1;
    int i = 1;
    int distance = 0;

    while (true) {
        if ((dir == 1 && x <= y && y <= x + i) || (dir == -1 && x - i <= y && y <= x)) {
            distance += abs(y - x);
            fout << distance;
            return 0;
        }
        else {
            i *= 2;
            distance += i;
            dir *= -1;
        }
    }
}
