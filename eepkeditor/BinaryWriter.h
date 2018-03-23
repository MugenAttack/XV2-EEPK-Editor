#pragma once
#include <iostream>
#include <fstream>
#include "bitConverter.h"
using namespace std;
class BinaryWriter
{
public:
	static void Write(fstream*, byte);
	static void Write(fstream*, byte*, int);
	static void Write(fstream*, char);
	static void Write(fstream*, char*, int);
	static void Write(fstream*, short);
	static void Write(fstream*, int);
	static void Write(fstream*, float);
	static void Write(fstream*, unsigned short);
	static void Write(fstream*, unsigned int);
	static void WriteASCII(fstream*, std::string);
	static void WriteUnicodeA(fstream*, std::string);
	static void WriteASCIIat(fstream*, int , std::string);
	static int WriteASCIIEnd(fstream*, std::string);
	static int getEndPos(fstream*);
};

