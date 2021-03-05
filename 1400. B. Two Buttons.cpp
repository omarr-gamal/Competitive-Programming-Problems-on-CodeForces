// link to problem: https://codeforces.com/problemset/problem/520/B

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


bool vis[100005];
void solve() {
    short n, m;
    cin >> n >> m;

    queue<pair<short, short>> q;
    q.push({n, 0});
    vis[n] = true;
    while (!q.empty()) {
        short x = q.front().first;
        short depth = q.front().second;
        q.pop();

        if (x == m) {
            cout << depth;
            return;
        }
        vis[x] = true;
        if (x > 1 && !vis[x - 1])
            q.push({x - 1, depth + 1});
        if (x < m && !vis[x * 2])
            q.push({x * 2, depth + 1});
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

 

