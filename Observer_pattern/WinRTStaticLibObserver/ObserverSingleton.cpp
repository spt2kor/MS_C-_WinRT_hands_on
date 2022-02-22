#include "pch.h"
#include "ObserverSingleton.h"
#include "Logger.h"


namespace winrt::WinRTStaticLibObserver
{		

	std::once_flag  ObserverSingleton::m_once_init;
	std::shared_ptr<ObserverSingleton> ObserverSingleton::m_instance{ nullptr };


	ObserverSingleton::ObserverSingleton()
	{
		g_fs.open("SingletonWinRTLib_log.txt", std::fstream::out);

		Log("starting ObserverSingleton CTOR");

	}

	ObserverSingleton::~ObserverSingleton()
	{
		slim_lock_guard const change_guard(m_mapChange);
		for (auto& itr : m_Listners)
		{
			Log(string(" DTOR remove : " + to_string(itr.first) ));
			itr.second.reset(); //will delete event object
		}
		m_Listners.clear();

		Log("closing ObserverSingleton DTOR");
		g_fs.close();
	}

	void ObserverSingleton::NewInstance()
	{
		Log(" Init Singleton: ");
		m_instance = std::shared_ptr<ObserverSingleton> (new ObserverSingleton());
	}

	ObserverSingleton& ObserverSingleton::GetInstance()
	{
		std::call_once(m_once_init, &ObserverSingleton::NewInstance);
		return *m_instance;
	}

	fire_and_forget ObserverSingleton::NotifyAsyn(hstring cmdStr, WinRTStaticLibObserver::PODData myData)
	{
		//create local copy first
		WinRTStaticLibObserver::implementation::PODData *pData = get_self<WinRTStaticLibObserver::implementation::PODData>(myData);

		com_ptr<WinRTStaticLibObserver::implementation::PODData> local_myData = make_self<WinRTStaticLibObserver::implementation::PODData>();

		*local_myData = *pData;
		//---------------------------------------------------------------------

		co_await resume_background();

		auto itr = m_Listners.find(cmdStr);
		if (itr != m_Listners.end())
		{

			( *( itr->second ) ) (cmdStr, *local_myData);

		}		
	}

	WinRTStaticLibObserver::EventToken  ObserverSingleton::AddEventHandler(const hstring& cmdStr, WinRTStaticLibObserver::UpdateOnDataChange const& handler)
	{
		auto itr = m_Listners.find(cmdStr);
		if (itr != m_Listners.end())
		{
			return WinRTStaticLibObserver::EventToken(itr->second->add(handler).value);
		}
		else
		{
			pair<EventMAP_ITR, bool> insertResPair;
			{
				slim_lock_guard const change_guard(m_mapChange);
				insertResPair = m_Listners.emplace(cmdStr, std::make_unique< winrt::event<WinRTStaticLibObserver::UpdateOnDataChange > >());
			}

			return WinRTStaticLibObserver::EventToken(insertResPair.first->second->add(handler).value);
		}
	}

	void ObserverSingleton::RemoveEventHandler(const hstring& cmdStr, const WinRTStaticLibObserver::EventToken& token_value)
	{
		event_token eToken;
		eToken.value = token_value.token_value();
		auto itr = m_Listners.find(cmdStr);
		if (itr != m_Listners.end())
		{
			itr->second->remove(eToken);
		}
		//Note: Dont remove from m_Listners.
	}

}
