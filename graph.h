#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

struct vertex
{
  char label[20];
  int location;
};

struct edge
{
  vertex start;
  vertex end;
  int weight;
};

struct edgenode
{
  edge edata;
  edgenode* next;
};

struct adjacent
{
  vertex vdata;
  edgenode* listhead;
};

class adjacentTable
{
 public:
  adjacentTable();
  ~adjacentTable();
  int searchEmpty();
  void insertV(char* newlabel);
  void print();
  void insertE(char*  newStart, char* newEnd, int newWeight);
  int findLocation(char* nlabel);
  void deleteE(char* delStart, char* delEnd);
  void deleteV(char* delStartv);

  
 private:
  adjacent table[20];
  
};

#endif
