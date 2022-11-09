#ifndef COMMON_H
#define COMMON_H
#include <InputFile.h>

using namespace std;

class common{
	public:
		void getCommonWords();
		common();
		common(string file);
		~common();
	private:
		string file;
};

#endif
