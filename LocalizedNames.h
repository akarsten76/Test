#pragma once

// Einige RegUtil-Funktionen wurden hierhin ausgelagert, damit die Excel-Tabelle von jedem Modul
// nicht unnötig mit _TR-Makros zugemüllt wird.

class COMMDLL_API LocalizedNames
{
public:
	// Die Funktionen liefern nicht mehr bool zurück sondern CString,
	// um Einzeiler zu ermöglichen. Ein leerer String ist als false zu interpretieren.
	// Mixed heisst Original + Übersetzung
	static CString GetLanguageName(const CString& sAbbr, bool bMixed = true);
	static CString GetLanguageAbbr(const CString& sName, bool bMixed = true);
	static CString GetLanguageAbbr(WORD nLCode);
	static CString GetRegionAbbr(WORD nLCode);
	static WORD    GetSystemLCID();
	static int     GetLCID(const CString& sAbbr);
	static int     GetLanguageCodepage(const CString& sAbbr);
	static CString GetRegionName(const CString& sAbbr);

private:
	LocalizedNames();
	static LocalizedNames& GetInstance();

	CString GetMixedLanguageName(const CString& sAbbr);
	CString GetMixedLanguageAbbr(const CString& sMixedName);
	static CString MakeUpper(CString s) { return s.MakeUpper(); }

	std::map<CString, CString> m_mapAbbrToLangName;
	std::map<CString, int> m_mapAbbrToLCID, m_mapAbbrToCodePage;
	std::map<int, CString> m_mapLCIDToAbbr;
};
