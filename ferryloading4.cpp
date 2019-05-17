#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long n; cin >> n;
    while (n--) {
        long l, num, c = 0; cin >> l >> num;
        l *= 100;
        queue<long> lq, rq;
        for (long i = 0; i < num; i++) {
            long length;
            string side; cin >> length >> side;
            if (side == string("left")) lq.push(length);
            if (side == string("right")) rq.push(length);
        }
    
        bool isLeft = true;
        long capacity = 0,r = 0;
        while (c < num) {
        
           if (isLeft) {
              while (capacity < l && !lq.empty()) {
                  capacity += lq.front();
                  if (capacity > l) break;
                  lq.pop();
                  c++;
                }
            } else {
                while (capacity < l && !rq.empty()) {
                   capacity += rq.front();
                   if (capacity > l) break;
                   rq.pop();
                  c++;
                }
            }
            r++;
            capacity = 0;
            if (isLeft) {
              isLeft = false;
            } else isLeft = true;
        }
        cout << r << endl;
    }
}