#include "MindReader.h"
using namespace ::std;

MindReader::MindReader()
	: m_bfCode("")
{
	m_tape.push_back(0);
	m_currentCell = m_tape.begin();
}

MindReader::MindReader(string code)
	: m_bfCode(code)
{
	m_tape.push_back(0);
	m_currentCell = m_tape.begin();
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

void MindReader::IncrementCell()
{
	(*m_currentCell)++;
}

void MindReader::DecrementCell()
{
	(*m_currentCell)--;
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