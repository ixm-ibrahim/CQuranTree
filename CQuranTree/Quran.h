#pragma once

#include <fstream>
#include <iostream>
#include "Arabic.h"

#define QURAN_PATH ".\\Files\\quran"

namespace Quran
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

	// http://www.islamguiden.com/arabic/etajweed1.html
	enum class Tajweed
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

	class Letter : public Arabic::Letter
	{
		private:
			std::vector<Tajweed> tajweed;
			TextualPosition textualPosition;

			void SetTextualPosition(TextualPosition);

			friend class Word;

		public:
			Letter(Arabic::Character, Arabic::Diacritic, std::vector<Arabic::Diacritic>, std::vector<Tajweed>, Arabic::Position = Arabic::Position::NONE);
			~Letter();

			void Reset();

			TextualPosition GetTextualPosition();

			void SetTajweed(std::vector<Tajweed>);
			void SetTajweed(int, Tajweed);
			void AddTajweed(Tajweed);
			void AddTajweed(int);
			void AddTajweed(std::string);
			void RemoveTajweed(int);
			void RemoveTajweed(Tajweed);
			void ClearTajweed();

			std::vector<int> GetASCII() const;
			std::vector<std::string> GetHex() const;

			int ASCIICount() const;
			int DiacriticCount() const;

			bool IsArabic(bool checkCharacter, bool checkDiacritic, bool checkSpace);
	};
	
	// Note that GetLetters() returns Arabic::Letters, not Quran::Letters, while the [] operator returns a Quran::Letter and not an Arabic::Letter
	class Word : public Arabic::Word
	{
		private:
			TextualPosition textualPosition;

			void SetTextualPosition(TextualPosition);

			friend class Verse;

		public:
			TextualPosition GetTextualPosition();

			Arabic::Letter& operator [](int);
	};

	extern std::map<Tajweed, int> ASCIIByTajweed;
	extern std::map<int, Tajweed> TajweedByASCII;

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
				int numberOfVerses;
				int numberOfWords;
				int numberOfLetters;
			};

		private:
			std::vector<Verse> verses;
			TextualPosition textualPosition;
			Attributes attributes;

			void PopulateData(std::string);

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

	bool is_tajweed(int);

	bool is_arabic(int, bool = true);

	std::string to_string(Tajweed);
	std::string to_string(RevelationPeriod);
	std::string to_string(Chapter::Name);

	int to_ascii(Tajweed);
	int to_ascii(Letter);

	std::string to_hex(Tajweed);
	std::string to_hex(Letter);

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