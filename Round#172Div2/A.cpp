#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    if(s[0] >= 'a' && s[0] <= 'z') cout << (char)(s[0] - 'a' + 'A');
    else cout << s[0];
    cout << s.substr(1, s.length()-1) << endl;
    return 0;
}
