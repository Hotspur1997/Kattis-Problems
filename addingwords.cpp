#include <bits/stdc++.h>
using namespace std;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    unordered_map<long, string> r;
    unordered_map<string, long> f;
    string s;
    while(cin >> s, !cin.eof()) {
        
        if(s == string("clear")) {
            r.clear();
            f.clear();
        } else if (s == string("def")) {
            
            string s1; cin >> s1;
            long n; cin >> n;
            auto it = f.find(s1);
            if (it != f.end()) r.erase(it -> second);
            f[s1] = n;
            r[n] = s1;
        } else if(s == string("calc")) {
            vector<string> o;
            long result = 0, c = 0;
            string s2;
            bool u = false, isplus = false, isminus = false;
                
            while(cin >> s2 && s2 != "=") {
                    
                o.push_back(s2);
                if (c % 2 == 0) {
                        
                    if (!u) {
                         auto it = f.find(s2);
                         if (it == f.end())  u = true;  
                    }
                        
                    if (!u) {
                        if (!c) {
                            result = f[s2];
                        } else {
                                
                            if(isplus) result += f[s2];
                            if (isminus) result -= f[s2];
                        }
                    } 
                    c++;
                } else {
                        
                    switch(s2[0]) {
                            
                        case '+':
                          isplus = true;
                          isminus = false;
                          break;
                               
                        case '-':
                          isminus = true;
                          isplus = false;
                          break;
                    }
                    c++;
                }
            }
            o.emplace_back("=");
            for (long i = 0; i < o.size(); i++) cout << o[i] << " ";
            if (u) {
                cout << "unknown" << endl;
            } else {
                auto it = r.find(result);
                if (it == r.end()) {
                    cout << "unknown" << endl;
                } else cout << r[result] << endl;
                    
            }
        }
    }
}