// link to problem: https://codeforces.com/problemset/problem/1468/C

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

struct cust {
    ll i;
    ll k;
    bool s;
};
void solve() {
    ll q, n, k, i = 1, ld = 0;
    cin >> q;
    vector<cust> v;
    multiset<pair<ll, ll>, greater<>> ms;

    while (q--) {
        cin >> n;
        if (n == 1) {
            cin >> k;
            v.push_back({i, k, true});
            ms.insert({k, -i});
            i++;
        } else {
            if (n == 2) {
                for (int j = ld; j < v.size(); j++) {
                    if (!v[j].s)
                        continue;
                    cout << v[j].i << " ";
                    v[j].s = false;
                    ms.erase(ms.find({v[j].k, -v[j].i}));
                    ld = v[j].i - 1;
                    break;
                }
            } else { // n = 3
                auto it = v.begin();
                advance(it, -(ms.begin()->second) - 1);
                ms.erase(ms.begin());
                cout << it->i << " ";
                it->s = false;
            }
        }
    }
//    cout << endl << i;

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

 