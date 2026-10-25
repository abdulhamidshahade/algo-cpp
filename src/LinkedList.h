#pragma once

#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node<T>* next;
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;

public:
	LinkedList() {
		head = nullptr;
	}

private:
	bool isEmpty() {
		return (head == nullptr);
	}

public:
	void traverse() {
		if (isEmpty()) {
			cout << "\n--> LinkedList is empty.\n";
		}

		Node<T>* current = head;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}

		cout << "\n";
	}

	void insertAtBegin(T data) {

		Node<T>* newNode = new Node<T>{ data };

		if (isEmpty()) {
			head = newNode;
			newNode->next = nullptr;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtEnd(T data) {
		Node<T>* current = head;
		Node<T>* newNode = new Node<T>{ data };

		if (isEmpty()) {
			insertAtBegin(data);
			return;
		}

		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = newNode;
		newNode->next = nullptr;
	}

	bool isFound(T data) {
		Node<T>* current = head;

		while (current != nullptr) {
			if (current->data == data) {
				return true;
			}

			current = current->next;
		}

		return false;
	}

	int count() {
		int count = 0;

		Node<T>* current = head;

		while (current != nullptr) {
			++count;
			current = current->next;
		}

		return count;
	}

	int countOfItem(T item) {

		if (isEmpty()) {
			return 0;
		}

		if (!isFound(item)) {
			return 0;
		}

		int count = 0;

		Node<T>* current = head;

		while (current != nullptr) {
			if (current->data == item) {
				++count;
			}

			current = current->next;
		}

		return count;
	}

	void insertBeforeItem(T data, T item) {
		if (!isFound(item)) {
			cout << "\n-->The item is not found!\n";
		}
		if (count() == 1) {
			insertAtBegin(data);
			return;
		}
		Node<T>* newNode = new Node<T>{ data };
		Node<T>* current = head;

		while (current->next->data != item) {
			current = current->next;
		}

		newNode->next = current->next;
		current->next = newNode;
	}

	void deleteAtBegin() {
		Node<T>* current = head;

		if (isEmpty()) {
			cout << "\nThe linkedlist is empty!\n";
		}

		head = current->next;

		delete current;
	}
};