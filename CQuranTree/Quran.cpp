#include "Quran.h"

using namespace Quran_old;



///////////////////////////////////////////////////////////////////////////////
// Quran 
///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Dictionary for looking up ASCII values by their respective Symbol symbols
/// </summary>
std::map<Symbol, int> Quran_old::ASCIIBySymbol
{
	{Symbol::COMPULSORY_STOP,		1752},
	{Symbol::PROHIBITED_STOP,		1753},
	{Symbol::GOOD_STOP,				1750},
	{Symbol::SUFFICIENT_STOP,		1751},
	{Symbol::EQUALITY_STOP,			1754},
	{Symbol::PRECAUTIONARY_STOP,	1755},
	{Symbol::BRIEF_STOP,			1756},
	{Symbol::SAJDAH,				1769},
	{Symbol::MEEM_IQLAB_ABOVE,		1762},
	{Symbol::MEEM_IQLAB_BELOW,		1773},
	{Symbol::QUARTER_OF_HALF,		1758},
};
/// <summary>
/// Dictionary for looking up Symbol symbols by their ASCII values
/// </summary>
std::map<int, Symbol> Quran_old::SymbolByASCII
{
	{1752,	Symbol::COMPULSORY_STOP},
	{1753,	Symbol::PROHIBITED_STOP},
	{1750,	Symbol::GOOD_STOP},
	{1751,	Symbol::SUFFICIENT_STOP},
	{1754,	Symbol::EQUALITY_STOP},
	{1755,	Symbol::PRECAUTIONARY_STOP},
	{1756,	Symbol::BRIEF_STOP},
	{1769,	Symbol::SAJDAH},
	{1762,	Symbol::MEEM_IQLAB_ABOVE},
	{1773,	Symbol::MEEM_IQLAB_BELOW},
	{1758,	Symbol::QUARTER_OF_HALF},
};

bool Quran_old::is_meccan(RevelationPeriod r)
{
	return r == RevelationPeriod::MECCAN || r == RevelationPeriod::LATE_MECCAN;
}
bool Quran_old::is_medinan(RevelationPeriod r)
{
	return r == RevelationPeriod::MEDINAN;
}

bool Quran_old::is_character(int ascii)
{
	return Arabic_old::is_character(ascii);
}
bool Quran_old::is_character(int ascii, int previous, int previous2)
{
	return Arabic_old::is_character(ascii) || (ascii == 1620 && (previous == 1618 || (previous == 1600 && previous2 == 1618)));
}
bool Quran_old::is_character(int ascii, int previous, int previous2, int previous3, int previous4, int after, int after2)
{
	bool alifAfter = after == 1575 || (!Arabic_old::is_character(after) && after2 == 1575);
	bool lamBefore = previous == 1604 || (previous == 1600 && previous2 == 1604) || (previous == 1600 && !Arabic_old::is_character(previous2) && previous3 == 1604) || (!Arabic_old::is_character(previous) && !Arabic_old::is_character(previous2) && !Arabic_old::is_character(previous3) && previous4 == 1604);
	
	return Arabic_old::is_character(ascii) || (ascii == 1620 && alifAfter && lamBefore);
}
bool Quran_old::is_character(std::string hex, std::string previous)
{
	return is_character(Arabic_old::to_ascii(hex), Arabic_old::to_ascii(previous), 0);
}

bool Quran_old::is_symbol(int ascii)
{
	return SymbolByASCII.count(ascii) == 1;
}
bool Quran_old::is_symbol(std::string hex)
{
	return SymbolByASCII.count(Arabic_old::to_ascii(hex)) == 1;
}

/// <summary>
/// Returns true if the ASCII value is a valid arabic character, diacritic, or symbols symbols, and false otherwise
/// </summary>
/// <param name="ascii:">ASCII value to analyze</param>
/// <returns>boolean representing if the ASCII value is a valid arabic character, diacritic, or symbols symbols</returns>
bool Quran_old::is_arabic(int ascii, bool checkSpace)
{
	return Arabic_old::is_arabic(ascii, checkSpace) || is_symbol(ascii);
}
/// <summary>
/// Returns true if the hexadecimal value is a valid arabic character, diacritic, or symbols symbols, and false otherwise
/// </summary>
/// <param name="hex:">hexadecimal value to analyze</param>
/// <returns>boolean representing if the hexadecimal value is a valid arabic character, diacritic, or symbols symbols</returns>
bool Quran_old::is_arabic(std::string hex, bool checkSpace)
{
	return Arabic_old::is_arabic(hex, checkSpace) || is_symbol(hex);
}

std::string Quran_old::to_string(int ascii)
{
	if (SymbolByASCII.count(ascii) == 1)
		return to_string(SymbolByASCII[ascii]);
	else if (Arabic_old::DiacriticByASCII.count(ascii) == 1)
		return to_string(Arabic_old::DiacriticByASCII[ascii]);
	else if (Arabic_old::LetterByASCII.count(ascii) == 1)
		return to_string(Arabic_old::LetterByASCII[ascii].GetCharacter());

	return "NONE";
}
std::string Quran_old::to_string(Symbol t)
{
	switch (t)
	{
		case Symbol::COMPULSORY_STOP:
			return "COMPULORY_STOP";
		case Symbol::PROHIBITED_STOP:
			return "PROHIBITED_STOP";
		case Symbol::GOOD_STOP:
			return "GOOD_STOP";
		case Symbol::SUFFICIENT_STOP:
			return "SUFFICIENT_STOP";
		case Symbol::EQUALITY_STOP:
			return "EQUALITY_STOP";
		case Symbol::PRECAUTIONARY_STOP:
			return "PRECAUTIONARY_STOP";
		case Symbol::BRIEF_STOP:
			return "BRIEF_STOP";
		case Symbol::SAJDAH:
			return "SAJDAH";
		case Symbol::MEEM_IQLAB_ABOVE:
			return "MEEM_IQLAB_ABOVE";
		case Symbol::MEEM_IQLAB_BELOW:
			return "MEEM_IQLAB_BELOW";
		case Symbol::QUARTER_OF_HALF:
			return "QUARTER_OF_HALF";
	}

	return "NONE";
}
std::string Quran_old::to_string(RevelationPeriod r)
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
std::string Quran_old::to_string(Chapter::Name n)
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

int Quran_old::to_ascii(Symbol t)
{
	return ASCIIBySymbol[t];
}
int Quran_old::to_ascii(Letter l)
{
	return Arabic_old::ASCIIByLetter[Arabic_old::Letter(l.GetCharacter(), l.GetModification())];
}

std::string Quran_old::to_hex(Symbol t)
{
	return Arabic_old::to_hex(to_ascii(t));
}
std::string Quran_old::to_hex(Letter l)
{
	return Arabic_old::to_hex(to_ascii(l));
}

std::string Quran_old::sound_of(int ascii)
{
	if (SymbolByASCII.count(ascii) == 1)
		return to_string(SymbolByASCII[ascii]);
	else if (Arabic_old::DiacriticByASCII.count(ascii) == 1)
		return to_string(Arabic_old::DiacriticByASCII[ascii]);
	else if (Arabic_old::LetterByASCII.count(ascii) == 1)
		return Arabic_old::LetterByASCII[ascii].to_string();

	return "";
}
std::string Quran_old::sound_of(Letter l, bool includeDiacritics)
{
	return Arabic_old::sound_of(l.GetCharacter(), l.GetModification(), l.GetDiacritics(), l.GetPosition(), includeDiacritics);
}
std::string Quran_old::sound_of(std::vector<Letter> ls, bool includeDiacritics)
{
	std::string sound = "";

	for (auto& l : ls)
		sound += sound_of(l, includeDiacritics);

	return sound;
}
std::string Quran_old::sound_of(Word w, bool includeDiacritics)
{
	std::string sound = "";

	for (auto& l : w.GetLetters())
		sound += sound_of(l, includeDiacritics);

	return sound;
}
std::string Quran_old::sound_of(std::vector<Word> ws, bool includeDiacritics)
{
	std::string sound = sound_of(ws[0], includeDiacritics);

	for (unsigned int i = 1; i < ws.size(); i++)
		sound += " " + sound_of(ws[i], includeDiacritics);

	return sound;
}
std::string Quran_old::sound_of(Verse v, bool includeDiacritics)
{
	return sound_of(v.GetWords(), includeDiacritics);
}

int Quran_old::abjad_value(Letter l)
{
	return abjad_value(l.GetCharacter());
}
int Quran_old::abjad_value(std::vector<Letter> ls)
{
	int sum = 0;

	for (auto& l : ls)
		sum += abjad_value(l);

	return sum;
}
int Quran_old::abjad_value(Word w)
{
	int sum = 0;

	for (auto& l : w.GetLetters())
		sum += abjad_value(l);

	return sum;
}
int Quran_old::abjad_value(std::vector<Word> ws)
{
	int sum = 0;

	for (auto& w : ws)
		sum += abjad_value(w);

	return sum;
}
int Quran_old::abjad_value(Verse v)
{
	return abjad_value(v.GetWords());
}
int Quran_old::abjad_value(std::vector<Verse> vs)
{
	int sum = 0;

	for (auto& v : vs)
		sum += abjad_value(v);

	return sum;
}
int Quran_old::abjad_value(Chapter c)
{
	return abjad_value(c.GetVerses());
}

int Quran_old::sequential_value(Letter l)
{
	return sequential_value(l.GetCharacter());
}
int Quran_old::sequential_value(std::vector<Letter> ls)
{
	int sum = 0;

	for (auto& l : ls)
		sum += sequential_value(l);

	return sum;
}
int Quran_old::sequential_value(Word w)
{
	int sum = 0;

	for (auto& l : w.GetLetters())
		sum += sequential_value(l);

	return sum;
}
int Quran_old::sequential_value(std::vector<Word> ws)
{
	int sum = 0;

	for (auto& w : ws)
		sum += sequential_value(w);

	return sum;
}
int Quran_old::sequential_value(Verse v)
{
	return sequential_value(v.GetWords());
}
int Quran_old::sequential_value(std::vector<Verse> vs)
{
	int sum = 0;

	for (auto& v : vs)
		sum += sequential_value(v);

	return sum;
}
int Quran_old::sequential_value(Chapter c)
{
	return sequential_value(c.GetVerses());
}

//TODO: implement logger for QuranTree
//TODO: implement parallel programming
bool Quran_old::validate_file(std::string quranPath)
{
	std::wifstream quranFile(quranPath);
	std::wstring line;
	int lines = 0;
	int wordCount = 0;
	int letterCount = 0;
	int letterWordCount = 0;

	//quranFile.imbue(std::locale("ar_SA.UTF-8"));
	quranFile.imbue(std::locale("en_US.UTF-8"));

	//std::vector<Word> words(6236);
	std::vector<Word> words;

	while (std::getline(quranFile, line))
	{
		if (line.size() == 0 || line[0] == '#')
			continue;
		
		lines++;

		//wordCount++;

		// 188 (2:181) counts as 2
		// 1166 (8:6) counts as 2
		// 1744 (13:37) counts as 2
		//bool print = lines % 100 == 0;
		//bool print = lines >= 2100 && lines <= 2200;
		bool print = false;

		Word word;

		int n = 0;
		for (unsigned int i = 0; i < line.size(); i++)
		{//
			std::cout << "\r" << lines << "/" << NumVerses;
			int ascii = int(line[i]);
			int previous = (i == 0) ? 0 : int(line[i-1]);
			int previous2 = (i <= 1) ? 0 : int(line[i-2]);
			int previous3 = (i <= 2) ? 0 : int(line[i-3]);
			int previous4 = (i <= 3) ? 0 : int(line[i-4]);
			int after = (i >= line.size() - 1) ? 0 : int(line[i+1]);
			int after2 = (i >= line.size() - 2) ? 0 : int(line[i+2]);
			//std::cout << Arabic_old::to_string(ascii) << "\t";

			// igore BOM (Byte Order Mark)
			if (ascii == 65279)
				continue;

			if (!is_arabic(ascii, true))
			{
				std::cout << std::endl << "Unknown character " << ascii << " at (" << lines << ", " << (i+2) << ")" << std::endl;
				return false;
			}
			//if (Quran_old::is_character(ascii, previous, previous2))
			//else if (Quran_old::is_character(ascii, previous, previous2, previous3, previous4, after, after2) || (lines == 79 && n == 36))
			else if (Quran_old::is_character(ascii, 0, 0, 0, 0, 0, 0) || (lines == 79 && n == 36))
			{
				word.AddLetter(Arabic_old::Letter((lines == 79 && n == 36) ? 1575 : ascii));
				
				letterCount++;
				
				n++;
			}
			//else if (ascii == ' ' && (!Quran_old::is_symbol(previous) || previous == ASCIIBySymbol[Symbol::MEEM_IQLAB_ABOVE] || previous == ASCIIBySymbol[Symbol::MEEM_IQLAB_BELOW]) && (i + 1 != line.size() - 1))
			
			if ((i == line.size() - 1 && word.Count() != 0) || (ascii == ' ' && (!Quran_old::is_symbol(previous) || previous == ASCIIBySymbol[Symbol::MEEM_IQLAB_ABOVE] || previous == ASCIIBySymbol[Symbol::MEEM_IQLAB_BELOW]) && (i + 1 != line.size() - 1)))
			{
				if (print) std::cout << std::endl;

				wordCount++;
				
				letterWordCount += word.CharacterCount();
				words.push_back(word);
				word.Reset();
			}
			
			if (print) if (Quran_old::is_symbol(ascii)) std::cout << to_string(ascii) << std::endl; else std::cout << lines << "\t" << wordCount << "\t" << letterCount << "\t" << n << "\t" << ascii << "\t" << sound_of(ascii) << std::endl;
		}

		if (print) std::cout << "------------------------------------------" << std::endl;

		if (lines == 16000)
			break;
	}

	std::cout << std::endl;
	std::cout << "Word Count: " << wordCount << std::endl;
	std::cout << "Letter Count: " << letterCount << std::endl;

	return lines == NumVerses;
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


Letter::Letter(Arabic_old::Character character, Arabic_old::Diacritic modification, std::vector<Arabic_old::Diacritic> diacritics, std::vector<Symbol> symbol, Arabic_old::Position position) : Arabic_old::Letter(character, modification, diacritics, position)
{
	SetSymbols(symbol);
}
Letter::~Letter()
{
	Reset();
}

void Letter::Reset()
{
	this->character = Arabic_old::Character::NONE;
	this->modification = Arabic_old::Diacritic::NONE;
	this->position = position;
	diacritics.clear();
	symbols.clear();
}

void Letter::SetTextualPosition(TextualPosition textualPosition)
{
	this->textualPosition = textualPosition;
}
TextualPosition Letter::GetTextualPosition()
{
	return this->textualPosition;
}

void Letter::SetSymbols(std::vector<Symbol> symbol)
{
	this->symbols = symbol;
}
void Letter::SetSymbol(int index, Symbol symbol)
{
	this->symbols[index] = symbol;
}
void Letter::AddSymbol(Symbol symbol)
{
	this->symbols.push_back(symbol);
}
void Letter::AddSymbol(int ascii)
{
	if (is_symbol(ascii))
	{
		Symbol t = SymbolByASCII[ascii];

		if (t != Symbol::NONE)
			this->symbols.push_back(t);
	}
}
void Letter::AddSymbol(std::string hex)
{
	if (is_symbol(hex))
	{
		Symbol t = SymbolByASCII[Arabic_old::to_ascii(hex)];

		if (t != Symbol::NONE)
			this->symbols.push_back(t);
	}
}
void Letter::RemoveSymbol(int index)
{
	Utilities::remove_at(this->symbols, index);
}
void Letter::RemoveSymbol(Symbol symbol)
{
	Utilities::remove_all(this->symbols, symbol);
}
void Letter::ClearSymbol()
{
	this->symbols.clear();
}

std::vector<int> Letter::GetASCII() const
{
	std::vector<int> ret;

	if (this->character != Arabic_old::Character::NONE)
		ret.push_back(to_ascii(this->character));

	int ascii = to_ascii(this->modification);
	if (Arabic_old::is_diacritic(ascii))
		ret.push_back(ascii);

	for (auto& d : this->diacritics)
	{
		ascii = to_ascii(d);
		if (Arabic_old::is_diacritic(ascii))
			ret.push_back(ascii);
	}

	for (auto& t : this->symbols)
	{
		ascii = to_ascii(t);
		if (is_symbol(ascii))
			ret.push_back(ascii);
	}

	return ret;
}
std::vector<std::string> Letter::GetHex() const
{
	std::vector<std::string> ret;

	if (this->character != Arabic_old::Character::NONE)
		ret.push_back(to_hex(this->character));

	std::string hex = to_hex(this->modification);
	if (Arabic_old::is_diacritic(hex))
		ret.push_back(hex);

	for (auto& d : this->diacritics)
	{
		hex = to_hex(d);
		if (Arabic_old::is_diacritic(hex))
			ret.push_back(hex);
	}

	for (auto& t : this->symbols)
	{
		hex = to_hex(t);
		if (is_symbol(hex))
			ret.push_back(hex);
	}

	return ret;
}

int Letter::ASCIICount() const
{
	return diacritics.size() + symbols.size() + (int)is_arabic(this->character, true);
}

bool Letter::IsArabic(bool checkCharacter, bool checkDiacritic, bool checkSymbol, bool checkSpace)
{
	if (checkCharacter && (this->character == Arabic_old::Character::NONE || (!checkSpace && this->character == Arabic_old::Character::SPACE)))
		return false;
	if (checkDiacritic)
		for (auto& d : this->diacritics)
			if (!Arabic_old::is_diacritic(to_ascii(d)))
				return false;
	if (checkSymbol)
		for (auto& t : this->symbols)
			if (!is_symbol(to_ascii(t)))
				return false;

	return true;
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

Arabic_old::Letter& Word::operator [](int index)
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
	return Quran_old::to_string((Chapter::Name) this->attributes.chapterNum);
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
		if (!(w.LetterCount() == 1 && w.GetLetters()[0].GetCharacter() == Arabic_old::Character::WAW))
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

void Chapter::PopulateData(std::string quranPath)
{
	// depend on value in attribtues->chapterNum

	// confirm valid path to quran text file

}

Chapter::Chapter()
{
	this->textualPosition = TextualPosition();
	this->textualPosition.chapterNum = 0;
}
Chapter::Chapter(int chapterNum, std::string quranPath)
{
	this->textualPosition = TextualPosition();
	this->textualPosition.chapterNum = chapterNum;
	
	PopulateData(quranPath);
}
Chapter::Chapter(Name name, std::string quranPath) : Chapter((int) name, quranPath) {}
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
QuranTree::QuranTree(std::string quranPath)
{
	this->quranPath = quranPath;
}
QuranTree::~QuranTree()
{
	chapters.clear();
}

void QuranTree::PopulateData()
{
	for (unsigned int i = 0; i < NumChapters; i++)
		this->chapters.push_back(Chapter(i, this->quranPath));
}