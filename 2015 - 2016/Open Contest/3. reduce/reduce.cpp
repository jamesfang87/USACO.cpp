#include <bits/stdc++.h>
using namespace std;


int main() {
	ifstream fin("reduce.in");
	ofstream fout("reduce.out");

	int n; fin >> n;
	vector<int> xCo, yCo;

	for (int i = 0; i < n; i++) {
		int tempX, tempY; fin >> tempX >> tempY;
		xCo.push_back(tempX), yCo.push_back(tempY);

	}


	unsigned long long answer = 18446744073709551615ULL;
	int answer_at = 0;
	pair<int, int> removed;
	pair<int, int> bruh;
	for (int i = 0; i < n; i++) {
		removed.first = xCo.at(i), removed.second = yCo.at(i);
		xCo.erase(xCo.begin() + i), yCo.erase(yCo.begin() + i);
		unsigned long long area = (*max_element(xCo.begin(), xCo.end()) - *min_element(xCo.begin(), xCo.end())) * (*max_element(yCo.begin(), yCo.end()) - *min_element(yCo.begin(), yCo.end()));
		xCo.insert(xCo.begin() + i, removed.first);
		yCo.insert(yCo.begin() + i, removed.second);
		answer = min(answer, area);
	}
	fout << answer;
}
