#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int dpmax[105][905], dpmin[105][905];

int dfsmin(int m, int s, bool first) {
    if(s < 0) return dpmin[m][s] = -2;
    if(m == 1) {
	if(s > 9) return dpmin[m][s] = -2;
	return dpmin[m][s] = s;
    }
    if(dpmin[m][s] != -1)
	return dpmin[m][s];
    int ret = 0x3f3f3f3f;
    for(int i = 9 ; i >= (first ? 1 : 0) ; i--) {
	int t = dfsmin(m-1,s-i,false);
	if(t != -2) {
	    int mul = 1;
	    for(int k = 0 ; k < m-1 ; k++) mul *= 10;
	    ret = min(ret, t+mul*i);
	}
    }
    if(ret == 0x3f3f3f3f) return dpmin[m][s] = -2;
    return dpmin[m][s] = ret;
}

int dfsmax(int m, int s, bool first) {
    if(s < 0) return dpmax[m][s] = -2;
    if(m == 1) {
	if(s > 9) return dpmax[m][s] = -2;
	return dpmax[m][s] = s;
    }
    if(dpmax[m][s] != -1) return dpmax[m][s];
    int ret = -0x3f3f3f3f;
    for(int i = 9 ; i >= (first ? 1: 0) ; i--) {
	int t = dfsmax(m-1,s-i,false);
	if(t != -2) {
	    int mul = 1;
	    for(int k = 0 ; k < m-1 ; k++) mul *= 10;
	    ret = max(ret, t + mul *i);
	}
    }
    if(ret == -0x3f3f3f3f) return dpmax[m][s] = -2;
    return dpmax[m][s] = ret;
}

int main() {
    int m, s;
    cin >> m >> s;
    memset(dpmax, -1, sizeof(dpmax));
    memset(dpmin, -1, sizeof(dpmin));
    int a1 = dfsmin(m,s,true);
    int a2 = dfsmax(m,s,true);
    if(a1 < 0) a1 = -1;
    if(a2 < 0) a2 = -1;
    cout << a1 << ' ' << a2 << endl;
}
