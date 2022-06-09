//.cpp for graph
#include <iostream>
#include <cstring>
#include <cctype>
#include <climits>
#include <stack>
#include "graph.h"

using namespace std;

//build table
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

//search if table is empty
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

//insert vertex
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

//print table
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
	      cout << current->edata.end.label << "(";
	      cout << current->edata.weight << ") ";
	      current = current->next;
	    }
	  cout << endl;
	}
    }
}

//insert edge
void adjacentTable::insertE(char* newStart, char* newEnd, int newWeight)
{
  edge temp;
  temp.start.location = findLocation(newStart);
  temp.end.location = findLocation(newEnd);
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
      edgenode* temph = table[svalue].listhead;
      table[svalue].listhead = newNode;
      table[svalue].listhead->next = temph;
    }

}

//find location of a vertex
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

//delete edge
void adjacentTable::deleteE(char* delStart, char* delEnd)
{
  if(findLocation(delStart) == -1 || findLocation(delEnd) == -1)
    {
      cout << "not a valid edge" << endl;
      return;
    }
  
  int delplace;
  delplace = findLocation(delStart);
  edgenode* previous = table[delplace].listhead;
  edgenode* current = table[delplace].listhead;

  if(table[delplace].listhead == NULL)
    {
      cout << "edge not exists." << endl;
      return;
    }
  
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

//delete vertex
void adjacentTable::deleteV(char* delStartv)
{
  if(findLocation(delStartv) == -1)
    {
      cout << "not a valid vertex" << endl;
      return;
    }
  
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

//find location of vertex with smallest pathvalue
int adjacentTable::smallest()
{
  int smallest = INT_MAX;
  int slocation;
  
  for (int i = 0; i < 20; i++)
    {
      if (table[i].vdata.location != -1)
	{
	  if (table[i].vdata.pathvalue <= smallest && table[i].vdata.visited == false)
	    {
	      smallest = table[i].vdata.pathvalue;
	      slocation = i;
	    }
	}
    }
  return slocation;  
}

//find shortest path
void adjacentTable::shortestPath(char* sStart, char* sEnd)
{

  for (int i = 0; i < 20; i++)
    {
      if (table[i].vdata.location != -1)
	{
	  table[i].vdata.visited = false;
	  table[i].vdata.pathvalue = INT_MAX;
	  table[i].vdata.prelocation = -1;
	}
    }

  int curlocation = findLocation(sStart);
  table[curlocation].vdata.pathvalue = 0;
  
  while (curlocation != findLocation(sEnd))
    {
      edgenode* curedge = table[curlocation].listhead;
      while (curedge != NULL)
	{
	  int templocation = curedge->edata.end.location;
	  int tempvalue = curedge->edata.weight + table[curlocation].vdata.pathvalue;
	  if (tempvalue < table[templocation].vdata.pathvalue)
	    {
	      table[templocation].vdata.pathvalue = tempvalue;
	      table[templocation].vdata.prelocation = curlocation;
	    }
	  curedge = curedge->next;
	}
      
      curlocation = smallest();
      table[curlocation].vdata.visited = true;
    }

  //check if there is a path exists
  if(table[curlocation].vdata.pathvalue == INT_MAX)
    {
      cout << "no path exists!!" << endl;
      return;
    }

  //there is a shortest path, output its information
  cout << "the shortest pathvalue is: " << table[curlocation].vdata.pathvalue << endl;
  stack<char*> output;
  while (curlocation != findLocation(sStart))
    {
      output.push(table[curlocation].vdata.label);
      curlocation = table[curlocation].vdata.prelocation;
    }
  output.push(table[curlocation].vdata.label);

  while (!output.empty())
    {
      cout << output.top() << " ";
      output.pop();
    }
  cout << endl;
}
