#include <iostream>
#include <vector> 
#include <set>
#include <iterator>
#include <algorithm> 
#include <stddef.h>
#include <string> 

using namespace std;

int main()
{
    int n, m;
    char c, tmp;
    cin >> n >> m >> c;
    vector<char> vtmp;
    vector<vector<char>> v;
    set <int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            vtmp.push_back(tmp);
        }
        v.push_back(vtmp);
        vtmp.clear();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == c) {
                if ((i-1<n) && (i-1 >=0)) {
                    if ((v[i-1][j] != c) && (v[i-1][j] != '.')) {
                        s.insert(v[i - 1][j]);
                    }
                } 

                if ((i+1<n) && (i+1 >=0)) {
                    if ((v[i+1][j] != c) && (v[i+1][j] != '.')) {
                        s.insert(v[i + 1][j]);
                    }
                }

                if ((j-1<m) && (j-1 >=0)) {
                    if ((v[i][j-1] != c) && (v[i][j-1] != '.')) {
                        s.insert(v[i][j-1]);
                    }
                }

                if ((j+1<m) && (j+1 >=0)) {
                    if ((v[i][j+1] != c) && (v[i][j+1] != '.')) {
                        s.insert(v[i][j+1]);
                    }
                }
            }
        }
    }

    cout << s.size();

    return 0;
}