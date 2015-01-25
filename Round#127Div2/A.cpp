#include <iostream>
#include <string>

using namespace std;

bool isPal(string s) {
    int i = 0 , j = s.length() - 1;
    while(i < j) {
        if(s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    string ans = "";
    for(int i = 0 ; i < (1<<(n+1))-1 ; i++) {
        string temp = "";
        for(int k = 0 ; k < n ; k++) {
            if(i & (1 << k)) {
                temp += s[k];
            }
        }
        if(isPal(temp) && temp > ans) {
            ans = temp;
        }
    }
    cout << ans << endl;
    return 0;
}
