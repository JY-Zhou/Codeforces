#include <iostream>
#include <string>

using namespace std;

string reverse(string s) {
    string ret = "";
    for(int i = s.length()-1 ; i >= 0 ; i--) {
        ret += s[i];
    }
    return ret;
}

int main() {
    string a,b;
    cin >> a >> b;
    b = reverse(b);
    if(a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
