#include "Engine.h"

void Engine::run()
{
	start();

	while (!m_applicationShouldClose)
		update();

	end();
}

void Engine::start()
{
	m_list.initialize();
	m_list.pushFront(7);
	m_list.pushBack(2);
	m_list.insert(5, 1);
	m_list.insert(9, 1);
	m_list.insert(4, 4);
	m_list.insert(4, 0);
	m_list.print();
	system("pause");
	system("cls");
}

void Engine::update()
{
	m_list.sort();
	m_list.print();
	system("pause");
	system("cls");
	m_list.remove(4);
}

void Engine::end()
{
}
