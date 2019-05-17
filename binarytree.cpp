#include <bits/stdc++.h>
#include <climits>
#define MOD_CONST 21092013
using namespace std;
typedef unsigned long long ull;

void trace(unordered_set<ull> &visited, ull &count, long len, const char* a, ull &current) {
    
    for (long i = 0; i < len; i++) {
        
        if (a[i] == 'U') {
            
           if (current != 0) {
                    
                if (current % 2 == 0) {
                    
                      current = (current - 2) / 2;
                } else {
                    
                      current = (current - 1) / 2;
                }
            } 
            
            continue;
        }
        
        if (a[i] == 'L') {
            
            current = 2 * current + 1;
            continue;
        }
        
        if (a[i] == 'R') {
        
            current = 2 * current + 2;
            continue;
        }
        
    }
}

void track(unordered_set<ull> &visited, ull &count, long len, ull constant, 
           const char* a, ull &current) {
    
    
    for (ull i = 0; i < len; i++) {
        
        if (constant & (ull)(1 << i)) {
            
            if (a[i] == 'U') {
                
                if (current != 0) {
                    
                    if (current % 2 == 0) {
                    
                       current = (current - 2) / 2;
                    } else {
                    
                       current = (current - 1) / 2;
                    }
                }
                continue;
            }
            
            if (a[i] == 'L') {
                
                current = 2 * current + 1;
                continue;
            }
            
            if (a[i] == 'R') {
                
                current = 2 * current + 2;
                continue;
            }
        }
    }
    
    if (!visited.count(current)) {
        
        visited.insert(current);
        count++;
        count %= MOD_CONST;
    }
    
}

int main() {
    
    
    long n;
    long caseCounter = 1;
    cin >> n;
    
    while (n--) {
        
        string s1, s2;
        ull count = 0;
        cin >> s1;
        cin >> s2;
        const char* string1 = s1.c_str();
        const char* string2 = s2.c_str();
        ull parent = 0;
        ull current = 0;
        unordered_set<ull> visited;
        
        trace(visited, count, s1.length(), string1, current);
        ull initialCurrent = current;
        
        for (ull i = 0; i < (ull)(1 << s2.length()); i++) {
            
            current = initialCurrent;
            track(visited, count, s2.length(), i, string2, current);
        }
        
        cout << "Case " << caseCounter++ << ": " << count << endl;
        
        /*
        for (auto i = visited.begin(); i != visited.end(); i++) {
            
            cout << (*i).first << (*i).second << endl;
        }
        */
        
    }
    
    return 0;
}