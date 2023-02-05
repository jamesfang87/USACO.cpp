#include <bits/stdc++.h>
using namespace std;


vector<int> count_freq(string s) {
	vector<int> freq(26);
	for (char c : s) {
		freq[c - 'a']++;
	}
	return freq;
}


int main() {
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");

    int n; fin >> n;
    vector<pair<string, string>> pairs (n);


    for (int i = 0; i < n; i++) {
        fin >> pairs[i].first >> pairs[i].second;
    }

    vector<int> max_blocks(26);
    fill(max_blocks.begin(), max_blocks.end(), 0);

    for (auto i : pairs) {
        vector<int> freq1 = count_freq(i.first);
        vector<int> freq2 = count_freq(i.second);
        for (int c = 0; c < 26; c++) {
            max_blocks[c] += max(freq1[c], freq2[c]);
        }
    }

    for (int c = 0; c < 26; c++) {
        fout << max_blocks[c] << '\n';
    }
    return 0;
}