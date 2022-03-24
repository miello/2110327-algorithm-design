#include <bits/stdc++.h>

using namespace std;
const int MXW = 505;
double board[MXW][MXW];

int main() {
    int k;
    cin >> k;

    while(k--) {
        int n;
        cin >> n;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                cin >> board[i][j];
            }
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                for(int k = 1; k <= n; ++k) {
                    board[i][j] = max(board[i][j], board[i][k] * board[k][j]);
                }
            }
        }

        bool isInfinite = false;

        for(int i = 1; i <= n; ++i) {
            for(int k = 1; k <= n; ++k) {
                if(board[i][k] * board[k][i] > 1) {
                    isInfinite = true;
                }
            }
        }
        cout << (isInfinite ? "YES" : "NO") << "\n";
        
    }
    
}