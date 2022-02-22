#include "pch.h"
#include "WeatherDataUserControl.h"
#if __has_include("WeatherDataUserControl.g.cpp")
#include "WeatherDataUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::WeatherData_App::implementation
{
    WeatherDataUserControl::WeatherDataUserControl():
        _weData(winrt::WeatherData_App::Model::GetWeData())
    {
        InitializeComponent();
    }


}
