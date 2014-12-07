#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a[4];
    int l = 0;
    for(int i = 0 ; i < 4; i++) a[i] = 0;
    for(int i = 0 ; s[i] ; i++) {
        if(s[i] != '+') {
            a[s[i]-'0']++;
            l++;
        }
    }
    l --;
    for(int i = 1 ; i < 4; i++) {
        while(a[i]) {
            cout << i;
            a[i] --;
            if(l > 0) cout << '+';
            l--;
        }
    }
    cout << endl;

    return 0;
}
