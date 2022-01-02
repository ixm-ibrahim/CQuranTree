#pragma once

#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "Utilities.h"


namespace Arabic
{

	class Character
	{
		public:
			enum class Type
			{
				UNKNOWN = 0,
				LETTER,
				DIACRITIC,
				SYMBOL
			};

		protected:
			int ascii = 0;
			Type type = Type::UNKNOWN;

		public:

			int GetASCII();
			Type GetType();

			bool operator ==(const Character&);
			bool operator !=(const Character&);

			virtual void Reset() = 0;
			virtual void SetASCII(int) = 0;
			virtual std::string ToString() = 0;
	};

	class Letter : public Character
	{
		public:
			enum class Value
			{
				NONE,
				ALIF,
				BA,
				TA,
				THA,
				JEEM,
				HHA,
				KHA,
				DAL,
				DHAL,
				RA,
				ZAYN,
				SEEN,
				SHEEN,
				SAD,
				DAD,
				TTA,
				THHA,
				AYN,
				GHAYN,
				FA,
				QAF,
				KAF,
				LAM,
				MEEM,
				NOON,
				HA,
				WAW,
				YA,
				HAMZAH
			};
			enum class Modification
			{
				NONE = 0,
				MADDAH,
				HAMZAH_ABOVE,
				HAMZAH_BELOW,
				HAMZAH_MIDDLE,
				MARBUTAH,
				MAQSURAH,
				KHANJARIYAH,
				WASLAH
			};
			enum class Position
			{
				NONE = 0,
				ISOLATED,
				BEGINNING,
				MIDDLE,
				END
			};

		private:
			Value value = Value::NONE;
			Modification modification = Modification::NONE;
			Position position = Position::NONE;

		public:
			Letter();
			Letter(int, Position = Position::NONE);
			Letter(Value, Position = Position::NONE);
			Letter(int, Modification, Position = Position::NONE);
			Letter(Value, Modification, Position = Position::NONE);

			void Reset();

			void SetASCII(int);
			Value GetValue();

			Modification GetModification();
			void SetModification(Modification);

			Position GetPosition();
			void SetPosition(Position);

			int GetAbjadValue();
			int GetSequentialValue();

			std::string SoundOf();
			std::string ToString();
	};

	class Diacritic : public Character
	{
		public:
			enum class Value
			{
				NONE = 0,
				TATWEEL,
				TANWEEN_FATHAH,
				TANWEEN_DAMMAH,
				TANWEEN_KASRAH,
				FATHAH,
				DAMMAH,
				KASRAH,
				SHADDAH,
				SUKOON,
				MADDAH,
				HAMZAH,			// when used as a letter
				ALIF_KHANJARIYAH,
				SUKOON_WASLAH,
				SUKOON_ALIF,	// https://symbols.me/tag/sukoon/
				SEEN_SUBSTITUTION,
				SMALL_WAW,
				SMALL_YA,
				SMALL_YA_ABOVE,
				DOUBLE_NOON,
				GRAND_IMAALAH,	// see Quran 11:41
				ISHMAAM,		// see Quran 12:11
				TASHEEL,		// see Quran 41:44
				// Modified characters
				HAMZAH_ABOVE,
				HAMZAH_BELOW,
				HAMZAH_MIDDLE,
				ALIF_WASLAH,
				ALIF_MAQSURAH,
				MARBUTAH,
			};

		private:
			Value value;

		public:
			Diacritic();
			Diacritic(int);
			Diacritic(Value);

			void Reset();

			void SetASCII(int);
			Value GetValue();

			std::string ToString();

	};

	class Symbol : public Character
	{
		public:
			// http://www.islamguiden.com/arabic/esymbol1.html
			enum class Value
			{
				NONE = 0,
				COMPULSORY_STOP,
				PROHIBITED_STOP,
				GOOD_STOP,
				SUFFICIENT_STOP,
				EQUALITY_STOP,
				PRECAUTIONARY_STOP,
				BRIEF_STOP,
				SAJDAH,
				MEEM_IQLAB_ABOVE,
				MEEM_IQLAB_BELOW,
				QUARTER_OF_HALF
			};

		private:
			Value value;

		public:
			Symbol();
			Symbol(int);
			Symbol(Value);

			void SetASCII(int);
			Value GetValue();

			void Reset();

			std::string ToString();
	};
	
	typedef Character::Type character_t;
	typedef Letter::Value letter_t;
	typedef Letter::Modification modification_t;
	typedef Letter::Position position_t;
	typedef Diacritic::Value diacritic_t;
	typedef Symbol::Value symbol_t;

	std::string to_string(int);
	std::string to_string(Character*);

	int to_ascii(std::string);
	std::string to_hex(int);

	character_t get_type(int);

	letter_t get_letter(int);
	diacritic_t get_diacritic(int);
	symbol_t get_symbol(int);

	int abjad_value(int);
	int abjad_value(Character*);
	int abjad_value(Letter*);
	int abjad_value(std::vector<Character*>);

	int sequential_value(int, bool = false);
	int sequential_value(Character*, bool = false);
	int sequential_value(Letter*, bool = false);
	int sequential_value(std::vector<Character*>, bool = false);

	std::string sound_of(int, bool = true);
	std::string sound_of(int, std::vector<Diacritic*>, bool = true);
	std::string sound_of(Character*, bool = true);
	std::string sound_of(Character*, std::vector<Diacritic*>, bool = true);
	std::string sound_of(std::vector<Character*>, bool = true);

	bool is_letter(int, bool = false);
	bool is_diacritic(int);
	bool is_symbol(int);
	bool is_arabic(int, bool = false);

	bool has_modification(int);
	bool has_harakah(std::vector<Diacritic*>);
	bool has_diacritic(std::vector<Diacritic*>, Diacritic d);
}
