#include "pch.h"
#include "MyObservable.h"
#include "MyObserverUtil.MyObservable.g.cpp"
#include "Logger.h"

namespace winrt::MyObserverUtil::implementation
{
    void MyObservable::SetData(const hstring& cmdStr, MyObserverUtil::PODData const& myData)
    {
        m_VoiceCmdResultSingleton.SetData(cmdStr , myData);
    }

    int16_t MyObservable::Register(const hstring& cmdStr, MyObserverUtil::UpdateOnDataChange handler)
    {
        return m_VoiceCmdResultSingleton.AddEventHandler(cmdStr, handler);
    }


    int16_t MyObservable::DeRegister(const hstring& cmdStr, MyObserverUtil::UpdateOnDataChange handler)
    {
        return m_VoiceCmdResultSingleton.RemoveEventHandler(cmdStr , handler);
    }


    MyObservable::MyObservable() : m_VoiceCmdResultSingleton(VoiceCommandResultSingleton::GetInstance())
    {

    }
}
