// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data)
	: _pPreviousNode(nullptr), _pNextNode(nullptr), _data(data)
{
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
	pNewNode->_pPreviousNode = _pPreviousNode;
	pNewNode->_pNextNode     = this;
	if (_pPreviousNode) 
		_pPreviousNode->_pNextNode = pNewNode;
	_pPreviousNode = pNewNode;
	return pNewNode;
}

Node* Node::InsertNextNode(char data) {
	Node* pNewNode = new Node(data);
	pNewNode->_pPreviousNode = this;
	pNewNode->_pNextNode     = _pNextNode;
	if (_pNextNode) 
		_pNextNode->_pPreviousNode = pNewNode;
	_pNextNode = pNewNode;
	return pNewNode;
}

bool Node::ErasePreviousNode() {
	if (_pPreviousNode) {
		Node* pNode    = _pPreviousNode;
		_pPreviousNode = _pPreviousNode->GetPreviousNode();
		if (_pPreviousNode)
			_pPreviousNode->_pNextNode = this;
		delete pNode;
		return true;
	}
	return false;
}

bool Node::EraseNextNode() {
	if (_pNextNode) {
		Node* pNode = _pNextNode;
		_pNextNode  = _pNextNode->GetNextNode();
		if (_pNextNode) 
			_pNextNode->_pPreviousNode = this;
		delete pNode;
		return true;
	}
	return false;
}
