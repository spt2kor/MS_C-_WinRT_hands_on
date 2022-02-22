#include "pch.h"
#include "MyObservable.h"
#include "MyObservable.g.cpp"
#include "Logger.h"

namespace winrt::WinRTDLLObserver::implementation
{
    void MyObservable::SetData(const hstring& cmdStr, WinRTDLLObserver::PODData const& myData)
    {
        m_VoiceCmdResultSingleton.SetData(cmdStr , myData);
    }

    WinRTDLLObserver::EventToken  MyObservable::Register(const hstring& cmdStr, WinRTDLLObserver::UpdateOnDataChange handler)
    {
        return m_VoiceCmdResultSingleton.AddEventHandler(cmdStr, handler);
    }


    void MyObservable::DeRegister(const hstring& cmdStr, const WinRTDLLObserver::EventToken& token_value)
    {
        return m_VoiceCmdResultSingleton.RemoveEventHandler(cmdStr,token_value);
    }


    MyObservable::MyObservable() : m_VoiceCmdResultSingleton(winrt::WinRTDLLObserver::VoiceCommandResultSingleton::GetInstance())
    {

    }
}
