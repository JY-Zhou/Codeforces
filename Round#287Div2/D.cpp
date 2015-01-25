#include <bits/stdc++.h>

using namespace std;

long long dp[1005][105][2];
long long m;
int n, k;

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> k >> m;
    if(n == 1) {
	int sum = 0;
	for(int x = 1 ; x < 10 ; x++) {
	    sum += (x % k == 0);
	}
	cout << sum%m << endl;
    } else {
	for(int x = 0 ; x < 10 ; x++) {
	    dp[1][x%k][x==0] ++;
	    dp[1][x%k][x==0] %= m;
	}
	long long e = 1;
	for(int i = 2 ; i <= n ; i++) {
	    e = (e * 10) % k;
	    for(int x = 0 ; x < 10 ; x++) {
		for(int j = 0 ; j < k ; j++) {
		    long long idx = e;
		    idx = e * x % k;
		    idx = (j + k - idx) % k;
		    if(idx != 0) {
			dp[i][j][x==0] += dp[i-1][idx][0]%m;
			dp[i][j][x==0] %= m;
		    }
		    dp[i][j][x==0] += dp[i-1][idx][1]%m;
		    dp[i][j][x==0] %= m;
		}
	    }
	}
	long long sum = 0;
	long long fuk = 1;
	for(int i = n ; i >= 1 ; i--) {
	    if(i == n-1) fuk *= 9;
	    if(i < n-1) fuk *= 10, fuk %= m;
	    int t = dp[i][0][0] * fuk % m;
	    sum += t;
	    sum %= m;
	}
	cout << sum << endl;
    }
}
