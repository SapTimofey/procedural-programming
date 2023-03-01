#pragma once
#include <iostream>    //Для cin/cout
#include <locale>      //Для вывода русским
#include <string>      //Для перевода string -> int/float
#include "HomeWork4.h" //Модуль Д/з 4
#include "Settings.h"  //Модуль настроек
#include "main.h"
#include <msclr\marshal_cppstd.h>


float chek(int type, std::string cons_out, bool i);

float check_num(int type, System::String^ str);