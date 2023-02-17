#include <bits/stdc++.h>
using namespace std;

struct Object {
    int x1, y1, x2, y2;
    int area() { return (y2 - y1) * (x2 - x1); }
};

int intersect(Object p, Object q) {
    int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
    int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
    return xOverlap * yOverlap;
}

int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    Object b1, b2, truck;  // billboards a, b, and the truck
    fin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    fin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    fin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;
    fout << b1.area() + b2.area() - intersect(b1, truck) - intersect(b2, truck) << endl;
}