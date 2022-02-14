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
	
}

void Engine::update()
{
	while (m_list.getLength() < 20)
	{
		int random = rand();
		m_list.pushFront(random);
	}
	m_list.print();
	m_list.sort();
	system("pause");
	system("cls");
	m_2List = m_list;
	m_list.destroy();
	m_2List.print();
	system("pause");
	system("cls");
}

void Engine::end()
{
}
