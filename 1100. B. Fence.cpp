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
    int n, k, tmp, s = 0, index = 0;
    cin >> n >> k;
    vector<int> nv;
    vector<int> sum;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nv.push_back(tmp);
    }

    for (int i = 0; i < k; i++) {
        s += nv[i];
    }

    sum.push_back(s);

    for (int i = k; i < nv.size(); i++) {
        s += nv[i];
        s -= nv[i - k];
        sum.push_back(s);
    }

    for (int i = 0; i < sum.size(); i++) {
        if (sum[i] < sum[index]) {
            index = i;
        }
    }
    cout << index+1;

    return 0;
}