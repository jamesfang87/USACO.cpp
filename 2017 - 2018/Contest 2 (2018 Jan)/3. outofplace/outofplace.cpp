#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");

    int n; fin >> n;
    int heights[n];
    int before[n];
    
    for (int i = 0; i < n; i++) {
        int temp; fin >> temp;
        heights[i] = temp;
        before[i] = temp;
    }
    
    sort(heights, heights +  n);
    
    int counter = -1;
    for (int i = 0; i < n; i++) {
        if (heights[i] != before[i]) {
            counter++;
        }
    }

    fout << max(0, counter);
}