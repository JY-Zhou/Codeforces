#include <iostream>
using namespace std;

int a[10] = {2,7,2,3,3,4,2,5,1,2};

int main() {
    int n;
    cin >> n;
    cout << a[n/10] * a[n%10] << endl;
}
