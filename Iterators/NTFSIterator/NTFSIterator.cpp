#include "NTFSIterator.h"

Cluster NTFSIterator::GetCurrent()
{
    return ntfs->ReadCluster(Cursor);
}
