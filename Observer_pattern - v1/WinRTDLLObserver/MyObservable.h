#pragma once
#include "MyObservable.g.h"
#include "VoiceCommandResultSingleton.h"

#include "EventToken.h"

using namespace std;
using namespace winrt::Windows::Foundation;
using namespace winrt;

namespace winrt::WinRTDLLObserver::implementation
{
    struct MyObservable : MyObservableT<MyObservable>
    {
    private:
        winrt::WinRTDLLObserver::VoiceCommandResultSingleton& m_VoiceCmdResultSingleton;
    
    public:
        MyObservable() ;

        void SetData(const hstring& cmdStr , WinRTDLLObserver::PODData const& myData);

        WinRTDLLObserver::EventToken Register(const hstring& cmdStr, WinRTDLLObserver::UpdateOnDataChange func);
        void DeRegister(const hstring& cmdStr, const WinRTDLLObserver::EventToken& token_value);

    };
}
namespace winrt::WinRTDLLObserver::factory_implementation
{
    struct MyObservable : MyObservableT<MyObservable, implementation::MyObservable>
    {
    };
}
