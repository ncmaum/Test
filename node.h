// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	explicit Node(char data);
	char GetData();
	Node* InsertPreviousNode(char data);
	Node* InsertNextNode(char data);
	Node* GetPreviousNode();
	Node* GetNextNode();
	bool ErasePreviousNode();
	bool EraseNextNode();

private:
	Node* _pPreviousNode;
	Node* _pNextNode;
	char _data;

	void SetPreviousNode(Node* pNode) { _pPreviousNode = pNode; }
	void SetNextNode(Node* pNode) { _pNextNode = pNode; }
};

#endif  // NODE_H_