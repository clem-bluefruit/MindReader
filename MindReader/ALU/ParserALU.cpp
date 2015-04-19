#include "ParserALU.h"
#include <string>

using namespace ::std;

ParserALU::ParserALU(MindReader &tape)
	: m_tape(tape)
{}

ParserALU::~ParserALU()
{}

int ParserALU::CodeLength()
{
	return m_tape.ViewCode().length();
}

string ParserALU::ParseString()
{
	if (m_tape.GetSize() == 0)
		m_tape.AddCell();

	for (char &c : m_tape.ViewCode())
	{
		switch (c)
		{
		case '+':
			m_tape.IncrementCell(0);
			break;
		default:
			break;
		}
	}
	return m_tape.OutputString();
}