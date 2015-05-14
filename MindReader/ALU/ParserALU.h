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
	std::stack<unsigned int> m_cellPointer;
	std::stack<std::string> m_loopCode;
	void AddStartPoint(const unsigned int start);
	void AddEndPoint(const unsigned int end);
	void CleanLoopPoints();
	const unsigned int CurrentStartPoint() const;
	const unsigned int CurrentEndPoint() const;
	const unsigned int CurrentLoopTimes() const;
	std::string loopCode;
	std::string ParseLoop();
	void ProcessChar(const char &codeChar, std::string &tapeString, unsigned int i);
	const unsigned char ViewTapeCell(const unsigned int cell);
};
