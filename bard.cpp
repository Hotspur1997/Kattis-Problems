#include <bits/stdc++.h>
using namespace std;

int main() {
    long n,m, count = 0; cin >> n >> m;
    vector<unordered_set<long>> c(n);
    cin.ignore();
    while (m--) {
        long num; cin >> num;
        bool p = false;
        unordered_set<long> check;
        while(num--) {
            long d; cin >> d;
            d--;
            if (!d) p = true;
            check.insert(d);
        }
        if (p) {
            for (auto j = check.begin(); j != check.end(); j++) c[*j].insert(count);
            count++;
        } else {
            unordered_set<long> u;
            for (auto j = check.begin(); j != check.end(); j++) {
                for (auto k = c[*j].begin(); k != c[*j].end(); k++) u.insert(*k);
            }
            for (auto j = check.begin(); j != check.end(); j++) c[*j] = u;
        }
    }
    cout << 1 << '\n';
    for (long i = 1; i < n; i++) {
        if (c[i] == c[0]) cout << i + 1 << '\n';
    }
}