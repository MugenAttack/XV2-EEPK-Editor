#pragma once
#include <string>
#include <vector>
#include "bitConverter.h"
using namespace std;

struct EEPK_unk1_2
{
	byte Byte_00;
	string String_00;
};

struct EEPK_unk1_1
{
	short Short_00;
	byte Byte_02;
	vector<EEPK_unk1_2> unk1_2;
};

struct EEPK_unk1
{
	int Int_00;
	int Int_04;
	int Int_08;
	int Int_0C;
	int Int_10;
	vector<EEPK_unk1_1> unk1_1;
	string String_24;
	string String_28;
	string String_2C;
};

struct EEPK_unk2_1
{
	short Short_00;
	short Short_02;
	short Short_04;
	short Short_06;
	//16 bytes
	float Float_18;
	short Short_1C;
	short Short_1E;
	int Int_20;

	short Short_24;
	short Short_26;

	float Float_28;
	float Float_2C;
	float Float_30;
	float Float_34;

	float Float_38;
	float Float_3C;
	float Float_40;
	float Float_44;

	float Float_48;
	float Float_4C;
	float Float_50;
	float Float_54;

	float Float_58;
	short Short_5C;
	short Short_5E;

	string String_60;
};

struct EEPK_unk2
{
	bool isEmpty;
	int Int_00;
	vector<EEPK_unk2_1> unk2_1;
};

class eepk
{
public:
	eepk();
	~eepk();
	int unk0;
	EEPK_unk1* unk1;
	int unk1Count;
	EEPK_unk2* unk2;
	int unk2Count;
	void read(string);
	void write(string);

};

