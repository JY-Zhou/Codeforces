#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e6+5;
int ca[maxn],cb[maxn];
int dig[maxn];

int main() {
    string s;
    int a, b;
    cin >> s >> a >> b;
    memset(ca, -1, sizeof(ca));
    memset(cb, -1, sizeof(cb));

    int k = s.length();
    int ans = 1;
    int i = k - 1;
    while(s[i] == '0') i--, ans = ans*10%b;
    int m = 0;
    for(; i >= 0 ; i--) {
	cb[i] = m = (m + (s[i]-'0') * ans) % b;
	ans = ans * 10 % b;
    }
    m = 0;
    for(i = 0 ; i < k ; i++) {
	ca[i] = m = (m * 10 + s[i]-'0') % a;
    }
    
    for(i = 0 ; i < k-1 ; i++) {
	if(ca[i] == 0 && cb[i+1] == 0 && s[i+1]!='0') {
	    cout << "YES" << endl;
	    int j = 0;
	    for(; j <= i ; j++) cout << s[j];
	    cout << endl;
	    for(; j < k ; j++) cout << s[j];
	    cout << endl;
	    return 0;
	}
    }
    cout << "NO" << endl;
    return 0;
}
