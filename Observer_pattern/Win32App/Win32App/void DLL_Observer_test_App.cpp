

#include "framework.h"
#include "Logger.h"

//===========================================================
// 
//===================================================
void ShowNumberCallback(hstring cmd, WinRTDLLObserver::PODData data) {
    Log(string("Obs1:Update:" + to_string(cmd) + string(":") + to_string(data.m_msg())));
}
void ShowGridCallback(hstring cmd, WinRTDLLObserver::PODData data) {
    Log(string("Obs1:Update:" + to_string(cmd) + string(":") + to_string(data.m_msg())));
}


void CommonCmdCallback(hstring cmd, WinRTDLLObserver::PODData data) {
    Log(string("Obs2:AutoRevoke:Update" + to_string(cmd) + string(":") + to_string(data.m_msg())));
}
//===========================================================



void DLL_Observer_test_App()
{
    winrt::WinRTDLLObserver::MyObserver observer1;
    auto token1 = observer1.Register(L"Show Number", ShowNumberCallback);
    auto token2 = observer1.Register(L"Show Grid", ShowGridCallback);


    winrt::WinRTDLLObserver::MyObserverAutoRevoke observer2;
    auto cmdVsTokenMap = observer2.RegisterCmds({ L"Show Number"  , L"Show Grid" }, CommonCmdCallback);


    ObserverConsumer1::ObserConsumer1 consumer1;
    consumer1.Register(L"Show Number");
    //======================
    winrt::WinRTDLLObserver::MySubject subject;
    WinRTDLLObserver::PODData p_data;
    p_data.m_msg(L"Val=1");
    subject.NotifyAsyn(L"Show Number", p_data);
    //======================
    Sleep(500);
    //-----------------------------------
    p_data.m_msg(L"Val=2");
    subject.NotifyAsyn(L"Show Grid", p_data);
    //-----------------------------------
    Sleep(1000);
    //----------------------------
    observer2.DeRegisterCmds(cmdVsTokenMap);

    consumer1.DeRegister(L"Show Number");

    observer1.DeRegister(L"Show Number", token1);
    observer1.DeRegister(L"Show Grid", token2);
}