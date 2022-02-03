#include <bits/stdc++.h>

using namespace std;

int distance(pair<int, int> &a, pair<int, int> &b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

int closestPair(vector<pair<int, int>> &pointX, vector<pair<int, int>> &pointY, int l, int r) {
    if (r - l <= 2) {
        int d = distance(pointX[l], pointX[r]);
        for(int i = l; i <= r; ++i) {
            for(int j = i + 1; j <= r; ++j) {
                d = min(distance(pointX[i], pointX[j]), d);
            }
        }
        return d;
    }

    int mid = (l + r) >> 1;

    int midY = (int)(pointY.size()) >> 1;

    vector<pair<int, int>> sepL, sepR;
    for(int i = 0; i < pointY.size(); ++i) {
        if((pointY[i].first < pointX[mid].first || (pointY[i].first == pointX[mid].first && pointY[i].second < pointX[mid].second)) && (int)sepL.size() < midY) sepL.push_back(pointY[i]);
        else sepR.push_back(pointY[i]);
    }

    int left = closestPair(pointX, sepL, l, mid);
    int right = closestPair(pointX, sepR, mid + 1, r);

    int d = min(left, right);

    vector<pair<int, int>> tmp;
    int midLine = pointX[mid].first;
    for(int i = 0; i < pointY.size(); ++i) {
        if(abs(pointY[i].first - midLine) < d) {
            tmp.push_back(pointY[i]);
        }
    } 

    int sz = tmp.size();
    for(int i = 0; i < sz; ++i) {
        for(int j = i + 1; j < sz && abs(tmp[i].second - tmp[j].second) < d; ++j) {
            d = min(d, distance(tmp[i], tmp[j]));
        }
    }

    return d;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arrX, arrY;

    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        arrX.emplace_back(x, y);
        arrY.emplace_back(x, y);
    }

    sort(arrX.begin(), arrX.end());
    sort(arrY.begin(), arrY.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });

    cout << closestPair(arrX, arrY, 0, n - 1);
}