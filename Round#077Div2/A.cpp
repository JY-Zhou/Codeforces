#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int a = 0;
    if(s.length() < 7) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0 ; i < 6 ; i++) a += s[i] - '0'; 
    for(int i = 6 ; s[i] ; i++) {
        a += s[i] - '0';
        if(a == 7 || a == 0) { 
            cout << "YES" << endl; 
            return 0;
        }
        a -= s[i-6] - '0';
    }
    cout << "NO" << endl;
    return 0;
}
