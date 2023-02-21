#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int num;
    fin >> num;

    vector<int> shells = {0, 1, 2}; //positions of the shells
    vector<int> choosen = {0, 0, 0}; //number of times that shells 1, 2, 3 were chosen

    for (int i = 0; i < num; i++) {
        int a, b, g;
        fin >> a >> b >> g;
        a--, b--, g--;

        swap(shells.at(a), shells.at(b));
        choosen.at(shells.at(g))++;
    }
    fout << *max_element(choosen.begin(), choosen.end());
}