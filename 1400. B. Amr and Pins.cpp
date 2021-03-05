// link to problem: https://codeforces.com/problemset/problem/507/B

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
    ll r, x, y, x2, y2, ans = 0;
    cin >> r >> x >> y >> x2 >> y2;
    r *= 2;
 
    ans += sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) / r;
//    ans = (ll)sqrt(ans);
    if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) - (ll)(sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y))) != 0
        || (ll)sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) % r != 0)
        ans++;
    cout << ans;
 
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

  