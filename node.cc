// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	_data = data;
	_pPreviousNode = nullptr;
	_pNextNode = nullptr;
}

char Node::GetData() {
	return _data;
}

Node* Node::GetPreviousNode() {
	return _pPreviousNode;
}

Node* Node::GetNextNode() {
	return _pNextNode;
}

Node* Node::InsertPreviousNode(char data) {
	Node* pNewNode = new Node(data);
	pNewNode->SetPreviousNode(_pPreviousNode);
	pNewNode->SetNextNode(this);
	if (_pPreviousNode) _pPreviousNode->SetNextNode(pNewNode);
	_pPreviousNode = pNewNode;
	return pNewNode;
}

Node* Node::InsertNextNode(char data) {
	Node* pNewNode = new Node(data);
	pNewNode->SetPreviousNode(this);
	pNewNode->SetNextNode(_pNextNode);
	if (_pNextNode) _pNextNode->SetPreviousNode(pNewNode);
	_pNextNode = pNewNode;
	return pNewNode;
}

bool Node::ErasePreviousNode() {
	if (_pPreviousNode) {
		Node* pNode = _pPreviousNode->GetPreviousNode();
		delete _pPreviousNode;
		this->SetPreviousNode(pNode);
		if (pNode) pNode->SetNextNode(this);
		return true;
	}
	return false;
}

bool Node::EraseNextNode() {
	if (_pNextNode) {
		Node* pNode = _pNextNode->GetNextNode();
		delete _pNextNode;
		this->SetNextNode(pNode);
		if (pNode) pNode->SetPreviousNode(this);
		return true;
	}
	return false;
}
