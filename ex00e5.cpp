#include <bits/stdc++.h>

using namespace std;

void gen(int idx, int n, int k, int cnt, bool found, char *c) {
  if(idx == n) {
    if(found) {
      for(int i = 0; i < n; i++) {
        cout << c[i];
      }
      cout << "\n";
    }
    return;
  }

  c[idx] = '0';
  gen(idx + 1, n, k, 0, found, c);
  c[idx] = '1';
  gen(idx + 1, n, k, cnt + 1, (cnt + 1 >= k) || found, c);
} 

int main() {
  int n, k;
  cin >> n >> k;
  char *c = new char[n];
  gen(0, n, k, 0, false, c);
  delete[] c;
}