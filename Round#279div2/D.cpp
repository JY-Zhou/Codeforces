#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct XX {
    long long x, y;
    int step;
    XX(long long xx, long long yy, int ss) {
	x = xx, y = yy, step = ss;
    }
    XX() {}
};

map <long long, XX> m[2];
map <long long, int> vis[2];
long long mod = 1e9+7.01;
long long ax,ay,bx,by;

void bfs() {
    if(ax*ay == bx*by) {
	cout << "0" << endl;
	cout << ax << " " << ay << endl;
	cout << bx << " " << by << endl;
	return;
    }
    queue <XX> q[2];
    for(int i = 0 ; i < 2 ; i++) 
	while(!q[i].empty())
	    q[i].pop();
    q[0].push(XX(ax, ay, 0));
    vis[0][ax*mod+ay] = 1;
    q[1].push(XX(bx, by, 0));
    vis[1][bx*mod+by] = 1;
    while(!q[0].empty() || !q[1].empty()) {
	for(int k = 0 ; k < 2 ; k++) {
	    if(!q[k].empty()) {
		int step = q[k].front().step;
		while(!q[k].empty() && q[k].front().step == step) {
		    XX cur = q[k].front();
		    q[k].pop();
		    if(m[k].count(cur.x*cur.y) == 0)
			m[k][cur.x*cur.y] = cur;
		    if(m[k^1].count(cur.x*cur.y) > 0) {
			XX anot = m[k^1][cur.x*cur.y];
			cout << anot.step + cur.step << endl;
			XX resa = m[0][cur.x*cur.y];
			XX resb = m[1][cur.x*cur.y];
			cout << resa.x << " " << resa.y << endl;
			cout << resb.x << " " << resb.y << endl;
			return;
		    }
		    for(int i = 2 ; i <= 3; i++) {
			if(cur.x > 1 && cur.x % i == 0) {
			    int nx = cur.x - cur.x / i;
			    if(nx > 0 && vis[k].count(nx*mod+cur.y) == 0) {
				q[k].push(XX(nx, cur.y, cur.step+1));
				vis[k][nx*mod+cur.y] = 1;
			    }
			}
			if(cur.y > 1 && cur.y % i == 0) {
			    int ny = cur.y - cur.y/i;
			    if(ny > 0 && vis[k].count(cur.x*mod+ny) == 0) {
				q[k].push(XX(cur.x, ny, cur.step+1));
				vis[k][cur.x*mod+ny] = 1;
			    }
			}
		    }
		}
	    }
	}
    }
    cout << "-1" << endl;
    return;
}

int main() {
    cin >> ax >> ay >> bx >> by;
    bfs();
    return 0;
}
