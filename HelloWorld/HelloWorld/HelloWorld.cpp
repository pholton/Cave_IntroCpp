// HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string input;

	cout << "Enter your name: " << flush;
	cin >> input;
	cout << "Hello " << input << endl;

	float fValue = 76.4;
	// fixed comes from iomanip.h, can also use scientific
	// defines how cout will show the float (scientific vs. fixed)
	cout << fixed << fValue << endl;
	// setprecision also comes from iomanip.h
	cout << setprecision(20) << fValue << endl;

	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;

	cout << (double)fValue << endl;

	//system("pause");

	return 0;
}

