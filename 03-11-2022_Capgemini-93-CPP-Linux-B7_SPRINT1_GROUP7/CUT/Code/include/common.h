#ifndef COMMON_H
#define COMMON_H
#include <InputFile.h>

using namespace std;

class Common{
	public:
		Common();
		Common(string file);
		~Common();
		void getCommonWords();
	private:
		string file;
};

#endif
