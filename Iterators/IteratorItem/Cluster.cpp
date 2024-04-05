#include "Cluster.h"
#include <iostream>
using namespace std;

Cluster::~Cluster()
{
    delete[] content;
}

Cluster::Cluster(BYTE* data, unsigned int num)
{
    clusterNum = num;
    content = data;
}
