#include "pch.h"
#include "App.h"
#include "App.g.cpp"
#include "Logger.h"

#include "winrt/MyObserverUtil.h"
using namespace winrt;
using namespace Windows::UI::Xaml;

std::fstream g_fs;


void TEST_DLL_With_Ecports_win32() {

    winrt::MyObserverUtil::MyObservable observable;

    auto func = [](auto& cmdStr, auto& podData) {
        Log(string("Recv::" + string(to_string(cmdStr))));
        Log(string("Recv:POD:" + string(to_string(podData.m_msg()))));
    };
    Log("RegisterObserver");
    observable.Register(L"Show Number", func);
    /*
    winrt::MyObserverUtil::PODData pdata;
    pdata.m_msg(L"ShowNumberCmd");
    observable.SetData(L"Show Number", pdata);
    */
    Sleep(3000);
   // observable.DeRegister(L"Show Number", func);
}

namespace winrt::MyUWPApp::implementation
{
    App::App()
    {
        Initialize();
        AddRef();
        m_inner.as<::IUnknown>()->Release();

        g_fs.open("XAML_islan_UWP_log.txt", std::fstream::out);

        Log("starting App function");

        TEST_DLL_With_Ecports_win32();
    }
    App::~App()
    {
        Log("closing App function");
        g_fs.close();

        Close();
    }
}