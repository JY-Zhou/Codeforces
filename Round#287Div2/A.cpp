#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[105];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) {
	cin >> a[i].first;
	a[i].second = i+1;
    }
    sort(a, a+n);
    vector <int> ans;
    for(int i = 0; i < n ; i++) {
	if(k < a[i].first) {
	    break;
	}
	k -= a[i].first;
	ans.push_back(a[i].second);
    }
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++) {
	cout << ans[i] << " \n"[i==ans.size()-1];
    }
    return 0;
}
