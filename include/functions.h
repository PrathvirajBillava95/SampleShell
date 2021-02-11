/*
 * Simple Unix Like shell written in C++
 * Author: Prathviraj Billava
 * 
 * functions.h : header file for commmand.cpp
 *
 * helper function declaration
 */
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

int CheckIfPipeCmd(string str);
void splitSpace(string str, string *parsedCmd);

#endif
