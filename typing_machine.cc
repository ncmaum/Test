// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	_pPreviousNode = nullptr;
	_pNextNode = nullptr;
}

void TypingMachine::HomeKey() {
	while (_pPreviousNode) _pPreviousNode = _pPreviousNode->GetPreviousNode();
	return;
}

void TypingMachine::EndKey() {
	while (_pNextNode->GetNextNode()) _pNextNode = _pNextNode->GetNextNode();
	return;
}

void TypingMachine::LeftKey() {
	if (_pPreviousNode) _pPreviousNode = _pPreviousNode->GetPreviousNode();
	return;
}

void TypingMachine::RightKey() {
	if (_pNextNode) _pNextNode = _pNextNode->GetNextNode();
	return;
}

bool TypingMachine::TypeKey(char key) {
	if (key < 0x20 || key > 0x7E) return false;
	if (_pPreviousNode) _pPreviousNode->InsertNextNode(key);
	else _pPreviousNode = new Node(key);
	return true;
}

bool TypingMachine::EraseKey() {
	if (_pPreviousNode) {
		Node* pTmpNode = _pPreviousNode->GetPreviousNode();
		if (pTmpNode) {
			pTmpNode->EraseNextNode();
			_pPreviousNode = pTmpNode;
		}
		else if (_pNextNode) {
			_pNextNode->ErasePreviousNode();
			_pPreviousNode = nullptr;
		}
		else {
			delete _pPreviousNode;
			_pPreviousNode = nullptr;
		}

		return true;
	}
	return false;
}

std::string TypingMachine::Print(char separator) {
	std::string result = "";
	Node* pNode = _pPreviousNode;
	if (pNode)
	{
		result = pNode->GetData() + result;
		while (pNode->GetPreviousNode()) pNode = pNode->GetPreviousNode();
	}
	result = result + separator;
	pNode = _pNextNode;
	if (pNode)
	{
		result += pNode->GetData();
		while (pNode->GetNextNode()) pNode = pNode->GetNextNode();
	}

	return result;
}
