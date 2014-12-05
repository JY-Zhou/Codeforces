#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2e5+5;
const int maxv = 1e6+5;

int prev[maxv], next[maxv];

struct XX {
    int a,b;
} pairs[maxn];

int res[maxn];

int main() {
    memset(prev, -1, sizeof(prev));
    memset(next, -1, sizeof(next));
    int n;
    cin >> n;
    int st, ed;
    for(int i = 0 ; i < n ; i++) {
	cin >> pairs[i].a >> pairs[i].b;
	if(pairs[i].a == 0) st = i;
	if(pairs[i].b == 0) ed = i;
	prev[pairs[i].b] = pairs[i].a;
	next[pairs[i].a] = pairs[i].b;
    }
    if(n % 2 == 1) {
	int t = pairs[st].b;
	for(int i = 1 ; i < n; i+=2) {
	    res[i] = t;
	    t = next[t];
	}
	for(int i = 0 ; i < n ; i++) {
	    if(prev[pairs[i].a] == -1 && next[pairs[i].a] != -1) {
		t = pairs[i].a; break;
	    }
	}
	for(int i = 0 ; i < n ; i+=2) {
	    res[i] = t;
	    t = next[t];
	}
    } else {
	int t = pairs[st].b;
	for(int i = 1 ; i < n; i+=2) {
	    res[i] = t;
	    t = next[t];
	}
	t = pairs[ed].a;
	for(int i = n-2 ; i >= 0; i-=2) {
	    res[i] = t;
	    t = prev[t];
	}
    }
    for(int i = 0 ; i < n ; i++) {
	cout << res[i];
	if(i < n-1) cout << ' ';
	else cout << endl;
    }

    return 0;
}
