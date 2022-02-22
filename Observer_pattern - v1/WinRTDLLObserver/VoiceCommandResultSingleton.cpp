#include "pch.h"
#include "VoiceCommandResultSingleton.h"
#include "Logger.h"


namespace winrt::WinRTDLLObserver
{		

	std::once_flag  VoiceCommandResultSingleton::m_once_init;
	std::shared_ptr<VoiceCommandResultSingleton> VoiceCommandResultSingleton::m_instance{ nullptr };


	VoiceCommandResultSingleton::VoiceCommandResultSingleton() 
	{

	}

	VoiceCommandResultSingleton::~VoiceCommandResultSingleton() 
	{
	
	}

	void VoiceCommandResultSingleton::NewInstance()
	{
		m_instance = std::shared_ptr<VoiceCommandResultSingleton> (new VoiceCommandResultSingleton());
	}

	VoiceCommandResultSingleton& VoiceCommandResultSingleton::GetInstance()
	{
		std::call_once(m_once_init, &VoiceCommandResultSingleton::NewInstance);
		return *m_instance;
	}

	void VoiceCommandResultSingleton::SetData(const hstring& cmdStr, WinRTDLLObserver::PODData const& myData)
	{
		m_myData = myData;
		(*m_Listners[cmdStr])(cmdStr, m_myData);
	}

	WinRTDLLObserver::EventToken  VoiceCommandResultSingleton::AddEventHandler(const hstring& cmdStr, WinRTDLLObserver::UpdateOnDataChange & handler)
	{
		if (m_Listners.find(cmdStr) != m_Listners.end())
		{
			return WinRTDLLObserver::EventToken(m_Listners[cmdStr]->add(handler).value);
		}
		else
		{
			m_Listners[cmdStr] = new winrt::event<WinRTDLLObserver::UpdateOnDataChange > {};

			return WinRTDLLObserver::EventToken(m_Listners[cmdStr]->add(handler).value);
		}
	}

	void VoiceCommandResultSingleton::RemoveEventHandler(const hstring& cmdStr, const WinRTDLLObserver::EventToken& token_value)
	{
		event_token eToken;
		eToken.value = token_value.token_value();
		if (m_Listners.find(cmdStr) != m_Listners.end())
		{
			m_Listners[cmdStr]->remove(eToken);
		}
	}

}
