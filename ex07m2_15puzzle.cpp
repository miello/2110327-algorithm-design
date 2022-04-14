#include <bits/stdc++.h>

using namespace std;

const int MXT = 4;

const int MOVE[4][2] = {{ -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }};

class Node {
    public:
        int cost, move;
        vector<vector<int>> table;

        Node(): cost(0), move(0), table() {}

        Node(int move, vector<vector<int>> table): move(move), table(table) {
            int nowCost = 0;
            for(int i = 0; i < MXT; ++i) {
                for(int j = 0; j < MXT; ++j) {
                    if(table[i][j] != 0) {
                        int now = table[i][j] - 1;
                        nowCost += abs((now / MXT) - i) + abs((now % MXT) - j);
                    }
                }
            }
            if(nowCost == 0) {
                this->cost = 0;
                return;
            }
            this->cost = move + nowCost;
        }
};

class NodeComparator {
    public:
        bool operator()(const Node &lhs, const Node &rhs) {
            return lhs.cost > rhs.cost;
        }
};

int main() {
    vector<vector<int>> table(MXT, vector<int>(MXT, 0));
    for(int i = 0; i < MXT; ++i) {
        for(int j = 0; j < MXT; ++j) {
            cin >> table[i][j];
        }
    }

    priority_queue<Node, vector<Node>, NodeComparator> pq;
    map<vector<vector<int>>, int> mp;

    mp[table] = 0;
    pq.push(Node(0, table));
    
    while(!pq.empty()) {
        vector<vector<int>> nowTable = pq.top().table;
        int nowMove = pq.top().move;
        int nowCost = pq.top().cost;

        pq.pop();


        if(mp[nowTable] != nowMove) continue;

        if(nowCost == 0) {
            cout << nowMove;
            return 0;
        }

        mp[nowTable] = nowMove;

        int x = 0, y = 0;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                if(nowTable[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }

        for(int i = 0; i < 4; ++i) {
            int newX = x + MOVE[i][0];
            int newY = y + MOVE[i][1];

            if(newX >= 0 && newX < MXT && newY >= 0 && newY < MXT) {
                swap(nowTable[newX][newY], nowTable[x][y]);

                if(mp.find(nowTable) == mp.end() || mp[nowTable] > nowMove + 1){
                    mp[nowTable] = nowMove + 1;
                    pq.emplace(nowMove + 1, nowTable);
                }
                
                swap(nowTable[newX][newY], nowTable[x][y]);

            }
        }
    }
}
