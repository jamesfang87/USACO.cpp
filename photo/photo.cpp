#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("photo.in");
    ofstream fout("photo.out");

    int num; fin >> num;

    int array[num - 1];
    int answer[num];

    for (int i = 0; i < num - 1; i++) {
        fin >> array[i];
    }

    //bool breakNow = false;

    for (int i = 1; i < array[0]; i++) {
        fill(answer, answer + num, 0);
        answer[0] = i;


        for (int j = 0; j < num; j++) {
            answer[j + 1] = array[j] - answer[j];
            if (count(answer, answer + num, answer[j + 1]) != 1) {
                break;
            }
        }
        // the way an answer can be wrong is if it's a duplicate of a number used before or it is out of the range [1, N]
        
        if (*max_element(answer, answer + num) == num && *min_element(answer, answer + num) == 1) {
            for (int i = 0; i < num; i++) {
                fout << answer[i];
                if (i != num - 1) {
                    fout << ' ';
                }
                
            }
        }
        else {
            continue;
        }
        
        
    }

    


}