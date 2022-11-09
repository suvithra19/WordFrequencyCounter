#ifndef INPUTFILE_H
#define INPUTFILE_H
#include <vector>
#include <map>
#include <string>
#include <thread>
#include <set>
#include <mutex>

using namespace std;

extern vector<thread> threads;
extern map<string,int> frequencyCount;
extern set<string> commonWords;
extern string filename;
extern int readInputFile(string filename);

	
#endif

