#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int n;

struct Animal {
    string species;
    vector<string> attributes;
};

int max_alike(vector<Animal> animals) {
    int maximum = 0;
    vector<bool> v(n); fill(v.begin(), v.begin() + 2, true);

    do {
        vector<int> comb = {};
        for (int i = 0; i < n; i++) {
            if (v[i]) comb.push_back(i);
        }

        vector<string> common_attributes;
        sort(all(animals[comb[0]].attributes));
        sort(all(animals[comb[1]].attributes));

        set_intersection(all(animals[comb[0]].attributes), all(animals[comb[1]].attributes),
                         back_inserter(common_attributes));

        maximum = max(maximum, (int) common_attributes.size());

    } while (prev_permutation(v.begin(), v.end()));

    return maximum;
}


int main() {
    ifstream fin("guess.in");
    ofstream fout("guess.out");

    fin >> n;

    vector<Animal> animals (n);
    for (int i = 0; i < n; i++) {
        string temp_species; fin >> temp_species;
        int num; fin >> num;
        vector<string> temp_attributes;

        for (int j = 0; j < num; j++) {
            string temp_attribute; fin >> temp_attribute;
            temp_attributes.push_back(temp_attribute);
        }
        animals[i] = {temp_species, temp_attributes};
    }
    fout << max_alike(animals) + 1;
}