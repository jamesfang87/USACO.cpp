#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");

    pair<int, int> coords = {1000, 1000};

    int num;
    fin >> num;
    int t = 0;
    int field[2001][2001] = {0};
    int answer = 999999999;
    for (int i = 0; i < num; i++) {
        char dir;
        int steps;
        fin >> dir >> steps;
        if (dir == 'N') {
            for (int j = 1; j <= steps; j++) {
                t++;
                coords.second++;
                if (field[coords.first][coords.second] != 0) {
                    int last = field[coords.first][coords.second];
                    if (last < answer) {
                        answer = last;
                    }
                }
                field[coords.first][coords.second] = t;
            }
        }
        else if (dir == 'E') {
            for (int j = 1; j <= steps; j++) {
                t++;
                coords.first++;
                if (field[coords.first][coords.second] != 0) {
                    int last = field[coords.first][coords.second];
                    if (last < answer) {
                        answer = last;
                    }
                }
                field[coords.second][coords.first] = t;
            }
            
        }
        else if (dir == 'W') {
            for (int j = 1; j <= steps; j++) {
                t++;
                coords.first--;
                if (field[coords.second][coords.first] != 0) {
                    int last = field[coords.first][coords.second];
                    if (last < answer) {
                        answer = last;
                    }
                }
                field[coords.second][coords.first] = t;
            }
        }
        else {
            for (int j = 1; j <= steps; j++) {
                t++;
                coords.second--;
                if (field[coords.second][coords.first] != 0) {
                    int last = field[coords.first][coords.second];
                    if (last < answer) {
                        answer = last;
                    }
                }
                field[coords.second][coords.first] = t;
            }   
        }
    }
    if (answer != 999999999) {
        fout << -1 << '\n';
    }
    else {
        fout << answer;
    }
}
