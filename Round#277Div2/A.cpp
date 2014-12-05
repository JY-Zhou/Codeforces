#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 1e5+5;
const double eps = 1e-8;

int main() {
    long long n;
    while(cin >> n) {
	if(n & 1) {
	    cout << (-((n+1)>>1)) << endl;
	} else {
	    cout << (n >> 1) << endl;
	}
    }
    return 0;
}
