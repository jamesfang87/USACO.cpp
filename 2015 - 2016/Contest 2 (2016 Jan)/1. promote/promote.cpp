#include <bits/stdc++.h>
using namespace std;


struct Contest{
    int before, after;
};


int main() {
    ifstream fin("promote.in");
    ofstream fout("promote.out");

    Contest bronze, silver, gold, plat;

    fin >> bronze.before >> bronze.after;
    fin >> silver.before >> silver.after;
    fin >> gold.before >> gold.after;
    fin >> plat.before >> plat.after;
    
    //how do we figure out how many people promoted from gold to plat? We can just simply find the difference
    //silver to gold is a bit more complicated.  We will have to suppose that no one promoted from gold to plat
    //essentially, we pretend that no one left gold- people only joined the gold division.
    //silver is the same.  suppose that no one promoted out of silver.  Lucky, we have already calculated this.
    //it is simply the number of people in the var silver_to_gold

    int gold_to_plat = plat.after - plat.before; 
    int silver_to_gold = gold.after - gold.before + gold_to_plat; 
    int bronze_to_silver = silver.after - silver.before + silver_to_gold;
    fout << bronze_to_silver << '\n';
    fout << silver_to_gold << '\n';
    fout << gold_to_plat << '\n';
}