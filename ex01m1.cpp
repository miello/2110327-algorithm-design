#include <bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int, int>> iii;

void gen_ans(vector<iii> &ans, int sx, int sy, int ex, int ey, int x, int y) {
    int midX = (sx + ex) >> 1;
    int midY = (sy + ey) >> 1;

    int param[4][2] = {
        { midX, midY }, 
        { midX + 1, midY }, 
        { midX, midY + 1 }, 
        { midX + 1, midY + 1 }
    };

    // 2 x 2 case
    if(ex - sx == 1 && ey - sy == 1) {
        int idx;
        if(sx == x && sy == y) idx = 0;
        if(sx + 1 == x && sy == y) idx = 1;
        if(sx == x && sy + 1 == y) idx = 2;
        if(sx + 1 == x && sy + 1 == y) idx = 3;
        ans.emplace_back(idx, make_pair(sx, sy));
        return;
    }

    // Hole on top left
    // 01
    // 11
    if(sx <= x && x <= midX && sy <= y && y <= midY) {
        param[0][0] = x;
        param[0][1] = y;
        ans.emplace_back(0, make_pair(midX, midY));
    }

    // Hole on top right
    // 10
    // 11
    else if(midX + 1 <= x && x <= ex && sy <= y && y <= midY) {
        param[1][0] = x;
        param[1][1] = y;
        ans.emplace_back(1, make_pair(midX, midY));
    }

    // Hole on bottom left
    // 11
    // 01
    else if(sx <= x && x <= midX && midY + 1 <= y && y <= ey) {
        param[2][0] = x;
        param[2][1] = y;
        ans.emplace_back(2, make_pair(midX, midY));
    }

    // Hole on bottom right
    // 11 
    // 10
    if(midX + 1 <= x && x <= ex && midY + 1 <= y && y <= ey) {
        param[3][0] = x;
        param[3][1] = y;
        ans.emplace_back(3, make_pair(midX, midY));
    }

    gen_ans(ans, sx, sy, midX, midY, param[0][0], param[0][1]);
    gen_ans(ans, midX + 1, sy, ex, midY, param[1][0], param[1][1]);
    gen_ans(ans, sx, midY + 1, midX, ey, param[2][0], param[2][1]);
    gen_ans(ans, midX + 1, midY + 1, ex, ey, param[3][0], param[3][1]);
}

int main() {
    int l, x, y;
    cin >> l >> x >> y;
    
    vector<iii> ans;
    
    gen_ans(ans, 0, 0, l - 1, l - 1, x, y);
    cout << ans.size() << "\n";
    for(auto &i: ans) {
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    }
}
