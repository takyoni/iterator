#include "Cluster.h"
#include <iostream>
using namespace std;

Cluster::~Cluster()
{
    delete[] content;
}

Cluster::Cluster(BYTE* data, unsigned int num, unsigned int ClusterSize)
{
    content = data;
    //std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
    clusterNum = num;
}
