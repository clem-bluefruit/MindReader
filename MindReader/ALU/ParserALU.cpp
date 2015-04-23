#include "ParserALU.h"
#include <string>
#include <regex>
#include <iostream>

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

string ParserALU::ParseString(const string codeString, int cell = 0)
{
	if (m_tape.GetSize() == 0)
		m_tape.AddCell();
	unsigned int cellPointer = cell;
	
	string tapeString = "";

	regex match("\\[([^\\]*)]", regex_constants::extended);
	smatch loop;
	regex_search(codeString, loop, match);
	
	//return to_string(loop.size());

	int loopTimes = 0;
	int i = 0;
	int loopPoint = 0;

	for (const auto c : codeString)
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
			loopTimes = (m_tape.ViewCell(cellPointer) - 1);
			loopPoint = cellPointer;
			break;
		case ']':
			for (int loops = 0; loops < loopTimes; ++loops)
				tapeString += ParseString(loop[1], loopPoint);
			break;
		default:
			break;
		}
		++i;
	}
	//return codeString;
	return tapeString;
}