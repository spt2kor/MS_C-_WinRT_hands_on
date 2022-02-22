// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <thread>
using namespace std;


#define MAX_LOADSTRING 100

extern HINSTANCE g_hInstance;
extern std::fstream g_fs;

#define Log(msg) g_fs << __LINE__<<":"<<__func__<<"["<<std::this_thread::get_id()<<"] : "<<(msg) << endl;
