#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n, p;
    cin >> n >> p;
    string a = "", b ="";
    string s;
    cin >> s;
    int l = s.length()-1;
    bool f = true;
    int st = 0;
    int ed = 0;
    for(int i = 0 ; i < n/2 ; i++) {
	if(s[i] != s[l-i]) {
	    f = false;
	    if(f) st = i;
	    else ed = i;
	}
    }
    if(f) {
	cout << 0 << endl;
	return 0;
    }
    int ret = n/2-1;
    if(n % 2 == 1 && p == n/2+1) p = 0;
    else {
	if( p <= n/2) {
	} else {
	    p = n + 1 - p;
	}
	if(p >= ed + 1 || p <= st + 1)
	    ret += ed - st;
	else 
	    ret += ed - st + (min (ed+1-p, p-1));
    }
    for(int i = 0 ; i < n/2 ; i ++) {
	int d = s[i] - s[l-i];
	d = abs(d);
	d = min(26-d, d);
	ret += d;
    }
    cout << ret << endl;
    return 0;
}
