#include "stdafx.h"
#include "BinaryReader.h"




byte BinaryReader::ReadByte(fstream* file)
{
	char b;
	file->read(&b, sizeof(char));
	return (byte)b;
}

short BinaryReader::ReadInt16(fstream* file)
{
	short i;
	file->read((char*)&i, sizeof(short));
	return i;
}

int BinaryReader::ReadInt32(fstream* file)
{
	int i;
	file->read((char*)&i, sizeof(int));
	return i;
}

float BinaryReader::ReadFloat(fstream* file)
{
	float i;
	file->read((char*)&i, sizeof(float));
	return i;
}

unsigned short BinaryReader::ReadUInt16(fstream* file)
{
	char s[sizeof(unsigned short)];
	file->read(s, sizeof(unsigned short));
	return (unsigned short)((byte)s[1] << 8 | (byte)s[0]);
}

unsigned int BinaryReader::ReadUInt32(fstream* file)
{
	char i[sizeof(unsigned int)];
	file->read(i, sizeof(unsigned int));
	return (unsigned int)((byte)i[3] << 24 |
		(byte)i[2] << 16 |
		(byte)i[1] << 8 |
		(byte)i[0]);
}

std::string BinaryReader::ReadASCII(fstream* file)
{
	char c;
	std::string s = "";
	file->get(c);
	while (c != '\0')
	{
		s.push_back(c);
		file->get(c);
	};
	return s;
}

std::string BinaryReader::ReadASCIIat(fstream *file, int address)
{
	int r = file->tellg();
	file->seekg(address);
	std::string s = BinaryReader::ReadASCII(file);
	file->seekg(r);
	return s;
}



void BinaryReader::ReadBytes(fstream* file, byte* bits, int length)
{
	bits = new byte[length];
	for (int i = 0; i < length; i++)
	{
		bits[i] = BinaryReader::ReadByte(file);
	}
}