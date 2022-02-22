#pragma once

#include <windows.h>
#undef GetCurrentTime
// C RunTime Header Files
#include <iostream>
#include <fstream>
#include <thread>

#include <chrono>
#include <ctime>
#include <time.h>
using namespace std;
//===================================================
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.system.h>

#include "winrt/WinRTDLLObserver.h"
#include "winrt/ObserverConsumer1.h"
#include "winrt/WinRTStaticLibObserver.h"


void* __stdcall WinRTStaticLibObserver_get_activation_factory(
    std::wstring_view const& name);

void* __stdcall winrt_get_activation_factory(
    std::wstring_view const& name);
    

void DLL_Observer_test_App();

void WinRTLib_Observer_test_app();



using namespace winrt;
