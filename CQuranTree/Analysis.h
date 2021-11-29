#pragma once

#include "Arabic.h"

namespace Analysis
{
	int occurance_of(std::vector<Arabic::Word>, Arabic::Letter);
	int occurance_of(std::vector<Arabic::Word>, Arabic::Word);
	int occurance_of(std::vector<Arabic::Word>, std::vector<Arabic::Word>);
}