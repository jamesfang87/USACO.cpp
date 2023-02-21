#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");
    int n; fin >> n;

    int upper[n], lower[n];
    string type[n];

    for (int i = 0; i < n; i++) {
        fin >> type[i] >> lower[i] >> upper[i];
    }

    int start_min = -999999999, start_max = 999999999;
    for (int i = n - 1; i >= 0; i--) {
        if (type[i] == "on") {
            start_min -= upper[i]; start_max -= lower[i]; start_min = max(0, start_min);
        }
        else if (type[i] == "off") {
            start_min += lower[i]; start_max += upper[i];
        }
        else {
            start_min = max(start_min, lower[i]); start_max = min(start_max, upper[i]);
        }
    }
    fout << start_min << " " << start_max << "\n";

    int end_min = -999999999, end_max = 999999999;
    for (int i = 0; i < n; i++) {
        if (type[i] == "on") {
            end_min += lower[i]; end_max += upper[i];
        }
        else if (type[i] == "off") {
            end_min -= upper[i]; end_max -= lower[i]; end_min = max(0, end_min);
        }
        else {
            end_min = max(end_min, lower[i]); end_max = min(end_max, upper[i]);
        }
    }
    fout << end_min << " " << end_max << "\n";

}