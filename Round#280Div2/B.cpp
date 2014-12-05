#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double a[2005];

int main() {
    int n,l;
    cin >> n >> l;
    for(int i = 0 ; i < n ; i++) {
	cin >> a[i];
    }
    sort(a, a+n);
    double res = -1;
    if(a[0] != 0) {
	for(int i = 0 ; i < n ; i++) {
	    if(a[i] != 0) {
		res = max(res, (double)a[i]);
		break;
	    }
	}
    }
    if(a[n-1] != l) {
	for(int i = n-1 ; i >= 0 ; i--) {
	    if(a[i] != l) {
		res = max(res, (double)l-a[i]);
		break;
	    }
	}
    }
    a[n] = 0;
    a[n+1] = l;
    sort(a, a+n+2);
    for(int i = 1 ; i < n+2 ; i++) {
	res = max(res, (a[i] - a[i-1])/2.0);
    }
    printf("%.9f\n", res+1e-12);
    return 0;
}
