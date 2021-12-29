// CQuranTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <locale.h>
#include <windows.h>
#include "Quran.h"

using namespace Arabic_old;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //std::setlocale(LC_ALL, "ar_SA.UTF-8");

    std::wcout << "Hello arabic: بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ\n";

    //std::cout << abjad_value(Character::GHAYN) << std::endl << to_ascii("0x1b36") << std::endl
    //          << sound_of(Letter(Character::TA, Diacritic::MARBUTAH, std::vector<Diacritic> {Diacritic::TANWEEN_FATHAH}))
    //          << sound_of(Letter(Character::TA, Diacritic::MARBUTAH));

    std::vector<Letter> ibrahim
    {
        Letter(Character::ALIF, Diacritic::HAMZAH_BELOW, std::vector<Diacritic> {Diacritic::KASRAH}),
        Letter(Character::BA, std::vector<Diacritic> {Diacritic::SUKOON}),
        Letter(Character::RA, std::vector<Diacritic> {Diacritic::FATHAH}),
        Letter(Character::ALIF),
        Letter(Character::HA, std::vector<Diacritic> {Diacritic::KASRAH}),
        Letter(Character::YA, Position::MIDDLE),
        Letter(Character::MEEM, std::vector<Diacritic> {Diacritic::SUKOON}),
    };
    std::vector<Letter> bsm
    {
        Letter(Character::BA, std::vector<Diacritic> {Diacritic::KASRAH}),
        Letter(Character::SEEN, std::vector<Diacritic> {Diacritic::SUKOON}),
        Letter(Character::MEEM, std::vector<Diacritic> {Diacritic::KASRAH}),
        Letter(Character::SPACE),
        Letter(Character::ALIF, std::vector<Diacritic> {Diacritic::FATHAH}),
        Letter(Character::LAM, std::vector<Diacritic> {Diacritic::SUKOON}),
        Letter(Character::LAM, std::vector<Diacritic> {Diacritic::SHADDAH,Diacritic::FATHAH}),
        Letter(Character::HA, Diacritic::MARBUTAH, std::vector<Diacritic> {Diacritic::KASRAH}),
        Letter(Character::SPACE),
        Letter(Character::ALIF, Diacritic::ALIF_WASLAH),
        Letter(Character::LAM),
        Letter(Character::RA, std::vector<Diacritic> {Diacritic::SHADDAH,Diacritic::FATHAH}),
        Letter(Character::HHA, std::vector<Diacritic> {Diacritic::SUKOON}),
        Letter(Character::MEEM, std::vector<Diacritic> {Diacritic::FATHAH}),
        Letter(Character::NONE, std::vector<Diacritic> {Diacritic::ALIF_KHANJARIYAH}),
        Letter(Character::NOON, std::vector<Diacritic> {Diacritic::KASRAH}),
        Letter(Character::SPACE),
        Letter(Character::ALIF, Diacritic::ALIF_WASLAH),
        Letter(Character::LAM),
        Letter(Character::RA, std::vector<Diacritic> {Diacritic::SHADDAH,Diacritic::FATHAH}),
        Letter(Character::HHA, std::vector<Diacritic> {Diacritic::KASRAH}),
        Letter(Character::YA, Position::MIDDLE),
        Letter(Character::MEEM, std::vector<Diacritic> {Diacritic::SUKOON}),
    };
    Word test1 = Word(ibrahim);
    Word test2 = Word(bsm);

    std::cout << sound_of(ibrahim) << " " << sound_of(ibrahim, false) << std::endl
              << sound_of(bsm) << std::endl
              << sound_of(bsm, false) << std::endl
              << sound_of(test1) << " " << sound_of(test1, false) << std::endl
              << sound_of(test2) << std::endl
              << sound_of(test2, false) << std::endl;

    std::cout << Quran_old::validate_file(".\\Files\\quran-uthmani.txt") << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
