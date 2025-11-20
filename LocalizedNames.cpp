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
	mapAbbrToLangName[L"DE"] = L"Deutsch";
	mapAbbrToLangName[L"EN"] = L"English";
	mapAbbrToLangName[L"IT"] = L"Italiano";
	mapAbbrToLangName[L"HR"] = L"Hrvatski";
	mapAbbrToLangName[L"NL"] = L"Nederlands";
	mapAbbrToLangName[L"FR"] = L"Français";
	mapAbbrToLangName[L"DA"] = L"Dansk";              // Dänisch
	mapAbbrToLangName[L"PL"] = L"Polski";
	mapAbbrToLangName[L"HU"] = L"Magyar";             // Ungarisch
	mapAbbrToLangName[L"FL"] = L"Vlaams";             // Flämisch
	mapAbbrToLangName[L"EL"] = L"Ελληνικά";           // Griechisch
	mapAbbrToLangName[L"ES"] = L"Español";
	mapAbbrToLangName[L"TR"] = L"Türkçe";
	mapAbbrToLangName[L"CZ"] = L"Česky";              // Tschechisch
	mapAbbrToLangName[L"RU"] = L"Русский";            // Russisch
	mapAbbrToLangName[L"UA"] = L"Українська";         // Ukrainisch
	mapAbbrToLangName[L"SQ"] = L"Shqip";              // Albanisch
	mapAbbrToLangName[L"BG"] = L"Български";          // Bulgarisch
	mapAbbrToLangName[L"ET"] = L"Eesti";              // Estnisch
	mapAbbrToLangName[L"FI"] = L"Suomi";              // Finnisch
	mapAbbrToLangName[L"LV"] = L"Latviešu";           // Lettisch
	mapAbbrToLangName[L"LT"] = L"Lietuvių";           // Litauisch
	mapAbbrToLangName[L"PT"] = L"Português";          // Portugisisch
	mapAbbrToLangName[L"RO"] = L"Română";             // Rumänisch
	mapAbbrToLangName[L"SV"] = L"Svenska";            // Schwedisch
	mapAbbrToLangName[L"SR"] = L"Српски";             // Serbisch
	mapAbbrToLangName[L"SK"] = L"Slovenčina";         // Slowakisch
	mapAbbrToLangName[L"SL"] = L"Slovenščina";        // Slowenisch
	mapAbbrToLangName[L"NO"] = L"Norsk (bokmål)";     // Norwegisch
	mapAbbrToLangName[L"BS"] = L"Bosansky";           // Bosnisch

	// Sprachekürzel zu LCID
	mapAbbrToLCID[L"BG"] = 0x0402;
	mapAbbrToLCID[L"CZ"] = 0x0405;
	mapAbbrToLCID[L"DA"] = 0x0406;
	mapAbbrToLCID[L"DE"] = 0x0407;
	mapAbbrToLCID[L"EL"] = 0x0408;
	mapAbbrToLCID[L"EN"] = 0x0409;
	mapAbbrToLCID[L"ES"] = 0x040a;
	mapAbbrToLCID[L"FI"] = 0x040b;
	mapAbbrToLCID[L"FR"] = 0x040c;
	mapAbbrToLCID[L"HU"] = 0x040e;
	mapAbbrToLCID[L"IT"] = 0x0410;
	mapAbbrToLCID[L"NL"] = 0x0413;
	mapAbbrToLCID[L"PL"] = 0x0415;
	mapAbbrToLCID[L"RO"] = 0x0418;
	mapAbbrToLCID[L"RU"] = 0x0419;
	mapAbbrToLCID[L"HR"] = 0x041a;
	mapAbbrToLCID[L"SK"] = 0x041b;
	mapAbbrToLCID[L"SQ"] = 0x041c;
	mapAbbrToLCID[L"SV"] = 0x041d;
	mapAbbrToLCID[L"TR"] = 0x041f;
	mapAbbrToLCID[L"SL"] = 0x0424;
	mapAbbrToLCID[L"ET"] = 0x0425;
	mapAbbrToLCID[L"LV"] = 0x0426;
	mapAbbrToLCID[L"LT"] = 0x0427;
	mapAbbrToLCID[L"FL"] = 0x0813;
	mapAbbrToLCID[L"NO"] = 0x0814;
	mapAbbrToLCID[L"PT"] = 0x0816;
	mapAbbrToLCID[L"SR"] = 0x081a; // Serbian (Serbia, Latin)

	// LCID zu Sprachkürzel
	for (const auto& [abbr, lcid] : mapAbbrToLCID)
	{
		mapLCIDToAbbr[lcid] = abbr;
	}

	mapLCIDToAbbr[0xc1a] = L"SR"; // Serbian (Serbia, Cyrillic)

	// Sprache zu CodePage
	mapAbbrToCodePage[L"DE"] = 1252;
	mapAbbrToCodePage[L"EN"] = 1252;
	mapAbbrToCodePage[L"FR"] = 1252;
	mapAbbrToCodePage[L"RU"] = 1251;
	mapAbbrToCodePage[L"IT"] = 1252;
	mapAbbrToCodePage[L"NL"] = 1252;
	mapAbbrToCodePage[L"ES"] = 1252; // Spanisch
	mapAbbrToCodePage[L"CZ"] = 1250; // Tschechisch
	mapAbbrToCodePage[L"HU"] = 1250; // Ungarisch
	mapAbbrToCodePage[L"TR"] = 1254;
	mapAbbrToCodePage[L"PL"] = 1250;
	mapAbbrToCodePage[L"UK"] = 1252;
	mapAbbrToCodePage[L"FL"] = 1252;
	mapAbbrToCodePage[L"NO"] = 1252; // Norwegisch
	mapAbbrToCodePage[L"EL"] = 1253; // Griechisch
	mapAbbrToCodePage[L"PT"] = 1252; // Portugiesisch
	mapAbbrToCodePage[L"RO"] = 1250; // Rumänisch
	mapAbbrToCodePage[L"SV"] = 1252; // Schwedisch
	mapAbbrToCodePage[L"SR"] = 1251; // Serbisch (kyrillisch)
	mapAbbrToCodePage[L"SK"] = 1252; // Slowakisch
	mapAbbrToCodePage[L"SL"] = 1252; // Slowenisch
	mapAbbrToCodePage[L"SQ"] = 1250; // Albanisch
	mapAbbrToCodePage[L"ET"] = 1257; // Estnisch
	mapAbbrToCodePage[L"FI"] = 1252; // Finnisch
	mapAbbrToCodePage[L"BG"] = 1251; // Bulgarisch
	mapAbbrToCodePage[L"DA"] = 1252; // Dänisch
	mapAbbrToCodePage[L"HR"] = 1250; // Kroatisch
	mapAbbrToCodePage[L"LV"] = 1257; // Lettisch
	mapAbbrToCodePage[L"LT"] = 1257; // Litauisch
	mapAbbrToCodePage[L"BS"] = 1250; // Bosnisch (nicht kyrillisches Bosnisch)
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

	for (const auto& [key, value] : inst.mapAbbrToLangName)
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

	auto it = inst.mapLCIDToAbbr.find(nLCID);
	ASSERT(it != inst.mapLCIDToAbbr.end());
	return (it != inst.mapLCIDToAbbr.end()) ? it->second : CString();
}

int LocalizedNames::GetLCID(const CString& sAbbr)
{
	LocalizedNames& inst = GetInstance();

	auto it = inst.mapAbbrToLCID.find(MakeUpper(sAbbr));
	ASSERT(it != inst.mapAbbrToLCID.end());
	return (it != inst.mapAbbrToLCID.end()) ? it->second : -1;
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

	auto it = inst.mapAbbrToCodePage.find(MakeUpper(sAbbr));
	ASSERT(it != inst.mapAbbrToCodePage.end());
	return (it != inst.mapAbbrToCodePage.end()) ? it->second : -1;
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
	auto it = mapAbbrToLangName.find(MakeUpper(sAbbr));
	ASSERT(it != mapAbbrToLangName.end());
	if (it == mapAbbrToLangName.end())
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

	for (const auto& [key, value] : mapAbbrToLangName)
	{
		if (value == sLangName)
			return key;
	}

	ASSERT(false);
	return L"";
}

#pragma warning(pop)
