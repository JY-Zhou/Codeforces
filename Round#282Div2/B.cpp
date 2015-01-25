#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int s = a-b;
    if(s == 0) {
        cout << "infinity" << endl;
    } else if (s == 1) {
        cout << 1 << endl;
    } else {
        int m = 2;
        int ans = 0;
        while(s > b) {
            if(s % m == 0) {
                ans ++;
                while(s % m == 0) {
                    s /= m;
                }
            }
            m++;
        }
        cout << ans << endl;
    }
    return 0;
}
