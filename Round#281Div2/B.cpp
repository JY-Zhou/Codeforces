#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long sa = 0, sb = 0;
    bool res = true;
    vector <int> a, b;
    while (n--) {
	int x;
	cin >> x;
	if(n == 0) {
	    res = x > 0;
	}
	if(x > 0) {
	    sa += x;
	    a.push_back(x);
	} else {
	    x = -x;
	    sb += x;
	    b.push_back(x);
	}
    }
    if(sa > sb) {
	cout << "first" << endl;
    } else if(sb > sa) {
	cout << "second" << endl;
    } else {
	int flag = 1;
	int i = 0;
	for( ; i < min(a.size(), b.size()) ; i++) {
	    if(a[i] != b[i]) {
		flag = a[i] - b[i];
		break;
	    }
	}
	if(i >= min(a.size(), b.size())) {
	    flag = a.size()-b.size();
	}
	if(flag > 0) {
	    cout << "first" << endl;
	} else if(flag < 0) {
	    cout << "second" << endl;
	} else {
	    if(res) cout << "first" << endl;
	    else cout << "second" << endl;
	}
    }
    return 0;
}
