#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "WeatherDataUserControl.g.h"
#include "WeatherDataUserControl.h"
#include "WeData.h"

using namespace winrt::WeatherData_App::Model;

namespace winrt::WeatherData_App::implementation
{
    struct WeatherDataUserControl : WeatherDataUserControlT<WeatherDataUserControl>
    {
        WeData& _weData;

        WeatherDataUserControl();

        WeData WeDataP();
        void WeDataP(WeData& data);        
    };
}

namespace winrt::WeatherData_App::factory_implementation
{
    struct WeatherDataUserControl : WeatherDataUserControlT<WeatherDataUserControl, implementation::WeatherDataUserControl>
    {
    };
}
