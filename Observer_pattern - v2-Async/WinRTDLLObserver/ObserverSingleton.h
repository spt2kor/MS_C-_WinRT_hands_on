#pragma once
#include "pch.h"
#include "PODData.h"
#include "EventToken.h"
#include <iostream>
#include <unordered_map>
#include <memory>
using namespace winrt;

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;


namespace winrt::WinRTDLLObserver
{
	class ObserverSingleton 
	{
	private:
		//unordered_map< hstring, winrt::event<WinRTDLLObserver::UpdateOnDataChange >* > m_Listners;
		typedef unordered_map< hstring, unique_ptr<event<WinRTDLLObserver::UpdateOnDataChange > > > EventMAP;
		typedef EventMAP::iterator EventMAP_ITR;

		EventMAP m_Listners;
		static shared_ptr<ObserverSingleton>	m_instance;
		static std::once_flag					m_once_init;
		slim_mutex								m_mapChange;
		WinRTDLLObserver::PODData				m_myData;
		

		//-----------------------------
		ObserverSingleton();		
		static void NewInstance();

	public:
		~ObserverSingleton();

		static ObserverSingleton&	GetInstance();
		
		fire_and_forget NotifyAsyn(hstring cmdStr, WinRTDLLObserver::PODData myData);

		WinRTDLLObserver::EventToken AddEventHandler(const hstring& cmdStr, WinRTDLLObserver::UpdateOnDataChange const& handler);

		void RemoveEventHandler(const hstring& cmdStr, const WinRTDLLObserver::EventToken& token_value) ;
	};
}
