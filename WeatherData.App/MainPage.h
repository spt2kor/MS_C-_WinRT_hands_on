#pragma once

#include "MainPage.g.h"
#include <winrt/Windows.Foundation.h>



namespace winrt::WeatherData_App::implementation
{
    struct MainPage : MainPageT<MainPage>
    {

        WeatherData_App::WeDataViewModel _weDataViewModel;

        MainPage();
        WeatherData_App::WeDataViewModel& MainWeDataViewModel() {
            return _weDataViewModel;
        }

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

        Windows::Foundation::IAsyncAction DoWorkAsync(const hstring& cityName);
    };
}

namespace winrt::WeatherData_App::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
