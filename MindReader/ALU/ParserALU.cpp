#include "ParserALU.h"
#include <string>
#include <sstream>

using namespace ::std;

ParserALU::ParserALU(MindReader &tape)
	: m_tape(tape)
{
	m_cellPointer.push(0);
}

ParserALU::~ParserALU()
{}

const unsigned int ParserALU::CodeLength() const
{
	return m_tape.ViewCode().length();
}

string ParserALU::ParseString()
{
	return ParseString(m_tape.ViewCode());
}

string ParserALU::ParseString(const string &codeString)
{
	if (m_tape.GetSize() == 0)
		m_tape.AddCell();
	string tapeString = "";
	unsigned int i = 0;
	for (const auto &c : codeString)
	{
		ProcessChar(c, tapeString, i);
		i++;
	}
	return tapeString;
}

void ParserALU::ProcessChar(const char &codeChar, string &tapeString, unsigned int i)
{
	int loopLength = 0;
	unsigned int cellPointer = m_cellPointer.top();
	switch (codeChar)
	{
	case '+':
		m_tape.IncrementCell(m_cellPointer.top());
		break;
	case '-':
		m_tape.DecrementCell(m_cellPointer.top());
		break;
	case '>':
		m_tape.AddCell();
		cellPointer++;
		break;
	case '<':
		cellPointer--;
		break;
	case '.':
		if (ViewTapeCell(m_cellPointer.top()) != '\0')
			tapeString += ViewTapeCell(m_cellPointer.top());
		break;
	case '[':
		AddStartPoint(i + 1);
		m_loopTimes.push(ViewTapeCell(cellPointer) - 1);
		break;
	case ']':
		AddEndPoint(i);
		loopLength = (CurrentEndPoint() - CurrentStartPoint());
		m_loopCode.push(m_tape.ViewCode().substr(CurrentStartPoint(), loopLength));
		tapeString += ParseLoop();
		break;
	default:
		break;
	}
}

void ParserALU::AddStartPoint(const unsigned int start)
{
	m_loopFrom.push(start);
}

void ParserALU::AddEndPoint(const unsigned int end)
{
	m_loopTo.push(end);
}

const unsigned int ParserALU::CurrentStartPoint() const
{
	return m_loopFrom.top();
}

const unsigned int ParserALU::CurrentEndPoint() const
{
	return m_loopTo.top();
}

const unsigned int ParserALU::CurrentLoopTimes() const
{
	return m_loopTimes.top();
}

void ParserALU::CleanLoopPoints()
{
	m_loopFrom.pop();
	m_loopTo.pop();
	m_loopTimes.pop();
	m_loopCode.pop();
	m_cellPointer.pop();
}

string ParserALU::ParseLoop()
{
	string toTape = "";
	for (int i = 0; i < CurrentLoopTimes(); ++i)
	{
		toTape += ParseString(m_loopCode.top());
	}
	CleanLoopPoints();
	return toTape;
}

const unsigned char ParserALU::ViewTapeCell(const unsigned int cell)
{
	return m_tape.ViewCell(cell);
}
