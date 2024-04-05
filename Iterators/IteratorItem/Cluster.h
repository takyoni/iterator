#pragma once
#include <iostream>
#include "windows.h"
using namespace std;

class Cluster
{
private:
	unsigned int clusterNum;
	BYTE* content;
public:
	BYTE* GetContent() { return content; };
	unsigned int GetNum() const { return clusterNum; };
	Cluster(BYTE* data, unsigned int num);
	~Cluster();
};

