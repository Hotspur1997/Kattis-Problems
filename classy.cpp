#include <bits/stdc++.h>
#define LINE_CONST 30
using namespace std;
typedef pair<string, vector<string>> iPair;

int main() {
    
    long n;
    cin >> n;
    
    while (n--) {
        
        long num;
        cin >> num;
        iPair* container = new iPair[num];
        for (long i = 0; i < num; i++) {
            
            string name;
            cin >> name;
            name.erase(name.end() - 1);
            string token;
            cin >> token;
            istringstream iss(token);
            string dummy;
            vector<string> d;
            
            while(getline(iss, dummy, '-')) {
                
                d.push_back(dummy);
            }
            
            string c;
            cin >> c;
            container[i] = make_pair(name, d);
        }
        
        stable_sort(container, container + num, [](iPair s1, iPair s2) {
            
            vector<string> v1 = s1.second;
            vector<string> v2 = s2.second;
            long v1Len = v1.size() - 1;
            long v2Len = v2.size() - 1;
            long slen = 0;
            long blen = 0;
            long c = 0;
            
            if (v1Len > v2Len) {
                
                slen = v2Len;
                blen = v1Len;
                
            } else {
                
                slen = v1Len;
                blen = v2Len;
            }
            
            while (c <= slen) {
                
                if ((v1[v1Len - c] == "upper" && v2[v2Len - c] == "middle") ||
                    (v1[v1Len - c] == "middle" && v2[v2Len - c] == "lower") ||
                    (v1[v1Len - c] == "upper" && v2[v2Len - c] == "lower")) {
                        
                        return true;
                    }
                
                if ((v2[v2Len - c] == "upper" && v1[v1Len - c] == "middle") ||
                    (v2[v2Len - c] == "middle" && v1[v1Len - c] == "lower") ||
                    (v2[v2Len - c] == "upper" && v1[v1Len - c] == "lower")) {
                        
                        return false;
                    }
                    
                    c++;
            }
            
            while (v1Len != v2Len && c <= blen) {
                
                if (v1Len - c >= 0) {
                    
                    if (v1[v1Len - c] == "upper") {
                        
                        return true;
                    }
                    
                    if(v1[v1Len - c] == "lower") {
                        
                        return false;
                    }
                }
                
                if (v2Len - c >= 0) {
                    
                    if (v2[v2Len - c] == "upper") {
                        
                        return false;
                    }
                    
                    if (v2[v2Len - c] == "lower") {
                        
                        return true;
                    }
                }
                
                c++;
            }
            
            return s1.first < s2.first;
        });
        
        for (long i = 0; i < num; i++) {
            
            cout << container[i].first << endl;
        }
        
        for (long i = 0; i < LINE_CONST; i++) {
            
            cout << "=";
        }
        
        cout << endl;
        delete[] container;
        container = 0;
    }
    
    return 0;
}