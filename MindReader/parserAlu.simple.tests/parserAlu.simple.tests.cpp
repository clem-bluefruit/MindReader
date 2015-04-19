#include <gtest\gtest.h>
#include <MindReader.h>
#include <ParserALU.h>
#include <string>
using namespace ::testing;

TEST(ParserALU, Initialise_ALU_from_initialised_MindReader)
{
	MindReader tape("+++");
	ParserALU alu(tape);
	ASSERT_EQ(3, alu.CodeLength()) << "Tape value is INCORRECT";
}

TEST(ParserALU, Basic_code_string_gives_output_of_tab_char)
{
	std::string inputString = "+++++ ++++";
	std::string expected = "\t";

	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expected, alu.ParseString()) << "Parser output is NOT tab char";
}