#include <iostream>
#include <cstring>
#include <cctype>
#include "graph.h"

using namespace std;

int main()
{
  bool runProgram = true;
  char input[10];
  adjacentTable myGraph;

  while (runProgram == true)
    {
      cout << "Type ADDV, PRINT" << endl;
      cin.get(input, 10);
      cin.get();

      if (strcmp(input, "ADDV") == 0)
	{
	  char nlabel[30];
	  cout << "Type label" << endl;
	  cin.get(nlabel, 30);
	  cin.get();

	  myGraph.insert(nlabel);
	}
      else if (strcmp(input, "PRINT") == 0)
	{
	  myGraph.print();
	}
    }
  
}
