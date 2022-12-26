//bruh idfk just find like the most bottom-left corner and
// like the most top-right corner and like just fit a square or smth fuck this

#include <fstream>
#include <utility>
#include <iostream>

using namespace std;


int main() {
    ifstream fin("square.in");
    ofstream fout("square.out");

    std::pair<int, int> bottomleft1;
    std::pair<int, int> topright1;
    std::pair<int, int> bottomleft2;
    std::pair<int, int> topright2;
    //      x                    y                         x                  y
    fin >> bottomleft1.first >> bottomleft1.second >> topright1.first >> topright1.second;
    fin >> bottomleft2.first >> bottomleft2.second >> topright2.first >> topright2.second;

    int answer_X = max(topright1.first, topright2.first) - min(bottomleft1.first, bottomleft2.first);
    int answer_Y = max(topright1.second, topright2.second) - min(bottomleft1.second, bottomleft2.second);
    fout << max(answer_X * answer_X, answer_Y * answer_Y);
}
