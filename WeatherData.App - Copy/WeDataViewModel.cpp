#include "pch.h"
#include "WeDataViewModel.h"
#if __has_include("WeDataViewModel.g.cpp")
#include "WeDataViewModel.g.cpp"
#endif
#include "WeData.h"
#include <winrt/Windows.Web.Http.Headers.h>

using namespace winrt::Windows::Web::Http;
using namespace winrt::Windows::Foundation;
using namespace winrt::WeatherData_App::Model;


namespace winrt::WeatherData_App::implementation
{
    winrt::event_token WeDataViewModel::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    void WeDataViewModel::PropertyChanged(winrt::event_token const& token)
    {
        m_propertyChanged.remove(token);
    }

    IAsyncAction WeDataViewModel::DoWorkAsync(const hstring& cityName)
    {
        if (!cityName.empty()) {
            wstring t_url(L"https://api.openweathermap.org//data//2.5//weather?q=");
            t_url += cityName + L"&appid=6b55e9cff793e92f4dc2ceb5d56cda63";

            Uri weatherApiReqUri{ t_url };
            HttpClient httpClient;
            HttpResponseMessage httpResponseMsg;
            wstring httpResponseMsgStr;

            // Add a user-agent header to the GET request.
            auto headers{ httpClient.DefaultRequestHeaders() };

            // The safe way to add a header value is to use the TryParseAdd method, and verify the return value is true.
            // This is especially important if the header value is coming from user input.
            std::wstring header{ L"ie" };
            if (!headers.UserAgent().TryParseAdd(header))
            {
                throw L"Invalid header value: " + header;
            }

            header = L"Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.2; WOW64; Trident/6.0)";
            if (!headers.UserAgent().TryParseAdd(header))
            {
                throw L"Invalid header value: " + header;
            }

            try {

                httpResponseMsg = co_await httpClient.GetAsync(weatherApiReqUri);
                httpResponseMsg.EnsureSuccessStatusCode();
                httpResponseMsgStr = co_await httpResponseMsg.Content().ReadAsStringAsync();

            }
            catch (winrt::hresult_error const& ex) {
                httpResponseMsgStr = ex.message();
            }

            //WeatherDataResult().Text(httpResponseMsgStr);

            if (convertJSONToWeatherData(httpResponseMsgStr.c_str(), _weData)) {
                m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Pressure" });

                hstring weatherdataStr = L"Temperature : " + to_hstring(_weData._main._temp);

                //WeatherDataResult().Text(weatherdataStr);
            }
            co_return;
        }
    }
}
