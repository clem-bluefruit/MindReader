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
	char ViewCell(int) const;
	void PlusCell(int);
	void MinusCell(int);
private:
	std::vector<char> m_tape;
};
