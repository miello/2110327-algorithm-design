#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    queue<int> plantQ;
    queue<int> storeQ;
    
    vector<pair<int, pair<int, int>>> v;
    for(int i = 0; i < k; ++i) {
        int d, e, l;
        cin >> d >> e >> l;
        v.push_back({d, { e, l }});
    }

    sort(v.begin(), v.end());
    for(auto &i: v) {
        int type = i.second.first;
        int route = i.second.second;
        // A type (production)
        if(type == 0) {
            if(storeQ.size()) {
                cout << storeQ.front() << "\n";
                storeQ.pop();
            } else {
                plantQ.push(route);
                cout << "0" << "\n";
            }
        } 
        // B type (store)
        else {
            if(plantQ.size()) {
                cout << plantQ.front() << "\n";
                plantQ.pop();
            } else {
                storeQ.push(route);
                cout << "0" << "\n";
            }
        }
    }
}