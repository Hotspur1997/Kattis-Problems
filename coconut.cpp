#include <bits/stdc++.h>
#define FOLD 0
#define FIST 1
#define PALM 2
using namespace std;
struct person {
    long s;
    long index;
};

int main() {
    
    long s,n; cin >> s >> n;
    vector<person> v;
    for (long i = 1; i <= n; i++) {
        person d; 
        d.index = i;
        d.s = FOLD;
        v.push_back(d);
    }
    long i = 0;
    while (v.size() > 1) {
        
        i = (i + s - 1) % v.size();
        if (v[i].s == FOLD) {
            v[i].s = FIST;
            person d;
            d.s = FIST;
            d.index = v[i].index;
            v.insert(v.begin() + i, d);
        } else if (v[i].s == FIST) {
            v[i].s = PALM;
            i++;
        } else v.erase(v.begin() + i);
    }
    cout << v[0].index << endl;
}