#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace winrt::WeatherData_App::Model
{
	struct WeData
	{
        struct Coordinates {
            double _longi = 0.0;
            double _latit = 0.0;
        }_coord; 

        struct Weather {
            struct WeatherDetails {
                long _id = 0;
                hstring _main;
                hstring _desc;
                hstring _icon;
            };
            vector<WeatherDetails> _arrWeatherDetails;
        }_weather;
        
        hstring _base;

        struct Main {
            double _temp = 0.0;
            double _feels_like = 0.0;
            double _temp_min =0.0;
            double _temp_max = 0.0;
            long _pressure =0;
            long _humidity =0;
        }_main;

        long _visibility = 0;

        struct Wind {
            double _speed =0.0;
            long _deg =0;
        }_wind;
        
        struct Clouds {
            long _all =0;
        }_clouds;

        long _dt =0;

        struct Sys {
            long _type =0;
            long _id =0;
            hstring _country;
            long _sunrise =0;
            long _sunset =0;
        }_sys;
        
        long __timezone =0;
        long _id =0;
        hstring _name;
        long _cod =0;
	};

    WeData& GetWeData();
    bool convertJSONToWeatherData(const hstring& jsonData, WeData& weData);
}

