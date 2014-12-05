#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct XX {
    ll a,b;
    bool operator< (const XX& c) const {
	return b < c.b;
    }
}ex[100005];

int main() {
    ll n, r, avg;
    cin >> n >> r >> avg;
    for(int i = 0 ; i < n ; i++) {
	cin >> ex[i].a >> ex[i].b;
    }
    sort(ex, ex + n);
    ll cur = 0;
    for(int i = 0 ; i < n ; i++) {
	cur += ex[i].a;
    }
    if(cur - avg*n >= 0) {
	cout << 0 << endl;
	return 0;
    }
    ll res = 0;
    for(int i = 0 ; i < n ; i++) {
	if(cur + (r-ex[i].a) - avg*n >= 0) {
	    int x = avg*n-cur;
	    res += x*ex[i].b;
	    break;
	} else {
	    cur += r-ex[i].a;
	    res += (r-ex[i].a)*ex[i].b;
	}
    }
    cout << res << endl;
    return 0;
}
