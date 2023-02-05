#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("square.in");
    ofstream fout("square.out");

    pair<int, int> bottomleft1;
    pair<int, int> topright1;
    pair<int, int> bottomleft2;
    pair<int, int> topright2;
    //      x                    y                         x                  y
    fin >> bottomleft1.first >> bottomleft1.second >> topright1.first >> topright1.second;
    fin >> bottomleft2.first >> bottomleft2.second >> topright2.first >> topright2.second;

    int answer_X = max(topright1.first, topright2.first) - min(bottomleft1.first, bottomleft2.first);
    int answer_Y = max(topright1.second, topright2.second) - min(bottomleft1.second, bottomleft2.second);
    fout << max(answer_X * answer_X, answer_Y * answer_Y);
}