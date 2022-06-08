#include <iostream>
#include <cstring>
#include <cctype>
#include "graph.h"

using namespace std;

adjacentTable::adjacentTable ()
{
  for (int i = 0; i < 20; i++)
    {
      strcpy(table[i].vdata.label, "");
      table[i].vdata.location = -1;
      table[i].listhead = NULL;
    }
}

adjacentTable::~adjacentTable() {}

int adjacentTable::searchEmpty()
{
  for (int i = 0; i < 20; i++)
    {
      if (strcmp(table[i].vdata.label, "") == 0)
	{
	  return i;
	}
    }
  return -1;
}

void adjacentTable::insertV(char* newlabel)
{
  int place;
  place = searchEmpty();

  if (place != -1)
    {
      strcpy(table[place].vdata.label, newlabel);
      table[place].vdata.location = place;
    }
}

void adjacentTable::print()
{
  for (int i = 0; i < 20; i++)
    {
      if (strcmp(table[i].vdata.label, "") != 0)
	{
	  cout << table[i].vdata.label << ": ";
	  edgenode* current = table[i].listhead;
	  while (current != NULL)
	    {
	      cout << current->edata.end.label << " ";
	      current = current->next;
	    }
	  cout << endl;
	}
    }
}

void adjacentTable::insertE(char* newStart, char* newEnd, int newWeight)
{
  edge temp;
  strcpy(temp.start.label, newStart);
  strcpy(temp.end.label, newEnd);
  temp.weight = newWeight;

  edgenode* newNode = new edgenode();
  newNode->edata = temp;

  int svalue;
  svalue = findLocation(newStart);

  if (table[svalue].listhead == NULL)
    {
      table[svalue].listhead = newNode;
      table[svalue].listhead->next = NULL;
    }
  else
    {
      cout << "line 82" << endl;
      edgenode* temph = table[svalue].listhead;
      table[svalue].listhead = newNode;
      table[svalue].listhead->next = temph;
    }

}

int adjacentTable::findLocation(char* nlabel)
{

  for (int i = 0; i < 20; i++)
    {
      if (strcmp(table[i].vdata.label, nlabel) == 0)
	{
	  return i;
	}
    }
  return -1;
  
}

void adjacentTable::deleteE(char* delStart, char* delEnd)
{
  
  int delplace;
  delplace = findLocation(delStart);
  edgenode* previous = table[delplace].listhead;
  edgenode* current = table[delplace].listhead;
  if (strcmp(table[delplace].listhead->edata.end.label, delEnd) == 0)
    {
      edgenode* temp = table[delplace].listhead;
      table[delplace].listhead = table[delplace].listhead->next;
      delete temp;
    }
  else
    {
      current = current->next;
      while (current  != NULL)
	{
	  if (strcmp(current->edata.end.label, delEnd) == 0)
	    {
	      edgenode* temp = current;
	      previous->next = current->next;
	      delete temp;
	      return;
	    }
	  previous = current;
	  current = current->next;
	}
	  return;
    }
  
}

void adjacentTable::deleteV(char* delStartv)
{
  int delp;
  delp = findLocation(delStartv);
  edgenode* previous = table[delp].listhead;
  edgenode* current = table[delp].listhead;

  //delete every edge with the delStartv as start vertex
  if (strcmp(table[delp].listhead->edata.start.label, delStartv) == 0)
    {
      while (table[delp].listhead != NULL)
	{
	  edgenode* temp = table[delp].listhead;
	  table[delp].listhead = table[delp].listhead->next;
	  delete temp;
	}
      table[delp].vdata.location = -1;
      strcpy(table[delp].vdata.label, "");
    }

  //delete every edge with the delStartv as the end vertex
  for (int i = 0; i < 20; i++)
    {
      if (table[i].vdata.location != -1)
	{
	  if (table[i].listhead != NULL)
	    {
	      edgenode* previous = table[i].listhead;
	      edgenode* current = table[i].listhead;
	      if (strcmp(table[i].listhead->edata.end.label, delStartv) == 0)
		{
		  edgenode* temp = table[i].listhead;
		  table[i].listhead = table[i].listhead->next;
		  delete temp;
		}
		else
		  {
		    current = current->next;
		    while (current != NULL)
		      {
			if (strcmp(current->edata.end.label, delStartv) == 0)
			  {
			    edgenode* temp = current;
			    previous->next = current->next;
			    delete temp;
			    return;
			  }
			previous = current;
			current = current->next;
		      }
		  }
	    }
	}
    }
}
