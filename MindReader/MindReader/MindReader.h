#pragma once

#include <string>
#include <vector>

class MindReader
{
public:
	MindReader();
	MindReader(std::string code);
	~MindReader();
	const unsigned int GetSize() const;
	void AddCell();
	void IncrementCell();
	void DecrementCell();
	const char ViewCell(const unsigned int cellID) const;
	void InputCode(std::string code);
	const std::string ViewCode() const;
	const std::string OutputString() const;
	unsigned int m_cellIndex;
private:
	std::vector<unsigned char> m_tape;
	std::string m_bfCode;
};
