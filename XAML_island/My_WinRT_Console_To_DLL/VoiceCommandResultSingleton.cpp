#include "pch.h"
#include "VoiceCommandResultSingleton.h"
#include "Logger.h"

namespace winrt::MyObserverUtil::implementation
{		
	VoiceCommandResultSingleton& VoiceCommandResultSingleton::GetInstance()
	{
		static VoiceCommandResultSingleton theVoiceCommandResultSingleton{};
		return theVoiceCommandResultSingleton;
	}

	void VoiceCommandResultSingleton::SetData(const hstring& cmdStr, MyObserverUtil::PODData const& myData)
	{
		m_myData = myData;
		(*m_Listners[cmdStr])(cmdStr, m_myData);
	}

	int16_t VoiceCommandResultSingleton::AddEventHandler(const hstring& cmdStr, MyObserverUtil::UpdateOnDataChange & handler)
	{
		if (m_Listners.find(cmdStr) != m_Listners.end())
		{
			//m_ListnersTokens[reinterpret_cast<void*>(&handler)] = 
				m_Listners[cmdStr]->add(handler);
		}
		else
		{
			m_Listners[cmdStr] = new winrt::event<MyObserverUtil::UpdateOnDataChange > {};

			//m_ListnersTokens[reinterpret_cast<void*>(&handler)] = 
				m_Listners[cmdStr]->add(handler);
		}
		return 1;
	}

	int16_t VoiceCommandResultSingleton::RemoveEventHandler(const hstring& cmdStr, MyObserverUtil::UpdateOnDataChange & handler)
	{
		//if(m_ListnersTokens.find(reinterpret_cast<void*>(&handler)) != m_ListnersTokens.end())
		{
			if (m_Listners.find(cmdStr) != m_Listners.end())
			{
				//m_Listners[cmdStr]->remove(m_ListnersTokens[reinterpret_cast<void*>(&handler)]);
				return 1;
			}
			else
			{
				return 0;
			}
		}
		return 0;		
	}

}
