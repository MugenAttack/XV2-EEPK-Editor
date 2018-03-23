#include "stdafx.h"
#include "BinaryWriter.h"

void BinaryWriter::Write(fstream* file, byte val)
{
	file->write((char*)&val, sizeof(unsigned char));
}

void BinaryWriter::Write(fstream* file, byte* val, int length)
{
	file->write((char*)val, sizeof(unsigned char) * length);
}

void BinaryWriter::Write(fstream* file, char val)
{
	file->write((char*)&val, sizeof(char));
}

void BinaryWriter::Write(fstream* file, char* val, int length)
{
	file->write(val, sizeof(char) * length);
}

void BinaryWriter::Write(fstream*file, short val)
{
	file->write(reinterpret_cast<char*>(&val), sizeof(short));
}

void BinaryWriter::Write(fstream*file, int val)
{
	file->write(reinterpret_cast<char*>(&val), sizeof(int));
}

void BinaryWriter::Write(fstream*file, float val)
{
	file->write(reinterpret_cast<char*>(&val), sizeof(float));
}

void BinaryWriter::Write(fstream*file, unsigned short val)
{
	file->write(reinterpret_cast<char*>(&val), sizeof(unsigned short));
}

void BinaryWriter::Write(fstream*file, unsigned int val)
{
	file->write(reinterpret_cast<char*>(&val), sizeof(unsigned int));
}

void BinaryWriter::WriteASCII(fstream* file, std::string val)
{
	int length = val.size();
	for (int i = 0; i < length; i++)
	{
		BinaryWriter::Write(file, val[i]);
	}
	BinaryWriter::Write(file, '\0');
}

void BinaryWriter::WriteUnicodeA(fstream* file, std::string val)
{
	int length = val.size();
	for (int i = 0; i < length; i++)
	{
		BinaryWriter::Write(file, val[i]);
		BinaryWriter::Write(file, '\0');
	}
	BinaryWriter::Write(file, '\0');
	BinaryWriter::Write(file, '\0');
}

void BinaryWriter::WriteASCIIat(fstream *file, int address, std::string val)
{
	int rPos = file->tellp();
	file->seekp(address, ios::beg);
	BinaryWriter::WriteASCII(file, val);
	file->seekp(rPos, ios::beg);
}

int BinaryWriter::WriteASCIIEnd(fstream *file, std::string val)
{
	int rPos = file->tellp();
	file->seekp(0, ios::end);
	int pos = file->tellp();
	BinaryWriter::WriteASCII(file, val);
	file->seekp(rPos, ios::beg);
	return pos;
}

int BinaryWriter::getEndPos(fstream *file)
{
	int rPos = file->tellp();
	file->seekp(0, ios::end);
	int pos = file->tellp();
	file->seekp(0, ios::beg);
	return pos;
	
}
