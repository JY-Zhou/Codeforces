#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string team[2];
int a[100][2];

int main() {
    cin >> team[0];
    cin >> team[1];
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    while(n--) {
	int time, id;
	char tt, col;
	cin >> time >> tt >> id >> col;
	int tn = (tt=='a'?1:0);
	int inc = (col=='y'?1:2);
	if(a[id][tn] >= 0)
	    a[id][tn] += inc;
	if(a[id][tn] >= 2) {
	    cout << team[tn] << ' ' << id << ' ' << time << endl;
	    a[id][tn] = -1;
	}
    }
    return 0;
}
