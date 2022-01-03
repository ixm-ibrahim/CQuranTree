#include "Arabic.h"

using namespace Arabic;


///////////////////////////////////////////////////////////////////////////////
// Arabic 
///////////////////////////////////////////////////////////////////////////////


std::string Arabic::to_string(int ascii)
{
	switch (ascii)
	{
		// letters
		{
			case 32:
				return "SPACE";
			case 1600:
				return "TATWEEL";
			case 1569:
				return "HAMZAH";
			case 1570:
				return "ALIF with MADDAH";
			case 1571:
				return "ALIF with HAMZAH_ABOVE";
			case 1572:
				return "WAW with HAMZAH_ABOVE";
			case 1573:
				return "ALIF with HAMZAH_BELOW";
			case 1574:
				return "HAMZAH_MIDDLE";
			case 1575:
				return "ALIF";
			case 1576:
				return "BA";
			case 1577:
				return "TA MARBUTAH";
			case 1578:
				return "TA";
			case 1579:
				return "THA";
			case 1580:
				return "JEEM";
			case 1581:
				return "HHA";
			case 1582:
				return "KHA";
			case 1583:
				return "DAL";
			case 1584:
				return "DHAL";
			case 1585:
				return "RA";
			case 1586:
				return "ZAYN";
			case 1587:
				return "SEEN";
			case 1588:
				return "SHEEN";
			case 1589:
				return "SAD";
			case 1590:
				return "DAD";
			case 1591:
				return "TTA";
			case 1592:
				return "THHA";
			case 1593:
				return "AYN";
			case 1594:
				return "GHAYN";
			case 1601:
				return "FA";
			case 1602:
				return "QAF";
			case 1603:
				return "KAF";
			case 1604:
				return "LAM";
			case 1605:
				return "MEEM";
			case 1606:
				return "NOON";
			case 1607:
				return "HA";
			case 1608:
				return "WAW";
			case 1609:
				return "ALIF_MAQSURAH";
			case 1610:
				return "YA";
			case 1648:
				return "ALIF_KHANJARIYAH";
			case 1649:
				return "ALIF_WASLAH";
		}
		// diacritics
		{
			case 1611:
				return "TANWEEN_FATHAH";
			case 1612:
				return "TANWEEN_DAMMAH";
			case 1613:
				return "TANWEEN_KASRAH";
			case 1614:
				return "FATHAH";
			case 1615:
				return "DAMMAH";
			case 1616:
				return "KASRAH";
			case 1617:
				return "SHADDAH";
			case 1618:
				return "SUKOON";
			case 1619:
				return "MADDAH";
			case 1620:
				return "HAMZAH";
			case 1759:
				return "SUKOON_WASLAH";
			case 1760:
				return "SUKOON_ALIF";
			case 1763:
				return "SEEN_SUBSTITUTION";
			case 1765:
				return "SMALL_WAW";
			case 1766:
				return "SMALL_YA";
			case 1767:
				return "SMALL_YA_ABOVE";
			case 1768:
				return "DOUBLE_NOON";
			case 1770:
				return "GRAND_IMAALAH";
			case 1771:
				return "ISHMAAM";
			case 1772:
				return "TASHEEL";
		}
		// symbols
		{
			case 1750:
				return "GOOD_STOP";
			case 1751:
				return "SUFFICIENT_STOP";
			case 1752:
				return "COMPULSORY_STOP";
			case 1753:
				return "PROHIBITED_STOP";
			case 1754:
				return "EQUALITY_STOP";
			case 1755:
				return "PRECAUTIONARY_STOP";
			case 1756:
				return "BRIEF_STOP";
			case 1758:
				return "QUARTER_OF_HALF";
			case 1762:
				return "MEEM_IQLAB_ABOVE";
			case 1769:
				return "SAJDAH";
			case 1773:
				return "MEEM_IQLAB_BELOW";
		}
	}
	
	return "UNKNOWN";
}
std::string Arabic::to_string(Character* c)
{
	return to_string(c->GetASCII());
}

int Arabic::to_ascii(letter_t letter, modification_t modification)
{
	switch (letter)
	{
		case letter_t::HAMZAH:
			if (modification == modification_t::HAMZAH_MIDDLE)
				return 1574;
			return 1569;
		case letter_t::ALIF:
			if (modification == modification_t::MADDAH)
				return 1570;
			if (modification == modification_t::HAMZAH_ABOVE)
				return 1571;
			if (modification == modification_t::HAMZAH_BELOW)
				return 1573;
			if (modification == modification_t::KHANJARIYAH)
				return 1648;
			if (modification == modification_t::WASLAH)
				return 1649;
			return 1575;
		case letter_t::BA:
			return 1576;
		case letter_t::TA:
			if (modification == modification_t::MARBUTAH)
				return 1577;
			return 1578;
		case letter_t::THA:
			return 1579;
		case letter_t::JEEM:
			return 1580;
		case letter_t::HHA:
			return 1581;
		case letter_t::KHA:
			return 1582;
		case letter_t::DAL:
			return 1583;
		case letter_t::DHAL:
			return 1584;
		case letter_t::RA:
			return 1585;
		case letter_t::ZAYN:
			return 1586;
		case letter_t::SEEN:
			return 1587;
		case letter_t::SHEEN:
			return 1588;
		case letter_t::SAD:
			return 1589;
		case letter_t::DAD:
			return 1590;
		case letter_t::TTA:
			return 1591;
		case letter_t::THHA:
			return 1592;
		case letter_t::AYN:
			return 1593;
		case letter_t::GHAYN:
			return 1594;
		case letter_t::FA:
			return 1601;
		case letter_t::QAF:
			return 1602;
		case letter_t::KAF:
			return 1603;
		case letter_t::LAM:
			return 1604;
		case letter_t::MEEM:
			return 1605;
		case letter_t::NOON:
			return 1606;
		case letter_t::HA:
			return 1607;
		case letter_t::WAW:
			if (modification == modification_t::HAMZAH_ABOVE)
				return 1572;
			return 1608;
		case letter_t::YA:
			if (modification == modification_t::MAQSURAH)
				return 1609;
			return 1610;
	}

	return 0;
}
int Arabic::to_ascii(diacritic_t diacritic)
{
	switch (diacritic)
	{
		case diacritic_t::TANWEEN_FATHAH:
			return 1611;
		case diacritic_t::TANWEEN_DAMMAH:
			return 1612;
		case diacritic_t::TANWEEN_KASRAH:
			return 1613;
		case diacritic_t::FATHAH:
			return 1614;
		case diacritic_t::DAMMAH:
			return 1615;
		case diacritic_t::KASRAH:
			return 1616;
		case diacritic_t::SHADDAH:
			return 1617;
		case diacritic_t::SUKOON:
			return 1618;
		case diacritic_t::MADDAH:
			return 1619;
		case diacritic_t::HAMZAH:
			return 1620;
		case diacritic_t::SUKOON_WASLAH:
			return 1759;
		case diacritic_t::SUKOON_ALIF:
			return 1760;
		case diacritic_t::SEEN_SUBSTITUTION:
			return 1763;
		case diacritic_t::SMALL_WAW:
			return 1765;
		case diacritic_t::SMALL_YA:
			return 1766;
		case diacritic_t::SMALL_YA_ABOVE:
			return 1767;
		case diacritic_t::DOUBLE_NOON:
			return 1768;
		case diacritic_t::GRAND_IMAALAH:
			return 1770;
		case diacritic_t::ISHMAAM:
			return 1771;
		case diacritic_t::TASHEEL:
			return 1772;
	}

	return 0;
}
int Arabic::to_ascii(symbol_t symbol)
{
	switch (symbol)
	{
		case symbol_t::GOOD_STOP:
			return 1750;
		case symbol_t::SUFFICIENT_STOP:
			return 1751;
		case symbol_t::COMPULSORY_STOP:
			return 1752;
		case symbol_t::PROHIBITED_STOP:
			return 1753;
		case symbol_t::EQUALITY_STOP:
			return 1754;
		case symbol_t::PRECAUTIONARY_STOP:
			return 1755;
		case symbol_t::BRIEF_STOP:
			return 1756;
		case symbol_t::QUARTER_OF_HALF:
			return 1758;
		case symbol_t::MEEM_IQLAB_ABOVE:
			return 1762;
		case symbol_t::SAJDAH:
			return 1769;
		case symbol_t::MEEM_IQLAB_BELOW:
			return 1773;
	}

	return 0;
}

int Arabic::to_ascii(std::string hex)
{
	int n = 0;
	std::stringstream ss;
	ss << std::hex << hex;
	ss >> n;
	return n;
}
std::string Arabic::to_hex(int ascii)
{
	std::stringstream ss;
	ss << std::hex << ascii;
	return ss.str();
}

character_t Arabic::get_type(int ascii)
{
	if (is_letter(ascii))
		return character_t::LETTER;
	if (is_diacritic(ascii))
		return character_t::DIACRITIC;
	if (is_symbol(ascii))
		return character_t::SYMBOL;
	
	return character_t::UNKNOWN;
}

letter_t Arabic::get_letter(int ascii)
{
	if (is_letter(ascii))
		switch(ascii)
		{
			case 32:	// space
				break;
			case 1600:	// tatweel
				break;
			case 1569:
				return letter_t::HAMZAH;
			case 1570:	// alif with maddah
				return letter_t::ALIF;
			case 1571:	// alif with hamzah above
				return letter_t::ALIF;
			case 1572:	// waw with hamzah above
				return letter_t::WAW;
			case 1573:	// alif with hamzah below
				return letter_t::ALIF;
			case 1574:	// hamzah middle
				return letter_t::HAMZAH;
			case 1575:
				return letter_t::ALIF;
			case 1576:
				return letter_t::BA;
			case 1577:	// ta marbutah
				return letter_t::TA;
			case 1578:
				return letter_t::TA;
			case 1579:
				return letter_t::THA;
			case 1580:
				return letter_t::JEEM;
			case 1581:
				return letter_t::HHA;
			case 1582:
				return letter_t::KHA;
			case 1583:
				return letter_t::DAL;
			case 1584:
				return letter_t::DHAL;
			case 1585:
				return letter_t::RA;
			case 1586:
				return letter_t::ZAYN;
			case 1587:
				return letter_t::SEEN;
			case 1588:
				return letter_t::SHEEN;
			case 1589:
				return letter_t::SAD;
			case 1590:
				return letter_t::DAD;
			case 1591:
				return letter_t::TTA;
			case 1592:
				return letter_t::THHA;
			case 1593:
				return letter_t::AYN;
			case 1594:
				return letter_t::GHAYN;
			case 1601:
				return letter_t::FA;
			case 1602:
				return letter_t::QAF;
			case 1603:
				return letter_t::KAF;
			case 1604:
				return letter_t::LAM;
			case 1605:
				return letter_t::MEEM;
			case 1606:
				return letter_t::NOON;
			case 1607:
				return letter_t::HA;
			case 1608:
				return letter_t::WAW;
			case 1609:	// alif maqsurah
				return letter_t::YA;
			case 1610:
				return letter_t::YA;
			case 1648:	// alif khanjariyah
				break;
			case 1649:	// alif waslah
				return letter_t::ALIF;
		}

	return letter_t::NONE;
}
modification_t Arabic::get_modification(int ascii)
{
	if (has_modification(ascii))
		switch (ascii)
		{
			case 1570:	// alif with maddah
				return modification_t::MADDAH;
			case 1571:	// alif with hamzah above
			case 1572:	// waw with hamzah above
				return modification_t::HAMZAH_ABOVE;
			case 1573:	// alif with hamzah below
				return modification_t::HAMZAH_BELOW;
			case 1574:	// hamzah middle
				return modification_t::HAMZAH_MIDDLE;
			case 1577:	// ta marbutah
				return modification_t::MARBUTAH;
			case 1609:	// alif maqsurah
				return modification_t::MAQSURAH;
			case 1648:	// alif khanjariyah
				return modification_t::KHANJARIYAH;
			case 1649:	// alif waslah
				return modification_t::WASLAH;
		}

	return modification_t::NONE;
}
diacritic_t Arabic::get_diacritic(int ascii)
{
	if (is_diacritic(ascii))
		switch (ascii)
		{
			case 1611:
				return diacritic_t::TANWEEN_FATHAH;
			case 1612:
				return diacritic_t::TANWEEN_DAMMAH;
			case 1613:
				return diacritic_t::TANWEEN_KASRAH;
			case 1614:
				return diacritic_t::FATHAH;
			case 1615:
				return diacritic_t::DAMMAH;
			case 1616:
				return diacritic_t::KASRAH;
			case 1617:
				return diacritic_t::SHADDAH;
			case 1618:
				return diacritic_t::SUKOON;
			case 1619:
				return diacritic_t::MADDAH;
			case 1620:
				return diacritic_t::HAMZAH;
			case 1759:
				return diacritic_t::SUKOON_WASLAH;
			case 1760:
				return diacritic_t::SUKOON_ALIF;
			case 1763:
				return diacritic_t::SEEN_SUBSTITUTION;
			case 1765:
				return diacritic_t::SMALL_WAW;
			case 1766:
				return diacritic_t::SMALL_YA;
			case 1767:
				return diacritic_t::SMALL_YA_ABOVE;
			case 1768:
				return diacritic_t::DOUBLE_NOON;
			case 1770:
				return diacritic_t::GRAND_IMAALAH;
			case 1771:
				return diacritic_t::ISHMAAM;
			case 1772:
				return diacritic_t::TASHEEL;
		}

	return diacritic_t::NONE;
}
symbol_t Arabic::get_symbol(int ascii)
{
	if (is_symbol(ascii))
		switch (ascii)
		{
			case 1750:
				return symbol_t::GOOD_STOP;
			case 1751:
				return symbol_t::SUFFICIENT_STOP;
			case 1752:
				return symbol_t::COMPULSORY_STOP;
			case 1753:
				return symbol_t::PROHIBITED_STOP;
			case 1754:
				return symbol_t::EQUALITY_STOP;
			case 1755:
				return symbol_t::PRECAUTIONARY_STOP;
			case 1756:
				return symbol_t::BRIEF_STOP;
			case 1758:
				return symbol_t::QUARTER_OF_HALF;
			case 1762:
				return symbol_t::MEEM_IQLAB_ABOVE;
			case 1769:
				return symbol_t::SAJDAH;
			case 1773:
				return symbol_t::MEEM_IQLAB_BELOW;
		}

	return symbol_t::NONE;
}

int Arabic::abjad_value(int ascii)
{
	switch (ascii)
	{
		case 1569:		// hamzah
		case 1570:		// alif with maddah
		case 1571:		// alif with hamzah above
			return 1;
		case 1572:		// waw with hamzah above
			return 6;
		case 1573:		// alif with hamzah below
		case 1574:		// hamzah middle
		case 1575:		// alif
			return 1;
		case 1576:		// ba
			return 2;
		case 1577:		// ta marbutah
		case 1578:		// ta
			return 400;
		case 1579:		// tha
			return 500;
		case 1580:		// jeem
			return 3;
		case 1581:		// hha
			return 8;
		case 1582:		// kha
			return 600;
		case 1583:		// dal
			return 800;
		case 1584:		// dhal
			return 700;
		case 1585:		// ra
			return 200;
		case 1586:		// zayn
			return 7;
		case 1587:		// seen
			return 60;
		case 1588:		// sheen
			return 300;
		case 1589:		// sad
			return 90;
		case 1590:		// dad
			return 4;
		case 1591:		// tta
			return 9;
		case 1592:		// thha
			return 900;
		case 1593:		// ayn
			return 70;
		case 1594:		// ghayn
			return 1000;
		case 1601:		// fa
			return 80;
		case 1602:		// qaf
			return 100;
		case 1603:		// kaf
			return 20;
		case 1604:		// lam
			return 30;
		case 1605:		// meem
			return 40;
		case 1606:		// noon
			return 50;
		case 1607:		// ha
			return 5;
		case 1608:		// waw
			return 6;
		case 1609:		// alif maqsurah
		case 1610:		// ya
			return 10;
		case 1648:		// alif khanjariyah
		case 1649:		// alif waslah
			return 1;
	}

	return 0;
}
int Arabic::abjad_value(Character* character)
{
	return abjad_value(character->GetASCII());
}
int Arabic::abjad_value(Letter* letter)
{
	return abjad_value(letter->GetASCII());
}
int Arabic::abjad_value(std::vector<Character*> characters)
{
	int sum = 0;

	for (auto c : characters)
		sum += abjad_value(c);

	return sum;
}

int Arabic::sequential_value(int ascii, bool modern)
{
	if (modern)
		switch (ascii)
		{
		case 1569:		// hamzah
		case 1570:		// alif with maddah
		case 1571:		// alif with hamzah above
			return 1;
		case 1572:		// waw with hamzah above
			return 27;
		case 1573:		// alif with hamzah below
		case 1574:		// hamzah middle
		case 1575:		// alif
			return 1;
		case 1576:		// ba
			return 2;
		case 1577:		// ta marbutah
		case 1578:		// ta
			return 3;
		case 1579:		// tha
			return 4;
		case 1580:		// jeem
			return 5;
		case 1581:		// hha
			return 6;
		case 1582:		// kha
			return 7;
		case 1583:		// dal
			return 8;
		case 1584:		// dhal
			return 9;
		case 1585:		// ra
			return 10;
		case 1586:		// zayn
			return 11;
		case 1587:		// seen
			return 12;
		case 1588:		// sheen
			return 13;
		case 1589:		// sad
			return 14;
		case 1590:		// dad
			return 15;
		case 1591:		// tta
			return 16;
		case 1592:		// thha
			return 17;
		case 1593:		// ayn
			return 18;
		case 1594:		// ghayn
			return 19;
		case 1601:		// fa
			return 20;
		case 1602:		// qaf
			return 21;
		case 1603:		// kaf
			return 22;
		case 1604:		// lam
			return 23;
		case 1605:		// meem
			return 24;
		case 1606:		// noon
			return 25;
		case 1607:		// ha
			return 26;
		case 1608:		// waw
			return 27;
		case 1609:		// alif maqsurah
		case 1610:		// ya
			return 28;
		case 1648:		// alif khanjariyah
		case 1649:		// alif waslah
			return 1;
		}
	else
		switch (ascii)
		{
			case 1569:		// hamzah
			case 1570:		// alif with maddah
			case 1571:		// alif with hamzah above
				return 1;
			case 1572:		// waw with hamzah above
				return 6;
			case 1573:		// alif with hamzah below
			case 1574:		// hamzah middle
			case 1575:		// alif
				return 1;
			case 1576:		// ba
				return 2;
			case 1577:		// ta marbutah
			case 1578:		// ta
				return 22;
			case 1579:		// tha
				return 23;
			case 1580:		// jeem
				return 3;
			case 1581:		// hha
				return 8;
			case 1582:		// kha
				return 24;
			case 1583:		// dal
				return 26;
			case 1584:		// dhal
				return 25;
			case 1585:		// ra
				return 20;
			case 1586:		// zayn
				return 7;
			case 1587:		// seen
				return 15;
			case 1588:		// sheen
				return 21;
			case 1589:		// sad
				return 18;
			case 1590:		// dad
				return 26;
			case 1591:		// tta
				return 9;
			case 1592:		// thha
				return 27;
			case 1593:		// ayn
				return 16;
			case 1594:		// ghayn
				return 28;
			case 1601:		// fa
				return 17;
			case 1602:		// qaf
				return 19;
			case 1603:		// kaf
				return 11;
			case 1604:		// lam
				return 12;
			case 1605:		// meem
				return 13;
			case 1606:		// noon
				return 14;
			case 1607:		// ha
				return 5;
			case 1608:		// waw
				return 6;
			case 1609:		// alif maqsurah
			case 1610:		// ya
				return 10;
			case 1648:		// alif khanjariyah
			case 1649:		// alif waslah
				return 1;
		}

	return 0;
}
int Arabic::sequential_value(Character* character, bool modern)
{
	return sequential_value(character->GetASCII(), modern);
}
int Arabic::sequential_value(Letter* letter, bool modern)
{
	return sequential_value(letter->GetASCII(), modern);
}
int Arabic::sequential_value(std::vector<Character*> characters, bool modern)
{
	int sum = 0;

	for (auto c : characters)
		sum += sequential_value(c, modern);

	return sum;
}

std::string Arabic::sound_of(int ascii, bool includeDiacritics)
{
	return sound_of(ascii, std::vector<Diacritic*>(), includeDiacritics);
}
std::string Arabic::sound_of(int ascii, std::vector<Diacritic*> diacritics, bool includeDiacritics)
{
	if (!includeDiacritics && is_diacritic(ascii))
		return "";

	std::string sound = "";

	switch (ascii)
	{
		// letters
		{
			case 32:		// space
			{
				sound = " ";
				break;
			}
			case 1569:		// hamzah
			{
				sound = "'";
				break;
			}
			case 1570:		// alif with maddah
			{
				sound = "AA";
				break;
			}
			case 1571:		// alif with hamzah above
			{
				sound = "A";
				break;
			}
			case 1572:		// waw with hamzah above
			{
				sound = "'";
				break;
			}
			case 1573:		// alif with hamzah below
			{
				sound = "I";
				break;
			}
			case 1574:		// hamzah middle
			{
				sound = "'";
				break;
			}
			case 1575:		// alif
			{
				if (has_diacritic(diacritics, diacritic_t::SUKOON) || has_diacritic(diacritics, diacritic_t::SUKOON_ALIF))
					sound = "Ⱥ";
				else if (has_diacritic(diacritics, diacritic_t::TASHEEL))
					sound = "a";
				// if there is a TANWEEN_FATHAH, get sound from diacritic section (silent alif)
				else if (!has_diacritic(diacritics, diacritic_t::TANWEEN_FATHAH))
					sound = "A";
				break;
			}
			case 1576:		// ba
			{
				sound = "B";
				break;
			}
			case 1577:		// ta marbutah
			{
				sound = has_harakah(diacritics) ? "T" : "H";
				break;
			}
			case 1578:		// ta
			{
				sound = "T";
				break;
			}
			case 1579:		// tha
			{
				sound = "Ṯ";
				break;
			}
			case 1580:		// jeem
			{
				sound = "J";
				break;
			}
			case 1581:		// hha
			{
				sound = "Ḥ";
				break;
			}
			case 1582:		// kha
			{
				sound = "Ḵ";
				break;
			}
			case 1583:		// dal
			{
				sound = "D";
				break;
			}
			case 1584:		// dhal
			{
				sound = "Ḏ";
				break;
			}
			case 1585:		// ra
			{
				sound = "R";
				break;
			}
			case 1586:		// zayn
			{
				sound = "Z";
				break;
			}
			case 1587:		// seen
			{
				sound = "S";
				break;
			}
			case 1588:		// sheen
			{
				sound = "Š";
				break;
			}
			case 1589:		// sad
			{
				sound = has_diacritic(diacritics, diacritic_t::SEEN_SUBSTITUTION) ? "S" : "Ṣ";
				break;
			}
			case 1590:		// dad
			{
				sound = "Ḍ";
				break;
			}
			case 1591:		// tta
			{
				sound = "Ṭ";
				break;
			}
			case 1592:		// thha
			{
				sound = "Ẓ";
				break;
			}
			case 1593:		// ayn
			{
				sound = "3";
				break;
			}
			case 1594:		// ghayn
			{
				sound = "Ġ";
				break;
			}
			case 1601:		// fa
			{
				sound = "F";
				break;
			}
			case 1602:		// qaf
			{
				sound = "Q";
				break;
			}
			case 1603:		// kaf
			{
				sound = "K";
				break;
			}
			case 1604:		// lam
			{
				sound = "L";
				break;
			}
			case 1605:		// meem
			{
				sound = "M";
				break;
			}
			case 1606:		// noon
			{
				sound = "N";
				break;
			}
			case 1607:		// ha
			{
				sound = "HA";
				break;
			}
			case 1608:		// waw
			{
				//sound = (position == position_t::MIDDLE || position == position_t::END) ? "Ū" : "W";
				sound = (diacritics.size() == 0 || has_diacritic(diacritics, diacritic_t::SUKOON)) ? "W" : "Ū";
				break;
			}
			case 1609:		// alif maqsurah
			{
				sound = "A";
				break;
			}
			case 1610:		// ya
			{
				//sound = (position == position_t::MIDDLE) ? "Ī" : "Y";
				sound = (diacritics.size() == 0 || has_diacritic(diacritics, diacritic_t::SUKOON)) ? "Y" : "Ī";
				break;
			}
			case 1648:		// alif khanjariyah
			{
				sound = "ā";
				break;
			}
			case 1649:		// alif waslah
			{
				sound = "Ⱥ";
				break;
			}
		}
		// diacritics
		{
			case 1611:		// tanween fathah
			{
				sound = "an";
				break;
			}
			case 1612:		// tanween dammah
			{
				sound = "un";
				break;
			}
			case 1613:		// tanween kasrah
			{
				sound = "in";
				break;
			}
			case 1614:		// fathah
			{
				sound = "a";
				break;
			}
			case 1615:		// dammah
			{
				sound = "u";
				break;
			}
			case 1616:		// kasrah
			{
				sound = "i";
				break;
			}
			case 1617:		// shaddah
				break;			// letter required
			case 1618:		// sukoon
			{
				sound = "";
				break;
			}
			case 1619:		// maddah
				break;			// letter required
			case 1620:		// hamzah
			{
				sound = "'";
				break;
			}
			case 1759:		// sukoon waslah
			{
				//sound = "⍉";
				break;
			}
			case 1760:		// special sukoon over alif
			{
				//sound = "⍉";
				break;
			}
			case 1763:		// seen substitution
				break;			// letter required
			case 1765:		// small waw
			{
				sound = "u";
				break;
			}
			case 1766:		// small ya
			{
				sound = "ī";
				break;
			}
			case 1767:		// small ya above
			{
				sound = "ī";
				break;
			}
			case 1768:		// double noon
			{
				sound = "un";
				break;
			}
			case 1770:		// grand imaalah
			{
				sound = "ey";
				break;
			}
			case 1771:		// ishmaam
				break;			// no written equivalent
			case 1772:		// tas-heel
				break;			// letter required
		}
		// symbols
		{
			case 1752:		// compulsory stop
			{
				sound = ".";
				break;
			}
			case 1753:		// prohibited stop
			{
				sound = ",";
				break;
			}
			case 1750:		// good stop
			{
				sound = "; ";
				break;
			}
			case 1751:		// sufficient stop
			{
				sound = ",";
				break;
			}
			case 1754:		// equality stop
				break;
			case 1755:		// precautionary stop
				break;
			case 1756:		// brief stop
			{
				sound = ", ";
				break;
			}
			case 1769:		// sajdah
				break;
			case 1762:		// meem iqlab above
				break;			// letter required
			case 1773:		// meem iqlab below
				break;			// letter required
			case 1758:		// quarter of half
				break;
		}
	}
	
	if (!includeDiacritics)
		return sound;

	if (has_diacritic(diacritics, diacritic_t::SHADDAH))
		sound += sound;
	if (has_diacritic(diacritics, diacritic_t::MADDAH))
		sound += sound;

	for (auto dp : diacritics)
	{
		switch (dp->GetValue())
		{
			case diacritic_t::FATHAH:
				sound += "a";
				break;
			case diacritic_t::KASRAH:
				sound += "i";
				break;
			case diacritic_t::SMALL_YA:
				sound += "ī";
					break;
			case diacritic_t::DAMMAH:
			case diacritic_t::SMALL_WAW:
				sound += "u";
					break;
			case diacritic_t::TANWEEN_FATHAH:
				sound += "an";
					break;
			case diacritic_t::TANWEEN_KASRAH:
				sound += "in";
				break;
			case diacritic_t::TANWEEN_DAMMAH:
				sound += "un";
				break;
		}
	}

	return sound;
}
std::string Arabic::sound_of(Character* character, bool includeDiacritics)
{
	return sound_of(character->GetASCII(), std::vector<Diacritic*>(), includeDiacritics);
}
std::string Arabic::sound_of(Character* character, std::vector<Diacritic*> diacritics, bool includeDiacritics)
{
	return sound_of(character->GetASCII(), diacritics, includeDiacritics);
}
std::string Arabic::sound_of(std::vector<Character*> word, bool includeDiacritics)
{
	std::string sound = "";

	for (unsigned int i = 0; i < word.size(); i++)
		sound += sound_of(word[i], includeDiacritics);

	return sound;
}

bool Arabic::is_letter(int ascii, bool checkspace)
{
	return (ascii == ' ' && checkspace)
		|| (ascii >= 1569 && ascii <= 1594)		// note that tatweel (1600), alif khanjariyah (1648),
		|| (ascii >= 1600 && ascii <= 1610)		// and alif waslah (1649) can be either a Letter or
		|| (ascii >= 1648 && ascii <= 1649);	// Diacritic, depending on the use case
}
bool Arabic::is_diacritic(int ascii)
{
	// meem saakin - 1762/0x6e2   <------------	// does not appear in quran text?

	return  ascii == 1600						// note that tatweel (1600), alif khanjariyah (1648),
		|| (ascii >= 1611 && ascii <= 1620)
		||  ascii == 1648						// and alif waslah (1649) can be either a Letter or
		||  ascii == 1649						// Diacritic, depending on the use case
		|| (ascii >= 1759 && ascii <= 1760)
		||  ascii == 1763
		|| (ascii >= 1765 && ascii <= 1768)
		|| (ascii >= 1770 && ascii <= 1772);
}
bool Arabic::is_symbol(int ascii)
{
	return (ascii >= 1750 && ascii <= 1756)
		||  ascii == 1758
		||  ascii == 1762
		||  ascii == 1769
		||  ascii == 1773;
}
bool Arabic::is_arabic(int ascii, bool checkspace)
{
	return is_letter(ascii, checkspace)
		|| is_diacritic(ascii)
		|| is_symbol(ascii);
}

bool Arabic::has_modification(int ascii)
{
	return (ascii >= 1570 && ascii <= 1574)
		||  ascii == 1577
		||  ascii == 1609
		|| (ascii >= 1648 && ascii <= 1649);
}
bool Arabic::has_harakah(std::vector<Diacritic*> diacritics)
{
	for (auto dp : diacritics)
		if (dp->GetValue() == diacritic_t::FATHAH
		 || dp->GetValue() == diacritic_t::KASRAH
		 || dp->GetValue() == diacritic_t::DAMMAH
		 || dp->GetValue() == diacritic_t::TANWEEN_FATHAH
		 || dp->GetValue() == diacritic_t::TANWEEN_KASRAH
		 || dp->GetValue() == diacritic_t::TANWEEN_DAMMAH)
			return true;

	return false;
}
bool Arabic::has_diacritic(std::vector<Diacritic*> diacritics, Diacritic d)
{
	return Utilities::index_of(diacritics, d) != -1;
}


///////////////////////////////////////////////////////////////////////////////
// Character 
///////////////////////////////////////////////////////////////////////////////


int Character::GetASCII()
{
	return this->ascii;
}
character_t Character::GetType()
{
	return this->type;
}

std::string Character::SoundOf()
{
	return sound_of(this->ascii);
}
std::string Character::ToString()
{
	return to_string(this->ascii);
}

bool Character::operator ==(const Character& rhs)
{
	return this->ascii == rhs.ascii;
}
bool Character::operator !=(const Character& rhs)
{
	return !(*this == rhs);
}


///////////////////////////////////////////////////////////////////////////////
// Letter 
///////////////////////////////////////////////////////////////////////////////


Letter::Letter()
{
	Reset();
}
Letter::Letter(int ascii, Position position) : Letter()
{
	this->SetASCII(ascii);
	this->position = position;
}
Letter::Letter(Value value, Position position) : Letter()
{
	this->ascii = to_ascii(value);
	this->value = value;
	this->modification = Modification::NONE;
	this->position = position;
}
Letter::Letter(Value value, Modification modification, Position position) : Letter()
{
	this->ascii = to_ascii(value, modification);
	this->value = value;
	this->modification = modification;
	this->position = position;
}

void Letter::Reset()
{
	this->ascii = 0;
	this->type = character_t::LETTER;

	this->value = letter_t::NONE;
	this->modification = modification_t::NONE;
	this->position = position_t::NONE;
}

void Letter::SetASCII(int ascii)
{
	this->ascii = ascii;
	this->value = get_letter(ascii);
	this->modification = get_modification(ascii);
}
letter_t Letter::GetValue()
{
	return this->value;
}

modification_t Letter::GetModification()
{
	return this->modification;
}
void Letter::SetModification(modification_t m)
{
	this->modification = m;
	this->ascii = to_ascii(this->value, m);
}

position_t Letter::GetPosition()
{
	return this->position;
}
void Letter::SetPosition(position_t p)
{
	this->position = p;
}

int Letter::GetAbjadValue()
{
	return abjad_value(this->ascii);
}
int Letter::GetSequentialValue()
{
	return sequential_value(this->ascii);
}


///////////////////////////////////////////////////////////////////////////////
// Diacritic 
///////////////////////////////////////////////////////////////////////////////


Diacritic::Diacritic()
{
	Reset();
}
Diacritic::Diacritic(int ascii)
{
	this->SetASCII(ascii);
}
Diacritic::Diacritic(Value value)
{
	this->GetValue(value);
}

void Diacritic::Reset()
{
	this->ascii = 0;
	this->value = diacritic_t::NONE;
}
void Diacritic::SetASCII(int ascii)
{
	this->ascii = ascii;
	this->value = get_diacritic(ascii);
}

void Diacritic::GetValue(Value value)
{
	this->ascii = to_ascii(value);
	this->value = value;
}
diacritic_t Diacritic::GetValue()
{
	return this->value;
}


///////////////////////////////////////////////////////////////////////////////
// Symbol 
///////////////////////////////////////////////////////////////////////////////


Symbol::Symbol()
{
	Reset();
}
Symbol::Symbol(int ascii)
{
	this->SetASCII(ascii);
}
Symbol::Symbol(Value value)
{
	this->GetValue(value);
}

void Symbol::Reset()
{
	this->ascii = 0;
	this->value = symbol_t::NONE;
}
void Symbol::SetASCII(int ascii)
{
	this->ascii = ascii;
	this->value = get_symbol(ascii);
}

void Symbol::GetValue(Value value)
{
	this->ascii = to_ascii(value);
	this->value = value;
}
symbol_t Symbol::GetValue()
{
	return this->value;
}


/*
/// <summary>
/// Dictionary for looking up ASCII values by their respective Letters
/// </summary>
std::map<Letter, int> Arabic_old::ASCIIByLetter
{
	{Letter(Character::SPACE, Diacritic::NONE),				32},
	{Letter(Character::NONE, Diacritic::TATWEEL),			1600},
	{Letter(Character::HAMZAH, Diacritic::NONE),			1569},
	{Letter(Character::ALIF, Diacritic::MADDAH),			1570},
	{Letter(Character::ALIF, Diacritic::HAMZAH_ABOVE),		1571},
	{Letter(Character::WAW, Diacritic::HAMZAH_ABOVE),		1572},
	{Letter(Character::ALIF, Diacritic::HAMZAH_BELOW),		1573},
	{Letter(Character::HAMZAH, Diacritic::HAMZAH_MIDDLE),	1574},
	{Letter(Character::ALIF, Diacritic::NONE),				1575},
	{Letter(Character::BA, Diacritic::NONE),				1576},
	{Letter(Character::TA, Diacritic::MARBUTAH),			1577},
	{Letter(Character::TA, Diacritic::NONE),				1578},
	{Letter(Character::THA, Diacritic::NONE),				1579},
	{Letter(Character::JEEM, Diacritic::NONE),				1580},
	{Letter(Character::HHA, Diacritic::NONE),				1581},
	{Letter(Character::KHA, Diacritic::NONE),				1582},
	{Letter(Character::DAL, Diacritic::NONE),				1583},
	{Letter(Character::DHAL, Diacritic::NONE),				1584},
	{Letter(Character::RA, Diacritic::NONE),				1585},
	{Letter(Character::ZAYN, Diacritic::NONE),				1586},
	{Letter(Character::SEEN, Diacritic::NONE),				1587},
	{Letter(Character::SHEEN, Diacritic::NONE),				1588},
	{Letter(Character::SAD, Diacritic::NONE),				1589},
	{Letter(Character::DAD, Diacritic::NONE),				1590},
	{Letter(Character::TTA, Diacritic::NONE),				1591},
	{Letter(Character::THHA, Diacritic::NONE),				1592},
	{Letter(Character::AYN, Diacritic::NONE),				1593},
	{Letter(Character::GHAYN, Diacritic::NONE),				1594},
	{Letter(Character::FA, Diacritic::NONE),				1601},
	{Letter(Character::QAF, Diacritic::NONE),				1602},
	{Letter(Character::KAF, Diacritic::NONE),				1603},
	{Letter(Character::LAM, Diacritic::NONE),				1604},
	{Letter(Character::MEEM, Diacritic::NONE),				1605},
	{Letter(Character::NOON, Diacritic::NONE),				1606},
	{Letter(Character::HA, Diacritic::NONE),				1607},
	{Letter(Character::WAW, Diacritic::NONE),				1608},
	{Letter(Character::YA, Diacritic::ALIF_MAQSURAH),		1609},
	{Letter(Character::YA, Diacritic::NONE),				1610},
	{Letter(Character::ALIF, Diacritic::ALIF_KHANJARIYAH),	1648},
	{Letter(Character::ALIF, Diacritic::ALIF_WASLAH),		1649},
}
/// <summary>
/// Dictionary for looking up Letters by their ASCII values
/// </summary>
std::map<int, Letter> Arabic_old::LetterByASCII
{
	{32,	Letter(Character::SPACE, Diacritic::NONE)},
	{1600,	Letter(Character::NONE, Diacritic::TATWEEL)},
	{1569,	Letter(Character::HAMZAH, Diacritic::NONE)},
	{1570,	Letter(Character::ALIF, Diacritic::MADDAH)},
	{1571,	Letter(Character::ALIF, Diacritic::HAMZAH_ABOVE)},
	{1572,	Letter(Character::WAW, Diacritic::HAMZAH_ABOVE)},
	{1573,	Letter(Character::ALIF, Diacritic::HAMZAH_BELOW)},
	{1574,	Letter(Character::HAMZAH, Diacritic::HAMZAH_MIDDLE)},
	{1575,	Letter(Character::ALIF, Diacritic::NONE)},
	{1576,	Letter(Character::BA, Diacritic::NONE)},
	{1577,	Letter(Character::TA, Diacritic::MARBUTAH)},
	{1578,	Letter(Character::TA, Diacritic::NONE)},
	{1579,	Letter(Character::THA, Diacritic::NONE)},
	{1580,	Letter(Character::JEEM, Diacritic::NONE)},
	{1581,	Letter(Character::HHA, Diacritic::NONE)},
	{1582,	Letter(Character::KHA, Diacritic::NONE)},
	{1583,	Letter(Character::DAL, Diacritic::NONE)},
	{1584,	Letter(Character::DHAL, Diacritic::NONE)},
	{1585,	Letter(Character::RA, Diacritic::NONE)},
	{1586,	Letter(Character::ZAYN, Diacritic::NONE)},
	{1587,	Letter(Character::SEEN, Diacritic::NONE)},
	{1588,	Letter(Character::SHEEN, Diacritic::NONE)},
	{1589,	Letter(Character::SAD, Diacritic::NONE)},
	{1590,	Letter(Character::DAD, Diacritic::NONE)},
	{1591,	Letter(Character::TTA, Diacritic::NONE)},
	{1592,	Letter(Character::THHA, Diacritic::NONE)},
	{1593,	Letter(Character::AYN, Diacritic::NONE)},
	{1594,	Letter(Character::GHAYN, Diacritic::NONE)},
	{1601,	Letter(Character::FA, Diacritic::NONE)},
	{1602,	Letter(Character::QAF, Diacritic::NONE)},
	{1603,	Letter(Character::KAF, Diacritic::NONE)},
	{1604,	Letter(Character::LAM, Diacritic::NONE)},
	{1605,	Letter(Character::MEEM, Diacritic::NONE)},
	{1606,	Letter(Character::NOON, Diacritic::NONE)},
	{1607,	Letter(Character::HA, Diacritic::NONE)},
	{1608,	Letter(Character::WAW, Diacritic::NONE)},
	{1609,	Letter(Character::YA, Diacritic::ALIF_MAQSURAH)},
	{1610,	Letter(Character::YA, Diacritic::NONE)},
	{1648,	Letter(Character::ALIF, Diacritic::ALIF_KHANJARIYAH)},
	{1649,	Letter(Character::ALIF, Diacritic::ALIF_WASLAH)},
}
/// <summary>
/// Dictionary for looking up ASCII values by their respective Diacritics
/// </summary>
std::map<Diacritic, int> Arabic_old::ASCIIByDiacritic
{
	{Diacritic::TATWEEL,			1600},
	{Diacritic::TANWEEN_FATHAH,		1611},
	{Diacritic::TANWEEN_DAMMAH,		1612},
	{Diacritic::TANWEEN_KASRAH,		1613},
	{Diacritic::FATHAH,				1614},
	{Diacritic::DAMMAH,				1615},
	{Diacritic::KASRAH,				1616},
	{Diacritic::SHADDAH,			1617},
	{Diacritic::SUKOON,				1618},
	{Diacritic::MADDAH,				1619},
	{Diacritic::HAMZAH,				1620},
	{Diacritic::ALIF_KHANJARIYAH,	1648},
	{Diacritic::SUKOON_WASLAH,		1759},
	{Diacritic::SUKOON_ALIF,		1760},
	{Diacritic::SEEN_SUBSTITUTION,	1763},
	{Diacritic::SMALL_WAW,			1765},
	{Diacritic::SMALL_YA,			1766},
	{Diacritic::SMALL_YA_ABOVE,		1767},
	{Diacritic::DOUBLE_NOON,		1768},
	{Diacritic::GRAND_IMAALAH,		1770},
	{Diacritic::ISHMAAM,			1771},
	{Diacritic::TASHEEL,			1772},
}
/// <summary>
/// Dictionary for looking up Diacritics by their ASCII values
/// </summary>
std::map<int, Diacritic> Arabic_old::DiacriticByASCII
{
	{1600,	Diacritic::TATWEEL},
	{1611,	Diacritic::TANWEEN_FATHAH},
	{1612,	Diacritic::TANWEEN_DAMMAH},
	{1613,	Diacritic::TANWEEN_KASRAH},
	{1614,	Diacritic::FATHAH},
	{1615,	Diacritic::DAMMAH},
	{1616,	Diacritic::KASRAH},
	{1617,	Diacritic::SHADDAH},
	{1618,	Diacritic::SUKOON},
	{1619,	Diacritic::MADDAH},
	{1620,	Diacritic::HAMZAH},
	{1648,	Diacritic::ALIF_KHANJARIYAH},
	{1759,	Diacritic::SUKOON_WASLAH},
	{1760,	Diacritic::SUKOON_ALIF},
	{1763,	Diacritic::SEEN_SUBSTITUTION},
	{1765,	Diacritic::SMALL_WAW},
	{1766,	Diacritic::SMALL_YA},
	{1767,	Diacritic::SMALL_YA_ABOVE},
	{1768,	Diacritic::DOUBLE_NOON},
	{1770,	Diacritic::GRAND_IMAALAH},
	{1771,	Diacritic::ISHMAAM},
	{1772,	Diacritic::TASHEEL},
}

/// <summary>
/// Converts an ascii value to a human-readable form
/// </summary>
/// <param name="ascii:">ascii value to convert</param>
/// <returns>string representation of an ascii value</returns>
std::string Arabic_old::to_string(int ascii)
{
	if (DiacriticByASCII.count(ascii) == 1)
		return to_string(DiacriticByASCII[ascii])
	else if (LetterByASCII.count(ascii) == 1)
		return to_string(LetterByASCII[ascii].GetCharacter())

	return "NONE"
}
/// <summary>
/// Converts a Character to a string
/// </summary>
/// <param name="character:">Character to convert</param>
/// <returns>string representation of a Character</returns>
std::string Arabic_old::to_string(Character character)
{
	switch (character)
	{
		case Character::NONE:
			return "NONE"
		case Character::SPACE:
			return "SPACE"
		case Character::HAMZAH:
			return "HAMZAH"
		case Character::ALIF:
			return "ALIF"
		case Character::BA:
			return "BA"
		case Character::JEEM:
			return "JEEM"
		case Character::DAL:
			return "DAL"
		case Character::HA:
			return "HA"
		case Character::WAW:
			return "WAW"
		case Character::ZAYN:
			return "ZAYN"
		case Character::HHA:
			return "HHA"
		case Character::TTA:
			return "TTA"
		case Character::YA:
			return "YA"
		case Character::KAF:
			return "KAF"
		case Character::LAM:
			return "LAM"
		case Character::MEEM:
			return "MEEM"
		case Character::NOON:
			return "NOON"
		case Character::SEEN:
			return "SEEN"
		case Character::AYN:
			return "AYN"
		case Character::FA:
			return "FA"
		case Character::SAD:
			return "SAD"
		case Character::QAF:
			return "QAF"
		case Character::RA:
			return "RA"
		case Character::SHEEN:
			return "SHEEN"
		case Character::TA:
			return "TA"
		case Character::THA:
			return "THA"
		case Character::KHA:
			return "KHA"
		case Character::DHAL:
			return "DHAL"
		case Character::DAD:
			return "DAD"
		case Character::THHA:
			return "THHA"
		case Character::GHAYN:
			return "GHAYN"
		case Character::ONE:
			return "ONE"
		case Character::TWO:
			return "TWO"
		case Character::THREE:
			return "THREE"
		case Character::FOUR:
			return "FOUR"
		case Character::FIVE:
			return "FIVE"
		case Character::SIX:
			return "SIX"
		case Character::SEVEN:
			return "SEVEN"
		case Character::EIGHT:
			return "EIGHT"
		case Character::NINE:
			return "NINE"
		case Character::ZERO:
			return "ZERO"
	}

	return "NONE"
}
/// <summary>
/// Converts a Position to a string
/// </summary>
/// <param name="p:">Position to convert</param>
/// <returns>string representation of a Position</returns>
std::string Arabic_old::to_string(Position p)
{
	switch (p)
	{
		case Position::ISOLATED:
			return "ISOLATED"
		case Position::BEGINNING:
			return "BEGINNING"
		case Position::MIDDLE:
			return "MIDDLE"
		case Position::END:
			return "END"
	}

	return "NONE"
}
/// <summary>
/// Converts a Diacritic to a string
/// </summary>
/// <param name="d:">Diacritic to convert</param>
/// <returns>string representation of a Diacritic</returns>
std::string Arabic_old::to_string(Diacritic d)
{
	switch (d)
	{
		case Diacritic::TATWEEL:
			return "TATWEEL"
		case Diacritic::HAMZAH:
			return "HAMZAH"
		case Diacritic::HAMZAH_ABOVE:
			return "HAMZAH_ABOVE"
		case Diacritic::HAMZAH_BELOW:
			return "HAMZAH_BELOW"
		case Diacritic::HAMZAH_MIDDLE:
			return "HAMZAH_MIDDLE"
		case Diacritic::FATHAH:
			return "FATHAH"
		case Diacritic::KASRAH:
			return "KASRAH"
		case Diacritic::DAMMAH:
			return "DAMMAH"
		case Diacritic::SUKOON:
			return "SUKOON"
		case Diacritic::SUKOON_WASLAH:
			return "SUKOON_WASLAH"
		case Diacritic::SUKOON_ALIF:
			return "SUKOON_ALIF"
		case Diacritic::SMALL_WAW:
			return "SMALL_WAW"
		case Diacritic::SMALL_YA:
			return "SMALL_YA"
		case Diacritic::SMALL_YA_ABOVE:
			return "SMALL_YA_ABOVE"
		case Diacritic::SHADDAH:
			return "SHADDAH"
		case Diacritic::MADDAH:
			return "MADDAH"
		case Diacritic::TANWEEN_FATHAH:
			return "TANWEEN_FATHAH"
		case Diacritic::TANWEEN_KASRAH:
			return "TANWEEN_KASRAH"
		case Diacritic::TANWEEN_DAMMAH:
			return "TANWEEN_DAMMAH"
		case Diacritic::ALIF_WASLAH:
			return "ALIF_WASLAH"
		case Diacritic::ALIF_KHANJARIYAH:
			return "ALIF_KHANJARIYAH"
		case Diacritic::ALIF_MAQSURAH:
			return "ALIF_MAQSURAH"
		case Diacritic::MARBUTAH:
			return "MARBUTAH"
		case Diacritic::DOUBLE_NOON:
			return "DOUBLE_NOON"
		case Diacritic::GRAND_IMAALAH:
			return "GRAND_IMAALAH"
		case Diacritic::ISHMAAM:
			return "ISHMAAM"
		case Diacritic::TASHEEL:
			return "TAS-HEEL"
		case Diacritic::SEEN_SUBSTITUTION:
			return "SEEN_SUBSTITUTION"
	}

	return "NONE"
}
/// <summary>
/// Converts a Word Type to a string
/// </summary>
/// <param name="t:">Word Type to convert</param>
/// <returns>string representation of a Word Type</returns>
std::string Arabic_old::to_string(Word::Type t)
{
	switch (t)
	{
		case Word::Type::NOUN:
			return "NOUN"
		case Word::Type::VERB:
			return "VERB"
		case Word::Type::ADJECTIVE:
			return "ADJECTIVE"
		case Word::Type::ADVERB:
			return "ADVERB"
		case Word::Type::PRONOUN:
			return "PRONOUN"
	}

	return "NONE"
}
/// <summary>
/// Converts a Word Tense to a string
/// </summary>
/// <param name="t:">Word Tense to convert</param>
/// <returns>string representation of a Word Tense</returns>
std::string Arabic_old::to_string(Word::Tense t)
{
	switch (t)
	{
		case Word::Tense::ROOT:
			return "ROOT"
		case Word::Tense::PAST:
			return "PAST"
		case Word::Tense::PRESENT:
			return "PRESENT"
		case Word::Tense::FUTURE:
			return "FUTURE"
		case Word::Tense::COMMAND:
			return "COMMAND"
	}

	return "NONE"
}
/// <summary>
/// Converts a Word Person to a string
/// </summary>
/// <param name="p:">Word Person to convert</param>
/// <returns>string representation of a Word Person</returns>
std::string Arabic_old::to_string(Word::Person p)
{
	switch (p)
	{
		case Word::Person::FIRST:
			return "FIRST"
		case Word::Person::SECOND:
			return "SECOND"
		case Word::Person::THRID:
			return "THRID"
		case Word::Person::FOURTH:
			return "FOURTH"
	}
	
	return "NONE"
}
/// <summary>
/// Converts a Word Quantity to a string
/// </summary>
/// <param name="q:">Word Quantity to convert</param>
/// <returns>string representation of a Word Quantity</returns>
std::string Arabic_old::to_string(Word::Quantity q)
{
	switch (q)
	{
		case Word::Quantity::SINGULAR:
			return "SINGULAR"
		case Word::Quantity::DUAL:
			return "DUAL"
		case Word::Quantity::PLURAL:
			return "PLURAL"
	}
	
	return "NONE"
}
/// <summary>
/// Converts a Word Gender to a string
/// </summary>
/// <param name="g:">Word Gender to convert</param>
/// <returns>string representation of a Word Gender</returns>
std::string Arabic_old::to_string(Word::Gender g)
{
	switch (g)
	{
		case Word::Gender::MASCULINE:
			return "MASCULINE"
		case Word::Gender::FEMININE:
			return "FEMININE"
	}
		
	return "NONE"
}

/// <summary>
/// Converts a hexadecimal to its ascii representation
/// </summary>
/// <param name="hex:">hexadecimal to convert</param>
/// <returns>ascii representation of a hexadecimal</returns>
int Arabic_old::to_ascii(std::string hex)
{
	int n = 0
	std::stringstream ss
	ss << std::hex << hex
	ss >> n
	return n
}
/// <summary>
/// Converts a Character to its ascii representation
/// </summary>
/// <param name="character:">Character to convert</param>
/// <returns>ascii representation of a Character (without additional diacritics)</returns>
int Arabic_old::to_ascii(Character character)
{
	return ASCIIByLetter[Letter(character)]
}
/// <summary>
/// Converts a Diacritic to its ascii representation
/// </summary>
/// <param name="d:">Diacritic to convert</param>
/// <returns>ascii representation of a Diacritic</returns>
int Arabic_old::to_ascii(Diacritic d)
{
	return ASCIIByDiacritic[d]
}
/// <summary>
/// Converts a Letter to its ascii representation
/// </summary>
/// <param name="rhs:">Letter to convert</param>
/// <returns>ascii representation of a Letter</returns>
int Arabic_old::to_ascii(Letter letter)
{
	return ASCIIByLetter[letter]
}

/// <summary>
/// Converts an integer to its hexadecimal representation
/// </summary>
/// <param name="n:">integer to convert</param>
/// <returns>hexadecimal representation of an integer</returns>
std::string Arabic_old::to_hex(int n)
{
	std::stringstream ss
	ss << std::hex << n
	return ss.str()
}
/// <summary>
/// Converts a Character to its hexadecimal representation
/// </summary>
/// <param name="character:">Character to convert</param>
/// <returns>hexadecimal representation of a Character</returns>
std::string Arabic_old::to_hex(Character character)
{
	return to_hex(to_ascii(character))
}
/// <summary>
/// Converts a Diacritic to its hexadecimal representation
/// </summary>
/// <param name="d:">Diacritic to convert</param>
/// <returns>hexadecimal representation of a Diacritic</returns>
std::string Arabic_old::to_hex(Diacritic d)
{
	return to_hex(to_ascii(d))
}
/// <summary>
/// Converts a Letter to its hexadecimal representation
/// </summary>
/// <param name="rhs:">Letter to convert</param>
/// <returns>hexadecimal representation of a Letter</returns>
std::string Arabic_old::to_hex(Letter letter)
{
	return to_hex(to_ascii(letter))
}

/// <summary>
/// Returns the abjad value of a Character
/// </summary>
/// <param name="character:">Character to convert</param>
/// <returns>abjad value of a Character</returns>
int Arabic_old::abjad_value(Character character)
{
	return abs(static_cast<int>(character))
}
/// <summary>
/// Returns the abjad value of a Letter
/// </summary>
/// <param name="rhs:">Letter to convert</param>
/// <returns>abjad value of a Letter</returns>
int Arabic_old::abjad_value(Letter letter)
{
	return abjad_value(letter.GetCharacter())
}
/// <summary>
/// Returns the abjad value of a vector of Letters
/// </summary>
/// <param name="ls:">Letters to convert</param>
/// <returns>abjad value of a number of Letters</returns>
int Arabic_old::abjad_value(std::vector<Letter> ls)
{
	int sum = 0

	for (auto& letter : ls)
		sum += abjad_value(letter)

	return sum
}
/// <summary>
/// Returns the abjad value of a Word
/// </summary>
/// <param name="w:">Word to convert</param>
/// <returns>abjad value of a Word</returns>
int Arabic_old::abjad_value(Word w)
{
	int sum = 0

	for (auto& letter : w.GetLetters())
		sum += abjad_value(letter)

	return sum
}
/// <summary>
/// Returns the abjad value of a vector of Words
/// </summary>
/// <param name="ws:">Words to convert</param>
/// <returns>abjad value of a number of Words</returns>
int Arabic_old::abjad_value(std::vector<Word> ws)
{
	int sum = 0

	for (auto& w : ws)
		sum += abjad_value(w)

	return sum
}

//TODO: value of ya with alif maqsurah on it

/// <summary>
/// Returns the sequential value of a Character
/// </summary>
/// <param name="character:">Character to convert</param>
/// <returns>sequential value of a Character</returns>
int Arabic_old::sequential_value(Character character)
{
	switch (character)
	{
		case Character::HAMZAH:
		case Character::ALIF:
			return 1
		case Character::BA:
			return 2
		case Character::JEEM:
			return 3
		case Character::DAL:
			return 4
		case Character::HA:
			return 5
		case Character::WAW:
			return 6
		case Character::ZAYN:
			return 7
		case Character::HHA:
			return 8
		case Character::TTA:
			return 9
		case Character::YA:
			return 10
		case Character::KAF:
			return 11
		case Character::LAM:
			return 12
		case Character::MEEM:
			return 13
		case Character::NOON:
			return 14
		case Character::SEEN:
			return 15
		case Character::AYN:
			return 16
		case Character::FA:
			return 17
		case Character::SAD:
			return 18
		case Character::QAF:
			return 19
		case Character::RA:
			return 20
		case Character::SHEEN:
			return 21
		case Character::TA:
			return 22
		case Character::THA:
			return 23
		case Character::KHA:
			return 24
		case Character::DHAL:
			return 25
		case Character::DAD:
			return 26
		case Character::THHA:
			return 27
		case Character::GHAYN:
			return 28
	}

	return 0
}
/// <summary>
/// Returns the sequential value of a Letter
/// </summary>
/// <param name="rhs:">Letter to convert</param>
/// <returns>sequential value of a Letter</returns>
int Arabic_old::sequential_value(Letter letter)
{
	return sequential_value(letter.GetCharacter())
}
/// <summary>
/// Returns the sequential value of a vector of Letters
/// </summary>
/// <param name="ls:">Letters to convert</param>
/// <returns>sequential value of a number of Letters</returns>
int Arabic_old::sequential_value(std::vector<Letter> ls)
{
	int sum = 0

	for (auto& letter : ls)
		sum += sequential_value(letter)

	return sum
}
/// <summary>
/// Returns the sequential value of a Word
/// </summary>
/// <param name="w:">Word to convert</param>
/// <returns>sequential value of a Word</returns>
int Arabic_old::sequential_value(Word w)
{
	int sum = 0

	for (auto& letter : w.GetLetters())
		sum += sequential_value(letter)

	return sum
}
/// <summary>
/// Returns the sequential value of a vector of Words
/// </summary>
/// <param name="ws:">Words to convert</param>
/// <returns>sequential value of a number of Words</returns>
int Arabic_old::sequential_value(std::vector<Word> ws)
{
	int sum = 0

	for (auto& w : ws)
		sum += sequential_value(w)

	return sum
}

/// <summary>
/// Returns the sound that a Letter makes with all its members separated into different parameters, with the option to visualize its Diacritics
/// </summary>
/// <param name="character">the Letter's "character"</param>
/// <param name="modification">the Letter's "modification"</param>
/// <param name="diacritics">the Letter's "diacritics"</param>
/// <param name="position">the Letter's "position"</param>
/// <param name="includeDiacritics:">if set to true, the Diacritics' sounds will be textualized as well (default true)</param>
/// <returns>std::string representation of the Letter's sound</returns>
std::string Arabic_old::sound_of(Character character, Diacritic modification, std::vector<Diacritic> diacritics, Position position, bool includeDiacritics)
{
	std::string sound = ""

	switch (character)
	{
		case Character::SPACE:
		{
			return " "
			break
		}
		case Character::HAMZAH: // includes the HAMZAH_MIDDLE modification
		{
			sound = "'"
			break
		}
		case Character::ALIF:
		{
			switch (modification)
			{
				case Diacritic::MADDAH:
					sound = "AA"
					break
				case Diacritic::HAMZAH_BELOW:
					sound = "I"
					break
				default:
					if (modification == Diacritic::ALIF_WASLAH || Utilities::index_of(diacritics, Diacritic::SUKOON) != -1 || Utilities::index_of(diacritics, Diacritic::SUKOON_ALIF) != -1)
						sound = "Ⱥ"
					else if (Utilities::index_of(diacritics, Diacritic::TASHEEL) != -1)
						sound = "a"
					else if (Utilities::index_of(diacritics, Diacritic::TANWEEN_FATHAH) == -1)	// if there is a TANWEEN_FATHAH, get sound from diacritic section
						sound = "A"
					break
			}
			break
		}
		case Character::BA:
		{
			sound = "B"
			break
		}
		case Character::TA:
		{
			if  (modification != Diacritic::MARBUTAH								// if it is not MARBUTAH
			 || (Utilities::index_of(diacritics, Diacritic::FATHAH) != -1			// or
			 ||  Utilities::index_of(diacritics, Diacritic::KASRAH) != -1			// if there it has a harakah
			 ||  Utilities::index_of(diacritics, Diacritic::DAMMAH) != -1)
			 || (Utilities::index_of(diacritics, Diacritic::TANWEEN_FATHAH) != -1
			 ||  Utilities::index_of(diacritics, Diacritic::TANWEEN_KASRAH) != -1
			 ||  Utilities::index_of(diacritics, Diacritic::TANWEEN_DAMMAH) != -1))
				sound = "T"
			else
				sound = "H"
			break
		}
		case Character::THA:
		{
			sound = "Ṯ"
			break
		}
		case Character::JEEM:
		{
			sound = "J"
			break
		}
		case Character::HHA:
		{
			sound = "Ḥ"
			break
		}
		case Character::KHA:
		{
			sound = "Ḵ"
			break
		}
		case Character::DAL:
		{
			sound = "D"
			break
		}
		case Character::DHAL:
		{
			sound = "Ḏ"
			break
		}
		case Character::RA:
		{
			sound = "R"
			break
		}
		case Character::ZAYN:
		{
			sound = "Z"
			break
		}
		case Character::SEEN:
		{
			sound = "S"
			break
		}
		case Character::SHEEN:
		{
			sound = "Š"
			break
		}
		case Character::SAD:
		{
			if (Utilities::index_of(diacritics, Diacritic::SEEN_SUBSTITUTION) != -1)
				sound = "S"
			else
				sound = "Ṣ"
			break
		}
		case Character::DAD:
		{
			sound = "Ḍ"
			break
		}
		case Character::TTA:
		{
			sound = "Ṭ"
			break
		}
		case Character::THHA:
		{
			sound = "Ẓ"
			break
		}
		case Character::AYN:
		{
			sound = "3"
			break
		}
		case Character::GHAYN:
		{
			sound = "Ġ"
			break
		}
		case Character::FA:
		{
			sound = "F"
			break
		}
		case Character::QAF:
		{
			sound = "Q"
			break
		}
		case Character::KAF:
		{
			sound = "K"
			break
		}
		case Character::LAM:
		{
			sound = "L"
			break
		}
		case Character::MEEM:
		{
			sound = "M"
			break
		}
		case Character::NOON:
		{
			sound = "N"
			break
		}
		case Character::HA:
		{
			sound = "H"
			break
		}
		case Character::WAW:
		{
			if (modification == Diacritic::HAMZAH_ABOVE)
				sound = "'"
			else if (position == Position::MIDDLE || position == Position::END)
				sound = "Ū"
			else
				sound = "W"
			break
		}
		case Character::YA:
		{
			if (modification == Diacritic::ALIF_MAQSURAH)
				sound = "A"
			else if (position == Position::MIDDLE)
				sound = "Ī"
			else
				sound = "Y"
			break
		}
		default:	// Diacritic::TATWEEL
		{
			if (Utilities::index_of<Diacritic>(diacritics, Diacritic::GRAND_IMAALAH) != -1)
				sound = "ey"
			else if (Utilities::index_of<Diacritic>(diacritics, Diacritic::HAMZAH) != -1)
				sound = "'"
			else if (Utilities::index_of<Diacritic>(diacritics, Diacritic::ALIF_KHANJARIYAH) != -1)
				sound = "ā"
		}
	}

	if (!includeDiacritics)
		return sound

	if (Utilities::index_of(diacritics, Diacritic::SHADDAH) != -1)
		sound += sound
	if (Utilities::index_of(diacritics, Diacritic::MADDAH) != -1)
		sound += sound

	for (auto& d : diacritics)
	{
		switch (d)
		{
			case Diacritic::FATHAH:
				sound += "a"
				break
			case Diacritic::KASRAH:
				sound += "i"
				break
			case Diacritic::SMALL_YA:
				sound += "ī"
				break
			case Diacritic::DAMMAH:
			case Diacritic::SMALL_WAW:
				sound += "u"
				break
			case Diacritic::TANWEEN_FATHAH:
				sound += "an"
				break
			case Diacritic::TANWEEN_KASRAH:
				sound += "in"
				break
			case Diacritic::TANWEEN_DAMMAH:
				sound += "un"
				break
		}
	}

	return sound
}
/// <summary>
/// Returns the sound that a Letter makes, with the option to visualize its Diacritics
/// </summary>
/// <param name="letter:">Letter to convert</param>
/// <param name="includeDiacritics:">if set to true, the Diacritics' sounds will be textualized as well (default true)</param>
/// <returns>std::string representation of the Letter's sound</returns>
std::string Arabic_old::sound_of(Letter letter, bool includeDiacritics)
{
	return sound_of(letter.GetCharacter(), letter.GetModification(), letter.GetDiacritics(), letter.GetPosition(), includeDiacritics)
}
/// <summary>
/// Returns the sound that a collection of Letters make, with the option to visualize their Diacritics
/// </summary>
/// <param name="ls:">Letters to convert</param>
/// <param name="includeDiacritics:">if set to true, the Diacritics' sounds will be textualized as well (default true)</param>
/// <returns>std::string representation of the Letters' sound</returns>
std::string Arabic_old::sound_of(std::vector<Letter> ls, bool includeDiacritics)
{
	std::string sound = ""

	for (auto& letter : ls)
		sound += sound_of(letter, includeDiacritics)

	return sound
}
/// <summary>
/// Returns the sound that a Word makes, with the option to visualize their Diacritics
/// </summary>
/// <param name="w:">Word to convert</param>
/// <param name="includeDiacritics:">if set to true, the Diacritics' sounds will be textualized as well (default true)</param>
/// <returns>std::string representation of the Word's sound</returns>
std::string Arabic_old::sound_of(Word w, bool includeDiacritics)
{
	std::string sound = ""

	for (auto& letter : w.GetLetters())
		sound += sound_of(letter, includeDiacritics)

	return sound
}
/// <summary>
/// Returns the sound that a sentance of Words makes, with the option to visualize its Diacritics
/// </summary>
/// <param name="ws:">sentance of Words to convert</param>
/// <param name="includeDiacritics:">if set to true, the Diacritics' sounds will be textualized as well (default true)</param>
/// <returns>std::string representation of the sentance of Words' sound</returns>
std::string sound_of(std::vector<Word> ws, bool includeDiacritics)
{
	std::string sound = sound_of(ws[0], includeDiacritics)

	for (unsigned int i = 1 i < ws.size() i++)
		sound += " " + sound_of(ws[i], includeDiacritics)

	return sound
}

/// <summary>
/// Checks if an ASCII value is a valid arabic character
/// </summary>
/// <param name="ascii:">ASCII value to analyze</param>
/// <param name="checkSpace:">consider a space as a valid character</param>
/// <returns>boolean that represents if the ASCII value is a valid arabic character</returns>
bool Arabic_old::is_character(int ascii, bool checkSpace)
{
	// Hamza to Ghayn
	if (ascii >= 1569 && ascii <= 1594)
		return true

	// Fa to Ya
	if (ascii >= 1601 && ascii <= 1610)
		return true

	// Alif Waslah and Space
	return ascii == 1649 || (checkSpace && ascii == 32)
}
/// <summary>
/// Checks if a hexadecimal value is a valid arabic character
/// </summary>
/// <param name="hex:">hexadecimal value to analyze</param>
/// <param name="checkSpace:">consider a space as a valid character</param>
/// <returns>boolean that represents if the hexadecimal value is a valid arabic character</returns>
bool Arabic_old::is_character(std::string hex, bool checkSpace)
{
	return is_character(to_ascii(hex), checkSpace)
}
/// <summary>
/// Checks if an ASCII value is a valid arabic diacritic
/// </summary>
/// <param name="ascii:">ASCII value to analyze</param>
/// <returns>boolean that represents if the ASCII value is a valid arabic diacritic</returns>
bool Arabic_old::is_diacritic(int ascii)
{
	// meem saakin - 06e2   <------------

	return ascii == 1600 || (ascii >= 1611 && ascii <= 1620) || ascii == 1648 || ascii == 1759 || ascii == 1760 || ascii == 1763 || ascii == 1765 || (ascii >= 1766 && ascii <= 1768) || (ascii >= 1770 && ascii <= 1772)
}
/// <summary>
/// Checks if a hexadecimal value is a valid arabic diacritic
/// </summary>
/// <param name="hex:">hexadecimal value to analyze</param>
/// <returns>boolean that represents if the hexadecimal value is a valid arabic diacritic</returns>
bool Arabic_old::is_diacritic(std::string hex)
{
	return is_diacritic(to_ascii(hex))
}

//TODO: is_arabic(int,bool) may have redundant logic in it: just use an OR statement

/// <summary>
/// Returns true if the ASCII value is a valid arabic character or diacritic, and false otherwise
/// </summary>
/// <param name="ascii:">ASCII value to analyze</param>
/// <returns>boolean representing if the ASCII value is a valid arabic character or diacritic</returns>
bool Arabic_old::is_arabic(int ascii, bool checkSpace)
{
	if (DiacriticByASCII.count(ascii) == 1)
		return is_arabic(DiacriticByASCII[ascii])

	return is_arabic(LetterByASCII[ascii], checkSpace)
}
/// <summary>
/// Returns true if a Character is a valid arabic ASCII value, and false otherwise
/// </summary>
/// <param name="ascii:">Character to analyze</param>
/// <returns>boolean representing if the Character is a valid arabic ASCII value</returns>
bool Arabic_old::is_arabic(Character character, bool checkSpace)
{
	return is_character(to_ascii(character), checkSpace)
}
/// <summary>
/// Returns true if a Diacritic is a valid arabic ASCII value, and false otherwise
/// </summary>
/// <param name="d:">Diacritic to analyze</param>
/// <returns>boolean representing if the Diacritic is a valid arabic ASCII value</returns>
bool Arabic_old::is_arabic(Diacritic d)
{
	return is_diacritic(to_ascii(d))
}
/// <summary>
/// Returns true if a Letter contains valid arabic ASCII values, and false otherwise
/// </summary>
/// <param name="rhs:">Letter to analyze</param>
/// <returns>boolean representing if the Letter contains valid arabic ASCII values</returns>
bool Arabic_old::is_arabic(Letter letter, bool checkSpace)
{
	for (auto& d : letter.GetDiacritics())
		if (!is_arabic(d))
			return false

	bool test = is_character(to_ascii(letter), checkSpace)

	return is_character(to_ascii(letter), checkSpace)
}
/// <summary>
/// Returns true if a Word contains valid arabic ASCII values, and false otherwise
/// </summary>
/// <param name="w:">Word to analyze</param>
/// <returns>boolean representing if the Word contains valid arabic ASCII values</returns>
bool Arabic_old::is_arabic(Word w, bool checkSpace)
{
	for (auto& letter: w.GetLetters())
		if (!is_arabic(letter, checkSpace))
			return false

	return true
}


///////////////////////////////////////////////////////////////////////////////
// Letter 
///////////////////////////////////////////////////////////////////////////////


/// <summary>
/// Default constructor for a Letter
/// </summary>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(Position position)
{
	Reset()

	this->position = position
}
/// <summary>
/// Letter constructor using an ASCII value
/// </summary>
/// <param name="ascii:">ASCII value to convert</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(int ascii, Position position) : Letter(position)
{
	SetFromASCII(ascii)
}
/// <summary>
/// Letter constructor using a hexadecimal value
/// </summary>
/// <param name="hex:">hexadecimal value to convert</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(std::string hex, Position position) : Letter(to_ascii(hex), position) {}
/// <summary>
/// Letter constructor using a set of ASCII values
/// </summary>
/// <param name="asciis:">ASCII values to convert, respectively organized as a Character, Modification, and Diacritics</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(std::vector<int> asciis, Position position) : Letter(position)
{
	if (asciis.size() > 0)
	{
		SetFromASCII(asciis[0])

		for (unsigned int i = 1 i < asciis.size() i++)
			if (is_diacritic(asciis[i]))
				AddDiacritic(asciis[i])
	}
	
}
/// <summary>
/// Letter constructor using a set of hexadecimal values
/// </summary>
/// <param name="hexes:">hexadecimal values to convert, respectively organized as a Character, Modification, and Diacritics</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(std::vector<std::string> hexes, Position position) : Letter()
{
	if (hexes.size() > 0)
	{
		SetFromASCII(to_ascii(hexes[0]))

		for (unsigned int i = 1 i < hexes.size() i++)
		{
			int ascii = to_ascii(hexes[i])

			if (is_diacritic(ascii))
				AddDiacritic(ascii)
		}
	}
}
/// <summary>
/// Letter constructor using a Character
/// </summary>
/// <param name="character:">Character to convert</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(Character character, Position position) : Letter(position)
{
	SetCharacter(character)
}
/// <summary>
/// Letter constructor using a Character and std::vector of Diacritics
/// </summary>
/// <param name="character:">Character to convert</param>
/// <param name="diacritics:">vector of accompanying Diacritics</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(Character character, std::vector<Diacritic> diacritics, Position position) : Letter(character, position)
{
	SetDiacritics(diacritics)
}
/// <summary>
/// Letter constructor using a Character and Modification
/// </summary>
/// <param name="character:">Character to convert</param>
/// <param name="modification:">the Character's attached Modification</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(Character character, Diacritic modification, Position position) : Letter(position)
{
	SetCharacter(character, modification)
}
/// <summary>
/// Letter constructor using a Character, Modification, and std::vector of Diacritics
/// </summary>
/// <param name="character:">Character to convert</param>
/// <param name="modification:">the Character's attached Modification</param>
/// <param name="diacritics:">vector of accompanying Diacritics</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(Character character, Diacritic modification, std::vector<Diacritic> diacritics, Position position) : Letter(character, modification, position)
{
	SetDiacritics(diacritics)
}
/// <summary>
/// Default destructor for a Letter
/// </summary>
Letter::~Letter()
{
	Reset()
}

/// <summary>
/// Resets all the values of a Letter
/// </summary>
void Letter::Reset()
{
	this->character = Character::NONE
	this->modification = Diacritic::NONE
	this->position = position
	diacritics.clear()
}

/// <summary>
/// Constructs a Letter (Character and Modification) from an ascii value
/// </summary>
/// <param name="ascii:">ASCII value to convert</param>
/// <returns>boolean that represents if the construction was successful or not</returns>
bool Letter::SetFromASCII(int ascii)
{
	if (is_arabic(ascii))
	{
		if (is_character(ascii))
		{
			this->character = LetterByASCII[ascii].GetCharacter()
			this->modification = LetterByASCII[ascii].GetModification()
		}
		else if (is_diacritic(ascii))
			this->diacritics.push_back(DiacriticByASCII[ascii])

		return true
	}

	return false
}
/// <summary>
/// Gets the Letter's "character" member
/// </summary>
/// <returns>a Character</returns>
Character Letter::GetCharacter() const
{
	return this->character
}
/// <summary>
/// Sets the Letter's "character" member, using a Character with the option to clear the modification
/// </summary>
/// <param name="character:">the Character to set</param>
/// <param name="clearModification:">clears the "modification" member if set to true (default true)</param>
void Letter::SetCharacter(Character character, bool clearModification)
{
	this->character = character
	if (clearModification)
		this->modification = Diacritic::NONE
}
/// <summary>
/// Sets the Letter's "character" member, using a Character and Modification
/// </summary>
/// <param name="character:">the Character to set</param>
/// <param name="modification:">the Character's modification</param>
void Letter::SetCharacter(Character character, Diacritic modification)
{
	this->character = character
	this->modification = modification
}
/// <summary>
/// Sets the Letter's "character" member, using an ASCII value with the option to clear the modification
/// </summary>
/// <param name="ascii:">the ASCII value to convert</param>
/// <param name="clearModification:">clears the "modification" member if set to true (default true)</param>
void Letter::SetCharacter(int ascii, bool clearModification)
{
	this->character = LetterByASCII[ascii].GetCharacter()
	if (clearModification)
		this->modification = Diacritic::NONE
}
/// <summary>
/// Sets the Letter's "character" member, using a hexadecimal value with the option to clear the modification
/// </summary>
/// <param name="hex:">the hexadecimal value to convert</param>
/// <param name="clearModification:">clears the "modification" member if set to true (default true)</param>
void Letter::SetCharacter(std::string hex, bool clearModification)
{
	SetCharacter(to_ascii(hex), clearModification)
}
/// <summary>
/// Gets the Letter's "modification" member
/// </summary>
/// <returns>a Character</returns>
Diacritic Letter::GetModification() const
{
	return this->modification
}
/// <summary>
/// Sets the Letter's "modification" member using a Diacritic
/// </summary>
/// <param name="modification:">the Character's modification</param>
void Letter::SetModification(Diacritic modification)
{
	this->modification = modification
}

/// <summary>
/// Gets the Letter's "diacritics" member
/// </summary>
/// <returns>a vector of Diacritics</returns>
std::vector<Diacritic> Letter::GetDiacritics()
{
	return this->diacritics
}
/// <summary>
/// Sets the Letter's "diacritics" member, using a vector of Diacritics
/// </summary>
/// <param name="diacritics:">the vector of Diacritics to add</param>
void Letter::SetDiacritics(std::vector<Diacritic> diacritics)
{
	ClearDiacritics()

	this->diacritics = diacritics
}
/// <summary>
/// Sets a single element in the Letter's "diacritics" member, using an index and Diacritic
/// </summary>
/// <param name="index:">the index to modify</param>
/// <param name="diacritic:">the Diacritic to set</param>
void Letter::SetDiacritic(int index, Diacritic diacritic)
{
	this->diacritics[index] = diacritic
}
/// <summary>
/// Appends a Diacritic to the Letter's "diacritics" member
/// </summary>
/// <param name="diacritic:">the Diacritic to add</param>
void Letter::AddDiacritic(Diacritic diacritic)
{
	if (diacritic != Diacritic::NONE)
	{
		this->diacritics.push_back(diacritic)
	}
}
/// <summary>
/// Appends a Diacritic from an ASCII value to the Letter's "diacritics" member
/// </summary>
/// <param name="ascii:">the Diacritic (as an ASCII value) to add</param>
void Letter::AddDiacritic(int ascii)
{
	if (is_diacritic(ascii))
	{
		Diacritic d = DiacriticByASCII[ascii]

		if (d != Diacritic::NONE)
			this->diacritics.push_back(d)
	}
}
/// <summary>
/// Appends a Diacritic from a hexadecimal value to the Letter's "diacritics" member
/// </summary>
/// <param name="hex:">the Diacritic (as a hexadecimal value) to add</param>
void Letter::AddDiacritic(std::string hex)
{
	AddDiacritic(to_ascii(hex))
}
/// <summary>
/// Removes a Diacritic from the Letter's "diacritics" member by index
/// </summary>
/// <param name="index:">the index to remove</param>
void Letter::RemoveDiacritic(int index)
{
	Utilities::remove_at(this->diacritics, index)
}
/// <summary>
/// Removes all occurances of a Diacritic from the Letter's "diacritics" member
/// </summary>
/// <param name="diacritic:">the Diacritic to remove</param>
void Letter::RemoveDiacritic(Diacritic diacritic)
{
	Utilities::remove_all(this->diacritics, diacritic)
}
/// <summary>
/// Clears the Letter's "diacritics" member
/// </summary>
void Letter::ClearDiacritics()
{
	this->diacritics.clear()
}

/// <summary>
/// Gets a Letter's "position" member
/// </summary>
/// <returns>the Letter's Position</returns>
Position Letter::GetPosition() const
{
	return this->position
}
/// <summary>
/// Sets the Letter's "position" member using a Position
/// </summary>
/// <param name="position:">the Position to be set</param>
void Letter::SetPosition(Position position)
{
	this->position = position
}

/// <summary>
/// Gets all ASCII values attributed to a Letter
/// </summary>
/// <returns>a std::vector of ASCII values that respectively represent the Character, modification, and Diacritics</returns>
std::vector<int> Letter::GetASCII() const
{
	std::vector<int> ret

	if (this->character != Character::NONE)
		ret.push_back(to_ascii(this->character))

	int ascii = to_ascii(this->modification)
	if (is_diacritic(ascii))
		ret.push_back(ascii)

	for (auto& d : this->diacritics)
	{
		ascii = to_ascii(d)
		if (is_diacritic(ascii))
			ret.push_back(ascii)
	}

	return ret
}
/// <summary>
/// Gets all hexadecimal values attributed to a Letter
/// </summary>
/// <returns>a std::vector of hexadecimal values that respectively represent the Character, modification, and Diacritics</returns>
std::vector<std::string> Letter::GetHex() const
{
	std::vector<std::string> ret

	if (this->character != Character::NONE)
		ret.push_back(to_hex(this->character))

	std::string hex = to_hex(this->modification)
	if (is_diacritic(hex))
		ret.push_back(hex)

	for (auto& d : this->diacritics)
	{
		hex = to_hex(d)
		if (is_diacritic(hex))
			ret.push_back(hex)
	}

	return ret
}

/// <summary>
/// Gets the Abjad value of the Letter
/// </summary>
/// <returns>an integer that represents the Letter's Abjad value</returns>
int Letter::GetAbjadValue()
{
	return abjad_value(*this)
}
/// <summary>
/// Gets the sequential value of the Letter
/// </summary>
/// <returns>an integer that represents the Letter's sequential value</returns>
int Letter::GetSequentialValue()
{
	return sequential_value(*this)
}

/// <summary>
/// Transliterates the Letter, with the option to add a space at the end
/// </summary>
/// <param name="addSpace:">if set true, a space will be added at the end</param>
/// <returns>a std::string that represents the Letter's transliteration</returns>
std::string Letter::to_string(bool addSpace)
{
	return sound_of(*this) + (addSpace ? " " : "")
}

/// <summary>
/// The Letter's equality operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are equal</returns>
bool Letter::operator ==(const Letter& rhs)
{
	if (this->diacritics.size() != rhs.diacritics.size())
		return false

	for (unsigned int i = 0 i < rhs.diacritics.size() i++)
		if (this->diacritics[i] != rhs.diacritics[i])
			return false

	return this->character == rhs.character && this->modification == rhs.modification
}
/// <summary>
/// The Letter's inequality operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are not equal</returns>
bool Letter::operator !=(const Letter& rhs)
{
	return !(*this == rhs)
}
/// <summary>
/// The Letter's less-than operator (primarily used to allow the use of a Letter key in an std::map)
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are equal</returns>
bool Letter::operator <(const Letter& rhs) const
{
	return abjad_value(*this) < abjad_value(rhs)
}

/// <summary>
/// Gets the total amount of ASCII values that can be attributed to a Letter
/// </summary>
/// <returns>integer that represents the number of all the Letter's ASCII values</returns>
int Letter::ASCIICount() const
{
	return diacritics.size() + (int)is_arabic(this->character, true)
}
/// <summary>
/// Gets the number of the Letter's diacritics
/// </summary>
/// <returns>integer that represents the number of the Letter's diacritics</returns>
int Letter::DiacriticCount() const
{
	return diacritics.size()
}

/// <summary>
/// Tests the Letter to confirm all its characters are Arabic
/// </summary>
/// <param name="checkCharacter:">allow the checking of the "character" member</param>
/// <param name="checkDiacritic:">allow the checking of the "diacritics" member</param>
/// <param name="checkSpace:">if set to true, spaces will be considered as valid characters</param>
/// <returns></returns>
bool Letter::IsArabic(bool checkCharacter, bool checkDiacritic, bool checkSpace)
{
	if (checkCharacter && (this->character == Character::NONE || (!checkSpace && this->character == Character::SPACE)))
		return false
	if (checkDiacritic)
		for (auto& d : this->diacritics)
			if (!is_diacritic(to_ascii(d)))
				return false

	return true
}


///////////////////////////////////////////////////////////////////////////////
// Word 
///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Default constructor for an TextualPosition struct
/// </summary>
Word::Attributes::Attributes()
{
	this->type = Type::NONE
	this->tense = Tense::NONE
	this->quantity = Quantity::NONE
	this->gender = Gender::NONE
	this->person = Person::NONE
}
/// <summary>
/// TextualPosition struct constructor using a Type, Tense, Quantity, Gender, and Person
/// </summary>
/// <param name="type:">the Word's Type</param>
/// <param name="tense:">the Word's Tense</param>
/// <param name="quantity:">the Word's Quantity</param>
/// <param name="gender:">the Word's Gender</param>
/// <param name="person:">the Word's Person</param>
Word::Attributes::Attributes(Type type, Tense tense, Quantity quantity, Gender gender, Person person)
{
	this->type = type
	this->tense = tense
	this->quantity = quantity
	this->gender = gender
	this->person = person
}

/// <summary>
/// Default constructor for a Letter
/// </summary>
Word::Word()
{
	Reset()
}
/// <summary>
/// Word constructor using a Letter
/// </summary>
/// <param name="letter:">the Letter to add</param>
Word::Word(Letter letter) : Word()
{
	this->letters.push_back(letter)
}
/// <summary>
/// Word constructor using a std::vector of Letters
/// </summary>
/// <param name="letters:">the Letters that make up the Word</param>
Word::Word(std::vector<Letter> letters) : Word()
{
	this->letters = letters
}
/// <summary>
/// Word constructor using a std::vector of ASCII values
/// </summary>
/// <param name="asciis:">the ASCII values that represent the Word's letters</param>
Word::Word(std::vector<int> asciis) : Word()
{
	for (unsigned int i = 0 i < asciis.size() i++)
		if (is_character(asciis[i]))
			this->letters.push_back(LetterByASCII[asciis[i]])
}
/// <summary>
/// Word constructor using a std::vector of hexadecimal values
/// </summary>
/// <param name="hexes:">the hexadecimal values that represent the Word's letters</param>
Word::Word(std::vector<std::string> hexes) : Word()
{
	for (unsigned int i = 0 i < hexes.size() i++)
	{
		int ascii = to_ascii(hexes[i])

		if (is_character(ascii))
			this->letters.push_back(LetterByASCII[ascii])
	}
}
/// <summary>
/// Default destructor for a Word
/// </summary>
Word::~Word()
{
	Reset()
}

/// <summary>
/// Gets the Letters in a Word
/// </summary>
/// <returns>a vector of the Word's Letters</returns>
std::vector<Letter> Word::GetLetters() const
{
	return this->letters
}
/// <summary>
/// Sets all the Word's Letters
/// </summary>
/// <param name="letters:">the Letters to set</param>
/// <param name="clearRoot:">if set to true, then the Word's "root" member will be cleared</param>
void Word::SetLetters(std::vector<Letter> letters, bool clearRoot)
{
	this->letters.clear()
	this->letters = letters

	if (clearRoot)
		this->root.clear()
}
/// <summary>
/// Sets a Word's Letter at an index
/// </summary>
/// <param name="index:">the index of the changing Letter</param>
/// <param name="letter:">the Letter to set</param>
/// <param name="clearRoot:">if set to true, then the Word's "root" member will be cleared</param>
void Word::SetLetter(int index, Letter letter, bool clearRoot)
{
	this->letters[index] = letter

	if (clearRoot)
		this->root.clear()
}
/// <summary>
/// Adds a new Letter to a Word
/// </summary>
/// <param name="letter:">the Letter to add</param>
/// <param name="clearRoot"">if set to true, then the Word's "root" member will be cleared</param>
void Word::AddLetter(Letter letter, bool clearRoot)
{
	this->letters.push_back(letter)

	if (clearRoot)
		this->root.clear()
}
/// <summary>
/// Inserts a Word's Letter after an index
/// </summary>
/// <param name="index:">the index before the inserting Letter</param>
/// <param name="letter:">the Letter to set</param>
/// <param name="clearRoot:">if set to true, then the Word's "root" member will be cleared</param>
void Word::InsertLetter(int index, Letter letter, bool clearRoot)
{
	Utilities::insert_at(this->letters, index, letter)

	if (clearRoot)
		this->root.clear()
}
/// <summary>
/// Revoves a Word's Letter at an index
/// </summary>
/// <param name="index:">the index of the Letter to be removed</param>
/// <param name="clearRoot:">if set to true, then the Word's "root" member will be cleared</param>
void Word::RemoveLetter(int index, bool clearRoot)
{
	Utilities::remove_at(this->letters, index)

	if (clearRoot)
		this->root.clear()
}

/// <summary>
/// Gets the root Characters of a Word
/// </summary>
/// <returns>a vector of the root's Characters</returns>
std::vector<Character> Word::GetRoot() const
{
	return this->root
}
/// <summary>
/// Sets the root Characters of a Word
/// </summary>
/// <param name="root:">a std::vector of Characters to replace the "root" member</param>
void Word::SetRoot(std::vector<Character> root)
{
	this->root.clear()
	this->root = root
}
/// <summary>
/// Sets the Word's root's Character at an index
/// </summary>
/// <param name="index:">the index of interest</param>
/// <param name="character:">the root's Character to be the replacement</param>
void Word::SetRootCharacter(int index, Character character)
{
	this->root[index] = character
}
/// <summary>
/// Adds a new Character at the end of the "root" member
/// </summary>
/// <param name="character:">the Character to be the added to the "root" member</param>
void Word::AddRootCharacter(Character character)
{
	this->root.push_back(character)
}
/// <summary>
/// Inserts a new Character at an index of the "root" member
/// </summary>
/// <param name="index:">the index of interest</param>
/// <param name="character:">the Character to be the inserted into the "root" member</param>
void Word::InsertRootCharacter(int index, Character character)
{
	Utilities::insert_at(this->root, index, character)
}
/// <summary>
/// Removes a Character at an index of the "root" member
/// </summary>
/// <param name="index:">the index with the desired Character to remove</param>
void Word::RemoveRootCharacter(int index)
{
	Utilities::remove_at(this->root, index)
}

/// <summary>
/// Sets the Word's "attributes" member
/// </summary>
/// <param name="attributes:">the Attributes to set</param>
void Word::SetAttributes(Attributes attributes)
{
	this->attributes = attributes
}
/// <summary>
/// Gets the Word's "attributes" member
/// </summary>
/// <returns>the Word's "attributes" member</returns>
Word::Attributes Word::GetAttributes() const
{
	return this->attributes
}
/// <summary>
/// Sets the Word's Type in the "attributes" member
/// </summary>
/// <param name="type:">the Type to set</param>
void Word::SetType(Type type)
{
	this->attributes.type = type
}
/// <summary>
/// Sets the Word's Tense in the "attributes" member
/// </summary>
/// <param name="tense:">the Tense to set</param>
void Word::SetTense(Tense tense)
{
	this->attributes.tense = tense
}
/// <summary>
/// Sets the Word's Quantity in the "attributes" member
/// </summary>
/// <param name="quantity:">the Quantity to set</param>
void Word::SetQuantity(Quantity quantity)
{
	this->attributes.quantity = quantity
}
/// <summary>
/// Sets the Word's Gender in the "attributes" member
/// </summary>
/// <param name="gender:">the Gender to set</param>
void Word::SetGender(Gender gender)
{
	this->attributes.gender = gender
}
/// <summary>
/// Sets the Word's Person in the "attributes" member
/// </summary>
/// <param name="person:">the Person to set</param>
void Word::SetPerson(Person person)
{
	this->attributes.person = person
}

/// <summary>
/// Clears the Word's "attributes" member
/// </summary>
void Word::ResetAttributes()
{
	this->attributes.type = Type::NONE
	this->attributes.tense = Tense::NONE
	this->attributes.quantity = Quantity::NONE
	this->attributes.gender = Gender::NONE
	this->attributes.person = Person::NONE
}
/// <summary>
/// Resets the whole Word to default values
/// </summary>
void Word::Reset()
{
	letters.clear()
	root.clear()

	ResetAttributes()
}

/// <summary>
/// Gets all ASCII values attributed to a Word
/// </summary>
/// <returns>a std::vector of ASCII values that represent the Word</returns>
std::vector<int> Word::GetASCII() const
{
	std::vector<int> asciis

	for (unsigned int i = 0 i < this->Count() i++)
		Utilities::addrange(asciis, this->letters[i].GetASCII())

	return asciis
}
/// <summary>
/// Gets all hexadecimal values attributed to a Word
/// </summary>
/// <returns>a std::vector of hexadecimal values that represent the Word</returns>
std::vector<std::string> Word::GetHex() const
{
	std::vector<std::string> hexes

	for (unsigned int i = 0 i < this->Count() i++)
		Utilities::addrange(hexes, this->letters[i].GetHex())

	return hexes
}

/// <summary>
/// Gets the Abjad value of the Word
/// </summary>
/// <returns>an integer that represents the Word's Abjad value</returns>
int Word::GetAbjadValue() const
{
	return abjad_value(*this)
}
/// <summary>
/// Gets the sequential value of the Word
/// </summary>
/// <returns>an integer that represents the Word's sequential value</returns>
int Word::GetSequentialValue() const
{
	return sequential_value(*this)
}

/// <summary>
/// Transliterates the Word, with the option to add a space at the end
/// </summary>
/// <param name="addSpace:">if set true, a space will be added at the end</param>
/// <returns>a std::string that represents the Word's transliteration</returns>
std::string Word::to_string(bool addSpace)
{
	return sound_of(*this) + (addSpace ? " " : "")
}

Letter& Word::operator [](int index)
{
	return this->letters[index]
}
/// <summary>
/// The Word's equality operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are equal</returns>
bool Word::operator ==(const Word& rhs)
{
	if (this->Count() != rhs.Count())
		return false

	for (unsigned int i = 0 i < this->Count() i++)
		if (this->letters[i] != rhs.letters[i])
			return false
	
	return true
}
/// <summary>
/// The Word's inequality operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are not equal</returns>
bool Word::operator !=(const Word& rhs)
{
	return !(*this == rhs)
}
/// <summary>
/// The Word's add operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>a new Word with the Letters from "rhs" appended to the current Word</returns>
Word Word::operator +(const Letter& rhs)
{
	AddLetter(rhs)
	return *this
}
/// <summary>
/// The Word's decrement operator
/// </summary>
/// <returns>the same word with the last Letter removed</returns>
Word& Word::operator --()
{
	this->letters.pop_back()
	return *this
}

/// <summary>
/// Gets the number of Letters in the Word
/// </summary>
/// <returns>integer that represents the number of letters in the Word</returns>
int Word::Count() const
{
	return LetterCount()
}
/// <summary>
/// Gets the total amount of ASCII values that can be attributed to a Word
/// </summary>
/// <returns>integer that represents the number of all the Word's ASCII values</returns>
int Word::ASCIICount() const
{
	int sum = 0

	for (auto letter : this->letters)
		sum += letter.ASCIICount()

	return sum
}
/// <summary>
/// Gets the number of Characters in the Word
/// </summary>
/// <returns>integer that represents the number of Characters in the Word</returns>
int Word::CharacterCount() const
{
	int sum = 0

	for (auto letter : this->letters)
		if (letter.GetCharacter() != Character::NONE)
			sum ++

	return sum
}
/// <summary>
/// Gets the number of Letters in the Word
/// </summary>
/// <returns>integer that represents the number of letters in the Word</returns>
int Word::LetterCount() const
{
	return this->letters.size()
}
/// <summary>
/// Gets the number of Diacritics in the Word
/// </summary>
/// <returns>integer that represents the number of Diacritics in the Word</returns>
int Word::DiacriticCount() const
{
	int sum = 0

	for (auto letter : this->letters)
		sum += letter.DiacriticCount()

	return sum
}

/// <summary>
/// Gets the number of occurances of a specified Letter within a Word
/// </summary>
/// <param name="letter:">the Letter of interest</param>
/// <returns>integer representing the number of occurances of the desired Letter in the Word</returns>
int Word::OccuranceOf(Letter letter) const
{
	return Utilities::occurance_of(this->letters, letter)
}
*/