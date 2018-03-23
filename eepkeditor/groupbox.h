#pragma once
#include "C:\nana-master\include\nana\gui\widgets\panel.hpp"
#include "nana\gui\widgets\label.hpp"
#include "nana\gui\drawing.hpp"

class groupbox :
	public nana::panel<false>
{
public:
	groupbox(nana::window wd, int x, int y, unsigned int width, unsigned int height);
	~groupbox();
};

