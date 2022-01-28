#pragma once
#include "List.h"
#include "Node.h"
class Engine
{
public:
	void run();
	void start();
	void update();
	void end();

private:
	bool m_applicationShouldClose;
	List<int> m_list;
};

