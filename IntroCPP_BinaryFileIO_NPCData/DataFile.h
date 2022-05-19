#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
public:
	struct Record {
		Image image;
		string name;
		int age;
	};
	
private:
	// removed records being saved in a vector to instead having the records only being loaded one at a time when required
	Record record;
	int recordCount;

public:
	DataFile();
	~DataFile();

	void AddRecord(string imageFilename, string name, int age);
	Record* GetRecord(int index);

	int GetRecordCount() { return recordCount; };

	void Load(string filename, int recordIndexInt);
};

