#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    string road; fin >> road;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    vector<bool> v(26);
    fill(v.begin(), v.begin() + 2, true);

    int crosses = 0;

    for (char letter : alphabet) {
        for (char other_letter : alphabet) {
            pair<int, int> char1 , char2;
            char1.first = road.find(letter);
            char1.second = road.find_last_of(letter);
            char2.first = road.find(other_letter);
            char2.second = road.find_last_of(other_letter);

            
            if (char1 != char2) {
                if ((char1.first < char2.first && char2.first < char1.second) && (char2.first < char1.second && char1.second < char2.second)) {
                    crosses++;
                }
            }
        }
    }
    fout << crosses;
}