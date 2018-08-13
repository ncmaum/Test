// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() 
	: _pPreviousNode(nullptr), _pNextNode(nullptr), _length(0)
{
}

void TypingMachine::HomeKey() {
	while (_pPreviousNode)
		LeftKey();
	return;
}

void TypingMachine::EndKey() {
	while (_pNextNode)
		RightKey();
	return;
}

void TypingMachine::LeftKey() {
	if (_pPreviousNode) {
		_pNextNode = _pPreviousNode;
		_pPreviousNode = _pPreviousNode->GetPreviousNode();
	}
	return;
}

void TypingMachine::RightKey() {
	if (_pNextNode) {
		_pPreviousNode = _pNextNode;
		_pNextNode = _pNextNode->GetNextNode();
	}
	return;
}

bool TypingMachine::TypeKey(char key) {
	if (key < 0x20 || key > 0x7E || _length >= 100)
		return false;
	if (_pPreviousNode)
		_pPreviousNode = _pPreviousNode->InsertNextNode(key);
	else if (_pNextNode)
		_pPreviousNode = _pNextNode->InsertPreviousNode(key);
	else
		_pPreviousNode = new Node(key);
	++_length;
	return true;
}

bool TypingMachine::EraseKey() {
	if (_pPreviousNode) {
		Node* pTmpNode = _pPreviousNode->GetPreviousNode();
		if (pTmpNode)
			pTmpNode->EraseNextNode();
		else if (_pNextNode)
			_pNextNode->ErasePreviousNode();
		else
			delete _pPreviousNode;
		_pPreviousNode = pTmpNode;
		--_length;
		return true;
	}
	return false;
}

std::string TypingMachine::Print(char separator) {
	std::string result = "";

	Node* pNode = _pPreviousNode;
	while (pNode) {
		result = pNode->GetData() + result;
		pNode = pNode->GetPreviousNode();
	} while (pNode);

	if (separator != 0) result = result + separator;

	pNode = _pNextNode;
	while (pNode)
	{
		result += pNode->GetData();
		pNode = pNode->GetNextNode();
	};

	return result;
}
