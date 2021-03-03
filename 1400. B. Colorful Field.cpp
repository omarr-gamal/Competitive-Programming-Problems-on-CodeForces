#include <iostream>
#include <vector> 
#include <set>
#include <iterator>
#include <algorithm> 
#include <stddef.h>
#include <string> 

using namespace std;

struct Cell {
    unsigned short n;
    unsigned short m;

    bool operator==(const Cell& rhs) const noexcept
    {
        return this->n == rhs.n && this->m == rhs.m;
    }
};

int main()
{
    unsigned short n, m, k, t, tmp, tmp2;
    int p = 0;
    int o, res;
    char counter = 'c';
    cin >> n >> m >> k >> t;
    struct Cell cell;
    vector<Cell> wastefield;

    for (short i = 0; i < k; i++) {
        cin >> cell.n >> cell.m;
        wastefield.push_back(cell);
    }

    for (short i = 0; i < t; i++) {
        cin >> tmp >> tmp2;

        cell.n = tmp; 
        cell.m = tmp2;

        if (count(wastefield.begin(), wastefield.end(), cell)) {
            cout << "Waste" << endl;
        } else {
            o = ((tmp - 1) * (m)) + tmp2 - 1;
            for (int i = 0; i < wastefield.size(); i++){
                int b = (wastefield[i].n - 1) * (m)+(wastefield[i].m - 1);
                if (b < o) {
                    p++;
                }
            }
            res = o - p;
            if (res % 3 == 1) {
                cout << "Kiwis" << endl;
                p = 0;
            }
            else if (res % 3 == 2) {
                cout << "Grapes" << endl;
                p = 0;
            }
            else if (res % 3 == 0) {
                cout << "Carrots" << endl;
                p = 0;
            }
        }
    }
    return 0;
}