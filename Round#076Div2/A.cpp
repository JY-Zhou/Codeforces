#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    map <string, int> m;
    for(int i = 0 ; i < 10 ; i++) {
        string temp;
        cin >> temp;
        m[temp] = i;
    }
    for(int i = 0 ; i < 80 ; i+=10) {
        cout << m[s.substr(i, 10)];
    }
    cout << endl;
    return 0;
}
