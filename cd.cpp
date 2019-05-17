#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, currIndex = 0, res = 0;
    vector<int> v(n);
    while (cin >> n, cin >> m, m && n) {
        currIndex = 0; res = 0;
        v.clear(); v.resize(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        for (int i = 0; i < m; ++i) {
            int num; cin >> num;
            while (currIndex < n && v[currIndex] < num) currIndex++;
            if (v[currIndex] == num) {
                if (currIndex < n && v[currIndex] == num) currIndex++;
                res++;
            }
        }
        cout << res << '\n';
    }
}