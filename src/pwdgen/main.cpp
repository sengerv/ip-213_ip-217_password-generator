#include <iostream>
#include <string.h>
#include "cxxopts.h"

#include <libpwdgen/pwdgenerator.h>

using namespace std;
using namespace cxxopts;

int main(int argc, char **argv){
	Options options("pwdgen.exe", "Password Generator by Maxim and Vladik :)");
	options.add_options()
		("l,lowercase", "Include lowercase letters")
		("u,uppercase", "Incldue uppercase letters")
		("d,digit", "Include digit")
		("s,special", "Include special simbols")
		("c,count", "Count password to generate", cxxopts::value<size_t>()->default_value("1"))
		("n,lenght", "Password lenght", cxxopts::value<size_t>()->default_value("10"))
		("h,help", "Print help directory")
		;


	auto args = options.parse(argc, argv);

	bool f1, f2, f3, f4;
  	if (args.count("l") == 0 && args.count("u") == 0
    && args.count("d") == 0 && args.count("s") == 0) 
	{
    	f1 = true;
		f2 = true;
		f3 = true;
		f4 = true;
		cout << "Enter \"pwdgen.exe -h \" to see info.." << endl;
  	}
  	else 
	{
		f1 = args.count("l");
		f2 = args.count("u");
		f3 = args.count("d");
		f4 = args.count("s");
  	}

	PWD_Generator gener;
	cout << gener.generate(6, f1, f2, f3, f4) << endl;

	if (args.count("h")) {
		cout << options.help() << endl;
		cout << "example: pwdgen.exe -u -n 10" << endl;
		exit(0);
	}
}