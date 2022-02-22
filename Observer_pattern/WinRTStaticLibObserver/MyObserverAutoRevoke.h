#pragma once
#include "MyObserverAutoRevoke.g.h"
#include "ObserverSingleton.h"

using Map = winrt::Windows::Foundation::Collections::IMap<winrt::hstring, winrt::WinRTStaticLibObserver::EventToken>;
using MapView = winrt::Windows::Foundation::Collections::IMapView<winrt::hstring, winrt::WinRTStaticLibObserver::EventToken>;
using Vector = winrt::Windows::Foundation::Collections::IVector<winrt::hstring>;

namespace winrt::WinRTStaticLibObserver::implementation
{

    struct MyObserverAutoRevoke : MyObserverAutoRevokeT<MyObserverAutoRevoke>
    {
    private:

        winrt::WinRTStaticLibObserver::ObserverSingleton& m_ObserverSingleton;
        Map m_CmdTokenMap{ nullptr };

    public:

        MyObserverAutoRevoke();
        ~MyObserverAutoRevoke();

        winrt::WinRTStaticLibObserver::EventToken Register(winrt::hstring const& cmdString, winrt::WinRTStaticLibObserver::UpdateOnDataChange const& func);

        void DeRegister(winrt::hstring const& cmdString, winrt::WinRTStaticLibObserver::EventToken const& token_value);

        MapView RegisterCmds(Vector const& cmdStrings, winrt::WinRTStaticLibObserver::UpdateOnDataChange const& func);

        void DeRegisterCmds(MapView const& reg_tokens);

        void DeRegisterAll();
    };
}
namespace winrt::WinRTStaticLibObserver::factory_implementation
{
    struct MyObserverAutoRevoke : MyObserverAutoRevokeT<MyObserverAutoRevoke, implementation::MyObserverAutoRevoke>
    {
    };
}
