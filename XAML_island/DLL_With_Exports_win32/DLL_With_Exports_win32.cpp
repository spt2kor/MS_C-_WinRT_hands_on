// DLL_With_Exports_win32.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "DLL_With_Exports_win32.h"


// This is an example of an exported variable
DLLWITHEXPORTSWIN32_API int nDLLWithExportswin32=101;

VoiceData CDLLWithExportswin32::m_data;

// This is an example of an exported function.
DLLWITHEXPORTSWIN32_API int fnDLLWithExportswin32(void)
{
    return 108;
}

// This is the constructor of a class that has been exported.
CDLLWithExportswin32::CDLLWithExportswin32()
{
    return;
}



DLLWITHEXPORTSWIN32_API void NotifyOnDataChange(const VoiceData& data)
{
    CDLLWithExportswin32::m_data = data;
}
