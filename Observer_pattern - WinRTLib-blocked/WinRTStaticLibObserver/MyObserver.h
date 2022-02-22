#pragma once
#include "MyObserver.g.h"
#include "ObserverSingleton.h"

using namespace std;

namespace winrt::WinRTStaticLibObserver::implementation
{
    struct MyObserver : MyObserverT<MyObserver>
    {
    private:
        WinRTStaticLibObserver::ObserverSingleton& m_ObserverSingleton;

    public:

        MyObserver();

        WinRTStaticLibObserver::EventToken Register(hstring const& cmdString, WinRTStaticLibObserver::UpdateOnDataChange const& func);

        void DeRegister(hstring const& cmdString, WinRTStaticLibObserver::EventToken const& token_value);
    };
}
namespace winrt::WinRTStaticLibObserver::factory_implementation
{
    struct MyObserver : MyObserverT<MyObserver, implementation::MyObserver>
    {
    };
}
