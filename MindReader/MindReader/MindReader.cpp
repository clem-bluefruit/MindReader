#include "MindReader.h"
using namespace ::std;

MindReader::MindReader()
	: m_tape(0),
	  m_bfCode(""),
	  m_cellIndex(0)
{
	AddCell();
}

MindReader::MindReader(string code)
	: m_tape(0),
	  m_bfCode(code),
	  m_cellIndex(0)
{
	AddCell();
}

MindReader::~MindReader()
{}

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
	m_tape.at(m_cellIndex) += 1;
}

void MindReader::DecrementCell()
{
	m_tape.at(m_cellIndex) -= 1;
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
	string appendChars = "";
	for (const char c : m_tape)
	{
		appendChars += c;
	}
	return appendChars;
}
