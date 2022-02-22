#pragma once
#include "MyTestClass.g.h"


namespace winrt::MyUWPApp::implementation
{
    struct MyTestClass : MyTestClassT<MyTestClass>
    {
        MyTestClass();

        MyTestClass(int16_t some_value);
        static int16_t GetInstanceCount();
        int16_t GetValue();
    private:
        static int16_t m_instanceCount;

        int16_t m_value{0};
    };
}
namespace winrt::MyUWPApp::factory_implementation
{
    struct MyTestClass : MyTestClassT<MyTestClass, implementation::MyTestClass>
    {
    };
}
