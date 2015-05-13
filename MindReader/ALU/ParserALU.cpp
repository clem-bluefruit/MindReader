#include "ParserALU.h"
#include <string>
#include <sstream>

using namespace ::std;

ParserALU::ParserALU(MindReader &tape)
	: m_tape(tape),
	  m_loopFrom(0),
	  m_loopTo(0),
	  m_loopTimes(0)
{}

ParserALU::~ParserALU()
{}

const unsigned int ParserALU::CodeLength() const
{
	return m_tape.ViewCode().length();
}

string ParserALU::ParseString()
{
	return ParseString(m_tape.ViewCode(), 0);
}

string ParserALU::ParseString(const string &codeString, unsigned int cell = 0)
{
	if (m_tape.GetSize() == 0)
		m_tape.AddCell();
	unsigned int cellPointer = cell;
	
	string tapeString = "";
	string loopCode = "";

	int i = 0;

	for (const auto &c : codeString)
	{
		ProcessChar(c, tapeString, cellPointer, i);
		i++;
	}
	return tapeString;
}

void ParserALU::ProcessChar(char codeChar, string &tapeString, unsigned int &cellPointer, unsigned int i)
{
	int loopLength = 0;
	switch (codeChar)
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
		if (ViewTapeCell(cellPointer) != '\0')
			tapeString += ViewTapeCell(cellPointer);
		break;
	case '[':
		AddStartPoint(i + 1);
		m_loopTimes.push_back(ViewTapeCell(cellPointer) - 1);
		break;
	case ']':
		AddEndPoint(i);
		loopLength = (CurrentEndPoint() - CurrentStartPoint());
		loopCode = m_tape.ViewCode().substr(CurrentStartPoint(), loopLength);
		tapeString += ParseLoop(loopCode, cellPointer);
		break;
	default:
		break;
	}
}

void ParserALU::AddStartPoint(const unsigned int start)
{
	m_loopFrom.push_back(start);
}

void ParserALU::AddEndPoint(const unsigned int end)
{
	m_loopTo.push_back(end);
}

const unsigned int ParserALU::CurrentStartPoint() const
{
	return m_loopFrom.back();
}

const unsigned int ParserALU::CurrentEndPoint() const
{
	return m_loopTo.back();
}

const unsigned int ParserALU::CurrentLoopTimes() const
{
	return m_loopTimes.back();
}

void ParserALU::CleanLoopPoints()
{
	m_loopFrom.pop_back();
	m_loopFrom.shrink_to_fit();
	m_loopTo.pop_back();
	m_loopTo.shrink_to_fit();
	m_loopTimes.pop_back();
	m_loopTimes.shrink_to_fit();
}

string ParserALU::ParseLoop(const std::string &codeLoop, const unsigned int cell)
{
	string toTape = "";
	for (int i = 0; i < CurrentLoopTimes(); ++i)
	{
		toTape += ParseString(codeLoop, cell);
	}
	CleanLoopPoints();
	return toTape;
}

const unsigned char ParserALU::ViewTapeCell(const unsigned int cell)
{
	return m_tape.ViewCell(cell);
}
