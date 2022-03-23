#include <bits/stdc++.h>

using namespace std;

const int MXN = 5005;
vector<int> edge[MXN], edgeT[MXN], newEdge[MXN];
vector<int> par(MXN, 0), indegree(MXN, 0), rankN(MXN, 1), cntRank(MXN, 0);
vector<bool> isPass(MXN, false);
stack<int> order;

void dfs(int now, int prev, int parent) {
    if(now != parent) {
        par[now] = parent;
    }

    isPass[now] = true;

    for(auto &i: edge[now]) {
        if(i == prev || isPass[i]) continue;
        dfs(i, now, parent);
    }
}

void dfsT(int now, int prev) {
    isPass[now] = true;
    for(auto &i: edgeT[now]) {
        if(i == prev || isPass[i]) continue;
        dfsT(i, now);
    }

    order.push(now);
}

void rankDFS(int now, int prev) {
    isPass[now] = true;
    for(auto &i: newEdge[now]) {
        if(i == prev) continue;
        rankN[i] = max(rankN[i], rankN[now] + 1);

        if(!isPass[i] && --indegree[i] == 0) rankDFS(i, now);
    }
}

int main() {
    int n, p;
    cin >> n >> p;

    // SCC
    for(int i = 0; i < n; ++i) {
        par[i] = i;
    }
    
    for(int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edgeT[b].push_back(a);
    }

    for(int i = 0; i < n; ++i) {
        if(!isPass[i]) {
            dfsT(i, -1);
        }
    }

    for(int i = 0; i < n; ++i) isPass[i] = false;
    while(order.size()) {
        int now = order.top();

        order.pop();
        if(isPass[now]) continue;

        dfs(now, -1, now);
    }

    // Make new graph with compression
    for(int i = 0; i < n; ++i) {
        for(auto &j: edge[i]) {
            if(par[i] != par[j]) {
                newEdge[par[i]].push_back(par[j]);
                ++indegree[par[j]];
            }
        }
    }

    // Last depth first search
    for(int i = 0; i < n; ++i) {
        isPass[i] = false;
    }

    for(int i = 0; i < n; ++i) {
        if(indegree[i] == 0 && !isPass[i]) rankDFS(i, -1);
    }

    // Count rank
    for(int i = 0; i < n; ++i) {
        ++cntRank[rankN[par[i]]];
    }
    
    for(int i = 1; cntRank[i] != 0; ++i) cout << cntRank[i] << " ";
}
