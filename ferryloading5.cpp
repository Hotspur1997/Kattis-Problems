#include <bits/stdc++.h>
using namespace std;
typedef pair <long, double> iPair;

bool condition(double sCount, double pCount) {
    return ((sCount / pCount > 0.8 && pCount / sCount > 1.2) ||
            (pCount / sCount > 0.8 && sCount / pCount > 1.2));
}

int main() {
    
    while (1) {
        long n; cin >> n;
        if (!n) break;
        double pCount = 0, sCount = 0;
        stack<iPair> s, p;
        vector<iPair> input(n);
        for (long i = 0; i < n; i++) {
            double v; cin >> v;
            input[i] = make_pair(i + 1, v);
        }
        stable_sort(input.rbegin(), input.rend());
        for(long i = 0; i < n; i++) {
            if (i % 2 == 0) {
                s.push(input[i]);
                sCount += input[i].second;
            } else {
                p.push(input[i]);
                pCount += input[i].second;
            }
        }
        
        while (condition(sCount, pCount)) {
            if (pCount > sCount) {
                sCount += p.top().second;
                pCount -= p.top().second;
                s.push(p.top());
                p.pop();
            } else if (pCount < sCount) {
                sCount -= s.top().second;
                pCount += s.top().second;
                p.push(s.top());
                s.pop();
            }
        }
        while (!s.empty()) {
            cout << s.top().first << " ";
            s.pop();
        }
        cout << '\n';
    }
}