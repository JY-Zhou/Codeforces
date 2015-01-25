#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string a;
    cin >> a;
    int pos = -1;
    int len = a.length();
    vector <int> v;
    for(int i = 0 ; i < len ; ) {
        if(i+4 < len && a[i] == 'h' && a[i+1] == 'e' 
                && a[i+2] == 'a' && a[i+3] == 'v' && a[i+4] == 'y') {
            v.push_back(1);
            i += 5;
        } else if(i+4 < len && a[i] == 'm' && a[i+1] == 'e'
                && a[i+2] == 't' && a[i+3] == 'a' && a[i+4] == 'l') {
            v.push_back(0);
            i += 5;
        } else {
            i++;
        }
    }
    long long ans = 0;
    long long ext = 0;
    for(int i = 0 ; i < v.size() ; i++) {
        if(v[i] == 1) ext ++;
        if(v[i] == 0) ans += ext;
    }
    cout << ans << endl;
    return 0;
}
