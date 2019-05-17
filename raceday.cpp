#include <bits/stdc++.h>
#define CONST 3
using namespace std;
struct t {
    long hr;
    long min;
};

struct info {
    string name;
    string bib;
    string oTime[CONST];
    t tres[CONST];
    long rank[CONST];
};

void time_Parse(string s, t &d) {
    istringstream iss(s);
    string t;
    vector<string> v;
    while (getline(iss, t, ':')) v.push_back(t);
    d.hr = stoi(v[0]);
    d.min = stoi(v[1]);
}

void sort_selector(vector<info> &res, long n) {
    
    for (long k = 0; k < CONST; k++) {
      stable_sort(res.begin(), res.end(), [k](info p1, info p2) {
          if (p1.tres[k].hr < p2.tres[k].hr) return true;
          if (p1.tres[k].hr == p2.tres[k].hr && p1.tres[k].min < p2.tres[k].min) return true;
            return false;
      });
      for (long i = 0; i < n; i++) {
          info ref = res[i];
          long currRank = i + 1;
          for (long j = i; j < n; j++, i++) {
              if (ref.tres[k].hr == res[j].tres[k].hr && ref.tres[k].min == res[j].tres[k].min) {
                  res[j].rank[k] = currRank;
              } else {
                  i--;
                  break;
              }
           }
        }
    }
    stable_sort(res.begin(), res.end(), [](info p1, info p2) {
        return p1.name < p2.name;
    });
}

int main() {
    long n;
    while (cin >> n, !cin.eof()) {
        if (!n) break;
        unordered_map<string, info> f_map;
        unordered_map<string, string> rev_map;
        vector<info> res;
        cin.ignore();
        for (long i = 0; i < n; i++) {
            string s; getline(cin,s);
            istringstream iss(s);
            vector<string> v;
            string t, name2;
            while (getline(iss, t, ' ')) v.push_back(t);
            name2 += v[1]; name2 += ", "; name2 += v[0];
            info dummy;
            dummy.name = name2;
            dummy.bib = v[2];
            f_map[name2] = dummy;
            rev_map[v[2]] = name2;
        }
        for (long i = 0; i < 3 * n; i++) {
            string s1, s2, s3; cin >> s1 >> s2 >> s3;
            string name = rev_map[s1];
            if (s2 == "S1") {
                f_map[name].oTime[0] = s3;
                time_Parse(s3, f_map[name].tres[0]);
            } else if (s2 == "S2") {
                f_map[name].oTime[1] = s3;
                time_Parse(s3, f_map[name].tres[1]);
            } else if (s2 == "F") {
                f_map[name].oTime[2] = s3;
                time_Parse(s3, f_map[name].tres[2]);
            }
        }
        for (auto i = f_map.begin(); i != f_map.end(); i++) res.push_back(i -> second);
        sort_selector(res, n);
        cout << "NAME                       BIB    SPLIT1      RANK    SPLIT2      RANK    FINISH      RANK" << '\n';
        for (long i = 0; i < res.size(); i++) {
            cout << left << setw(20) 
            << res[i].name << right
            << setw(10) << res[i].bib
            << setw(10) << res[i].oTime[0]
            << setw(10) << res[i].rank[0]
            << setw(10) << res[i].oTime[1]
            << setw(10) << res[i].rank[1]
            << setw(10) << res[i].oTime[2]
            << setw(10) << res[i].rank[2] << '\n';
        }
        cout << '\n';
    }
}