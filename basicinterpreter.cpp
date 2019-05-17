#include <bits/stdc++.h>
using namespace std;

int getNumber (string s, unordered_map<string, int> &r) {
    if(s.size() == 1) {
        if (isdigit(s[0])) {
            return stoi(s);
        } else return r[s];
    } else if (isdigit(s[s.size() - 1])) {
        return stoi(s);
    } else return r[s];
}

void parse(string s, unordered_map<string, int> &r, map<int, string>::iterator &curr, map<int, string> &m, bool &modified) {
    string t;
    for (long i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            t += s[i];
        } else break;
    }
    istringstream iss(s);
    string key, dummy, val;
    vector<string> v;
    while (getline(iss, dummy, ' ')) v.push_back(dummy);
    key = v[1];
    
    if (t == "LET") {
        if (v.size() == 4) {
            int num = getNumber(v[v.size() - 1], r);
            r[key] = num;
        }
        if (v.size() == 6) {
            int val2 = getNumber(v[v.size() - 1], r);
            int val = getNumber(v[v.size() - 3], r);
            string op = v[v.size() - 2];
            int res = 0;
            if (op == "+") res = val + val2;
            if (op == "/") res = val / val2;
            if (op == "-") res = val - val2;
            if (op == "*") res = val * val2;
            r[key] = res;
        }
    }
    
    if (t == "IF") {
        int num = getNumber(v[1], r);
        int k = getNumber(v[3], r);
        int line = stoi(v[v.size() - 1]);
        if (v[2] == "<=" && num <= k) {
                curr = m.find(line);
                modified = true;
        }
        if (v[2] == "=" && num == k) {
                curr = m.find(line);
                modified = true;
        }
        if (v[2] == "<" && num < k) {
                curr = m.find(line);
                modified = true;
        }
        if (v[2] == ">=" && num >= k) {
                curr = m.find(line);
                modified = true;
        }
        if (v[2] == ">" && num > k) {
                curr = m.find(line);
                modified = true;
        }
        if (v[2] == "<>" && num != k) {
            curr = m.find(line);
            modified = true;
        }
    }
    
    if (t == "PRINTLN" || t == "PRINT") {
        long index = 0;
        for (long i = 0; i < s.size(); i++) {
            if (s[i] == '"') {
                index = i;
                break;
            }
        }
        if (!index) {
            int res = getNumber(v[v.size() - 1], r);
            cout << res;
            if (t == "PRINTLN")  cout << '\n';
        } else {
            for (long i = index + 1; i < s.length() - 1; i++) cout << s[i];
            if (t == "PRINTLN") cout << '\n';
        }
    }
}

int main() {
    map<int, string> m;
    unordered_map<string, int> r;
    string s;
    bool modified = false;
    while (getline(cin, s), !cin.eof()) {
        long index = 0;
        string num;
        for (long i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                num += s[i];
            } else {
                index = i;
                break;
            }
        }
        s.erase(s.begin(), s.begin() + index + 1);
        m[stoi(num)] = s;
    }
    map<int, string>::iterator curr = m.begin();
    while (curr != m.end()) {
        modified = false;
        parse(curr -> second, r, curr, m, modified);
        if (!modified) curr++;
    }
}