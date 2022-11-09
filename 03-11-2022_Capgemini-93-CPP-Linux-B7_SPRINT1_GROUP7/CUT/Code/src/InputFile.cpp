#include <InputFile.h>
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

using namespace std;
map<string,int> frequencyCount;
set<string> commonWords;
string filename;

int readInputFile(string filename){
	// multiple input files are parsing 
	const char* file = filename.c_str();
	ifstream input;
	try{
		// opening input files
		input.open(file);
		if(!input.is_open()){
			throw "file not found" ;
		}

	}
	catch(...){
		cout << "Input File not found" << endl ;
	}
	fstream invalid;
	try{
		invalid.open("output/invalid.txt");
		if(!invalid.is_open()){
			throw "file not found" ;
		}
	}
	catch(...){
		cout << "output File is not found" << endl ;
	}
	string line;
	while(getline(input,line)){
		// tokenize each word in the input files
		stringstream ss(line);
		string word;
		while(getline(ss,word,' ')){
			// checking word in common word txt file 
			if(!(find(commonWords.begin(),commonWords.end(),word)!=commonWords.end())){
				// check if string has digit or not
				if(std::string::npos != word.find_first_of("0123456789")){
					invalid << word << '\t' ;	
					cout << "invalid word - stored in invalid.txt" << endl ;
				}
				else{
					// compare the word case insensitive
					transform(word.begin(),word.end(),word.begin(), ::tolower);
					// if the word already present in map, value of that key is incremented 
					
					if(frequencyCount.find(word)!=frequencyCount.end()){
						frequencyCount.at(word)=frequencyCount.at(word)+1;
					}
					else{
						// if the word is not present in map, insert a element
						frequencyCount.insert(pair<string,int>(word,1));
					}
					
				}
			}

		}
	}
	invalid.close();
	input.close();
	return 1 ;
}

