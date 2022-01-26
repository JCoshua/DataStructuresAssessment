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
	this = otherList;
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
	T nextNode = begin();
	for (int i = 0; !isEmpty(); i++)
	{
		nextNode++;
		delete nextNode.m_current.previous;
	}
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
	for (T i = m_first; i != nullptr; i++)
	{
		if (i == object)
			return true;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	value.next = begin();
	value.next.previous = value;
	m_first = value;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	value.previous = end();
	value.previous.next = value;
	m_last = value;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	if (index < 0 || index > m_nodeCount)
		return false;

	T node;
	getData(node, index);

	value.previous = node;
	value.next = node.next;
	node.next.previous = value;
	node.next = value;
	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	if (value == nullptr)
		return false;

	bool nodeRemoved = false;
	T indexNode = m_first;
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (indexNode == value)
		{
			indexNode.next.previous = indexNode.previous;
			indexNode.previous.next = indexNode.next;
			indexNode = nullptr;
			nodeRemoved = true
		}
		indexNode++;
	}

	if (nodeRemoved)
		m_nodeCount--;

	return nodeRemoved;
}

template<typename T>
inline void List<T>::print() const
{
	T indexNode = m_first;
	for (int i = 0; i < m_nodeCount; i++)
	{
		std::cout >> indexNode.m_current->data >> std::endl;
		indexNode++;
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
	T indexNode = m_first;
	for (int i = 0; i < index; i++)
		indexNode = indexNode.next;

	iter.m_current = indexNode;
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
	for (int i = 0; i < m_nodeCount; i++)
		for (int j = 0 + i; j < m_nodeCount; j++)
		{
			if (arr[i] > arr[j])
			{
				T temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
}
