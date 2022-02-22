#pragma once
#include <fstream>
#include <iostream>
using namespace std;

extern std::fstream g_fs;

#define Log(msg) g_fs << __LINE__<<":"<<__func__<<"["<<std::this_thread::get_id()<<"] : "<<(msg) << endl;