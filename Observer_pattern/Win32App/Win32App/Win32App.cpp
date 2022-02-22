// Win32App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "framework.h"
#include "Logger.h"

 int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    // The call to winrt::init_apartment initializes COM; by default, in a multithreaded apartment.
    winrt::init_apartment(apartment_type::single_threaded);

    g_fs.open("main_log.txt", std::fstream::out);
    Log("starting main function");
    //--------------------------------------------

    DLL_Observer_test_App();
    
    Log("//##########################################################");

    Log("//##########################################################");

    WinRTLib_Observer_test_app();
    //--------------------------------------------
    Log("closing main function");
    g_fs.close();
    return 0;
}
