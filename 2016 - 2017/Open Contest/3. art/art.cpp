#include <fstream>
#include <string>
using namespace std;

int n;


bool found(int color, string square[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (stoi(square[i].substr(j, 1)) == color) return true;
        }
    }
    return false;
}


//if something another color is on top of color 2, then return true. else, return false
bool on_top(int color1, int color2, string square[]) {
    int t = n, b = 0, l = n, r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (stoi(square[i].substr(j, 1)) == color1) {
                t = min(t, i);
                b = max(b, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }

    for (int i = t; i <= b; i++) {
        for (int j = l; j <= r; j++) {
            if (stoi(square[i].substr(j, 1)) == color2) return true;
        }
    }
    return false;
}



int main() {
    ifstream fin("art.in");
    ofstream fout("art.out");

    fin >> n;

    string square[n];
    for (int i = 0; i < n; i++) {
        fin >> square[i];
    }

    int answer = 0;
    for (int i = 1; i <= 9; i++) {
        bool potential = false;
        if (found(i, square)) {
            potential = true;
            for (int j = 1; j <= 9; j++) {
                if (i != j && on_top(j, i, square)) potential = false;
            }
        }
        if (potential) {
            answer++;
        }
    }
    fout << answer;
}