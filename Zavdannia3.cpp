#include <iostream>
#include <cstring>
#include "Functions.h"
#include "Tasks.h"

int main()
{
	Actions actions;

	actions.showTasks();
	actions.searchPriority(1);
	actions.showTasksMonth("12.2023");
	actions.showTasks();
}
