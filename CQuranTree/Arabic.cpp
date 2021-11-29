#include "Arabic.h"

using namespace Arabic;

///////////////////////////////////////////////////////////////////////////////
// Arabic 
///////////////////////////////////////////////////////////////////////////////

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
/// <param name="l:">Letter to convert</param>
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
	std::stringstream stream;
	stream << std::hex << n;
	return stream.str();
}
std::string Arabic::to_hex(Character);
std::string Arabic::to_hex(Diacritic);
std::string Arabic::to_hex(Letter);

int Arabic::abjad_value(Character);
int Arabic::abjad_value(Letter);
int Arabic::abjad_value(std::vector<Letter>);
int Arabic::abjad_value(Word);
int Arabic::abjad_value(std::vector<Word>);

int Arabic::sequential_value(Character);
int Arabic::sequential_value(Letter);
int Arabic::sequential_value(std::vector<Letter>);
int Arabic::sequential_value(Word);
int Arabic::sequential_value(std::vector<Word>);

/// <summary>
/// Returns the sound that a Letter makes
/// </summary>
/// <param name="l:">Letter to analyze</param>
/// <returns>std::string representation of the Letter's sound</returns>
std::string Arabic::sound_of(Letter l)
{
	std::string sound = "";

	switch (l.GetCharacter())
	{
		case Character::SPACE:
		{
			sound = " ";
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
					if (std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::TANWEEN_FATHAH) == l.GetDiacritics().end()	// if there is a TANWEEN_FATHAH, get sound from diacritic section
					 && std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::ALIF_WASLAH) == l.GetDiacritics().end())	// if there is a ALIF_WASLAH, ignore the sound
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
			if  (l.GetModification() != Diacritic::MARBUTAH																				// if it is not MARBUTAH
			 || (std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::TANWEEN_FATHAH) != l.GetDiacritics().end()	// or
			 ||  std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::TANWEEN_KASRAH) != l.GetDiacritics().end()	// if there is a TANWEEN
			 ||  std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::TANWEEN_DAMMAH) != l.GetDiacritics().end()))
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
			if (std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::HAMZAH) != l.GetDiacritics().end())
				sound = "'";
			else if (std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::ALIF_KHANJARIYAH) != l.GetDiacritics().end())
				sound = "A";
		}
	}
	
	if (std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::SHADDAH) != l.GetDiacritics().end())
		sound += sound;
	if (std::find(l.GetDiacritics().begin(), l.GetDiacritics().end(), Diacritic::MADDAH) != l.GetDiacritics().end())
		sound += sound;

	// TODO: optimize loop by breaking upon diacritic
	// TODO: deal with vowels that match their harakat
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