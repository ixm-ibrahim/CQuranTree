// CQuranTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "Arabic.h"

using namespace Arabic;

int main()
{
    SetConsoleOutputCP(65001);
    std::cout << "Hello World!\n";

    //std::cout << abjad_value(Character::GHAYN) << std::endl << to_ascii("0x1b36") << std::endl
    //          << sound_of(Letter(Character::TA, Diacritic::MARBUTAH, std::vector<Diacritic> {Diacritic::TANWEEN_FATHAH}))
    //          << sound_of(Letter(Character::TA, Diacritic::MARBUTAH));

    std::vector<Letter> word
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

    std::cout << sound_of(word) << " " << sound_of(word, false) << std::endl
              << sound_of(bsm) << std::endl
              << sound_of(bsm, false) << std::endl;
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
