#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int r[105], c[105];
int b[105][105];

int main () {
    int m,n;
    scanf("%d%d",&m,&n);
    memset(r, -1, sizeof(r));
    memset(c, -1, sizeof(c));
    for(int i = 0 ; i < m ; i ++) {
	for(int j = 0 ; j < n ; j++){
	    scanf("%d",&b[i][j]);
	}
    }
    if(m == 1 && n == 1) {
	cout << "YES" << endl;
	cout << b[0][0] << endl;
	return 0;
    }
    for(int i = 0 ; i < m ; i++) {
	for(int j = 0 ; j < n ; j++) {
	    if(b[i][j] == 1) {
		if(r[i] == -1) {
		    r[i] = 1;
		    for(int k = 0 ; k < n ; k++)
			r[i] &= b[i][k];
		}
		if(c[j] == -1) {
		    c[j] = 1;
		    for(int k = 0 ; k < m ; k++)
			c[j] &= b[k][j];
		}
		if(c[j] == 0 && r[i] == 0) {
		    puts("NO");
		    return 0;
		}
	    }
	}
    }
    puts("YES");
    for(int i = 0 ; i < m ; i++) {
	for(int j = 0 ; j < n ; j++) {
	    printf("%d", (r[i] & c[j]));
	    if( j == n - 1 ) puts("");
	    else putchar(' ');
	}
    }

    return 0;
}
