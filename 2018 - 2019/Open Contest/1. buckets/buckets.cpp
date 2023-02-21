#include <bits/stdc++.h>
using namespace std;

struct Object {
    int x, y;
};

int main() {
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");
    Object barn{};
    Object rock{};
    Object lake{};

    for (int i  = 0; i < 10; i++) {
        string temp; fin >> temp;

        for (int j = 0; j < 10; j++) {
            if (temp.substr(j, 1) == "B") barn.x = j, barn.y = i;
            else if (temp.substr(j, 1) == "R") rock.x = j, rock.y = i;
            else if (temp.substr(j, 1) == "L") lake.x = j, lake.y = i;
        }
    }

    //if (barn.x != lake.x && barn.y != lake.y)
    int dist_br = abs(barn.x - rock.x) + abs(barn.y - rock.y);
    int dist_bl = abs(barn.x - lake.x) + abs(barn.y - lake.y);
    int dist_rl = abs(rock.x - lake.x) + abs(rock.y - lake.y);

    if ((barn.x == lake.x || barn.y == lake.y) && dist_bl == dist_br + dist_rl)
        fout << dist_bl + 1 << "\n";
    else
        fout << dist_bl - 1 << "\n";
}