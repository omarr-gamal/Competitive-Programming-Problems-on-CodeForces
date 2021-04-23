// problem link: https://codeforces.com/problemset/problem/1486/B

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

using namespace std;

void solve() {
    long long n, a;
    vector<long long > x, y;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        x.push_back(a);
        cin >> a;
        y.push_back(a);
    }
    if (n % 2 == 0) {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << endl;
    } else
        cout << "1\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
