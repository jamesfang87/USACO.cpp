#include <bits/stdc++.h>
using namespace std;


int main () {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int n_cows, n_genes;
    fin >> n_cows >> n_genes;

    string plain[n_cows];
    string spotty[n_cows];
    
    for (int i = 0; i < n_cows; i++) {
       fin >> spotty[i];
       
    }

    for (int i = 0; i < n_cows; i++) {
        fin >> plain[i];
    }

    int count = 0;
    for (int pos = 0; pos < n_genes; pos++) {
        char spotty_genotype[n_cows];
        char plain_genotype[n_cows];

        for (int cow = 0; cow < n_cows; cow++) {
            spotty_genotype[cow] = spotty[cow][pos];
            plain_genotype[cow] = plain[cow][pos];
        }
        
        sort(plain_genotype, plain_genotype + n_cows);
        sort(spotty_genotype, spotty_genotype + n_cows);

        string str_intersection;
        set_intersection(plain_genotype, plain_genotype + n_cows, spotty_genotype, spotty_genotype + n_cows, back_inserter(str_intersection));
        if (str_intersection == "") {
            count++;
        }
    }
    fout << count;
}