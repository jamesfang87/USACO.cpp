#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("taming.in");
    ofstream fout("taming.out");
    int days; fin >> days;

    int log[days];
    for (int i = 0; i < days; i++) {
        fin >> log[i];
    }

    
    log[0] = 0;
    for (int i = days - 1; i >= 0; i--) {
        if (log[i] >= 0) {
            for (int j = log[i]; j >= 0; j--) {
                if (log[i - j] < 0) {
                    log[i - j] = log[i] - j;
                }
            }
        }
    }


    if (log[0] != 0) {
        fout << -1;
        return 0;
    }
    else {
        int expected = 1;
        for (int i = 1; i < days; i++) {
            if (log[i] > 0 && log[i] != expected) {
                fout << -1;
                return 0;
            }
            else if (log[i] == 0) {
                expected = 1;
            }
            else {
                expected++;
            }
        }
    }
    
    int minimum = count(log, log + days, 0);
    int maximum = minimum + count(log, log + days, -1);;
    fout << minimum << ' ' << maximum;
}