#include <bits/stdc++.h>
using namespace std;
struct car {
    long dTime;
    long aTime;
    long index;
    string side; 
};

int main() {
    
    long n; cin >> n;
    while (n--) {
        long max, t, m; cin >> max >> t >> m;
        queue<car> q, lq, rq;
        bool isLeft = true;
        long count = 0;
        vector<car> v, result;
        for (long i = 0; i < m; i++) {
            long a; cin >> a;
            string s; cin >> s;
            car d;
            d.dTime = a;
            d.side = s;
            d.index = i;
            q.push(d);
        }
        count = 0;
        long tCount = 0;
        while(count < m) {
            while (tCount >= q.front().dTime && !q.empty()) {
                
                if (q.front().side ==  string("left")) lq.push(q.front());
                if (q.front().side == string("right")) rq.push(q.front());
                q.pop();
            }
            if (lq.empty() && rq.empty()) {
                tCount = q.front().dTime;
                continue;
            }
            if (isLeft) {
                for (long j = 0; j < max && !lq.empty(); j++) {
                    v.push_back(lq.front());
                    lq.pop();
                }
            } else {
                for (long j = 0; j < max && !rq.empty(); j++) {
                    v.push_back(rq.front());
                    rq.pop();
                }
            }
            tCount += t;
            for (long i = 0; i < v.size(); i++) {
                v[i].aTime = tCount;
                result.push_back(v[i]);
                count++;
            }
            v.clear();
            if (isLeft) {
                isLeft = false;
            } else isLeft = true;
        }
        sort(result.begin(), result.end(), [](car s1, car s2) {
            return s1.index < s2.index;
        });
        
        for (long i = 0; i < result.size(); i++) cout << result[i].aTime << endl;
        cout << endl;
    }
}