
#include "framework.h"
#include "Logger.h"

//===========================================================
// 
//===================================================
void ShowNumberCallback(hstring cmd, WinRTStaticLibObserver::PODData data) {
    Log(string("Obs1:Update:" + to_string(cmd) + string(":") + to_string(data.m_msg())));
}
void ShowGridCallback(hstring cmd, WinRTStaticLibObserver::PODData data) {
    Log(string("Obs1:Update:" + to_string(cmd) + string(":") + to_string(data.m_msg())));
}


void CommonCmdCallback(hstring cmd, WinRTStaticLibObserver::PODData data) {
    Log(string("Obs2:AutoRevoke:Update" + to_string(cmd) + string(":") + to_string(data.m_msg())));
}
//===========================================================
/*
int32_t __stdcall handler(void* classId, winrt::guid const& iid, void** factory) noexcept
{
    bool expected = reinterpret_cast<hstring const&>(classId) == L"Windows.Foundation.Uri";
    REQUIRE(expected);
    REQUIRE(iid == guid_of<IUriRuntimeClassFactory>());

    *factory = detach_abi(make<custom_factory>());
    return 0;
}
*/

void WinRTLib_Observer_test_app()
{
    auto c_handler = winrt_activation_handler;

    //winrt_activation_handler = winrt_get_activation_factory;
    /*
    auto factory = winrt::get_activation_factory<winrt::WinRTStaticLibObserver::MyObserver>();
    winrt::WinRTStaticLibObserver::MyObserver  account = factory.ActivateInstance<winrt::WinRTStaticLibObserver::MyObserver >();
    
    winrt::Windows::Foundation::IActivationFactory factory = nullptr;
    attach_abi(factory , winrt_get_activation_factory(L"WinRTStaticLibObserver.MyObserver"));
    auto observer11 = factory.ActivateInstance<winrt::WinRTStaticLibObserver::MyObserver >();
    winrt::WinRTStaticLibObserver::MyObserver observer1;
    auto token1 = observer1.Register(L"Show Number", ShowNumberCallback);
    auto token2 = observer1.Register(L"Show Grid", ShowGridCallback);


    winrt::WinRTStaticLibObserver::MyObserverAutoRevoke observer2;
    auto cmdVsTokenMap = observer2.RegisterCmds({ L"Show Number"  , L"Show Grid" }, CommonCmdCallback);
    */

    ObserverConsumer1::WinRTLibObserConsumer consumer1;
    consumer1.Register(L"Show Number");
    //======================
    /*winrt::WinRTStaticLibObserver::MySubject subject;
    WinRTStaticLibObserver::PODData p_data;
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
    */
}




void* __stdcall winrt_get_activation_factory(
    std::wstring_view const& name)
{
    void* factory = WinRTStaticLibObserver_get_activation_factory(name);
    if (factory)
    {
        return factory;
    }

    ////call other activation factories 

    return nullptr;
}

