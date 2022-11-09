#ifndef INPUTFILE_H
#define INPUTFILE_H
#include <vector>
#include <map>
#include <string>
#include <thread>
#include <set>

using namespace std;
class Tes{
	private:
		string file;
	public:
		Tes(){};
		~Tes(){};
		void setFile(string name);
		int readInputFile(string file);
		string getfile();
};
extern vector<thread> threads;
extern map<string,int> frequencyCount;
extern set<string> commonWords;
extern string filename;
extern int readInputFile(string file);

	
#endif

