#include <bits/stdc++.h>
using namespace std;

int n;


int explode_left(int haybales[], int start) {
    int num_exploded = 0;
    int radius = 1;


    while (true) {
        int lower = haybales[start] - radius;
        int newly_exploded = 0;

        for (int i = start - 1; i >= 0; i--) {
            if (haybales[i] >= lower) {
                newly_exploded++;
                start--;
            }
            else {
                break;
            }
        }
        num_exploded += newly_exploded;

        if (newly_exploded == 0) {
            break;
        }
        else {
            radius++;
        }
    }
    return num_exploded;
}



int explode_right(int haybales[], int start) {
    int num_exploded = 0;
    int radius = 1;

    while (true) {
        int upper = haybales[start] + radius;
        int newly_exploded = 0;

        for (int i = start + 1; i <= n - 1; i++) {
            if (haybales[i] <= upper) {
                newly_exploded++;
                start++;
            }
            else {
                break;
            }
        }
        num_exploded += newly_exploded;

        if (newly_exploded == 0) {
            break;
        }
        else {
            radius++;
        }  
    }
    return num_exploded;
}



int main() {
    ifstream fin("angry.in");
    fin >> n;

    int haybales[n];
    for (int i = 0; i < n; i++) {
        fin >> haybales[i];
    }
    sort(haybales, haybales + n);

    int maximum = 0;
    for (int i = 0; i < n; i++) {
        int temp_total = 1 + explode_left(haybales, i) + explode_right(haybales, i);
        maximum = max(temp_total, maximum);
    }

    ofstream fout("angry.out");
    fout << maximum;
}