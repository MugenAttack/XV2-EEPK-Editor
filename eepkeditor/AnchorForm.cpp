#include "stdafx.h"
#include "AnchorForm.h"


AnchorForm::AnchorForm(nana::window wd, nana::rectangle rect, eepk* _file) : nana::panel<false>(wd, rect)
{
	file = _file;
	lstUnk2.create(*this, nana::rectangle(25, 10, 121, 21));
	lstUnk2.events().selected([this]() {updateUnk2();});
	lblInt00.create(*this, nana::rectangle(170, 12, 62, 17));
	lblInt00.caption("Int_00");
	lblInt00.bgcolor(nana::color(240, 240, 240));
	txtInt00.create(*this, nana::rectangle(220, 10, 70, 21));
	chkEmpty.create(*this, nana::rectangle(320, 10, 80, 17));
	chkEmpty.caption("is Empty");
	chkEmpty.bgcolor(nana::color(240, 240, 240));
	grpUnk1_1.create(*this, nana::rectangle(-5, 40, 460, 300));
	grpUnk1_1.bgcolor(nana::color(240, 240, 240));
	grblbl1.create(*this, nana::rectangle(30, 40, 40, 17));
	grblbl1.caption("Layers");
	grblbl1.bgcolor(nana::color(240, 240, 240));

	cbUnk2_1.create(grpUnk1_1, nana::rectangle(30, 20, 100, 21));
	cbUnk2_1.events().selected([this]() {updateUnk2_1();});
	lblBone.create(grpUnk1_1, nana::rectangle(180, 22, 50, 21));
	lblBone.caption("Bone");
	lblBone.bgcolor(nana::color(240, 240, 240));
	txtBone.create(grpUnk1_1, nana::rectangle(230, 20, 120, 21));
	txtBone.events().key_release([this]() {unk2_1->String_60 = txtBone.caption();});
	
	//set 1
	for (int i = 0; i < 9; i++)
	{
		lblset1[i].create(grpUnk1_1, nana::rectangle(20, 52 + (i * 26), 50, 17));
		lblset1[i].bgcolor(nana::color(240, 240, 240));
	}

	lblset1[0].caption("Effect ID");
	lblset1[1].caption("Short_02");
	lblset1[2].caption("Short_04");
	lblset1[3].caption("Short_06");
	lblset1[4].caption("Float_18");
	lblset1[5].caption("Short_1C");
	lblset1[6].caption("Short_1E");
	lblset1[7].caption("Int_20");
	lblset1[8].caption("Short_24");


	for (int i = 0; i < 9; i++)
	{
		txtset1[i].create(grpUnk1_1, nana::rectangle(85, 50 + (i * 26), 60, 21));
		txtset1[i].bgcolor(nana::color(255, 255, 255));
	}

	txtset1[0].events().key_release([this]() {unk2_1->Short_00 = atoi(txtset1[0].caption().c_str());});
	txtset1[1].events().key_release([this]() {unk2_1->Short_02 = atoi(txtset1[1].caption().c_str());});
	txtset1[2].events().key_release([this]() {unk2_1->Short_04 = atoi(txtset1[2].caption().c_str());});
	txtset1[3].events().key_release([this]() {unk2_1->Short_06 = atoi(txtset1[3].caption().c_str());});
	txtset1[4].events().key_release([this]() {unk2_1->Float_18 = atof(txtset1[4].caption().c_str());});
	txtset1[5].events().key_release([this]() {unk2_1->Short_1C = atoi(txtset1[5].caption().c_str());});
	txtset1[6].events().key_release([this]() {unk2_1->Short_1E = atoi(txtset1[6].caption().c_str());});
	txtset1[7].events().key_release([this]() {unk2_1->Int_20 = atoi(txtset1[7].caption().c_str());});
	txtset1[8].events().key_release([this]() {unk2_1->Short_24 = atoi(txtset1[8].caption().c_str());});
	//set 2
	for (int i = 0; i < 9; i++)
	{
		lblset2[i].create(grpUnk1_1, nana::rectangle(168, 52 + (i * 26), 50, 17));
		lblset2[i].bgcolor(nana::color(240, 240, 240));
	}

	lblset2[0].caption("Short_26");
	lblset2[1].caption("Pos X");
	lblset2[2].caption("Pos Y");
	lblset2[3].caption("Pos Z");
	lblset2[4].caption("Float_34");
	lblset2[5].caption("Float_38");
	lblset2[6].caption("Float_3C");
	lblset2[7].caption("Float_40");
	lblset2[8].caption("Float_44");
	lblset2[9].caption("Float_48");

	for (int i = 0; i < 9; i++)
	{
		txtset2[i].create(grpUnk1_1, nana::rectangle(233, 50 + (i * 26), 60, 21));
		txtset2[i].bgcolor(nana::color(255, 255, 255));
	}
	
	txtset2[0].events().key_release([this]() {unk2_1->Short_26 = atoi(txtset2[0].caption().c_str());});
	txtset2[1].events().key_release([this]() {unk2_1->Float_28 = atof(txtset2[1].caption().c_str());});
	txtset2[2].events().key_release([this]() {unk2_1->Float_2C = atof(txtset2[2].caption().c_str());});
	txtset2[3].events().key_release([this]() {unk2_1->Float_30 = atof(txtset2[3].caption().c_str());});
	txtset2[4].events().key_release([this]() {unk2_1->Float_34 = atof(txtset2[4].caption().c_str());});
	txtset2[5].events().key_release([this]() {unk2_1->Float_38 = atof(txtset2[5].caption().c_str());});
	txtset2[6].events().key_release([this]() {unk2_1->Float_40 = atof(txtset2[6].caption().c_str());});
	txtset2[7].events().key_release([this]() {unk2_1->Float_44 = atof(txtset2[7].caption().c_str());});
	txtset2[8].events().key_release([this]() {unk2_1->Float_48 = atof(txtset2[8].caption().c_str());});

	//set 3
	for (int i = 0; i < 9; i++)
	{
		lblset3[i].create(grpUnk1_1, nana::rectangle(315, 52 + (i * 26), 50, 17));
		lblset3[i].bgcolor(nana::color(240, 240, 240));
	}

	lblset3[0].caption("Float_4C");
	lblset3[1].caption("Scale X");
	lblset3[2].caption("Scale Y");
	lblset3[3].caption("Scale Z");
	lblset3[4].caption("Short_5C");
	lblset3[5].caption("Short_5E");

	for (int i = 0; i < 6; i++)
	{
		txtset3[i].create(grpUnk1_1, nana::rectangle(380, 50 + (i * 26), 60, 21));
		txtset3[i].bgcolor(nana::color(255, 255, 255));
	}

	txtset3[0].events().key_release([this]() {unk2_1->Float_4C = atof(txtset3[0].caption().c_str());});
	txtset3[1].events().key_release([this]() {unk2_1->Float_50 = atof(txtset3[1].caption().c_str());});
	txtset3[2].events().key_release([this]() {unk2_1->Float_54 = atof(txtset3[2].caption().c_str());});
	txtset3[3].events().key_release([this]() {unk2_1->Float_58 = atof(txtset3[3].caption().c_str());});
	txtset3[4].events().key_release([this]() {unk2_1->Short_5C = atoi(txtset3[4].caption().c_str());});
	txtset3[5].events().key_release([this]() {unk2_1->Short_5E = atoi(txtset3[5].caption().c_str());});

}


AnchorForm::~AnchorForm()
{
}

void AnchorForm::updateUnk2()
{
	unk2 = &file->unk2[lstUnk2.option()];
	chkEmpty.check(unk2->isEmpty);
	if (!unk2->isEmpty)
	{
		grpUnk1_1.show();
		grblbl1.show();
		txtInt00.show();
		lblInt00.show();
		txtInt00.caption(std::to_string(unk2->Int_00));
		cbUnk2_1.clear();
		for (int i = 0; i < unk2->unk2_1.size(); i++)
			cbUnk2_1.push_back(to_string(i));

	}
	else
	{
		grpUnk1_1.hide();
		grblbl1.hide();
		txtInt00.hide();
		lblInt00.hide();
	}
}

void AnchorForm::updateUnk2_1()
{
	unk2_1 = &unk2->unk2_1[cbUnk2_1.option()];
	txtset1[0].caption(to_string(unk2_1->Short_00));
	txtset1[1].caption(to_string(unk2_1->Short_02));
	txtset1[2].caption(to_string(unk2_1->Short_04));
	txtset1[3].caption(to_string(unk2_1->Short_06));
	txtset1[4].caption(to_string(unk2_1->Float_18));
	txtset1[5].caption(to_string(unk2_1->Short_1C));
	txtset1[6].caption(to_string(unk2_1->Short_1E));
	txtset1[7].caption(to_string(unk2_1->Int_20));
	txtset1[8].caption(to_string(unk2_1->Short_24));
	
	txtset2[0].caption(to_string(unk2_1->Short_26));
	txtset2[1].caption(to_string(unk2_1->Float_28));
	txtset2[2].caption(to_string(unk2_1->Float_2C));
	txtset2[3].caption(to_string(unk2_1->Float_30));
	txtset2[4].caption(to_string(unk2_1->Float_34));
	txtset2[5].caption(to_string(unk2_1->Float_38));
	txtset2[6].caption(to_string(unk2_1->Float_3C));
	txtset2[7].caption(to_string(unk2_1->Float_40));
	txtset2[8].caption(to_string(unk2_1->Float_44));

	txtset3[0].caption(to_string(unk2_1->Float_48));
	txtset3[1].caption(to_string(unk2_1->Float_4C));
	txtset3[2].caption(to_string(unk2_1->Float_50));
	txtset3[3].caption(to_string(unk2_1->Float_54));
	txtset3[4].caption(to_string(unk2_1->Short_5C));
	txtset3[5].caption(to_string(unk2_1->Short_5E));

	txtBone.caption(unk2_1->String_60);
}
