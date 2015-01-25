#include <bits/stdc++.h>

using namespace std;

int main() {
    double r,x,y,x1,y1;
    cin >> r >> x >> y >> x1 >> y1;
    double dist = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    double d = 2*r;
    int k = dist/d;
    if(dist-d*k < 1e-8) cout << (int)k << endl;
    else cout << (int)k + 1 << endl;
    return 0;
}
