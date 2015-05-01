#include "ParserALU.h"
#include <string>

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
	int loopLength = 0;

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
			AddStartPoint(i + 1);
			m_loopTimes.push_back(m_tape.ViewCell(cellPointer) - 1);
			break;
		case ']':
			AddEndPoint(i);
			loopLength = (CurrentEndPoint() - CurrentStartPoint());
			loopCode = codeString.substr(CurrentStartPoint(), loopLength);
			tapeString += ProcessLoop(loopCode, cellPointer);
			break;
		default:
			break;
		}
		i++;
	}
	return tapeString;
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

void ParserALU::CleanLoopPoints()
{
	m_loopFrom.pop_back();
	m_loopTo.pop_back();
	m_loopTimes.pop_back();
}

string ParserALU::ProcessLoop(const std::string &codeLoop, const unsigned int cell)
{
	string toTape = "";
	const int loopTimes = m_loopTimes.back();
	for (int i = 0; i < loopTimes; ++i)
	{
		toTape += ParseString(codeLoop, cell);
	}
	CleanLoopPoints();
	return toTape;
}