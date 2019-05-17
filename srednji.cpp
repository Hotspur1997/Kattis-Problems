#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n, m, res = 0, index = 0, sum = 0; cin >> n >> m;
    vector<long> v(n);
    for (long i = 0; i < n; ++i) cin >> v[i];
    unordered_map<long, long> smaller;
    smaller[0] = 1;
    for (long i = 0; i < n; ++i) {
        if (v[i] == m) {
            index = i;
            break;
        }
    }
    for (long i = index - 1; i >= 0; i--) {
        if (v[i] < m) {
            sum++;
        } else sum--;
        smaller[sum]++;
    }
    sum = 0;
    res = smaller[0];
    for (long i = index + 1; i < n; i++) {
        if (v[i] < m) {
            sum++;
        } else sum--;
        res += smaller[-sum];
        
    }
    cout << res;
}