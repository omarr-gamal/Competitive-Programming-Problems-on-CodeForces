#include <iostream>
#include <vector> 
#include <set>
#include <iterator>
#include <algorithm> 
#include <stddef.h>
#include <string> 
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, index = 0;
    cin >> n;
    char ch;
    vector<char> v;
    vector<char> vd;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        v.push_back(ch);
    }

    for (int i = v.size() - 1; i > -1; i--) {
        index = vd.size() / 2;
        vd.insert(vd.begin() + index , v[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << vd[i];
    }

    return 0;
}