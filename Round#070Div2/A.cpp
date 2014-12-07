#include <iostream>
#include <string>

using namespace std;

int main() {
    string a,b,c;
    string v = "aeiou";
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    int ans = 0;
    for(int i = 0 ; a[i] ; i++) {
        for(int j = 0 ; v[j] ; j++) {
            if(a[i] == v[j]) {
                ans ++;
            }
        }
    }
    if(ans != 5) {
        cout << "NO" << endl;
        return 0;
    }
    ans = 0;
    for(int i = 0 ; b[i] ; i++) {
        for(int j = 0 ; v[j] ; j++) {
            if(b[i] == v[j]) {
                ans ++;
            }
        }
    }
    if(ans != 7) {
        cout << "NO" << endl;
        return 0;
    }
    ans = 0;
    for(int i = 0 ; c[i] ; i++) {
        for(int j = 0 ; v[j] ; j++) {
            if(c[i] == v[j]) {
                ans ++;
            }
        }
    }
    if(ans != 5) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
