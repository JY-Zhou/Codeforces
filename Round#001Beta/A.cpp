#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x,y,a;
    cin >> x >> y >> a;
    if(x % a == 0) x /= a;
    else x = x/a + 1;
    if(y % a == 0) y /= a;
    else y = y/a + 1;
    cout << x*y << endl;

    return 0;
}
