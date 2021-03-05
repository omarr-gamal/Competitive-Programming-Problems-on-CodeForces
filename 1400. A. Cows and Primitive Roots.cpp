// link to problem: https://codeforces.com/problemset/problem/284/A

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

bool isPrime(ll n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
bool isSquare(ll a) {
    ll b = sqrt(a);
    return b * b == a;
}
bool isCube(ll N) {
    ll cube_root;
    cube_root = round(cbrt(N));
    if ((ll)cube_root * (ll)cube_root * (ll)cube_root == N) {
        return true;
    }
    else {
        return false;
    }
}
ll gcd(ll a, ll b) {
    ll t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
ll lcm(ll a, ll b) {
    if (a > b)
        return (a / gcd(a, b)) * b;
    else
        return (b / gcd(a, b)) * a;
}
ll modBigNumber(string num, ll m) {
    vector<int> vec;
    ll mod = 0;

    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        mod = mod * 10 + digit;

        int quo = mod / m;
        vec.push_back(quo);

        mod = mod % m;
    }

    return mod;
}
vector<int> prime_factors(ll n) {
    vector<int> v;
    while (n % 2 == 0) {
        v.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }

    if (n > 2)
        v.push_back(n);

    return v;
}
set<int> dist_prime_factors(ll n) {
    set<int> v;
    while (n % 2 == 0) {
        v.insert(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            v.insert(i);
            n /= i;
        }
    }

    if (n > 2)
        v.insert(n);

    return v;
}
vector<int> getDivisors(int n) {
    vector<int> v;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)
                v.push_back(i);

            else {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}
int ind_binary_search(vector<int> v, int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == x)
            return m;
        if (v[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int isSubstring(string s1, string s2) {
    int M = s1.length();
    int N = s2.length();

    for (int i = 0; i <= N - M; i++) {
        int j;

        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}
ll nCr(ll n, ll r) {
    ll p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            ll m = gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    } else p = 1;

    return p;
}
int power(int x, unsigned int y, int p) {
    int res = 1;

    x = x % p;

    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;

        y = y >> 1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

void solve() {
    ll p;
    cin >> p;

    int result = 1;
    for (int i = 2; i < (p - 1); i++)
        if (gcd(i, (p - 1)) == 1)
            result++;

    cout << result;

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


