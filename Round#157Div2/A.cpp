#include <iostream>
#include <string>

using namespace std;

int main() {
    string a[8];
    for(int i = 0 ; i < 8 ; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 1 ; j < 8 ; j++) {
            if(a[i][j] == a[i][j-1]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
