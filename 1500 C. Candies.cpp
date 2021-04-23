// problem link: https://codeforces.com/problemset/problem/991/C

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

bool simulate(ll n, ll k) {
    ll vas = 0, on = n;

    while (n >= k) {
        vas += k;
        n -= k;
        n -= ll(n / 10);
    }

    vas += n;

    return ((vas * 2) >= on);
}

void solve() {
    ll n;
    cin >> n;

    ll left = 1, right = n, mid = right, ans = mid;
    while (right >= left) {
        mid = (left + right) / 2;
        if (simulate(n, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
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
