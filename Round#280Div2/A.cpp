#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int i = 1;
    while(1) {
	sum += i;
	n -= sum;
	if(n < 0) break;
	i++;
    }
    cout << i-1 << endl;
    return 0;
}
