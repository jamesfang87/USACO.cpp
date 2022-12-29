// Source: https://usaco.guide/general/io

#include <utility>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	ifstream fin("triangles.in");
	ofstream fout("triangles.out");

	int nPoints; 
    fin >> nPoints;
	pair<int, int> points[nPoints];

	for (int i = 0; i < nPoints; i++) {
		pair<int, int> temp; fin >> temp.first >> temp.second;
        //cout << temp.first << temp.second;
        points[i] = temp;
 	}


    vector<bool> v(nPoints);
    fill(v.begin(), v.begin() + 3, true);

    int answer = 0;
    
    do {
        pair<int, int> temp[3];
        int times = -1;
        for (int i = 0; i < nPoints; ++i) {
            if (v[i]) {
                times++;
                //cout << points[i].first << ' ' << points[i].second << '\n';
                temp[times] = points[i];
                
            }
        }

        //cout << temp[0].first << ", " << temp[0].second << temp[1].first << ", " << temp[1].second << temp[2].first << ", " << temp[2].second;

        if (temp[0].first == temp[2].first && temp[0].second == temp[1].second) {
            answer = max(abs(temp[0].second - temp[2].second) * abs(temp[0].first - temp[1].first), answer);
            //cout << "changed to " << abs(temp[0].second - temp[2].second) * abs(temp[0].first - temp[1].first);
        }
        else if (temp[0].first == temp[1].first && temp[0].second == temp[2].second) {
            answer = max(abs(temp[0].first - temp[2].first) * abs(temp[0].second - temp[1].second), answer);
            //cout << "changed ";
        }
        else if (temp[0].first == temp[1].first && temp[1].second == temp[2].second) {
            answer = max(abs(temp[0].second - temp[1].second) * abs(temp[1].first - temp[1].first), answer);
            //cout << "changed ";
        }
        else if (temp[0].first == temp[2].first && temp[1].second == temp[2].second) {
            answer = max(abs(temp[0].second - temp[2].second) * abs(temp[1].first - temp[2].first), answer);
            //cout << "changed ";
        }
        else if (temp[0].second == temp[1].second && temp[1].first == temp[2].first) {
            answer = max(abs(temp[0].first - temp[1].first) * abs(temp[2].second - temp[1].second), answer);
            //cout << "changed ";
        }
        else if (temp[0].second == temp[2].second && temp[1].first == temp[2].first) {
            answer = max(abs(temp[0].first - temp[2].first) * abs(temp[2].second - temp[1].second), answer);
            //cout << "changed ";
        }

        
    } while (prev_permutation(v.begin(), v.end()));

    fout << answer;
    return 0;


}
