#include <iostream>
#include <fstream>
#include <set>
#include <numeric>

using namespace std;

void solve() {
    ifstream fin("sleeping.in");
    int n; cin >> n;
    //cin >> n;

    int numbers[n];
    int sum = 0;
    for (int j = 0; j < n; j++) {
        cin >> numbers[j];
        sum += numbers[j];
        //cin >> numbers[j];
    }
        
    
    for (int divisor = n; divisor >= 1; divisor--) {
        //check if you can make sum divided by divisor
        //divisor is also the number of segments
        if (sum % divisor == 0) {
            int segment_sum = 0;
                    //int num_segments = divisor;
            int needed_sum = sum / divisor;
                    //int num_successful = 0;
            bool ok = true;
            for (int number : numbers) {
                segment_sum += number;
                if (segment_sum > needed_sum) {
                    ok = false;
                    break;
                }
                else if (segment_sum == needed_sum) {
                    segment_sum = 0;
                }
            }
            if (ok) {
                cout << n - divisor << '\n';
                return;
            }   
        }
    }
}



int main() {
    ifstream fin("sleeping.in");
    int n_test; cin >> n_test;
    //cin >> n_test;

    for (int i = 0; i < n_test; i++) {
        solve();
    } 
}
    
