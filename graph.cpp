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

void adjacentTable::insert(char* newlabel)
{
  int empty;
  empty = searchEmpty();

  if (empty != -1)
    {
      strcpy(table[empty].vdata.label, newlabel);
    }
}

void adjacentTable::print()
{
  for (int i = 0; i < 20; i++)
    {
      if (strcmp(table[i].vdata.label, "") != 0)
	{
	  cout << table[i].vdata.label << ":" << endl;
	}
    }
}
