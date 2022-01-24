#include <bits/stdc++.h>

using namespace std;

void gen(int idx, int n, int k, string s) {
  if(idx == k) {
    if(n != 0) {
      return;
    }
    cout << s << "\n";
    return;
  }
  
  if(n != 0) {
    gen(idx + 1, n - 1, k, s + "1");
  }
  gen(idx + 1, n, k, s + "0");
} 

int main() {
  int n, k;
  cin >> n >> k;
  gen(0, n, k, "");
}