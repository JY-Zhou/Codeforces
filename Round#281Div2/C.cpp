#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 3e5+5;
const int inf = 0x3f3f3f3f;

int n,m;
int a[maxn], b[maxn];
vector <int> c;

int main() {
    int res = -inf;
    int sa, sb;
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    cin >> m;
    for(int i = 0 ; i < m ; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    c.clear();

    int p,q;
    p = q = 0;
    c.push_back(min(a[0], b[0])-1);
    while(p < n && q < m) {
	if(a[p] < b[q]){
	    if(a[p] != c[c.size()-1])
		c.push_back(a[p]);
	    p++;
	} else if(a[p] > b[q]){
	    if(b[q] != c[c.size()-1]) 
		c.push_back(b[q]);
	    q++;
	} else {
	    if(a[p] != c[c.size()-1])
		c.push_back(a[p]);
	    p++, q++;
	}
    }
    if(p < n) {
	while(p < n) c.push_back(a[p++]);
    }
    if(q < m) {
	while(q < m) c.push_back(b[q++]);
    }

    for(int i = 0 ; i < c.size() ; i++) {
	int ia = upper_bound(a, a+n, c[i]) - a;
	int ib = upper_bound(b, b+m, c[i]) - b;
	int ta = 2*ia + 3*(n-ia);
	int tb = 2*ib + 3*(m-ib);
	if(ta - tb > res || (ta - tb == res && ta > sa)) {
	    sa = ta;
	    sb = tb;
	    res = sa - sb;
	}
    }
    if(2*n - 2*m > res || (2*n - 2*m == res && 2*n > sa)) {
	sa = 2*n;
	sb = 2*m;
	res = sa - sb;
    }
    cout << sa << ':' << sb << endl;
    return 0;
}
