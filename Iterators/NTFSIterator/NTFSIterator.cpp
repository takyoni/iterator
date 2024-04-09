#include "NTFSIterator.h"

Cluster NTFSIterator::GetCurrent()
{
    Cluster* item = new Cluster();
    ntfs->ReadCluster(item, Cursor);
    return *item;
}
