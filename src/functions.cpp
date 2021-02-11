/*
 * Code Owner: Prathviraj Billava
 * 
 * Simple Unix Like shell written in C++
 *
 * functions.cpp : helper functions
 * 
 */

#include <string>
#include <bits/stdc++.h>
using namespace std;
#include "functions.h"

/*
 * int CheckIfPipeCmd(string str)
 * Checks if the command sting str is a piped command
 * and returns the location of pipe (|)
 */
int CheckIfPipeCmd(string str)
{
        int findPipe = str.find('|', 0);
		
	return findPipe;
}

/*
 * void splitSpace(string str, string *parsedCmd)
 * Splits the string str by the spaces and stores the 
 * splited words in parsedCmd
 *
 */
void splitSpace(string str, string *parsedCmd)
{
	istringstream ss(str);

	int i=0;

	while (ss >> parsedCmd[i++]);
}
