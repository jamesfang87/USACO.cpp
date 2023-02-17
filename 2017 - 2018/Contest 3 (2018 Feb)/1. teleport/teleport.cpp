#include <bits/stdc++.h>
using namespace std;

bool is_between(int test, int lower, int upper) {
    if (lower <= test && test <= upper) 
        return true;
    return false;
}


int main() {
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    int start, end;
    fin >> start >> end;

    if (start > end)
        swap(start, end);

    int portal_start, portal_end;
    fin >> portal_start >> portal_end;

    if (portal_start > portal_end)
        swap(portal_start, portal_end);


    int guaranteed = end - start;
    
    if (is_between(portal_start, start, end) && is_between(portal_end, start, end)) {
        fout << (portal_start - start) + (end - portal_end);
    }

    else if (portal_start < start && portal_end < end) {
        fout << min(guaranteed, (start - portal_start) + (end - portal_end));
    }
    else if (start < portal_start && end < portal_end) {
        fout << min(guaranteed, (portal_start - start) + (portal_end - end));
    }

    else if (portal_start < start && end < portal_end) {
        fout << min(guaranteed, (start - portal_start) + (portal_end - end));
    }
    else {
        fout << guaranteed;
    }
}