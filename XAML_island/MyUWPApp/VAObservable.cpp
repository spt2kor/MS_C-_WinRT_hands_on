#include "pch.h"
#include "VAObservable.h"
#include "VAObservable.g.cpp"

namespace winrt::MyUWPApp::implementation
{
    void VAObservable::SetData(MyUWPApp::PODData const& myData)
    {
        m_VoiceCmdResultSingleton.SetData(myData);
    }


    event_token VAObservable::NotifyOnDataChange(MyUWPApp::UpdateOnDataChange const& handler)
    {
        return m_VoiceCmdResultSingleton.AddEventHandler(handler);
    }


    void VAObservable::NotifyOnDataChange(event_token const& token) noexcept
    {
        m_VoiceCmdResultSingleton.RemoveEventHandler(token);
    }


    VAObservable::VAObservable() : m_VoiceCmdResultSingleton(VoiceCommandResultSingleton::GetInstance())
    {

    }
}
