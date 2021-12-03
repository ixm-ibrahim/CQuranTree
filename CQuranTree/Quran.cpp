#include "Quran.h"

using namespace Quran;



///////////////////////////////////////////////////////////////////////////////
// Quran 
///////////////////////////////////////////////////////////////////////////////


std::string Quran::to_string(RevelationPeriod r)
{
	switch (r)
	{
		case RevelationPeriod::MECCAN:
			return "MECCAN";
		case RevelationPeriod::MEDINAN:
			return "MEDINAN";
		case RevelationPeriod::LATE_MECCAN:
			return "LATE_MECCAN";
	}

	return "UNKNOWN";
}
std::string Quran::to_string(Chapter::Name n)
{
	switch (n)
	{
		case Chapter::Name::AL_FATIHA:
			return "AL_FATIHA";
		case Chapter::Name::AL_BAQARAH:
			return "AL_BAQARAH";
		case Chapter::Name::ALI_IMRAN:
			return "ALI_IMRAN";
		case Chapter::Name::AL_NISA:
			return "AL_NISA";
		case Chapter::Name::AL_MAIDAH:
			return "AL_MAIDAH";
		case Chapter::Name::AL_ANAM:
			return "AL_ANAM";
		case Chapter::Name::AL_ARAF:
			return "AL_ARAF";
		case Chapter::Name::AL_ANFAL:
			return "AL_ANFAL";
		case Chapter::Name::AT_TAWBAH:
			return "AT_TAWBAH";
		case Chapter::Name::YUNUS:
			return "YUNUS";
		case Chapter::Name::HUD:
			return "HUD";
		case Chapter::Name::YUSUF:
			return "YUSUF";
		case Chapter::Name::AR_RAD:
			return "AR_RAD";
		case Chapter::Name::IBRAHIM:
			return "IBRAHIM";
		case Chapter::Name::AL_HIJR:
			return "AL_HIJR";
		case Chapter::Name::AN_NAHL:
			return "AN_NAHL";
		case Chapter::Name::AL_ISRA:
			return "AL_ISRA";
		case Chapter::Name::AL_KAHF:
			return "AL_KAHF";
		case Chapter::Name::MARYAM:
			return "MARYAM";
		case Chapter::Name::TAHA:
			return "TAHA";
		case Chapter::Name::AL_ANBIYA:
			return "AL_ANBIYA";
		case Chapter::Name::AL_HAJJ:
			return "AL_HAJJ";
		case Chapter::Name::AL_MUMINUN:
			return "AL_MUMINUN";
		case Chapter::Name::AN_NUR:
			return "AN_NUR";
		case Chapter::Name::AL_FURQAN:
			return "AL_FURQAN";
		case Chapter::Name::ASH_SHUARA:
			return "ASH_SHUARA";
		case Chapter::Name::AN_NAML:
			return "AN_NAML";
		case Chapter::Name::AL_QASAS:
			return "AL_QASAS";
		case Chapter::Name::AL_ANKABOOT:
			return "AL_ANKABOOT";
		case Chapter::Name::AR_ROOM:
			return "AR_ROOM";
		case Chapter::Name::LUQMAN:
			return "LUQMAN";
		case Chapter::Name::AS_SAJDAH:
			return "AS_SAJDAH";
		case Chapter::Name::AL_AHZAB:
			return "AL_AHZAB";
		case Chapter::Name::SABA:
			return "SABA";
		case Chapter::Name::FATIR:
			return "FATIR";
		case Chapter::Name::YASIN:
			return "YASIN";
		case Chapter::Name::AS_SAFFAT:
			return "AS_SAFFAT";
		case Chapter::Name::SAD:
			return "SAD";
		case Chapter::Name::AZ_ZUMAR:
			return "AZ_ZUMAR";
		case Chapter::Name::GHAFIR:
			return "GHAFIR";
		case Chapter::Name::FUSSILAT:
			return "FUSSILAT";
		case Chapter::Name::ASH_SHURA:
			return "ASH_SHURA";
		case Chapter::Name::AZ_ZUKHRUF:
			return "AZ_ZUKHRUF";
		case Chapter::Name::AD_DUKHAN:
			return "AD_DUKHAN";
		case Chapter::Name::AL_JATHIYAH:
			return "AL_JATHIYAH";
		case Chapter::Name::AL_AHQAF:
			return "AL_AHQAF";
		case Chapter::Name::MUHAMMAD:
			return "MUHAMMAD";
		case Chapter::Name::AL_FATH:
			return "AL_FATH";
		case Chapter::Name::AL_HUJURAT:
			return "AL_HUJURAT";
		case Chapter::Name::QAF:
			return "QAF";
		case Chapter::Name::AD_DHARIYAT:
			return "AD_DHARIYAT";
		case Chapter::Name::AT_TOOR:
			return "AT_TOOR";
		case Chapter::Name::AN_NAJM:
			return "AN_NAJM";
		case Chapter::Name::AL_QAMAR:
			return "AL_QAMAR";
		case Chapter::Name::AR_RAHMAN:
			return "AR_RAHMAN";
		case Chapter::Name::AL_WAQIAH:
			return "AL_WAQIAH";
		case Chapter::Name::AL_HADEED:
			return "AL_HADEED";
		case Chapter::Name::AL_MUJADILAH:
			return "AL_MUJADILAH";
		case Chapter::Name::AL_HASHR:
			return "AL_HASHR";
		case Chapter::Name::AL_MUMTAHANAH:
			return "AL_MUMTAHANAH";
		case Chapter::Name::AS_SAFF:
			return "AS_SAFF";
		case Chapter::Name::AL_JUMUAH:
			return "AL_JUMUAH";
		case Chapter::Name::AL_MUNAFIQUN:
			return "AL_MUNAFIQUN";
		case Chapter::Name::AT_TAGHABUN:
			return "AT_TAGHABUN";
		case Chapter::Name::AT_TALAQ:
			return "AT_TALAQ";
		case Chapter::Name::AT_TAHRIM:
			return "AT_TAHRIM";
		case Chapter::Name::AL_MULK:
			return "AL_MULK";
		case Chapter::Name::AL_QALAM:
			return "AL_QALAM";
		case Chapter::Name::AL_HAQAH:
			return "AL_HAQAH";
		case Chapter::Name::AL_MAARIJ:
			return "AL_MAARIJ";
		case Chapter::Name::NOOH:
			return "NOOH";
		case Chapter::Name::AL_JINN:
			return "AL_JINN";
		case Chapter::Name::AL_MUZZAMMIL:
			return "AL_MUZZAMMIL";
		case Chapter::Name::AL_MUDDATHTHIR:
			return "AL_MUDDATHTHIR";
		case Chapter::Name::AL_QIYAMAH:
			return "AL_QIYAMAH";
		case Chapter::Name::AL_INSAN:
			return "AL_INSAN";
		case Chapter::Name::AL_MURSALAT:
			return "AL_MURSALAT";
		case Chapter::Name::AN_NABA:
			return "AN_NABA";
		case Chapter::Name::AN_NAZIAT:
			return "AN_NAZIAT";
		case Chapter::Name::ABASA:
			return "ABASA";
		case Chapter::Name::AT_TAKWEER:
			return "AT_TAKWEER";
		case Chapter::Name::AL_INFITAR:
			return "AL_INFITAR";
		case Chapter::Name::AL_MUTAFFIFIN:
			return "AL_MUTAFFIFIN";
		case Chapter::Name::AL_INSHIQAQ:
			return "AL_INSHIQAQ";
		case Chapter::Name::AL_BURUJ:
			return "AL_BURUJ";
		case Chapter::Name::AT_TARIQ:
			return "AT_TARIQ";
		case Chapter::Name::AL_ALA:
			return "AL_ALA";
		case Chapter::Name::AL_GHASHIYAH:
			return "AL_GHASHIYAH";
		case Chapter::Name::AL_FAJR:
			return "AL_FAJR";
		case Chapter::Name::AL_BALAD:
			return "AL_BALAD";
		case Chapter::Name::ASH_SHAMS:
			return "ASH_SHAMS";
		case Chapter::Name::AL_LAYL:
			return "AL_LAYL";
		case Chapter::Name::AD_DUHA:
			return "AD_DUHA";
		case Chapter::Name::ASH_SHARH:
			return "ASH_SHARH";
		case Chapter::Name::AT_TEEN:
			return "AT_TEEN";
		case Chapter::Name::AL_ALAQ:
			return "AL_ALAQ";
		case Chapter::Name::AL_QADR:
			return "AL_QADR";
		case Chapter::Name::AL_BAYINNAH:
			return "AL_BAYINNAH";
		case Chapter::Name::AL_ZALZALAH:
			return "AL_ZALZALAH";
		case Chapter::Name::AL_ADIYAT:
			return "AL_ADIYAT";
		case Chapter::Name::AL_QARIAH:
			return "AL_QARIAH";
		case Chapter::Name::AT_TAKATHUR:
			return "AT_TAKATHUR";
		case Chapter::Name::AL_ASR:
			return "AL_ASR";
		case Chapter::Name::AL_HUMUZAH:
			return "AL_HUMUZAH";
		case Chapter::Name::AL_FEEL:
			return "AL_FEEL";
		case Chapter::Name::QURAYSH:
			return "QURAYSH";
		case Chapter::Name::AL_MAOON:
			return "AL_MAOON";
		case Chapter::Name::AL_KAWTHAR:
			return "AL_KAWTHAR";
		case Chapter::Name::AL_KAFIRUN:
			return "AL_KAFIRUN";
		case Chapter::Name::AN_NASR:
			return "AN_NASR";
		case Chapter::Name::AL_MASAD:
			return "AL_MASAD";
		case Chapter::Name::AL_IKHLAS:
			return "AL_IKHLAS";
		case Chapter::Name::AL_FALAQ:
			return "AL_FALAQ";
		case Chapter::Name::AN_NAS:
			return "AN_NAS";
	}

	return "UNKNOWN_ERROR";
}

bool Quran::is_meccan(RevelationPeriod r)
{
	return r == RevelationPeriod::MECCAN || r == RevelationPeriod::LATE_MECCAN;
}
bool Quran::is_medinan(RevelationPeriod r)
{
	return r == RevelationPeriod::MEDINAN;
}

std::string Quran::sound_of(Letter, bool)
{
	return "";
}
std::string Quran::sound_of(std::vector<Letter>, bool)
{
	return "";
}
std::string Quran::sound_of(Word, bool)
{
	return "";
}
std::string Quran::sound_of(std::vector<Word>, bool)
{
	return "";
}
std::string Quran::sound_of(Verse, bool)
{
	return "";
}

int Quran::abjad_value(Letter)
{
	return 0;
}
int Quran::abjad_value(std::vector<Letter>)
{
	return 0;
}
int Quran::abjad_value(Word)
{
	return 0;
}
int Quran::abjad_value(std::vector<Word>)
{
	return 0;
}
int Quran::abjad_value(Verse)
{
	return 0;
}
int Quran::abjad_value(std::vector<Verse>)
{
	return 0;
}
int Quran::abjad_value(Chapter)
{
	return 0;
}

int Quran::sequential_value(Letter)
{
	return 0;
}
int Quran::sequential_value(std::vector<Letter>)
{
	return 0;
}
int Quran::sequential_value(Word)
{
	return 0;
}
int Quran::sequential_value(std::vector<Word>)
{
	return 0;
}
int Quran::sequential_value(Verse)
{
	return 0;
}
int Quran::sequential_value(std::vector<Verse>)
{
	return 0;
}
int Quran::sequential_value(Chapter)
{
	return 0;
}


///////////////////////////////////////////////////////////////////////////////
// TextualPosition 
///////////////////////////////////////////////////////////////////////////////


TextualPosition::TextualPosition()
{

}
TextualPosition::TextualPosition(int chapterNum, int verseNum, int verseNumBasmallah, int wordNum, int wordNumBasmallah, int wordNumWaw, int wordNumBasmallahWaw, int letterNum, int letterNumBasmallah, int letterNumWaw, int letterNumBasmallahWaw, int pageNum, int stationNum, int partNum, int halfNum, int quarterNum, int bowingNum)
{
	this->chapterNum = chapterNum;
	this->verseNum = verseNum;
	this->verseNumBasmallah = verseNumBasmallah;
	this->wordNum = wordNum;
	this->wordNumBasmallah = wordNumBasmallah;
	this->wordNumWaw = wordNumWaw;
	this->wordNumBasmallahWaw = wordNumBasmallahWaw;
	this->letterNum = letterNum;
	this->letterNumBasmallah = letterNumBasmallah;
	this->letterNumWaw = letterNumWaw;
	this->letterNumBasmallahWaw = letterNumBasmallahWaw;
	this->pageNum = pageNum;
	this->stationNum = stationNum;
	this->partNum = partNum;
	this->halfNum = halfNum;
	this->quarterNum = quarterNum;
	this->bowingNum = bowingNum;
}


///////////////////////////////////////////////////////////////////////////////
// Letter 
///////////////////////////////////////////////////////////////////////////////


void Letter::SetTextualPosition(TextualPosition textualPosition)
{
	this->textualPosition = textualPosition;
}
TextualPosition Letter::GetTextualPosition()
{
	return this->textualPosition;
}


///////////////////////////////////////////////////////////////////////////////
// Word 
///////////////////////////////////////////////////////////////////////////////


void Word::SetTextualPosition(TextualPosition textualPosition)
{
	this->textualPosition = textualPosition;
}
TextualPosition Word::GetTextualPosition()
{
	return this->textualPosition;
}


///////////////////////////////////////////////////////////////////////////////
// Verse 
///////////////////////////////////////////////////////////////////////////////


void Verse::SetTextualPosition(TextualPosition)
{

}
void Verse::SetAttributes(TextualPosition)
{

}

Verse::Verse()
{

}
Verse::Verse(std::vector<Word>, int, int, TextualPosition, Attributes)
{

}

std::vector<Word> Verse::GetWords()
{
	return std::vector<Word>();
}
std::vector<int> Verse::GetASCII()
{
	return std::vector<int>();
}
std::vector<int> Verse::GetHex()
{
	return std::vector<int>();
}

std::string Verse::GetChapterName()
{
	return Quran::to_string((Chapter::Name) this->attributes.chapterNum);
}
TextualPosition Verse::GetTextualPosition()
{
	return this->textualPosition;
}
Verse::Attributes Verse::GetAttributes()
{
	return this->attributes;
}

int Verse::GetAbjadValue()
{
	return 0;
}
int Verse::GetSequentialValue()
{
	return 0;
}

std::string Verse::to_string()
{
	return "";
}

Word& Verse::operator [](int)
{
	return this->words[0];
}
bool Verse::operator ==(Verse)
{
	return 0;
}
bool Verse::operator !=(Verse)
{
	return 0;
}

int Verse::Count()
{
	return 0;
}
int Verse::CharacterCount()
{
	return 0;
}
int Verse::DiacriticCount()
{
	return 0;
}
int Verse::LetterCount()
{
	return 0;
}
int Verse::WordCount(bool)
{
	return 0;
}

bool Verse::IsMeccan()
{
	return 0;
}
bool Verse::IsMedinan()
{
	return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Chapter 
///////////////////////////////////////////////////////////////////////////////


Chapter::~Chapter()
{

}


///////////////////////////////////////////////////////////////////////////////
// QuranTree 
///////////////////////////////////////////////////////////////////////////////

