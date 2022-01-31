#pragma once
template<typename T>
class Node
{
public:
	Node();
	Node(T value);

	//The node after this node
	Node<T>* next;

	//The node before this node
	Node<T>* previous;

	//The data this node holds
	T data;
};

template<typename T>
inline Node<T>::Node()
{
	next = nullptr;
	previous = nullptr;
	data = T();
}

template<typename T>
inline Node<T>::Node(T value)
{
	next = nullptr;
	previous = nullptr;
	data = value;
}
