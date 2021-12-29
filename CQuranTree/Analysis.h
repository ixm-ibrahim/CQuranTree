#pragma once

#include "Arabic.h"

namespace Analysis
{
	int occurance_of(std::vector<Arabic_old::Word>, Arabic_old::Letter);
	int occurance_of(std::vector<Arabic_old::Word>, Arabic_old::Word);
	int occurance_of(std::vector<Arabic_old::Word>, std::vector<Arabic_old::Word>);
}