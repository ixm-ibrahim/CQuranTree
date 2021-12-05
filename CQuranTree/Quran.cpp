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

int Quran::to_ascii(Letter l)
{
	return Arabic::ASCIIByLetter[Arabic::Letter(l.GetCharacter(), l.GetModification())];
}
std::string Quran::to_hex(Letter l)
{
	return Arabic::to_hex(to_ascii(l));
}

std::string Quran::sound_of(Letter l, bool includeDiacritics)
{
	return Arabic::sound_of(l.GetCharacter(), l.GetModification(), l.GetDiacritics(), l.GetPosition(), includeDiacritics);
}
std::string Quran::sound_of(std::vector<Letter> ls, bool includeDiacritics)
{
	std::string sound = "";

	for (auto& l : ls)
		sound += sound_of(l, includeDiacritics);

	return sound;
}
std::string Quran::sound_of(Word w, bool includeDiacritics)
{
	std::string sound = "";

	for (auto& l : w.GetLetters())
		sound += sound_of(l, includeDiacritics);

	return sound;
}
std::string Quran::sound_of(std::vector<Word> ws, bool includeDiacritics)
{
	std::string sound = sound_of(ws[0], includeDiacritics);

	for (unsigned int i = 1; i < ws.size(); i++)
		sound += " " + sound_of(ws[i], includeDiacritics);

	return sound;
}
std::string Quran::sound_of(Verse v, bool includeDiacritics)
{
	return sound_of(v.GetWords(), includeDiacritics);
}

int Quran::abjad_value(Letter l)
{
	return abjad_value(l.GetCharacter());
}
int Quran::abjad_value(std::vector<Letter> ls)
{
	int sum = 0;

	for (auto& l : ls)
		sum += abjad_value(l);

	return sum;
}
int Quran::abjad_value(Word w)
{
	int sum = 0;

	for (auto& l : w.GetLetters())
		sum += abjad_value(l);

	return sum;
}
int Quran::abjad_value(std::vector<Word> ws)
{
	int sum = 0;

	for (auto& w : ws)
		sum += abjad_value(w);

	return sum;
}
int Quran::abjad_value(Verse v)
{
	return abjad_value(v.GetWords());
}
int Quran::abjad_value(std::vector<Verse> vs)
{
	int sum = 0;

	for (auto& v : vs)
		sum += abjad_value(v);

	return sum;
}
int Quran::abjad_value(Chapter c)
{
	return abjad_value(c.GetVerses());
}

int Quran::sequential_value(Letter l)
{
	return sequential_value(l.GetCharacter());
}
int Quran::sequential_value(std::vector<Letter> ls)
{
	int sum = 0;

	for (auto& l : ls)
		sum += sequential_value(l);

	return sum;
}
int Quran::sequential_value(Word w)
{
	int sum = 0;

	for (auto& l : w.GetLetters())
		sum += sequential_value(l);

	return sum;
}
int Quran::sequential_value(std::vector<Word> ws)
{
	int sum = 0;

	for (auto& w : ws)
		sum += sequential_value(w);

	return sum;
}
int Quran::sequential_value(Verse v)
{
	return sequential_value(v.GetWords());
}
int Quran::sequential_value(std::vector<Verse> vs)
{
	int sum = 0;

	for (auto& v : vs)
		sum += sequential_value(v);

	return sum;
}
int Quran::sequential_value(Chapter c)
{
	return sequential_value(c.GetVerses());
}


///////////////////////////////////////////////////////////////////////////////
// TextualPosition 
///////////////////////////////////////////////////////////////////////////////


TextualPosition::TextualPosition()
{
	this->chapterNum = 0;
	this->verseNum = 0;
	this->verseNumBasmallah = 0;
	this->wordNum = 0;
	this->wordNumBasmallah = 0;
	this->wordNumWaw = 0;
	this->wordNumBasmallahWaw = 0;
	this->letterNum = 0;
	this->letterNumBasmallah = 0;
	this->letterNumWaw = 0;
	this->letterNumBasmallahWaw = 0;
	this->pageNum = 0;
	this->stationNum = 0;
	this->partNum = 0;
	this->halfNum = 0;
	this->quarterNum = 0;
	this->bowingNum = 0;
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

Arabic::Letter& Word::operator [](int index)
{
	return this->letters[index];
}

///////////////////////////////////////////////////////////////////////////////
// Verse 
///////////////////////////////////////////////////////////////////////////////


void Verse::SetTextualPosition(TextualPosition t)
{
	this->textualPosition = t;
}
void Verse::SetAttributes(Attributes a)
{
	this->attributes = a;
}

Verse::Verse()
{
	words.clear();
	textualPosition = TextualPosition();
	attributes = Attributes();
}
Verse::Verse(std::vector<Word> words, TextualPosition textualPosition, Attributes attributes)
{
	this->words = words;
	this->textualPosition = textualPosition;
	this->attributes = attributes;
}
Verse::~Verse()
{
	this->words.clear();
}

std::vector<Word> Verse::GetWords()
{
	return this->words;
}
std::vector<int> Verse::GetASCII()
{
	//TODO: allocate vector memory before subsequent calls to addrange
	std::vector<int> asciis;

	for (unsigned int i = 0; i < this->Count(); i++)
		Utilities::addrange(asciis, this->words[i].GetASCII());

	return asciis;
}
std::vector<std::string> Verse::GetHex()
{
	std::vector<std::string> hexes;

	for (unsigned int i = 0; i < this->Count(); i++)
		Utilities::addrange(hexes, this->words[i].GetHex());

	return hexes;
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
	return abjad_value(*this);
}
int Verse::GetSequentialValue()
{
	return sequential_value(*this);
}

std::string Verse::to_string()
{
	return sound_of(this->words);
}

Word& Verse::operator [](int index)
{
	return this->words[index];
}
bool Verse::operator ==(const Verse& rhs)
{
	if (this->Count() != rhs.Count())
		return false;

	for (unsigned int i = 0; i < this->Count(); i++)
		if (this->words[i] != rhs.words[i])
			return false;

	return true;
}
bool Verse::operator !=(const Verse& rhs)
{
	return !(*this == rhs);
}

int Verse::Count() const
{
	return this->words.size();
}
int Verse::CharacterCount() const
{
	int sum = 0;

	for (auto w : this->words)
		sum += w.CharacterCount();

	return sum;
}
int Verse::DiacriticCount() const
{
	int sum = 0;

	for (auto w : this->words)
		sum += w.DiacriticCount();

	return sum;
}
int Verse::LetterCount() const
{
	int sum = 0;

	for (auto w : this->words)
		sum += w.LetterCount();

	return sum;
}
int Verse::WordCount(bool includeWaw) const
{
	if (includeWaw)
		return this->Count();

	int sum = 0;

	for (auto& w : this->words)
		if (!(w.LetterCount() == 1 && w.GetLetters()[0].GetCharacter() == Arabic::Character::WAW))
			sum++;

	return sum;
}

bool Verse::IsMeccan()
{
	return is_meccan(this->attributes.revelationPeriod);
}
bool Verse::IsMedinan()
{
	return is_medinan(this->attributes.revelationPeriod);
}


///////////////////////////////////////////////////////////////////////////////
// Chapter 
///////////////////////////////////////////////////////////////////////////////

void Chapter::PopulateData()
{
	// depend on value in attribtues->chapterNum
}

Chapter::Chapter()
{
	this->textualPosition = TextualPosition();
	this->textualPosition.chapterNum = 0;
}
Chapter::Chapter(int chapterNum)
{
	this->textualPosition = TextualPosition();
	this->textualPosition.chapterNum = chapterNum;

	PopulateData();
}
Chapter::Chapter(Name name) : Chapter((int) name) {}
Chapter::~Chapter()
{
	this->verses.clear();
}

std::vector<Verse> Chapter::GetVerses()
{
	return this->verses;
}
TextualPosition Chapter::GetTextualPosition()
{
	return this->textualPosition;
}
Chapter::Attributes Chapter::GetAttributes()
{
	return this->attributes;
}

int Chapter::GetAbjadValue()
{
	return abjad_value(*this);
}
int Chapter::GetSequentialValue()
{
	return sequential_value(*this);
}

std::vector<int> Chapter::GetASCII()
{
	std::vector<int> asciis;

	for (unsigned int i = 0; i < this->Count(); i++)
		Utilities::addrange(asciis, this->verses[i].GetASCII());

	return asciis;
}
std::vector<std::string> Chapter::GetHex()
{
	std::vector<std::string> hexes;

	for (unsigned int i = 0; i < this->Count(); i++)
		Utilities::addrange(hexes, this->verses[i].GetHex());

	return hexes;
}

Verse& Chapter::operator [](int index)
{
	return this->verses[index];
}

int Chapter::Count() const
{
	return verses.size();
}
int Chapter::CharacterCount() const
{
	int sum = 0;

	for (auto v : this->verses)
		sum += v.CharacterCount();

	return sum;
}
int Chapter::DiacriticCount() const
{
	int sum = 0;

	for (auto v : this->verses)
		sum += v.DiacriticCount();

	return sum;
}
int Chapter::LetterCount() const
{
	int sum = 0;

	for (auto v : this->verses)
		sum += v.LetterCount();

	return sum;
}
int Chapter::WordCount(bool includeWaw) const
{
	int sum = 0;

	for (auto v : this->verses)
		sum += v.WordCount(includeWaw);

	return sum;
}
int Chapter::VerseCount(bool includeBasmallah) const
{
	return this->Count() + includeBasmallah;
}

bool Chapter::IsMeccan()
{
	return is_meccan(this->attributes.revelationPeriod);
}
bool Chapter::IsMedinan()
{
	return is_medinan(this->attributes.revelationPeriod);
}


///////////////////////////////////////////////////////////////////////////////
// QuranTree 
///////////////////////////////////////////////////////////////////////////////

QuranTree::QuranTree() {}
QuranTree::QuranTree(std::string)
{
	// I forgot why I put this here
}
QuranTree::~QuranTree()
{
	chapters.clear();
}

void QuranTree::PopulateData()
{
	for (unsigned int i = 0; i < NumChapters; i++)
		chapters.push_back(Chapter(i));
}