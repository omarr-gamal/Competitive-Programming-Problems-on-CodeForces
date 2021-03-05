// link to problem: https://codeforces.com/problemset/problem/1167/C

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

using namespace std;


vector<ll> edges[500005];
bool visited[500005];
ll a[500005];
void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        vector<ll> v(x);
        for (int j = 0; j < x; ++j) {
            cin >> v[j];
            --v[j];
        }
        for (int j = 0; j + 1 < x; ++j) {
            edges[v[j]].push_back(v[j + 1]);
            edges[v[j + 1]].push_back(v[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            //BFS
            vector<ll> component;
            queue<ll> q;
            q.push(i);
            while (!q.empty()) {
                ll d = q.front();
                q.pop();
                if (visited[d]) continue;
                visited[d] = true;
                component.push_back(d);

                for (ll y: edges[d]) {
                    if (!visited[y]) {
                        q.push(y);
                    }
                }
            }
            for (ll y: component) {
                a[y] = component.size();
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }

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
