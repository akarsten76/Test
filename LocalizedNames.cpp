#include "stdafx.h"
#include "LocalizedNames.h"

#pragma warning(push)
#pragma warning(disable: 4566) // cannot be represented in the current code page

namespace LocalizedNames
{
	void InitLanguageMaps();

	CString GetMixedLanguageName(const CString& sAbbr);
	CString GetMixedLanguageAbbr(const CString& sMixedName);
	CString MakeUpper(CString s) { return s.MakeUpper(); }

	CMapStringToString mapAbbrToLangName;
	CMap<CString, LPCTSTR, int, int> mapAbbrToLCID, mapAbbrToCodePage;
	CMap<int, int, CString, const CString&> mapLCIDToAbbr;
}

void LocalizedNames::InitLanguageMaps()
{
	static bool bDone = false;
	if (bDone)
		return;

	// die Originalnamen in jeweiliger Sprache mappen
	mapAbbrToLangName.SetAt(L"DE", L"Deutsch");
	mapAbbrToLangName.SetAt(L"EN", L"English");
	mapAbbrToLangName.SetAt(L"IT", L"Italiano");
	mapAbbrToLangName.SetAt(L"HR", L"Hrvatski");
	mapAbbrToLangName.SetAt(L"NL", L"Nederlands");
	mapAbbrToLangName.SetAt(L"FR", L"Français");
	mapAbbrToLangName.SetAt(L"DA", L"Dansk");              // Dänisch
	mapAbbrToLangName.SetAt(L"PL", L"Polski");
	mapAbbrToLangName.SetAt(L"HU", L"Magyar");             // Ungarisch
	mapAbbrToLangName.SetAt(L"FL", L"Vlaams");             // Flämisch
	mapAbbrToLangName.SetAt(L"EL", L"Ελληνικά");           // Griechisch
	mapAbbrToLangName.SetAt(L"ES", L"Español");
	mapAbbrToLangName.SetAt(L"TR", L"Türkçe");
	mapAbbrToLangName.SetAt(L"CZ", L"Česky");              // Tschechisch
	mapAbbrToLangName.SetAt(L"RU", L"Русский");            // Russisch
	mapAbbrToLangName.SetAt(L"UA", L"Українська");         // Ukrainisch
	mapAbbrToLangName.SetAt(L"SQ", L"Shqip");              // Albanisch
	mapAbbrToLangName.SetAt(L"BG", L"Български");          // Bulgarisch
	mapAbbrToLangName.SetAt(L"ET", L"Eesti");              // Estnisch
	mapAbbrToLangName.SetAt(L"FI", L"Suomi");              // Finnisch
	mapAbbrToLangName.SetAt(L"LV", L"Latviešu");           // Lettisch
	mapAbbrToLangName.SetAt(L"LT", L"Lietuvių");           // Litauisch
	mapAbbrToLangName.SetAt(L"PT", L"Português");          // Portugisisch
	mapAbbrToLangName.SetAt(L"RO", L"Română");             // Rumänisch
	mapAbbrToLangName.SetAt(L"SV", L"Svenska");            // Schwedisch
	mapAbbrToLangName.SetAt(L"SR", L"Српски");             // Serbisch
	mapAbbrToLangName.SetAt(L"SK", L"Slovenčina");         // Slowakisch
	mapAbbrToLangName.SetAt(L"SL", L"Slovenščina");        // Slowenisch
	mapAbbrToLangName.SetAt(L"NO", L"Norsk (bokmål)");     // Norwegisch
	mapAbbrToLangName.SetAt(L"BS", L"Bosansky");           // Bosnisch

	// Sprachekürzel zu LCID
	mapAbbrToLCID.SetAt(L"BG", 0x0402);
	mapAbbrToLCID.SetAt(L"CZ", 0x0405);
	mapAbbrToLCID.SetAt(L"DA", 0x0406);
	mapAbbrToLCID.SetAt(L"DE", 0x0407);
	mapAbbrToLCID.SetAt(L"EL", 0x0408);
	mapAbbrToLCID.SetAt(L"EN", 0x0409);
	mapAbbrToLCID.SetAt(L"ES", 0x040a);
	mapAbbrToLCID.SetAt(L"FI", 0x040b);
	mapAbbrToLCID.SetAt(L"FR", 0x040c);
	mapAbbrToLCID.SetAt(L"HU", 0x040e);
	mapAbbrToLCID.SetAt(L"IT", 0x0410);
	mapAbbrToLCID.SetAt(L"NL", 0x0413);
	mapAbbrToLCID.SetAt(L"PL", 0x0415);
	mapAbbrToLCID.SetAt(L"RO", 0x0418);
	mapAbbrToLCID.SetAt(L"RU", 0x0419);
	mapAbbrToLCID.SetAt(L"HR", 0x041a);
	mapAbbrToLCID.SetAt(L"SK", 0x041b);
	mapAbbrToLCID.SetAt(L"SQ", 0x041c);
	mapAbbrToLCID.SetAt(L"SV", 0x041d);
	mapAbbrToLCID.SetAt(L"TR", 0x041f);
	mapAbbrToLCID.SetAt(L"SL", 0x0424);
	mapAbbrToLCID.SetAt(L"ET", 0x0425);
	mapAbbrToLCID.SetAt(L"LV", 0x0426);
	mapAbbrToLCID.SetAt(L"LT", 0x0427);
	mapAbbrToLCID.SetAt(L"FL", 0x0813);
	mapAbbrToLCID.SetAt(L"NO", 0x0814);
	mapAbbrToLCID.SetAt(L"PT", 0x0816);
	mapAbbrToLCID.SetAt(L"SR", 0x081a); // Serbian (Serbia, Latin)

	// LCID zu Sprachkürzel
	for (const CMap<CString, LPCTSTR, int, int>::CPair* p = mapAbbrToLCID.PGetFirstAssoc(); p; p = mapAbbrToLCID.PGetNextAssoc(p))
	{
		mapLCIDToAbbr.SetAt(p->value, p->key);
	}

	mapLCIDToAbbr.SetAt(0xc1a, L"SR"); // Serbian (Serbia, Cyrillic)

	// Sprache zu CodePage
	mapAbbrToCodePage.SetAt(L"DE", 1252);
	mapAbbrToCodePage.SetAt(L"EN", 1252);
	mapAbbrToCodePage.SetAt(L"FR", 1252);
	mapAbbrToCodePage.SetAt(L"RU", 1251);
	mapAbbrToCodePage.SetAt(L"IT", 1252);
	mapAbbrToCodePage.SetAt(L"NL", 1252);
	mapAbbrToCodePage.SetAt(L"ES", 1252); // Spanisch
	mapAbbrToCodePage.SetAt(L"CZ", 1250); // Tschechisch
	mapAbbrToCodePage.SetAt(L"HU", 1250); // Ungarisch
	mapAbbrToCodePage.SetAt(L"TR", 1254);
	mapAbbrToCodePage.SetAt(L"PL", 1250);
	mapAbbrToCodePage.SetAt(L"UK", 1252);
	mapAbbrToCodePage.SetAt(L"FL", 1252);
	mapAbbrToCodePage.SetAt(L"NO", 1252); // Norwegisch
	mapAbbrToCodePage.SetAt(L"EL", 1253); // Griechisch
	mapAbbrToCodePage.SetAt(L"PT", 1252); // Portugiesisch
	mapAbbrToCodePage.SetAt(L"RO", 1250); // Rumänisch
	mapAbbrToCodePage.SetAt(L"SV", 1252); // Schwedisch
	mapAbbrToCodePage.SetAt(L"SR", 1251); // Serbisch (kyrillisch)
	mapAbbrToCodePage.SetAt(L"SK", 1252); // Slowakisch
	mapAbbrToCodePage.SetAt(L"SL", 1252); // Slowenisch
	mapAbbrToCodePage.SetAt(L"SQ", 1250); // Albanisch
	mapAbbrToCodePage.SetAt(L"ET", 1257); // Estnisch
	mapAbbrToCodePage.SetAt(L"FI", 1252); // Finnisch
	mapAbbrToCodePage.SetAt(L"BG", 1251); // Bulgarisch
	mapAbbrToCodePage.SetAt(L"DA", 1252); // Dänisch
	mapAbbrToCodePage.SetAt(L"HR", 1250); // Kroatisch
	mapAbbrToCodePage.SetAt(L"LV", 1257); // Lettisch
	mapAbbrToCodePage.SetAt(L"LT", 1257); // Litauisch
	mapAbbrToCodePage.SetAt(L"BS", 1250); // Bosnisch (nicht kyrillisches Bosnisch)

	bDone = true;
}

CString LocalizedNames::GetLanguageName(const CString& sAbbr, BOOL bMixed)
{
	if (bMixed)
		return GetMixedLanguageName(sAbbr);

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

	ASSERT(FALSE);
	return L"";
}

CString LocalizedNames::GetLanguageAbbr(const CString& sName, BOOL bMixed)
{
	if (bMixed)
		return GetMixedLanguageAbbr(sName);

	InitLanguageMaps();

	for (const CMapStringToString::CPair* p = mapAbbrToLangName.PGetFirstAssoc(); p; p = mapAbbrToLangName.PGetNextAssoc(p))
	{
		if (p->value == sName)
			return p->key;
	}

	ASSERT(FALSE);
	return L"";
}

CString LocalizedNames::GetLanguageAbbr(WORD nLCID)
{
	InitLanguageMaps();

	CString sAbbr;
	VERIFY(mapLCIDToAbbr.Lookup(nLCID, sAbbr));
	return sAbbr;
}

int LocalizedNames::GetLCID(const CString& sAbbr)
{
	InitLanguageMaps();

	int nLCID = -1;
	VERIFY(mapAbbrToLCID.Lookup(MakeUpper(sAbbr), nLCID));
	return nLCID;
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
	InitLanguageMaps();

	int nCP = -1;
	VERIFY(mapAbbrToCodePage.Lookup(MakeUpper(sAbbr), nCP));
	return nCP;
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

	ASSERT(FALSE);
	return sKey;
}

CString LocalizedNames::GetMixedLanguageName(const CString& sAbbr)
{
	InitLanguageMaps();

	CString sName;
	VERIFY(mapAbbrToLangName.Lookup(MakeUpper(sAbbr), sName));
	CString sTrName = GetLanguageName(sAbbr, FALSE);

	if (sName == sTrName)
		return sName;

	CString sMixedName;
	sMixedName.Format(L"%s (%s)", sName, sTrName);
	return sMixedName;
}

CString LocalizedNames::GetMixedLanguageAbbr(const CString& sMixedName)
{
	InitLanguageMaps();

	CString sAbbr;
	int ind = sMixedName.Find(L' ');
	if (ind < 0)
		ind = sMixedName.GetLength();

	CString sLangName = sMixedName.Left(ind);

	for (const CMapStringToString::CPair* p = mapAbbrToLangName.PGetFirstAssoc(); p; p = mapAbbrToLangName.PGetNextAssoc(p))
	{
		if (p->value == sLangName)
			return p->key;
	}

	ASSERT(FALSE);
	return L"";
}

#pragma warning(pop)
