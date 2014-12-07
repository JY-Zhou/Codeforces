#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct XX {
    string name;
    int id;
    int priority;
    
    bool operator < (const XX & c) const {
        if(priority == c.priority) 
            return id < c.id;
        return priority < c.priority;
    }
} a[105];

int main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        string sa, b;
        cin >> sa >> b;
        a[i].name = sa;
        a[i].id = i;
        if(b == "captain") a[i].priority = 4;
        else if(b == "man") a[i].priority = 3;
        else if(b == "woman" || b == "child") a[i].priority = 2;
        else if(b == "rat") a[i].priority = 1;
    }
    sort(a, a+n);
    for(int i = 0 ; i < n ; i++) {
        cout << a[i].name << endl;
    }
    return 0;
}
