#include <bits/stdc++.h>
using namespace std;

int main() {
    long n; cin >> n;
    while (n--) {
        long c; cin >> c;
        long p, q; cin >> p;
        cin.ignore();
        cin >> q;
        cout << c << " ";
        if (p == 1 && q == 1) {
            cout << 1 << "/" << 2 << '\n';
        } else if (q == 1) {
            cout << 1 << "/" << p + 1 << '\n';
        } else if (p < q) {
             q -= p;
             p += q;
             cout << p << "/" << q << '\n';
        } else if (p > q) {
            long count = 0;
            while (p > q) {
                p -= q;
                count++;
            }
            q -= p;
            p += q;
            while (count--) q += p;
            cout << p << "/" << q << '\n';
        }
    }
}