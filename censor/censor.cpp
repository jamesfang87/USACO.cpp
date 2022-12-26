#include <fstream>
#include <string>

using namespace std;

int main () {
    ifstream fin("censor.in");
    ofstream fout("censor.out");

    string magazine;
    fin >> magazine ;

    string censored;
    fin >> censored;
    int position = 0;
    while (true) {
        int pos = magazine.find(censored, position);
        if (pos == string::npos) {
            break;
        }
        magazine.erase(pos, censored.size());

    }
        
    
    fout << magazine;
}