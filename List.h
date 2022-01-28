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
	void sort();
private:
	Node<T>* m_first;
	Node<T>* m_last;
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
	initialize();
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
	for (Node<T>* i = m_first; i != nullptr; i++)
	{
		if (i->data == object)
			return true;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	newNode->next = m_first;
	if(m_first != nullptr)
	newNode->next->previous = newNode;
	m_first = newNode;
	if (m_last == nullptr)
		m_last = newNode;
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	newNode->previous = m_last;
	if (m_last != nullptr)
		newNode->previous->next = newNode;
	m_last = newNode;
	if (m_first == nullptr)
		m_first = newNode;
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	if (index < 0 || index > m_nodeCount)
		return false;

	Node<T>* node = m_first;
	Node<T>* newNode = new Node<T>(value);
	
	for (int i = 1; i < index; i++)
		node = node->next;

	if (node != m_last)
	{
		newNode->next = node->next;
		node->next->previous = newNode;
	}
	if (index != 0)
	{
		newNode->previous = node;
		node->next = newNode;
	}
	if (index == 0)
	{
		m_first = newNode;
		node->previous = newNode;
		newNode->next = node;
	}
	if(index == m_nodeCount)
		m_last = newNode; 
	m_nodeCount++;

	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	if (value == NULL)
		return false;

	bool nodeRemoved = false;
	Node<T>* indexNode = m_first;
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (indexNode->data == value)
		{
			indexNode->next->previous = indexNode->previous;
			indexNode->previous->next = indexNode->next;
			nodeRemoved = true;
			m_nodeCount--;

		}
		indexNode = indexNode->next;
	}

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
	m_first = otherList.m_first;
	m_last = otherList.m_last;
	m_nodeCount = otherList.m_nodeCount;
}

template<typename T>
inline void List<T>::sort()
{
	Node<T>* firstNode = m_first;
	for (int i = 1; i < m_nodeCount; i++)
	{
		Node<T>* secondNode = firstNode->next;
		for (int j = 0 + i; j < m_nodeCount; j++)
		{
			if (firstNode->data > secondNode->data)
			{
				T temp = secondNode->data;
				secondNode->data = firstNode->data;
				firstNode->data = temp;
			}
			secondNode = secondNode->next;
		}
		firstNode = firstNode->next;
	}
}
