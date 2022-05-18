#include "DataFile.h"
#include <fstream>
using namespace std;

#include <iostream>

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	//Clear();
}

void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	Record* r = new Record;
	r->image = i;
	r->name = name;
	r->age = age;

	//record.push_back(r);
	recordCount++;
}

DataFile::Record* DataFile::GetRecord(int index)
{
	return &record;
}

Image LoadImageEx(Color* pixels, int width, int height)
{
	Image image = { 0 };
	unsigned char* fileData = (unsigned char*)pixels;
	unsigned char* dataPtr = fileData;
	unsigned int size = GetPixelDataSize(width, height, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
	image.data = RL_MALLOC(size);      // Allocate required memory in bytes
	if (image.data)
	{
		memcpy(image.data, dataPtr, size); // Copy required data to image
		image.width = width;
		image.height = height;
		image.mipmaps = 1;
		image.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
	}
	return image;
}

Color* GetImageData(Image image)
{
	return (Color*)image.data;
}

//void DataFile::Save(string filename)
//{
//	ofstream outfile(filename, ios::binary);
//
//	int recordCount = records.size();
//	outfile.write((char*)&recordCount, sizeof(int));
//
//	for (int i = 0; i < recordCount; i++)
//	{		
//		Color* imgdata = GetImageData(records[i]->image);
//				
//		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
//		int nameSize = records[i]->name.length();
//		int ageSize = sizeof(int);
//
//		outfile.write((char*)&records[i]->image.width, sizeof(int));
//		outfile.write((char*)&records[i]->image.height, sizeof(int));
//		
//		outfile.write((char*)&nameSize, sizeof(int));
//		outfile.write((char*)&ageSize, sizeof(int));
//
//		outfile.write((char*)imgdata, imageSize);
//		outfile.write((char*)records[i]->name.c_str(), nameSize);
//		outfile.write((char*)&records[i]->age, ageSize);
//	}
//
//	outfile.close();
//}

void DataFile::Load(string filename, int recordIndexInt)
{
	//Clear();

	ifstream infile(filename, ios::binary);

	//int jumpInt = 0;

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	//std::cout << recordIndexInt << std::endl;


	bool alreadyran = false;

	for (int i = 0; i < recordIndexInt; i++)
	{
		//std::cout << infile.tellg() << std::endl;
		
		//if (!alreadyran)
		//{


		//	if (recordIndexInt == 1)
		//	{
		//		alreadyran = true;
		//		std::cout << "1" << std::endl;
		//		infile.seekg(4, ios::beg);
		//		//std::cout << infile.tellg() << std::endl;
		//	}
		//	if (recordIndexInt == 2)
		//	{
		//		alreadyran = true;
		//		std::cout << "2" << std::endl;
		//		infile.seekg(4, ios::beg);
		//		//std::cout << infile.tellg() << std::endl;
		//	}
		//	if (recordIndexInt == 3)
		//	{
		//		alreadyran = true;
		//		std::cout << "3" << std::endl;
		//		infile.seekg(4, ios::beg);
		//		//std::cout << infile.tellg() << std::endl;
		//	}
		//	if (recordIndexInt == 4)
		//	{
		//		alreadyran = true;
		//		std::cout << "4" << std::endl;
		//		infile.seekg(4, ios::beg);
		//		//std::cout << infile.tellg() << std::endl;
		//	}
		//	if (recordIndexInt == 5)
		//	{
		//		alreadyran = true;
		//		std::cout << "5" << std::endl;
		//		infile.seekg(4, ios::beg);
		//		//std::cout << infile.tellg() << std::endl;
		//	}
		//}

		std::cout << infile.tellg() << std::endl;

		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;
		
		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));
		
		imageSize = sizeof(Color) * width * height;
		
		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));
		
		char* imgdata = new char[imageSize];
		infile.read(imgdata, imageSize);
		
		Image img = LoadImageEx((Color*)imgdata, width, height);
		char* name = new char[nameSize];
		int age = 0;
		
		infile.read((char*)name, nameSize);
		infile.read((char*)&age, ageSize);
		
		//std::cout << name << std::endl;
		
		record.image = img;
		record.name = string(name, nameSize);
		record.age = age;
		//std::cout << record.name << std::endl;
		
		//record.name
		
		//record.push_back(r);
		
		delete[] imgdata;
		delete[] name;
		
	}

	infile.close();
}

//void DataFile::Clear()
//{
//	for (int i = 0; i < record.size(); i++)
//	{
//		delete record[i];
//	}
//	record.clear();
//	recordCount = 0;
//}

