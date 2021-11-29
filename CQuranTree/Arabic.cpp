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
/// <param name="l:">Letter to convert</param>
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
/// <param name="l:">Letter to convert</param>
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
/// <param name="l:">Letter to convert</param>
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
bool Arabic::is_character(std::string hex, bool checkSpace)
{
	return is_character(to_ascii(hex), checkSpace);
}
bool Arabic::is_diacritic(int ascii)
{
	// meem saakin - 06e2   <------------

	return (ascii >= 1611 && ascii <= 1620) || ascii == 1648 || ascii == 1759;
}
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
/// <param name="l:">Letter to analyze</param>
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

Letter::Letter(Position position)
{
	Reset();

	this->position = position;
}
Letter::Letter(int ascii, Position position) : Letter(position)
{
	SetFromASCII(ascii);
}
Letter::Letter(std::string hex, Position position) : Letter(to_ascii(hex), position) {}
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
Letter::Letter(Character character, Position position) : Letter(position)
{
	SetCharacter(character);
}
Letter::Letter(Character character, Diacritic modification, Position position) : Letter(position)
{
	SetCharacter(character, modification);
}
Letter::~Letter()
{
	Reset();
}

void Letter::Reset()
{
	this->character = Character::NONE;
	this->modification = Diacritic::NONE;
	this->position = position;
	this->ASCIICharacter = 0;
	this->hexCharacter = "0x0000";
	diacritics.clear();
	ASCIIDiacritics.clear();
	hexDiacritics.clear();
}

bool Letter::SetFromASCII(int ascii)
{
	if (is_arabic(ascii))
		if (is_character(ascii))
		{
			this->character = LetterByASCII[ascii].GetCharacter();
			this->modification = LetterByASCII[ascii].GetModification();
			this->ASCIICharacter = ascii;
			this->hexCharacter = to_hex(ascii);
		}
		else if (is_diacritic(ascii))
			this->diacritics.push_back(DiacriticByASCII[ascii]);

	return false;
}
Character Letter::GetCharacter()
{
	return this->character;
}
void Letter::SetCharacter(Character character, bool clearModification)
{
	this->character = character;
	if (clearModification)
		this->modification = Diacritic::NONE;
	this->ASCIICharacter = to_ascii(character);
	this->hexCharacter = to_hex(character);
}
void Letter::SetCharacter(Character character, Diacritic modification)
{
	this->character = character;
	this->modification = modification;
	this->ASCIICharacter = to_ascii(character);
	this->hexCharacter = to_hex(character);
}
void Letter::SetCharacter(int ascii, bool clearModification)
{
	this->character = LetterByASCII[ascii].GetCharacter();
	if (clearModification)
		this->modification = Diacritic::NONE;
	this->ASCIICharacter = ascii;
	this->hexCharacter = to_hex(ascii);
}

void Letter::SetCharacter(std::string hex, bool clearModification)
{
	SetCharacter(to_ascii(hex), clearModification);
}
Diacritic Letter::GetModification()
{
	return this->modification;
}
void Letter::SetModification(Diacritic modification)
{
	this->modification = modification;
}

std::vector<Diacritic> Letter::GetDiacritics()
{
	return this->diacritics;
}
void Letter::SetDiacritics(std::vector<Diacritic> diacritics)
{
	ClearDiacritics();

	this->diacritics = diacritics;

	for (unsigned int i = 0; i < diacritics.size(); i++)
	{
		this->ASCIIDiacritics.push_back(to_ascii(diacritics[i]));
		this->hexDiacritics.push_back(to_hex(diacritics[i]));
	}
}
void Letter::SetDiacritic(int index, Diacritic diacritic)
{
	this->diacritics[index] = diacritic;
	this->ASCIIDiacritics[index] = to_ascii(diacritic);
	this->hexDiacritics[index] = to_hex(diacritic);
}
void Letter::AddDiacritic(Diacritic diacritic)
{
	if (diacritic != Diacritic::NONE)
	{
		this->diacritics.push_back(diacritic);
		this->ASCIIDiacritics.push_back(to_ascii(diacritic));
		this->hexDiacritics.push_back(to_hex(diacritic));
	}
}
void Letter::AddDiacritic(int ascii)
{
	if (is_diacritic(ascii))
	{
		Diacritic d = DiacriticByASCII[ascii];

		if (d != Diacritic::NONE)
		{
			this->diacritics.push_back(d);
			this->ASCIIDiacritics.push_back(ascii);
			this->hexDiacritics.push_back(to_hex(ascii));
		}
	}
}
void Letter::AddDiacritic(std::string hex)
{
	AddDiacritic(to_ascii(hex));
}
void Letter::RemoveDiacritic(int index)
{
	this->diacritics.erase(this->diacritics.begin() + index);
	this->ASCIIDiacritics.erase(this->ASCIIDiacritics.begin() + index);
	this->hexDiacritics.erase(this->hexDiacritics.begin() + index);
}
void Letter::RemoveDiacritic(Diacritic diacritic)
{
	this->diacritics.erase(std::remove(this->diacritics.begin(), this->diacritics.end(), diacritic), this->diacritics.end());
	this->ASCIIDiacritics.erase(std::remove(this->ASCIIDiacritics.begin(), this->ASCIIDiacritics.end(), to_ascii(diacritic)), this->ASCIIDiacritics.end());
	this->hexDiacritics.erase(std::remove(this->hexDiacritics.begin(), this->hexDiacritics.end(), to_hex(diacritic)), this->hexDiacritics.end());
}
void Letter::ClearDiacritics()
{
	this->diacritics.clear();
	this->ASCIIDiacritics.clear();
	this->hexDiacritics.clear();
}

Position Letter::GetPosition()
{
	return this->position;
}
void Letter::SetPosition(Position position)
{
	this->position = position;
}

std::vector<int> Letter::GetASCII()
{
	std::vector<int> ret;

	if (is_character(this->ASCIICharacter))
		ret.push_back(this->ASCIICharacter);

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
std::vector<std::string> Letter::GetHex()
{
	std::vector<std::string> ret;

	if (is_character(this->hexCharacter))
		ret.push_back(this->hexCharacter);

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
int Letter::GetASCIICharacter()
{
	return this->ASCIICharacter;
}
std::string Letter::GetHexCharacter()
{
	return this->hexCharacter;
}
std::vector<int> Letter::GetASCIIDiacritics()
{
	return this->ASCIIDiacritics;
}
std::vector<std::string> Letter::GetHexDiacritics()
{
	return this->hexDiacritics;
}

int Letter::GetAbjadValue()
{
	return abjad_value(*this);
}
int Letter::GetSequentialValue()
{
	return sequential_value(*this);
}

std::string Letter::to_string(bool addSpace)
{
	return sound_of(*this) + (addSpace ? " " : "");
}

bool Letter::operator ==(const Letter& l)
{
	return true;
}
bool Letter::operator !=(const Letter& l)
{
	return true;
}
bool Letter::operator <(const Letter& l)
{
	return to_ascii(*this) < to_ascii(l);
}

int Letter::ASCIICount()
{
	return diacritics.size() + (int)is_arabic(this->character, true);
}
int Letter::DiacriticCount()
{
	return diacritics.size();
}

bool Letter::IsArabic(bool checkCharacter, bool checkDiacritic, bool checkSpace, bool checkExtra)
{
	if (checkCharacter)
		if (!is_arabic(this->character))
			return false;
}