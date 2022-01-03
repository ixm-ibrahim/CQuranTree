#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include "Arabic.h"
#include "Utilities.h"

#define QURAN_PATH ".\\Files\\quran-uthmani.txt"

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

	struct Attributes
	{
		struct TextualPosition
		{
			int chapterNum;
			int verseNum;
			int wordNum;
			int letterNum;
			int pageNum;
			int stationNum;
			int partNum;
			int halfNum;
			int quarterNum;
			int bowingNum;
			int basmallahNum;
			int independentWawNum;
			int hamzahLetterNum;
			int hamzahAlifLamNum;

			TextualPosition();
			TextualPosition(int, int, int, int, int, int, int, int, int, int, int, int, int);
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
		bool isIndependentWaw;
		bool isHamzahBetweenLamAlif;
	};
	enum class SearchParameters
	{
		DEFAULT				= 0,
		STOP_AFTER_VERSE	= 1,
		STOP_AFTER_CHAPTER	= 2,
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

			CQuranCharacter* GetNextCharacter(int, SearchParameters = SearchParameters::DEFAULT);
			CQuranCharacter* GetNextCharacter(Character, SearchParameters = SearchParameters::DEFAULT);
			CQuranCharacter* GetNextCharacter(CQuranCharacter*, SearchParameters = SearchParameters::DEFAULT);
			CQuranCharacter* GetPreviousCharacter(int, SearchParameters = SearchParameters::DEFAULT);
			CQuranCharacter* GetPreviousCharacter(Character, SearchParameters = SearchParameters::DEFAULT);
			CQuranCharacter* GetPreviousCharacter(CQuranCharacter*, SearchParameters = SearchParameters::DEFAULT);

			CQuranWord* GetNextWord(std::vector<int>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetNextWord(std::vector<Character>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetNextWord(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetNextWord(CQuranWord*, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetPreviousWord(std::vector<int>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetPreviousWord(std::vector<Character>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetPreviousWord(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetPreviousWord(CQuranWord*, bool = false, SearchParameters = SearchParameters::DEFAULT);

			CQuranWord* GetNextWordWithRoot(std::vector<int>, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetNextWordWithRoot(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetNextWordWithRoot(CQuranWord*, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetPreviousWordWithRoot(std::vector<int>, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetPreviousWordWithRoot(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranWord* GetPreviousWordWithRoot(CQuranWord*, SearchParameters = SearchParameters::DEFAULT);

			CQuranVerse* GetNextVerse(CQuranVerse*, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerse(CQuranVerse*, SearchParameters = SearchParameters::DEFAULT);

			CQuranVerse* GetNextVerseWithRoot(std::vector<int>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetNextVerseWithRoot(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetNextVerseWithRoot(CQuranWord*, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithRoot(std::vector<int>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithRoot(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithRoot(CQuranWord*, SearchParameters = SearchParameters::DEFAULT);

			CQuranVerse* GetNextVerseWithWord(std::vector<int>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetNextVerseWithWord(std::vector<Character>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetNextVerseWithWord(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetNextVerseWithWord(CQuranWord*, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithWord(std::vector<int>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithWord(std::vector<Character>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithWord(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithWord(CQuranWord*, bool = false, SearchParameters = SearchParameters::DEFAULT);

			CQuranVerse* GetNextVerseWithPhrase(std::vector<std::vector<int>>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetNextVerseWithPhrase(std::vector<std::vector<Character>>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetNextVerseWithPhrase(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetNextVerseWithPhrase(std::vector<CQuranWord*>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<std::vector<int>>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<std::vector<Character>>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			CQuranVerse* GetPreviousVerseWithPhrase(std::vector<CQuranWord*>, bool = false, SearchParameters = SearchParameters::DEFAULT);

			virtual std::string ToString() = 0;
			virtual std::string ToEnglish() = 0;
			virtual std::string SoundOf() = 0;
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

			std::string ToString();
			std::string ToEnglish();
			std::string SoundOf();
	};
	
	class CQuranWord : public CQuranNode
	{
		private:
			std::vector<CQuranCharacter*> word;
			std::string translation;

		public:
			CQuranWord();
			CQuranWord(std::vector<CQuranCharacter*>, std::string = "");
			CQuranWord(std::vector<CQuranCharacter*>, Attributes, std::string = "");
			~CQuranWord();

			std::vector<CQuranCharacter*> GetWord();

			std::string ToString();
			std::string ToEnglish();
			std::string SoundOf();
	};
	
	class CQuranVerse : public CQuranNode
	{
		private:
			std::vector<CQuranWord*> verse;

		public:
			CQuranVerse();
			CQuranVerse(std::vector<CQuranWord*>);
			CQuranVerse(std::vector<CQuranWord*>, Attributes);
			~CQuranVerse();

			std::vector<CQuranWord*> GetVerse();

			std::string ToString();
			std::string ToEnglish();
			std::string SoundOf();
	};
	
	class CQuranChapter : public CQuranNode
	{
		private:
			std::vector<CQuranVerse*> chapter;

		public:
			CQuranChapter();
			CQuranChapter(std::vector<CQuranVerse*>);
			CQuranChapter(std::vector<CQuranVerse*>, Attributes);
			~CQuranChapter();

			std::vector<CQuranVerse*> GetChapter();

			std::string ToString();
			std::string ToEnglish();
			std::string SoundOf();
	};

	class CQuranTree
	{
		public:
			struct State
			{
				CQuranCharacter* currentCharacter;
				CQuranWord* currentWord;
				CQuranVerse* currentVerse;
				CQuranChapter* currentChapter;
			};

		private:
			std::vector<CQuranChapter*> chapters;

			std::map<std::string, int> settings;
			std::vector<State> state;

			void PopulateData();
			void DeleteData();

		public:
			bool Debug = false;

			CQuranTree();
			~CQuranTree();

			std::vector<CQuranChapter*> GetQuran();

			CQuranCharacter* GetSymbolAt(int);
			CQuranCharacter* GetDiacriticAt(int);
			CQuranCharacter* GetLetterAt(int);
			CQuranCharacter* GetCharacterAt(int);
			CQuranWord* GetWordAt(int, bool);
			CQuranVerse* GetBasmallahAt(int);
			CQuranVerse* GetVerseAt(int);
			CQuranChapter* GetMakkanChapterAt(int);
			CQuranChapter* GetMadinanChapterAt(int);
			CQuranChapter* GetChapterAt(int);


			int GetLetterCount(int, SearchParameters = SearchParameters::DEFAULT);
			int GetLetterCount(letter_t, SearchParameters = SearchParameters::DEFAULT);
			int GetDiacriticCount(int, SearchParameters = SearchParameters::DEFAULT);
			int GetDiacriticCount(diacritic_t, SearchParameters = SearchParameters::DEFAULT);
			int GetSymbolCount(int, SearchParameters = SearchParameters::DEFAULT);
			int GetSymbolCount(symbol_t, SearchParameters = SearchParameters::DEFAULT);
			int GetCharacterCount(int, SearchParameters = SearchParameters::DEFAULT);
			int GetCharacterCount(Character, SearchParameters = SearchParameters::DEFAULT);
			int GetCharacterCount(CQuranCharacter*, SearchParameters = SearchParameters::DEFAULT);

			int GetWordCount(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);				// (ex.with word, display counts of each grammatical category)
			int GetWordCount(std::vector<Character>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			int GetWordCount(CQuranWord*, bool = false, SearchParameters = SearchParameters::DEFAULT);

			int GetVerseCount(std::vector<std::vector<letter_t>>, SearchParameters = SearchParameters::DEFAULT);
			int GetVerseCount(std::vector<std::vector<Character>>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			int GetVerseCount(CQuranVerse*, bool = false, SearchParameters = SearchParameters::DEFAULT);
			int GetPhraseCount(std::vector<std::vector<letter_t>>, SearchParameters = SearchParameters::DEFAULT);
			int GetPhraseCount(std::vector<std::vector<Character>>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			int GetPhraseCount(CQuranVerse*, bool = false, SearchParameters = SearchParameters::DEFAULT);


			std::vector<CQuranCharacter*> GetOccurancesOfLetter(int, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranCharacter*> GetOccurancesOfLetter(letter_t, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranCharacter*> GetOccurancesOfDiacritic(int, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranCharacter*> GetOccurancesOfDiacritic(diacritic_t, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranCharacter*> GetOccurancesOfSymbol(int, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranCharacter*> GetOccurancesOfSymbol(symbol_t, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranCharacter*> GetOccurancesOfCharacter(int, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranCharacter*> GetOccurancesOfCharacter(Character, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranCharacter*> GetOccurancesOfCharacter(CQuranCharacter*, SearchParameters = SearchParameters::DEFAULT);

			std::vector<CQuranWord*> GetOccurancesOfWord(std::vector<letter_t>, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranWord*> GetOccurancesOfWord(std::vector<Character>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranWord*> GetOccurancesOfWord(CQuranWord*, bool = false, SearchParameters = SearchParameters::DEFAULT);

			std::vector<CQuranVerse*> GetOccurancesOfVerse(std::vector<std::vector<letter_t>>, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranVerse*> GetOccurancesOfVerse(std::vector<std::vector<Character>>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranVerse*> GetOccurancesOfVerse(CQuranVerse*, bool = false, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranVerse*> GetOccurancesOfPhrase(std::vector<std::vector<letter_t>>, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranVerse*> GetOccurancesOfPhrase(std::vector<std::vector<Character>>, bool = false, SearchParameters = SearchParameters::DEFAULT);
			std::vector<CQuranVerse*> GetOccurancesOfPhrase(CQuranVerse*, bool = false, SearchParameters = SearchParameters::DEFAULT);


			int DistanceBetween(CQuranCharacter*, SearchParameters = SearchParameters::DEFAULT);
			int DistanceBetween(CQuranWord*, bool = false, SearchParameters = SearchParameters::DEFAULT);
			int DistanceBetween(CQuranVerse*, bool = false, SearchParameters = SearchParameters::DEFAULT);

			int DistanceBetween(CQuranCharacter*, CQuranCharacter*, SearchParameters = SearchParameters::DEFAULT);
			int DistanceBetween(CQuranCharacter*, CQuranWord*, SearchParameters = SearchParameters::DEFAULT);
			int DistanceBetween(CQuranCharacter*, CQuranVerse*, SearchParameters = SearchParameters::DEFAULT);
			
			int DistanceBetween(CQuranWord*, CQuranCharacter*, SearchParameters = SearchParameters::DEFAULT);
			int DistanceBetween(CQuranWord*, CQuranWord*, SearchParameters = SearchParameters::DEFAULT);
			int DistanceBetween(CQuranWord*, CQuranVerse*, SearchParameters = SearchParameters::DEFAULT);
			
			int DistanceBetween(CQuranVerse*, CQuranCharacter*, SearchParameters = SearchParameters::DEFAULT);
			int DistanceBetween(CQuranVerse*, CQuranWord*, SearchParameters = SearchParameters::DEFAULT);
			int DistanceBetween(CQuranVerse*, CQuranVerse*, SearchParameters = SearchParameters::DEFAULT);

			int DistanceBetween(CQuranChapter*, CQuranChapter*, SearchParameters = SearchParameters::DEFAULT);
	};
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