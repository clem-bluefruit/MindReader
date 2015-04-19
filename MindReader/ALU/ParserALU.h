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
private:
	MindReader &m_tape;
};