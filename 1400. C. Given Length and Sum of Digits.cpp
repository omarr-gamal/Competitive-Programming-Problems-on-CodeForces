// link to problem: https://codeforces.com/problemset/problem/489/C

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
    void solve() {
    ll len, sum2;
    cin >> len >> sum2;
    if (sum2 > 9 * len || (sum2 == 0 && len > 1)) { cout << "-1 -1"; return; }
 
    ll sum = sum2;
    string max_s, min_s;
    while (sum > 9) {
        max_s += '9';
        sum -= 9;
    }
    max_s += to_string(sum);
    ll tmp = max_s.length();
    for (int i = 0; i < len - tmp; ++i) {
        max_s += "0";
    }
 
    sum = sum2;
    sum--; min_s += "1";
    for (int i = 1; i < len; ++i) {
        min_s += "0";
    }
    tmp = sum / 9;
    int i;
    for (i = 0; i < tmp; ++i) {
        min_s[len - i - 1] = '9';
        sum -= 9;
    }
//        cout << "sum : " << sum << endl;
    if (sum) {
        min_s[len - i - 1] += sum;
    }
 
    cout << min_s << " " << max_s;
 
}

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

  