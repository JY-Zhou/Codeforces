#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool judge(int x) {
    while(x > 0) {
	if(x % 10 == 8) {
	    return true;
	}
	x /= 10;
    }
    return false;
}

int main () {
    int n;
    cin >> n;
    int i = 1;
    while(1) {
	if(judge(abs(n+i))) {
	    cout << i << endl;
	    break;
	}
	i++;
    }
    return 0;
}
