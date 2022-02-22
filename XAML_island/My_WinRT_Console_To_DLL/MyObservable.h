#pragma once
#include "MyObserverUtil.MyObservable.g.h"
#include "VoiceCommandResultSingleton.h"

using namespace std;
using namespace winrt::Windows::Foundation;
using namespace winrt;

namespace winrt::MyObserverUtil::implementation
{
    struct MyObservable : MyObservableT<MyObservable>
    {
    private:
        VoiceCommandResultSingleton& m_VoiceCmdResultSingleton;
    
    public:
        MyObservable() ;

        void SetData(const hstring& cmdStr , MyObserverUtil::PODData const& myData);

        int16_t Register(const hstring& cmdStr, MyObserverUtil::UpdateOnDataChange func);
        int16_t DeRegister(const hstring& cmdStr, MyObserverUtil::UpdateOnDataChange func);

 //       event_token NotifyOnDataChange(MyObserverUtil::UpdateOnDataChange const& handler);
        
   //     void NotifyOnDataChange(event_token const& token) noexcept;
    };
}
namespace winrt::MyObserverUtil::factory_implementation
{
    struct MyObservable : MyObservableT<MyObservable, implementation::MyObservable>
    {
    };
}
