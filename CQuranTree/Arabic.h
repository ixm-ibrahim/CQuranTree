#pragma once

#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "Utilities.h"

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
		SUKOON_ALIF,	// https://tajweed.me/tag/sukoon/
		SHADDAH,
		MADDAH,
		TANWEEN_FATHAH,
		TANWEEN_KASRAH,
		TANWEEN_DAMMAH,
		ALIF_WASLAH,
		ALIF_KHANJARIYAH,
		ALIF_MAQSURAH,
		SMALL_WAW,
		SMALL_YA,
		MARBUTAH,
		GRAND_IMAALAH,
		ISHMAAM,
		DOUBLE_NOON,
		TASHEEL,
		SEEN_SUBSTITUTION,
		PSEUDO_LETTER
	};

	class Letter
	{
		protected:
			Character character;
			Diacritic modification;
			Position position;
			std::vector<Diacritic> diacritics;

		public:
			Letter(Position = Position::NONE);
			Letter(int, Position = Position::NONE);
			Letter(std::string, Position = Position::NONE);
			Letter(std::vector<int>, Position = Position::NONE);
			Letter(std::vector<std::string>, Position = Position::NONE);
			Letter(Character, Position = Position::NONE);
			Letter(Character, std::vector<Diacritic>, Position = Position::NONE);
			Letter(Character, Diacritic, Position = Position::NONE);
			Letter(Character, Diacritic, std::vector<Diacritic>, Position = Position::NONE);
			~Letter();

			void Reset();

			bool SetFromASCII(int);
			Character GetCharacter() const;
			void SetCharacter(Character, bool = true);
			void SetCharacter(Character, Diacritic);
			void SetCharacter(int, bool = true);
			void SetCharacter(std::string, bool = true);
			Diacritic GetModification() const;
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
			Position GetPosition() const;
			void SetPosition(Position);

			std::vector<int> GetASCII() const;
			std::vector<std::string> GetHex() const;

			int GetAbjadValue();
			int GetSequentialValue();

			std::string to_string(bool = false);

			bool operator ==(const Letter&);
			bool operator !=(const Letter&);
			bool operator <(const Letter& l) const;

			int ASCIICount() const;
			int DiacriticCount() const;
			
			bool IsArabic(bool checkCharacter, bool checkDiacritic, bool checkSpace);
	};

	class Word
	{
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
			enum class Person
			{
				NONE = 0,
				FIRST,
				SECOND,
				THRID,
				FOURTH
			};

			struct Attributes
			{
				Type type;
				Tense tense;
				Quantity quantity;
				Gender gender;
				Person person;

				Attributes();
				Attributes(Type, Tense, Quantity, Gender, Person);
			};

		protected:
			std::vector<Letter> letters;
			std::vector<Character> root;
			Attributes attributes;

		public:
			Word();
			Word(Letter);
			Word(std::vector<Letter>);
			Word(std::vector<int>);
			Word(std::vector<std::string>);
			~Word();

			std::vector<Letter> GetLetters() const;
			void SetLetters(std::vector<Letter>, bool = true);
			void SetLetter(int, Letter, bool = true);
			void AddLetter(Letter, bool = true);
			void InsertLetter(int, Letter, bool = true);
			void RemoveLetter(int, bool = true);

			std::vector<Character> GetRoot() const;
			void SetRoot(std::vector<Character>);
			void SetRootCharacter(int, Character);
			void AddRootCharacter(Character);
			void InsertRootCharacter(int, Character);
			void RemoveRootCharacter(int);

			void SetAttributes(Attributes);
			Attributes GetAttributes() const;
			void SetType(Type);
			void SetTense(Tense);
			void SetQuantity(Quantity);
			void SetGender(Gender);
			void SetPerson(Person);

			void ResetAttributes();
			void Reset();

			std::vector<int> GetASCII() const;
			std::vector<std::string> GetHex() const;

			int GetAbjadValue() const;
			int GetSequentialValue() const;

			std::string to_string(bool = true);

			Letter& operator [](int);
			bool operator ==(const Word&);
			bool operator !=(const Word&);
			Word operator +(const Letter&);
			Word& operator --();

			int Count() const;
			int ASCIICount() const;
			int CharacterCount() const;
			int LetterCount() const;
			int DiacriticCount() const;

			int OccuranceOf(Letter) const;
	};

	extern std::map<Letter, int> ASCIIByLetter;
	extern std::map<int, Letter> LetterByASCII;

	extern std::map<Diacritic, int> ASCIIByDiacritic;
	extern std::map<int, Diacritic> DiacriticByASCII;
	
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

	std::string sound_of(Character, Diacritic, std::vector<Diacritic>, Position = Position::NONE, bool = true);
	std::string sound_of(Letter, bool = true);
	std::string sound_of(std::vector<Letter>, bool = true);
	std::string sound_of(Word, bool = true);
	std::string sound_of(std::vector<Word>, bool = true);

	bool is_character(int, bool = false);
	bool is_character(std::string, bool = false);
	bool is_diacritic(int);
	bool is_diacritic(std::string);

	bool is_arabic(int, bool = false);
	bool is_arabic(Character, bool = false);
	bool is_arabic(Diacritic);
	bool is_arabic(Letter, bool = false);
	bool is_arabic(Word, bool = false);
};