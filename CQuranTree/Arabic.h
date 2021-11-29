#pragma once

#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace Arabic
{
	enum class Character
	{
		NONE = 0,
		SPACE = 32,
		HAMZAH = -1,
		ALIF = 1,
		BA = 2,
		JEEM = 3,
		DAL = 4,
		HA = 5,
		WAW = 6,
		ZAYN = 7,
		HHA = 8,
		TTA = 9,
		YA = 10,
		KAF = 20,
		LAM = 30,
		MEEM = 40,
		NOON = 50,
		SEEN = 60,
		AYN = 70,
		FA = 80,
		SAD = 90,
		QAF = 100,
		RA = 200,
		SHEEN = 300,
		TA = 400,
		THA = 500,
		KHA = 600,
		DHAL = 700,
		DAD = 800,
		THHA = 900,
		GHAYN = 1000,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		ZERO,
	};
	enum class Position
	{
		NONE = 0,
		ISOLATED,
		BEGINNING,
		MIDDLE,
		END
	};
	enum class Diacritic
	{
		NONE = 0,
		HAMZAH, // when used as a letter
		HAMZAH_ABOVE,
		HAMZAH_BELOW,
		HAMZAH_MIDDLE,
		FATHAH,
		KASRAH,
		DAMMAH,
		SUKOON,
		SUKOON_WASLAH,
		SHADDAH,
		MADDAH,
		TANWEEN_FATHAH,
		TANWEEN_KASRAH,
		TANWEEN_DAMMAH,
		ALIF_WASLAH,
		ALIF_KHANJARIYAH,
		ALIF_MAQSURAH,
		MARBUTAH,
	};

	class Letter
	{
		private:
			Character character;
			Diacritic modification;
			Position position;
			int ASCIICharacter;
			std::string hexCharacter;
			std::vector<Diacritic> diacritics;
			std::vector<int> ASCIIDiacritics;
			std::vector<std::string> hexDiacritics;

		public:
			Letter(Position = Position::NONE);
			Letter(int, Position = Position::NONE);
			Letter(std::string, Position = Position::NONE);
			Letter(std::vector<int>, Position = Position::NONE);
			Letter(std::vector<std::string>, Position = Position::NONE);
			Letter(Character, Position = Position::NONE);
			Letter(Character, Diacritic, Position = Position::NONE);
			~Letter();

			void Reset();

			bool SetFromASCII(int);
			Character GetCharacter();
			void SetCharacter(Character, bool = true);
			void SetCharacter(Character, Diacritic);
			void SetCharacter(int, bool = true);
			void SetCharacter(std::string, bool = true);
			Diacritic GetModification();
			void SetModification(Diacritic);
			std::vector<Diacritic> GetDiacritics();
			void SetDiacritics(std::vector<Diacritic>);
			void SetDiacritic(int, Diacritic);
			void AddDiacritic(Diacritic);
			void AddDiacritic(int);
			void AddDiacritic(std::string);
			void RemoveDiacritic(int);
			void RemoveDiacritic(Diacritic);
			void ClearDiacritics();
			Position GetPosition();
			void SetPosition(Position);

			std::vector<int> GetASCII();
			std::vector<std::string> GetHex();
			int GetASCIICharacter();
			std::string GetHexCharacter();
			std::vector<int> GetASCIIDiacritics();
			std::vector<std::string> GetHexDiacritics();

			int GetAbjadValue();
			int GetSequentialValue();

			std::string to_string(bool = false);

			bool operator ==(const Letter&);
			bool operator !=(const Letter&);
			bool operator <(const Letter& l);

			int ASCIICount();
			int DiacriticCount();
			
			bool IsArabic(bool checkCharacter, bool checkDiacritic, bool checkSpace, bool checkExtra);
	};

	class Word
	{
		private:
			std::vector<Letter> letters;
			std::vector<Character> root;

		public:
			enum class Type
			{
				NONE = 0,
				NOUN,
				VERB,
				ADJECTIVE,
				ADVERB,
				PRONOUN
			};
			enum class Tense
			{
				NONE = 0,
				ROOT,
				PAST,
				PRESENT,
				FUTURE,
				COMMAND
			};
			enum class Person
			{
				NONE = 0,
				FIRST,
				SECOND,
				THRID,
				FOURTH
			};
			enum class Quantity
			{
				NONE = 0,
				SINGULAR,
				DUAL,
				PLURAL
			};
			enum class Gender
			{
				NONE = 0,
				MASCULINE,
				FEMININE
			};

			Word();
			Word(Letter);
			Word(std::vector<Letter>);
			Word(std::vector<int>, char = ' ');
			Word(std::vector<std::string>, char = ' ');
			~Word();

			std::vector<Letter> GetLetters();
			void SetLetters(std::vector<Letter>);
			void SetLetter(int, Letter);
			void AddLetter(int, Letter);
			void RemoveLetter(int);
			void Reset();

			std::vector<Character> GetRoot();
			int GetASCII();
			int GetHex();

			int GetAbjadValue();
			int GetSequentialValue();

			std::string to_string();

			Letter& operator [](int);
			bool operator ==(const Word&);
			bool operator !=(const Word&);
			bool operator +(const Letter&);
			bool operator --();

			int Count();
			int CharacterCount();
			int LetterCount();
			int DiacriticCount();

			int OccuranceOf(Letter);
	};

	std::map<Letter,int> ASCIIByLetter
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
	std::map<int, Letter> LetterByASCII
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

	std::map<Diacritic, int> ASCIIByDiacritic
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
	std::map<int, Diacritic> DiacriticByASCII
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
	
	std::string to_string(int);
	std::string to_string(Character);
	std::string to_string(Position);
	std::string to_string(Diacritic);
	std::string to_string(Word::Type);
	std::string to_string(Word::Tense);
	std::string to_string(Word::Person);
	std::string to_string(Word::Quantity);
	std::string to_string(Word::Gender);

	int to_ascii(std::string);
	int to_ascii(Character);
	int to_ascii(Diacritic);
	int to_ascii(Letter);

	std::string to_hex(int);
	std::string to_hex(Character);
	std::string to_hex(Diacritic);
	std::string to_hex(Letter);

	int abjad_value(Character);
	int abjad_value(Letter);
	int abjad_value(std::vector<Letter>);
	int abjad_value(Word);
	int abjad_value(std::vector<Word>);

	int sequential_value(Character);
	int sequential_value(Letter);
	int sequential_value(std::vector<Letter>);
	int sequential_value(Word);
	int sequential_value(std::vector<Word>);

	std::string sound_of(Letter);

	bool is_character(int, bool = false);
	bool is_character(std::string, bool = false);
	bool is_diacritic(int);
	bool is_diacritic(std::string);

	bool is_arabic(int);
	bool is_arabic(std::string);
	bool is_arabic(Character, bool = false);
	bool is_arabic(Diacritic);
	bool is_arabic(Letter, bool = false);
	bool is_arabic(Word, bool = false);
};