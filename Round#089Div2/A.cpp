#include <iostream>
#include <string>
using namespace std;

int main() {
    string vow = "AEIOUYaeiouy";
    string s;
    cin >> s;
    string t = "";
    for(int i = 0 ; s[i] ; i ++) {
	bool pass = false;
	for(int j = 0 ; vow[j] ; j++) {
	    if(s[i] == vow[j]) {
		pass = true;
		break;
	    }
	}
	if(pass) continue;
	t += s[i];
    }
    for(int i = 0 ; t[i] ; i++) {
	cout << ".";
	if(t[i] >= 'A' && t[i] <= 'Z') cout << (char)(t[i]-'A'+'a');
	else cout << t[i];
    }
    cout << endl;
    return 0;
}
