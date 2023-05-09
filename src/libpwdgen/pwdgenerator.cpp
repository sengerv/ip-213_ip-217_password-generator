#include <iostream>
#include <libpwdgen/pwdgenerator.h>

string PWD_Generator::generate(size_t lenght, bool flag_lowercase, bool flag_uppercase, bool flag_digit, bool flag_special)
{
	string result, password;

	if (!flag_lowercase && !flag_uppercase && !flag_digit && !flag_special) {
		return "";
	}

	if (flag_lowercase) {
		result += pwd_lowercase;
	}

	if (flag_uppercase) {
		result += pwd_uppercase;
	}

	if (flag_digit) {
		result += pwd_digit;
	}

	if (flag_special) {
		result += pwd_special;
	}

	uniform_int_distribution<int> dist(0, result.length() - 1);
	for (size_t i = 0; i < lenght; i++) {
		password += result[dist(rng)];
	}
	
	return password;
}