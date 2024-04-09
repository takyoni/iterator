#include "FS.h"
#include "windows.h"
#include "Cluster.h"
#include <stdexcept>
bool FS::Init(LPCWSTR fileName) {
    fileHandler = CreateFileW(
        fileName,    // Drive to open
        GENERIC_READ,           // Access mode
        FILE_SHARE_READ | FILE_SHARE_WRITE,        // Share Mode
        NULL,                   // Security Descriptor
        OPEN_EXISTING,          // How to create
        0,                      // File attributes
        NULL);                  // Handle to template

    if (fileHandler == INVALID_HANDLE_VALUE)
    {
        throw std::invalid_argument("Error INVALID_HANDLE_VALUE!");
        return false;
    }
    if (!ReadClusterSize()) {
        throw std::invalid_argument("Error INVALID_HANDLE_VALUE!");
        return false;
    }
    return true;
}
void FS::ReadCluster(Cluster* item, unsigned int clusterNum)
{
    DWORD bytesRead;
    DWORD bytesToRead = clusterSize;
    LARGE_INTEGER sectorSizeOffset;
    sectorSizeOffset.QuadPart = static_cast<LONGLONG>(clusterNum) * clusterSize; // �������� ��� ������� �������
    BYTE* arr = new BYTE[clusterSize];
    // ������������� ��������
    if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
        throw std::invalid_argument("Set FilePointer error");
        CloseHandle(fileHandler);
//        return false;
    }
    if (!ReadFile(fileHandler, arr, clusterSize, &bytesRead, NULL))
    {
        throw std::invalid_argument("ReadFile error");
        CloseHandle(fileHandler);
//        return false;
    }
    item->SetClusterNum(clusterNum);
    item->SetContent(arr);
    //delete[] arr;
}
bool FS::ReadClusterSize()
{
    return false;
}
FS::~FS() {
	CloseHandle(fileHandler);
}
