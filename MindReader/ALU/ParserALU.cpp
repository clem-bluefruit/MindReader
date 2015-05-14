#include "ParserALU.h"
#include <string>
#include <sstream>

using namespace ::std;

ParserALU::ParserALU(MindReader &tape)
	: m_tape(tape)
{}

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
	unsigned int &cellIndex = m_tape.m_cellIndex;
	
	string tapeString = "";
	string loopCode = "";

	int i = 0;
	int loopLength = 0;

	for (const auto &c : codeString)
	{
		switch (c)
		{
		case '+':
			m_tape.IncrementCell();
			break;
		case '-':
			m_tape.DecrementCell();
			break;
		case '>':
			cellIndex++;
			if (cellIndex >= m_tape.GetSize())
				m_tape.AddCell();
			break;
		case '<':
			cellIndex--;
			break;
		case '.':
			tapeString += ViewTapeCell(cellIndex);
			break;
		case '[':
			AddStartPoint(i + 1);
			m_loopTimes.push(ViewTapeCell(cellIndex));
			break;
		case ']':
			AddEndPoint(i);
			tapeString += ParseLoop(GetLoop(codeString));
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
	return (m_loopTimes.top()) - 1; // Subtract 1 as ran once already
}

void ParserALU::CleanLoopPoints()
{
	m_loopFrom.pop();
	m_loopTo.pop();
	m_loopTimes.pop();
}

string ParserALU::ParseLoop(const std::string &codeLoop)
{
	if (codeLoop == "<")
	{
		while (ViewTapeCell(m_tape.m_cellIndex) != 0)
		{
			m_tape.m_cellIndex--;
		}
		return "";
	}
	
	string toTape = "";
	for (int i = 0; i < CurrentLoopTimes(); ++i)
	{
		toTape += ParseString(codeLoop);
	}
	CleanLoopPoints();
	return toTape;
}

string ParserALU::GetLoop(string codeString)
{
	unsigned int loopLength = (CurrentEndPoint() - CurrentStartPoint());
	return codeString.substr(CurrentStartPoint(), loopLength);
}

const unsigned char ParserALU::ViewTapeCell(const unsigned int cell)
{
	return m_tape.ViewCell(cell);
}
