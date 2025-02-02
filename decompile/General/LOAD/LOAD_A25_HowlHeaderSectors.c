#include <common.h>

int DECOMP_LOAD_HowlHeaderSectors(CdlFILE* cdlFileHWL, void* ptrDestination, int firstSector, int numSector)
{
	CdlLOC loc;
	
	DECOMP_CDSYS_SetMode_StreamData();
	
	// If reading out of file bounds, quit
	if ( ((firstSector+numSector)*0x800 - cdlFileHWL->size) >= 0x800 )
		return 0;
	
	CdIntToPos(CdPosToInt(&cdlFileHWL->pos) + firstSector, &loc);
		
	char buf[8];
	CdControl(CdlSetloc, &loc, buf);
		
	if(CdRead(numSector, ptrDestination, 0x80) == 0) 
		return 0;
	
	if(CdReadSync(0,0) != 0) 
		return 0;
	
	return 1;
}