#pragma once
#include <MindReader.h>
#include <string>
#include <vector>

class ParserALU
{
public:
	ParserALU(MindReader &tape);
	~ParserALU();
	const unsigned int CodeLength() const;
	std::string ParseString();
	std::string ParseString(const std::string &codeString, unsigned int cell);
private:
	MindReader &m_tape;
	std::vector<unsigned int> m_loopFrom;
	std::vector<unsigned int> m_loopTo;
	std::vector<unsigned int> m_loopTimes;
	std::string loopCode;
	void AddStartPoint(const unsigned int start);
	void AddEndPoint(const unsigned int end);
	void CleanLoopPoints();
	const unsigned int CurrentStartPoint() const;
	const unsigned int CurrentEndPoint() const;
	std::string ProcessLoop(const std::string &codeString, const unsigned int cell);
};