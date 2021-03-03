#include <iostream>
#include <vector> 
#include <set>
#include <iterator>
#include <algorithm> 
#include <stddef.h>

using namespace std;

struct P {
    int a;
    int b;
};

bool sortMatches(P p1, P p2){
    return (p1.b < p2.b);
}

int main()
{
    int n, m, tmpA, tmpB, maxM=0;
    cin >> n >> m;
    vector<P> containers;
    for (int i = 0; i < m; i++) {
        cin >> tmpA >> tmpB;
        P tmpP = { tmpA, tmpB };
        containers.push_back(tmpP);
    }
    sort(containers.begin(), containers.end(), sortMatches);
    reverse(containers.begin(), containers.end());
    for (auto x : containers) {
        if (n == x.a) {
            n -= x.a;
            maxM += (x.a * x.b);
            cout << maxM;
            return 0;
        }
        else if (n > x.a) {
            n -= x.a;
            maxM += (x.a * x.b);
        }
        else if (n < x.a) {
            maxM += (n * x.b);
            n -= x.a;
            cout << maxM;
            return 0;
        }
    }
    if (n != 0) {
        cout << maxM;
    }
    return 0;
}