#include <iostream>
#include <string>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	string s = to_string(a + b);
	for (int i = 0; i < s.length(); i++){
		cout << s[i];
		if (s[i] == '-')
			continue;
		if (s.length() % 3 == (i + 1) % 3 && i + 1 != s.length())
			cout << ',';
	}
	return 0;
	//
}