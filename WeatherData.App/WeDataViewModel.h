#pragma once

#include "WeDataViewModel.g.h"
#include <WeData.h>
#include <winrt/Windows.Foundation.h>

using namespace winrt::WeatherData_App::Model;

namespace winrt::WeatherData_App::implementation
{
    struct WeDataViewModel : WeDataViewModelT<WeDataViewModel>
    {
        WeDataViewModel() = default;
        WeData _weData;
        bool _WeDataModified;

        WeData MainWeData() {
            return _weData;
        }
        bool WeDataModified()
        {
            return _WeDataModified;
        }

        void WeDataModified(bool WeDataModified);

        Windows::Foundation::IAsyncAction DoWorkAsync(const hstring& cityName);

        winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value);

        void PropertyChanged(winrt::event_token const& token);

        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::WeatherData_App::factory_implementation
{
    struct WeDataViewModel : WeDataViewModelT<WeDataViewModel, implementation::WeDataViewModel>
    {
    };
}
