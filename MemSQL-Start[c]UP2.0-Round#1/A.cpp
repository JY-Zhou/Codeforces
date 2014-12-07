#include <iostream>
#include <string>

using namespace std;

const string eevee[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0 ; i < 8 ; i++) {
        if(eevee[i].length() == n) {
            bool flag = false;
            for(int k = 0 ; s[k] ; k++) {
                if(s[k] != '.' && s[k] != eevee[i][k]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout << eevee[i] << endl;
                return 0;
            }
        }
    }
    return 0;
}
