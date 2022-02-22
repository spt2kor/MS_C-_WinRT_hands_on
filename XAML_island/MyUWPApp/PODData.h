#pragma once
#include "PODData.g.h"


namespace winrt::MyUWPApp::implementation
{
    struct PODData : PODDataT<PODData>
    {
        PODData();
        ~PODData();

        hstring m_msg();
        void m_msg(hstring const& value);
        hstring m_value();
        void m_value(hstring const& value);
        int16_t m_status();
        void m_status(int16_t value);
    private:
        hstring _msg;
        hstring _value;
        int16_t _status;

    };
}

namespace winrt::MyUWPApp::factory_implementation
{
    struct PODData : PODDataT<PODData, implementation::PODData>
    {
    };
}