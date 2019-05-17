#include <bits/stdc++.h>
#define CONST 4
using namespace std;

void move_down(long** a, long i) {
    
    long zCount = 0;
    for (long j = CONST - 1; j >= 0; j--) {
         if(!a[j][i]) {
             zCount++;
         } else a[j + zCount][i] = a[j][i];
    }
    for (long j = 0; j < zCount; j++) a[j][i] = 0;
    for (long j = CONST - 1; j > 0; j--) {
        if (a[j][i] && a[j][i] == a[j - 1][i]) {
            a[j][i] *= 2;
            for (long k = j - 1; k > 0; k--) a[k][i] = a[k - 1][i];
            a[0][i] = 0;
        }
    }
}

void move_up(long** a, long i) {
    
    long zCount = 0;
    for (long j = 0; j < CONST; j++) {
        if (!a[j][i]) {
            zCount++;
        } else a[j - zCount][i] = a[j][i];
    }
    for (long j = CONST - 1; j >= CONST - zCount; j--) a[j][i] = 0;
    for (long j = 0; j < CONST - 1; j++) {
        if (a[j][i] && a[j][i] == a[j + 1][i]) {
            a[j][i] *= 2;
            for (long k = j + 1; k < CONST - 1; k++) a[k][i] = a[k + 1][i];
            a[CONST - 1][i] = 0;
        }
    }
}

void move_right(long* row) {
    
    long zCount = 0;
    for (long i = CONST-1; i >=0 ; i--) {
        if (!row[i]) {
            zCount++;
        } else row[i + zCount] = row[i];
    }
    for (long i = 0; i < zCount; i++) row[i] = 0;
    for (long i = CONST - 1; i > 0; i--) {
        
        if (row[i] && row[i] == row[i - 1]) {
            row[i] *= 2;
            for (long k = i - 1; k > 0; k--) row[k] = row[k - 1];
            row[0] = 0;
        }
    }
}

void move_left(long* row) {
    
    long zCount = 0;
    for (long i = 0; i < CONST; i++) {
        if (!row[i]) {
            zCount++;
        } else row[i - zCount] = row[i];
    }
    for (long i = CONST - 1; i >= CONST - zCount; i--) row[i] = 0;
    for (long i = 0; i < CONST - 1; i++) {
        if (row[i] && row[i] == row[i + 1]) {
            row[i] *= 2; 
            for (long k = i + 1; k < CONST; k++) row[k] = row[k + 1];
            row[CONST - 1] = 0;
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long** a = new long*[CONST];
    for (long i = 0; i < CONST; i++) {
        a[i] = new long[CONST];
        for (long j = 0; j < CONST; j++) cin >> a[i][j];
    }
    
    long n; cin >> n;
    if (!n) for (long i = 0; i < CONST; i++) move_left(a[i]);
    if (n == 1) for (long i = 0; i < CONST; i++) move_up(a, i);
    if (n == 2) for (long i = 0; i < CONST; i++) move_right(a[i]);
    if (n == 3) for (long i = 0; i < CONST; i++) move_down(a, i);
    for (long i = 0; i < CONST; i++) {
        for (long j = 0; j < CONST; j++) cout << a[i][j] << " ";
        cout << '\n';
    }
    for (long i = 0; i < CONST; i++) {
      delete a[i]; a[i] = 0;
    }
    delete[] a;
}
