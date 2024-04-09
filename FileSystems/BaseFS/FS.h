#include "windows.h"
#include "Cluster.h"
#pragma once
class FS
{
protected:
	HANDLE fileHandler = NULL;
	unsigned int clusterSize = {0};
	unsigned int clusterCount = { 0 };
	virtual bool ReadClusterSize();
public:
	bool Init(LPCWSTR);
	void ReadCluster(Cluster* asd, unsigned int);
	unsigned int ClusterSize() const { return clusterSize; };
	unsigned int ClusterCount() const { return clusterCount; };
	virtual ~FS();
};