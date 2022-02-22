#include "pch.h"
#include "VoiceCommandResultSingleton.h"

namespace winrt::MyUWPApp::implementation
{		
	VoiceCommandResultSingleton& VoiceCommandResultSingleton::GetInstance()
	{
		static VoiceCommandResultSingleton theVoiceCommandResultSingleton{};
		return theVoiceCommandResultSingleton;
	}

	void VoiceCommandResultSingleton::SetData(MyUWPApp::PODData const& myData) 
	{
		m_myData = myData;
		m_Listners(m_myData);
	}

	event_token VoiceCommandResultSingleton::AddEventHandler(MyUWPApp::UpdateOnDataChange const& handler)
	{
		return m_Listners.add(handler);
	}

	void VoiceCommandResultSingleton::RemoveEventHandler(event_token const& token) noexcept
	{
		m_Listners.remove(token);
	}

}
