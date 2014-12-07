#include <iostream>
#include <string>

using namespace std;

string tick(string s) {
    int n = (s[0] - '0') * 600 + (s[1] - '0') * 60 
        + (s[3] - '0') * 10 + (s[4] - '0');
    n ++;
    int h = n / 60 % 24;
    int m = n % 60;
    s = "";
    s += h / 10 + '0';
    s += h % 10 + '0';
    s += ':';
    s += m / 10 + '0';
    s += m % 10 + '0';
    return s;
}

bool isPal(string s) {
    int i = 0, j = s.length()-1;
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
    string next;
    while(!isPal(next = tick(s))) {
        s = next;
    }
    cout << next << endl;
    return 0;
}
