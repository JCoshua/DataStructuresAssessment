#pragma once
#include "Iterator.h"
#include "Node.h"
#include <iostream>
template<typename T>
class List
{
public:
	List();
	List(const List<T>& otherList);
	~List();

	/// <summary>
	/// Deletes all nodes in the list
	/// </summary>
	void destroy();

	/// <summary>
	/// Returns an iterator pointing to the first node in the list
	/// </summary>
	/// <returns>The iterator pointing to the first node in the list</returns>
	Iterator<T> begin() const;

	/// <summary>
	/// Returns an iterator pointing to the first node in the list
	/// </summary>
	/// <returns>The iterator pointing to the first node in the list</returns>
	Iterator<T> end() const;

	/// <summary>
	/// Checks to see if the given item is in the list
	/// </summary>
	/// <param name="object">The item being checked</param>
	/// <returns>If the item is in the list</returns>
	bool contains(const T object) const;

	/// <summary>
	/// Adds a new node to the beginning of the list
	/// </summary>
	/// <param name="value">The value added</param>
	void pushFront(const T& value);

	/// <summary>
	/// Adds a new node to the end of the list
	/// </summary>
	/// <param name="value">The value added</param>
	void pushBack(const T& value);

	/// <summary>
	/// Adds a new node at the given index
	/// </summary>
	/// <param name="value">The node to be added</param>
	/// <param name="index">The index to add the node</param>
	/// <returns>If the value was added</returns>
	bool insert(const T& value, int index);

	/// <summary>
	/// Remove all nodes with the given value
	/// </summary>
	/// <param name="value">The Value to be removed</param>
	/// <returns>If the value was removed</returns>
	bool remove(const T& value);

	/// <summary>
	/// Prints the values for all the nodes
	/// </summary>
	void print() const;

	/// <summary>
	/// Set the default values for the first node pointer, the last node pointer, and the node count
	/// </summary>
	void initialize();

	/// <summary>
	/// Returns whether or not the list has any nodes in it
	/// </summary>
	/// <returns>Whether or not the list has any nodes in it</returns>
	bool isEmpty() const;

	/// <summary>
	/// Sets the given iterator to point to a node at the given index
	/// </summary>
	/// <param name="iter">The Iterator to point</param>
	/// <param name="index">The index of the node the iterator should point to</param>
	/// <returns></returns>
	bool getData(Iterator<T>& iter, int index);

	/// <summary>
	/// Returns the amount of nodes in the list
	/// </summary>
	/// <returns>The amount of nodes in the list</returns>
	int getLength() const;

	const List<T>& operator =(const List<T>& otherList);

	/// <summary>
	/// Uses bubble sort to sort the list.
	/// </summary>
	void sort();
private:
	//The first node of the list
	Node<T>* m_first;
	//The last node of the list
	Node<T>* m_last;
	//The number of nodes in the list
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& otherList)
{
	m_first = otherList.m_first;
	m_last = otherList.m_last;
	m_nodeCount = otherList.getLength();
}

template<typename T>
inline List<T>::~List()
{
	m_first = nullptr;
	m_last = nullptr;
}

template<typename T>
inline void List<T>::destroy()
{
	Node<T>* nodeToDelete = m_first;
	Node<T>* nextNode;
	while(m_nodeCount != 0)
	{

		nextNode = nodeToDelete->next;
		nodeToDelete = nullptr;
		m_nodeCount--;
		nodeToDelete = nextNode;
	}
	m_first = nullptr;
	m_last = nullptr;
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return m_first;
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return m_last;
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	for (Node<T>* i = m_first; i != nullptr; i = i->next)
	{
		if (i->data == object)
			return true;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//Creates a new Node
	Node<T>* newNode = new Node<T>(value);

	//Make the first node the new node's next
	newNode->next = m_first;

	//If a first node exists
	if(m_first != nullptr)
		//Make the first node's previous the new node
		newNode->next->previous = newNode;

	//Make the new node the first node
	m_first = newNode;

	//If there is no last node
	if (m_last == nullptr)
		//Make the new node the last node
		m_last = newNode;

	//Increment the node count
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Creates a new Node
	Node<T>* newNode = new Node<T>(value);

	//Makes the last node the new node's previous
	newNode->previous = m_last;

	//If a last node exists
	if (m_last != nullptr)
		//Make the last node's next the new node
		newNode->previous->next = newNode;

	//Make the new node the last node
	m_last = newNode;

	//If there is no first node
	if (m_first == nullptr)
		//Make the new node the first node
		m_first = newNode;

	//Increment the node count
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//Return false is the index is out of bounds
	if (index < 0 || index > m_nodeCount)
		return false;

	//Create a node using the first node
	Node<T>* node = m_first;

	//Create a new node
	Node<T>* newNode = new Node<T>(value);
	
	//Increment to the index of the List
	for (int i = 1; i < index; i++)
		node = node->next;

	//if the incremented node is not the last node
	if (node != m_last)
	{
		//Make the new node's next be the incremented node's next
		newNode->next = node->next;
		//Makes the incremented node's next's previous be the nde node
		node->next->previous = newNode;
	}
	//if the incremented node is not the first node
	if (index != 0)
	{
		//Make the new node's previous be the incremented node
		newNode->previous = node;
		//Makes the incremented node's next be the new node
		node->next = newNode;
	}

	//If the index is at the start of the list
	if (index == 0)
	{
		//If the first exists
		if (m_first != nullptr)
		{
			//Make the incremented node's previous become the new node
			node->previous = newNode;
			//Makes the new node's next become the incremented node
			newNode->next = node;
		}

		//Make the new node the first node
		m_first = newNode;
	}

	//If the index is at the end of the list
	if(index == m_nodeCount)
		//Make the new node the last node
		m_last = newNode; 

	//Increment the node counter
	m_nodeCount++;

	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Return false if the value is null
	if (value == NULL)
		return false;

	bool nodeRemoved = false;
	int numberOfRemovedNodes = 0;
	Node<T>* indexNode = m_first;
	for (int i = 0; i
		< m_nodeCount; i++)
	{
		//If the data of the node at the current index is equal to the value
		if (indexNode->data == value)
		{
			//If the node is not the last node
			if(indexNode != m_last)
				//Set the node's next's previous to be the node's previous
				indexNode->next->previous = indexNode->previous;
			//If the node is the last node but not the first node
			else if(indexNode != m_first)
				//Make the nodes previous be the last node
				m_last = indexNode->previous;

			//If the node is not the first node
			if (indexNode != m_first)
				//Set the node's next's previous to be the node's next
				indexNode->previous->next = indexNode->next;
			//If the node is the first node but not the last node
			else if (indexNode != m_last)
				//Make the node's next be the first node
				m_first = indexNode->next;

			//If the node is the only node
			if (indexNode == m_first && indexNode == m_last)
			{
				//Make both the first and last nodes null
				m_first = nullptr;
				m_last = nullptr;
			}

			indexNode = nullptr;
			nodeRemoved = true;
			//Increment the number of nodes removed
			numberOfRemovedNodes++;
		}
		//Increment the node
		indexNode = indexNode->next;
	}
	//Subtract the number of removed nodes from the node count
	m_nodeCount -= numberOfRemovedNodes;
	return nodeRemoved;
}

template<typename T>
inline void List<T>::print() const
{
	Node<T>* indexNode = m_first;
	for (int i = 0; i < m_nodeCount; i++)
	{
		std::cout << indexNode->data << std::endl;
		indexNode = indexNode->next;
	}
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return m_first == nullptr && m_last == nullptr && m_nodeCount == 0;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	for (int i = 0; i < index; i++)
		iter++;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	Node<T>* iterNode = new Node<T>();
	m_first = iterNode;
	Node<T>* copyNode = otherList.m_first;
	for (int i = 0; i < otherList.getLength(); i++)
	{
		iterNode->data = copyNode->data;
		iterNode->next = new Node<T>();
		iterNode->next->previous = iterNode;
		iterNode = iterNode->next;
		copyNode = copyNode->next;
		iterNode->previous->next = iterNode;
	}
	m_last = iterNode;
	m_nodeCount = otherList.getLength();
	return *this;
}

template<typename T>
inline void List<T>::sort()
{
	//Create a new node equal to the first node
	Node<T>* firstNode = m_first;
	for (int i = 1; i < m_nodeCount; i++)
	{
		//Create a second new node equal to the second node
		Node<T>* secondNode = firstNode->next;
		for (int j = 0 + i; j < m_nodeCount; j++)
		{
			//If the first node's data is greater than the second's data
			if (firstNode->data > secondNode->data)
			{
				//Swap the two values
				T temp = secondNode->data;
				secondNode->data = firstNode->data;
				firstNode->data = temp;
			}
			//Increment the second node
			secondNode = secondNode->next;
		}
		//Increment the first node
		firstNode = firstNode->next;
	}
}
