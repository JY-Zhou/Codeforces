#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int a[26];
    for(int i = 0 ; i < 26 ; i++) a[i] = 0;
    for(int i = 0 ; s[i] ; i++) a[s[i]-'a'] ++;
    for(int i = 0 ; i < 26 ; i++) {
        if(a[i] % n == 0) {
            a[i] /= n;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    string str = "";
    for(int i = 0 ; i < 26 ; i++) {
        for(int j = 0 ; j < a[i] ; j++) {
            str += i+'a';
        }
    }
    for(int i = 0 ; i < n ; i++) {
        cout << str;
    }
    cout << endl;
    return 0;
}
