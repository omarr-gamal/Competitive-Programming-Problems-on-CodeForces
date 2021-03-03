#include <iostream>
#include <vector> 
#include <set>
#include <iterator>
#include <algorithm> 

using namespace std;

int main()
{
    vector<int> myvector;
    vector<int> result;
    int T, m, s;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> m;
        myvector.push_back(m);
    }

    for (int i = 0; i < myvector.size(); i++) {
        s = 1;
        for (int j = i+1; j < myvector.size(); j++) {
            if (myvector[j] <= myvector[j-1]) {
                s++;
            }
            else {
                break;
            }
        }
        for (int k = i-1; k >= 0; k--) {
            if (myvector[k] <= myvector[k+1]) {
                s++;
            }
            else {
                break;
            }
        }
        result.push_back(s);    
    }
    sort(result.begin(), result.end());
    reverse(result.begin(), result.end());
    cout << result[0]<<endl;

    return 0;
}