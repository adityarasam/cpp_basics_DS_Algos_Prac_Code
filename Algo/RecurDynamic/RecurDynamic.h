#ifndef RECURDYNAMIC_H_INCLUDED
#define RECURDYNAMIC_H_INCLUDED

#include <iostream>
#include <vector>
#include <utility>     //pair



using namespace std;

/*----------------RECURSIVE--------------------*/
int fibonacci(int i);
int countWays(int n);                                                   //---------------CHILD STEPS---------------------------

vector<pair<int,int>> getPath (vector<vector<bool>> maze);              //---------------ROBOT GRID---------------------------
vector<vector<bool>> createGirdMaze(int size, bool test);

int findMagicFast(vector<int> &array);                                  //---------------Finding Magic number-----------------

/*----------------RECURSIVE DYNAMIC------------*/
int fibonacciDyn(int n);
int CountWaysDyn(int n);

#endif