#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include "Arabic.h"
#include "Utilities.h"

#define QURAN_PATH ".\\Files\\quran-uthmani.txt"

#define INCLUDE_DIACRITICS					0b00000001
#define INCLUDE_SYMBOLS						0b00000010
#define INCLUDE_BASMALLAH					0b00000100
#define INCLUDE_INDEPENDENT_WAW				0b00001000
#define INCLUDE_HAMZAH_BETWEEN_ALIF_LAM		0b00010000

using namespace Arabic;

namespace Quran
{
	const int NumChapters = 114;
	const int NumVerses = 6236;
	const int NumVersesBasmallah = 6348;
	const int NumWords = 77878 +3;
	const int NumWordsBasmallah = 78326 + 3;
	const int NumWordsWaw = 0;
	const int NumWordsBasmallahWaw = 0;
	const int NumLetters = 327792;
	const int NumLettersBasmallah = 329920;
	const int NumLettersWaw = 0;
	const int NumLettersBasmallahWaw = 0;
	const int NumPages = 604;
	const int NumStations = 7;
	const int NumParts = 30;
	const int NumHalves = NumParts * 2;
	const int NumQuarters = NumHalves * 4;
	const int NumBowings = 556;

	const std::vector<int> VerseNumByChapter
	{
		7,
		286,
		200,
		176,
		120,
		165,
		206,
		75,
		129,
		109,
		123,
		111,
		43,
		52,
		99,
		128,
		111,
		110,
		98,
		135,
		112,
		78,
		118,
		64,
		77,
		227,
		93,
		88,
		69,
		60,
		34,
		30,
		73,
		54,
		45,
		83,
		182,
		88,
		75,
		85,
		54,
		53,
		89,
		59,
		37,
		35,
		38,
		29,
		18,
		45,
		60,
		49,
		62,
		55,
		78,
		96,
		29,
		22,
		24,
		13,
		14,
		11,
		11,
		18,
		12,
		12,
		30,
		52,
		52,
		44,
		28,
		28,
		20,
		56,
		40,
		31,
		50,
		40,
		46,
		42,
		29,
		19,
		36,
		25,
		22,
		17,
		19,
		26,
		30,
		20,
		15,
		21,
		11,
		8,
		8,
		19,
		5,
		8,
		8,
		11,
		11,
		8,
		3,
		9,
		5,
		4,
		7,
		3,
		6,
		3,
		5,
		4,
		5,
		6,
	};
	const std::vector<int> TotalVerseNumByChapter
	{
		7,
		293,
		493,
		669,
		789,
		954,
		1160,
		1235,
		1364,
		1473,
		1596,
		1707,
		1750,
		1802,
		1901,
		2029,
		2140,
		2250,
		2348,
		2483,
		2595,
		2673,
		2791,
		2855,
		2932,
		3159,
		3252,
		3340,
		3409,
		3469,
		3503,
		3533,
		3606,
		3660,
		3705,
		3788,
		3970,
		4058,
		4133,
		4218,
		4272,
		4325,
		4414,
		4473,
		4510,
		4545,
		4583,
		4612,
		4630,
		4675,
		4735,
		4784,
		4846,
		4901,
		4979,
		5075,
		5104,
		5126,
		5150,
		5163,
		5177,
		5188,
		5199,
		5217,
		5229,
		5241,
		5271,
		5323,
		5375,
		5419,
		5447,
		5475,
		5495,
		5551,
		5591,
		5622,
		5672,
		5712,
		5758,
		5800,
		5829,
		5848,
		5884,
		5909,
		5931,
		5948,
		5967,
		5993,
		6023,
		6043,
		6058,
		6079,
		6090,
		6098,
		6106,
		6125,
		6130,
		6138,
		6146,
		6157,
		6168,
		6176,
		6179,
		6188,
		6193,
		6197,
		6204,
		6207,
		6213,
		6216,
		6221,
		6225,
		6230,
		6236,
	};

	struct Attributes
	{
		struct TextualPosition
		{
			int chapterNum;
			int verseNum;
			int verseNumInChapter;
			int wordNum;
			int wordNumInVerse;
			int wordNumInChapter;
			int letterNum;
			int letterNumInWord;
			int letterNumInVerse;
			int letterNumInChapter;
			int characterNum;
			int characterNumInLetter;
			int characterNumInWord;
			int characterNumInVerse;
			int characterNumInChapter;
			int pageNum;
			int stationNum;
			int partNum;
			int halfNum;
			int quarterNum;
			int bowingNum;
			int basmallahNum;
			int independentWawNum;
			int hamzahLetterNum;
			int hamzahBetweenAlifLamNum;

			TextualPosition();
			TextualPosition(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

			static void copy(TextualPosition&, TextualPosition);

			TextualPosition operator =(const TextualPosition&);
		};
		struct Grammar
		{
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

			std::vector<letter_t> root;
			Type type;
			Tense tense;
			Quantity quantity;
			Gender gender;
			Person person;

			Grammar();
			Grammar(std::vector<letter_t>, Type, Tense, Quantity, Gender, Person);

			static void copy(Grammar&, Grammar);

			Grammar operator =(const Grammar&);
		};
		enum class RevelationPeriod
		{
			UNKNOWN = 0,
			MAKKAN = 1,
			MADINAN = 2,
			LATE_MAKKAN = 3,
		};

		TextualPosition textualPosition;
		Grammar grammar;
		RevelationPeriod revelationPeriod;
		character_t characterType;
		bool hasSymbol;
		bool isBasmallah;
		bool hasIndependentWaw;
		bool isHamzahBetweenLamAlif;

		Attributes();
		Attributes(TextualPosition, Grammar, RevelationPeriod, character_t, bool, bool, bool, bool);

		static void copy(Attributes&, Attributes);

		Attributes operator =(const Attributes&);
	};

	class CQuranCharacter;
	class CQuranWord;
	class CQuranVerse;
	class CQuranChapter;

	class CQuranNode
	{
		public:
			enum class Type
			{
				NONE = 0,
				CHARACTER,
				WORD,
				VERSE,
				CHAPTER
			};

		protected:
			Type type;
			Attributes attributes;

			CQuranCharacter* nextCharacter;
			CQuranCharacter* currentCharacter;
			CQuranCharacter* previousCharacter;
			CQuranWord* nextWord;
			CQuranWord* currentWord;
			CQuranWord* previousWord;
			CQuranVerse* nextVerse;
			CQuranVerse* currentVerse;
			CQuranVerse* previousVerse;
			CQuranChapter* nextChapter;
			CQuranChapter* currentChapter;
			CQuranChapter* previousChapter;

		public:
			static bool copy_links_and_attributes(CQuranNode*, CQuranNode*, bool = false);
			static void reset_links(CQuranNode*, bool = true);
			
			Type GetType();

			Attributes GetAttributes();
			void SetAttributes(Attributes);

			CQuranCharacter* GetNextCharacter();
			void SetNextCharacter(CQuranCharacter*, bool = false);
			CQuranCharacter* GetPreviousCharacter();
			void SetPreviousCharacter(CQuranCharacter*, bool = false);
			CQuranWord* GetNextWord();
			void SetNextWord(CQuranWord*, bool = false);
			CQuranWord* GetPreviousWord();
			void SetPreviousWord(CQuranWord*, bool = false);
			CQuranVerse* GetNextVerse();
			void SetNextVerse(CQuranVerse*, bool = false);
			CQuranVerse* GetPreviousVerse();
			void SetPreviousVerse(CQuranVerse*, bool = false);
			CQuranChapter* GetNextChapter();
			void SetNextChapter(CQuranChapter*, bool = false);
			CQuranChapter* GetPreviousChapter();
			void SetPreviousChapter(CQuranChapter*, bool = false);

			CQuranCharacter* GetCurrentCharacter();
			CQuranWord* GetCurrentWord();
			CQuranVerse* GetCurrentVerse();
			CQuranChapter* GetCurrentChapter();

			CQuranCharacter* GetNextLetter(bool, bool, bool);
			CQuranCharacter* GetPreviousLetter(bool, bool, bool);
			CQuranCharacter* GetNextDiacritic(bool, bool, bool);
			CQuranCharacter* GetPreviousDiacritic(bool, bool, bool);
			CQuranCharacter* GetNextSymbol();
			CQuranCharacter* GetPreviousSymbol();

			CQuranWord* GetNextWawWord();
			CQuranWord* GetPreviousWawWord();

			CQuranVerse* GetNextBasmallah();
			CQuranVerse* GetPreviousBasmallah();
			CQuranVerse* GetNextPage();
			CQuranVerse* GetPreviousPage();
			CQuranVerse* GetNextStation();
			CQuranVerse* GetPreviousStation();
			CQuranVerse* GetNextPart();
			CQuranVerse* GetPreviousPart();
			CQuranVerse* GetNextHalf();
			CQuranVerse* GetPreviousHalf();
			CQuranVerse* GetNextQuarter();
			CQuranVerse* GetPreviousQuarter();
			CQuranVerse* GetNextBowing();
			CQuranVerse* GetPreviousBowing();

			CQuranChapter* GetNextMakkanChapter();
			CQuranChapter* GetPreviousMakkanChapter();
			CQuranChapter* GetNextMadinanChapter();
			CQuranChapter* GetPreviousMadinanChapter();

			CQuranCharacter* GetNextCharacter(int);
			CQuranCharacter* GetNextCharacter(Character*);
			CQuranCharacter* GetNextCharacter(CQuranCharacter*);
			CQuranCharacter* GetPreviousCharacter(int);
			CQuranCharacter* GetPreviousCharacter(Character*);
			CQuranCharacter* GetPreviousCharacter(CQuranCharacter*);

			CQuranWord* GetNextWord(std::vector<int>, int = 0);
			CQuranWord* GetNextWord(std::vector<letter_t>);
			CQuranWord* GetNextWord(std::vector<Character*>, int = 0);
			CQuranWord* GetNextWord(std::vector<CQuranCharacter*>, int = 0);
			CQuranWord* GetNextWord(CQuranWord*, int = 0);
			CQuranWord* GetPreviousWord(std::vector<int>, int = 0);
			CQuranWord* GetPreviousWord(std::vector<letter_t>);
			CQuranWord* GetPreviousWord(std::vector<Character*>, int = 0);
			CQuranWord* GetPreviousWord(std::vector<CQuranCharacter*>, int = 0);
			CQuranWord* GetPreviousWord(CQuranWord*, int = 0);

			CQuranWord* GetNextWordWithRoot(std::vector<int>);
			CQuranWord* GetNextWordWithRoot(std::vector<letter_t>);
			CQuranWord* GetNextWordWithRoot(CQuranWord*);
			CQuranWord* GetPreviousWordWithRoot(std::vector<int>);
			CQuranWord* GetPreviousWordWithRoot(std::vector<letter_t>);
			CQuranWord* GetPreviousWordWithRoot(CQuranWord*);

			CQuranVerse* GetNextVerse(CQuranVerse*);
			CQuranVerse* GetPreviousVerse(CQuranVerse*);

			CQuranVerse* GetNextVerseWithRoot(std::vector<int>);
			CQuranVerse* GetNextVerseWithRoot(std::vector<letter_t>);
			CQuranVerse* GetNextVerseWithRoot(CQuranWord*);
			CQuranVerse* GetPreviousVerseWithRoot(std::vector<int>);
			CQuranVerse* GetPreviousVerseWithRoot(std::vector<letter_t>);
			CQuranVerse* GetPreviousVerseWithRoot(CQuranWord*);

			CQuranVerse* GetNextVerseWithWord(std::vector<int>, int = 0);
			CQuranVerse* GetNextVerseWithWord(std::vector<letter_t>);
			CQuranVerse* GetNextVerseWithWord(std::vector<Character*>, int = 0);
			CQuranVerse* GetNextVerseWithWord(CQuranWord*, int = 0);
			CQuranVerse* GetPreviousVerseWithWord(std::vector<int>, int = 0);
			CQuranVerse* GetPreviousVerseWithWord(std::vector<letter_t>);
			CQuranVerse* GetPreviousVerseWithWord(std::vector<Character*>, int = 0);
			CQuranVerse* GetPreviousVerseWithWord(CQuranWord*, int = 0);

			CQuranVerse* GetNextVerseWithPhrase(std::vector<int>, int = 0);
			CQuranVerse* GetNextVerseWithPhrase(std::vector<letter_t>);
			CQuranVerse* GetNextVerseWithPhrase(std::vector<Character*>, int = 0);
			CQuranVerse* GetNextVerseWithPhrase(std::vector<CQuranCharacter*>, int = 0);
			CQuranVerse* GetNextVerseWithPhrase(std::vector<CQuranWord*>, int = 0);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<int>, int = 0);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<letter_t>);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<Character*>, int = 0);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<CQuranCharacter*>, int = 0);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<CQuranWord*>, int = 0);

			virtual std::string ToString() = 0;
			virtual std::string GetTranslation() = 0;
			virtual std::string SoundOf(bool = false) = 0;
	};

	class CQuranCharacter : public CQuranNode
	{
		private:
			Character* character;

		public:
			CQuranCharacter();
			CQuranCharacter(Character*);
			CQuranCharacter(Character*, Attributes);
			~CQuranCharacter();

			Character* GetCharacter();
			int GetASCII();

			std::string ToString();
			std::string GetTranslation();
			std::string SoundOf(bool = false);
	};
	
	class CQuranWord : public CQuranNode
	{
		private:
			std::vector<CQuranCharacter*> word;
			std::string translation;

			friend class CQuranNode;

		public:
			CQuranWord();
			CQuranWord(std::vector<CQuranCharacter*>, std::string = "");
			CQuranWord(std::vector<CQuranCharacter*>, Attributes, std::string = "");
			~CQuranWord();

			std::vector<CQuranCharacter*> GetWord();
			CQuranCharacter* GetCharacter(int);
			std::vector<int> GetASCII();

			int Count();

			std::string ToString();
			std::string GetTranslation();
			std::string SoundOf(bool = false);

			CQuranCharacter* operator[](size_t);
	};
	
	class CQuranVerse : public CQuranNode
	{
		private:
			std::vector<CQuranWord*> verse;

			friend class CQuranNode;

		public:
			CQuranVerse();
			CQuranVerse(std::vector<CQuranWord*>);
			CQuranVerse(std::vector<CQuranWord*>, Attributes);
			~CQuranVerse();

			std::vector<CQuranWord*> GetVerse();
			CQuranWord* GetWord(int);
			CQuranCharacter* GetCharacter(int, int);

			int Count();

			std::string ToString();
			std::string GetTranslation();
			std::string SoundOf(bool = false);

			CQuranWord* operator[](size_t);
	};
	
	class CQuranChapter : public CQuranNode
	{
		private:
			std::vector<CQuranVerse*> chapter;

			friend class CQuranNode;

		public:
			CQuranChapter();
			CQuranChapter(std::vector<CQuranVerse*>);
			CQuranChapter(std::vector<CQuranVerse*>, Attributes);
			~CQuranChapter();

			std::vector<CQuranVerse*> GetChapter();
			CQuranVerse* GetVerse(int);
			CQuranWord* GetWord(int, int);
			CQuranCharacter* GetCharacter(int, int, int);

			int Count();

			std::string ToString();
			std::string GetTranslation();
			std::string SoundOf(bool = false);

			CQuranVerse* operator[](size_t);
	};

	class CQuranTree
	{
		public:
			struct State
			{
				CQuranCharacter* cursor;
			};

		private:
			std::vector<CQuranChapter*> chapters;
			std::map<std::string, int> settings;
			std::vector<State> state;
			int searchParameters;

			void PopulateData();
			void DeleteData();

		public:
			bool Debug = false;

			CQuranTree();
			~CQuranTree();

			std::vector<CQuranChapter*> GetQuran();

			CQuranNode* Get(int, int, int, int);
			CQuranNode* Get(int, int, int);
			CQuranNode* Get(int, int);
			CQuranNode* Get(int);

			CQuranCharacter* GetCharacter(int, int, int, int);
			CQuranCharacter* GetLetter(int, int, int, int);
			CQuranCharacter* GetDiacritic(int, int, int, int);
			CQuranCharacter* GetSymbol(int, int, int, int);
			CQuranWord* GetWord(int, int, int);
			CQuranVerse* GetVerse(int);
			CQuranVerse* GetVerse(int, int);
			CQuranChapter* GetChapter(int);

			CQuranCharacter* GetSymbolAt(int);
			CQuranCharacter* GetDiacriticAt(int);
			CQuranCharacter* GetLetterAt(int);
			CQuranCharacter* GetCharacterAt(int);
			CQuranWord* GetWordAt(int, bool);
			CQuranVerse* GetVerseAt(int);
			CQuranChapter* GetChapterAt(int);

			CQuranVerse* GetBasmallahAt(int);
			CQuranChapter* GetMakkanChapterAt(int);
			CQuranChapter* GetMadinanChapterAt(int);

			int LetterCount(int);
			int LetterCount(letter_t);
			int DiacriticCount(int);
			int DiacriticCount(diacritic_t);
			int SymbolCount(int);
			int SymbolCount(symbol_t);
			int CharacterCount(int);
			int CharacterCount(Character*);
			int CharacterCount(CQuranCharacter*);

			int WordCount(std::vector<letter_t>);				// (ex.with word, display counts of each grammatical category)
			int WordCount(std::vector<Character*>);
			int WordCount(CQuranWord*);

			int VerseCount(std::vector<std::vector<letter_t>>);
			int VerseCount(std::vector<std::vector<Character*>>);
			int VerseCount(CQuranVerse*);
			int PhraseCount(std::vector<std::vector<letter_t>>);
			int PhraseCount(std::vector<std::vector<Character*>>);
			int PhraseCount(CQuranVerse*);

			std::vector<CQuranCharacter*> OccurancesOfLetter(int);
			std::vector<CQuranCharacter*> OccurancesOfLetter(letter_t);
			std::vector<CQuranCharacter*> OccurancesOfDiacritic(int);
			std::vector<CQuranCharacter*> OccurancesOfDiacritic(diacritic_t);
			std::vector<CQuranCharacter*> OccurancesOfSymbol(int);
			std::vector<CQuranCharacter*> OccurancesOfSymbol(symbol_t);
			std::vector<CQuranCharacter*> OccurancesOfCharacter(int);
			std::vector<CQuranCharacter*> OccurancesOfCharacter(Character*);
			std::vector<CQuranCharacter*> OccurancesOfCharacter(CQuranCharacter*);

			std::vector<CQuranWord*> OccurancesOfWord(std::vector<letter_t>);
			std::vector<CQuranWord*> OccurancesOfWord(std::vector<Character>);
			std::vector<CQuranWord*> OccurancesOfWord(CQuranWord*);

			std::vector<CQuranVerse*> OccurancesOfVerse(std::vector<std::vector<letter_t>>);
			std::vector<CQuranVerse*> OccurancesOfVerse(std::vector<std::vector<Character>>);
			std::vector<CQuranVerse*> OccurancesOfVerse(CQuranVerse*);
			std::vector<CQuranVerse*> OccurancesOfPhrase(std::vector<std::vector<letter_t>>);
			std::vector<CQuranVerse*> OccurancesOfPhrase(std::vector<std::vector<Character>>);
			std::vector<CQuranVerse*> OccurancesOfPhrase(CQuranVerse*);

			int DistanceBetween(CQuranCharacter*);
			int DistanceBetween(CQuranWord*);
			int DistanceBetween(CQuranVerse*);

			int DistanceBetween(CQuranCharacter*, CQuranCharacter*);
			int DistanceBetween(CQuranCharacter*, CQuranWord*);
			int DistanceBetween(CQuranCharacter*, CQuranVerse*);
			
			int DistanceBetween(CQuranWord*, CQuranCharacter*);
			int DistanceBetween(CQuranWord*, CQuranWord*);
			int DistanceBetween(CQuranWord*, CQuranVerse*);
			
			int DistanceBetween(CQuranVerse*, CQuranCharacter*);
			int DistanceBetween(CQuranVerse*, CQuranWord*);
			int DistanceBetween(CQuranVerse*, CQuranVerse*);

			int DistanceBetween(CQuranChapter*, CQuranChapter*);


			//@TODO: make sure symbols are ignored in searches!!! (except for searching specifically for symbols obviously)
			static bool Equals(std::vector<int>, std::vector<int>);
			static bool Equals(std::vector<int>, std::vector<letter_t>);
			static bool Equals(std::vector<letter_t>, std::vector<int>);
			static bool Equals(std::vector<letter_t>, std::vector<letter_t>);
			static bool Equals(CQuranWord*, CQuranWord*, bool = false);
			static bool Equals(CQuranWord*, std::vector<int>, bool = false);
			static bool Equals(CQuranWord*, std::vector<letter_t>);
			static bool Equals(CQuranWord*, std::vector<Character*>, bool = false);
			static bool Equals(CQuranWord*, std::vector<CQuranCharacter*>, bool = false);
			static bool Equals(CQuranVerse*, CQuranVerse*, bool = false);
			static bool Equals(CQuranVerse*, std::vector<CQuranWord*>*, bool = false);

			static bool Contains(CQuranWord*, int);
			static bool Contains(CQuranWord*, letter_t);
			static bool Contains(CQuranWord*, Character*);
			static bool Contains(CQuranWord*, CQuranCharacter*);
			static bool Contains(CQuranVerse*, int);
			static bool Contains(CQuranVerse*, letter_t);
			static bool Contains(CQuranVerse*, Character*);
			static bool Contains(CQuranVerse*, CQuranCharacter*);
			static bool Contains(CQuranVerse*, std::vector<int>, bool = false);
			static bool Contains(CQuranVerse*, std::vector<letter_t>);
			static bool Contains(CQuranVerse*, std::vector<Character*>, bool = false);
			static bool Contains(CQuranVerse*, std::vector<CQuranCharacter*>, bool = false);
			static bool Contains(CQuranVerse*, CQuranWord*, bool = false);
			static bool Contains(CQuranChapter*, int);
			static bool Contains(CQuranChapter*, letter_t);
			static bool Contains(CQuranChapter*, Character*);
			static bool Contains(CQuranChapter*, CQuranCharacter*);
			static bool Contains(CQuranChapter*, std::vector<int>, bool = false);
			static bool Contains(CQuranChapter*, std::vector<letter_t>);
			static bool Contains(CQuranChapter*, std::vector<Character*>, bool = false);
			static bool Contains(CQuranChapter*, std::vector<CQuranCharacter*>, bool = false);
			static bool Contains(CQuranChapter*, CQuranVerse*);

			CQuranChapter* operator[](size_t);
	};

	typedef Attributes::RevelationPeriod revelation_t;
	typedef CQuranNode::Type node_t;

	bool is_enabled(int, int);

	//@TODO: include searchParameters for these
	int verse_num_by_chapter(int);
	int total_verse_num_by_chapter(int);

	int chapter_num_by_total_verse(int);

	bool is_letter(CQuranCharacter*, bool = false);
	bool is_diacritic(CQuranCharacter*);
	bool is_symbol(CQuranCharacter*);

	bool is_makkan(revelation_t);
	bool is_makkan(CQuranNode*);
	bool is_madinan(revelation_t);
	bool is_madinan(CQuranNode*);
}
/*
namespace Quran_old
{
	const int NumChapters				= 114;
	const int NumVerses					= 6236;
	const int NumVersesBasmallah		= 6348;
	const int NumWords					= 77878;
	const int NumWordsBasmallah			= 78326;
	const int NumWordsWaw				= 0;
	const int NumWordsBasmallahWaw		= 0;
	const int NumLetters				= 327792;
	const int NumLettersBasmallah		= 329920;
	const int NumLettersWaw				= 0;
	const int NumLettersBasmallahWaw	= 0;
	const int NumPages					= 604;
	const int NumStations				= 7;
	const int NumParts					= 30;
	const int NumHalves					= NumParts * 2;
	const int NumQuarters				= NumHalves * 4;
	const int NumBowings				= 556;

	// http://www.islamguiden.com/arabic/esymbol1.html
	enum class Symbol
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

	enum class RevelationPeriod
	{
		UNKNOWN = 0,
		MECCAN = 1,
		MEDINAN = 2,
		LATE_MECCAN = 3,
	};

	struct TextualPosition
	{
		int chapterNum;
		int verseNum;
		int verseNumBasmallah;
		int wordNum;
		int wordNumBasmallah;
		int wordNumWaw;
		int wordNumBasmallahWaw;
		int letterNum;
		int letterNumBasmallah;
		int letterNumWaw;
		int letterNumBasmallahWaw;
		int pageNum;
		int stationNum;
		int partNum;
		int halfNum;
		int quarterNum;
		int bowingNum;

		TextualPosition();
		TextualPosition(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
	};

	class Word;
	class Verse;
	class Chapter;

	class Letter : public Arabic_old::Letter
	{
		private:
			std::vector<Symbol> symbols;
			TextualPosition textualPosition;

			void SetTextualPosition(TextualPosition);

			friend class Word;

		public:
			Letter(Arabic_old::Character, Arabic_old::Diacritic, std::vector<Arabic_old::Diacritic>, std::vector<Symbol>, Arabic_old::Position = Arabic_old::Position::NONE);
			~Letter();

			void Reset();

			TextualPosition GetTextualPosition();

			void SetSymbols(std::vector<Symbol>);
			void SetSymbol(int, Symbol);
			void AddSymbol(Symbol);
			void AddSymbol(int);
			void AddSymbol(std::string);
			void RemoveSymbol(int);
			void RemoveSymbol(Symbol);
			void ClearSymbol();

			std::vector<int> GetASCII() const;
			std::vector<std::string> GetHex() const;

			int ASCIICount() const;

			bool IsArabic(bool, bool, bool, bool);
	};
	
	// Note that GetLetters() returns Arabic_old::Letters, not Quran::Letters, while the [] operator returns a Quran::Letter and not an Arabic_old::Letter
	class Word : public Arabic_old::Word
	{
		private:
			TextualPosition textualPosition;

			void SetTextualPosition(TextualPosition);

			friend class Verse;

		public:
			TextualPosition GetTextualPosition();

			Arabic_old::Letter& operator [](int);
	};

	extern std::map<Symbol, int> ASCIIBySymbol;
	extern std::map<int, Symbol> SymbolByASCII;

	class Verse
	{
		public:
			struct Attributes
			{
				RevelationPeriod revelationPeriod;
				int numberOfWords;
				int numberOfLetters;
				int chapterNum;
				int verseNum;
				int verseNumBasmallah;
				int wordNum;
				int wordNumBasmallah;
				int wordNumWaw;
				int wordNumBasmallahWaw;
				int letterNum;
				int letterNumBasmallah;
				int letterNumWaw;
				int letterNumBasmallahWaw;
				int pageNum;
				int stationNum;
				int partNum;
				int halfNum;
				int quarterNum;
				int bowingNum;
			};

		private:
			std::vector<Word> words;
			TextualPosition textualPosition;
			Attributes attributes;

			void SetTextualPosition(TextualPosition);
			void SetAttributes(Attributes);

			friend class Chapter;

		public:
			Verse();
			Verse(std::vector<Word>, TextualPosition, Attributes);
			~Verse();

			std::vector<Word> GetWords();
			std::vector<int> GetASCII();
			std::vector<std::string> GetHex();

			std::string GetChapterName();
			TextualPosition GetTextualPosition();
			Attributes GetAttributes();

			int GetAbjadValue();
			int GetSequentialValue();

			std::string to_string();

			Word& operator [](int);
			bool operator ==(const Verse&);
			bool operator !=(const Verse&);

			int Count() const;
			int CharacterCount() const;
			int DiacriticCount() const;
			int LetterCount() const;
			int WordCount(bool = true) const;

			bool IsMeccan();
			bool IsMedinan();
	};

	class Chapter
	{
		public:
			struct Attributes
			{
				RevelationPeriod revelationPeriod = RevelationPeriod::UNKNOWN;
				int chronologicalOrder;
				int numberOfVerses;
				int numberOfWords;
				int numberOfLetters;
			};

		private:
			std::vector<Verse> verses;
			TextualPosition textualPosition;
			Attributes attributes;

			void PopulateData(std::string);
			void PopulateData(std::ifstream);

		public:
			enum class Name
			{
				UNKNOWN_ERROR = 0,
				AL_FATIHA,		// 1
				AL_BAQARAH, 	// 2
				ALI_IMRAN,  	// 3
				AL_NISA,    	// 4
				AL_MAIDAH, 		// 5
				AL_ANAM, 		// 6
				AL_ARAF, 		// 7
				AL_ANFAL, 		// 8
				AT_TAWBAH, 		// 9
				YUNUS,			// 10
				HUD,			// 11
				YUSUF,			// 12
				AR_RAD,			// 13
				IBRAHIM,		// 14
				AL_HIJR,		// 15
				AN_NAHL,		// 16
				AL_ISRA,		// 17
				AL_KAHF,		// 18
				MARYAM,			// 19
				TAHA, 			// 20
				AL_ANBIYA,		// 21
				AL_HAJJ,		// 22
				AL_MUMINUN,		// 23
				AN_NUR,			// 24
				AL_FURQAN,		// 25
				ASH_SHUARA,		// 26
				AN_NAML,		// 27
				AL_QASAS,		// 28
				AL_ANKABOOT, 	// 29
				AR_ROOM,		// 30
				LUQMAN,			// 31
				AS_SAJDAH,		// 32
				AL_AHZAB,		// 33
				SABA,			// 34
				FATIR,			// 35
				YASIN,			// 36
				AS_SAFFAT,		// 37
				SAD,			// 38
				AZ_ZUMAR,		// 39
				GHAFIR,			// 40
				FUSSILAT,		// 41
				ASH_SHURA,		// 42
				AZ_ZUKHRUF,		// 43
				AD_DUKHAN,		// 44
				AL_JATHIYAH,	// 45
				AL_AHQAF,		// 46
				MUHAMMAD,		// 47
				AL_FATH,		// 48
				AL_HUJURAT,		// 49
				QAF,			// 50
				AD_DHARIYAT,	// 51
				AT_TOOR,		// 52
				AN_NAJM,		// 53
				AL_QAMAR,		// 54
				AR_RAHMAN,		// 55
				AL_WAQIAH,		// 56
				AL_HADEED,		// 57
				AL_MUJADILAH,	// 58
				AL_HASHR,		// 59
				AL_MUMTAHANAH,	// 60
				AS_SAFF,		// 61
				AL_JUMUAH,		// 62
				AL_MUNAFIQUN,	// 63
				AT_TAGHABUN,	// 64
				AT_TALAQ,		// 65
				AT_TAHRIM,		// 66
				AL_MULK,		// 67
				AL_QALAM,		// 68
				AL_HAQAH,		// 69
				AL_MAARIJ,		// 70
				NOOH,			// 71
				AL_JINN,		// 72
				AL_MUZZAMMIL,	// 73
				AL_MUDDATHTHIR,	// 74
				AL_QIYAMAH,		// 75
				AL_INSAN,		// 76
				AL_MURSALAT,	// 77
				AN_NABA,		// 78
				AN_NAZIAT,		// 79
				ABASA,			// 80
				AT_TAKWEER,		// 81
				AL_INFITAR,		// 82
				AL_MUTAFFIFIN,	// 83
				AL_INSHIQAQ,	// 84
				AL_BURUJ,		// 85
				AT_TARIQ,		// 86
				AL_ALA,			// 87
				AL_GHASHIYAH,	// 88
				AL_FAJR,		// 89
				AL_BALAD,		// 90
				ASH_SHAMS,		// 91
				AL_LAYL,		// 92
				AD_DUHA,		// 93
				ASH_SHARH,		// 94
				AT_TEEN,		// 95
				AL_ALAQ,		// 96
				AL_QADR,		// 97
				AL_BAYINNAH,	// 98
				AL_ZALZALAH,	// 99
				AL_ADIYAT,		// 100
				AL_QARIAH,		// 101
				AT_TAKATHUR,	// 102
				AL_ASR,			// 103
				AL_HUMUZAH,		// 104
				AL_FEEL,		// 105
				QURAYSH,		// 106
				AL_MAOON,		// 107
				AL_KAWTHAR,		// 108
				AL_KAFIRUN,		// 109
				AN_NASR,		// 110
				AL_MASAD,		// 111
				AL_IKHLAS,		// 112
				AL_FALAQ,		// 113
				AN_NAS			// 114
			};

			Chapter();
			Chapter(int, std::string = QURAN_PATH);
			Chapter(Name, std::string = QURAN_PATH);
			~Chapter();

			std::vector<Verse> GetVerses();
			TextualPosition GetTextualPosition();
			Attributes GetAttributes();

			int GetAbjadValue();
			int GetSequentialValue();

			std::vector<int> GetASCII();
			std::vector<std::string> GetHex();

			Verse& operator [](int);

			int Count() const;
			int CharacterCount() const;
			int DiacriticCount() const;
			int LetterCount() const;
			int WordCount(bool = true) const;
			int VerseCount(bool = false) const;

			bool IsMeccan();
			bool IsMedinan();
	};

	const std::map<Chapter::Name, int> VerseNumByChapter
	{
		{Chapter::Name::UNKNOWN_ERROR,	0},
		{Chapter::Name::AL_FATIHA,		7},		// 1
		{Chapter::Name::AL_BAQARAH,		286},	// 2
		{Chapter::Name::ALI_IMRAN,		200},	// 3
		{Chapter::Name::AL_NISA,		176},	// 4
		{Chapter::Name::AL_MAIDAH,		120},	// 5
		{Chapter::Name::AL_ANAM,		165},	// 6
		{Chapter::Name::AL_ARAF,		206},	// 7
		{Chapter::Name::AL_ANFAL,		75},	// 8
		{Chapter::Name::AT_TAWBAH,		129},	// 9
		{Chapter::Name::YUNUS,			109},	// 10
		{Chapter::Name::HUD,			123},	// 11
		{Chapter::Name::YUSUF,			111},	// 12
		{Chapter::Name::AR_RAD,			43},	// 13
		{Chapter::Name::IBRAHIM, 		52},	// 14
		{Chapter::Name::AL_HIJR,		99},	// 15
		{Chapter::Name::AN_NAHL,		128},	// 16
		{Chapter::Name::AL_ISRA,		111},	// 17
		{Chapter::Name::AL_KAHF,		110},	// 18
		{Chapter::Name::MARYAM,			98},	// 19
		{Chapter::Name::TAHA,			135},	// 20
		{Chapter::Name::AL_ANBIYA,		112},	// 21
		{Chapter::Name::AL_HAJJ,		78},	// 22
		{Chapter::Name::AL_MUMINUN,		118},	// 23
		{Chapter::Name::AN_NUR,			64},	// 24
		{Chapter::Name::AL_FURQAN,		77},	// 25
		{Chapter::Name::ASH_SHUARA,		227},	// 26
		{Chapter::Name::AN_NAML,		93},	// 27
		{Chapter::Name::AL_QASAS,		88},	// 28
		{Chapter::Name::AL_ANKABOOT,	69},	// 29
		{Chapter::Name::AR_ROOM,		60},	// 30
		{Chapter::Name::LUQMAN,			34},	// 31
		{Chapter::Name::AS_SAJDAH,		30},	// 32
		{Chapter::Name::AL_AHZAB,		73},	// 33
		{Chapter::Name::SABA,			54},	// 34
		{Chapter::Name::FATIR,			45},	// 35
		{Chapter::Name::YASIN,			83},	// 36
		{Chapter::Name::AS_SAFFAT,		182},	// 37
		{Chapter::Name::SAD,			88},	// 38
		{Chapter::Name::AZ_ZUMAR,		75},	// 39
		{Chapter::Name::GHAFIR,			85},	// 40
		{Chapter::Name::FUSSILAT,		54},	// 41
		{Chapter::Name::ASH_SHURA,		53},	// 42
		{Chapter::Name::AZ_ZUKHRUF,		89},	// 43
		{Chapter::Name::AD_DUKHAN,		59},	// 44
		{Chapter::Name::AL_JATHIYAH,	37},	// 45
		{Chapter::Name::AL_AHQAF,		35},	// 46
		{Chapter::Name::MUHAMMAD,		38},	// 47
		{Chapter::Name::AL_FATH,		29},	// 48
		{Chapter::Name::AL_HUJURAT,		18},	// 49
		{Chapter::Name::QAF,			45},	// 50
		{Chapter::Name::AD_DHARIYAT,	60},	// 51
		{Chapter::Name::AT_TOOR,		49},	// 52
		{Chapter::Name::AN_NAJM,		62},	// 53
		{Chapter::Name::AL_QAMAR,		55},	// 54
		{Chapter::Name::AR_RAHMAN,		78},	// 55
		{Chapter::Name::AL_WAQIAH,		96},	// 56
		{Chapter::Name::AL_HADEED,		29},	// 57
		{Chapter::Name::AL_MUJADILAH,	22},	// 58
		{Chapter::Name::AL_HASHR,		24},	// 59
		{Chapter::Name::AL_MUMTAHANAH,	13},	// 60
		{Chapter::Name::AS_SAFF,		14},	// 61
		{Chapter::Name::AL_JUMUAH,		11},	// 62
		{Chapter::Name::AL_MUNAFIQUN,	11},	// 63
		{Chapter::Name::AT_TAGHABUN,	18},	// 64
		{Chapter::Name::AT_TALAQ,		12},	// 65
		{Chapter::Name::AT_TAHRIM,		12},	// 66
		{Chapter::Name::AL_MULK,		30},	// 67
		{Chapter::Name::AL_QALAM,		52},	// 68
		{Chapter::Name::AL_HAQAH,		52},	// 69
		{Chapter::Name::AL_MAARIJ,		44},	// 70
		{Chapter::Name::NOOH,			28},	// 71
		{Chapter::Name::AL_JINN,		28},	// 72
		{Chapter::Name::AL_MUZZAMMIL,	20},	// 73
		{Chapter::Name::AL_MUDDATHTHIR,	56},	// 74
		{Chapter::Name::AL_QIYAMAH,		40},	// 75
		{Chapter::Name::AL_INSAN,		31},	// 76
		{Chapter::Name::AL_MURSALAT,	50},	// 77
		{Chapter::Name::AN_NABA,		40},	// 78
		{Chapter::Name::AN_NAZIAT,		46},	// 79
		{Chapter::Name::ABASA,			42},	// 80
		{Chapter::Name::AT_TAKWEER,		29},	// 81
		{Chapter::Name::AL_INFITAR,		19},	// 82
		{Chapter::Name::AL_MUTAFFIFIN,	36},	// 83
		{Chapter::Name::AL_INSHIQAQ,	25},	// 84
		{Chapter::Name::AL_BURUJ,		22},	// 85
		{Chapter::Name::AT_TARIQ,		17},	// 86
		{Chapter::Name::AL_ALA,			19},	// 87
		{Chapter::Name::AL_GHASHIYAH,	26},	// 88
		{Chapter::Name::AL_FAJR,		30},	// 89
		{Chapter::Name::AL_BALAD,		20},	// 90
		{Chapter::Name::ASH_SHAMS,		15},	// 91
		{Chapter::Name::AL_LAYL,		21},	// 92
		{Chapter::Name::AD_DUHA,		11},	// 93
		{Chapter::Name::ASH_SHARH,		8},		// 94
		{Chapter::Name::AT_TEEN,		8},		// 95
		{Chapter::Name::AL_ALAQ,		19},	// 96
		{Chapter::Name::AL_QADR,		5},		// 97
		{Chapter::Name::AL_BAYINNAH,	8},		// 98
		{Chapter::Name::AL_ZALZALAH,	8},		// 99
		{Chapter::Name::AL_ADIYAT,		11},	// 100
		{Chapter::Name::AL_QARIAH,		11},	// 101
		{Chapter::Name::AT_TAKATHUR,	8},		// 102
		{Chapter::Name::AL_ASR,			3},		// 103
		{Chapter::Name::AL_HUMUZAH,		9},		// 104
		{Chapter::Name::AL_FEEL,		5},		// 105
		{Chapter::Name::QURAYSH,		4},		// 106
		{Chapter::Name::AL_MAOON,		7},		// 107
		{Chapter::Name::AL_KAWTHAR,		3},		// 108
		{Chapter::Name::AL_KAFIRUN,		6},		// 109
		{Chapter::Name::AN_NASR,		3},		// 110
		{Chapter::Name::AL_MASAD,		5},		// 111
		{Chapter::Name::AL_IKHLAS,		4},		// 112
		{Chapter::Name::AL_FALAQ,		5},		// 113
		{Chapter::Name::AN_NAS,			6},		// 114
	};

	class QuranTree
	{
		private:
			std::string quranPath = QURAN_PATH;
			std::vector<Chapter> chapters;

		public:
			QuranTree();
			QuranTree(std::string);
			~QuranTree();

			void PopulateData();
	};

	bool is_meccan(RevelationPeriod);
	bool is_medinan(RevelationPeriod);

	bool is_character(int);
	bool is_character(int, int, int);
	bool is_character(int, int, int, int, int, int, int);
	bool is_character(std::string, std::string = "");

	bool is_symbol(int);
	bool is_symbol(std::string);

	bool is_arabic(int, bool = true);
	bool is_arabic(std::string, bool = true);

	std::string to_string(int);
	std::string to_string(Symbol);
	std::string to_string(RevelationPeriod);
	std::string to_string(Chapter::Name);

	int to_ascii(Symbol);
	int to_ascii(Letter);

	std::string to_hex(Symbol);
	std::string to_hex(Letter);

	std::string sound_of(int);
	std::string sound_of(Letter, bool = true);
	std::string sound_of(std::vector<Letter>, bool = true);
	std::string sound_of(Word, bool = true);
	std::string sound_of(std::vector<Word>, bool = true);
	std::string sound_of(Verse, bool = true);

	int abjad_value(Letter);
	int abjad_value(std::vector<Letter>);
	int abjad_value(Word);
	int abjad_value(std::vector<Word>);
	int abjad_value(Verse);
	int abjad_value(std::vector<Verse>);
	int abjad_value(Chapter);

	int sequential_value(Letter);
	int sequential_value(std::vector<Letter>);
	int sequential_value(Word);
	int sequential_value(std::vector<Word>);
	int sequential_value(Verse);
	int sequential_value(std::vector<Verse>);
	int sequential_value(Chapter);

	bool validate_file(std::string);
}
*/