#pragma once
#include "PODData.h"
#include "EventToken.h"
#include <iostream>
#include <unordered_map>
#include <memory>


using namespace std;

namespace winrt::WinRTStaticLibObserver
{
	class ObserverSingleton 
	{
	private:
		typedef unordered_map< hstring, unique_ptr<event<winrt::WinRTStaticLibObserver::UpdateOnDataChange > > > EventMAP;
		typedef EventMAP::iterator EventMAP_ITR;

		EventMAP								m_Listners;
		static shared_ptr<ObserverSingleton>	m_instance;
		static std::once_flag					m_once_init;
		slim_mutex								m_mapChange;

		//-----------------------------
		ObserverSingleton();		
		static void NewInstance();

	public:
		~ObserverSingleton();

		static ObserverSingleton&	GetInstance();
		
		winrt::fire_and_forget NotifyAsyn(winrt::hstring cmdStr, winrt::WinRTStaticLibObserver::PODData myData);

		winrt::WinRTStaticLibObserver::EventToken AddEventHandler(const winrt::hstring& cmdStr, winrt::WinRTStaticLibObserver::UpdateOnDataChange const& handler);

		void RemoveEventHandler(const winrt::hstring& cmdStr, const winrt::WinRTStaticLibObserver::EventToken& token_value) ;
	};
}
