#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int hm,am,dm;
int hy,ay,dy;
int ch,ca,cd;

int main() {
    cin >> hy >> ay >> dy;
    cin >> hm >> am >> dm;
    cin >> ch >> ca >> cd;
    int res = 0x3f3f3f3f;
    for(int i = 0 ; i < 205; i++) {
	for(int j = 0 ; j < 205 ; j++) {
	    if(ay + i <= dm) continue;
	    int t = 0;
	    if(hm % (ay+i - dm) == 0) t = hm / (ay+i-dm);
	    else t = (int)(hm / (ay+i-dm) + 1);
	    int hh = max(0, (am - dy - j) * t + 1 - hy);
	    res = min(res, i*ca + j*cd + hh*ch);
	}
    }
    cout << res << endl;
    return 0;
}
