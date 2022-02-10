#include <iostream>
#include <vector>

using namespace std;

long long mow(long long start, long long budget, int k, vector<int> lawn, int grass) {
  if (budget - (k + lawn[start]) >= 0) {
    grass += lawn[start];
    budget -= (k + lawn[start]);
    start += 1;
    return mow(start, budget, k, lawn, grass);
  } else {
    return grass;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<int> lawn;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    lawn.push_back(l);
  }
  for (int i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    cout << mow(a, b, k, lawn, 0) << "\n";
  }
  return 0;
}