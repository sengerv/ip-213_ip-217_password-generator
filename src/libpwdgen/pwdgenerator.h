#pragma once
#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 400
#define MAX_CIRCLES 10
using namespace std;
#include <random>
#include <string>

const char pwd_lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char pwd_uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char pwd_digit[] = "1234567890";
const char pwd_special[] = "!@#$%^&*_+";

class PWD_Generator {

	random_device rd{};
	mt19937 rng{
		rd()
	};

public:
	string generate(size_t lenght, bool flag_lowercase, bool flag_uppercase, bool flag_digit, bool flag_special);
};

