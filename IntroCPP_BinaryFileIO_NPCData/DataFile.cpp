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

}

void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	Record* r = new Record;
	r->image = i;
	r->name = name;
	r->age = age;

	recordCount++;
}

// Changed to call the records indiviually when required instead of getting from a vector
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

// added recordIndexInt as an argument to call desired record
void DataFile::Load(string filename, int recordIndexInt)
{
	ifstream infile(filename, ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	// changed to use recordIndexInt instead of recordCount in for loop to use for obtaining the correct record
	for (int i = 0; i < recordIndexInt; i++)
	{
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;
		
		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));
		
		imageSize = sizeof(Color) * width * height;
		
		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));
		
		// if i equals the recordIndexInt - 1 it will load the all the data from the previous variables to produce the
		// display wanted for the records
		// else it will skip to the start of the next record using the image, name and age Size
		if (i == recordIndexInt - 1)
		{
			char* imgdata = new char[imageSize];
			infile.read(imgdata, imageSize);

			Image img = LoadImageEx((Color*)imgdata, width, height);
			char* name = new char[nameSize];
			int age = 0;

			infile.read((char*)name, nameSize);
			infile.read((char*)&age, ageSize);



			record.image = img;
			record.name = string(name, nameSize);
			record.age = age;


			delete[] imgdata;
			delete[] name;
		}
		else
		{
			infile.seekg(imageSize + nameSize + ageSize, ios::cur);
		}

		
		
	}

	infile.close();
}

