#include "pch.h"
#include "MyObserver.h"
#include "MyObserver.g.cpp"

namespace winrt::WinRTDLLObserver::implementation
{
    MyObserver::MyObserver() :m_ObserverSingleton(ObserverSingleton::GetInstance())
    {

    }

    winrt::WinRTDLLObserver::EventToken MyObserver::Register(hstring const& cmdString, winrt::WinRTDLLObserver::UpdateOnDataChange const& aDelegate)
    {
        return m_ObserverSingleton.AddEventHandler(cmdString, aDelegate);
    }

    void MyObserver::DeRegister(hstring const& cmdString, winrt::WinRTDLLObserver::EventToken const& token_value)
    {
        m_ObserverSingleton.RemoveEventHandler(cmdString, token_value);
    }
}
