#include <iostream>
#include <string>
#include <iostream>

using namespace std;

bool isCap(char x) {
    return x >= 'A' && x <= 'Z';
}

bool is(string s) {
    if(s.length() == 1 && s[0] >= 'A' && s[0] <= 'Z') return true;
    for(int i = 1; s[i]; i++) {
        if(!isCap(s[i])) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    if(is(s)) {
        for(int i = 0 ; s[i] ; i++) {
            if(isCap(s[i])) cout << (char)(s[i] - 'A' + 'a');
            else cout << (char)(s[i] - 'a' + 'A');
        }
        cout << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}
