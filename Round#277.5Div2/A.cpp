#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct XX {
    int val;
    int id;
    bool operator < (const XX & c) const{
	return val < c.val;
    }
} a[3005];

int n;
bool vis[3005];
queue <int> f, t;

int main() {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
	scanf("%d", &a[i].val);
	a[i].id = i;
    }
    sort(a, a+n);
    memset(vis, 0, sizeof(vis));
    int m = 0;
    for(int i = 0 ; i < n ; i++) {
	int ii = i;
	if(!vis[ii]) {
	    vis[ii] = true;
	    if(!vis[a[ii].id]) {
		while(!vis[a[ii].id]) {
		    vis[a[ii].id] = true;
		    f.push(ii);
		    t.push(a[ii].id);
		    ii = a[ii].id;
		    m ++;
		}
	    }
	}
    }
    cout << m << endl;
    while(!f.empty()) {
	cout << f.front() << ' ' << t.front() << endl;
	f.pop();
	t.pop();
    }
    return 0;
}
