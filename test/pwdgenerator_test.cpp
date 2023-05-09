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