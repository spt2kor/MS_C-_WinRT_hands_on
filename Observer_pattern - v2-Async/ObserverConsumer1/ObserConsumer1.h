#pragma once
#include "ObserConsumer1.g.h"
#include "winrt/WinRTDLLObserver.h"

#include <functional>



using namespace std;
using namespace winrt::Windows::Foundation;
using namespace winrt;


namespace winrt::ObserverConsumer1::implementation
{
    struct ObserConsumer1 : ObserConsumer1T<ObserConsumer1>
    {
    private:
        WinRTDLLObserver::MyObserver m_Observer{nullptr};
        hstring m_strData;
        std::function <void(hstring, WinRTDLLObserver::PODData)> m_callback;

        void MyCallback(hstring cmd, WinRTDLLObserver::PODData p_data);
        WinRTDLLObserver::EventToken m_token;
    public:
        ObserConsumer1() ;
        hstring GetData();

        void Register(const hstring& cmdStr);
        void DeRegister(const hstring& cmdStr);

    };
}
namespace winrt::ObserverConsumer1::factory_implementation
{
    struct ObserConsumer1 : ObserConsumer1T<ObserConsumer1, implementation::ObserConsumer1>
    {
    };
}
