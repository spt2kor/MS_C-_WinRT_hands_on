#include "pch.h"
#include "MyObserver.h"
#include "MyObserver.g.cpp"

#include "Logger.h"

namespace winrt::WinRTStaticLibObserver::implementation
{
    MyObserver::MyObserver() :m_ObserverSingleton(ObserverSingleton::GetInstance())
    {

    }

    winrt::WinRTStaticLibObserver::EventToken MyObserver::Register(hstring const& cmdString, winrt::WinRTStaticLibObserver::UpdateOnDataChange const& aDelegate)
    {
        Log(string("reg@cmd:" + to_string(cmdString)));
        return m_ObserverSingleton.AddEventHandler(cmdString, aDelegate);
    }

    void MyObserver::DeRegister(hstring const& cmdString, winrt::WinRTStaticLibObserver::EventToken const& token_value)
    {

        Log(string("Dereg@ccmd:" + to_string(cmdString)));
        m_ObserverSingleton.RemoveEventHandler(cmdString, token_value);
    }
}
