#include <bits/stdc++.h>
using namespace std;
typedef pair<string, long> iPair;
int main() {
    string s;
    set<string> st;
    map<string, set<string>> resMap;
    vector<iPair> res;
    string op = "";
    while (getline(cin,s), !cin.eof()) {
        
        if (isupper(s[0])) {
            op = s;
            set<string> d;
            resMap[op] = d;
        }
        if (isdigit(s[0]) && stoi(s) == 1) {
            for (auto i = resMap.begin(); i != resMap.end(); i++) res.push_back(make_pair(i -> first, (i -> second).size()));
            stable_sort(res.begin(), res.end(), [](iPair s1, iPair s2) {
                if (s1.second > s2.second) return true;
                if (s1.second == s2.second && s1.first < s2.first) return true;
                return false;
            });
            for (long i = 0; i < res.size(); ++i) cout << res[i].first << " " << res[i].second << '\n';
            st.clear();
            resMap.clear();
            res.clear();
        }
        if (isdigit(s[0]) && !stoi(s)) break;
        if (islower(s[0])) {
            if (!st.count(s)) {
                st.insert(s); 
                resMap[op].insert(s);
            } else {
                for (auto i = resMap.begin(); i != resMap.end(); i++) {
                    if (i -> first != op && (i-> second).count(s)) (i -> second).erase(s);
                }
            }
        }
    }
}