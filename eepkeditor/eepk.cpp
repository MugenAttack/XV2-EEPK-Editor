#include "stdafx.h"
#include "eepk.h"
#include "BinaryReader.h"
#include "BinaryWriter.h"


eepk::eepk()
{
}


eepk::~eepk()
{
}

void eepk::read(string filename)
{
	delete[] unk1;
	delete[] unk2;
	fstream file;
	file.open(filename, ios::binary | ios::in);
	file.seekg(8, ios::beg);
	unk0 = BinaryReader::ReadInt32(&file);
	unk1Count = BinaryReader::ReadInt16(&file);
	unk2Count = BinaryReader::ReadInt16(&file);
	int unk1Address = BinaryReader::ReadInt32(&file);
	int unk2Address = BinaryReader::ReadInt32(&file);

	unk1 = new EEPK_unk1[unk1Count];
	for (int i = 0; i < unk1Count; i++)
	{
		file.seekg(unk1Address + (i * 48), ios::beg);
		unk1[i].Int_00 = BinaryReader::ReadInt32(&file);
		unk1[i].Int_04 = BinaryReader::ReadInt32(&file);
		unk1[i].Int_08 = BinaryReader::ReadInt32(&file);
		unk1[i].Int_0C = BinaryReader::ReadInt32(&file);
		unk1[i].Int_10 = BinaryReader::ReadInt32(&file);
		file.seekg(10, ios::cur);
		int count1 = BinaryReader::ReadInt16(&file);
		int address = BinaryReader::ReadInt32(&file) + unk1Address + (i * 48);
		int address2 = BinaryReader::ReadInt32(&file);
		if (address2 != 0)
		{
			unk1[i].String_24 = BinaryReader::ReadASCIIat(&file, unk1Address + (i * 48) + address2);
			cout << unk1[i].String_24 << endl;
		}
		address2 = BinaryReader::ReadInt32(&file);
		if (address2 != 0)
		{
			unk1[i].String_28 = BinaryReader::ReadASCIIat(&file, unk1Address + (i * 48) + address2);
			cout << unk1[i].String_28 << endl;
		}

		address2 = BinaryReader::ReadInt32(&file);
		if (address2 != 0)
		{
			unk1[i].String_2C = BinaryReader::ReadASCIIat(&file, unk1Address + (i * 48) + address2);
			cout << unk1[i].String_2C << endl;
		}

		for (int j = 0; j < count1; j++)
		{
			EEPK_unk1_1 unk1_1;
			file.seekg(address + (j * 12),ios::beg);
			unk1_1.Short_00 = BinaryReader::ReadInt16(&file);
			unk1_1.Byte_02 = BinaryReader::ReadByte(&file);
			int count2 = BinaryReader::ReadByte(&file);
			int unk1_2Address1 = BinaryReader::ReadInt32(&file) + address + (j * 12);
			int unk1_2Address2 = BinaryReader::ReadInt32(&file) + address + (j * 12);
			for (int k = 0; k < count2; k++)
			{
				EEPK_unk1_2 unk1_2;
				unk1_1.unk1_2.push_back(unk1_2);
			}

			file.seekg(unk1_2Address1, ios::beg);
			for (int k = 0; k < count2; k++)
			{
				unk1_1.unk1_2[k].Byte_00 = BinaryReader::ReadByte(&file);
			}

			file.seekg(unk1_2Address2, ios::beg);
			for (int k = 0; k < count2; k++)
			{
				int a = BinaryReader::ReadInt32(&file);
				unk1_1.unk1_2[k].String_00 = BinaryReader::ReadASCIIat(&file, address + (j * 12) + a);
				cout << unk1_1.unk1_2[k].String_00 << endl;
			}

			unk1[i].unk1_1.push_back(unk1_1);
		}

	}

	unk2 = new EEPK_unk2[unk2Count];
	for (int i = 0; i < unk2Count; i++)
	{
		file.seekg(unk2Address + (i * 4), ios::beg);
		int address = BinaryReader::ReadInt32(&file);
		if (address != 0)
		{
			unk2[i].isEmpty = false;
			file.seekg(address, ios::beg);
			unk2[i].Int_00 = BinaryReader::ReadInt32(&file);
			file.seekg(6, ios::cur);
			int count = BinaryReader::ReadInt16(&file);
			int address2 = BinaryReader::ReadInt32(&file);
			file.seekg(address + address2, ios::beg);
			for (int j = 0; j < count; j++)
			{
				EEPK_unk2_1 unk2_1;
				unk2_1.Short_00 = BinaryReader::ReadInt16(&file);
				unk2_1.Short_02 = BinaryReader::ReadInt16(&file);
				unk2_1.Short_04 = BinaryReader::ReadInt16(&file);
				unk2_1.Short_06 = BinaryReader::ReadInt16(&file);
				file.seekg(16, ios::cur);
				unk2_1.Float_18 = BinaryReader::ReadFloat(&file);
				unk2_1.Short_1C = BinaryReader::ReadInt16(&file);
				unk2_1.Short_1E = BinaryReader::ReadInt16(&file);
				unk2_1.Int_20 = BinaryReader::ReadInt32(&file);
				unk2_1.Short_24 = BinaryReader::ReadInt16(&file);
				unk2_1.Short_26 = BinaryReader::ReadInt16(&file);

				unk2_1.Float_28 = BinaryReader::ReadFloat(&file);
				unk2_1.Float_2C = BinaryReader::ReadFloat(&file);
				unk2_1.Float_30 = BinaryReader::ReadFloat(&file);
				unk2_1.Float_34 = BinaryReader::ReadFloat(&file);
				cout << unk2_1.Float_28 << endl;
				unk2_1.Float_38 = BinaryReader::ReadFloat(&file);
				unk2_1.Float_3C = BinaryReader::ReadFloat(&file);
				unk2_1.Float_40 = BinaryReader::ReadFloat(&file);
				unk2_1.Float_44 = BinaryReader::ReadFloat(&file);

				unk2_1.Float_48 = BinaryReader::ReadFloat(&file);
				unk2_1.Float_4C = BinaryReader::ReadFloat(&file);
				unk2_1.Float_50 = BinaryReader::ReadFloat(&file);
				unk2_1.Float_54 = BinaryReader::ReadFloat(&file);

				unk2_1.Float_58 = BinaryReader::ReadFloat(&file);
				unk2_1.Short_5C = BinaryReader::ReadInt16(&file);
				unk2_1.Short_5E = BinaryReader::ReadInt16(&file);
				int address3 = BinaryReader::ReadInt32(&file);
				if (address3 != 0)
				{
					unk2_1.String_60 = BinaryReader::ReadASCIIat(&file, address + address2 + (100 * j) + address3);
					cout << unk2_1.String_60 << endl;
				}
				else
					unk2_1.String_60 = "";

				unk2[i].unk2_1.push_back(unk2_1);
			}

		}
		else
		{
			unk2[i].isEmpty = true;
		}


	}
	file.close();
}

void eepk::write(string filename)
{

	//calculate start positions
	int unk1Start = 24 + unk2Count * 4;
	int unk1_1Start = unk1Start + (unk1Count * 48);
	int unk1_1AddressStart = unk1_1Start;
	for (int i = 0; i < unk1Count; i++)
		unk1_1AddressStart += unk1[i].unk1_1.size() * 12;
	int unk2Start = unk1_1AddressStart;
	for (int i = 0; i < unk1Count; i++)
	{
		for (int j = 0; j < unk1[i].unk1_1.size(); j++)
			unk2Start += unk1[i].unk1_1[j].unk1_2.size() * 4;
	}

	int unk2_1Start = unk2Start;
	for (int i = 0; i < unk2Count; i++)
	{
		if (!unk2[i].isEmpty)
			unk2_1Start += 16;
	}
	int textStart = unk2_1Start;
	for (int i = 0; i < unk2Count; i++)
	{
		if (!unk2[i].isEmpty)
			textStart += unk2[i].unk2_1.size() * 100;
	}

	int currentUnk1 = unk1Start;
	int currentUnk1_1 = unk1_1Start;
	int currentAddress = unk1_1AddressStart;
	int currentUnk2 = unk2Start;
	int currentUnk2_1 = unk2_1Start;
	int currentText = textStart;
	cout << currentUnk1 << endl;
	cout << currentUnk1_1 << endl;
	cout << currentText << endl;
	fstream file;
	file.open(filename, ios::out | ios::binary | ios::trunc);
	BinaryWriter::Write(&file, new byte[8]{ 0x23,0x45,0x50,0x4B,0xFE,0xFF,0x18,0x00 }, 8);
	BinaryWriter::Write(&file, unk0);
	BinaryWriter::Write(&file, (short)unk1Count);
	BinaryWriter::Write(&file, (short)unk2Count);
	BinaryWriter::Write(&file, unk1Start);
	BinaryWriter::Write(&file, 24);
	
	for (int i = 0; i < unk1Count; i++)
	{
		file.seekp(unk1Start + (i * 48), ios::beg);
		int pos = file.tellp();
		BinaryWriter::Write(&file,unk1[i].Int_00);
		BinaryWriter::Write(&file,unk1[i].Int_04);
		BinaryWriter::Write(&file,unk1[i].Int_08);
		BinaryWriter::Write(&file,unk1[i].Int_0C);
		BinaryWriter::Write(&file,unk1[i].Int_10);
		file.seekp(10, ios::cur);
		BinaryWriter::Write(&file, (short)unk1[i].unk1_1.size());
		BinaryWriter::Write(&file, currentUnk1_1 - currentUnk1);

		if (unk1[i].String_24.length() > 0)
		{
			BinaryWriter::Write(&file, currentText - currentUnk1);
			BinaryWriter::WriteASCIIat(&file, currentText, unk1[i].String_24);
			currentText += unk1[i].String_24.length() + 1;
		}
		if (unk1[i].String_28.length() > 0)
		{
			BinaryWriter::Write(&file, currentText - currentUnk1);
			BinaryWriter::WriteASCIIat(&file, currentText, unk1[i].String_28);
			currentText += unk1[i].String_28.length() + 1;
		}
		if (unk1[i].String_2C.length() > 0)
		{
			BinaryWriter::Write(&file, currentText - currentUnk1);
			BinaryWriter::WriteASCIIat(&file, currentText, unk1[i].String_2C);
			currentText += unk1[i].String_2C.length() + 1;
		}

		for (int j = 0; j < unk1[i].unk1_1.size(); j++)
		{
			file.seekp(currentUnk1_1, ios::beg);
			EEPK_unk1_1 unk1_1 = unk1[i].unk1_1[j];
			BinaryWriter::Write(&file, unk1_1.Short_00);
			BinaryWriter::Write(&file, unk1_1.Byte_02);
			BinaryWriter::Write(&file, (byte)unk1_1.unk1_2.size());
			BinaryWriter::Write(&file, currentText - currentUnk1_1);
			BinaryWriter::Write(&file, currentAddress - currentUnk1_1);
			file.seekp(currentText,ios::beg);
			for (int k = 0; k < unk1_1.unk1_2.size(); k++)
				BinaryWriter::Write(&file, unk1_1.unk1_2[k].Byte_00);

			currentText += unk1_1.unk1_2.size();
			file.seekp(currentAddress, ios::beg);
			for (int k = 0; k < unk1_1.unk1_2.size(); k++)
			{
				BinaryWriter::Write(&file, currentText - currentUnk1_1);
				BinaryWriter::WriteASCIIat(&file, currentText, unk1_1.unk1_2[k].String_00);
				currentText += unk1_1.unk1_2[k].String_00.length() + 1;
				currentAddress += 4;
			}
			currentUnk1_1 += 12;
		}

		currentUnk1 += 48;
	}

	for (int i = 0; i < unk2Count; i++)
	{
		if (!unk2[i].isEmpty)
		{
			file.seekp(24 + (i * 4), ios::beg);
			BinaryWriter::Write(&file, currentUnk2);
			file.seekp(currentUnk2, ios::beg);
			BinaryWriter::Write(&file, unk2[i].Int_00);
			file.seekp(6, ios::cur);
			BinaryWriter::Write(&file, (short)unk2[i].unk2_1.size());
			BinaryWriter::Write(&file, currentUnk2_1 - currentUnk2);
			currentUnk2 += 16;

			        for (int j = 0; j < unk2[i].unk2_1.size(); j++)
			        {
			            file.seekp(currentUnk2_1, ios::beg);
						EEPK_unk2_1 unk2_1 = unk2[i].unk2_1[j];
			            BinaryWriter::Write(&file,unk2_1.Short_00);
			            BinaryWriter::Write(&file,unk2_1.Short_02);
			            BinaryWriter::Write(&file,unk2_1.Short_04);
			            BinaryWriter::Write(&file,unk2_1.Short_06);
						file.seekp(16, ios::cur);
						BinaryWriter::Write(&file, unk2_1.Float_18);
						BinaryWriter::Write(&file,unk2_1.Short_1C);
			            BinaryWriter::Write(&file,unk2_1.Short_1E);
			            BinaryWriter::Write(&file,unk2_1.Int_20);
			            BinaryWriter::Write(&file,unk2_1.Short_24);
			            BinaryWriter::Write(&file,unk2_1.Short_26);

			            BinaryWriter::Write(&file,unk2_1.Float_28);
			            BinaryWriter::Write(&file,unk2_1.Float_2C);
			            BinaryWriter::Write(&file,unk2_1.Float_30);
			            BinaryWriter::Write(&file,unk2_1.Float_34);

			            BinaryWriter::Write(&file,unk2_1.Float_38);
			            BinaryWriter::Write(&file,unk2_1.Float_3C);
			            BinaryWriter::Write(&file,unk2_1.Float_40);
			            BinaryWriter::Write(&file,unk2_1.Float_44);

			            BinaryWriter::Write(&file,unk2_1.Float_48);
			            BinaryWriter::Write(&file,unk2_1.Float_4C);
			            BinaryWriter::Write(&file,unk2_1.Float_50);
			            BinaryWriter::Write(&file,unk2_1.Float_54);

			            BinaryWriter::Write(&file,unk2_1.Float_58);
			            BinaryWriter::Write(&file,unk2_1.Short_5C);
			            BinaryWriter::Write(&file,unk2_1.Short_5E);
			            
						if (unk2_1.String_60 != "")
						{
							BinaryWriter::Write(&file, currentText - currentUnk2_1);
							BinaryWriter::WriteASCIIat(&file, currentText, unk2_1.String_60);
							currentText += unk2_1.String_60.length() + 1;
						}

			            currentUnk2_1 += 100;
			        }

		}
	}

	file.close();
}