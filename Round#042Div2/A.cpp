#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string a,b;
    cin >> a;
    n--;
    int sa = 1, sb = 0;
    while(n--) {
        string temp;
        cin >> temp;
        if(temp == a) sa++;
        else b = temp, sb++;
    }
    if(sa < sb) cout << b << endl;
    else cout << a << endl;
    return 0;
}
