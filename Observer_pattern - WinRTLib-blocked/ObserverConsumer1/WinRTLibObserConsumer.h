#pragma once
#include "WinRTLibObserConsumer.g.h"
#include "winrt/WinRTStaticLibObserver.h"

#include <functional>

using namespace std;
using namespace winrt::Windows::Foundation;
using namespace winrt;


namespace winrt::ObserverConsumer1::implementation
{
    struct WinRTLibObserConsumer : WinRTLibObserConsumerT<WinRTLibObserConsumer>
    {
    private:
        WinRTStaticLibObserver::MyObserver m_Observer{nullptr};
        std::function <void(hstring, WinRTStaticLibObserver::PODData)> m_callback;

        void MyCallback(hstring cmd, WinRTStaticLibObserver::PODData p_data);
        WinRTStaticLibObserver::EventToken m_token;
    public:
        WinRTLibObserConsumer() ;

        void Register(const hstring& cmdStr);
        void DeRegister(const hstring& cmdStr);

    };
}
namespace winrt::ObserverConsumer1::factory_implementation
{
    struct WinRTLibObserConsumer : WinRTLibObserConsumerT<WinRTLibObserConsumer, implementation::WinRTLibObserConsumer>
    {
    };
}
