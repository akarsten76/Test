#pragma once

// Einige RegUtil-Funktionen wurden hierhin ausgelagert, damit die Excel-Tabelle von jedem Modul
// nicht unnötig mit _TR-Makros zugemüllt wird.

namespace LocalizedNames
{
	// Die Funktionen liefern nicht mehr bool zurück sondern CString, 
	// um Einzeiler zu ermöglichen. Ein leerer String ist als false zu interpretieren.
	// Mixed heisst Original + Übersetzung
	COMMDLL_API CString GetLanguageName(const CString& sAbbr, bool bMixed = true);
	COMMDLL_API CString GetLanguageAbbr(const CString& sName, bool bMixed = true);
	COMMDLL_API CString GetLanguageAbbr(WORD nLCode);
	COMMDLL_API CString GetRegionAbbr(WORD nLCode);
	COMMDLL_API WORD    GetSystemLCID();
	COMMDLL_API int     GetLCID(const CString& sAbbr);
	COMMDLL_API int     GetLanguageCodepage(const CString& sAbbr);
	COMMDLL_API CString GetRegionName(const CString& sAbbr);
}
