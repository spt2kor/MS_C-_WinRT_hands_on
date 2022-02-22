#include "pch.h"
#include "MySubject.h"
#include "MySubject.g.cpp"

namespace winrt::WinRTDLLObserver::implementation
{
    MySubject::MySubject():m_ObserverSingleton(ObserverSingleton::GetInstance())
    {

    }

    void MySubject::NotifyAsyn(hstring const& cmdStr, winrt::WinRTDLLObserver::PODData const& myData)
    {
        m_ObserverSingleton.NotifyAsyn(cmdStr,myData);
    }
}
