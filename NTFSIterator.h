#pragma once
#include "Iterator.h"
#include "NTFS.h"
class NTFSIterator :
    public Iterator<Cluster>
{
private:
    NTFS* ntfs;
    unsigned int Count;
    unsigned int Cursor;
public:
    NTFSIterator(NTFS* fsItem) :Iterator(fsItem->ClusterCount()) {
        ntfs = fsItem;
        Count = ntfs->ClusterCount();
        Cursor = 0;
    }
    void First() { Cursor = 0; }
    void Next() { Cursor ++; }
    bool IsDone() const { return (Cursor >= Count); }
    Cluster GetCurrent();
};

