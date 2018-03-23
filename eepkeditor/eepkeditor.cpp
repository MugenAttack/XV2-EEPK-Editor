// eepkeditor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MainForm.h"
int main()
{
	
	MainForm main;
	main.caption("XV2 EEPK Editor by MugenAttack");
	main.bgcolor(nana::color(240, 240, 240));
	main.size(nana::size(450, 410));
	main.show();
	nana::exec();

    return 0;
}

