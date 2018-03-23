#pragma once
#include "nana\gui.hpp"
#include "nana\gui\widgets\menubar.hpp"
#include "nana\gui\widgets\combox.hpp"
#include "nana\gui\widgets\label.hpp"
#include "nana\gui\widgets\textbox.hpp"
#include "nana\gui\widgets\tabbar.hpp"
#include "EffectForm.h"
#include "AnchorForm.h"
#include "eepk.h"
class MainForm :
	public nana::form
{
public:
	MainForm();
	~MainForm();
	nana::menubar MainBar;
	nana::tabbar<int> tab;
	std::vector<nana::panel<false>*> pages;
	void tabSwitch(int);
	EffectForm* eForm;
	AnchorForm* aForm;
	nana::label lblUnk0;
	nana::textbox txtUnk0;
	eepk file;
	std::string filename;
	void open();
	void save();





};

