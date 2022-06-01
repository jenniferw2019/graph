#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

adjacentTable::adjacentTable
{
  for (int i = 0; i < 20; i++)
    {
      strcpy(adjacent[i].vdata.label, "");
      adjacent[i].vdata.location = -1;
      adjacent[i].listhead = NULL;
    }
}

adjacentTable::~adjacentTable() {}

int adjacentTable::searchEmpty()
{
  for (int i = 0; i < 20; i++)
    {
      if (strcmp(adjacent[i].vdata.label, ""))
	{
	  return i;
	}
      else
	{
	  cout << "No empty vertex" << endl;
	}
    }
}


