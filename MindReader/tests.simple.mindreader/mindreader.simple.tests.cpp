#include <gtest\gtest.h>
#include <MindReader.h>

using namespace ::testing;

TEST(MindReader, Initialised_tape_returns_empty_cell)
{
	MindReader tape;
	ASSERT_EQ(0, tape.GetSize()) << "Size is NOT 0";
}

TEST(MindReader, Adding_a_cell_to_tape_returns_size_1_null_value)
{
	MindReader tape;
	tape.AddCell();
	ASSERT_EQ(1, tape.GetSize()) << "Size is NOT 1";
	ASSERT_EQ(NULL, tape.ViewCell(0)) << "Initialised cell is NOT null";
}

TEST(MindReader, Adding_2_cells_increment_values_2_each)
{
	MindReader tape;
	tape.AddCell(2);
	for (int i = 0; i < 2; ++i)
	{
		tape.PlusCell(0);
		tape.PlusCell(1);
	}
	ASSERT_EQ(2, tape.GetSize()) << "Size is NOT 2";
	ASSERT_EQ(2, tape.ViewCell(0)) << "Cell value of 0 is NOT 2";
	ASSERT_EQ(2, tape.ViewCell(1)) << "Cell value of 1 is NOT 2";
}

TEST(MindReader, Adding_2_cells_increment_2_each_decrement_2_each_gives_2_null_cells)
{
	MindReader tape;
	tape.AddCell(2);
	for (int i = 0; i < 2; ++i)
	{
		tape.PlusCell(0);
		tape.PlusCell(1);
	}
	for (int i = 1; i >= 0; --i)
	{
		tape.MinusCell(0);
		tape.MinusCell(1);
	}
	ASSERT_EQ(2, tape.GetSize()) << "Size is NOT 2";
	ASSERT_EQ(NULL, tape.ViewCell(0)) << "Cell 0 is NOT null";
	ASSERT_EQ(NULL, tape.ViewCell(1)) << "Cell 1 is NOT null";
}

TEST(MindReader, Automate_adding_cells_to_tape_adding_5_cells_returns_size_5)
{
	MindReader tape;
	tape.AddCell(5);
	ASSERT_EQ(5, tape.GetSize()) << "Tape does NOT have 5 cells";
}