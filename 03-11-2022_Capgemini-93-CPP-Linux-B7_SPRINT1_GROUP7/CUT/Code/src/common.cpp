#include <InputFile.h>
#include <common.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <thread>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <set>

using namespace std;

Common::Common(){
}
Common::Common(string file){
	this->file = file;
}
Common::~Common(){
}

void Common::getCommonWords(){
	ifstream common;
	try{
		common.open(file.c_str());
		if(!common.is_open()){
			throw "invalid" ;
		}
	}
	catch(...){
		cout << "common words file not found" << endl ;
	}
	string line;
	while(getline(common,line)){
		stringstream ss(line);
		string cword;
		while(getline(ss,cword,' ')){
			// common words in commonword.txt files are stored in set
			commonWords.insert(cword) ;
		}
	}
	common.close();
}


