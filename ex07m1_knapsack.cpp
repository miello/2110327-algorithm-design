#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int now;
        double weight;
        double cost;
        double sum_value;
        
        Node(): now(0), weight(0), cost(0.0), sum_value(0.0) {}
        Node(int now, double weight, double cost, double sum_value): now(now), weight(weight), cost(cost), sum_value(sum_value) {}

};

double calculate_value(double weight, vector<pair<double, double>> &item, int st) {
    int sz = item.size();
    double value = 0;
    for(int i = st; i < sz && weight != 0; ++i) {
        if(item[i].second > weight) {
            value += weight * (item[i].first / item[i].second);
            break;
        }
        
        value += item[i].first;
        weight -= item[i].second;
    }

    return value;
}

class NodeComparator {
    public:
        bool operator()(const Node &lhs, const Node &rhs) {
            return lhs.cost < rhs.cost;
        }
};

int main() {
    double w;
    int n;

    cin >> w >> n;
    vector<pair<double, double>> tmp(n, pair<double, double>(0.0, 0.0)), item;

    for(int i = 0; i < n; ++i) {
        cin >> tmp[i].first;
    }
    
    for(int i = 0; i < n; ++i) {
        cin >> tmp[i].second;
    }

    double ans = 0;

    for(int i = 0; i < n; ++i) {
        if(tmp[i].second == 0) {
            ans += tmp[i].first;
            continue;
        }
        item.push_back(tmp[i]);    
    }

    sort(item.begin(), item.end(), [](const pair<double, double> &a, const pair<double, double> &b) {
        return (a.first / a.second) > (b.first / b.second);
    });

    priority_queue<Node, vector<Node>, NodeComparator> pq;
    pq.push(Node(0, w, calculate_value(w, item, 0), 0.0));

    double bound = 0, ansBound = 0;
    int sz = item.size();

    while(!pq.empty()) {
        Node current = pq.top();

        pq.pop();

        if(current.cost <= bound) break;
        if(current.now == sz) {
            if(bound < current.cost) {
                bound = current.cost;
                ansBound = current.sum_value;
            }
            continue;
        }

        pq.push(Node(current.now + 1, current.weight, current.sum_value + calculate_value(current.weight, item, current.now + 1), current.sum_value));
        if(current.weight >= item[current.now].second) {
            double newWeight = current.weight - item[current.now].second;
            double newValue = current.sum_value + item[current.now].first;
            double newCost = newValue + calculate_value(newWeight, item, current.now + 1);

            pq.push(Node(current.now + 1, newWeight,  newCost, newValue ));
        }
    }

    cout << fixed << setprecision(5) << ans + ansBound;
}