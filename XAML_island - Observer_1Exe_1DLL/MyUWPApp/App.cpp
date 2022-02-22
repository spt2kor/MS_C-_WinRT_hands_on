#include "pch.h"
#include "App.h"
#include "App.g.cpp"
#include "Logger.h"
using namespace winrt;
using namespace Windows::UI::Xaml;

std::fstream g_fs;

namespace winrt::MyUWPApp::implementation
{
    App::App()
    {
        Initialize();
        AddRef();
        m_inner.as<::IUnknown>()->Release();

        g_fs.open("XAML_islan_UWP_log.txt", std::fstream::out);

        Log("starting App function");

    }
    App::~App()
    {
        Log("closing App function");
        g_fs.close();

        Close();
    }
}