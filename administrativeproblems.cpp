#include <bits/stdc++.h>
using namespace std;

struct l_t {
    long t;
    string name;
    char action;
    long num;
    string carName;
};

struct car_t {
    long price;
    long p_cost;
    long d_cost;
};

struct person_t {
    string carType;
    long status;
    long long totalCost;
};

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n; cin >> n;
    while (n--) {
      long num, logs; cin >> num >> logs;
      unordered_map<string, car_t> car;
      map<string, person_t> p;
      vector<l_t> r;
      for (long i = 0; i < num; i++) {
          car_t d;
          string name; cin >> name;
          cin >> d.price >> d.p_cost >> d.d_cost;
          car[name] = d;
      }
      
      for (long i = 0; i < logs; i++) {
          l_t d;
          cin >> d.t >> d.name >> d.action;
          p[d.name].status = 'r';
          p[d.name].totalCost = 0;
          if (d.action == 'p') {
              cin >> d.carName;
          } else cin >> d.num;
          r.push_back(d);
      }
      for (long i = 0; i < r.size(); i++) {
          
          person_t &d = p[r[i].name];
          if (r[i].action == 'p') {
                if (d.status == 'r') {
                   d.carType = r[i].carName;
                   d.status = 'p';
                   d.totalCost += car[r[i].carName].p_cost;
                } else d.status = 'u';
            }
          
          if (r[i].action == 'a') {
                  if (d.status == 'p') {
                      d.totalCost += ceil((double)(r[i].num) * car[d.carType].price / 100);
                  } else d.status = 'u';
          }
          
          if (r[i].action == 'r') {
                  if (d.status == 'p') {
                      d.totalCost += car[d.carType].d_cost * r[i].num;
                      d.status = 'r';
                  } else d.status = 'u';
           }
      }
      
      for (auto i = p.begin(); i != p.end(); i++) {
          if ((i -> second).status != 'r') {
              cout << i -> first << " " << "INCONSISTENT" << '\n';
          } else cout << i -> first << " " << (i -> second).totalCost << '\n';
      }
    }
}