#include "InputFile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <thread>
#include <string>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <set>
int flag = 0;
using namespace std;
map<string,int> frequencyCount;
set<string> commonWords;
string Tes::getfile(){
	return file;
}
void Tes::setFile(string name){
	file = name;
}
int Tes::readInputFile(string file){
        const char* file_name = file.c_str();
	ifstream input;
	try{
		input.open(file_name);
		if(!input.is_open()){
			throw "file not found" ;
		}
	}
	catch(...){
		flag = 1;
	}
	fstream invalid;
	try{
		invalid.open("output/invalid.txt");
		if(!invalid.is_open()){
			throw "file not found" ;
		}
	}
	catch(...){
	}
	string line;
	while(getline(input,line)){
		stringstream ss(line);
		string word;
		while(getline(ss,word,' ')){
			if(!(find(commonWords.begin(),commonWords.end(),word)!=commonWords.end())){
				if(std::string::npos != word.find_first_of("0123456789")){
					invalid << word << '\t' ;	
				}
				else{
					transform(word.begin(),word.end(),word.begin(), ::tolower);
					if(frequencyCount.find(word)!=frequencyCount.end()){
						frequencyCount.at(word)=frequencyCount.at(word)+1;
					}
					else{
						frequencyCount.insert(pair<string,int>(word,1));
					}
				}
			}

		}
	}
	invalid.close();
	input.close();
	return flag;
}

