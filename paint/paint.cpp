#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;


int main() {
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    /*
    std::pair<int, int> pair;
    fin >> pair.first >> pair.second;
    std::pair<int, int> pair2;
    fin >> pair2.first >> pair2.second;



    if (pair2.first < pair.first) {
        if (pair2.second <= pair.first) {
            fout << (pair2.second - pair2.first) + (pair.second - pair.first);
        }
        else {
            fout << (max(pair2.second, pair.second) - pair2.first);
        }
    }
    else if (pair.first < pair2.first) {
        if (pair.second <= pair2.first) {
            fout << (pair2.second - pair2.first) + (pair.second - pair.first);
        }
        else {
            fout << (max(pair2.second, pair.second) - pair.first);
        }
    }
    else if (pair.first == pair2.first) {
        fout << max(pair.second, pair2.second) - pair.first;
    }
    */

    int a, b, c, d;
	fin >> a >> b >> c >> d;

	int total = (b - a) + (d - c);  // the sum of the two intervals
	int intersection = max(min(b, d) - max(a, c), 0);  // subtract the intersection
	int ans = total - intersection;

	fout << ans << "\n";
}