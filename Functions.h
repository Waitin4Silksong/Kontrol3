#pragma once
#include <iostream>
#include <cstring>
#include "Tasks.h"

struct Actions
{
	Task MaxTasks[50]; // max amount of possible tasks
	Task task; // for creating new task
	int amount; // current amount of tasks

	void addTask() // adding a task
	{
		if (amount <= 50) {
			std::cout << "Enter task info." << std::endl;
			std::cout << "Name: ";
			std::cin >> task.name;
			std::cout << "Priority: ";
			std::cin >> task.prior;
			std::cout << "Task description: ";
			std::cin >> task.descrip;
			std::cout << "Date and time (DD.MM.YYYY HH:MM): ";
			std::cin >> task.datetime;
			MaxTasks[amount++] = task; // <- for some reason this line makes error that blocks me from working later with code. Functions all are working though
			std::cout << "Task added successfuly.";
		}
		else {
			std::cout << "Too many tasks.";
		}
	} 

	void deleteTask(int taskNum) // deleting task
	{
		if (taskNum > 0 && taskNum <= amount) {
			for (int i = taskNum - 1; i < amount - 1; i++)
			{
				MaxTasks[i] = MaxTasks[i + 1];
			}
			amount--; // simple massive deleting
			std::cout << "Task deleted successfuly.";
		}
		else {
			std::cout << "Incorrect input.";
		}
	}

	void editTask(int taskNum) // editing task
	{
		if (amount > 0) {
			if (taskNum > 0 && taskNum <= amount) {
				Task& editedTask = MaxTasks[taskNum - 1]; // creating adress with new info to edit task
				std::cout << "Enter new info." << std::endl;
				std::cout << "Name: ";
				std::cin >> editedTask.name;
				std::cout << "Priority: ";
				std::cin >> editedTask.prior;
				std::cout << "Task description: ";
				std::cin >> editedTask.descrip;
				std::cout << "Date and time (DD.MM.YYYY HH:MM): ";
				std::cin >> editedTask.datetime;
				std::cout << "Task edited successfuly.";
			}
			else {
				std::cout << "Incorrect input.";
			}
		}
		else {
			std::cout << "No tasks to edit. Please add task first.";
		}
	}

	void searchName(const char* name) // searching by name
	{
		for (size_t i = 0; i < amount; i++)
		{
			if (std::strstr(MaxTasks[i].name, name) != nullptr) { //  std::strstr is function that looks for specific part of line (here it's looking for inputed "name" among all named)
				std::cout << "Name: " << MaxTasks[i].name << std::endl;
				std::cout << "Priority: " << MaxTasks[i].prior << std::endl;
				std::cout << "Task description: " << MaxTasks[i].descrip << std::endl;
				std::cout << "Date and time (DD.MM.YYYY HH:MM): " << MaxTasks[i].datetime << std::endl << std::endl;
			}
		}
	}
	void searchPriority(int prior) // searching by priority
	{
		for (size_t i = 0; i < amount; i++)
		{
			if (MaxTasks[i].prior == prior) {
				std::cout << "Name: " << MaxTasks[i].name << std::endl;
				std::cout << "Priority: " << MaxTasks[i].prior << std::endl;
				std::cout << "Task description: " << MaxTasks[i].descrip << std::endl;
				std::cout << "Date and time (DD.MM.YYYY HH:MM): " << MaxTasks[i].datetime << std::endl << std::endl;
			}
		}
	}
	void searchDescrip(const char* descrip) // searching by description
	{
		for (size_t i = 0; i < amount; i++)
		{
			if (std::strstr(MaxTasks[i].descrip, descrip) != nullptr) {
				std::cout << "Name: " << MaxTasks[i].name << std::endl;
				std::cout << "Priority: " << MaxTasks[i].prior << std::endl;
				std::cout << "Task description: " << MaxTasks[i].descrip << std::endl;
				std::cout << "Date and time (DD.MM.YYYY HH:MM): " << MaxTasks[i].datetime << std::endl << std::endl;
			}
		}
	}
	void searchDateTime(const char* datetime) // searching be date and time
	{
		for (size_t i = 0; i < amount; i++)
		{
			if (std::strstr(MaxTasks[i].name, datetime) != nullptr) {
				std::cout << "Name: " << MaxTasks[i].name << std::endl;
				std::cout << "Priority: " << MaxTasks[i].prior << std::endl;
				std::cout << "Task description: " << MaxTasks[i].descrip << std::endl;
				std::cout << "Date and time (DD.MM.YYYY HH:MM): " << MaxTasks[i].datetime << std::endl << std::endl;
			}
		}
	}

	void showTasksDay(const char* day) // shows tasks for inputed day
	{
		std::cout << "All tasks for " << day << ":" << std::endl;
		for (size_t i = 0; i < amount; i++)
		{
			if (std::strstr(MaxTasks[i].datetime, day) != nullptr) {
				std::cout << "Name: " << MaxTasks[i].name << std::endl;
				std::cout << "Priority: " << MaxTasks[i].prior << std::endl;
				std::cout << "Task description: " << MaxTasks[i].descrip << std::endl;
				std::cout << "Date and time (DD.MM.YYYY HH:MM): " << MaxTasks[i].datetime << std::endl << std::endl;
			}
			else {
				std::cout << "Invalid data";
			}
		}
	}
	void showTasksWeek(const char* firstday, const char* lastday) // shows tasks for inputed week
	{
		std::cout << "All tasks from " << firstday << " to " << lastday << ":" << std::endl;
		for (size_t i = 0; i < amount; i++)
		{
			if (strcmp(MaxTasks[i].datetime, firstday) >= 0 && strcmp(MaxTasks[i].datetime, lastday) <= 0) { //std::strcmp works similar to std::strstr, but for 2 objects
				std::cout << "Name: " << MaxTasks[i].name << std::endl;
				std::cout << "Priority: " << MaxTasks[i].prior << std::endl;
				std::cout << "Task description: " << MaxTasks[i].descrip << std::endl;
				std::cout << "Date and time (DD.MM.YYYY HH:MM): " << MaxTasks[i].datetime << std::endl << std::endl << std::endl;
			}
			else {
				std::cout << "Invalid data";
			}
		}
	}
	void showTasksMonth(const char* month) // shows tasks for inputed month
	{
		std::cout << "All tasks for " << month << ":" << std::endl;
		for (size_t i = 0; i < amount; i++)
		{
			if (std::strstr(MaxTasks[i].datetime, month) != nullptr) {
				std::cout << "Name: " << MaxTasks[i].name << std::endl;
				std::cout << "Priority: " << MaxTasks[i].prior << std::endl;
				std::cout << "Task description: " << MaxTasks[i].descrip << std::endl;
				std::cout << "Date and time (DD.MM.YYYY HH:MM): " << MaxTasks[i].datetime << std::endl << std::endl << std::endl;
			}
			else {
				std::cout << "Invalid data";
			}
		}
	}

	void sortByPrior() // sorting tasks by priority
	{
		for (int i = 0; i < amount - 1; i++)
		{
			for (int j = 0; j < amount - i - 1; j++) // used bubble sorting 'cos it's easier
			{
				if (MaxTasks[j].prior > MaxTasks[j + 1].prior) {
					std::swap(MaxTasks[j], MaxTasks[j + 1]);
				}
			}
		}
	}
	void sortByDateTime() // sorting tasks by date and time
	{
		for (int i = 0; i < amount - 1; i++)
		{
			for (int j = 0; j < amount - i - 1; j++)
			{
				if (std::strcmp(MaxTasks[j].datetime, MaxTasks[j + 1].datetime) > 0) {
					std::swap(MaxTasks[j], MaxTasks[j + 1]);
				}
			}
		}
	}

	void showTasks() // much compact "show" function, where you can choose sorting and then date
	{
		std::cout << "Sort tasks by:" << std::endl;
		std::cout << "Priority - 1" << std::endl;
		std::cout << "Date and time - 2" << std::endl;
		int sort;
		std::cin >> sort;
		switch (sort) {
		case 1:
			sortByPrior();
			break;
		case 2:
			sortByDateTime();
			break;
		default:
			std::cout << "Invalid input";
		}
		std::cout << std::endl << "Show tasks for:" << std::endl;
		std::cout << "Day - 1" << std::endl;
		std::cout << "Week - 2" << std::endl;
		std::cout << "Month - 3" << std::endl;
		int date;
		std::cin >> date;
		switch (date) {
		case 1:
			std::cout << "Enter day (DD.MM.YYYY): ";
			char day[10];
			std::cin >> day;
			showTasksDay(day);
			break;
		case 2:
			std::cout << "Enter start of the week (DD.MM.YYYY): ";
			char day1[10];
			std::cin >> day1;
			std::cout << std::endl << "Enter end of the week (DD.MM.YYYY): ";
			char day2[10];
			std::cin >> day2;
			showTasksWeek(day1, day2);
			break;
		case 3:
			std::cout << "Enter month (MM.YYYY): ";
			char month[7];
			std::cin >> month;
			showTasksMonth(month);
			break;
		default:
			std::cout << "Invalid input";
		}
	}

};