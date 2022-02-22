// Win32App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "framework.h"

std::fstream g_fs;

//===================================================
 void ShowNumberCallback(hstring cmd, WinRTDLLObserver::PODData data) {
     Log( string( "MainReceived: " + to_string(data.m_msg()) )   );
 }
 void ShowGridCallback(hstring cmd, WinRTDLLObserver::PODData data) {
     Log(string("MainReceived: " + to_string(data.m_msg())));
 }
//===========================================================
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    // The call to winrt::init_apartment initializes COM; by default, in a multithreaded apartment.
    winrt::init_apartment(apartment_type::single_threaded);

    g_fs.open("XAML_islan_log.txt", std::fstream::out);
    Log("starting main function");
    //--------------------------------------------
    winrt::WinRTDLLObserver::MyObserver observer1;
    auto token1 = observer1.Register(L"Show Number", ShowNumberCallback);
    auto token2 = observer1.Register(L"Show Grid", ShowGridCallback);


    ObserverConsumer1::ObserConsumer1 consumer1;
    consumer1.Register(L"Show Number");
    //======================
    winrt::WinRTDLLObserver::MySubject subject;
    WinRTDLLObserver::PODData p_data;
    p_data.m_msg(L"_Noitfy@ShowNumber_");
    subject.NotifyAsyn(L"Show Number", p_data);
    //======================

    Log( string( " Consumer1.Received: " + to_string(consumer1.GetData()) )  );
    //-----------------------------------
    p_data.m_msg(L"_Noitfy@ShowGrid_");
    subject.NotifyAsyn(L"Show Grid", p_data);
    //-----------------------------------

    Log(string(" Consumer1.Received: " + to_string(consumer1.GetData())));
    //----------------------------
    consumer1.DeRegister(L"Show Number");
    
    observer1.DeRegister(L"Show Number", token1);
    observer1.DeRegister(L"Show Grid", token2);

    //--------------------------------------------
    Log("closing main function");
    g_fs.close();
    return 0;
}
