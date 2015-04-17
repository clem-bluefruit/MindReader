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

void MindReader::AddCell(unsigned int numCells)
{
	for (int i = 0; i < numCells; ++i)
		AddCell();
}

char MindReader::ViewCell(int cellID = 0) const
{
	return m_tape.at(cellID);
}

void MindReader::PlusCell(int cellID)
{
	unsigned int value = ViewCell(cellID);
	value++;
	m_tape[cellID] = value;
}

void MindReader::MinusCell(int cellID)
{
	unsigned int value = ViewCell(cellID);
	value--;
	m_tape[cellID] = value;
}
