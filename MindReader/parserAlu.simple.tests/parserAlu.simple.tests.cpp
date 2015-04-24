#include <gtest\gtest.h>
#include <MindReader.h>
#include <ParserALU.h>
#include <string>
using namespace ::testing;

TEST(ParserALU, Initialise_ALU_from_initialised_MindReader)
{
	MindReader tape("+++.");
	ParserALU alu(tape);
	ASSERT_EQ(4, alu.CodeLength()) << "Tape value is INCORRECT";
}

TEST(ParserALU, Basic_code_string_gives_output_of_tab_char)
{
	std::string inputString = "+++++ ++++.";
	std::string expected    = "\t";

	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expected, alu.ParseString()) << "Parser output is NOT tab char";
}

TEST(ParserALU, Basic_code_input_after_initialise)
{
	std::string inputString = "+++++ ++++.";
	std::string expected    = "\t";

	MindReader tape;
	ParserALU alu(tape);
	tape.InputCode(inputString);

	ASSERT_EQ(expected, alu.ParseString());
}

TEST(ParserALU, Basic_code_input_add_subtract_output_tab)
{
	std::string inputString = "+++++ +++++-.";
	std::string expected    = "\t";

	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ("\t", alu.ParseString()) << "Parser output is NOT a tab char";
}

TEST(ParserALU, Basic_code_enters_value_of_9_to_Cell_0_and_10_to_Cell_1)
{
	std::string inputString = "+++++ ++++"
							  ">+++++ +++++<.>.";
	std::string expected    = "\t\n";

	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expected, alu.ParseString()) << "Output is NOT \t\n";
}

TEST(ParserALU, Code_input_contains_loop_points_totals_97_returns_a)
{
	std::string inputString = "+++++ +++++"
		  					  "[>+++++ +++++<-]"
							  ">---.";
	std::string expected    = "a";

	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expected, alu.ParseString()) << "Output is NOT a";
}

TEST(ParserALU, Code_input_contains_loop_points_returns_brainfuck)
{
	std::string inputString = "++++[>+++++<-]>[>+++++>++++++>+++++>+++++>+++++>+++++>++++++>+++++>+++++<<<<<<<<<-]>--.>------.>---.>+++++.>++++++++++.>++.>---.>-.>+++++++.";
	std::string expected = "brainfuck";

	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expected, alu.ParseString()) << "Output is NOT brainfuck";
}