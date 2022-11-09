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

vector<thread> threads;

int main(int argc, char* argv[]){
	common c1("data/commonword.txt");
	c1.getCommonWords();
	try{
		if(argc < 2 ){
			throw "exception" ;
		}
	}
	catch(...){
		cout << "Invalid Input : Input should be atleast two arguments" << endl ;
	}
	
	for(int i=1 ; i<argc ; i++ ){
		string filename(argv[i]);
		threads.emplace_back(readInputFile,filename);
	}
	for(auto& thr:threads){
		thr.join();
	}

	// unique words are printed with their frequencies

	map<string,int> :: iterator it;
	for(it=frequencyCount.begin();it!=frequencyCount.end();++it){
		cout << it->first << "," << it->second <<"\n" ;
	}
	return 0;
}
	


