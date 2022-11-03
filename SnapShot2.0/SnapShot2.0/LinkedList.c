#include <stdio.h>
#pragma warning(disable : 4996)

#include "LinkedList.h"
#include "LogFile.h"
#include "Structs.h"


void DllLinkedList(struct Dll* currentDLL)
{
	if (HeadDll == NULL)
	{
		HeadDll = currentDLL;
		TailDll = currentDLL;
		currentDLL->next = NULL;
		currentDLL->prev = NULL;
	}
	else
	{
		TailDll->next = currentDLL;
		currentDLL->prev = TailDll;
		currentDLL->next = NULL;
		TailDll = currentDLL;
	}
}

void ProcessLinkedList(struct Process* currentProcess)
{
	if (HeadPr == NULL)
	{
		HeadPr = currentProcess;
		TailPr = currentProcess;
		currentProcess->next = NULL;
		currentProcess->prev = NULL;
	}
	else
	{
		TailPr->next = currentProcess;
		currentProcess->prev = TailPr;
		currentProcess->next = NULL;
		TailPr = currentProcess;
	}
}

void AddNewDllToLinkedList(struct Dll* prevDLL, struct Dll* currentDLL)
{
	prevDLL->next = currentDLL;
	currentDLL->prev = prevDLL;
	currentDLL->next = NULL;
	TailDll = currentDLL;
}

void AddNewProcessToLinkedList(struct Process* prevProcess, struct Process* currentProcess)
{
	prevProcess->next = currentProcess;
	currentProcess->prev = prevProcess;
	currentProcess->next = NULL;
	TailPr = currentProcess;
}

//Initializing global variables
int snapShotIDCounter = 1;
struct SnapShot* HeadS = NULL;
struct SnapShot* TailS = NULL;
struct SnapShot* SnapShotLinkedList(struct SnapShot* currentSnapShot)
{
	if (HeadS == NULL)
	{
		HeadS = currentSnapShot;
		TailS = currentSnapShot;
		currentSnapShot->next = NULL;
		currentSnapShot->prev = NULL;
	}
	else
	{
		TailS->next = currentSnapShot;
		currentSnapShot->prev = TailS;
		currentSnapShot->next = NULL;
		TailS = currentSnapShot;
	}

	snapShotIDCounter++;
	HeadSnap = HeadS;
	TailSnap = TailS;
	return HeadS;
}