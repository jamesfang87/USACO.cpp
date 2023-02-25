#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    int n, k;
    fin >> n >> k;

    pair<int, int> seq1, seq2;
    fin >> seq1.first >> seq1.second;
    fin >> seq2.first >> seq2.second;
    seq1.first--; seq2.first--;

    vector<int> order (n);
    for (int i = 0; i < n; i++) {
        order[i] = i + 1;
    }

    int period = -1;
    vector<vector<int>> prev = {order};
    for (int i = 0; i < k; i++) {
        reverse(order.begin() + seq1.first, order.begin() + seq1.second);
        reverse(order.begin() + seq2.first, order.begin() + seq2.second);
        prev.emplace_back(order);
        
        if (count(prev.begin(), prev.end(), order) > 1) {
            period = prev.size() - 1;
            break;
        }
    }

    if (period != -1) {
        int remainder = k % period;
        for (int i : prev[remainder]) {
            fout << i << '\n';
        }
    }
    else {
        for (int i : order) {
            fout << i << '\n';
        }
    }
}