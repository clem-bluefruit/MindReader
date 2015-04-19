#include "MindReader.h"
using namespace ::std;

MindReader::MindReader()
	: m_tape(0),
	  m_bfCode("")
{
}

MindReader::MindReader(string code)
	: m_tape(0),
	m_bfCode(code)
{
}

MindReader::~MindReader()
{
}

unsigned int MindReader::GetSize() const
{
	return m_tape.size();
}

void MindReader::AddCell()
{
	m_tape.push_back(0);
}

void MindReader::IncrementCell(int cellID)
{
	int cellvalue = ViewCell(cellID);
	cellvalue++;
	m_tape.at(cellID) = cellvalue;
}

char MindReader::ViewCell(int cellID = 0) const
{
	return m_tape.at(cellID);
}

void MindReader::InputCode(string bfCode)
{
	m_bfCode = bfCode;
}

string MindReader::ViewCode() const
{
	return m_bfCode;
}

string MindReader::OutputString() const
{
	string appendChars;
	for (char c : m_tape)
	{
		appendChars += c;
	}
	return appendChars;
}