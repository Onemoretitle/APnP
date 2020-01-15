#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define BALCONY 1
#define PARTER 2
#define HIGH 3

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <list>
#include <string>
#include <ctime>

using namespace std;


struct seatStruct
{
	const char* type;
	int price, number, hallNum, row;
};



