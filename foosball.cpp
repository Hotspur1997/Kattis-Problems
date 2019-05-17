#include <bits/stdc++.h>
#define CONST 4
using namespace std;
typedef pair<string, string> iPair;

void swap(iPair &white, iPair &black, iPair &oWhite, iPair &oBlack, queue<string> &q, string &streak, long i) {
    if (streak[i] == 'W') {
          string temp = white.second;
          white.second = white.first;
          white.first = temp;
          temp = black.second;
          black.second = black.first;
          black.first = q.front();
          q.pop();
          q.push(temp);
          oBlack = make_pair(black.second, black.first);
    } else if (streak[i] == 'B') {
          string temp = black.second;
          black.second = black.first;
          black.first = temp;
          temp = white.second;
          white.second = white.first;
          white.first = q.front();
          q.pop();
          q.push(temp);
          oWhite = make_pair(white.second, white.first);
    }
}

int main() {
    long n, max = -LONG_MAX; cin >> n;
    queue<string> q;
    iPair black, white, oBlack, oWhite;
    vector<pair<long, iPair>> r; 
    for (long i = 0; i < CONST; i++) {
        string s; cin >> s;
        if (!i) {
            white.first = s;
        } else if (i == 1) {
            black.first = s;
        } else if (i == 2) {
            white.second = s;
        } else if (i == 3) black.second = s;
    }
    oBlack = black;
    oWhite = white;
    for (long i = CONST; i < n; i++) {
        string s; cin >> s;
        q.push(s);
    }
    string streak; cin >> streak;
    char prevChar;
    long res = 0;
    for (long i = 0; i < streak.size(); i++) {
        prevChar = streak[i];
        res = 0;
        for (long j = i; j < streak.size(); j++, i++) {
            if (prevChar == streak[j]) {
                res++;
            } else break;
            swap(white, black, oWhite, oBlack, q, streak, j);
        }
        i--;
        if (streak[i] == 'W') {
            r.push_back(make_pair(res, oWhite));
        } else r.push_back(make_pair(res, oBlack));
    }
    stable_sort(r.begin(), r.end(),[](pair<long,iPair> p1, pair<long,iPair> p2) {
        return p1.first < p2.first;
    });
    for (long i = 0; i < r.size(); i++) {
        if (r[i].first > max) max = r[i].first;
    }
    for (long i = 0; i < r.size(); i++) {
        if (r[i].first == max) cout << r[i].second.first << " " << r[i].second.second << '\n';
    }
}