#ifndef FILESYS_FAT_H
#define FILESYS_FAT_H

#include "../types.h"

namespace FAT16 {
	struct BootRecord {
	uint8_t JumpBootCode[3];
	uint8_t OEMName[8];
	uint8_t BytesPerSector[2];
	uint8_t SectorPerCluster;
	uint8_t ReservedSectorCount[2];
	uint8_t NumberofFATs;
	uint8_t RootDirectoryEntryCount[2];
	uint8_t TotalSector16[2];
	uint8_t Media;
	uint8_t FATSize16[2];
	uint8_t SectorPerTrack[2];
	uint8_t NumberOfHeads[2];
	uint8_t HiddenSector[4];
	uint8_t TotalSector32[4];
	
	uint8_t DriveNumber;
	uint8_t Reserved1;
	uint8_t BootSignature;
	uint8_t VolumeID[4];
	uint8_t VolumeLabel[11];
	uint8_t FileSystemType[8];
	
	uint8_t BootCode[448];
			
	uint8_t Signature [2];
	};
};

namespace FAT32 {
	struct BootRecord {
		uint8_t JumpBootCode[3];
		uint8_t OEMName[8];
		uint8_t BytesPerSector[2];
		uint8_t SectorPerCluster;
		uint8_t ReservedSectorCount[2];
		uint8_t NumberofFATs;
		uint8_t RootDirectoryEntryCount[2];
		uint8_t TotalSector16[2];
		uint8_t Media;
		uint8_t FATSize16[2];
		uint8_t SectorPerTrack[2];
		uint8_t NumberOfHeads[2];
		uint8_t HiddenSector[4];
		uint8_t TotalSector32[4];
		
		uint8_t FATSize32[4];
		uint8_t ExtFlags[2];
		uint8_t FileSystemVersion[2];
		uint8_t RootDirectoryCluster[4];
		uint8_t FileSystemInformation[2];
		uint8_t BootRecordBackupSector[2];
		uint8_t Reserved[12];
		uint8_t DriveNumber;
		uint8_t Reserved1;
		uint8_t BootSignature;
		uint8_t VolumeID[4];
		uint8_t VolumeLabel[11];
		uint8_t FileSystemType[8];
		
		uint8_t BootCode[420];
				
		uint8_t Signature [2];
	};
}

#endif
