#pragma once
#include <MindReader.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

class ParserALU
{
public:
	ParserALU(MindReader &tape);
	~ParserALU();
	const unsigned int CodeLength() const;
	std::string ParseString();
	std::string ParseString(const std::string &codeString);
private:
	MindReader &m_tape;
	std::stack<unsigned int> m_loopFrom;
	std::stack<unsigned int> m_loopTo;
	std::stack<unsigned int> m_loopTimes;
	void AddStartPoint(const unsigned int start);
	void AddEndPoint(const unsigned int end);
	void CleanLoopPoints();
	const unsigned int CurrentStartPoint() const;
	const unsigned int CurrentEndPoint() const;
	const unsigned int CurrentLoopTimes() const;
	std::string ParseLoop(const std::string &codeString);
	std::string GetLoop(std::string codeString);
	const unsigned char ViewTapeCell(const unsigned int cell);
};
