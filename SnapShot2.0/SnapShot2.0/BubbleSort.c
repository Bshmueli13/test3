#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#include "GetProcessInfo.h"
#include "LogFile.h"
#include "Structs.h"


//Making swap between two Processes
void Replace(struct Process* dllCount)
{
	if (dllCount == NULL) //No Processes in the list
	{
		LogEvent("No need to swap. There are no Processes in the list.");
		return;
	}
	else if (dllCount->next == NULL) //One Process in the list
	{
		LogEvent("No need to swap. There is only 1 Process in the list.");
		return;
	}
	else if (dllCount == HeadPr && dllCount->next == TailPr) //2 Processes in the list: HeadP and TailP
	{
		dllCount->prev = TailPr;
		dllCount->next = NULL;
		TailPr->prev = NULL;
		TailPr->next = dllCount;
		TailPr = dllCount;
		HeadPr = dllCount->prev;
	}
	else if (dllCount == HeadPr && dllCount->next != NULL) //2 first Processes in the list
	{
		dllCount->next = dllCount->next->next;
		dllCount->next->prev->next = dllCount;
		dllCount->next->prev->prev = NULL;
		dllCount->prev = dllCount->next->prev;
		dllCount->next->prev = dllCount;
		HeadPr = dllCount->prev;
	}
	else if (dllCount->next == TailPr && dllCount->prev != NULL) //2 last Processes in the list
	{
		dllCount->prev->next = dllCount->next;
		dllCount->next->prev = dllCount->prev;
		dllCount->next->next = dllCount;
		dllCount->prev = dllCount->next;
		dllCount->next = NULL;
		TailPr = dllCount;
	}
	else //2 middle Processes
	{
		dllCount->prev->next = dllCount->next;
		dllCount->next = dllCount->next->next;
		dllCount->next->prev->prev = dllCount->prev;
		dllCount->prev = dllCount->next->prev;
		dllCount->next->prev->next = dllCount;
		dllCount->next->prev = dllCount;
	}
}

//Sorts the list
void BubbleSort()
{
	//Starting to sort the list
	struct Process* currentItem = HeadPr;
	if (currentItem == NULL)
	{
		LogError("The List is empty");
		return;
	}

	LogEvent("Swap Process");
	int counter = 1;
	while (counter != 0)
	{
		counter = 0;
		currentItem = HeadPr;

		while (currentItem != NULL)
		{
			if (currentItem->next != NULL && currentItem->DLLCount > currentItem->next->DLLCount)
			{
				Replace(currentItem);
				counter++;
				currentItem = currentItem->prev;
			}

			currentItem = currentItem->next;
		}
	}


	LogEvent("End Bubble sorting the linked list");
}
