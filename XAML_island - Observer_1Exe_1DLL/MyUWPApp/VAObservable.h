#pragma once
#include "VAObservable.g.h"
#include "VoiceCommandResultSingleton.h"

using namespace std;
using namespace winrt::Windows::Foundation;
using namespace winrt;

namespace winrt::MyUWPApp::implementation
{
    struct VAObservable : VAObservableT<VAObservable>
    {
    private:
        VoiceCommandResultSingleton& m_VoiceCmdResultSingleton;
    
    public:
        VAObservable() ;

        void SetData(MyUWPApp::PODData const& myData);
        
        event_token NotifyOnDataChange(MyUWPApp::UpdateOnDataChange const& handler);
        
        void NotifyOnDataChange(event_token const& token) noexcept;
    };
}
namespace winrt::MyUWPApp::factory_implementation
{
    struct VAObservable : VAObservableT<VAObservable, implementation::VAObservable>
    {
    };
}
