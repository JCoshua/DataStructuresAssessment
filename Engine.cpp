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
}

void Engine::end()
{
}
