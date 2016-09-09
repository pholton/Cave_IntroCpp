#include "stdafx.h"
#include <iostream>

using namespace std;

int main() {

	string password = 'password';
	cout << "Enter your password > " << flush;

	string input;
	cin >> input;

	cout << "'" << input << "'" << endl;

	if (password == input) {

	}
}