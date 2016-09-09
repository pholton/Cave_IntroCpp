#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {

	string password = "password";
	cout << "Enter your password > " << flush;

	string input;
	cin >> input;

	//cout << "'" << input << "'" << endl;

	if (password == input) {
		cout << "Password accepted" << endl;
	}
	else {
		cout << "Access denied" << endl;
	}
}