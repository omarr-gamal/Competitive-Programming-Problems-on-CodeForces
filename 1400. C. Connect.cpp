// link to problem: https://codeforces.com/problemset/problem/1130/C

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
typedef long long ll;
const ll template_array_size = 1e6;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];

using namespace std;


char planet[50][50];
bool visited[50][50];
vector<pair<ll, ll>> b_component, e_component;

ll n, r1, c1, r2, c2, cost = 1000000000000;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, -1, 0, 1};
bool valid (ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void solve() {
    cin >> n >> r1 >> c1 >> r2 >> c2;

    --r1; --c1; --r2; --c2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> planet[i][j];
        }
    }

    queue<pair<ll, ll>> q;
    q.push({r1, c1});
    b_component.push_back({r1, c1});
    while (!q.empty()) {
        ll r = q.front().first;
        ll ct = q.front().second;
        q.pop();

        if (visited[r][ct]) continue;
        visited[r][ct] = true;
        b_component.push_back({r, ct});

        if (r == r2 && ct == c2) { cout << 0; return; }

        for (int i = 0; i < 4; ++i)
            if (valid(r + dx[i], ct + dy[i]))
                if (planet[r + dx[i]][ct + dy[i]] == '0')
                    if (!visited[r + dx[i]][ct + dy[i]])
                        q.push({r + dx[i], ct + dy[i]});
    }

    q.push({r2, c2});
    e_component.push_back({r2, c2});
    while (!q.empty()) {
        ll r = q.front().first;
        ll ct = q.front().second;
        q.pop();

        if (visited[r][ct]) continue;
        visited[r][ct] = true;
        e_component.push_back({r, ct});

        for (int i = 0; i < 4; ++i)
            if (valid(r + dx[i], ct + dy[i]))
                if (planet[r + dx[i]][ct + dy[i]] == '0')
                    if (!visited[r + dx[i]][ct + dy[i]])
                        q.push({r + dx[i], ct + dy[i]});
    }

    for (auto at: b_component)
        for (auto bt: e_component)
            cost = min(cost, (at.first - bt.first)*(at.first - bt.first) + (at.second - bt.second)*(at.second - bt.second));

    cout << cost;

}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    int T = 1;
//    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
