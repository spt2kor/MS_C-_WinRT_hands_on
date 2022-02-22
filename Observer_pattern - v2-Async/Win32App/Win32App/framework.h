#pragma once

#include <windows.h>
#undef GetCurrentTime
// C RunTime Header Files
#include <iostream>
#include <fstream>
#include <thread>
using namespace std;
//===================================================
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.system.h>

#include <winrt/WinRTDLLObserver.h>
#include <winrt/ObserverConsumer1.h>


using namespace winrt;
//============================================================
extern std::fstream g_fs;
//==========================================================
#define Log(msg) g_fs << __LINE__<<":"<<__func__<<"["<<std::this_thread::get_id()<<"] : "<<(msg) << endl;


//============================================================


