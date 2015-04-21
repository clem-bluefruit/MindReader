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
	void IncrementCell(int cellID);
	void DecrementCell(int cellID);
	char ViewCell(int cellID) const;
	void InputCode(std::string code);
	std::string ViewCode() const;
	std::string OutputString() const;
private:
	std::vector<char> m_tape;
	std::string m_bfCode;
};

/*
	Parser
	ALU
*/

