#include <bits/stdc++.h>
#define CONST 1000000007
#define GMAX 2000
#define CONST2 7
using namespace std;
typedef unsigned long long ull;
typedef vector<vector<long>> vv;

ull eval(long q, long v, unordered_map<ull, ull> &m) {
    long o = q;
    ull res = 1;
    long x = CONST2;
    if (!m.count(q)) {
      while (q > 0) {
          if (q & 1) res = (x * res) % CONST;
          q /= 2;
          x = (x * x) % CONST;
      }
      m[o] = (res % CONST);
    } else res = m[o];
    res = (res * v) % CONST;
    return res;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n, e, q, ref = 1; cin >> n >> e >> q;
    vv c1(n, vector<long>(n,0)), c2(n, vector<long>(n,0)), c3(n, vector<long>(n,1)),
    c4(n, vector<long>(n,1));
    unordered_map<ull, ull> m;
    for (long i = 0; i < n; i++) {
        c1[i][i] = 0; c2[i][i] = 0; c3[i][i] = 0; c4[i][i] = 0;
    }
    while (e--) {
        long a,b; cin >> a >> b;
        c1[a][b] = 1;
        c2[b][a] = 1;
        c3[a][b] = 0;
        c4[b][a] = 0;
    }
    while (q--) {
        long num; cin >> num;
        if (num == 1) {
            n++;
            c1.resize(n); c2.resize(n); 
            c3.resize(n); c4.resize(n);
            for (long i = 0; i < n; i++) {
                c1[i].resize(n); c2[i].resize(n); c3[i].resize(n); c4[i].resize(n);
            }
            for (long i = 0; i < n - 1; i++) {
                if (ref == 1 || ref == 2) {
                    c3[i][n - 1] = 1; c3[n - 1][i] = 1; c4[n - 1][i] = 1; c4[i][n - 1] = 1;
                } else if (ref == 3 || ref == 4) {
                    c1[i][n - 1] = 1; c1[n-1][i] = 1; c2[n - 1][i] = 1; c2[i][n - 1] = 1;
                }
            }
        }
        if (num == 2) {
            long a,b; cin >> a >> b;
            if (ref == 1) {
                c1[a][b] = 1; c2[b][a] = 1; c3[a][b] = 0; c4[b][a] = 0;
            } else if (ref == 2) {
                c2[a][b] = 1; c1[b][a] = 1; c4[a][b] = 0; c3[b][a] = 0;
            } else if (ref == 3) {
                c3[a][b] = 1; c4[b][a] = 1; c1[a][b] = 0; c2[b][a] = 0;
            } else if (ref == 4) {
                c4[a][b] = 1; c3[b][a] = 1; c2[a][b] = 0; c1[b][a] = 0;
            }
        }
        if (num == 3) {
            long a; cin >> a;
            for (long i = 0; i < n; i++) {
                if (i != a) {
                  if (ref == 1 || ref == 2) {
                     c1[a][i] = 0; c1[i][a] = 0; c2[i][a] = 0; c2[a][i] = 0;
                     c3[a][i] = 1; c3[i][a] = 1; c4[i][a] = 1; c4[a][i] = 1;
                  } else if (ref == 3 || ref == 4) {
                     c1[a][i] = 1; c1[i][a] = 1; c2[i][a] = 1; c2[a][i] = 1;
                     c3[a][i] = 0; c3[i][a] = 0; c4[i][a] = 0; c4[a][i] = 0;
                  }
                }
            }
        }
        if (num == 4) {
            long a,b; cin >> a >> b;
            if (ref == 1) {
                c1[a][b] = 0; c2[b][a] = 0; c3[a][b] = 1; c4[b][a] = 1;
            } else if (ref == 2) {
                c2[a][b] = 0; c1[b][a] = 0; c4[a][b] = 1; c3[b][a] = 1;
            } else if (ref == 3) {
                c3[a][b] = 0; c4[b][a] = 0; c1[a][b] = 1; c2[b][a] = 1;
            } else if (ref == 4) {
                c4[a][b] = 0; c3[b][a] = 0; c2[a][b] = 1; c1[b][a] = 1;
            }
        }
        if (num == 5) {
            if (ref == 1) {
                ref = 2;
            } else if (ref == 2) {
                ref = 1;
            } else if (ref == 3) {
                ref = 4;
            } else if (ref == 4) ref = 3;
        }
        if (num == 6) {
           if (ref == 1) {
               ref = 3;
           } else if (ref == 2) {
               ref = 4;
           } else if (ref == 3) {
               ref = 1;
           } else if (ref == 4) {
               ref = 2;
           }
        }
    }
    cout << n << '\n';
    for (long i = 0; i < n; i++) {
        vector<long> store;
        ull res = 0;
        long total = 0;
        for (long j = 0; j < n; j++) {
            if (ref == 1) {
               if (c1[i][j]) {
                   res += eval(total, j, m);
                   res %= CONST;
                   total++;
               }
            } else if (ref == 2) {
                if (c2[i][j]) {
                    res += eval(total, j, m);
                    res %= CONST;
                    total++;
                }
            } else if (ref == 3) {
                if (c3[i][j]) {
                    res += eval(total, j, m);
                    res %= CONST;
                    total++;
                }
            } else if (ref == 4) {
                if (c4[i][j]) {
                    res += eval(total, j, m);
                    res %= CONST;
                    total++;
                }
            }
        }
        cout << total << " ";
        cout << res << '\n';
    }
}