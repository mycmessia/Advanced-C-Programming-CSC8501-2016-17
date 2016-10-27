#pragma once
#ifndef _COMPARE_FILE_
#define _COMPARE_FILE_

#include <string>

using namespace std;

class CompareFile {
public:
	CompareFile () {};
	~CompareFile () {};

	bool fexists (const string& filename);

	bool compare (const string& file1, const string& file2);
};

#endif