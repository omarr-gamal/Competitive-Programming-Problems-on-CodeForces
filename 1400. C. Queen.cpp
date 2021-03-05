// link to problem: https://codeforces.com/problemset/problem/1143/C

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

void solve() {
    int n;
    cin >> n;
    vector<ll> children[n + 1];
    int c[n + 1];

    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x >> c[i];
        if (x != -1)
            children[x].push_back(i);
    }
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j < children[i].size(); ++j) {
//            cout << children[i][j] << " " ;
//        } cout << endl;
//    }
    vector<ll> ans;
    for (int i = 1; i <= n; ++i) {
        if (c[i] == 1) {
            bool pos = true;
            for (ll x: children[i]) {
                if (c[x] == 0) {
                    pos = false; break;
                }
            }
            if (pos) {
                ans.push_back(i);
            }
        }
    }

    if (ans.empty())
        cout << -1;
    else
        for (ll x: ans) cout << x << " ";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
//    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

  