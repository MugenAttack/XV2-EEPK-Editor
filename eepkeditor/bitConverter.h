#pragma once
#include <string>
typedef unsigned char byte;
class bitConverter
{
public:
	static int toInt32(byte*);
	static short toInt16(byte*);
	static float toFloat32(byte*);
	static std::string toString(byte*, int);

	static int toInt32(byte*,int);
	static short toInt16(byte*,int);
	static float toFloat32(byte*,int);
	static std::string toString(byte*, int, int);

	static void getBytes(int, byte*);
	static void getBytes(short, byte*);
	static void getBytes(float, byte*);



};

