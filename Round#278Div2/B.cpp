#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-8;

bool judge (int a, int b, int c, int d) {
    int t[4];
    t[0] = a, t[1] = b, t[2] = c, t[3] = d;
    sort(t, t+4);
    double x = (double)(a + b + c + d)/4.0;
    double y = (double)(t[1] + t[2])/2.0;
    double z = fabs(t[3]-t[0]);
    
    return fabs(x-y) < eps && fabs(x-z) < eps;
}

int main() {
    int n;
    int a,b,c,d;
    cin >> n;
    if(n == 0) {
	puts("YES");
	puts("1\n1\n3\n3");
    } else if (n == 1) {
	cin >> a;
	puts("YES");
	cout << 2*a << endl;
	cout << 2*a << endl;
	cout << 3*a << endl;
    } else if (n == 2) {
	cin >> a >> b;
	if(a > b) swap(a, b);
	if (3 * a < b) {
	    puts("NO");
	} else if (3 * a == b) {
	    puts("YES");
	    cout << a + 1 << endl;
	    cout << b - 1 << endl;
	} else {
	    puts("YES");
	    cout << 4 * a - b << endl;
	    cout << 3 * a << endl;
	}
    } else if (n == 3) {
	cin >> a >> b >> c;
	for(int i = 1 ; i <= 1000000 ; i++) {
	    if(judge(a,b,c,i)) {
		puts("YES");
		cout << i << endl;
		return 0;
	    }
	}
	puts("NO");
    } else {
	cin >> a >> b >> c >> d;
	if(judge(a,b,c,d)) {
	    puts("YES");
	} else {
	    puts("NO");
	}
    }
    return 0;
}
