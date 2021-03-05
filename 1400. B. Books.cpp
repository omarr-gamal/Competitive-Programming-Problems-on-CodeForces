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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    long long n, t, a, x = 0, y = 0, sum = 0, s = 0, mx = -1;
    vector<int> v;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        v.push_back(a);
    }
 
    while (x < v.size()) {
        if (y < v.size()) {
            if (v[y] + sum <= t) {
                sum += v[y];
                s++;
                y++;
            } else{
                mx = max(mx, s);
                s--;
                sum -= v[x];
                x++;
            }
        } else {
            mx = max(mx, s);
            s--;
            sum -= v[x];
            x++;
        }
    }
    cout << mx;
    return 0;
}