#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    int len = s.length();
    for(int i = 0 ; i < len ; i++) {
        int k = 0;
        for(int j = i+3 ; j < len ; j++) {
            if(j < len && s[j] == 'r' && s[j-1] == 'a'
                    && s[j-2] == 'e' && s[j-3] == 'b') k = 1;
            ans += k;
        }
    }
    cout << ans << endl;
    return 0;
}
