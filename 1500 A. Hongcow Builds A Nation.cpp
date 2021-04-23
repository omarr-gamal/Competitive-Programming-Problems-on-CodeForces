// problem link: https://codeforces.com/problemset/problem/744/A

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


vector<ll> edges[1005];
bool government[1005];
bool visited[1005];

void solve() {
    ll n, m, k, ans = 0, mxgovcompsize = -1, numedgesmxgovcomp = 0, govid;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        ll z;
        cin >> z; --z;
        government[z] = true;
    }
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (ll i = 0; i < n; ++i) {
        if (!visited[i] && government[i]) {
            vector<ll> component;
            queue<ll> q;
            ll edgestomake = 0;

            q.push(i);
            while (!q.empty()) {
                ll x = q.front();
                q.pop();

                if (visited[x]) continue;
                visited[x] = true;
                component.push_back(x);

                for (ll d: edges[x]) {
                    if (!visited[d]) {
                        q.push(d);
                    }
                }
            }
            ll compedges = 0;
            for (ll j: component) {
                compedges += edges[j].size();
            }
            if (component.size() >= 2)
                edgestomake = ((component.size() * (component.size() - 1)) / 2) - (compedges / 2);
            ans += edgestomake;
            c[i] = edgestomake;

            if (max(mxgovcompsize, (ll)component.size()) != mxgovcompsize) {
                mxgovcompsize = (ll)component.size();
                numedgesmxgovcomp = (compedges / 2);
                govid = i;
            }
        }
    }
    // for non gov..
    ll nongovedges = 0, nongovvertices = 0;
    for (ll i = 0; i < n; ++i) {
        if (!visited[i] && !government[i]) {
            nongovvertices++;
            nongovedges += edges[i].size();
        }
    }
//    cout << nongovvertices << " " << mxgovcompsize << " " << (nongovedges / 2)  << " " << numedgesmxgovcomp << endl;
    ans += (((nongovvertices + mxgovcompsize) * ((nongovvertices + mxgovcompsize) - 1)) / 2) - ((nongovedges / 2) + (numedgesmxgovcomp));
    ans -= c[govid];
    cout << ans;

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

