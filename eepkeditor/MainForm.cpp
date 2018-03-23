#include "stdafx.h"
#include "MainForm.h"
#include "nana\gui\filebox.hpp"

MainForm::MainForm()
{
	MainBar.create(*this);
	MainBar.push_back("File");
	MainBar.at(0).append("Open", [this](nana::menu::item_proxy &ip) {open();});
	MainBar.at(0).append("Save", [this](nana::menu::item_proxy &ip) {save();});
	//MainBar.at(0).append("Save As...", [this](nana::menu::item_proxy &ip) {});
	/*MainBar.push_back("Edit");
	MainBar.at(1).append("Add Effect Object");
	MainBar.at(1).append("Remove Effect Object");
	MainBar.at(1).append("Add Unk1_2");
	MainBar.at(1).append("Remove Unk1_2");*/
	MainBar.bgcolor(nana::color(250, 250, 250));

	lblUnk0.create(*this, nana::rectangle(20, 37, 30, 17));
	lblUnk0.caption("Unk0:");
	lblUnk0.bgcolor(nana::color(240, 240, 240));
	txtUnk0.create(*this, nana::rectangle(65, 35, 100, 21));
	txtUnk0.events().key_release([this]() {file.unk0 = std::atoi(txtUnk0.caption().c_str());});

	tab.create(*this, nana::rectangle(0, 60, 400, 21));
	tab.push_back("Effect Files");
	tab.push_back("Effects");
	tab.bgcolor(nana::color(240, 240, 240));
	tab.events().activated([this](const nana::arg_tabbar<int> &arg) {tabSwitch((int)tab.activated());});
	eForm = new EffectForm(*this, nana::rectangle(0, 82, 450, 320),&file);
	eForm->bgcolor(nana::color(240, 240, 240));
	aForm = new AnchorForm(*this, nana::rectangle(0, 82, 450, 320),&file);
	aForm->bgcolor(nana::color(240, 240, 240));
	pages.push_back(eForm);
	pages.push_back(aForm);
	eForm->hide();
	aForm->hide();

}


MainForm::~MainForm()
{
}

void MainForm::tabSwitch(int item)
{
	for (int i = 0; i < pages.size(); i++)
	{
		if (item == i)
			pages[i]->show();
		else
			pages[i]->hide();
	}
}

void MainForm::open()
{
	nana::filebox fb(true);
	fb.add_filter("XV2 EEPK File", "*.eepk");
	
	if (fb())
	{
		filename = fb.file();
		file.read(fb.file());
		txtUnk0.caption(std::to_string(file.unk0));
		eForm->lstUnk1.clear();
		for (int i = 0; i < file.unk1Count; i++)
			eForm->lstUnk1.push_back(std::to_string(i));

		aForm->lstUnk2.clear();
		for (int i = 0; i < file.unk2Count; i++)
			aForm->lstUnk2.push_back(std::to_string(i));
		
	}

}

void MainForm::save()
{
	file.write(filename);
}
