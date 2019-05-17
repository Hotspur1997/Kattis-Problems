#include <bits/stdc++.h>
#define CONST 3600
using namespace std;
typedef pair<long,long> iPair;

int main() {
    long n; cin >> n;
    long min = LONG_MAX, m, desiredMin, k;
    vector<long> mag;
    unordered_map<long,long> c;
    while (n--) {
        c.clear();
        min = LONG_MAX;
        cin >> m >> desiredMin;
        k = desiredMin;
        mag.clear();
        for (long i = 0; i < m; i++) {
            long num; cin >> num;
            mag.push_back(num);
        }
        queue<iPair> q;
        q.push(make_pair(0,0));
        c[0] = 0;
        while (!q.empty()) {
            long sum = q.front().first;
            long num = q.front().second;
            q.pop();
            for (long i = 0; i < mag.size(); i++) {
                long o = sum;
                sum += mag[i];
                num++;
                if (sum > CONST) sum = CONST;
                if (sum < 0) sum = 0;
                if (!c.count(sum)) {
                    c[sum] = num;
                    q.push(make_pair(sum,num));
                }
                num--;
                sum = o;
            }
        }
        while (!c.count(k)) k++;
        cout << c[k] << " " << k - desiredMin << '\n';
    }
}