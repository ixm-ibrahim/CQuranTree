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
					else if (Utilities::index_of<Diacritic>(l.GetDiacritics(), Diacritic::TANWEEN_FATHAH) == -1)	// if there is a TANWEEN_FATHAH, get sound from diacritic section
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
			 || (Utilities::index_of<Diacritic>(l.GetDiacritics(), Diacritic::TANWEEN_FATHAH) != -1	// or
			 ||  Utilities::index_of<Diacritic>(l.GetDiacritics(), Diacritic::TANWEEN_KASRAH) != -1	// if there is a TANWEEN
			 ||  Utilities::index_of<Diacritic>(l.GetDiacritics(), Diacritic::TANWEEN_DAMMAH) != -1))
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

	if (Utilities::index_of<Diacritic>(l.GetDiacritics(), Diacritic::SHADDAH) != -1)
		sound += sound;
	if (Utilities::index_of<Diacritic>(l.GetDiacritics(), Diacritic::MADDAH) != -1)
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
Character Letter::GetCharacter()
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
Diacritic Letter::GetModification()
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
	this->diacritics.erase(this->diacritics.begin() + index);
}
/// <summary>
/// Removes all occurances of a Diacritic from the Letter's "diacritics" member
/// </summary>
/// <param name="diacritic:">the Diacritic to remove</param>
void Letter::RemoveDiacritic(Diacritic diacritic)
{
	this->diacritics.erase(std::remove(this->diacritics.begin(), this->diacritics.end(), diacritic), this->diacritics.end());
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
Position Letter::GetPosition()
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
/// <returns>a vector of ASCII values that respectively represent the Character, modification, and Diacritics</returns>
std::vector<int> Letter::GetASCII()
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
/// <returns>a vector of hexadecimal values that respectively represent the Character, modification, and Diacritics</returns>
std::vector<std::string> Letter::GetHex()
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
int Letter::ASCIICount()
{
	return diacritics.size() + (int)is_arabic(this->character, true);
}
/// <summary>
/// Gets the number of the Letter's diacritics
/// </summary>
/// <returns>integer that represents the number of the Letter's diacritics</returns>
int Letter::DiacriticCount()
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


Word::Word()
{

}
Word::Word(Letter)
{

}
Word::Word(std::vector<Letter>)
{

}
Word::Word(std::vector<int>, char)
{

}
Word::Word(std::vector<std::string>, char)
{

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
std::vector<Letter> Word::GetLetters()
{
	return this->letters;
}
void Word::SetLetters(std::vector<Letter>)
{

}
void Word::SetLetter(int, Letter)
{

}
void Word::AddLetter(int, Letter)
{

}
void Word::RemoveLetter(int)
{

}
void Word::Reset()
{

}

std::vector<Character> Word::GetRoot()
{
	std::vector<Character> tmp;
	return tmp;
}
int Word::GetASCII()
{
	return 0;
}
std::string Word::GetHex()
{
	return "";
}

int Word::GetAbjadValue()
{
	return 0;
}
int Word::GetSequentialValue()
{
	return 0;
}

std::string Word::to_string()
{
	return "";
}

Letter& Word::operator [](int index)
{
	return this->letters[index];
}
bool Word::operator ==(const Word&)
{
	return true;
}
bool Word::operator !=(const Word&)
{
	return true;
}
bool Word::operator +(const Letter&)
{
	return true;
}
bool Word::operator --()
{
	return true;
}

int Word::Count()
{
	return 0;
}
int Word::CharacterCount()
{
	return 0;
}
int Word::LetterCount()
{
	return 0;
}
int Word::DiacriticCount()
{
	return 0;
}

int Word::OccuranceOf(Letter)
{
	return 0;
}