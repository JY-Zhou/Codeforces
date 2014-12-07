#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string t = "hello";
    int id = 0;
    for(int i = 0 ; s[i] ; i++) {
        if(s[i] == t[id]) {
            id++;
        }
    }
    if(id == 5) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
