#pragma once
#include "C:\nana-master\include\nana\gui\widgets\panel.hpp"
#include "nana\gui\widgets\combox.hpp"
#include "nana\gui\widgets\label.hpp"
#include "nana\gui\widgets\textbox.hpp"
#include "nana\gui\widgets\listbox.hpp"
#include "nana\gui.hpp"
#include "nana\gui\widgets\group.hpp"
#include "nana\gui\widgets\checkbox.hpp";
#include "eepk.h"

class AnchorForm :
	public nana::panel<false>
{
public:
	AnchorForm(nana::window wd, nana::rectangle rect, eepk* _file);
	~AnchorForm();
	nana::combox lstUnk2;
	nana::label lblInt00;
	nana::textbox txtInt00;
	nana::checkbox chkEmpty;
	nana::group grpUnk1_1;
	nana::label grblbl1;
	nana::combox cbUnk2_1;
	nana::listbox lstUnk2_1;
	nana::label lblBone;
	nana::textbox txtBone;
	nana::label lblset1[10];
	nana::textbox txtset1[10];
	nana::label lblset2[10];
	nana::textbox txtset2[10];
	nana::label lblset3[10];
	nana::textbox txtset3[6];
	void updateUnk2();
	void updateUnk2_1();
	eepk* file;
	EEPK_unk2* unk2;
	EEPK_unk2_1* unk2_1;
};

