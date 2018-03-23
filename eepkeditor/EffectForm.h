#pragma once
#include "C:\nana-master\include\nana\gui\widgets\panel.hpp"
#include "nana\gui\widgets\combox.hpp"
#include "nana\gui\widgets\label.hpp"
#include "nana\gui\widgets\textbox.hpp"
#include "nana\gui.hpp"
#include "nana\gui\widgets\\group.hpp"
#include "nana\gui\widgets\listbox.hpp"
#include "nana\gui\widgets\button.hpp"
#include "eepk.h"
struct unk1_2_item
{
	EEPK_unk1_2* item;
	int index;
};

class EffectForm :
	public nana::panel<false>
{
public:
	EffectForm(nana::window wd, nana::rectangle rect, eepk* _file);
	~EffectForm();
	eepk* file;
	nana::combox lstUnk1;
	nana::label lblUnk1[5];
	nana::textbox txtUnk1[5];

	nana::group grpUnk1_1;
	nana::label lblgrp1;
	nana::combox lstUnk1_1;
	nana::label lblUnk1_100;
	nana::textbox txtUnk1_100;
	nana::listbox lstFiles;

	nana::label lblUnk1str[3];
	nana::textbox txtUnk1str[3];

	//functions
	void updateUnk1();
	void updateUnk1_1();


	EEPK_unk1_1* unk1_1;
	int unk1_2;
	std::vector<unk1_2_item> items;
	nana::form* edit;
	nana::label lbledit;
	nana::textbox txtedit;
	nana::button btnedit;
	bool editopen = false;
	
};

