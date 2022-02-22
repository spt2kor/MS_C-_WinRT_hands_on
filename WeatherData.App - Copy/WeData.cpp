#include "pch.h"
#include "WeData.h"


using namespace winrt::Windows::Data::Json;

namespace winrt::WeatherData_App::Model
{
//"coord": {
//    "lon": 77.22,
//    "lat": 28.67
//  },
	void GetCoord(const JsonObject& root , WeData& weData) {
		JsonObject dummyObject;
		JsonObject _coord = root.GetNamedObject(L"coord", dummyObject);
		if (_coord.ValueType() == JsonValueType::Object) {
			weData._coord._latit = _coord.GetNamedNumber(L"lon" , 0.0);
			weData._coord._longi = _coord.GetNamedNumber(L"lat", 0.0);;
		}
	}
//  "weather": [
//    {
//      "id": 721,
//      "main": "Haze",
//      "description": "haze",
//      "icon": "50n"
//    }
//  ],
	void GetWeather(const JsonObject& root, WeData& weData) {
		JsonArray dummyObject;
		JsonArray weather = root.GetNamedArray(L"weather", dummyObject);
		if (weather.ValueType() == JsonValueType::Array)	{
			for (int i = 0; i < weather.Size(); ++i)	{
				JsonObject obj = weather.GetObjectAt(i);
				if(obj.ValueType() == JsonValueType::Object)	{
					WeData::Weather::WeatherDetails aWD;
					aWD._id = obj.GetNamedNumber(L"id", 0);
					aWD._main = obj.GetNamedString(L"main", L"");
					aWD._desc = obj.GetNamedString(L"description", L"");
					aWD._icon = obj.GetNamedString(L"icon", L"");
					weData._weather._arrWeatherDetails.push_back(aWD);
				}
			}
		}
	}
//  "base": "stations",
	void GetBase(const JsonObject& root, WeData& weData) {
		weData._base = root.GetNamedString(L"base", L"");
	}
//  "main": {
//    "temp": 291.63,
//    "feels_like": 290.47,
//    "temp_min": 289.15,
//    "temp_max": 294.26,
//    "pressure": 1021,
//    "humidity": 63
//  },
	void GetMain(const JsonObject& root, WeData& weData) {
		JsonObject dummyObject;
		JsonObject __main = root.GetNamedObject(L"main", dummyObject);
		if (__main.ValueType() == JsonValueType::Object) {
			weData._main._temp = __main.GetNamedNumber(L"temp", 0.0);
			weData._main._feels_like = __main.GetNamedNumber(L"feels_like", 0.0);
			weData._main._temp_min = __main.GetNamedNumber(L"temp_min", 0.0);
			weData._main._temp_max = __main.GetNamedNumber(L"temp_max", 0.0);
			weData._main._pressure = __main.GetNamedNumber(L"pressure", 0);
			weData._main._humidity = __main.GetNamedNumber(L"humidity", 0);
		}
	}

//  "visibility": 3000,
	void GetVisibility(const JsonObject& root, WeData& weData) {
		weData._visibility = root.GetNamedNumber(L"visibility", 0);
	}
//  "wind": {
//    "speed": 2.25,
//    "deg": 291
//  },
	void GetWind(const JsonObject& root, WeData& weData) {
		JsonObject dummyObject;
		JsonObject _wind = root.GetNamedObject(L"coord", dummyObject);
		if (_wind.ValueType() == JsonValueType::Object) {
			weData._wind._speed = _wind.GetNamedNumber(L"speed", 0.0);
			weData._wind._deg= _wind.GetNamedNumber(L"deg", 0);;
		}
	}
//  "clouds": {
//    "all": 0
//  },
	void GetClouds(const JsonObject& root, WeData& weData) {
		JsonObject dummyObject;
		JsonObject _clouds = root.GetNamedObject(L"coord", dummyObject);
		if (_clouds.ValueType() == JsonValueType::Object) {
			weData._clouds._all = _clouds.GetNamedNumber(L"all", 0);
		}
	}
//  "dt": 1606499379,
	void Getdt(const JsonObject& root, WeData& weData) {
		weData._dt= root.GetNamedNumber(L"dt", 0);
	}
//  "sys": {
//    "type": 1,
//    "id": 9165,
//    "country": "IN",
//    "sunrise": 1606440224,
//    "sunset": 1606478054
//  },
	void GetSys(const JsonObject& root, WeData& weData) {
		JsonObject dummyObject;
		JsonObject _sys = root.GetNamedObject(L"main", dummyObject);
		if (_sys.ValueType() == JsonValueType::Object) {
			weData._sys._type = _sys.GetNamedNumber(L"type", 0);
			weData._sys._id = _sys.GetNamedNumber(L"id", 0);
			weData._sys._country = _sys.GetNamedString(L"country", L"");
			weData._sys._sunrise = _sys.GetNamedNumber(L"sunrise", 0.0);
			weData._sys._sunset = _sys.GetNamedNumber(L"sunset", 0);
		}
	}
//  "timezone": 19800,
	void GetTimeZone(const JsonObject& root, WeData& weData) {
		weData.__timezone = root.GetNamedNumber(L"timezone", 0);
	}
//  "id": 1273294,
	void GetId(const JsonObject& root, WeData& weData) {
		weData._id = root.GetNamedNumber(L"id", 0);
	}
//  "name": "Delhi",
	void GetName(const JsonObject& root, WeData& weData) {
		weData._name = root.GetNamedString(L"name", L"");
	}
//  "cod": 200
	void GetCod(const JsonObject& root, WeData& weData) {
		weData._cod = root.GetNamedNumber(L"cod", 0);
	}

	bool convertJSONToWeatherData(const hstring& jsonData, WeData& weData) {
		JsonObject root{nullptr};
		if (JsonObject::TryParse(jsonData, root)) {
			//==================================================
			GetCoord(root, weData);
			GetWeather(root, weData);
			GetBase(root, weData);
			GetMain(root, weData); 
			GetVisibility(root, weData);
			GetWind(root, weData);
			GetClouds(root, weData);
			Getdt(root, weData);
			GetSys(root, weData);			
			GetTimeZone(root, weData);
			GetId(root, weData);
			GetName(root, weData);
			GetCod(root, weData);
			//===========================================================
			return true;
		}
		return false;
	}

	WeData& GetWeData()
	{
		static WeData _WeData;
		return _WeData;
	}
}
