#pragma once
#include <iostream>
#include "windows.h"
using namespace std;

class Cluster
{
private:
	unsigned int clusterSize;
	BYTE* content;
public:
	char Print();
	BYTE* GetContent() { return content; };
	~Cluster();
	Cluster(unsigned int clusterSize);
};

