#pragma once
#include "pch.h"
#include "PODData.h"
#include "EventToken.h"
#include <iostream>
#include <unordered_map>

using namespace std;
using namespace winrt::Windows::Foundation;
using namespace winrt;

namespace winrt::WinRTDLLObserver
{
	class VoiceCommandResultSingleton 
	{
	private:
		WinRTDLLObserver::PODData m_myData;
		unordered_map< hstring, winrt::event<WinRTDLLObserver::UpdateOnDataChange >* > m_Listners;
		static shared_ptr<VoiceCommandResultSingleton> m_instance;
		static std::once_flag               m_once_init;

		
		VoiceCommandResultSingleton();
		
		static void NewInstance();

	public:
		~VoiceCommandResultSingleton();

		static VoiceCommandResultSingleton&	GetInstance();
		
		void SetData(const hstring& cmdStr, WinRTDLLObserver::PODData const& myData);

		WinRTDLLObserver::EventToken AddEventHandler(const hstring& cmdStr, WinRTDLLObserver::UpdateOnDataChange & handler);

		void RemoveEventHandler(const hstring& cmdStr, const WinRTDLLObserver::EventToken& token_value) ;
	};
}
