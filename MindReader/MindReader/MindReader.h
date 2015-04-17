#pragma once

#include <string>
#include <vector>

class MindReader
{
public:
	MindReader();
	~MindReader();
	unsigned int GetSize() const;
	void AddCell();
	void AddCell(unsigned int numCells);
	char ViewCell(int cellID) const;
	void PlusCell(int cellID);
	void MinusCell(int cellID);
private:
	std::vector<char> m_tape;
};
