#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int x[26], y[26];
    for(int i = 0 ; i < 26 ; i++) {
        x[i] = y[i] = 0;
    }
    for(int i = 0 ; a[i] ; i++) x[a[i]-'A']++;
    for(int i = 0 ; b[i] ; i++) x[b[i]-'A']++;
    for(int i = 0 ; c[i] ; i++) y[c[i]-'A']++;
    for(int i = 0 ; i < 26 ; i++) {
        if(x[i] != y[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
