#pragma once
#include "pch.h"
#include <iostream>
#include "winrt/MyUWPApp.h"

using namespace std;
using namespace winrt::Windows::Foundation;
using namespace winrt;

namespace winrt::MyUWPApp::implementation
{
	class VoiceCommandResultSingleton 
	{
	private:
		MyUWPApp::PODData m_myData;

		winrt::event<MyUWPApp::UpdateOnDataChange > m_Listners;

		VoiceCommandResultSingleton() {}
		~VoiceCommandResultSingleton() {}

	public:
		static VoiceCommandResultSingleton&	GetInstance();
		
		void SetData(MyUWPApp::PODData const& myData);

		event_token AddEventHandler(MyUWPApp::UpdateOnDataChange const& handler);

		void RemoveEventHandler(event_token const& token) noexcept;
	};
}
