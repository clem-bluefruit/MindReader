#include <gtest\gtest.h>

#include <MindReader.h>
#include <ParserALU.h>
#include <string>
#include <iostream>
using namespace ::testing;

TEST(ParserALU, Basic_code_input_on_constructor_output_is_tab_char)
{
	std::string inputString = "+++++ ++++.";
	std::string expected    = "\t";
	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expected, alu.ParseString()) << "Parser with constructr, output is NOT tab char";
}

TEST(ParserALU, Basic_code_input_after_constructor_output_is_tab_char)
{
	std::string inputString = "+++++ ++++.";
	std::string expected    = "\t";
	MindReader tape;
	ParserALU alu(tape);
	tape.InputCode(inputString);
	ASSERT_EQ(expected, alu.ParseString()) << "Parser without constructor, output is NOT tab char";
}

TEST(ParserALU, Basic_code_input_10_minus_1_output_is_tab_char)
{
	std::string inputString = "+++++ +++++-.";
	std::string expected    = "\t";
	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ("\t", alu.ParseString()) << "Parser output is NOT a tab char";
}

TEST(ParserALU, Basic_code_iterate_two_cells_append_values_to_both)
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

TEST(ParserALU, Nested_loops_basic_example_output_is_2)
{
	std::string inputString = "+++++[>+++++[>++<-]<-]>>.";
	std::string expected = "2";
	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expected, alu.ParseString()) << "Output is NOT 2";
}

TEST(ParserALU, Nested_loops_three_deep_with_char_rollover_output_is_q)
{
	std::string inputString = "+++++[>+++++[>+++++[>+++++<-]<-]<-]>>>.";
	std::string expected = "q";
	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expected, alu.ParseString()) << "Output is NOT 'q'";
}


TEST(ParserALU, Nested_loops_example_Hello_World)
{
	std::string inputString = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
	std::string expectedString = "Hello World!";
	MindReader tape(inputString);
	ParserALU alu(tape);
	ASSERT_EQ(expectedString, alu.ParseString()) << "Output is NOT 'Hello World!'";
}
/*
TEST(ParserALU, Fibonacci_sequence_up_to_100)
{
std::string input = "+++++++++++"
">+>> >> ++++++++++++++++++++++++++++++++++++++++++++"
"> ++++++++++++++++++++++++++++++++ << << << [> [>> >> >> +> "
"+ << << << <-] >> >> >> >[<< << << <+>> >> >> >-]<[>++++++++++[-"
"<-[>> +>+<< <-] >> >[<< <+>> >-] + <[>[-]<[-]]>[<< [>> > +<< <"
"- ] >> [-]] << ] >> >[>> +> +<< <-] >> >[<< <+>> >-] + <[>[-]<[-]]"
">[<< +>> [-]] << << << <] >> >> >[++++++++++++++++++++++++ + "
"++++++++++++++++++++++ + .[-]]++++++++++<[-> - <]>++++"
"++++++++++++++++++++++++++++++++++++++++++++.[-] << "
"<< << << << << [>> >+> +<< << -] >> >> [<< << +>> >> -]<-[>> .>. << <"
"[-]] << [>> +>+<< <-] >> >[<< <+>> >-] << [<+>-] > [<+>-] << < -]";
std::string expected = "1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89";
MindReader tape(input);
ParserALU alu(tape);
ASSERT_EQ(expected, alu.ParseString()) << "Output is not '" << expected << "'";
}
/**/
