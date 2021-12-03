#include "Arabic.h"

using namespace Arabic;


///////////////////////////////////////////////////////////////////////////////
// Arabic 
///////////////////////////////////////////////////////////////////////////////


/// <summary>
/// Dictionary for looking up ASCII values by their respective Letters
/// </summary>
std::map<Letter, int> Arabic::ASCIIByLetter
{
	{Letter(Character::SPACE, Diacritic::NONE),				32},
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
};
/// <summary>
/// Dictionary for looking up Letters by their ASCII values
/// </summary>
std::map<int, Letter> Arabic::LetterByASCII
{
	{32,	Letter(Character::SPACE, Diacritic::NONE)},
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
};
/// <summary>
/// Dictionary for looking up ASCII values by their respective Diacritics
/// </summary>
std::map<Diacritic, int> Arabic::ASCIIByDiacritic
{
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
};
/// <summary>
/// Dictionary for looking up Diacritics by their ASCII values
/// </summary>
std::map<int, Diacritic> Arabic::DiacriticByASCII
{
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
};

/// <summary>
/// Converts an ascii value to a human-readable form
/// </summary>
/// <param name="ascii:">ascii value to convert</param>
/// <returns>string representation of an ascii value</returns>
std::string Arabic::to_string(int ascii)
{
	if (LetterByASCII.count(ascii) == 1)
		return LetterByASCII[ascii].to_string();
	else if (DiacriticByASCII.count(ascii) == 1)
		return to_string(DiacriticByASCII[ascii]);

	return "NONE";
}
/// <summary>
/// Converts a Character to a string
/// </summary>
/// <param name="c:">Character to convert</param>
/// <returns>string representation of a Character</returns>
std::string Arabic::to_string(Character c)
{
	switch (c)
	{
		case Character::NONE:
			return "NONE";
		case Character::SPACE:
			return "SPACE";
		case Character::HAMZAH:
			return "HAMZAH";
		case Character::ALIF:
			return "ALIF";
		case Character::BA:
			return "BA";
		case Character::JEEM:
			return "JEEM";
		case Character::DAL:
			return "DAL";
		case Character::HA:
			return "HA";
		case Character::WAW:
			return "WAW";
		case Character::ZAYN:
			return "ZAYN";
		case Character::HHA:
			return "HHA";
		case Character::TTA:
			return "TTA";
		case Character::YA:
			return "YA";
		case Character::KAF:
			return "KAF";
		case Character::LAM:
			return "LAM";
		case Character::MEEM:
			return "MEEM";
		case Character::NOON:
			return "NOON";
		case Character::SEEN:
			return "SEEN";
		case Character::AYN:
			return "AYN";
		case Character::FA:
			return "FA";
		case Character::SAD:
			return "SAD";
		case Character::QAF:
			return "QAF";
		case Character::RA:
			return "RA";
		case Character::SHEEN:
			return "SHEEN";
		case Character::TA:
			return "TA";
		case Character::THA:
			return "THA";
		case Character::KHA:
			return "KHA";
		case Character::DHAL:
			return "DHAL";
		case Character::DAD:
			return "DAD";
		case Character::THHA:
			return "THHA";
		case Character::GHAYN:
			return "GHAYN";
		case Character::ONE:
			return "ONE";
		case Character::TWO:
			return "TWO";
		case Character::THREE:
			return "THREE";
		case Character::FOUR:
			return "FOUR";
		case Character::FIVE:
			return "FIVE";
		case Character::SIX:
			return "SIX";
		case Character::SEVEN:
			return "SEVEN";
		case Character::EIGHT:
			return "EIGHT";
		case Character::NINE:
			return "NINE";
		case Character::ZERO:
			return "ZERO";
	}

	return "NONE";
}
/// <summary>
/// Converts a Position to a string
/// </summary>
/// <param name="p:">Position to convert</param>
/// <returns>string representation of a Position</returns>
std::string Arabic::to_string(Position p)
{
	switch (p)
	{
		case Position::ISOLATED:
			return "ISOLATED";
		case Position::BEGINNING:
			return "BEGINNING";
		case Position::MIDDLE:
			return "MIDDLE";
		case Position::END:
			return "END";
	}

	return "NONE";
}
/// <summary>
/// Converts a Diacritic to a string
/// </summary>
/// <param name="d:">Diacritic to convert</param>
/// <returns>string representation of a Diacritic</returns>
std::string Arabic::to_string(Diacritic d)
{
	switch (d)
	{
		case Diacritic::HAMZAH:
			return "HAMZAH";
		case Diacritic::HAMZAH_ABOVE:
			return "HAMZAH_ABOVE";
		case Diacritic::HAMZAH_BELOW:
			return "HAMZAH_BELOW";
		case Diacritic::HAMZAH_MIDDLE:
			return "HAMZAH_MIDDLE";
		case Diacritic::FATHAH:
			return "FATHAH";
		case Diacritic::KASRAH:
			return "KASRAH";
		case Diacritic::DAMMAH:
			return "DAMMAH";
		case Diacritic::SUKOON:
			return "SUKOON";
		case Diacritic::SUKOON_WASLAH:
			return "SUKOON_WASLAH";
		case Diacritic::SHADDAH:
			return "SHADDAH";
		case Diacritic::MADDAH:
			return "MADDAH";
		case Diacritic::TANWEEN_FATHAH:
			return "TANWEEN_FATHAH";
		case Diacritic::TANWEEN_KASRAH:
			return "TANWEEN_KASRAH";
		case Diacritic::TANWEEN_DAMMAH:
			return "TANWEEN_DAMMAH";
		case Diacritic::ALIF_WASLAH:
			return "ALIF_WASLAH";
		case Diacritic::ALIF_KHANJARIYAH:
			return "ALIF_KHANJARIYAH";
		case Diacritic::ALIF_MAQSURAH:
			return "ALIF_MAQSURAH";
		case Diacritic::MARBUTAH:
			return "MARBUTAH";
	}

	return "NONE";
}
/// <summary>
/// Converts a Word Type to a string
/// </summary>
/// <param name="t:">Word Type to convert</param>
/// <returns>string representation of a Word Type</returns>
std::string Arabic::to_string(Word::Type t)
{
	switch (t)
	{
		case Word::Type::NOUN:
			return "NOUN";
		case Word::Type::VERB:
			return "VERB";
		case Word::Type::ADJECTIVE:
			return "ADJECTIVE";
		case Word::Type::ADVERB:
			return "ADVERB";
		case Word::Type::PRONOUN:
			return "PRONOUN";
	}

	return "NONE";
}
/// <summary>
/// Converts a Word Tense to a string
/// </summary>
/// <param name="t:">Word Tense to convert</param>
/// <returns>string representation of a Word Tense</returns>
std::string Arabic::to_string(Word::Tense t)
{
	switch (t)
	{
		case Word::Tense::ROOT:
			return "ROOT";
		case Word::Tense::PAST:
			return "PAST";
		case Word::Tense::PRESENT:
			return "PRESENT";
		case Word::Tense::FUTURE:
			return "FUTURE";
		case Word::Tense::COMMAND:
			return "COMMAND";
	}

	return "NONE";
}
/// <summary>
/// Converts a Word Person to a string
/// </summary>
/// <param name="p:">Word Person to convert</param>
/// <returns>string representation of a Word Person</returns>
std::string Arabic::to_string(Word::Person p)
{
	switch (p)
	{
		case Word::Person::FIRST:
			return "FIRST";
		case Word::Person::SECOND:
			return "SECOND";
		case Word::Person::THRID:
			return "THRID";
		case Word::Person::FOURTH:
			return "FOURTH";
	}
	
	return "NONE";
}
/// <summary>
/// Converts a Word Quantity to a string
/// </summary>
/// <param name="q:">Word Quantity to convert</param>
/// <returns>string representation of a Word Quantity</returns>
std::string Arabic::to_string(Word::Quantity q)
{
	switch (q)
	{
		case Word::Quantity::SINGULAR:
			return "SINGULAR";
		case Word::Quantity::DUAL:
			return "DUAL";
		case Word::Quantity::PLURAL:
			return "PLURAL";
	}
	
	return "NONE";
}
/// <summary>
/// Converts a Word Gender to a string
/// </summary>
/// <param name="g:">Word Gender to convert</param>
/// <returns>string representation of a Word Gender</returns>
std::string Arabic::to_string(Word::Gender g)
{
	switch (g)
	{
		case Word::Gender::MASCULINE:
			return "MASCULINE";
		case Word::Gender::FEMININE:
			return "FEMININE";
	}
		
	return "NONE";
}

/// <summary>
/// Converts a hexadecimal to its ascii representation
/// </summary>
/// <param name="hex:">hexadecimal to convert</param>
/// <returns>ascii representation of a hexadecimal</returns>
int Arabic::to_ascii(std::string hex)
{
	int n = 0;
	std::stringstream ss;
	ss << std::hex << hex;
	ss >> n;
	return n;
}
/// <summary>
/// Converts a Character to its ascii representation
/// </summary>
/// <param name="c:">Character to convert</param>
/// <returns>ascii representation of a Character (without additional diacritics)</returns>
int Arabic::to_ascii(Character c)
{
	return ASCIIByLetter[Letter(c)];
}
/// <summary>
/// Converts a Diacritic to its ascii representation
/// </summary>
/// <param name="d:">Diacritic to convert</param>
/// <returns>ascii representation of a Diacritic</returns>
int Arabic::to_ascii(Diacritic d)
{
	return ASCIIByDiacritic[d];
}
/// <summary>
/// Converts a Letter to its ascii representation
/// </summary>
/// <param name="rhs:">Letter to convert</param>
/// <returns>ascii representation of a Letter</returns>
int Arabic::to_ascii(Letter l)
{
	return ASCIIByLetter[l];
}

/// <summary>
/// Converts an integer to its hexadecimal representation
/// </summary>
/// <param name="n:">integer to convert</param>
/// <returns>hexadecimal representation of an integer</returns>
std::string Arabic::to_hex(int n)
{
	std::stringstream ss;
	ss << std::hex << n;
	return ss.str();
}
/// <summary>
/// Converts a Character to its hexadecimal representation
/// </summary>
/// <param name="c:">Character to convert</param>
/// <returns>hexadecimal representation of a Character</returns>
std::string Arabic::to_hex(Character c)
{
	return to_hex(to_ascii(c));
}
/// <summary>
/// Converts a Diacritic to its hexadecimal representation
/// </summary>
/// <param name="d:">Diacritic to convert</param>
/// <returns>hexadecimal representation of a Diacritic</returns>
std::string Arabic::to_hex(Diacritic d)
{
	return to_hex(to_ascii(d));
}
/// <summary>
/// Converts a Letter to its hexadecimal representation
/// </summary>
/// <param name="rhs:">Letter to convert</param>
/// <returns>hexadecimal representation of a Letter</returns>
std::string Arabic::to_hex(Letter l)
{
	return to_hex(to_ascii(l));
}

/// <summary>
/// Returns the abjad value of a Character
/// </summary>
/// <param name="c:">Character to convert</param>
/// <returns>abjad value of a Character</returns>
int Arabic::abjad_value(Character c)
{
	return abs(static_cast<int>(c));
}
/// <summary>
/// Returns the abjad value of a Letter
/// </summary>
/// <param name="rhs:">Letter to convert</param>
/// <returns>abjad value of a Letter</returns>
int Arabic::abjad_value(Letter l)
{
	return abjad_value(l.GetCharacter());
}
/// <summary>
/// Returns the abjad value of a vector of Letters
/// </summary>
/// <param name="ls:">Letters to convert</param>
/// <returns>abjad value of a number of Letters</returns>
int Arabic::abjad_value(std::vector<Letter> ls)
{
	int sum = 0;

	for (auto& l : ls)
		sum += abjad_value(l);

	return sum;
}
/// <summary>
/// Returns the abjad value of a Word
/// </summary>
/// <param name="w:">Word to convert</param>
/// <returns>abjad value of a Word</returns>
int Arabic::abjad_value(Word w)
{
	int sum = 0;

	for (auto& l : w.GetLetters())
		sum += abjad_value(l);

	return sum;
}
/// <summary>
/// Returns the abjad value of a vector of Words
/// </summary>
/// <param name="ws:">Words to convert</param>
/// <returns>abjad value of a number of Words</returns>
int Arabic::abjad_value(std::vector<Word> ws)
{
	int sum = 0;

	for (auto& w : ws)
		sum += abjad_value(w);

	return sum;
}

//TODO: value of ya with alif maqsurah on it

/// <summary>
/// Returns the sequential value of a Character
/// </summary>
/// <param name="c:">Character to convert</param>
/// <returns>sequential value of a Character</returns>
int Arabic::sequential_value(Character c)
{
	switch (c)
	{
		case Character::HAMZAH:
		case Character::ALIF:
			return 1;
		case Character::BA:
			return 2;
		case Character::JEEM:
			return 3;
		case Character::DAL:
			return 4;
		case Character::HA:
			return 5;
		case Character::WAW:
			return 6;
		case Character::ZAYN:
			return 7;
		case Character::HHA:
			return 8;
		case Character::TTA:
			return 9;
		case Character::YA:
			return 10;
		case Character::KAF:
			return 11;
		case Character::LAM:
			return 12;
		case Character::MEEM:
			return 13;
		case Character::NOON:
			return 14;
		case Character::SEEN:
			return 15;
		case Character::AYN:
			return 16;
		case Character::FA:
			return 17;
		case Character::SAD:
			return 18;
		case Character::QAF:
			return 19;
		case Character::RA:
			return 20;
		case Character::SHEEN:
			return 21;
		case Character::TA:
			return 22;
		case Character::THA:
			return 23;
		case Character::KHA:
			return 24;
		case Character::DHAL:
			return 25;
		case Character::DAD:
			return 26;
		case Character::THHA:
			return 27;
		case Character::GHAYN:
			return 28;
	}

	return 0;
}
/// <summary>
/// Returns the sequential value of a Letter
/// </summary>
/// <param name="rhs:">Letter to convert</param>
/// <returns>sequential value of a Letter</returns>
int Arabic::sequential_value(Letter l)
{
	return sequential_value(l.GetCharacter());
}
/// <summary>
/// Returns the sequential value of a vector of Letters
/// </summary>
/// <param name="ls:">Letters to convert</param>
/// <returns>sequential value of a number of Letters</returns>
int Arabic::sequential_value(std::vector<Letter> ls)
{
	int sum = 0;

	for (auto& l : ls)
		sum += sequential_value(l);

	return sum;
}
/// <summary>
/// Returns the sequential value of a Word
/// </summary>
/// <param name="w:">Word to convert</param>
/// <returns>sequential value of a Word</returns>
int Arabic::sequential_value(Word w)
{
	int sum = 0;

	for (auto& l : w.GetLetters())
		sum += sequential_value(l);

	return sum;
}
/// <summary>
/// Returns the sequential value of a vector of Words
/// </summary>
/// <param name="ws:">Words to convert</param>
/// <returns>sequential value of a number of Words</returns>
int Arabic::sequential_value(std::vector<Word> ws)
{
	int sum = 0;

	for (auto& w : ws)
		sum += sequential_value(w);

	return sum;
}

/// <summary>
/// Returns the sound that a Letter makes, with the option to visualize its Diacritics
/// </summary>
/// <param name="l:">Letter to convert</param>
/// <param name="includeDiacritics:">if set to true, the Diacritics' sounds will be textualized as well (default true)</param>
/// <returns>std::string representation of the Letter's sound</returns>
std::string Arabic::sound_of(Letter l, bool includeDiacritics)
{
	std::string sound = "";

	switch (l.GetCharacter())
	{
		case Character::SPACE:
		{
			return " ";
			break;
		}
		case Character::HAMZAH: // includes the HAMZAH_MIDDLE modification
		{
			sound = "'";
			break;
		}
		case Character::ALIF:
		{
			switch (l.GetModification())
			{
				case Diacritic::MADDAH:
					sound = "AA";
					break;
				case Diacritic::HAMZAH_BELOW:
					sound = "I";
					break;
				default:
					if (l.GetModification() == Diacritic::ALIF_WASLAH)
						sound = "Ⱥ";
					else if (Utilities::index_of(l.GetDiacritics(), Diacritic::TANWEEN_FATHAH) == -1)	// if there is a TANWEEN_FATHAH, get sound from diacritic section
						sound = "A";
					break;
			}
			break;
		}
		case Character::BA:
		{
			sound = "B";
			break;
		}
		case Character::TA:
		{
			if  (l.GetModification() != Diacritic::MARBUTAH									// if it is not MARBUTAH
			 || (Utilities::index_of(l.GetDiacritics(), Diacritic::TANWEEN_FATHAH) != -1	// or
			 ||  Utilities::index_of(l.GetDiacritics(), Diacritic::TANWEEN_KASRAH) != -1	// if there is a TANWEEN
			 ||  Utilities::index_of(l.GetDiacritics(), Diacritic::TANWEEN_DAMMAH) != -1))
				sound = "T";
			else
				sound = "H";
			break;
		}
		case Character::THA:
		{
			sound = "Ṯ";
			break;
		}
		case Character::JEEM:
		{
			sound = "J";
			break;
		}
		case Character::HHA:
		{
			sound = "Ḥ";
			break;
		}
		case Character::KHA:
		{
			sound = "Ḵ";
			break;
		}
		case Character::DAL:
		{
			sound = "D";
			break;
		}
		case Character::DHAL:
		{
			sound = "Ḏ";
			break;
		}
		case Character::RA:
		{
			sound = "R";
			break;
		}
		case Character::ZAYN:
		{
			sound = "Z";
			break;
		}
		case Character::SEEN:
		{
			sound = "S";
			break;
		}
		case Character::SHEEN:
		{
			sound = "Š";
			break;
		}
		case Character::SAD:
		{
			sound = "Ṣ";
			break;
		}
		case Character::DAD:
		{
			sound = "Ḍ";
			break;
		}
		case Character::TTA:
		{
			sound = "Ṭ";
			break;
		}
		case Character::THHA:
		{
			sound = "Ẓ";
			break;
		}
		case Character::AYN:
		{
			sound = "3";
			break;
		}
		case Character::GHAYN:
		{
			sound = "Ġ";
			break;
		}
		case Character::FA:
		{
			sound = "F";
			break;
		}
		case Character::QAF:
		{
			sound = "Q";
			break;
		}
		case Character::KAF:
		{
			sound = "K";
			break;
		}
		case Character::LAM:
		{
			sound = "L";
			break;
		}
		case Character::MEEM:
		{
			sound = "M";
			break;
		}
		case Character::NOON:
		{
			sound = "N";
			break;
		}
		case Character::HA:
		{
			sound = "H";
			break;
		}
		case Character::WAW:
		{
			if (l.GetModification() == Diacritic::HAMZAH_ABOVE)
				sound = "'";
			else if (l.GetPosition() == Position::MIDDLE || l.GetPosition() == Position::END)
				sound = "Ū";
			else
				sound = "W";
			break;
		}
		case Character::YA:
		{
			if (l.GetModification() == Diacritic::ALIF_MAQSURAH)
				sound = "A";
			else if (l.GetPosition() == Position::MIDDLE)
				sound = "Ī";
			else
				sound = "Y";
			break;
		}
		default:	// no explicit character
		{
			if (Utilities::index_of<Diacritic>(l.GetDiacritics(), Diacritic::HAMZAH) != -1)
				sound = "'";
			else if (Utilities::index_of<Diacritic>(l.GetDiacritics(), Diacritic::ALIF_KHANJARIYAH) != -1)
				sound = "ā";
		}
	}
	
	if (!includeDiacritics)
		return sound;

	if (Utilities::index_of(l.GetDiacritics(), Diacritic::SHADDAH) != -1)
		sound += sound;
	if (Utilities::index_of(l.GetDiacritics(), Diacritic::MADDAH) != -1)
		sound += sound;

	// TODO: optimize loop by breaking upon diacritic
	for (auto& d: l.GetDiacritics())
	{
		switch (d)
		{
			case Diacritic::FATHAH:
				sound += "a";
				break;
			case Diacritic::KASRAH:
				sound += "i";
				break;
			case Diacritic::DAMMAH:
				sound += "u";
				break;
			case Diacritic::TANWEEN_FATHAH:
				sound += "an";
				break;
			case Diacritic::TANWEEN_KASRAH:
				sound += "in";
				break;
			case Diacritic::TANWEEN_DAMMAH:
				sound += "un";
				break;
		}
	}

	return sound;
}
/// <summary>
/// Returns the sound that a collection of Letters make, with the option to visualize their Diacritics
/// </summary>
/// <param name="ls:">Letters to convert</param>
/// <param name="includeDiacritics:">if set to true, the Diacritics' sounds will be textualized as well (default true)</param>
/// <returns>std::string representation of the Letters' sound</returns>
std::string Arabic::sound_of(std::vector<Letter> ls, bool includeDiacritics)
{
	std::string sound = "";

	for (auto& l : ls)
		sound += sound_of(l, includeDiacritics);

	return sound;
}
/// <summary>
/// Returns the sound that a Word makes, with the option to visualize their Diacritics
/// </summary>
/// <param name="w:">Word to convert</param>
/// <param name="includeDiacritics:">if set to true, the Diacritics' sounds will be textualized as well (default true)</param>
/// <returns>std::string representation of the Word's sound</returns>
std::string Arabic::sound_of(Word w, bool includeDiacritics)
{
	std::string sound = "";

	for (auto& l : w.GetLetters())
		sound += sound_of(l, includeDiacritics);

	return sound;
}

/// <summary>
/// Checks if an ASCII value is a valid arabic character
/// </summary>
/// <param name="ascii:">ASCII value to analyze</param>
/// <param name="checkSpace:">consider a space as a valid character</param>
/// <returns>boolean that represents if the ASCII value is a valid arabic character</returns>
bool Arabic::is_character(int ascii, bool checkSpace)
{
	// Hamza to Ghayn
	if (ascii >= 1569 && ascii <= 1594)
		return true;

	// Fa to Ya
	if (ascii >= 1601 && ascii <= 1610)
		return true;

	// Alif Waslah and Space
	return ascii == 1649 || (checkSpace && ascii == 32);
}
/// <summary>
/// Checks if a hexadecimal value is a valid arabic character
/// </summary>
/// <param name="hex:">hexadecimal value to analyze</param>
/// <param name="checkSpace:">consider a space as a valid character</param>
/// <returns>boolean that represents if the hexadecimal value is a valid arabic character</returns>
bool Arabic::is_character(std::string hex, bool checkSpace)
{
	return is_character(to_ascii(hex), checkSpace);
}
/// <summary>
/// Checks if an ASCII value is a valid arabic diacritic
/// </summary>
/// <param name="ascii:">ASCII value to analyze</param>
/// <returns>boolean that represents if the ASCII value is a valid arabic diacritic</returns>
bool Arabic::is_diacritic(int ascii)
{
	// meem saakin - 06e2   <------------

	return (ascii >= 1611 && ascii <= 1620) || ascii == 1648 || ascii == 1759;
}
/// <summary>
/// Checks if a hexadecimal value is a valid arabic diacritic
/// </summary>
/// <param name="hex:">hexadecimal value to analyze</param>
/// <returns>boolean that represents if the hexadecimal value is a valid arabic diacritic</returns>
bool Arabic::is_diacritic(std::string hex)
{
	return is_diacritic(to_ascii(hex));
}

/// <summary>
/// Returns true if the ASCII value is a valid arabic character or diacritic, and false otherwise
/// </summary>
/// <param name="ascii:">ASCII value to analyze</param>
/// <returns>boolean representing if the ASCII value is a valid arabic character or diacritic</returns>
bool Arabic::is_arabic(int ascii)
{
	if (LetterByASCII.count(ascii) == 1)
		return is_arabic(LetterByASCII[ascii]);

	return is_arabic(DiacriticByASCII[ascii]);
}
/// <summary>
/// Returns true if a Character is a valid arabic ASCII value, and false otherwise
/// </summary>
/// <param name="ascii:">Character to analyze</param>
/// <returns>boolean representing if the Character is a valid arabic ASCII value</returns>
bool Arabic::is_arabic(Character c, bool checkSpace)
{
	return is_character(to_ascii(c), checkSpace);
}
/// <summary>
/// Returns true if a Diacritic is a valid arabic ASCII value, and false otherwise
/// </summary>
/// <param name="d:">Diacritic to analyze</param>
/// <returns>boolean representing if the Diacritic is a valid arabic ASCII value</returns>
bool Arabic::is_arabic(Diacritic d)
{
	int ascii = to_ascii(d);

	// meem saakin - 06e2   <------------

	return (ascii >= 1611 && ascii <= 1620) || ascii == 1648 || ascii == 1759;
}
/// <summary>
/// Returns true if a Letter contains valid arabic ASCII values, and false otherwise
/// </summary>
/// <param name="rhs:">Letter to analyze</param>
/// <returns>boolean representing if the Letter contains valid arabic ASCII values</returns>
bool Arabic::is_arabic(Letter l, bool checkSpace)
{
	for (auto& d : l.GetDiacritics())
		if (!is_arabic(d))
			return false;

	return is_character(to_ascii(l), checkSpace);
}
/// <summary>
/// Returns true if a Word contains valid arabic ASCII values, and false otherwise
/// </summary>
/// <param name="w:">Word to analyze</param>
/// <returns>boolean representing if the Word contains valid arabic ASCII values</returns>
bool Arabic::is_arabic(Word w, bool checkSpace)
{
	for (auto& l: w.GetLetters())
		if (!is_arabic(l, checkSpace))
			return false;

	return true;
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
	Reset();

	this->position = position;
}
/// <summary>
/// Letter constructor using an ASCII value
/// </summary>
/// <param name="ascii:">ASCII value to convert</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(int ascii, Position position) : Letter(position)
{
	SetFromASCII(ascii);
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
		SetFromASCII(asciis[0]);

		for (unsigned int i = 1; i < asciis.size(); i++)
			if (is_diacritic(asciis[i]))
				AddDiacritic(asciis[i]);
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
		SetFromASCII(to_ascii(hexes[0]));

		for (unsigned int i = 1; i < hexes.size(); i++)
		{
			int ascii = to_ascii(hexes[i]);

			if (is_diacritic(ascii))
				AddDiacritic(ascii);
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
	SetCharacter(character);
}
/// <summary>
/// Letter constructor using a Character and std::vector of Diacritics
/// </summary>
/// <param name="character:">Character to convert</param>
/// <param name="diacritics:">vector of accompanying Diacritics</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(Character character, std::vector<Diacritic> diacritics, Position position) : Letter(character, position)
{
	SetDiacritics(diacritics);
}
/// <summary>
/// Letter constructor using a Character and Modification
/// </summary>
/// <param name="character:">Character to convert</param>
/// <param name="modification:">the Character's attached Modification</param>
/// <param name="position:">the Position of the letter in a word (default NONE)</param>
Letter::Letter(Character character, Diacritic modification, Position position) : Letter(position)
{
	SetCharacter(character, modification);
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
	SetDiacritics(diacritics);
}
/// <summary>
/// Default destructor for a Letter
/// </summary>
Letter::~Letter()
{
	Reset();
}

/// <summary>
/// Resets all the values of a Letter
/// </summary>
void Letter::Reset()
{
	this->character = Character::NONE;
	this->modification = Diacritic::NONE;
	this->position = position;
	diacritics.clear();
}

/// <summary>
/// Constructs a Letter (Character and Modification) from an ascii value
/// </summary>
/// <param name="ascii:">ASCII value to convert</param>
/// <returns>boolean that represents if the construction was successful or not</returns>
bool Letter::SetFromASCII(int ascii)
{
	if (is_arabic(ascii))
		if (is_character(ascii))
		{
			this->character = LetterByASCII[ascii].GetCharacter();
			this->modification = LetterByASCII[ascii].GetModification();
		}
		else if (is_diacritic(ascii))
			this->diacritics.push_back(DiacriticByASCII[ascii]);

	return false;
}
/// <summary>
/// Gets the Letter's "character" member
/// </summary>
/// <returns>a Character</returns>
Character Letter::GetCharacter() const
{
	return this->character;
}
/// <summary>
/// Sets the Letter's "character" member, using a Character with the option to clear the modification
/// </summary>
/// <param name="character:">the Character to set</param>
/// <param name="clearModification:">clears the "modification" member if set to true (default true)</param>
void Letter::SetCharacter(Character character, bool clearModification)
{
	this->character = character;
	if (clearModification)
		this->modification = Diacritic::NONE;
}
/// <summary>
/// Sets the Letter's "character" member, using a Character and Modification
/// </summary>
/// <param name="character:">the Character to set</param>
/// <param name="modification:">the Character's modification</param>
void Letter::SetCharacter(Character character, Diacritic modification)
{
	this->character = character;
	this->modification = modification;
}
/// <summary>
/// Sets the Letter's "character" member, using an ASCII value with the option to clear the modification
/// </summary>
/// <param name="ascii:">the ASCII value to convert</param>
/// <param name="clearModification:">clears the "modification" member if set to true (default true)</param>
void Letter::SetCharacter(int ascii, bool clearModification)
{
	this->character = LetterByASCII[ascii].GetCharacter();
	if (clearModification)
		this->modification = Diacritic::NONE;
}
/// <summary>
/// Sets the Letter's "character" member, using a hexadecimal value with the option to clear the modification
/// </summary>
/// <param name="hex:">the hexadecimal value to convert</param>
/// <param name="clearModification:">clears the "modification" member if set to true (default true)</param>
void Letter::SetCharacter(std::string hex, bool clearModification)
{
	SetCharacter(to_ascii(hex), clearModification);
}
/// <summary>
/// Gets the Letter's "modification" member
/// </summary>
/// <returns>a Character</returns>
Diacritic Letter::GetModification() const
{
	return this->modification;
}
/// <summary>
/// Sets the Letter's "modification" member using a Diacritic
/// </summary>
/// <param name="modification:">the Character's modification</param>
void Letter::SetModification(Diacritic modification)
{
	this->modification = modification;
}

/// <summary>
/// Gets the Letter's "diacritics" member
/// </summary>
/// <returns>a vector of Diacritics</returns>
std::vector<Diacritic> Letter::GetDiacritics()
{
	return this->diacritics;
}
/// <summary>
/// Sets the Letter's "diacritics" member, using a vector of Diacritics
/// </summary>
/// <param name="diacritics:">the vector of Diacritics to add</param>
void Letter::SetDiacritics(std::vector<Diacritic> diacritics)
{
	ClearDiacritics();

	this->diacritics = diacritics;
}
/// <summary>
/// Sets a single element in the Letter's "diacritics" member, using an index and Diacritic
/// </summary>
/// <param name="index:">the index to modify</param>
/// <param name="diacritic:">the Diacritic to set</param>
void Letter::SetDiacritic(int index, Diacritic diacritic)
{
	this->diacritics[index] = diacritic;
}
/// <summary>
/// Appends a Diacritic to the Letter's "diacritics" member
/// </summary>
/// <param name="diacritic:">the Diacritic to add</param>
void Letter::AddDiacritic(Diacritic diacritic)
{
	if (diacritic != Diacritic::NONE)
	{
		this->diacritics.push_back(diacritic);
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
		Diacritic d = DiacriticByASCII[ascii];

		if (d != Diacritic::NONE)
			this->diacritics.push_back(d);
	}
}
/// <summary>
/// Appends a Diacritic from a hexadecimal value to the Letter's "diacritics" member
/// </summary>
/// <param name="hex:">the Diacritic (as a hexadecimal value) to add</param>
void Letter::AddDiacritic(std::string hex)
{
	AddDiacritic(to_ascii(hex));
}
/// <summary>
/// Removes a Diacritic from the Letter's "diacritics" member by index
/// </summary>
/// <param name="index:">the index to remove</param>
void Letter::RemoveDiacritic(int index)
{
	Utilities::remove_at(this->diacritics, index);
}
/// <summary>
/// Removes all occurances of a Diacritic from the Letter's "diacritics" member
/// </summary>
/// <param name="diacritic:">the Diacritic to remove</param>
void Letter::RemoveDiacritic(Diacritic diacritic)
{
	Utilities::remove_all(this->diacritics, diacritic);
}
/// <summary>
/// Clears the Letter's "diacritics" member
/// </summary>
void Letter::ClearDiacritics()
{
	this->diacritics.clear();
}

/// <summary>
/// Gets a Letter's "position" member
/// </summary>
/// <returns>the Letter's Position</returns>
Position Letter::GetPosition() const
{
	return this->position;
}
/// <summary>
/// Sets the Letter's "position" member using a Position
/// </summary>
/// <param name="position:">the Position to be set</param>
void Letter::SetPosition(Position position)
{
	this->position = position;
}

/// <summary>
/// Gets all ASCII values attributed to a Letter
/// </summary>
/// <returns>a std::vector of ASCII values that respectively represent the Character, modification, and Diacritics</returns>
std::vector<int> Letter::GetASCII() const
{
	std::vector<int> ret;

	if (this->character != Character::NONE)
		ret.push_back(to_ascii(this->character));

	int ascii = to_ascii(this->modification);
	if (is_diacritic(ascii))
		ret.push_back(ascii);

	for (auto& d : this->diacritics)
	{
		ascii = to_ascii(d);
		if (is_diacritic(ascii))
			ret.push_back(ascii);
	}

	return ret;
}
/// <summary>
/// Gets all hexadecimal values attributed to a Letter
/// </summary>
/// <returns>a std::vector of hexadecimal values that respectively represent the Character, modification, and Diacritics</returns>
std::vector<std::string> Letter::GetHex() const
{
	std::vector<std::string> ret;

	if (this->character != Character::NONE)
		ret.push_back(to_hex(this->character));

	std::string hex = to_hex(this->modification);
	if (is_diacritic(hex))
		ret.push_back(hex);

	for (auto& d : this->diacritics)
	{
		hex = to_hex(d);
		if (is_diacritic(hex))
			ret.push_back(hex);
	}

	return ret;
}

/// <summary>
/// Gets the Abjad value of the Letter
/// </summary>
/// <returns>an integer that represents the Letter's Abjad value</returns>
int Letter::GetAbjadValue()
{
	return abjad_value(*this);
}
/// <summary>
/// Gets the sequential value of the Letter
/// </summary>
/// <returns>an integer that represents the Letter's sequential value</returns>
int Letter::GetSequentialValue()
{
	return sequential_value(*this);
}

/// <summary>
/// Transliterates the Letter, with the option to add a space at the end
/// </summary>
/// <param name="addSpace:">if set true, a space will be added at the end</param>
/// <returns>a std::string that represents the Letter's transliteration</returns>
std::string Letter::to_string(bool addSpace)
{
	return sound_of(*this) + (addSpace ? " " : "");
}

/// <summary>
/// The Letter's equality operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are equal</returns>
bool Letter::operator ==(const Letter& rhs)
{
	if (this->diacritics.size() != rhs.diacritics.size())
		return false;

	for (unsigned int i = 0; i < rhs.diacritics.size(); i++)
		if (this->diacritics[i] != rhs.diacritics[i])
			return false;

	return this->character == rhs.character && this->modification == rhs.modification;
}
/// <summary>
/// The Letter's inequality operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are not equal</returns>
bool Letter::operator !=(const Letter& rhs)
{
	return !(*this == rhs);
}
/// <summary>
/// The Letter's less-than operator (primarily used to allow the use of a Letter key in an std::map)
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are equal</returns>
bool Letter::operator <(const Letter& rhs) const
{
	return abjad_value(*this) < abjad_value(rhs);
}

/// <summary>
/// Gets the total amount of ASCII values that can be attributed to a Letter
/// </summary>
/// <returns>integer that represents the number of all the Letter's ASCII values</returns>
int Letter::ASCIICount() const
{
	return diacritics.size() + (int)is_arabic(this->character, true);
}
/// <summary>
/// Gets the number of the Letter's diacritics
/// </summary>
/// <returns>integer that represents the number of the Letter's diacritics</returns>
int Letter::DiacriticCount() const
{
	return diacritics.size();
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
		return false;
	if (checkDiacritic)
		for (auto& d : this->diacritics)
			if (!is_diacritic(to_ascii(d)))
				return false;

	return true;
}


///////////////////////////////////////////////////////////////////////////////
// Word 
///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Default constructor for an TextualPosition struct
/// </summary>
Word::Attributes::Attributes()
{
	this->type = Type::NONE;
	this->tense = Tense::NONE;
	this->quantity = Quantity::NONE;
	this->gender = Gender::NONE;
	this->person = Person::NONE;
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
	this->type = type;
	this->tense = tense;
	this->quantity = quantity;
	this->gender = gender;
	this->person = person;
}

/// <summary>
/// Default constructor for a Letter
/// </summary>
Word::Word()
{
	Reset();
}
/// <summary>
/// Word constructor using a Letter
/// </summary>
/// <param name="l:">the Letter to add</param>
Word::Word(Letter l) : Word()
{
	this->letters.push_back(l);
}
/// <summary>
/// Word constructor using a std::vector of Letters
/// </summary>
/// <param name="letters:">the Letters that make up the Word</param>
Word::Word(std::vector<Letter> letters) : Word()
{
	this->letters = letters;
}
/// <summary>
/// Word constructor using a std::vector of ASCII values
/// </summary>
/// <param name="asciis:">the ASCII values that represent the Word's letters</param>
Word::Word(std::vector<int> asciis) : Word()
{
	for (unsigned int i = 0; i < asciis.size(); i++)
		if (is_character(asciis[i]))
			this->letters.push_back(LetterByASCII[asciis[i]]);
}
/// <summary>
/// Word constructor using a std::vector of hexadecimal values
/// </summary>
/// <param name="hexes:">the hexadecimal values that represent the Word's letters</param>
Word::Word(std::vector<std::string> hexes) : Word()
{
	for (unsigned int i = 0; i < hexes.size(); i++)
	{
		int ascii = to_ascii(hexes[i]);

		if (is_character(ascii))
			this->letters.push_back(LetterByASCII[ascii]);
	}
}
/// <summary>
/// Default destructor for a Word
/// </summary>
Word::~Word()
{
	Reset();
}

/// <summary>
/// Gets the Letters in a Word
/// </summary>
/// <returns>a vector of the Word's Letters</returns>
std::vector<Letter> Word::GetLetters() const
{
	return this->letters;
}
/// <summary>
/// Sets all the Word's Letters
/// </summary>
/// <param name="letters:">the Letters to set</param>
/// <param name="clearRoot:">if set to true, then the Word's "root" member will be cleared</param>
void Word::SetLetters(std::vector<Letter> letters, bool clearRoot)
{
	this->letters.clear();
	this->letters = letters;

	if (clearRoot)
		this->root.clear();
}
/// <summary>
/// Sets a Word's Letter at an index
/// </summary>
/// <param name="index:">the index of the changing Letter</param>
/// <param name="letter:">the Letter to set</param>
/// <param name="clearRoot:">if set to true, then the Word's "root" member will be cleared</param>
void Word::SetLetter(int index, Letter letter, bool clearRoot)
{
	this->letters[index] = letter;

	if (clearRoot)
		this->root.clear();
}
/// <summary>
/// Adds a new Letter to a Word
/// </summary>
/// <param name="letter:">the Letter to add</param>
/// <param name="clearRoot"">if set to true, then the Word's "root" member will be cleared</param>
void Word::AddLetter(Letter letter, bool clearRoot)
{
	this->letters.push_back(letter);

	if (clearRoot)
		this->root.clear();
}
/// <summary>
/// Inserts a Word's Letter after an index
/// </summary>
/// <param name="index:">the index before the inserting Letter</param>
/// <param name="letter:">the Letter to set</param>
/// <param name="clearRoot:">if set to true, then the Word's "root" member will be cleared</param>
void Word::InsertLetter(int index, Letter letter, bool clearRoot)
{
	Utilities::insert_at(this->letters, index, letter);

	if (clearRoot)
		this->root.clear();
}
/// <summary>
/// Revoves a Word's Letter at an index
/// </summary>
/// <param name="index:">the index of the Letter to be removed</param>
/// <param name="clearRoot:">if set to true, then the Word's "root" member will be cleared</param>
void Word::RemoveLetter(int index, bool clearRoot)
{
	Utilities::remove_at(this->letters, index);

	if (clearRoot)
		this->root.clear();
}

/// <summary>
/// Gets the root Characters of a Word
/// </summary>
/// <returns>a vector of the root's Characters</returns>
std::vector<Character> Word::GetRoot() const
{
	return this->root;
}
/// <summary>
/// Sets the root Characters of a Word
/// </summary>
/// <param name="root:">a std::vector of Characters to replace the "root" member</param>
void Word::SetRoot(std::vector<Character> root)
{
	this->root.clear();
	this->root = root;
}
/// <summary>
/// Sets the Word's root's Character at an index
/// </summary>
/// <param name="index:">the index of interest</param>
/// <param name="character:">the root's Character to be the replacement</param>
void Word::SetRootCharacter(int index, Character character)
{
	this->root[index] = character;
}
/// <summary>
/// Adds a new Character at the end of the "root" member
/// </summary>
/// <param name="character:">the Character to be the added to the "root" member</param>
void Word::AddRootCharacter(Character character)
{
	this->root.push_back(character);
}
/// <summary>
/// Inserts a new Character at an index of the "root" member
/// </summary>
/// <param name="index:">the index of interest</param>
/// <param name="character:">the Character to be the inserted into the "root" member</param>
void Word::InsertRootCharacter(int index, Character character)
{
	Utilities::insert_at(this->root, index, character);
}
/// <summary>
/// Removes a Character at an index of the "root" member
/// </summary>
/// <param name="index:">the index with the desired Character to remove</param>
void Word::RemoveRootCharacter(int index)
{
	Utilities::remove_at(this->root, index);
}

/// <summary>
/// Sets the Word's "attributes" member
/// </summary>
/// <param name="attributes:">the Attributes to set</param>
void Word::SetAttributes(Attributes attributes)
{
	this->attributes = attributes;
}
/// <summary>
/// Gets the Word's "attributes" member
/// </summary>
/// <returns>the Word's "attributes" member</returns>
Word::Attributes Word::GetAttributes() const
{
	return this->attributes;
}
/// <summary>
/// Sets the Word's Type in the "attributes" member
/// </summary>
/// <param name="type:">the Type to set</param>
void Word::SetType(Type type)
{
	this->attributes.type = type;
}
/// <summary>
/// Sets the Word's Tense in the "attributes" member
/// </summary>
/// <param name="tense:">the Tense to set</param>
void Word::SetTense(Tense tense)
{
	this->attributes.tense = tense;
}
/// <summary>
/// Sets the Word's Quantity in the "attributes" member
/// </summary>
/// <param name="quantity:">the Quantity to set</param>
void Word::SetQuantity(Quantity quantity)
{
	this->attributes.quantity = quantity;
}
/// <summary>
/// Sets the Word's Gender in the "attributes" member
/// </summary>
/// <param name="gender:">the Gender to set</param>
void Word::SetGender(Gender gender)
{
	this->attributes.gender = gender;
}
/// <summary>
/// Sets the Word's Person in the "attributes" member
/// </summary>
/// <param name="person:">the Person to set</param>
void Word::SetPerson(Person person)
{
	this->attributes.person = person;
}

/// <summary>
/// Clears the Word's "attributes" member
/// </summary>
void Word::ResetAttributes()
{
	this->attributes.type = Type::NONE;
	this->attributes.tense = Tense::NONE;
	this->attributes.quantity = Quantity::NONE;
	this->attributes.gender = Gender::NONE;
	this->attributes.person = Person::NONE;
}
/// <summary>
/// Resets the whole Word to default values
/// </summary>
void Word::Reset()
{
	letters.clear();
	root.clear();

	ResetAttributes();
}

/// <summary>
/// Gets all ASCII values attributed to a Word
/// </summary>
/// <returns>a std::vector of ASCII values that represent the Word</returns>
std::vector<int> Word::GetASCII() const
{
	std::vector<int> asciis;

	for (unsigned int i = 0; i < this->Count(); i++)
		Utilities::addrange(asciis, this->letters[i].GetASCII());

	return asciis;
}
/// <summary>
/// Gets all hexadecimal values attributed to a Word
/// </summary>
/// <returns>a std::vector of hexadecimal values that represent the Word</returns>
std::vector<std::string> Word::GetHex() const
{
	std::vector<std::string> hexes;

	for (unsigned int i = 0; i < this->Count(); i++)
		Utilities::addrange(hexes, this->letters[i].GetHex());

	return hexes;
}

/// <summary>
/// Gets the Abjad value of the Word
/// </summary>
/// <returns>an integer that represents the Word's Abjad value</returns>
int Word::GetAbjadValue() const
{
	return abjad_value(*this);
}
/// <summary>
/// Gets the sequential value of the Word
/// </summary>
/// <returns>an integer that represents the Word's sequential value</returns>
int Word::GetSequentialValue() const
{
	return sequential_value(*this);
}

/// <summary>
/// Transliterates the Word, with the option to add a space at the end
/// </summary>
/// <param name="addSpace:">if set true, a space will be added at the end</param>
/// <returns>a std::string that represents the Word's transliteration</returns>
std::string Word::to_string(bool addSpace)
{
	return sound_of(*this) + (addSpace ? " " : "");
}

Letter& Word::operator [](int index)
{
	return this->letters[index];
}
/// <summary>
/// The Word's equality operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are equal</returns>
bool Word::operator ==(const Word& rhs)
{
	if (this->Count() != rhs.Count())
		return false;

	for (unsigned int i = 0; i < this->Count(); i++)
		if (this->letters[i] != rhs.letters[i])
			return false;
	
	return true;
}
/// <summary>
/// The Word's inequality operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>boolean that represents if the two values are not equal</returns>
bool Word::operator !=(const Word& rhs)
{
	return !(*this == rhs);
}
/// <summary>
/// The Word's add operator
/// </summary>
/// <param name="rhs:">the right-hand side of the condition</param>
/// <returns>a new Word with the Letters from "rhs" appended to the current Word</returns>
Word Word::operator +(const Letter& rhs)
{
	AddLetter(rhs);
	return *this;
}
/// <summary>
/// The Word's decrement operator
/// </summary>
/// <returns>the same word with the last Letter removed</returns>
Word& Word::operator --()
{
	this->letters.pop_back();
	return *this;
}

/// <summary>
/// Gets the number of Letters in the Word
/// </summary>
/// <returns>integer that represents the number of letters in the Word</returns>
int Word::Count() const
{
	return LetterCount();
}
/// <summary>
/// Gets the total amount of ASCII values that can be attributed to a Word
/// </summary>
/// <returns>integer that represents the number of all the Word's ASCII values</returns>
int Word::ASCIICount() const
{
	int sum = 0;

	for (auto l : this->letters)
		sum += l.ASCIICount();

	return sum;
}
/// <summary>
/// Gets the number of Characters in the Word
/// </summary>
/// <returns>integer that represents the number of Characters in the Word</returns>
int Word::CharacterCount() const
{
	int sum = 0;

	for (auto l : this->letters)
		if (l.GetCharacter() != Character::NONE)
			sum ++;

	return sum;
}
/// <summary>
/// Gets the number of Letters in the Word
/// </summary>
/// <returns>integer that represents the number of letters in the Word</returns>
int Word::LetterCount() const
{
	return this->letters.size();
}
/// <summary>
/// Gets the number of Diacritics in the Word
/// </summary>
/// <returns>integer that represents the number of Diacritics in the Word</returns>
int Word::DiacriticCount() const
{
	int sum = 0;

	for (auto l : this->letters)
		sum += l.DiacriticCount();

	return sum;
}

/// <summary>
/// Gets the number of occurances of a specified Letter within a Word
/// </summary>
/// <param name="l:">the Letter of interest</param>
/// <returns>integer representing the number of occurances of the desired Letter in the Word</returns>
int Word::OccuranceOf(Letter l) const
{
	return Utilities::occurance_of(this->letters, l);
}