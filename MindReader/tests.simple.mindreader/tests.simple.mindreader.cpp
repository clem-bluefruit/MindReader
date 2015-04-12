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
	tape.AddCell();
	tape.AddCell();
	tape.PlusCell(0);
	tape.PlusCell(0);
	tape.PlusCell(1);
	tape.PlusCell(1);
	ASSERT_EQ(2, tape.GetSize()) << "Size is NOT 2";
	ASSERT_EQ(2, tape.ViewCell(0)) << "Cell value of 0 is NOT 2";
	ASSERT_EQ(2, tape.ViewCell(1)) << "Cell value of 1 is NOT 2";
}