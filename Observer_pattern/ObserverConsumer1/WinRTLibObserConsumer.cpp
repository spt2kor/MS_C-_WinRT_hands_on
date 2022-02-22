#include "pch.h"
#include "WinRTLibObserConsumer.h"
#include "WinRTLibObserConsumer.g.cpp"
#include "Logger.h"

namespace winrt::ObserverConsumer1::implementation
{


    void WinRTLibObserConsumer::Register(const hstring& cmdStr)
    {
        //return  m_MyObservable.Register(cmdStr, m_callback);
        m_token = m_Observer.Register(cmdStr, {this, &WinRTLibObserConsumer::MyCallback });
    }


    void WinRTLibObserConsumer::DeRegister(const hstring& cmdStr)
    {
        return m_Observer.DeRegister(cmdStr, m_token);
    }


    void WinRTLibObserConsumer::MyCallback(hstring cmd, WinRTStaticLibObserver::PODData p_data)
    {
        Log(string( string("DLL:Update:") + to_string(cmd) + string(":") + to_string(p_data.m_msg()) ) );
    }

    WinRTLibObserConsumer::WinRTLibObserConsumer() : m_Observer(WinRTStaticLibObserver::MyObserver())
    {
     /*   m_callback = [this](hstring cmd, WinRTDLLObserver::PODData p_data) {
            this->m_strData = to_hstring(string("Recev:ObserConsumer1 :") + to_string(cmd) + string(" => ") + to_string(p_data.m_msg()));
        };
        */
    }
}
