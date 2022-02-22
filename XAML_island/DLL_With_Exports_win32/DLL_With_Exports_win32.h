// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLLWITHEXPORTSWIN32_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLLWITHEXPORTSWIN32_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLWITHEXPORTSWIN32_EXPORTS
#define DLLWITHEXPORTSWIN32_API __declspec(dllexport)
#else
#define DLLWITHEXPORTSWIN32_API __declspec(dllimport)
#endif

#include <iostream>
using namespace std;

////////////////////////////////////
// This class is exported from the dll
struct DLLWITHEXPORTSWIN32_API VoiceData {
    wstring _msg;
    wstring _value;
    int16_t _status;
};
DLLWITHEXPORTSWIN32_API void NotifyOnDataChange(const VoiceData& data);
////////////////////////////////////


// This class is exported from the dll
class DLLWITHEXPORTSWIN32_API CDLLWithExportswin32 {
public:
	CDLLWithExportswin32(void);

    static VoiceData m_data;
	// TODO: add your methods here.
};

extern DLLWITHEXPORTSWIN32_API int nDLLWithExportswin32;

DLLWITHEXPORTSWIN32_API int fnDLLWithExportswin32(void);
