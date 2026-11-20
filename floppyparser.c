#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		printf("Not enough arguments");
		return -1;
	}
	FILE *flopPtr = fopen(argv[1], "r");
	if(flopPtr == NULL)
		return -1;
	char * version = malloc(11);
	memset(version, 0, 11);
	fread(version, 11, 1, flopPtr);
	int temp, bytesPerSect, sectPerClust, numReservedSect, numFATS, maxEntries, totSect, sectPerFAT,
	sectPerTrack, numHeads, numHiddenSect, totSecFAT32, bootSig, volID;
	char * volLabel = malloc(11);
	char * fileSystemType = malloc(8);

	fread(&bytesPerSect, 2, 1, flopPtr);
	fread(&sectPerClust, 1, 1, flopPtr);
	fread(&numReservedSect, 2, 1, flopPtr);
	fread(&numFATS, 1, 1, flopPtr);
	fread(&maxEntries, 2, 1, flopPtr);
	fread(&totSect, 2, 1, flopPtr);
	fread(&temp, 1, 1, flopPtr);
	fread(&sectPerFAT, 2, 1, flopPtr);
	fread(&sectPerTrack, 2, 1, flopPtr);
	fread(&numHeads, 2, 1, flopPtr);
	fread(&numHiddenSect, 4, 1, flopPtr);
	fread(&totSecFAT32, 4, 1, flopPtr);
	fread(&temp, 2, 1, flopPtr);
	fread(&bootSig, 1, 1, flopPtr);
	fread(&volID, 4, 1, flopPtr);
	fread(volLabel, 11, 1, flopPtr);
	fread(fileSystemType, 8, 1, flopPtr);

	printf("%-28s= %d\n", "Bytes per sector", bytesPerSect);
	printf("%-28s= %d\n", "sectPerClust", sectPerClust);
	printf("%-28s= %d\n", "Number of reserved sectors", numReservedSect);
	printf("%-28s= %d\n", "Number of FATS", numFATS);
	printf("%-28s= %d\n", "Number of root entries", maxEntries);
	printf("%-28s= %d\n", "Total sector count", totSect);
        printf("%-28s= %d\n", "Sectors per FAT", sectPerFAT);
	printf("%-28s= %d\n", "Sectors per track", sectPerTrack);
        printf("%-28s= %d\n", "Number of heads", numHeads);
	printf("%-28s= 0x%X\n", "Boot signature", bootSig);
        printf("%-28s= 0x%X\n", "Volume ID", volID);
	printf("%-28s= %s\n", "Volume Label", volLabel);
        printf("%-28s= %s\n", "File system type", fileSystemType);
	return 0;
}

