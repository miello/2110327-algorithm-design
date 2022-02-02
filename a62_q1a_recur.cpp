#include <bits/stdc++.h>

using namespace std;

int arr[256][256];

void recur(int lx, int ly, int rx, int ry, int a, int b) {
    if(a == 0) {
        arr[lx][ly] = b;
        return;
    }

    int midX = (lx + rx) >> 1;
    int midY = (ly + ry) >> 1;

    recur(lx, ly, midX, midY, a - 1, b);
    recur(lx, midY + 1, midX, ry, a - 1, b - 1);
    recur(midX + 1, ly, rx, midY, a - 1, b + 1);
    recur(midX + 1, midY + 1, rx, ry, a - 1, b);    
}

int main() {
    int a, b;
    cin >> a >> b;

    int szX = (1 << a);
    int szY = (1 << a);

    recur(0, 0, szX - 1, szY - 1, a, b);
    for(int i = 0; i < szX; ++i) {
        for(int j = 0; j < szY; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}