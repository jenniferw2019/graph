/*
This program creates a graph. User can enter vertex and edge, delete vertex and edge.
User can also find the shortest path between two vertex.
Author: Jennifer Wang
6/8/22
 */
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
      cout << "Type ADDV, ADDE, PRINT, DELETE_E, DELETE_V, SHORTEST, QUIT" << endl;
      cin.get(input, 10);
      cin.get();

      //add vertex
      if (strcmp(input, "ADDV") == 0)
	{
	  char nlabel[30];
	  cout << "Type vertex label" << endl;
	  cin.get(nlabel, 30);
	  cin.get();

	  myGraph.insertV(nlabel);
	}
      //print table
      else if (strcmp(input, "PRINT") == 0)
	{
	  myGraph.print();
	}
      //add edge
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
	  cout << "Type a integer value weight" << endl;
	  cin >> nweight;
	  cin.get();

	  myGraph.insertE(nstart, nend, nweight);
	}
      //delete edge
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
      //delete vertex
      else if (strcmp(input, "DELETE_V") == 0)
	{
	  char startdelv[30];
	  cout << "Type vertex to delete" << endl;
	  cin.get(startdelv, 30);
	  cin.get();

	  myGraph.deleteV(startdelv);
	}
      //find shortest path
      else if (strcmp(input, "SHORTEST") == 0)
	{
	  char s[30];
	  char e[30];
	  cout << "Type start location" << endl;
	  cin.get(s, 30);
	  cin.get();
	  cout << "Type end location" << endl;
	  cin.get(e, 30);
	  cin.get();

	  myGraph.shortestPath(s, e);
	}
      //quit
      else if(strcmp(input, "QUIT") == 0)
	{
	  runProgram = false;
	}
    }
  
}
