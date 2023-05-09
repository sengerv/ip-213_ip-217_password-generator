#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#include <libpwdgen/pwdgenerator.h>

#include <ctest.h>

CTEST(TEST_Generator, check_flag_lowercase)
{
	bool isAllLower = true;
	char buf[256];
	string pw1;
	string password = PWD_Generator().generate(10, true, false, false, false);
	strcpy(buf, password.c_str());
	for (int i = 0; i < 10; i++) {
	    	if (!islower(buf[i])) {
	      		isAllLower = false;
				break;
	    	}
  	}
	ASSERT_EQUAL(true, isAllLower);
	cout <<"Test_flag_lowercase OK: " << password << endl;
}

CTEST(TEST_Generator, check_flag_uppercase)
{
	bool isAllUpper = true;
	char buf[256];
	string pw1;
	string password = PWD_Generator().generate(10, false, true, false, false);
	strcpy(buf, password.c_str());
	for (int i = 0; i < 10; i++) {
	    	if (!isupper(buf[i])) {
	      		isAllUpper = false;
				break;
	    	}
  	}
	ASSERT_EQUAL(true, isAllUpper);
	cout <<"Test_flag_uppercase OK: " << password << endl;
}

CTEST(TEST_Generator, check_flag_digit)
{
	bool isAllDigits = true;
	char buf[256];
	string pw1;
	string password = PWD_Generator().generate(10, false, false, true, false);
	strcpy(buf, password.c_str());
	for (int i = 0; i < 10; i++) {
	    	if (!isdigit(buf[i])) {
	      		isAllDigits = false;
				break;
	    	}
  	}
	ASSERT_EQUAL(true, isAllDigits);
	cout <<"Test_flag_digit OK: " << password << endl;
}

CTEST(TEST_Generator, check_flag_special)
{
	bool isAllSpecial = true;
	char buf[256];
	string pw1;
	string password = PWD_Generator().generate(10, false, false, false, true);
	strcpy(buf, password.c_str());
	for (int i = 0; i < 10; i++) {
		bool ifHaveSpecialSymbol = false;
		for (char c : pwd_special)
		{
	    	if (buf[i] == c) {
	      		ifHaveSpecialSymbol = true;
	    	}
		}
		if (!ifHaveSpecialSymbol)
		{
			isAllSpecial = false;
			break;
		}
  	}
	ASSERT_EQUAL(true, isAllSpecial);
	cout <<"Test_flag_special OK: " << password << endl;
}


