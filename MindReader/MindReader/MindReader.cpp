#include "MindReader.h"
using namespace ::std;

MindReader::MindReader() :
	m_tape(0)
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

char MindReader::ViewCell(int cell = 0) const
{
	return m_tape.at(cell);
}

void MindReader::PlusCell(int cell)
{
	unsigned int value = ViewCell(cell);
	value++;
	m_tape[cell] = value;
}