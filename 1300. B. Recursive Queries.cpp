// link to problem: https://codeforces.com/problemset/problem/932/B

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


map<ll, vector<ll>> mp;


ll digit_product(ll n) {
    string s = to_string(n);
    ll res = 1;

    for(char c : s)
        if (c != '0')
            res *= (c - 48);

    return res;
}


void rec(ll n, ll m) {
    // base
    if (n < 10) {
        mp[n].push_back(m);
        return;
    }


    // recurrence
    rec(digit_product(n), m);
}



void solve() {
    ll l, r, k;
    cin >> l >> r >> k;

    cout << (upper_bound(mp[k].begin(), mp[k].end(), r) - mp[k].begin()) -
            (lower_bound(mp[k].begin(), mp[k].end(), l) - mp[k].begin())<< endl;
//    ll res = 0;
//    for (ll i : mp[k])
//        if (i <= r && i >= l)
//            res++;

//    cout << res << endl;



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    cin >> T;
    // preprocess all numbers from l to r
    for (int i = 1; i <= 1000000; ++i)
        rec(i, i);

    while(T--){
        solve();
    }
    return 0;
}