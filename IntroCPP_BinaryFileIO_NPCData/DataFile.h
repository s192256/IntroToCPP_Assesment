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
	
	//std::vector<Record*> records;	// delete this vector. Load only the required record 
	Record record;
	int recordCount;
	


public:
	DataFile();
	~DataFile();



	void AddRecord(string imageFilename, string name, int age);
	Record* GetRecord(int index);

	int GetRecordCount() { return recordCount; };

	//void Save(string filename);
	void Load(string filename, int recordIndexInt);

private:
	//void Clear();

};

