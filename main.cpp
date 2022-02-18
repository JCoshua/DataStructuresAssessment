// DataStructuresAssessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"

int main()
{
	bool m_applicationShouldClose = false;
	List<int> m_list;

	//This is a simple UI to help the user to interact with the list
	//The UI is not amazing but it is more efficency over style.
	//The user just uses the numpad to go through the menus as well as to add and remove numbers
	while (!m_applicationShouldClose)
	{
		int input = -1;
		std::cout << "Select an option" << std::endl;
		std::cout << "1. Add Number" << std::endl;
		std::cout << "2. Remove Number" << std::endl;
		std::cout << "3. Sort the List" << std::endl;
		std::cout << "4. Reset the list" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cin >> input;
		system("cls");
		if (input == 1)
		{
			std::cout << "Select an option" << std::endl;
			std::cout << "1. Add to front" << std::endl;
			std::cout << "2. Add to back" << std::endl;
			std::cout << "3. Add to specific location" << std::endl;
			std::cin >> input;
			system("cls");

			if (input == 1)
			{
				std::cout << "Please insert a Number" << std::endl;
				std::cin >> input;
				m_list.pushFront(input);
				system("cls");
				std::cout << "Number Added" << std::endl;
			}
			else if(input == 2)
			{
				std::cout << "Please insert a Number" << std::endl;
				std::cin >> input;
				m_list.pushBack(input);
				system("cls");
				std::cout << "Number Added" << std::endl;
			}
			else if (input == 3)
			{
				int secondInput;
				std::cout << "Please insert a Number" << std::endl;
				std::cin >> input;

				std::cout << "Please insert the numerical location in the list the value will be placed" << std::endl;
				std::cin >> secondInput;
				
				m_list.insert(input, secondInput);
				system("cls");
				std::cout << "Number Added" << std::endl;
			}
			else
				std::cout << "Invalid Input" << std::endl;
		}
		else if (input == 2)
		{
			std::cout << "Please insert a Number" << std::endl;
			std::cin >> input;
			m_list.remove(input);
			system("cls");
			std::cout << "Number Removed" << std::endl;
		}
		else if (input == 3)
		{
			m_list.sort();
			system("cls");
			std::cout << "List Sorted" << std::endl;
		}
		else if (input == 4)
		{
			m_list.destroy();
			m_list.initialize();
			system("cls");
			std::cout << "List Reset" << std::endl;
		}
		else if (input == 5)
			m_applicationShouldClose = true;
		else
		{
			system("cls");
			std::cout << "Invalid Input" << std::endl;
		}

		if (!m_applicationShouldClose)
		{
			m_list.print();
			system("pause");
			system("cls");
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
