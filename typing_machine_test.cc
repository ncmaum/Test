// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
	static void BarSeparatorTest() {
		TypingMachine tm;
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}

	static void EmptySeparatorTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.LeftKey();
		tm.TypeKey('c');
		ASSERT_EQ(tm.Print(0), std::string("acb"));
	}

	static void TypeKeyTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		ASSERT_EQ(tm.Print('|'), std::string("a|"));

		tm.TypeKey('b');
		ASSERT_EQ(tm.Print('|'), std::string("ab|"));
	}

	static void HomeKeyTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey('b');

		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|ab"));
	}

	static void EndKeyTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey('b');

		tm.HomeKey();
		EXPECT_EQ(tm.Print('|'), std::string("|ab"));

		tm.EndKey();
		EXPECT_EQ(tm.Print('|'), std::string("ab|"));
	}

	static void LeftKeyTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey('b');

		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|b"));

		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("|ab"));
	}

	static void RightKeyTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey('b');

		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|ab"));

		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|b"));
	}

	static void EraseTestWhenOneElement() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}

	static void EraseTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|"));
	}

	static void EraseTestAtBegin() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.HomeKey();
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("|ab"));
	}

	static void InvalidKeyTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey(0x19);
		tm.TypeKey(0x7F);

		ASSERT_EQ(tm.Print('|'), std::string("a|"));
	}

	static void EndlineKeyTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		tm.TypeKey(0x20);
		tm.TypeKey(0x7E);

		ASSERT_EQ(tm.Print('|'), std::string("a ~|"));
	}



public:
	static void RunTest() {
		BarSeparatorTest();
		EmptySeparatorTest();
		TypeKeyTest();
		HomeKeyTest();
		EndKeyTest();
		LeftKeyTest();
		RightKeyTest();
		EraseTestWhenOneElement();
		EraseTest();
		EraseTestAtBegin();
		InvalidKeyTest();
		EndlineKeyTest();
		// add more..
	}
};

class SomeOtherTestSuite
{
private:

public:
	static void RunTest() {
		// add more..
	}
};

void TypingMachineTest() {
	TmConstructorTestSuite::RunTest();
	// add more..
}