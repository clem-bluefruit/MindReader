#include <gtest\gtest.h>
#include <MindReader.h>
#include <string>
using namespace ::testing;

TEST(MindReader, Initialise_empty_tape)
{
	MindReader tape;
	ASSERT_EQ(0, tape.GetSize()) << "Tape is NOT empty";
}

TEST(MindReader, Adding_cells_to_tape)
{
	MindReader tape;
	for (int i = 0; i < 5; ++i)
	{
		tape.AddCell();
	}
	ASSERT_EQ(5, tape.GetSize()) << "Tape is NOT 5 cells";
}

TEST(MindReader, Add_input_string_to_MindReader)
{
	MindReader tape;
	std::string bfCode = "+";
	tape.InputCode(bfCode);
	ASSERT_EQ(bfCode, tape.ViewCode()) << "Input code does NOT match";
}

TEST(MindReader, Initialise_MindReader_with_input_string)
{
	std::string bfCode = "+";
	MindReader tape(bfCode);
	ASSERT_EQ(bfCode, tape.ViewCode()) << "Input code does NOT match initialised value";
}

TEST(MindReader, Initialised_value_is_overwritten)
{
	std::string bfCode = "+";
	std::string expected = "-";
	MindReader tape(bfCode);
	tape.InputCode(expected);
	ASSERT_EQ(expected, tape.ViewCode()) << "Code string is NOT -";
}