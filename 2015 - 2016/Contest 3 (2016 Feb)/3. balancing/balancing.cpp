#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

struct cow_struct {
    int x, y;
};

int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int n, m; 
    fin >> n >> m;

    vector<cow_struct> cows (n);
    set<int> xLocations, yLocations;

    for (int i = 0; i < n; i++) {
        fin >> cows[i].x >> cows[i].y;
        xLocations.insert(cows[i].x);
        yLocations.insert(cows[i].y);
    }


    int answer = n;
    for (int xIndex = 0; xIndex < xLocations.size(); xIndex++) {
        for (int yIndex = 0 ; yIndex < yLocations.size(); yIndex++) {
            int quadrants[4] = {0, 0, 0, 0};
            int xAxis = *next(xLocations.begin(), xIndex) + 1;
            int yAxis = *next(yLocations.begin(), yIndex) + 1;
            
            for (cow_struct cow: cows) {
                if (cow.x > xAxis && cow.y > yAxis) {
                    quadrants[0]++;
                }
                else if (cow.x < xAxis && cow.y > yAxis) {
                    quadrants[1]++;
                }
                else if (cow.x < xAxis && cow.y < yAxis) {
                    quadrants[2]++;
                }
                else if (cow.x > xAxis && cow.y < yAxis) {
                    quadrants[3]++;
                }
            }
            answer = min(*max_element(quadrants, quadrants + 4), answer);
        }
    }
    fout << answer;
}