#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int sa[26], sb[26];
    for(int i = 0 ; i < 26; i ++) sa[i] = sb[i] = 0;
    for(int i = 0 ; a[i] ; i++) sa[a[i]-'a'] ++;
    for(int i = 0 ; b[i] ; i++) sb[b[i]-'a'] ++;
    if(a.length() == b.length()) {
        bool can = true;
        for(int i = 0 ; i < 26; i++) {
            if(sa[i] != sb[i]) {
                can = false;
                break;
            }
        }
        if(can) {
            cout << "array" << endl;
            return 0;
        }
    } else if(a.length() > b.length()) {
        bool can = true;
        for(int i = 0 ; i < 26 ; i++) {
            if(sa[i] < sb[i]) {
                can = false;
                break;
            }
        }
        if(can) {
            int i,j;
            for(i = j = 0; a[i] && b[j] ; ) {
                if(a[i] == b[j]) i++, j++;
                else i++;
            }
            if(j == b.length()) cout << "automaton" << endl;
            else cout << "both" << endl;
            return 0;
        }
    }
    cout << "need tree" << endl;
    return 0;
}
