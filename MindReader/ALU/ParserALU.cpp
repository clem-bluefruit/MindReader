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
	return ParseString(m_tape.ViewCode(),0);
}

string ParserALU::ParseString(const string &codeString, int cell = 0)
{
	if (m_tape.GetSize() == 0)
		m_tape.AddCell();
	unsigned int cellPointer = cell;
	
	string tapeString = "";
	string loopCode = "";

	int i = 0;
	int loopFrom = 0;
	int loopTo = 0;
	int loopLength = 0;
	int loopTimes = 0;

	for (const auto &c : codeString)
	{
		switch (c)
		{
		case '+':
			m_tape.IncrementCell(cellPointer);
			break;
		case '-':
			m_tape.DecrementCell(cellPointer);
			break;
		case '>':
			m_tape.AddCell();
			cellPointer++;
			break;
		case '<':
			cellPointer--;
			break;
		case '.':
			tapeString += m_tape.ViewCell(cellPointer);
			break;
		case '[':
			loopFrom = (i + 1);
			loopTimes = (m_tape.ViewCell(cellPointer) - 1);
			break;
		case ']':
			loopTo = i;
			loopLength = (loopTo - loopFrom);
			loopCode = codeString.substr(loopFrom, loopLength);
			for (int loopNum = 0; loopNum < loopTimes; ++loopNum)
			{
				tapeString += ParseString(loopCode, cellPointer);
			}
			break;
		default:
			break;
		}
		i++;
	}
	return tapeString;
}