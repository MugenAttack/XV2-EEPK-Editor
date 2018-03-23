#include "stdafx.h"
#include "EffectForm.h"
#include "nana\gui.hpp"
#include <nana/gui/wvl.hpp>
#include <nana/gui/place.hpp>

EffectForm::EffectForm(nana::window wd, nana::rectangle rect, eepk *_file) : nana::panel<false>(wd, rect)
{
	file = _file;
	lstUnk1.create(*this, nana::rectangle(25, 10, 121, 21));
	for (int i = 0; i < 5; i++)
	{
		lblUnk1[i].create(*this, nana::rectangle(20, 42 + (i * 26), 50, 17));
		lblUnk1[i].bgcolor(nana::color(240, 240, 240));
	}
	lstUnk1.events().selected([this]() { updateUnk1(); });
	lblUnk1[0].caption("Int_00");
	txtUnk1[0].events().key_release([this]() {file->unk1[lstUnk1.option()].Int_00 = atoi(txtUnk1[0].caption().c_str());});
	lblUnk1[1].caption("Int_04");
	txtUnk1[1].events().key_release([this]() {file->unk1[lstUnk1.option()].Int_04 = atoi(txtUnk1[1].caption().c_str());});
	lblUnk1[2].caption("Int_08");
	txtUnk1[2].events().key_release([this]() {file->unk1[lstUnk1.option()].Int_08 = atoi(txtUnk1[2].caption().c_str());});
	lblUnk1[3].caption("Int_0C");
	txtUnk1[3].events().key_release([this]() {file->unk1[lstUnk1.option()].Int_0C = atoi(txtUnk1[3].caption().c_str());});
	lblUnk1[4].caption("Set ID");
	txtUnk1[4].events().key_release([this]() {file->unk1[lstUnk1.option()].Int_10 = atoi(txtUnk1[4].caption().c_str());
	for (int i = 0; i < file->unk1[lstUnk1.option()].unk1_1.size(); i++)
		file->unk1[lstUnk1.option()].unk1_1[i].Byte_02 = file->unk1[lstUnk1.option()].Int_10;;
		
	});

	for (int i = 0; i < 5; i++)
	{
		txtUnk1[i].create(*this, nana::rectangle(90, 40 + (i * 26), 70, 21));
		txtUnk1[i].bgcolor(nana::color(255, 255, 255));
	}

	grpUnk1_1.create(*this, nana::rectangle(190, 10, 250, 208));
	grpUnk1_1.bgcolor(nana::color(240, 240, 240));
	lblgrp1.create(*this, nana::rectangle(210, 10, 80, 17));
	lblgrp1.caption("Effect Objects");
	lblgrp1.bgcolor(nana::color(240, 240, 240));
	lstUnk1_1.create(grpUnk1_1, nana::rectangle(15, 20, 70, 21));
	lstUnk1_1.events().selected([this]() {updateUnk1_1();});

	lblUnk1_100.create(grpUnk1_1, nana::rectangle(120, 22, 30, 17));
	lblUnk1_100.bgcolor(nana::color(240, 240, 240));
	lblUnk1_100.caption("ID");
	txtUnk1_100.create(grpUnk1_1, nana::rectangle(150, 20, 70, 21));
	txtUnk1_100.events().key_release([this]() {unk1_1->Short_00 = atoi(txtUnk1_100.caption().c_str());});
	lstFiles.create(grpUnk1_1, nana::rectangle(5, 50, 240, 150));
	lstFiles.append_header("Type", 70);
	lstFiles.append_header("Filename", 160);
	
	lstFiles.events().selected([this](const nana::arg_listbox& arg) {unk1_2 = arg.item.value<unk1_2_item>().index;});
	lstFiles.events().dbl_click([this]() {
		if (!editopen)
		{
			edit = new nana::form(*this);
			edit->caption("Change File");
			edit->bgcolor(nana::color(240, 240, 240));
			edit->size(nana::size(240, 90));
			lbledit.create(*edit, nana::rectangle(20, 22, 50, 17));
			lbledit.bgcolor(nana::color(240, 240, 240));
			lbledit.caption("File");
			txtedit.create(*edit, nana::rectangle(70, 20, 150, 21));
			txtedit.caption(unk1_1->unk1_2[unk1_2].String_00);
			btnedit.create(*edit, nana::rectangle(80, 55, 80, 20));
			btnedit.caption("Change");
			btnedit.events().click([this]() {
				editopen = false;
				unk1_1->unk1_2[unk1_2].String_00 = txtedit.caption();
				updateUnk1_1();
				edit->close();
			});
			edit->show();
			editopen = true;
		}
		edit->events().unload([this]() {editopen = false;});
	});



	for (int i = 0; i < 3; i++)
	{
		lblUnk1str[i].create(*this, nana::rectangle(20, 232 + (i * 26), 70, 17));
		lblUnk1str[i].bgcolor(nana::color(240, 240, 240));
	}

	lblUnk1str[0].caption("Bind emb"); //24
	lblUnk1str[1].caption("Particle emm"); //28
	lblUnk1str[2].caption("Particle emb"); //2C


	for (int i = 0; i < 3; i++)
	{
		txtUnk1str[i].create(*this, nana::rectangle(110, 230 + (i * 26), 170, 21));
		txtUnk1str[i].bgcolor(nana::color(255, 255, 255));
	}

	txtUnk1str[0].events().key_release([this]() {file->unk1[lstUnk1.option()].String_24 = txtUnk1str[0].caption();});
	txtUnk1str[1].events().key_release([this]() {file->unk1[lstUnk1.option()].String_28 = txtUnk1str[1].caption();});
	txtUnk1str[2].events().key_release([this]() {file->unk1[lstUnk1.option()].String_2C = txtUnk1str[2].caption();});
	
}


EffectForm::~EffectForm()
{
}

void EffectForm::updateUnk1()
{
	txtUnk1[0].caption(to_string(file->unk1[lstUnk1.option()].Int_00));
	txtUnk1[1].caption(to_string(file->unk1[lstUnk1.option()].Int_04));
	txtUnk1[2].caption(to_string(file->unk1[lstUnk1.option()].Int_08));
	txtUnk1[3].caption(to_string(file->unk1[lstUnk1.option()].Int_0C));
	txtUnk1[4].caption(to_string(file->unk1[lstUnk1.option()].Int_10));

	txtUnk1str[0].caption(file->unk1[lstUnk1.option()].String_24);
	txtUnk1str[1].caption(file->unk1[lstUnk1.option()].String_28);
	txtUnk1str[2].caption(file->unk1[lstUnk1.option()].String_2C);

	//lstUnk1_2.clear();
	lstUnk1_1.clear();
	for (int i = 0; i < file->unk1[lstUnk1.option()].unk1_1.size(); i++)
		lstUnk1_1.push_back(to_string(file->unk1[lstUnk1.option()].unk1_1[i].Short_00));

}

nana::listbox::oresolver& operator<<(nana::listbox::oresolver& ores, const unk1_2_item item)
{
	return ores << item.item->Byte_00 << item.item->String_00;
}

void EffectForm::updateUnk1_1()
{
	unk1_1 = &file->unk1[lstUnk1.option()].unk1_1[lstUnk1_1.option()];
	txtUnk1_100.caption(to_string(unk1_1->Short_00));

	lstFiles.clear();
	items.clear();
	for (int i = 0; i < unk1_1->unk1_2.size(); i++)
	{
		unk1_2_item n;
		n.index = i;
		n.item = &unk1_1->unk1_2[i];
		items.push_back(n);
		lstFiles.at(0).append(items[i], true);
	}
	
}


