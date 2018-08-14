// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
	static void SingleNodeTest() {
		Node *node = new Node('A');
		ASSERT_EQ(node->GetData(), 'A');
		delete node;
	}

	static void InsertPreviousNodeTest() {
		Node *node = new Node('A');
		Node* previous_node = node->InsertPreviousNode('B');
		ASSERT_EQ(previous_node->GetData(), 'B');
		ASSERT_EQ(previous_node->GetNextNode()->GetData(), 'A');

		delete node;
		delete previous_node;
	}

	static void InsertNextNodeTest() {
		Node *node = new Node('A');
		Node* next_node = node->InsertNextNode('B');
		ASSERT_EQ(next_node->GetData(), 'B');
		ASSERT_EQ(next_node->GetPreviousNode()->GetData(), 'A');

		delete node;
		delete next_node;
	}

	static void InsertPreviousNodeTestWhenPreviousNodeExist() {
		Node *node = new Node('A');
		Node* previous_node = node->InsertPreviousNode('B');
		Node* new_previous_node = node->InsertPreviousNode('C');

		ASSERT_EQ(new_previous_node->GetData(), 'C');
		ASSERT_EQ(new_previous_node->GetPreviousNode()->GetData(), 'B');
		ASSERT_EQ(new_previous_node->GetNextNode()->GetData(), 'A');

		delete node;
		delete previous_node;
		delete new_previous_node;
	}

	static void InsertNextNodeTestWhenNextNodeExist() {
		Node *node = new Node('A');
		Node* next_node = node->InsertNextNode('B');
		Node* new_next_node = node->InsertNextNode('C');

		ASSERT_EQ(new_next_node->GetData(), 'C');
		ASSERT_EQ(new_next_node->GetPreviousNode()->GetData(), 'A');
		ASSERT_EQ(new_next_node->GetNextNode()->GetData(), 'B');

		delete node;
		delete next_node;
		delete new_next_node;
	}

	static void EraseNullPreviousNodeTest() {
		Node *node = new Node('A');
		ASSERT_EQ(node->ErasePreviousNode(), false);
		delete node;
	}

	static void EraseNullNextNodeTest() {
		Node *node = new Node('A');
		ASSERT_EQ(node->EraseNextNode(), false);
		delete node;
	}

	static void ErasePreviousNodeTest() {
		Node *node = new Node('A');
		node->InsertPreviousNode('B');

		ASSERT_EQ(node->ErasePreviousNode(), true);
		ASSERT_TRUE((node->GetPreviousNode() == nullptr));

		delete node;
	}
	
	static void EraseNextNodeTest() {
		Node *node = new Node('A');
		node->InsertNextNode('B');

		ASSERT_EQ(node->EraseNextNode(), true);
		ASSERT_TRUE((node->GetNextNode() == nullptr));

		delete node;
	}

	static void ErasePreviousNodeTestWhenTheNodeHasPreviousNode() {
		Node *node = new Node('A');
		Node* previous_node = node->InsertPreviousNode('B');
		node->InsertPreviousNode('C');

		EXPECT_EQ(node->GetPreviousNode()->GetData(), 'C');

		node->ErasePreviousNode();
		ASSERT_EQ(node->GetPreviousNode()->GetData(), 'B');

		delete node;
		delete previous_node;
	}

	static void EraseNextNodeTestWhenTheNodeHasNextNode() {
		Node *node = new Node('A');
		Node* next_node = node->InsertNextNode('B');
		node->InsertNextNode('C');
		
		EXPECT_EQ(node->GetNextNode()->GetData(), 'C');

		node->EraseNextNode();
		ASSERT_EQ(node->GetNextNode()->GetData(), 'B');

		delete node;
		delete next_node;
	}


public:
	static void RunTest() {
		SingleNodeTest();

		InsertPreviousNodeTest();
		InsertNextNodeTest();
		InsertPreviousNodeTestWhenPreviousNodeExist();
		InsertNextNodeTestWhenNextNodeExist();

		EraseNullPreviousNodeTest();
		EraseNullNextNodeTest();
		ErasePreviousNodeTest();
		EraseNextNodeTest();
		ErasePreviousNodeTestWhenTheNodeHasPreviousNode();
		EraseNextNodeTestWhenTheNodeHasNextNode();
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

void NodeTest() {
	NodeConstructorTestSuite::RunTest();
	// add more..
}