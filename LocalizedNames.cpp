#include "stdafx.h"
#include "LocalizedNames.h"
#include <map>

#pragma warning(push)
#pragma warning(disable: 4566) // cannot be represented in the current code page

LocalizedNames& LocalizedNames::GetInstance()
{
	static LocalizedNames instance;
	return instance;
}

LocalizedNames::LocalizedNames()
{
	// die Originalnamen in jeweiliger Sprache mappen
	m_mapAbbrToLangName[L"DE"] = L"Deutsch";
	m_mapAbbrToLangName[L"EN"] = L"English";
	m_mapAbbrToLangName[L"IT"] = L"Italiano";
	m_mapAbbrToLangName[L"HR"] = L"Hrvatski";
	m_mapAbbrToLangName[L"NL"] = L"Nederlands";
	m_mapAbbrToLangName[L"FR"] = L"Français";
	m_mapAbbrToLangName[L"DA"] = L"Dansk";              // Dänisch
	m_mapAbbrToLangName[L"PL"] = L"Polski";
	m_mapAbbrToLangName[L"HU"] = L"Magyar";             // Ungarisch
	m_mapAbbrToLangName[L"FL"] = L"Vlaams";             // Flämisch
	m_mapAbbrToLangName[L"EL"] = L"Ελληνικά";           // Griechisch
	m_mapAbbrToLangName[L"ES"] = L"Español";
	m_mapAbbrToLangName[L"TR"] = L"Türkçe";
	m_mapAbbrToLangName[L"CZ"] = L"Česky";              // Tschechisch
	m_mapAbbrToLangName[L"RU"] = L"Русский";            // Russisch
	m_mapAbbrToLangName[L"UA"] = L"Українська";         // Ukrainisch
	m_mapAbbrToLangName[L"SQ"] = L"Shqip";              // Albanisch
	m_mapAbbrToLangName[L"BG"] = L"Български";          // Bulgarisch
	m_mapAbbrToLangName[L"ET"] = L"Eesti";              // Estnisch
	m_mapAbbrToLangName[L"FI"] = L"Suomi";              // Finnisch
	m_mapAbbrToLangName[L"LV"] = L"Latviešu";           // Lettisch
	m_mapAbbrToLangName[L"LT"] = L"Lietuvių";           // Litauisch
	m_mapAbbrToLangName[L"PT"] = L"Português";          // Portugisisch
	m_mapAbbrToLangName[L"RO"] = L"Română";             // Rumänisch
	m_mapAbbrToLangName[L"SV"] = L"Svenska";            // Schwedisch
	m_mapAbbrToLangName[L"SR"] = L"Српски";             // Serbisch
	m_mapAbbrToLangName[L"SK"] = L"Slovenčina";         // Slowakisch
	m_mapAbbrToLangName[L"SL"] = L"Slovenščina";        // Slowenisch
	m_mapAbbrToLangName[L"NO"] = L"Norsk (bokmål)";     // Norwegisch
	m_mapAbbrToLangName[L"BS"] = L"Bosansky";           // Bosnisch

	// Sprachekürzel zu LCID
	m_mapAbbrToLCID[L"BG"] = 0x0402;
	m_mapAbbrToLCID[L"CZ"] = 0x0405;
	m_mapAbbrToLCID[L"DA"] = 0x0406;
	m_mapAbbrToLCID[L"DE"] = 0x0407;
	m_mapAbbrToLCID[L"EL"] = 0x0408;
	m_mapAbbrToLCID[L"EN"] = 0x0409;
	m_mapAbbrToLCID[L"ES"] = 0x040a;
	m_mapAbbrToLCID[L"FI"] = 0x040b;
	m_mapAbbrToLCID[L"FR"] = 0x040c;
	m_mapAbbrToLCID[L"HU"] = 0x040e;
	m_mapAbbrToLCID[L"IT"] = 0x0410;
	m_mapAbbrToLCID[L"NL"] = 0x0413;
	m_mapAbbrToLCID[L"PL"] = 0x0415;
	m_mapAbbrToLCID[L"RO"] = 0x0418;
	m_mapAbbrToLCID[L"RU"] = 0x0419;
	m_mapAbbrToLCID[L"HR"] = 0x041a;
	m_mapAbbrToLCID[L"SK"] = 0x041b;
	m_mapAbbrToLCID[L"SQ"] = 0x041c;
	m_mapAbbrToLCID[L"SV"] = 0x041d;
	m_mapAbbrToLCID[L"TR"] = 0x041f;
	m_mapAbbrToLCID[L"SL"] = 0x0424;
	m_mapAbbrToLCID[L"ET"] = 0x0425;
	m_mapAbbrToLCID[L"LV"] = 0x0426;
	m_mapAbbrToLCID[L"LT"] = 0x0427;
	m_mapAbbrToLCID[L"FL"] = 0x0813;
	m_mapAbbrToLCID[L"NO"] = 0x0814;
	m_mapAbbrToLCID[L"PT"] = 0x0816;
	m_mapAbbrToLCID[L"SR"] = 0x081a; // Serbian (Serbia, Latin)

	// LCID zu Sprachkürzel
	for (const auto& [abbr, lcid] : m_mapAbbrToLCID)
	{
		m_mapLCIDToAbbr[lcid] = abbr;
	}

	m_mapLCIDToAbbr[0xc1a] = L"SR"; // Serbian (Serbia, Cyrillic)

	// Sprache zu CodePage
	m_mapAbbrToCodePage[L"DE"] = 1252;
	m_mapAbbrToCodePage[L"EN"] = 1252;
	m_mapAbbrToCodePage[L"FR"] = 1252;
	m_mapAbbrToCodePage[L"RU"] = 1251;
	m_mapAbbrToCodePage[L"IT"] = 1252;
	m_mapAbbrToCodePage[L"NL"] = 1252;
	m_mapAbbrToCodePage[L"ES"] = 1252; // Spanisch
	m_mapAbbrToCodePage[L"CZ"] = 1250; // Tschechisch
	m_mapAbbrToCodePage[L"HU"] = 1250; // Ungarisch
	m_mapAbbrToCodePage[L"TR"] = 1254;
	m_mapAbbrToCodePage[L"PL"] = 1250;
	m_mapAbbrToCodePage[L"UK"] = 1252;
	m_mapAbbrToCodePage[L"FL"] = 1252;
	m_mapAbbrToCodePage[L"NO"] = 1252; // Norwegisch
	m_mapAbbrToCodePage[L"EL"] = 1253; // Griechisch
	m_mapAbbrToCodePage[L"PT"] = 1252; // Portugiesisch
	m_mapAbbrToCodePage[L"RO"] = 1250; // Rumänisch
	m_mapAbbrToCodePage[L"SV"] = 1252; // Schwedisch
	m_mapAbbrToCodePage[L"SR"] = 1251; // Serbisch (kyrillisch)
	m_mapAbbrToCodePage[L"SK"] = 1252; // Slowakisch
	m_mapAbbrToCodePage[L"SL"] = 1252; // Slowenisch
	m_mapAbbrToCodePage[L"SQ"] = 1250; // Albanisch
	m_mapAbbrToCodePage[L"ET"] = 1257; // Estnisch
	m_mapAbbrToCodePage[L"FI"] = 1252; // Finnisch
	m_mapAbbrToCodePage[L"BG"] = 1251; // Bulgarisch
	m_mapAbbrToCodePage[L"DA"] = 1252; // Dänisch
	m_mapAbbrToCodePage[L"HR"] = 1250; // Kroatisch
	m_mapAbbrToCodePage[L"LV"] = 1257; // Lettisch
	m_mapAbbrToCodePage[L"LT"] = 1257; // Litauisch
	m_mapAbbrToCodePage[L"BS"] = 1250; // Bosnisch (nicht kyrillisches Bosnisch)
}

CString LocalizedNames::GetLanguageName(const CString& sAbbr, bool bMixed)
{
	if (bMixed)
		return GetInstance().GetMixedLanguageName(sAbbr);

	// Werte nicht in InitLanguageMaps mappen.
	CString sKey = MakeUpper(sAbbr);

	// die übersetzten Sprachennamen in der gerade eingestellten Sprache mappen
	if (sKey == L"DE") return _TR(L"Deutsch");
	if (sKey == L"EN") return _TR(L"Englisch");
	if (sKey == L"IT") return _TR(L"Italienisch");
	if (sKey == L"HR") return _TR(L"Kroatisch");
	if (sKey == L"NL") return _TR(L"Niederländisch");
	if (sKey == L"FR") return _TR(L"Französisch");
	if (sKey == L"DA") return _TR(L"Dänisch");
	if (sKey == L"PL") return _TR(L"Polnisch");
	if (sKey == L"HU") return _TR(L"Ungarisch");
	if (sKey == L"FL") return _TR(L"Flämisch");
	if (sKey == L"EL") return _TR(L"Griechisch");
	if (sKey == L"ES") return _TR(L"Spanisch");
	if (sKey == L"TR") return _TR(L"Türkisch");
	if (sKey == L"CZ") return _TR(L"Tschechisch");
	if (sKey == L"RU") return _TR(L"Russisch");
	if (sKey == L"UA") return _TR(L"Ukrainisch");
	if (sKey == L"SQ") return _TR(L"Albanisch");
	if (sKey == L"BG") return _TR(L"Bulgarisch");
	if (sKey == L"ET") return _TR(L"Estnisch");
	if (sKey == L"FI") return _TR(L"Finnisch");
	if (sKey == L"LV") return _TR(L"Lettisch");
	if (sKey == L"LT") return _TR(L"Litauisch");
	if (sKey == L"PT") return _TR(L"Portugiesisch");
	if (sKey == L"RO") return _TR(L"Rumänisch");
	if (sKey == L"SV") return _TR(L"Schwedisch");
	if (sKey == L"SR") return _TR(L"Serbisch");
	if (sKey == L"SK") return _TR(L"Slowakisch");
	if (sKey == L"SL") return _TR(L"Slowenisch");
	if (sKey == L"NO") return _TR(L"Norwegisch");
	if (sKey == L"BS") return _TR(L"Bosnisch");

	ASSERT(false);
	return L"";
}

CString LocalizedNames::GetLanguageAbbr(const CString& sName, bool bMixed)
{
	if (bMixed)
		return GetInstance().GetMixedLanguageAbbr(sName);

	LocalizedNames& inst = GetInstance();

	for (const auto& [key, value] : inst.m_mapAbbrToLangName)
	{
		if (value == sName)
			return key;
	}

	ASSERT(false);
	return L"";
}

CString LocalizedNames::GetLanguageAbbr(WORD nLCID)
{
	LocalizedNames& inst = GetInstance();

	auto it = inst.m_mapLCIDToAbbr.find(nLCID);
	ASSERT(it != inst.m_mapLCIDToAbbr.end());
	return (it != inst.m_mapLCIDToAbbr.end()) ? it->second : CString();
}

int LocalizedNames::GetLCID(const CString& sAbbr)
{
	LocalizedNames& inst = GetInstance();

	auto it = inst.m_mapAbbrToLCID.find(MakeUpper(sAbbr));
	ASSERT(it != inst.m_mapAbbrToLCID.end());
	return (it != inst.m_mapAbbrToLCID.end()) ? it->second : -1;
}

WORD LocalizedNames::GetSystemLCID()
{
	// Language id des Betriebsystems ermitteln.
	TCHAR LCData[1024] = L"";
	UINT nLCode = 0;
	GetLocaleInfo(LOCALE_SYSTEM_DEFAULT, LOCALE_IDEFAULTLANGUAGE, &LCData[0], sizeof(LCData));
	_stscanf_s(LCData, L"%X", &nLCode);
	return (WORD)nLCode;
}

CString LocalizedNames::GetRegionAbbr(WORD nLCode)
{
	CString sRegionAbbr;

	// eine passende Region zu LCID auswählen.
	switch (nLCode)
	{
		case 0x0407: sRegionAbbr = L"DEU";break;
		case 0x0409: sRegionAbbr = L"INT";break; // England
		case 0x0405: sRegionAbbr = L"CZE";break;
		case 0x040c: sRegionAbbr = L"FRA";break;
		case 0x0410: sRegionAbbr = L"ITA";break;
		case 0x0413: sRegionAbbr = L"NED";break;
		case 0x0415: sRegionAbbr = L"POL";break;
		case 0x0419: sRegionAbbr = L"RUS";break;
		case 0x041f: sRegionAbbr = L"TUR";break;
		case 0x040e: sRegionAbbr = L"HUN";break;
		default:     sRegionAbbr = L"INT";
	}

	return sRegionAbbr;
}

int LocalizedNames::GetLanguageCodepage(const CString& sAbbr)
{
	LocalizedNames& inst = GetInstance();

	auto it = inst.m_mapAbbrToCodePage.find(MakeUpper(sAbbr));
	ASSERT(it != inst.m_mapAbbrToCodePage.end());
	return (it != inst.m_mapAbbrToCodePage.end()) ? it->second : -1;
}

CString LocalizedNames::GetRegionName(const CString& sAbbr)
{
	// Werte nicht in InitLanguageMaps mappen.
	CString sKey = MakeUpper(sAbbr);

	// der Häufigkeit nach sortiert, der Perfomance wegen
	if (sKey == L"DEU") return _TR(L"Deutschland");
	if (sKey == L"INT") return _TR(L"International");
	if (sKey == L"XXX") return _TR(L"Nicht spezifiziert");
	if (sKey == L"OES") return _TR(L"Österreich");
	if (sKey == L"NED") return _TR(L"Niederlande");
	if (sKey == L"FRA") return _TR(L"Frankreich");
	if (sKey == L"ITA") return _TR(L"Italien");
	if (sKey == L"ENU") return _TR(L"England");
	if (sKey == L"RUS") return _TR(L"Russland");
	if (sKey == L"POL") return _TR(L"Polen");
	if (sKey == L"BEL") return _TR(L"Belgien");
	if (sKey == L"HUN") return _TR(L"Ungarn");
	if (sKey == L"TUR") return _TR(L"Türkei");
	if (sKey == L"GRE") return _TR(L"Griechenland");
	if (sKey == L"CZE") return _TR(L"Tschechien");
	if (sKey == L"CHE") return _TR(L"Schweiz");
	if (sKey == L"CHD") return _TR(L"Schweiz (deutsch)");
	if (sKey == L"CHF") return _TR(L"Schweiz (französisch)");
	if (sKey == L"ESP") return _TR(L"Spanien");
	if (sKey == L"ISL") return _TR(L"Island");
	if (sKey == L"CRO") return _TR(L"Kroatien");
	if (sKey == L"ROM") return _TR(L"Rumänien");
	if (sKey == L"LAT") return _TR(L"Lettland");
	if (sKey == L"LTU") return _TR(L"Litauen");
	if (sKey == L"USA") return _TR(L"USA");
	if (sKey == L"GBR") return _TR(L"Großbritannien");
	if (sKey == L"POR") return _TR(L"Portugal");
	if (sKey == L"LUX") return _TR(L"Luxemburg");
	if (sKey == L"BIH") return _TR(L"Bosnien und Herzegowina");
	if (sKey == L"BGR") return _TR(L"Bulgarien");
	if (sKey == L"MDA") return _TR(L"Moldawien");
	if (sKey == L"SRB") return _TR(L"Serbien");
	if (sKey == L"UKR") return _TR(L"Ukraine");
	if (sKey == L"BLR") return _TR(L"Weißrussland");
	if (sKey == L"KAZ") return _TR(L"Kasachstan");
	if (sKey == L"SLO") return _TR(L"Slowenien");
	if (sKey == L"SLK") return _TR(L"Slowakei");
	if (sKey == L"AUS") return _TR(L"Australien");
	if (sKey == L"CHN") return _TR(L"China");
	if (sKey == L"AME") return L"Americas"; // kein _TR
	if (sKey == L"APA") return L"Asia / Pacific";
	if (sKey == L"MEA") return L"Middle East";
	if (sKey == L"EUR") return L"Europe";
	if (sKey == L"GLB") return L"Global"; // kein _TR
	if (sKey == L"UKD") return L"United Kingdom"; // richtig ist GBR

	ASSERT(false);
	return sKey;
}

CString LocalizedNames::GetMixedLanguageName(const CString& sAbbr)
{
	auto it = m_mapAbbrToLangName.find(MakeUpper(sAbbr));
	ASSERT(it != m_mapAbbrToLangName.end());
	if (it == m_mapAbbrToLangName.end())
		return CString();
	CString sName = it->second;
	CString sTrName = GetLanguageName(sAbbr, false);

	if (sName == sTrName)
		return sName;

	CString sMixedName;
	sMixedName.Format(L"%s (%s)", sName, sTrName);
	return sMixedName;
}

CString LocalizedNames::GetMixedLanguageAbbr(const CString& sMixedName)
{
	CString sAbbr;
	int ind = sMixedName.Find(L' ');
	if (ind < 0)
		ind = sMixedName.GetLength();

	CString sLangName = sMixedName.Left(ind);

	for (const auto& [key, value] : m_mapAbbrToLangName)
	{
		if (value == sLangName)
			return key;
	}

	ASSERT(false);
	return L"";
}

#pragma warning(pop)
