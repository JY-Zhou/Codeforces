#include <bits/stdc++.h>

using namespace std;

long long i = 1l;

long long dfs(long long h, long long n, int dir) {
    if(h == 0) return 0;
    int k = (n > (i << (h-1)));
    long long next = k ? (n - (i<<(h-1))) : n;
    if(dir ^ k) return (i << h) + dfs(h-1, next, dir);
    return dfs(h-1, next, dir^1) + 1;
}

int main() {
    long long h, n;
    cin >> h >> n;
    cout << dfs(h, n, 0) << endl;
    return 0;
}
