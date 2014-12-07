#include <iostream>
#include <string>

using namespace std;

string parse(string s) {
    string ret = "";
    for(int i = 0 ; s[i] ; i++) {
        ret += (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 'a' : s[i];
    }
    return ret;
}

int main() {
    string a,b;
    cin >> a >> b;
    a = parse(a);
    b = parse(b);
    if(a > b) cout << 1 << endl;
    else if(a < b) cout << -1 << endl;
    else cout << 0 << endl;
    return 0;
}
