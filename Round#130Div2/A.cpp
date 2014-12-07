#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int pos = -1;
    while((pos = s.find("WUB", 0)) >= 0) {
        s.replace(pos, 3, "#");
    }
    vector <string> res;
    for(int i = 0 ; s[i] ;) {
        if(s[i] != '#') {
            string temp = "";
            while(s[i] && s[i] != '#') temp += s[i++];
            res.push_back(temp);
        } else {
            i++;
        }
    }
    for(int i = 0; i < res.size() ; i++) {
        cout << res[i];
        if(i != res.size() - 1) cout << " ";
        else cout << endl;
    }
    return 0;
}
