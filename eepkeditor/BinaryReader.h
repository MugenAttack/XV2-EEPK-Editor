#pragma once
#include <iostream>
#include <fstream>
#include "bitConverter.h"
using namespace std;
static class BinaryReader
{
public:
	static byte ReadByte(fstream*);
	static void ReadBytes(fstream*,byte*,int);
	static short ReadInt16(fstream*);
	static int ReadInt32(fstream*);
	static float ReadFloat(fstream*);
	static unsigned short ReadUInt16(fstream*);
	static unsigned int ReadUInt32(fstream*);
	static std::string ReadASCII(fstream*); //reads until it hits a 0
	//static std::string ReadUnicode(fstream*); //reads until it hits a 0;
	static std::string ReadASCIIat(fstream*, int address); 
	
};

