#pragma once
#include <iostream>    //��� cin/cout
#include <locale>      //��� ������ �������
#include <string>      //��� �������� string -> int/float
#include "HomeWork4.h" //������ �/� 4
#include "Settings.h"  //������ ��������
#include "main.h"
#include <msclr\marshal_cppstd.h>


float chek(int type, std::string cons_out, bool i);

float check_num(int type, System::String^ str);