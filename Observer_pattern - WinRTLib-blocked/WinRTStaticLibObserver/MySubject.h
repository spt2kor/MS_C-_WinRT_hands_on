#pragma once
#include "MySubject.g.h"

#include "ObserverSingleton.h"


namespace winrt::WinRTStaticLibObserver::implementation
{
    struct MySubject : MySubjectT<MySubject>
    {
    private:
        winrt::WinRTStaticLibObserver::ObserverSingleton& m_ObserverSingleton;

    public:
        MySubject();

        void NotifyAsyn(hstring const& cmdStr, winrt::WinRTStaticLibObserver::PODData const& myData);
    };
}
namespace winrt::WinRTStaticLibObserver::factory_implementation
{
    struct MySubject : MySubjectT<MySubject, implementation::MySubject>
    {
    };
}
