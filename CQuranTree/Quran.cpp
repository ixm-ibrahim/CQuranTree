#include "Quran.h"

using namespace Quran;


///////////////////////////////////////////////////////////////////////////////
// Quran 
///////////////////////////////////////////////////////////////////////////////


bool Quran::is_enabled(int searchParameters, int param)
{
	return (searchParameters & param) == param;
}

int Quran::verse_num_by_chapter(int chapterNum)
{
	return VerseNumByChapter[chapterNum - 1];
}
int Quran::total_verse_num_by_chapter(int chapterNum)
{
	return TotalVerseNumByChapter[chapterNum-1];
}

int Quran::chapter_num_by_total_verse(int totalVerseNum)
{
	return Utilities::closest_value_upper<int>(TotalVerseNumByChapter, totalVerseNum) + 1;
}

bool Quran::is_letter(CQuranCharacter* character, bool checkSpace)
{
	return is_letter(character->GetCharacter(), checkSpace);
}
bool Quran::is_diacritic(CQuranCharacter* character)
{
	return is_diacritic(character->GetCharacter());
}
bool Quran::is_symbol(CQuranCharacter* character)
{
	return is_symbol(character->GetCharacter());
}

bool Quran::is_makkan(revelation_t r)
{
	return r == revelation_t::MAKKAN || r == revelation_t::LATE_MAKKAN;
}
bool Quran::is_makkan(CQuranNode* n)
{
	return is_makkan(n->GetAttributes().revelationPeriod);
}
bool Quran::is_madinan(revelation_t r)
{
	return r == revelation_t::MADINAN;
}
bool Quran::is_madinan(CQuranNode* n)
{
	return is_madinan(n->GetAttributes().revelationPeriod);
}

///////////////////////////////////////////////////////////////////////////////
// Attributes 
///////////////////////////////////////////////////////////////////////////////


Attributes::Attributes()
{
	this->textualPosition = TextualPosition();
	this->grammar = Grammar();
	this->revelationPeriod = RevelationPeriod::UNKNOWN;
	this->characterType = character_t::UNKNOWN;
	this->hasSymbol = false;
	this->isBasmallah = false;
	this->hasIndependentWaw = false;
	this->isHamzahBetweenLamAlif = false;
}
Attributes::Attributes(TextualPosition textualPosition, Grammar grammar, RevelationPeriod revelationPeriod, character_t characterType, bool hasSymbol, bool isBasmallah, bool hasIndependentWaw, bool isHamzahBetweenLamAlif)
{
	this->textualPosition = textualPosition;
	this->grammar = grammar;
	this->revelationPeriod = revelationPeriod;
	this->characterType = characterType;
	this->hasSymbol = hasSymbol;
	this->isBasmallah = isBasmallah;
	this->hasIndependentWaw = hasIndependentWaw;
	this->isHamzahBetweenLamAlif = isHamzahBetweenLamAlif;
}

void Attributes::copy(Attributes& to, Attributes from)
{
	TextualPosition::copy(to.textualPosition, from.textualPosition);
	Grammar::copy(to.grammar, from.grammar);
	to.revelationPeriod = from.revelationPeriod;
	to.characterType = from.characterType;
	to.hasSymbol = from.hasSymbol;
	to.isBasmallah = from.isBasmallah;
	to.hasIndependentWaw = from.hasIndependentWaw;
	to.isHamzahBetweenLamAlif = from.isHamzahBetweenLamAlif;
}

Attributes Attributes::operator =(const Attributes& rhs)
{
	copy(*this, rhs);
	return *this;
}


///////////////////////////////////////////////////////////////////////////////
// TextualPosition 
///////////////////////////////////////////////////////////////////////////////


Attributes::TextualPosition::TextualPosition()
{
	this->chapterNum = 0;
	this->verseNum = 0;
	this->verseNumInChapter = 0;
	this->wordNum = 0;
	this->wordNumInVerse = 0;
	this->wordNumInChapter = 0;
	this->letterNum = 0;
	this->letterNumInWord = 0;
	this->letterNumInVerse = 0;
	this->letterNumInChapter = 0;
	this->characterNum = 0;
	this->characterNumInLetter = 0;
	this->characterNumInWord = 0;
	this->characterNumInVerse = 0;
	this->characterNumInChapter = 0;
	this->pageNum = 0;
	this->stationNum = 0;
	this->partNum = 0;
	this->halfNum = 0;
	this->quarterNum = 0;
	this->bowingNum = 0;
	this->basmallahNum = 0;
	this->independentWawNum = 0;
	this->hamzahLetterNum = 0;
	this->hamzahBetweenAlifLamNum = 0;
}
Attributes::TextualPosition::TextualPosition(int chapterNum, int verseNum, int verseNumInChapter, int wordNum, int wordNumInVerse, int wordNumInChapter, int letterNum, int letterNumInWord, int letterNumInVerse, int letterNumInChapter, int characterNum, int characterNumInLetter, int characterNumInWord, int characterNumInVerse, int characterNumInChapter, int pageNum, int stationNum, int partNum, int halfNum, int quarterNum, int bowingNum, int basmallahNum, int independentWawNum, int hamzahLetterNum, int hamzahBetweenAlifLamNum)
{
	this->chapterNum = chapterNum;
	this->verseNum = verseNum;
	this->verseNumInChapter = verseNumInChapter;
	this->wordNum = wordNum;
	this->wordNumInVerse = wordNumInVerse;
	this->wordNumInChapter = wordNumInChapter;
	this->letterNum = letterNum;
	this->letterNumInWord = letterNumInWord;
	this->letterNumInVerse = letterNumInVerse;
	this->letterNumInChapter = letterNumInChapter;
	this->characterNum = characterNum;
	this->characterNumInLetter = characterNumInLetter;
	this->characterNumInWord = characterNumInWord;
	this->characterNumInVerse = characterNumInVerse;
	this->characterNumInChapter = characterNumInChapter;
	this->pageNum = pageNum;
	this->stationNum = stationNum;
	this->partNum = partNum;
	this->halfNum = halfNum;
	this->quarterNum = quarterNum;
	this->bowingNum = bowingNum;
	this->basmallahNum = basmallahNum;
	this->independentWawNum = independentWawNum;
	this->hamzahLetterNum = hamzahLetterNum;
	this->hamzahBetweenAlifLamNum = hamzahBetweenAlifLamNum;
}

void Attributes::TextualPosition::copy(TextualPosition& to, TextualPosition from)
{
	to.chapterNum = from.chapterNum;
	to.verseNum = from.verseNum;
	to.verseNumInChapter = from.verseNumInChapter;
	to.wordNum = from.wordNum;
	to.wordNumInVerse = from.wordNumInVerse;
	to.wordNumInChapter = from.wordNumInChapter;
	to.letterNum = from.letterNum;
	to.letterNumInWord = from.letterNumInWord;
	to.letterNumInVerse = from.letterNumInVerse;
	to.letterNumInChapter = from.letterNumInChapter;
	to.characterNum = from.characterNum;
	to.characterNumInLetter = from.characterNumInLetter;
	to.characterNumInWord = from.characterNumInWord;
	to.characterNumInVerse = from.characterNumInVerse;
	to.characterNumInChapter = from.characterNumInChapter;
	to.pageNum = from.pageNum;
	to.stationNum = from.stationNum;
	to.partNum = from.partNum;
	to.halfNum = from.halfNum;
	to.quarterNum = from.quarterNum;
	to.bowingNum = from.bowingNum;
	to.basmallahNum = from.basmallahNum;
	to.independentWawNum = from.independentWawNum;
	to.hamzahLetterNum = from.hamzahLetterNum;
	to.hamzahBetweenAlifLamNum = from.hamzahBetweenAlifLamNum;
}

Attributes::TextualPosition Attributes::TextualPosition::operator =(const TextualPosition& rhs)
{
	copy(*this, rhs);
	return *this;
}


///////////////////////////////////////////////////////////////////////////////
// Grammar 
///////////////////////////////////////////////////////////////////////////////


Attributes::Grammar::Grammar()
{
	this->root = std::vector<letter_t>(0);
	this->type = Type::NONE;
	this->tense = Tense::NONE;
	this->quantity = Quantity::NONE;
	this->gender = Gender::NONE;
	this->person = Person::NONE;
}
Attributes::Grammar::Grammar(std::vector<letter_t> root, Type type, Tense tense, Quantity quantity, Gender gender, Person person)
{
	this->root = root;
	this->type = type;
	this->tense = tense;
	this->quantity = quantity;
	this->gender = gender;
	this->person = person;
}

void Attributes::Grammar::copy(Grammar& to, Grammar from)
{
	to.root = from.root;
	to.type = from.type;
	to.tense = from.tense;
	to.quantity = from.quantity;
	to.gender = from.gender;
	to.person = from.person;
}

Attributes::Grammar  Attributes::Grammar::operator =(const Grammar& rhs)
{
	copy(*this, rhs);
	return *this;
}


///////////////////////////////////////////////////////////////////////////////
// CQuranNode 
///////////////////////////////////////////////////////////////////////////////


bool CQuranNode::copy_links_and_attributes(CQuranNode* newN, CQuranNode* oldN, bool deleteOldN)
{
	if (newN->type != oldN->type)
		return false;

	// copy attributes to new node
	newN->attributes = oldN->attributes;

	// copy references from old node to new node
	newN->nextCharacter = oldN->nextCharacter;
	newN->previousCharacter = oldN->previousCharacter;
	newN->nextWord = oldN->nextWord;
	newN->previousWord = oldN->previousWord;
	newN->nextVerse = oldN->nextVerse;
	newN->previousVerse = oldN->previousVerse;
	newN->nextChapter = oldN->nextChapter;
	newN->previousChapter = oldN->previousChapter;
	// the following will be updated as needed in the following section
	newN->currentCharacter = oldN->currentCharacter;
	newN->currentWord = oldN->currentWord;
	newN->currentVerse = oldN->currentVerse;
	newN->currentChapter = oldN->currentChapter;

	//	Chapter																Chapter
	//	Verse								Verse							  ...
	//	Word			Word				Word			Word			  ...
	//	Letter,Letter	Letter,Letter		Letter,Letter	Letter,Letter	  ...

	int charcterIndex = oldN->attributes.textualPosition.characterNumInWord;
	int wordIndex = oldN->attributes.textualPosition.wordNumInVerse;
	int verseIndex = oldN->attributes.textualPosition.verseNumInChapter;
	int chapterIndex = oldN->attributes.textualPosition.chapterNum;
	auto word = oldN->currentWord;
	auto verse = oldN->currentVerse;
	auto chapter = oldN->currentChapter;

	// update links in adjacent nodes
	switch (newN->type)
	{
		case node_t::CHARACTER:
		{
			newN->currentCharacter = dynamic_cast<CQuranCharacter*>(newN);
			word->word[charcterIndex] = newN->currentCharacter;

			if (charcterIndex == 1)
			{
				word->currentCharacter = newN->currentCharacter;
				word->nextCharacter = newN->currentCharacter;

				if (wordIndex == 1)
				{
					verse->currentCharacter = newN->currentCharacter;
					verse->nextCharacter = newN->currentCharacter;

					if (verseIndex == 1)
					{
						chapter->currentCharacter = newN->currentCharacter;
						chapter->nextCharacter = newN->currentCharacter;
					}
				}
			}
			else if (charcterIndex == word->word.size())
			{
				word->nextWord->previousCharacter = newN->currentCharacter;

				if (wordIndex == verse->verse.size())
				{
					verse->nextVerse->previousCharacter = newN->currentCharacter;

					if (verseIndex == chapter->chapter.size())
						chapter->nextVerse->previousCharacter = newN->currentCharacter;
				}
			}

			break;
		}
		case node_t::WORD:
		{
			newN->currentWord = dynamic_cast<CQuranWord*>(newN);
			newN->currentWord->translation = dynamic_cast<CQuranWord*>(oldN)->translation;
			verse->verse[wordIndex] = newN->currentWord;

			for (auto c : newN->nextWord->word)
				c->SetPreviousWord(newN->currentWord);
			for (auto c : newN->previousWord->word)
				c->SetNextWord(newN->currentWord);

			if (wordIndex == 1)
			{
				verse->currentWord = newN->currentWord;
				verse->nextWord = newN->currentWord;

				if (verseIndex == 1)
				{
					chapter->currentWord = newN->currentWord;
					chapter->nextWord = newN->currentWord;
				}
			}
			else if (wordIndex == verse->verse.size())
			{
				verse->nextVerse->previousWord = newN->currentWord;

				if (verseIndex == chapter->chapter.size())
					chapter->nextVerse->previousWord = newN->currentWord;
			}

			break;
		}
		case node_t::VERSE:
		{
			newN->currentVerse = dynamic_cast<CQuranVerse*>(newN);
			chapter->chapter[chapterIndex] = newN->currentVerse;

			for (auto w : newN->nextVerse->verse)
			{
				w->SetPreviousVerse(newN->currentVerse);

				for (auto c : w->word)
					c->SetPreviousVerse(newN->currentVerse);
			}
			for (auto w : newN->previousVerse->verse)
			{
				w->SetNextVerse(newN->currentVerse);

				for (auto c : w->word)
					c->SetNextVerse(newN->currentVerse);
			}

			if (verseIndex == 1)
			{
				chapter->currentVerse = newN->currentVerse;
				chapter->nextVerse = newN->currentVerse;
			}
			else if (verseIndex == chapter->chapter.size())
				chapter->nextChapter->previousVerse = newN->currentVerse;

			break;
		}
		case node_t::CHAPTER:
		{
			newN->currentChapter = dynamic_cast<CQuranChapter*>(newN);

			for (auto v : newN->nextChapter->chapter)
			{
				v->SetPreviousChapter(newN->currentChapter);

				for (auto w : v->verse)
				{
					w->SetPreviousChapter(newN->currentChapter);

					for (auto c : w->word)
						c->SetPreviousChapter(newN->currentChapter);
				}
			}
			for (auto v : newN->previousChapter->chapter)
			{
				v->SetNextChapter(newN->currentChapter);

				for (auto w : v->verse)
				{
					w->SetNextChapter(newN->currentChapter);

					for (auto c : w->word)
						c->SetNextChapter(newN->currentChapter);
				}
			}

			break;
		}
	}

	newN->nextCharacter->SetPreviousCharacter(newN->currentCharacter);
	newN->previousCharacter->SetNextCharacter(newN->currentCharacter);
	newN->nextWord->SetPreviousWord(newN->currentWord);
	newN->previousWord->SetNextWord(newN->currentWord);
	newN->nextVerse->SetPreviousVerse(newN->currentVerse);
	newN->previousVerse->SetNextVerse(newN->currentVerse);
	newN->nextChapter->SetPreviousChapter(newN->currentChapter);
	newN->previousChapter->SetNextChapter(newN->currentChapter);

	if (deleteOldN)
		delete oldN;

	return true;
}
void CQuranNode::reset_links(CQuranNode* node, bool deleteNode)
{
	if (deleteNode)
	{
		delete node->nextCharacter;
		delete node->currentCharacter;
		delete node->previousCharacter;
		delete node->nextWord;
		delete node->currentWord;
		delete node->previousWord;
		delete node->nextVerse;
		delete node->currentVerse;
		delete node->previousVerse;
		delete node->nextChapter;
		delete node->currentChapter;
		delete node->previousChapter;
	}

	node->nextCharacter = nullptr;
	node->currentCharacter = nullptr;
	node->previousCharacter = nullptr;
	node->nextWord = nullptr;
	node->currentWord = nullptr;
	node->previousWord = nullptr;
	node->nextVerse = nullptr;
	node->currentVerse = nullptr;
	node->previousVerse = nullptr;
	node->nextChapter = nullptr;
	node->currentChapter = nullptr;
	node->previousChapter = nullptr;
}

CQuranNode::Type CQuranNode::GetType()
{
	return this->type;
}

Attributes CQuranNode::GetAttributes()
{
	return this->attributes;
}
void CQuranNode::SetAttributes(Attributes attributes)
{
	this->attributes = attributes;
}

CQuranCharacter* CQuranNode::GetNextCharacter()
{
	return this->nextCharacter;
}
void CQuranNode::SetNextCharacter(CQuranCharacter* character, bool updateTree)
{
	if (updateTree)
		copy_links_and_attributes(character, this->nextCharacter, true);

	this->nextCharacter = character;
}
CQuranCharacter* CQuranNode::GetPreviousCharacter()
{
	return this->previousCharacter;
}
void CQuranNode::SetPreviousCharacter(CQuranCharacter* character, bool updateTree)
{
	if (updateTree)
		copy_links_and_attributes(character, this->previousCharacter, true);

	this->previousCharacter = character;
}
CQuranWord* CQuranNode::GetNextWord()
{
	return this->nextWord;
}
void CQuranNode::SetNextWord(CQuranWord* word, bool updateTree)
{
	if (updateTree)
		copy_links_and_attributes(word, this->nextWord, true);

	this->nextWord = word;
}
CQuranWord* CQuranNode::GetPreviousWord()
{
	return this->previousWord;
}
void CQuranNode::SetPreviousWord(CQuranWord* word, bool updateTree)
{
	if (updateTree)
		copy_links_and_attributes(word, this->previousWord, true);

	this->previousWord = word;
}
CQuranVerse* CQuranNode::GetNextVerse()
{
	return this->nextVerse;
}
void CQuranNode::SetNextVerse(CQuranVerse* verse, bool updateTree)
{
	if (updateTree)
		copy_links_and_attributes(verse, this->nextVerse, true);

	this->nextVerse = verse;
}
CQuranVerse* CQuranNode::GetPreviousVerse()
{
	return this->previousVerse;
}
void CQuranNode::SetPreviousVerse(CQuranVerse* verse, bool updateTree)
{
	if (updateTree)
		copy_links_and_attributes(verse, this->previousVerse, true);

	this->previousVerse = verse;
}
CQuranChapter* CQuranNode::GetNextChapter()
{
	return this->nextChapter;
}
void CQuranNode::SetNextChapter(CQuranChapter* chapter, bool updateTree)
{
	if (updateTree)
		copy_links_and_attributes(chapter, this->nextChapter, true);

	this->nextChapter = chapter;
}
CQuranChapter* CQuranNode::GetPreviousChapter()
{
	return this->previousChapter;
}
void CQuranNode::SetPreviousChapter(CQuranChapter* chapter, bool updateTree)
{
	if (updateTree)
		copy_links_and_attributes(chapter, this->previousChapter, true);

	this->previousChapter = chapter;
}

CQuranCharacter* CQuranNode::GetCurrentCharacter()
{
	return this->currentCharacter;
}
CQuranWord* CQuranNode::GetCurrentWord()
{
	return this->currentWord;
}
CQuranVerse* CQuranNode::GetCurrentVerse()
{
	return this->currentVerse;
}
CQuranChapter* CQuranNode::GetCurrentChapter()
{
	return this->currentChapter;
}

CQuranCharacter* CQuranNode::GetNextLetter(bool includeBasmallah, bool includeAlifKhanjariyah, bool includeHamzahBetweenLamAlif)
{
	auto current = this->currentCharacter;

	do
	{
		current = current->nextCharacter;

		if (Arabic::is_letter(current->GetCharacter()->GetASCII())
		 && (!includeBasmallah || current->GetAttributes().isBasmallah)
		 && (!includeAlifKhanjariyah || current->GetCharacter()->GetASCII() == Arabic::to_ascii(diacritic_t::ALIF_KHANJARIYAH)
		 && (!includeHamzahBetweenLamAlif || current->GetAttributes().isHamzahBetweenLamAlif)))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetPreviousLetter(bool includeBasmallah, bool includeAlifKhanjariyah, bool includeHamzahBetweenLamAlif)
{
	auto current = this->currentCharacter;

	do
	{
		current = current->previousCharacter;

		if (Arabic::is_letter(current->GetCharacter()->GetASCII())
		 && (!includeBasmallah || current->GetAttributes().isBasmallah)
		 && (!includeAlifKhanjariyah || current->GetCharacter()->GetASCII() == Arabic::to_ascii(diacritic_t::ALIF_KHANJARIYAH)
		 && (!includeHamzahBetweenLamAlif || current->GetAttributes().isHamzahBetweenLamAlif)))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetNextDiacritic(bool includeModifications, bool includeAlifKhanjariyah, bool includeHamzahBetweenLamAlif)
{
	auto current = this->currentCharacter;

	do
	{
		int ascii = current->GetCharacter()->GetASCII();
		current = current->nextCharacter;

		if (Arabic::is_diacritic(ascii)
		 && (!includeModifications || (Arabic::has_modification(ascii)
			 && ascii != Arabic::to_ascii(diacritic_t::ALIF_KHANJARIYAH)
			 && ascii != Arabic::to_ascii(diacritic_t::ALIF_MAQSURAH)
			 && ascii != Arabic::to_ascii(diacritic_t::MARBUTAH))
			)
		 && (!includeAlifKhanjariyah || ascii == Arabic::to_ascii(diacritic_t::ALIF_KHANJARIYAH)
		 && (!includeHamzahBetweenLamAlif || current->GetAttributes().isHamzahBetweenLamAlif)))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetPreviousDiacritic(bool includeModifications, bool includeAlifKhanjariyah, bool includeHamzahBetweenLamAlif)
{
	auto current = this->currentCharacter;

	do
	{
		int ascii = current->GetCharacter()->GetASCII();
		current = current->previousCharacter;

		if (Arabic::is_diacritic(ascii)
		 && (!includeModifications || (Arabic::has_modification(ascii)
			 && ascii != Arabic::to_ascii(diacritic_t::ALIF_KHANJARIYAH)
			 && ascii != Arabic::to_ascii(diacritic_t::ALIF_MAQSURAH)
			 && ascii != Arabic::to_ascii(diacritic_t::MARBUTAH))
			)
		 && (!includeAlifKhanjariyah || ascii == Arabic::to_ascii(diacritic_t::ALIF_KHANJARIYAH)
		 && (!includeHamzahBetweenLamAlif || current->GetAttributes().isHamzahBetweenLamAlif)))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetNextSymbol()
{
	auto current = this->currentCharacter;

	do
	{
		current = current->nextCharacter;

		if (Arabic::is_symbol(current->GetCharacter()))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetPreviousSymbol()
{
	auto current = this->currentCharacter;

	do
	{
		current = current->previousCharacter;

		if (Arabic::is_symbol(current->GetCharacter()))
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranWord* CQuranNode::GetNextWawWord()
{
	auto current = this->currentWord;

	do
	{
		current = current->nextWord;

		if (current->GetAttributes().hasIndependentWaw)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWawWord()
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (current->GetAttributes().hasIndependentWaw)
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranVerse* CQuranNode::GetNextBasmallah()
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		if (current->GetAttributes().isBasmallah)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousBasmallah()
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		if (current->GetAttributes().isBasmallah)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextPage()
{
	auto current = this->currentVerse;
	int page = this->attributes.textualPosition.pageNum;

	do
	{
		current = current->nextVerse;

		if (page != current->attributes.textualPosition.pageNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousPage()
{
	auto current = this->currentVerse;
	int page = this->attributes.textualPosition.pageNum;

	do
	{
		current = current->previousVerse;

		if (page != current->attributes.textualPosition.pageNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextStation()
{
	auto current = this->currentVerse;
	int station = this->attributes.textualPosition.stationNum;

	do
	{
		current = current->nextVerse;

		if (station != current->attributes.textualPosition.stationNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousStation()
{
	auto current = this->currentVerse;
	int station = this->attributes.textualPosition.stationNum;

	do
	{
		current = current->previousVerse;

		if (station != current->attributes.textualPosition.stationNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextPart()
{
	auto current = this->currentVerse;
	int part = this->attributes.textualPosition.partNum;

	do
	{
		current = current->nextVerse;

		if (part != current->attributes.textualPosition.partNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousPart()
{
	auto current = this->currentVerse;
	int part = this->attributes.textualPosition.partNum;

	do
	{
		current = current->previousVerse;

		if (part != current->attributes.textualPosition.partNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextHalf()
{
	auto current = this->currentVerse;
	int half = this->attributes.textualPosition.halfNum;

	do
	{
		current = current->nextVerse;

		if (half != current->attributes.textualPosition.halfNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousHalf()
{
	auto current = this->currentVerse;
	int half = this->attributes.textualPosition.halfNum;

	do
	{
		current = current->previousVerse;

		if (half != current->attributes.textualPosition.halfNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextQuarter()
{
	auto current = this->currentVerse;
	int quarter = this->attributes.textualPosition.quarterNum;

	do
	{
		current = current->nextVerse;

		if (quarter != current->attributes.textualPosition.quarterNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousQuarter()
{
	auto current = this->currentVerse;
	int quarter = this->attributes.textualPosition.quarterNum;

	do
	{
		current = current->previousVerse;

		if (quarter != current->attributes.textualPosition.quarterNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextBowing()
{
	auto current = this->currentVerse;
	int bowing = this->attributes.textualPosition.bowingNum;

	do
	{
		current = current->nextVerse;

		if (bowing != current->attributes.textualPosition.bowingNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousBowing()
{
	auto current = this->currentVerse;
	int bowing = this->attributes.textualPosition.bowingNum;

	do
	{
		current = current->previousVerse;

		if (bowing != current->attributes.textualPosition.bowingNum)
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranChapter* CQuranNode::GetNextMakkanChapter()
{
	auto current = this->currentChapter;

	do
	{
		current = current->nextChapter;

		if (is_makkan(current->attributes.revelationPeriod))
			return current;
	} while (current != nullptr);

	return nullptr;

}
CQuranChapter* CQuranNode::GetPreviousMakkanChapter()
{
	auto current = this->currentChapter;

	do
	{
		current = current->previousChapter;

		if (is_makkan(current->attributes.revelationPeriod))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranChapter* CQuranNode::GetNextMadinanChapter()
{
	auto current = this->currentChapter;

	do
	{
		current = current->nextChapter;

		if (is_madinan(current->attributes.revelationPeriod))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranChapter* CQuranNode::GetPreviousMadinanChapter()
{
	auto current = this->currentChapter;

	do
	{
		current = current->previousChapter;

		if (is_madinan(current->attributes.revelationPeriod))
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranCharacter* CQuranNode::GetNextCharacter(int ascii)
{
	auto current = this->currentCharacter;

	do
	{
		current = current->nextCharacter;

		if (current->GetCharacter()->GetASCII() == ascii)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetNextCharacter(Character* character)
{
	auto current = this->currentCharacter;

	do
	{
		current = current->nextCharacter;

		if (current->GetCharacter()->GetASCII() == character->GetASCII())
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetNextCharacter(CQuranCharacter* character)
{
	auto current = this->currentCharacter;

	do
	{
		current = current->nextCharacter;

		if (current->GetCharacter()->GetASCII() == character->GetCharacter()->GetASCII())
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetPreviousCharacter(int ascii)
{
	auto current = this->currentCharacter;

	do
	{
		current = current->previousCharacter;

		if (current->GetCharacter()->GetASCII() == ascii)
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetPreviousCharacter(Character* character)
{
	auto current = this->currentCharacter;

	do
	{
		current = current->previousCharacter;

		if (current->GetCharacter()->GetASCII() == character->GetASCII())
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranCharacter* CQuranNode::GetPreviousCharacter(CQuranCharacter* character)
{
	auto current = this->currentCharacter;

	do
	{
		current = current->previousCharacter;

		if (current->GetCharacter()->GetASCII() == character->GetCharacter()->GetASCII())
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranWord* CQuranNode::GetNextWord(std::vector<int> asciis, int searchParameters)
{
	auto current = this->currentWord;

	do
	{
		current = current->nextWord;

		if (CQuranTree::Equals(current, asciis, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetNextWord(std::vector<letter_t> letters)
{
	auto current = this->currentWord;

	do
	{
		current = current->nextWord;

		if (CQuranTree::Equals(current, letters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetNextWord(std::vector<Character*> characters, int searchParameters)
{
	auto current = this->currentWord;
	
	do
	{
		current = current->nextWord;

		if (CQuranTree::Equals(current, characters, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetNextWord(std::vector<CQuranCharacter*> characters, int searchParameters)
{
	auto current = this->currentWord;

	do
	{
		current = current->nextWord;

		if (CQuranTree::Equals(current, characters, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetNextWord(CQuranWord* word, int searchParameters)
{
	auto current = this->currentWord;

	do
	{
		current = current->nextWord;

		if (CQuranTree::Equals(current, word, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWord(std::vector<int> asciis, int searchParameters)
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (CQuranTree::Equals(current, asciis, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWord(std::vector<letter_t> letters)
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (CQuranTree::Equals(current, letters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWord(std::vector<Character*> characters, int searchParameters)
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (CQuranTree::Equals(current, characters, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWord(std::vector<CQuranCharacter*> characters, int searchParameters)
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (CQuranTree::Equals(current, characters, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWord(CQuranWord* word, int searchParameters)
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (CQuranTree::Equals(current, word, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranWord* CQuranNode::GetNextWordWithRoot(std::vector<int> asciis)
{
	auto current = this->currentWord;

	do
	{
		current = current->nextWord;

		if (CQuranTree::Equals(current->attributes.grammar.root, asciis))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetNextWordWithRoot(std::vector<letter_t> root)
{
	auto current = this->currentWord;

	do
	{
		current = current->nextWord;

		if (CQuranTree::Equals(current->attributes.grammar.root, root))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetNextWordWithRoot(CQuranWord* word)
{
	auto current = this->currentWord;

	do
	{
		current = current->nextWord;

		if (CQuranTree::Equals(current->attributes.grammar.root, word->attributes.grammar.root))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWordWithRoot(std::vector<int> asciis)
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (CQuranTree::Equals(current->attributes.grammar.root, asciis))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWordWithRoot(std::vector<letter_t> root)
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (CQuranTree::Equals(current->attributes.grammar.root, root))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranWord* CQuranNode::GetPreviousWordWithRoot(CQuranWord* word)
{
	auto current = this->currentWord;

	do
	{
		current = current->previousWord;

		if (CQuranTree::Equals(current->attributes.grammar.root, word->attributes.grammar.root))
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranVerse* CQuranNode::GetNextVerse(CQuranVerse* verse)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		if (CQuranTree::Equals(current, verse))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerse(CQuranVerse* verse)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		if (CQuranTree::Equals(current, verse))
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranVerse* CQuranNode::GetNextVerseWithRoot(std::vector<int> asciis)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		for (auto wp : current->verse)
			if (CQuranTree::Equals(wp->attributes.grammar.root, asciis))
				return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithRoot(std::vector<letter_t> root)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		for (auto wp : current->verse)
			if (CQuranTree::Equals(wp->attributes.grammar.root, root))
				return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithRoot(CQuranWord* word)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		for (auto wp : current->verse)
			if (CQuranTree::Equals(wp->attributes.grammar.root, word->attributes.grammar.root))
				return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithRoot(std::vector<int> asciis)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		for (auto wp : current->verse)
			if (CQuranTree::Equals(wp->attributes.grammar.root, asciis))
				return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithRoot(std::vector<letter_t> root)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		for (auto wp : current->verse)
			if (CQuranTree::Equals(wp->attributes.grammar.root, root))
				return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithRoot(CQuranWord* word)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		for (auto wp : current->verse)
			if (CQuranTree::Equals(wp->attributes.grammar.root, word->attributes.grammar.root))
				return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranVerse* CQuranNode::GetNextVerseWithWord(std::vector<int> asciis, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		if (CQuranTree::Contains(current, asciis, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithWord(std::vector<letter_t> letters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		if (CQuranTree::Contains(current, letters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithWord(std::vector<Character*> characters, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		if (CQuranTree::Contains(current, characters, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithWord(CQuranWord* word, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		if (CQuranTree::Contains(current, word, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithWord(std::vector<int> asciis, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		if (CQuranTree::Contains(current, asciis, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithWord(std::vector<letter_t> letters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		if (CQuranTree::Contains(current, letters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithWord(std::vector<Character*> characters, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		if (CQuranTree::Contains(current, characters, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithWord(CQuranWord* word, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		if (CQuranTree::Contains(current, word, searchParameters))
			return current;
	} while (current != nullptr);

	return nullptr;
}

CQuranVerse* CQuranNode::GetNextVerseWithPhrase(std::vector<int> asciis, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		auto testC = current->currentCharacter;
		auto nextStart = testC->GetNextCharacter();
		int index = 0;

		while (testC != nullptr && testC->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (is_symbol(testC->GetCharacter()) || (is_diacritic(testC->GetCharacter()) && !searchParameters))
			{
				testC = testC->GetNextCharacter();
				continue;
			}

			if (testC->GetCharacter()->GetASCII() == asciis[index++])
				testC = testC->GetNextCharacter();
			else
			{
				index = 0;
				testC = nextStart;
				nextStart = testC->GetNextCharacter();
			}

			if (index >= asciis.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithPhrase(std::vector<letter_t> phrase)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		auto testC = current->currentCharacter;
		auto nextStart = testC->GetNextCharacter();
		int index = 0;

		while (testC != nullptr && testC->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (is_symbol(testC->GetCharacter()) || is_diacritic(testC->GetCharacter()))
			{
				testC = testC->GetNextCharacter();
				continue;
			}

			if (testC->GetCharacter()->GetASCII() == to_ascii(phrase[index++]))
				testC = testC->GetNextCharacter();
			else
			{
				index = 0;
				testC = nextStart;
				nextStart = testC->GetNextCharacter();
			}

			if (index >= phrase.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithPhrase(std::vector<Character*> phrase, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		auto testC = current->currentCharacter;
		auto nextStart = testC->GetNextCharacter();
		int index = 0;

		while (testC != nullptr && testC->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (is_symbol(testC->GetCharacter()) || (is_diacritic(testC->GetCharacter()) && !searchParameters))
			{
				testC = testC->GetNextCharacter();
				continue;
			}

			if (testC->GetCharacter()->GetASCII() == phrase[index++]->GetASCII())
				testC = testC->GetNextCharacter();
			else
			{
				index = 0;
				testC = nextStart;
				nextStart = testC->GetNextCharacter();
			}

			if (index >= phrase.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithPhrase(std::vector<CQuranCharacter*> phrase, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		auto testC = current->currentCharacter;
		auto nextStart = testC->GetNextCharacter();
		int index = 0;

		while (testC != nullptr && testC->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (is_symbol(testC->GetCharacter()) || (is_diacritic(testC->GetCharacter()) && !searchParameters))
			{
				testC = testC->GetNextCharacter();
				continue;
			}

			if (testC->GetCharacter()->GetASCII() == phrase[index++]->GetCharacter()->GetASCII())
				testC = testC->GetNextCharacter();
			else
			{
				index = 0;
				testC = nextStart;
				nextStart = testC->GetNextCharacter();
			}

			if (index >= phrase.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetNextVerseWithPhrase(std::vector<CQuranWord*> phrase, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->nextVerse;

		auto testW = current->currentWord;
		auto nextStart = testW->GetNextWord();
		int index = 0;

		while (testW != nullptr && testW->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (CQuranTree::Equals(testW, phrase[index++]))
				testW = testW->GetNextWord();
			else
			{
				index = 0;
				testW = nextStart;
				nextStart = testW->GetNextWord();
			}

			if (index >= phrase.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithPhrase(std::vector<int> asciis, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		auto testC = current->currentCharacter;
		auto nextStart = testC->GetNextCharacter();
		int index = 0;

		while (testC != nullptr && testC->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (is_symbol(testC->GetCharacter()) || (is_diacritic(testC->GetCharacter()) && !searchParameters))
			{
				testC = testC->GetNextCharacter();
				continue;
			}

			if (testC->GetCharacter()->GetASCII() == asciis[index++])
				testC = testC->GetNextCharacter();
			else
			{
				index = 0;
				testC = nextStart;
				nextStart = testC->GetNextCharacter();
			}

			if (index >= asciis.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithPhrase(std::vector<letter_t> phrase)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		auto testC = current->currentCharacter;
		auto nextStart = testC->GetNextCharacter();
		int index = 0;

		while (testC != nullptr && testC->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (is_symbol(testC->GetCharacter()) || is_diacritic(testC->GetCharacter()))
			{
				testC = testC->GetNextCharacter();
				continue;
			}

			if (testC->GetCharacter()->GetASCII() == to_ascii(phrase[index++]))
				testC = testC->GetNextCharacter();
			else
			{
				index = 0;
				testC = nextStart;
				nextStart = testC->GetNextCharacter();
			}

			if (index >= phrase.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithPhrase(std::vector<Character*> phrase, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		auto testC = current->currentCharacter;
		auto nextStart = testC->GetNextCharacter();
		int index = 0;

		while (testC != nullptr && testC->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (is_symbol(testC->GetCharacter()) || (is_diacritic(testC->GetCharacter()) && !searchParameters))
			{
				testC = testC->GetNextCharacter();
				continue;
			}

			if (testC->GetCharacter()->GetASCII() == phrase[index++]->GetASCII())
				testC = testC->GetNextCharacter();
			else
			{
				index = 0;
				testC = nextStart;
				nextStart = testC->GetNextCharacter();
			}

			if (index >= phrase.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithPhrase(std::vector<CQuranCharacter*> phrase, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		auto testC = current->currentCharacter;
		auto nextStart = testC->GetNextCharacter();
		int index = 0;

		while (testC != nullptr && testC->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (is_symbol(testC->GetCharacter()) || (is_diacritic(testC->GetCharacter()) && !searchParameters))
			{
				testC = testC->GetNextCharacter();
				continue;
			}

			if (testC->GetCharacter()->GetASCII() == phrase[index++]->GetCharacter()->GetASCII())
				testC = testC->GetNextCharacter();
			else
			{
				index = 0;
				testC = nextStart;
				nextStart = testC->GetNextCharacter();
			}

			if (index >= phrase.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}
CQuranVerse* CQuranNode::GetPreviousVerseWithPhrase(std::vector<CQuranWord*> phrase, int searchParameters)
{
	auto current = this->currentVerse;

	do
	{
		current = current->previousVerse;

		auto testW = current->currentWord;
		auto nextStart = testW->GetNextWord();
		int index = 0;

		while (testW != nullptr && testW->GetAttributes().textualPosition.verseNum == current->attributes.textualPosition.verseNum)
		{
			if (CQuranTree::Equals(testW, phrase[index++]))
				testW = testW->GetNextWord();
			else
			{
				index = 0;
				testW = nextStart;
				nextStart = testW->GetNextWord();
			}

			if (index >= phrase.size())
				return current;
		};
	} while (current != nullptr);

	return nullptr;
}


///////////////////////////////////////////////////////////////////////////////
// CQuranCharacter 
///////////////////////////////////////////////////////////////////////////////


CQuranCharacter::CQuranCharacter()
{
	this->type = node_t::CHARACTER;
	this->attributes = Attributes();
	this->character = nullptr;
}
CQuranCharacter::CQuranCharacter(Character* c) : CQuranCharacter()
{
	this->character = c;
}
CQuranCharacter::CQuranCharacter(Character* c, Attributes a) : CQuranCharacter(c)
{
	this->attributes = a;
}
CQuranCharacter::~CQuranCharacter()
{
	delete this->character;
}

Character* CQuranCharacter::GetCharacter()
{
	return this->character;
}
int CQuranCharacter::GetASCII()
{
	return this->character->GetASCII();
}

std::string CQuranCharacter::ToString()
{
	return to_string(this->character);
}
std::string CQuranCharacter::GetTranslation()
{
	return "";
}
std::string CQuranCharacter::SoundOf(bool includeDiacritics)
{
	return sound_of(this->character, includeDiacritics);
}


///////////////////////////////////////////////////////////////////////////////
// CQuranWord 
///////////////////////////////////////////////////////////////////////////////


CQuranWord::CQuranWord()
{
	this->type = node_t::WORD;
	this->attributes = Attributes();
	this->word = std::vector<CQuranCharacter*>();
	this->translation = "";
}
CQuranWord::CQuranWord(std::vector<CQuranCharacter*> characters, std::string translation) : CQuranWord()
{
	this->word = characters;
	this->translation = translation;
}
CQuranWord::CQuranWord(std::vector<CQuranCharacter*> characters, Attributes attributes, std::string translation) : CQuranWord(characters, translation)
{
	this->attributes = attributes;
}
CQuranWord::~CQuranWord()
{
	for (auto cp : this->word)
		delete cp;

	this->word.clear();
}

std::vector<CQuranCharacter*> CQuranWord::GetWord()
{
	return this->word;
}
CQuranCharacter* CQuranWord::GetCharacter(int characterNum)
{
	return this->word[characterNum-1];
}
std::vector<int> CQuranWord::GetASCII()
{
	std::vector<int> asciis(this->word.size());
	
	for (size_t i = 0; i < this->word.size(); i++)
		asciis.push_back(this->word[i]->GetASCII());

	return asciis;
}

int CQuranWord::Count()
{
	return this->word.size();
}

std::string CQuranWord::ToString()
{
	std::string str = this->word[0]->ToString();

	for (size_t i = 1; i < this->word.size(); i++)
		str += "/" + this->word[i]->ToString();

	return str;
}
std::string CQuranWord::GetTranslation()
{
	return translation;
}
std::string CQuranWord::SoundOf(bool includeDiacritics)
{
	std::string str = "";

	for (size_t i = 0; i < this->word.size(); i++)
		str += this->word[i]->SoundOf(includeDiacritics);

	return str;
}

CQuranCharacter* CQuranWord::operator[](size_t index)
{
	return this->word[index];
}


///////////////////////////////////////////////////////////////////////////////
// CQuranVerse 
///////////////////////////////////////////////////////////////////////////////


CQuranVerse::CQuranVerse()
{
	this->type = node_t::VERSE;
	this->attributes = Attributes();
	this->verse = std::vector<CQuranWord*>();
}
CQuranVerse::CQuranVerse(std::vector<CQuranWord*> verse) : CQuranVerse()
{
	this->verse = verse;
}
CQuranVerse::CQuranVerse(std::vector<CQuranWord*> verse, Attributes attributes) : CQuranVerse(verse)
{
	this->attributes = attributes;
}
CQuranVerse::~CQuranVerse()
{
	for (auto wp : this->verse)
		delete wp;

	this->verse.clear();
}

std::vector<CQuranWord*> CQuranVerse::GetVerse()
{
	return this->verse;
}
CQuranWord* CQuranVerse::GetWord(int wordNum)
{
	return this->verse[wordNum-1];
}
CQuranCharacter* CQuranVerse::GetCharacter(int wordNum, int characterNum)
{
	return this->verse[wordNum-1]->GetCharacter(characterNum);
}

int CQuranVerse::Count()
{
	return this->verse.size();
}

std::string CQuranVerse::ToString()
{
	std::string str = this->verse[0]->ToString();

	for (size_t i = 1; i < this->verse.size(); i++)
		str += "  " + this->verse[i]->ToString();

	return str;
}
std::string CQuranVerse::GetTranslation()
{
	std::string str = this->verse[0]->ToString();

	for (size_t i = 1; i < this->verse.size(); i++)
		str += " " + this->verse[i]->GetTranslation();

	return str;
}
std::string CQuranVerse::SoundOf(bool includeDiacritics)
{
	std::string str = this->verse[0]->ToString();

	for (size_t i = 1; i < this->verse.size(); i++)
		str += " " + this->verse[i]->SoundOf(includeDiacritics);

	return str;
}

CQuranWord* CQuranVerse::operator[](size_t index)
{
	return this->verse[index];
}


///////////////////////////////////////////////////////////////////////////////
// CQuranChapter 
///////////////////////////////////////////////////////////////////////////////


CQuranChapter::CQuranChapter()
{
	this->type = node_t::CHAPTER;
	this->attributes = Attributes();
	this->chapter = std::vector<CQuranVerse*>();
}
CQuranChapter::CQuranChapter(std::vector<CQuranVerse*> chapter) : CQuranChapter()
{
	this->chapter = chapter;
}
CQuranChapter::CQuranChapter(std::vector<CQuranVerse*> chapter, Attributes attributes) : CQuranChapter(chapter)
{
	this->attributes = attributes;
}
CQuranChapter::~CQuranChapter()
{
	for (auto vp : this->chapter)
		delete vp;

	this->chapter.clear();
}

std::vector<CQuranVerse*> CQuranChapter::GetChapter()
{
	return this->chapter;
}
CQuranVerse* CQuranChapter::GetVerse(int verseNum)
{
	return this->chapter[verseNum-1];
}
CQuranWord* CQuranChapter::GetWord(int verseNum, int wordNum)
{
	return this->chapter[verseNum-1]->GetWord(wordNum);
}
CQuranCharacter* CQuranChapter::GetCharacter(int verseNum, int wordNum, int characterNum)
{
	return this->chapter[verseNum-1]->GetWord(wordNum)->GetCharacter(characterNum);
}

int CQuranChapter::Count()
{
	return this->chapter.size();
}

std::string CQuranChapter::ToString()
{
	std::string str = this->chapter[0]->ToString();

	for (size_t i = 1; i < this->chapter.size(); i++)
		str += "\n" + this->chapter[i]->ToString();

	return str;
}
std::string CQuranChapter::GetTranslation()
{
	std::string str = this->chapter[0]->ToString();

	for (size_t i = 1; i < this->chapter.size(); i++)
		str += "\n" + this->chapter[i]->GetTranslation();

	return str;
}
std::string CQuranChapter::SoundOf(bool includeDiacritics)
{
	std::string str = this->chapter[0]->ToString();

	for (size_t i = 1; i < this->chapter.size(); i++)
		str += "\n" + this->chapter[i]->SoundOf(includeDiacritics);

	return str;
}

CQuranVerse* CQuranChapter::operator[](size_t index)
{
	return this->chapter[index];
}


///////////////////////////////////////////////////////////////////////////////
// CQuranTree 
///////////////////////////////////////////////////////////////////////////////


void CQuranTree::PopulateData()
{

}
void CQuranTree::DeleteData()
{

}

CQuranTree::CQuranTree()
{
	PopulateData();
}
CQuranTree::~CQuranTree()
{
	DeleteData();
}

std::vector<CQuranChapter*> CQuranTree::GetQuran()
{
	return this->chapters;
}

CQuranNode* CQuranTree::Get(int chapterNum, int verseNum, int wordNum, int characterNum)
{
	return this->chapters[chapterNum-1]->GetVerse(verseNum)->GetWord(wordNum)->GetCharacter(characterNum);
}
CQuranNode* CQuranTree::Get(int chapterNum, int verseNum, int wordNum)
{
	return this->chapters[chapterNum-1]->GetVerse(verseNum)->GetWord(wordNum);
}
CQuranNode* CQuranTree::Get(int chapterNum, int verseNum)
{
	return this->chapters[chapterNum-1]->GetVerse(verseNum);
}
CQuranNode* CQuranTree::Get(int chapterNum)
{
	return this->chapters[chapterNum-1];
}

CQuranCharacter* CQuranTree::GetCharacter(int chapterNum, int verseNum, int wordNum, int characterNum)
{
	if (verseNum == 0)
		verseNum = 1;

	return this->chapters[chapterNum-1]->GetWord(verseNum, wordNum)->GetCharacter(characterNum);
}
CQuranCharacter* CQuranTree::GetLetter(int chapterNum, int verseNum, int wordNum, int letterNum)
{
	if (verseNum == 0)
		verseNum = 1;

	size_t count = 0;
	CQuranWord* w = this->chapters[chapterNum-1]->GetWord(verseNum, wordNum);

	for (size_t i = 0; i < w->Count(); i++)
	{
		if (is_letter(w->GetCharacter(i)))
			count++;

		if (count == letterNum)
			return w->GetCharacter(i);
	}

	return nullptr;
}
CQuranCharacter* CQuranTree::GetDiacritic(int chapterNum, int verseNum, int wordNum, int diacriticNum)
{
	if (verseNum == 0)
		verseNum = 1;

	size_t count = 0;
	CQuranWord* w = this->chapters[chapterNum-1]->GetWord(verseNum, wordNum);

	for (size_t i = 0; i < w->Count(); i++)
	{
		if (is_diacritic(w->GetCharacter(i)))
			count++;

		if (count == diacriticNum)
			return w->GetCharacter(i);
	}

	return nullptr;
}
CQuranCharacter* CQuranTree::GetSymbol(int chapterNum, int verseNum, int wordNum, int symbolNum)
{
	if (verseNum == 0)
		verseNum = 1;

	size_t count = 0;
	CQuranWord* w = this->chapters[chapterNum-1]->GetWord(verseNum, wordNum);

	for (size_t i = 0; i < w->Count(); i++)
	{
		if (is_symbol(w->GetCharacter(i)))
			count++;

		if (count == symbolNum)
			return w->GetCharacter(i);
	}

	return nullptr;
}
CQuranWord* CQuranTree::GetWord(int chapterNum, int verseNum, int wordNum)
{
	if (verseNum == 0)
		verseNum = 1;

	return this->GetChapter(chapterNum)->GetVerse(verseNum)->GetWord(wordNum);
}
CQuranVerse* CQuranTree::GetVerse(int totalVerseNum)
{
	if (totalVerseNum == 0)
		return this->GetChapter(1)->GetVerse(1);

	int chapterNum = chapter_num_by_total_verse(totalVerseNum);
	int remainder = totalVerseNum - total_verse_num_by_chapter(chapterNum);

	return this->chapters[chapterNum-1]->GetVerse(remainder);
}
CQuranVerse* CQuranTree::GetVerse(int chapterNum, int verseNum)
{
	if (verseNum == 0)
		verseNum = 1;

	return this->chapters[chapterNum-1]->GetVerse(verseNum);
}
CQuranChapter* CQuranTree::GetChapter(int chapterNum)
{
	return this->chapters[chapterNum-1];
}

CQuranCharacter* CQuranTree::GetSymbolAt(int)
{
	return nullptr;
}
CQuranCharacter* CQuranTree::GetDiacriticAt(int)
{
	return nullptr;
}
CQuranCharacter* CQuranTree::GetLetterAt(int textualPosition)
{
	return nullptr;
}
CQuranCharacter* CQuranTree::GetCharacterAt(int)
{
	return nullptr;
}
CQuranWord* CQuranTree::GetWordAt(int, bool)
{
	return nullptr;
}
CQuranVerse* CQuranTree::GetVerseAt(int verseNum)
{
	int startChapter = verseNum % NumChapters;
	int startVerse = verse_num_by_chapter(startChapter);

	CQuranVerse* current = this->GetVerse(startChapter, startVerse);

	while (current != nullptr)
	{
		int verseN = current->GetAttributes().textualPosition.verseNum;
		int verseBasmallahN = verseN + current->GetAttributes().textualPosition.basmallahNum;

		if (is_enabled(searchParameters, INCLUDE_BASMALLAH) && verseNum == verseBasmallahN
			|| verseNum == verseNum)
			return current;

		current->GetNextVerse();
	}

	return nullptr;
}
CQuranChapter* CQuranTree::GetChapterAt(int chapterNum)
{
	return this->chapters[chapterNum];
}

CQuranVerse* CQuranTree::GetBasmallahAt(int basmallahNum)
{
	if (basmallahNum >= 1 && basmallahNum <= 8)
		return this->GetVerse(basmallahNum, 0);
	if (basmallahNum >= 9 && basmallahNum <= 26)
		return this->GetVerse(basmallahNum + 1, 0);
	if (basmallahNum == 27)
		return this->GetVerse(27, 30);
	if (basmallahNum >= 28 && basmallahNum <= 114)
		return this->GetVerse(basmallahNum, 0);

	return nullptr;
}
CQuranChapter* CQuranTree::GetMakkanChapterAt(int makkanChapterNum)
{
	size_t count = 0;

	for (size_t i = 0; i < 114; i++)
	{
		if (is_makkan(this->chapters[i]))
			count++;

		if (count == makkanChapterNum)
			return this->chapters[i];
	}

	return nullptr;
}
CQuranChapter* CQuranTree::GetMadinanChapterAt(int madinanChapterNum)
{
	size_t count = 0;

	for (size_t i = 0; i < 114; i++)
	{
		if (is_madinan(this->chapters[i]))
			count++;

		if (count == madinanChapterNum)
			return this->chapters[i];
	}

	return nullptr;
}

// ex.with word, display counts of each grammatical category
int CQuranTree::LetterCount(int)
{
	return 0;
}
int CQuranTree::LetterCount(letter_t)
{
	return 0;
}
int CQuranTree::DiacriticCount(int)
{
	return 0;
}
int CQuranTree::DiacriticCount(diacritic_t)
{
	return 0;
}
int CQuranTree::SymbolCount(int)
{
	return 0;
}
int CQuranTree::SymbolCount(symbol_t)
{
	return 0;
}
int CQuranTree::CharacterCount(int)
{
	return 0;
}
int CQuranTree::CharacterCount(Character*)
{
	return 0;
}
int CQuranTree::CharacterCount(CQuranCharacter*)
{
	return 0;
}

int CQuranTree::WordCount(std::vector<letter_t>)
{
	return 0;
}
int CQuranTree::WordCount(std::vector<Character*>)
{
	return 0;
}
int CQuranTree::WordCount(CQuranWord*)
{
	return 0;
}

int CQuranTree::VerseCount(std::vector<std::vector<letter_t>>)
{
	return 0;
}
int CQuranTree::VerseCount(std::vector<std::vector<Character*>>)
{
	return 0;
}
int CQuranTree::VerseCount(CQuranVerse*)
{
	return 0;
}
int CQuranTree::PhraseCount(std::vector<std::vector<letter_t>>)
{
	return 0;
}
int CQuranTree::PhraseCount(std::vector<std::vector<Character*>>)
{
	return 0;
}
int CQuranTree::PhraseCount(CQuranVerse*)
{
	return 0;
}


std::vector<CQuranCharacter*> CQuranTree::OccurancesOfLetter(int)
{
	return std::vector<CQuranCharacter*>();
}
std::vector<CQuranCharacter*> CQuranTree::OccurancesOfLetter(letter_t)
{
	return std::vector<CQuranCharacter*>();
}
std::vector<CQuranCharacter*> CQuranTree::OccurancesOfDiacritic(int)
{
	return std::vector<CQuranCharacter*>();
}
std::vector<CQuranCharacter*> CQuranTree::OccurancesOfDiacritic(diacritic_t)
{
	return std::vector<CQuranCharacter*>();
}
std::vector<CQuranCharacter*> CQuranTree::OccurancesOfSymbol(int)
{
	return std::vector<CQuranCharacter*>();
}
std::vector<CQuranCharacter*> CQuranTree::OccurancesOfSymbol(symbol_t)
{
	return std::vector<CQuranCharacter*>();
}
std::vector<CQuranCharacter*> CQuranTree::OccurancesOfCharacter(int)
{
	return std::vector<CQuranCharacter*>();
}
std::vector<CQuranCharacter*> CQuranTree::OccurancesOfCharacter(Character*)
{
	return std::vector<CQuranCharacter*>();
}
std::vector<CQuranCharacter*> CQuranTree::OccurancesOfCharacter(CQuranCharacter*)
{
	return std::vector<CQuranCharacter*>();
}

std::vector<CQuranWord*> CQuranTree::OccurancesOfWord(std::vector<letter_t>)
{
	return std::vector<CQuranWord*>();
}
std::vector<CQuranWord*> CQuranTree::OccurancesOfWord(std::vector<Character>)
{
	return std::vector<CQuranWord*>();
}
std::vector<CQuranWord*> CQuranTree::OccurancesOfWord(CQuranWord*)
{
	return std::vector<CQuranWord*>();
}

std::vector<CQuranVerse*> CQuranTree::OccurancesOfVerse(std::vector<std::vector<letter_t>>)
{
	return std::vector<CQuranVerse*>();
}
std::vector<CQuranVerse*> CQuranTree::OccurancesOfVerse(std::vector<std::vector<Character>>)
{
	return std::vector<CQuranVerse*>();
}
std::vector<CQuranVerse*> CQuranTree::OccurancesOfVerse(CQuranVerse*)
{
	return std::vector<CQuranVerse*>();
}
std::vector<CQuranVerse*> CQuranTree::OccurancesOfPhrase(std::vector<std::vector<letter_t>>)
{
	return std::vector<CQuranVerse*>();
}
std::vector<CQuranVerse*> CQuranTree::OccurancesOfPhrase(std::vector<std::vector<Character>>)
{
	return std::vector<CQuranVerse*>();
}
std::vector<CQuranVerse*> CQuranTree::OccurancesOfPhrase(CQuranVerse*)
{
	return std::vector<CQuranVerse*>();
}


int CQuranTree::DistanceBetween(CQuranCharacter*)
{
	return 0;
}
int CQuranTree::DistanceBetween(CQuranWord*)
{
	return 0;
}
int CQuranTree::DistanceBetween(CQuranVerse*)
{
	return 0;
}

int CQuranTree::DistanceBetween(CQuranCharacter*, CQuranCharacter*)
{
	return 0;
}
int CQuranTree::DistanceBetween(CQuranCharacter*, CQuranWord*)
{
	return 0;
}
int CQuranTree::DistanceBetween(CQuranCharacter*, CQuranVerse*)
{
	return 0;
}

int CQuranTree::DistanceBetween(CQuranWord*, CQuranCharacter*)
{
	return 0;
}
int CQuranTree::DistanceBetween(CQuranWord*, CQuranWord*)
{
	return 0;
}
int CQuranTree::DistanceBetween(CQuranWord*, CQuranVerse*)
{
	return 0;
}

int CQuranTree::DistanceBetween(CQuranVerse*, CQuranCharacter*)
{
	return 0;
}
int CQuranTree::DistanceBetween(CQuranVerse*, CQuranWord*)
{
	return 0;
}
int CQuranTree::DistanceBetween(CQuranVerse*, CQuranVerse*)
{
	return 0;
}

int CQuranTree::DistanceBetween(CQuranChapter*, CQuranChapter*)
{
	return 0;
}


/*
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

*/