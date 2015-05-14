#pragma once

#include <string>
#include <vector>

class MindReader
{
public:
	MindReader();
	MindReader(std::string code);
	~MindReader();
	unsigned int GetSize() const;
	void AddCell();
	void IncrementCell();
	void DecrementCell();
	char ViewCell(int cellID) const;
	void InputCode(std::string code);
	std::string ViewCode() const;
	std::string OutputString() const;
	unsigned int m_cellIndex;
private:
	std::vector<unsigned char> m_tape;
	std::string m_bfCode;
};
