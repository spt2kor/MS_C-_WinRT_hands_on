#pragma once
#include "pch.h"
#include <iostream>
#include <unordered_map>
#include "winrt/MyObserverUtil.h"

using namespace std;
using namespace winrt::Windows::Foundation;
using namespace winrt;

namespace winrt::MyObserverUtil::implementation
{
	class VoiceCommandResultSingleton 
	{
	private:
		MyObserverUtil::PODData m_myData;

		unordered_map< hstring, winrt::event<MyObserverUtil::UpdateOnDataChange >* > m_Listners;

		//unordered_map< MyObserverUtil::UpdateOnDataChange, event_token> m_ListnersTokens;

		//unordered_map< void *, event_token> m_ListnersTokens;


		VoiceCommandResultSingleton() {}
		~VoiceCommandResultSingleton() {}

	public:
		static VoiceCommandResultSingleton&	GetInstance();
		
		void SetData(const hstring& cmdStr, MyObserverUtil::PODData const& myData);

		int16_t AddEventHandler(const hstring& cmdStr, MyObserverUtil::UpdateOnDataChange & handler);

		int16_t RemoveEventHandler(const hstring& cmdStr, MyObserverUtil::UpdateOnDataChange & handler) ;
	};
}
