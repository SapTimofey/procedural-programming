#pragma once
#include <conio.h>
#include <string>

class keyboard
{

public:
	int get_key();
	std::string Key_translation(int key);
};

