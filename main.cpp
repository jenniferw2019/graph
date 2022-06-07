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
      cout << "Type ADDV, ADDE, PRINT, DELETE_E" << endl;
      cin.get(input, 10);
      cin.get();

      if (strcmp(input, "ADDV") == 0)
	{
	  char nlabel[30];
	  cout << "Type label" << endl;
	  cin.get(nlabel, 30);
	  cin.get();

	  myGraph.insertV(nlabel);
	}
      else if (strcmp(input, "PRINT") == 0)
	{
	  myGraph.print();
	}
      else if (strcmp(input, "ADDE") == 0)
	{
	  char nstart[30];
	  char nend[30];
	  int nweight;
	  cout << "Type start vertex" << endl;
	  cin.get(nstart, 30);
	  cin.get();
	  cout << "Type end vertex" << endl;
	  cin.get(nend, 30);
	  cin.get();
	  cout << "Type weight" << endl;
	  cin >> nweight;
	  cin.get();

	  myGraph.insertE(nstart, nend, nweight);
	}
      else if (strcmp(input, "DELETE_E") == 0)
	{
	  char startdel[30];
	  char enddel[30];
	  cout << "Type start vertex of edge" << endl;
	  cin.get(startdel, 30);
	  cin.get();
	  cout << "Type end vertex of edge" << endl;
	  cin.get(enddel, 30);
	  cin.get();

	  myGraph.deleteE(startdel, enddel);
	}
    }
  
}
