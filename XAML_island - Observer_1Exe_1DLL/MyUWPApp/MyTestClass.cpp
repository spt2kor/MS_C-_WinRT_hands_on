#include "pch.h"
#include "MyTestClass.h"
#include "MyTestClass.g.cpp"


namespace winrt::MyUWPApp::implementation
{
    int16_t MyTestClass::m_instanceCount = 0;

    MyTestClass::MyTestClass()
    {
        ++m_instanceCount;
    }
    MyTestClass::MyTestClass(int16_t some_value):m_value(some_value)
    {
        ++m_instanceCount;
    }
    int16_t MyTestClass::GetInstanceCount()
    {
        return m_instanceCount;
    }
    int16_t MyTestClass::GetValue()
    {
        return m_value;
    }
}
