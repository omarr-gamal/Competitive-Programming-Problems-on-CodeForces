// link to problem: https://codeforces.com/problemset/problem/279/A

#include <stack>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <memory.h>
#include <string>
#include <deque>
#define ll long long
const ll template_array_size = 1e6;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int x, y;
    vector<seg> v;
    cin >> x >> y;
 
    v.push_back({0, 0, 0, 0});
    v.push_back({1, 0, 0, 0});
    v.push_back({1, 1, 0, 1});
    for (int i = 1; i < 110; i++) {
        v.push_back({v[v.size() - 1].x - (2 * i), v[v.size() - 1].y, 1, v[v.size() - 1].cnt + 1});
        v.push_back({v[v.size() - 1].x, v[v.size() - 1].y - (2 * i), 2, v[v.size() - 1].cnt + 1});
        v.push_back({v[v.size() - 1].x + ((2 * i) + 1), v[v.size() - 1].y, 3, v[v.size() - 1].cnt + 1});
        v.push_back({v[v.size() - 1].x, v[v.size() - 1].y + ((2 * i) + 1), 4, v[v.size() - 1].cnt + 1});
    }
 
    if ((x == 0 && y == 0) || (x == 1 && y == 0)) {
        cout << 0;
        return 0;
    } else if (x == 1 && y == 0) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < v.size(); i++) {
        if ((x == v[i].x && y == v[i].y) || (x == v[i + 1].x && y == v[i + 1].y)) {
            cout << v[i].cnt + 1;
            break;
        } else if ((x == v[i].x && y >= min(v[i].y, v[i + 1].y) && y <= max(v[i].y, v[i + 1].y)) ||
                   (y == v[i].y && x >= min(v[i].x, v[i + 1].x) && x <= max(v[i].x, v[i + 1].x))) {
            cout << v[i].cnt + 1;
            break;
        }
    }
    return 0;
}