#pragma once
#include <MindReader.h>
#include <string>

class ParserALU
{
public:
	ParserALU(MindReader &tape);
	~ParserALU();
	int CodeLength();
	std::string ParseString();
	std::string ParseString(const std::string &codeString, int cell);
private:
	MindReader &m_tape;
};