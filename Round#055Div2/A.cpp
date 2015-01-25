#include <iostream>
#include <string>

using namespace std;

bool isCap(char x) {
    return x >= 'A' && x <= 'Z';
}

int main() {
    string s;
    cin >> s;
    int a = 0 , b = 0;
    for(int i = 0 ; s[i] ; i++) {
        if(isCap(s[i])) a++;
        else b++;
    }
    if(a > b) {
        for(int i = 0 ; s[i] ; i++) {
            if(!isCap(s[i])) cout << (char)(s[i] - 'a' + 'A');
            else cout << s[i];
        }
        cout << endl;
    } else {
        for(int i = 0 ; s[i] ; i++) {
            if(isCap(s[i])) cout << (char)(s[i] - 'A' + 'a');
            else cout << s[i];
        }
        cout << endl;
    }
    return 0;
}

