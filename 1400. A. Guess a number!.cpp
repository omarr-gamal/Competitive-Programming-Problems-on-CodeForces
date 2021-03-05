// link to problem: https://codeforces.com/problemset/problem/416/A

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
 
    int n, t, x = 0;
    string q, a;
    vector<pair<string, int>> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q >> t >> a;
        if (a == "Y") {
            v.push_back({ q , t });
        } else {
            if (q.length() == 2) {
                if (q == "<=")
                    q = ">";
                else
                    q = "<";
            } else {
                if (q == "<")
                    q = ">=";
                else
                    q = "<=";
            }
            v.push_back({ q , t });
        }
    }
    /*
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << endl;
    } */
 
 
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first == "<") {
            if (x >= v[i].second) {
                x = v[i].second - 1;
            }
        } else if (v[i].first == ">") {
            if (x <= v[i].second) {
                x = v[i].second + 1;
            }
        } else if (v[i].first == "<=") {
            if (x > v[i].second) {
                x = v[i].second;
            }
        } else if (v[i].first == ">=") {
            if (x < v[i].second) {
                x = v[i].second + 1;
            }
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first == "<") {
            if (x >= v[i].second) {
                cout << "Impossible"; return 0;
            }
        } else if (v[i].first == ">") {
            if (x <= v[i].second) {
                cout << "Impossible"; return 0;
            }
        } else if (v[i].first == "<=") {
            if (x > v[i].second) {
                cout << "Impossible"; return 0;
            }
        } else if (v[i].first == ">=") {
            if (x < v[i].second) {
                cout << "Impossible"; return 0;
            }
        }
    }
    cout << x;
    return 0;
}