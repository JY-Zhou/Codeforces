#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector <int> a[3];
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
	int t;
	cin >> t;
	a[t-1].push_back(i);
    }
    int res = 0x3f3f3f3f;
    for(int i = 0 ; i < 3 ; i ++) {
	int s = a[i].size();
	res = min(res, s);
    }
    cout << res << endl;
    for(int i = 0 ; i < res ; i++) {
	cout << a[0][i] << ' ' << a[1][i] << ' ' << a[2][i] << endl;
    }
    return 0;
}
