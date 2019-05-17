#include <bits/stdc++.h>
#define DIST 50
#define SPEED 5
#define TIME 2
using namespace std;
typedef pair<double, double> iPair;
typedef vector<vector<double>> vv;

int main() {
    double xsrc,ysrc, xdst, ydst; cin >> xsrc >> ysrc >> xdst >> ydst;
    long n; cin >> n;
    vector<iPair> v(n + 2);
    for (long i = 0; i < n; i++) {
        double a,b; cin >> a >> b;
        v[i] = make_pair(a,b);
    }
    v[n] = make_pair(xsrc, ysrc);
    v[n + 1] = make_pair(xdst, ydst);
    vv c(n + 2, vector<double>(n + 2));
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n + 2; j++) {
            if (i != j) {
                double dist = (double)(sqrt(pow(v[i].first - v[j].first, 2.0) + pow(v[i].second - v[j].second, 2.0)));
                double t = (double)(dist) / SPEED;
                double t2 = (double)(dist - DIST) / SPEED + TIME;
                if (dist - DIST >= 0) {
                  if (t2 < t) {
                      c[i][j] = t2;
                  } else c[i][j] = t;
                } else c[i][j] = (double)(DIST - dist) / SPEED + TIME;
            } else c[i][i] = 0;
        }
    }
    for (long i = 0; i < n + 2; i++) {
        double dst = (double)(sqrt(pow(v[i].first - v[n].first, 2.0) + pow(v[i].second - v[n].second, 2.0)));
        double t = (double)dst / SPEED;
        c[n][i] = t;
    }
    for (long i = 0; i < n + 2; i++) {
        double dst = (double)(sqrt(pow(v[i].first - v[n + 1].first, 2.0) + pow(v[i].second - v[n + 1].second, 2.0)));
        double t = (double)dst / SPEED;
        c[n + 1][i] = t;
    }
   
    for (long k = 0; k < n + 2; k++) {
        for (long i = 0; i < n + 2; i++) {
            for (long j = 0; j < n + 2; j++) {
                if (c[i][k] + c[k][j] < c[i][j]) c[i][j] = c[i][k] + c[k][j];
            }
        }
    }
    cout << fixed << setprecision(3) << c[n][n + 1];
}