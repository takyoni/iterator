#include "Cluster.h"
#include <iostream>
using namespace std;

char Cluster::Print()
{
    return content[0];
}

Cluster::~Cluster()
{
    delete[] content;
}

Cluster::Cluster(unsigned int clusterSize)
{
    content = new BYTE[clusterSize];
}
