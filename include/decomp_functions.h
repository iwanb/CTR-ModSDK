#include <common.h>

void DECOMP_CDSYS_XaCallbackCdSync(char result);
void DECOMP_CDSYS_XaCallbackCdReady(char result);
void DECOMP_CDSYS_SetMode_StreamData();

// howl
void DECOMP_cseq_opcode00_empty(); // should remove
void DECOMP_cseq_opcode01_noteoff();
void DECOMP_cseq_opcode02_empty(); // should remove
void DECOMP_cseq_opcode03();
void DECOMP_cseq_opcode04_empty(); // should remove
void DECOMP_cseq_opcode05_noteon();
void DECOMP_cseq_opcode06();
void DECOMP_cseq_opcode07();
void DECOMP_cseq_opcode08();
void DECOMP_cseq_opcode09();
void DECOMP_cseq_opcode0a();

int DECOMP_DecalFont_DrawMultiLine(char* str, int posX, int posY, int maxPixLen, short fontType, int flags);

void DECOMP_LOAD_Callback_Overlay_Generic();
void DECOMP_LOAD_Callback_Overlay_230();
void DECOMP_LOAD_Callback_Overlay_231();
void DECOMP_LOAD_Callback_Overlay_232();
void DECOMP_LOAD_Callback_Overlay_233();
void DECOMP_LOAD_Callback_DriverModels();
void DECOMP_LOAD_Callback_Podiums();
void DECOMP_LOAD_Callback_LEV();
void DECOMP_LOAD_Callback_LEV_Adv();
void DECOMP_LOAD_VramFileCallback();
void DECOMP_LOAD_ReadFileASyncCallback(char result);
void* DECOMP_LOAD_ReadFile(struct BigHeader* bigfile, u_int loadType, int subfileIndex, void* destination, int *size, void * callback);
void* DECOMP_LOAD_VramFile(void* bigfilePtr, int subfileIndex, int* ptrDestination, int* size, int callbackOrFlags);
void* DECOMP_LOAD_ReadDirectory(char* filename);
void* DECOMP_LOAD_ReadFile_NoCallback(char* filename, void* ptrDestination, int* size);
int DECOMP_LOAD_TenStages(struct GameTracker* gGT, int loadingStage, struct BigHeader* bigfile);

void DECOMP_MainDrawCb_Vsync();
void DECOMP_MainDrawCb_DrawSync();

void DECOMP_MainInit_PrimMem(struct GameTracker* gGT);
void DECOMP_MainInit_OTMem(struct GameTracker* gGT);

void* DECOMP_MEMPACK_AllocMem(int size);
void* DECOMP_MEMPACK_ReallocMem(int size);
void* DECOMP_MEMPACK_AllocHighMem(int allocSize);
int DECOMP_MEMPACK_GetFreeBytes();
void DECOMP_MEMPACK_PopState();
int DECOMP_MEMPACK_PushState();
