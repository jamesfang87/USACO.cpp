#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("family.in");
    ofstream fout("family.out");

    int q; fin >> q;

    while(q--) {
        string text; fin >> text;
        if (text.length() < 3) {
            fout << "-1\n";
        }
        else if (text == "MOO") {
            fout << "0\n";
        }
        else if (count(text.begin(), text.end(), 'M') == 0) {
            fout << 0 + (text.length() - 3) + 1 << '\n';
        }
        else if (text.find("MO") == string::npos) {
            fout << "-1\n";
        }
        else if (text.find("MO") >= text.length() - 2) {
            fout << "-1\n";
        }
        else if (text.find("MOO") != string::npos) {
            fout << text.length() - 3 << '\n';
        }
        else if (text.find("MO") < text.length() - 2) {
            fout << 0 + (text.length() - 3) + 1 << '\n';
        }
        else if (text.find("OOO") != string::npos) {
            fout << (text.length() - 3) + 1 << '\n';
        }
        else if (text.find("OO") != string::npos) {
            fout << (text.length() - 3) + 2 << '\n';
        }
    }

    /*
    int n; fin >> n;
    string bessie, elise; fin >> bessie >> elise;

    pair<string, string> log[n];
    for (int i = 0; i < n; i++) {
        fin >> log[i].first >> log[i].second;
    }

    //i think we can just check all the possible types of relationships.

    string mother = "-11111";
    string first;
    int i = 0;
    for (; i < n; i++) {
        if (log[i].second == bessie) {
            mother = log[i].first;
            first = bessie;
            break;
        }
        else if (log[i].second == elise) {
            mother = log[i].first;
            first = elise;
            break;
        }
    }

    for (; i < n; i++) {
        if (log[i].first == mother && first == bessie && log[i].second == elise) {
            fout << "SIBLINGS";
            return 0;
        }
        else if (log[i].first == mother && first == elise && log[i].second == bessie) {
            fout << "SIBLINGS";
            return 0;
        }
    }
    */

    
}