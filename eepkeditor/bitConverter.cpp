#include "stdafx.h"
#include "bitConverter.h"

int bitConverter::toInt32(byte* bits)
{
	return bitConverter::toInt32(bits, 0);
}

short bitConverter::toInt16(byte* bits)
{
	return bitConverter::toInt16(bits, 0);
}

float bitConverter::toFloat32(byte* bits)
{
	return bitConverter::toFloat32(bits, 0);
}

std::string bitConverter::toString(byte *data, int length)
{
	return bitConverter::toString(data,0,length);
}

int bitConverter::toInt32(byte* bits, int pos)
{
	return (int)(bits[pos + 3] << 24 |
		bits[pos + 2] << 16 |
		bits[pos + 1] << 8 |
		bits[pos + 0]);
}

short bitConverter::toInt16(byte* bits, int pos)
{
	return (short)(bits[pos + 1] << 8 | bits[pos + 0]);
}

float bitConverter::toFloat32(byte* bits, int pos)
{
	return (float)((byte)bits[pos + 3] << 24 |
		(byte)bits[pos + 2] << 16 |
		(byte)bits[pos + 1] << 8 |
		(byte)bits[pos + 0]);
}

std::string bitConverter::toString(byte *bits, int pos, int length)
{
	std::string s;
	for (int i = 0; i < length; i++)
	{
		s.push_back(bits[pos + i]);
	};
	return s;
}
