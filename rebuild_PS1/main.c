#define REBUILD_PS1

#include <common.h>

// not in OG game, does not fit byte budget,
// random testing to learn more about the game 
#include "TEST_DrawInstances.c"
#include "TEST_ConvertRotToMatrix.c"
#include "TEST_ThTickRunBucket.c"

#include "../decompile/General/MAIN/MainMain.c"

#include "../decompile/General/CAMERA/CAM_01_ClearScreen.c"

#include "../decompile/General/CDSYS/CDSYS_c01_Init.c" 
#include "../decompile/General/CDSYS/CDSYS_c02_GetFilePosInt.c" 
#include "../decompile/General/CDSYS/CDSYS_c03_SetMode_StreamData.c" 
#include "../decompile/General/CDSYS/CDSYS_c04_SetMode_StreamAudio.c" 
#include "../decompile/General/CDSYS/CDSYS_c05_SetXAToLang.c" 
#include "../decompile/General/CDSYS/CDSYS_c06_XaCallbackCdSync.c" 
#include "../decompile/General/CDSYS/CDSYS_c07_XaCallbackCdReady.c" 
#include "../decompile/General/CDSYS/CDSYS_c08_SpuCallbackIRQ.c" 
#include "../decompile/General/CDSYS/CDSYS_c09_SpuCallbackTransfer.c" 
#include "../decompile/General/CDSYS/CDSYS_c10_SpuEnableIRQ.c" 
#include "../decompile/General/CDSYS/CDSYS_c11_SpuDisableIRQ.c" 
#include "../decompile/General/CDSYS/CDSYS_c13_XAGetNumTracks.c" 
#include "../decompile/General/CDSYS/CDSYS_c14_XASeek.c" 
#include "../decompile/General/CDSYS/CDSYS_c15_XAGetTrackLength.c" 
#include "../decompile/General/CDSYS/CDSYS_c16_XAPlay.c" 
#include "../decompile/General/CDSYS/CDSYS_c17_XAPauseRequest.c" 
#include "../decompile/General/CDSYS/CDSYS_c18_XAPauseForce.c" 
#include "../decompile/General/CDSYS/CDSYS_c19_XAPauseAtEnd.c" 

#include "../decompile/General/CTR_CycleTex_LEV.c"
#include "../decompile/General/CTR_ErrorScreen.c"
#include "../decompile/General/CTR_CycleTex_AllModels.c"
#include "../decompile/General/CTR_CycleTex_Model.c"

#include "../decompile/General/CTR_Box_DrawClearBox.c"
#include "../decompile/General/CTR_Box_DrawSolidBox.c"

#include "../decompile/General/DecalFont/DecalFont_GetLineWidth.c"
#include "../decompile/General/DecalFont/DecalFont_DrawLineStrlen.c"
#include "../decompile/General/DecalFont/DecalFont_DrawLine.c"
#include "../decompile/General/DecalFont/DecalFont_DrawLineOT.c"
#include "../decompile/General/DecalFont/DecalFont_DrawMultiLineStrlen.c"
#include "../decompile/General/DecalFont/DecalFont_DrawMultiLine.c"
#include "../decompile/General/DecalFont/DecalFont_GetLineWidthStrlen.c"

#include "../decompile/General/DecalGlobal/DecalGlobal_Clear.c"
#include "../decompile/General/DecalGlobal/DecalGlobal_Store.c"

#include "../decompile/General/DecalHUD/DecalHUD_DrawPolyFT4.c"
#include "../decompile/General/DecalHUD/DecalHUD_DrawPolyGT4.c"
#include "../decompile/General/DecalHUD/DecalHUD_Arrow2D.c"

#include "../decompile/General/DISPLAY/DISPLAY_Swap.c"

#include "../decompile/General/GAMEPAD/GAMEPAD_Init.c"
#include "../decompile/General/GAMEPAD/GAMEPAD_PollVsync.c"
#include "../decompile/General/GAMEPAD/GAMEPAD_GetNumConnected.c"
#include "../decompile/General/GAMEPAD/GAMEPAD_ProcessAnyoneVars.c"
#include "../decompile/General/GAMEPAD/GAMEPAD_ProcessTapRelease.c"
#include "../decompile/General/GAMEPAD/GAMEPAD_ProcessHold.c"

#include "../decompile/General/GAMEPROG/GAMEPROG_ResetHighScores.c"
#include "../decompile/General/GAMEPROG/GAMEPROG_CheckGhostsBeaten.c"
#include "../decompile/General/GAMEPROG/GAMEPROG_NewProfile_OutsideAdv.c"
// skip
#include "../decompile/General/GAMEPROG/GAMEPROG_NewProfile_InsideAdv.c"
// skip
#include "../decompile/General/GAMEPROG/GAMEPROG_NewGame_OnBoot.c"
#include "../decompile/General/GAMEPROG/GAMEPROG_GetPtrHighScoreTrack.c"

#include "../decompile/General/HOWL/h01_CountSounds.c"
#include "../decompile/General/HOWL/h02_OtherFX_Play.c"
#include "../decompile/General/HOWL/h03_OtherFX_Play_Echo.c"
#include "../decompile/General/HOWL/h04_OtherFX_Play_LowLevel.c"
#include "../decompile/General/HOWL/h05_OtherFX_Modify.c"
#include "../decompile/General/HOWL/h06_OtherFX_Stop1.c"
#include "../decompile/General/HOWL/h07_OtherFX_Stop2.c"
#include "../decompile/General/HOWL/h08_EngineAudio_InitOnce.c"
#include "../decompile/General/HOWL/h09_EngineAudio_Recalculate.c"
#include "../decompile/General/HOWL/h10_EngineAudio_Stop.c"
#include "../decompile/General/HOWL/h11_SetReverbMode.c"
#include "../decompile/General/HOWL/h12_CseqMusic_Start.c"
#include "../decompile/General/HOWL/h13_CseqMusic_Pause.c"
#include "../decompile/General/HOWL/h14_CseqMusic_Resume.c"
#include "../decompile/General/HOWL/h15_CseqMusic_ChangeVolume.c"
#include "../decompile/General/HOWL/h16_CseqMusic_Restart.c"
#include "../decompile/General/HOWL/h17_CseqMusic_ChangeTempo.c"
#include "../decompile/General/HOWL/h18_CseqMusic_AdvHubSwap.c"
#include "../decompile/General/HOWL/h19_CseqMusic_Stop.c"
#include "../decompile/General/HOWL/h20_CseqMusic_StopAll.c"
#include "../decompile/General/HOWL/h21_Bank_ResetAllocator.c"
#include "../decompile/General/HOWL/h22_Bank_Alloc.c"
#include "../decompile/General/HOWL/h23_Bank_AssignSpuAddrs.c"
#include "../decompile/General/HOWL/h24_Bank_Destroy.c"
#include "../decompile/General/HOWL/h25_Bank_ClearInRange.c"
#include "../decompile/General/HOWL/h26_Bank_Load.c"
#include "../decompile/General/HOWL/h27_Bank_DestroyLast.c"
#include "../decompile/General/HOWL/h28_Bank_DestroyUntilIndex.c"
#include "../decompile/General/HOWL/h29_Bank_DestroyAll.c"
#include "../decompile/General/HOWL/h30_howl_InstrumentPitch.c"
#include "../decompile/General/HOWL/h31_howl_InitGlobals.c"
#include "../decompile/General/HOWL/h32_howl_ParseHeader.c"
#include "../decompile/General/HOWL/h33_howl_ParseCseqHeader.c"
#include "../decompile/General/HOWL/h34_howl_LoadHeader.c"
#include "../decompile/General/HOWL/h35_howl_SetSong.c"
#include "../decompile/General/HOWL/h36_howl_LoadSong.c"
#include "../decompile/General/HOWL/h37_howl_ErasePtrCseqHeader.c"
#include "../decompile/General/HOWL/h38_howl_GetNextNote.c"
#include "../decompile/General/HOWL/h39_cseq_opcode01_noteoff.c"
#include "../decompile/General/HOWL/h40_cseq_opcode03.c"
#include "../decompile/General/HOWL/h41_howl_InitChannelAttr_Music.c"
#include "../decompile/General/HOWL/h42_cseq_opcode_from06and07.c"
#include "../decompile/General/HOWL/h43_cseq_opcode05_noteon.c"
#include "../decompile/General/HOWL/h44_cseq_opcode06.c"
#include "../decompile/General/HOWL/h45_cseq_opcode07.c"
#include "../decompile/General/HOWL/h46_cseq_opcode08.c"
#include "../decompile/General/HOWL/h47_cseq_opcode09.c"
#include "../decompile/General/HOWL/h48_cseq_opcode0a.c"
#include "../decompile/General/HOWL/h49_SongPool_FindFreeChannel.c"
#include "../decompile/General/HOWL/h50_SongPool_CalculateTempo.c"
#include "../decompile/General/HOWL/h51_SongPool_ChangeTempo.c"
#include "../decompile/General/HOWL/h52_SongPool_Start.c"
#include "../decompile/General/HOWL/h53_SongPool_Volume.c"
#include "../decompile/General/HOWL/h54_SongPool_AdvHub1.c"
#include "../decompile/General/HOWL/h55_SongPool_AdvHub2.c"
#include "../decompile/General/HOWL/h56_SongPool_StopCseq.c"
#include "../decompile/General/HOWL/h57_SongPool_StopAllCseq.c"
#include "../decompile/General/HOWL/h58_howl_Disable.c"
#include "../decompile/General/HOWL/h59_UpdateChannelVol_EngineFX.c"
#include "../decompile/General/HOWL/h60_UpdateChannelVol_OtherFX.c"
#include "../decompile/General/HOWL/h61_UpdateChannelVol_Music.c"
#include "../decompile/General/HOWL/h62_UpdateChannelVol_EngineFX_All.c"
#include "../decompile/General/HOWL/h63_UpdateChannelVol_Music_All.c"
#include "../decompile/General/HOWL/h64_UpdateChannelVol_OtherFX_All.c"
#include "../decompile/General/HOWL/h65_howl_VolumeGet.c"
#include "../decompile/General/HOWL/h66_howl_VolumeSet.c"
#include "../decompile/General/HOWL/h67_howl_ModeGet.c"
#include "../decompile/General/HOWL/h68_howl_ModeSet.c"
#include "../decompile/General/HOWL/h69_OptionsMenu_TestSound.c"
#include "../decompile/General/HOWL/h70_Smart_EnterCriticalSection.c"
#include "../decompile/General/HOWL/h71_Smart_ExitCriticalSection.c"
#include "../decompile/General/HOWL/h72_Channel_SetVolume.c"
#include "../decompile/General/HOWL/h73_Channel_FindSound.c"
#include "../decompile/General/HOWL/h74_Channel_AllocSlot_AntiSpam.c"
#include "../decompile/General/HOWL/h75_Channel_AllocSlot.c"
#include "../decompile/General/HOWL/h76_Channel_SearchFX_EditAttr.c"
#include "../decompile/General/HOWL/h77_Channel_SearchFX_Destroy.c"
#include "../decompile/General/HOWL/h78_Channel_DestroyAll_LowLevel.c"
#include "../decompile/General/HOWL/h79_Channel_ParseSongToChannels.c"
#include "../decompile/General/HOWL/h80_Channel_UpdateChannels.c"
#include "../decompile/General/HOWL/h81_Cutscene_VolumeBackup.c"
#include "../decompile/General/HOWL/h82_Cutscene_VolumeRestore.c"
#include "../decompile/General/HOWL/h83_howl_PlayAudio_Update.c"
#include "../decompile/General/HOWL/h84_howl_InitChannelAttr_EngineFX.c"
#include "../decompile/General/HOWL/h85_howl_InitChannelAttr_OtherFX.c"
#include "../decompile/General/HOWL/h86_howl_PauseAudio.c"
#include "../decompile/General/HOWL/h87_howl_UnPauseChannel.c"
#include "../decompile/General/HOWL/h88_howl_UnPauseAudio.c"
#include "../decompile/General/HOWL/h89_howl_StopAudio.c"
#include "../decompile/General/HOWL/h90_Voiceline_PoolInit.c"
#include "../decompile/General/HOWL/h91_Voiceline_ClearTimeStamp.c"
#include "../decompile/General/HOWL/h92_Voiceline_PoolClear.c"
#include "../decompile/General/HOWL/h93_Voiceline_StopAll.c"
#include "../decompile/General/HOWL/h94_Voiceline_ToggleEnable.c"
// skip h95, h96, h97 (requires CDSYS fix from void to int), h98 (empty)
#include "../decompile/General/HOWL/h99_Voiceline_SetDefaults.c"
#include "../decompile/General/HOWL/h100_Audio_SetState.c"
#include "../decompile/General/HOWL/h101_Audio_SetState_Safe.c"
#include "../decompile/General/HOWL/h102_Audio_AdvHub_SwapSong.c"
#include "../decompile/General/HOWL/h103_Audio_SetMaskSong.c"
#include "../decompile/General/HOWL/h104_Audio_Update1.c"
#include "../decompile/General/HOWL/h105_Audio_SetDefaults.c"
#include "../decompile/General/HOWL/h106_Audio_SetReverbMode.c"
#include "../decompile/General/HOWL/h107_Music_SetIntro.c"
#include "../decompile/General/HOWL/h108_Music_LoadBanks.c"
#include "../decompile/General/HOWL/h109_Music_AsyncParseBanks.c"
#include "../decompile/General/HOWL/h110_Music_SetDefaults.c"
#include "../decompile/General/HOWL/h111_Music_Adjust.c"
#include "../decompile/General/HOWL/h112_Music_LowerVolume.c"
#include "../decompile/General/HOWL/h113_Music_RaiseVolume.c"
#include "../decompile/General/HOWL/h114_Music_Restart.c"
#include "../decompile/General/HOWL/h115_Music_Stop.c"
#include "../decompile/General/HOWL/h116_Music_Start.c"
#include "../decompile/General/HOWL/h117_Music_End.c"
#include "../decompile/General/HOWL/h118_Music_GetHighestSongPlayIndex.c"

#include "../decompile/General/INSTANCE/INSTANCE_Birth.c"
#include "../decompile/General/INSTANCE/INSTANCE_Birth3D.c"
#include "../decompile/General/INSTANCE/INSTANCE_Birth2D.c"
#include "../decompile/General/INSTANCE/INSTANCE_BirthWithThread.c"
#include "../decompile/General/INSTANCE/INSTANCE_BirthWithThread_Stack.c"
#include "../decompile/General/INSTANCE/INSTANCE_Death.c"
#include "../decompile/General/INSTANCE/INSTANCE_GetNumAnimFrames.c"

#include "../decompile/General/JitPool/JitPool_Clear.c"
#include "../decompile/General/JitPool/JitPool_Init.c"
#include "../decompile/General/JitPool/JitPool_Add.c"
#include "../decompile/General/JitPool/JitPool_Remove.c"

#include "../decompile/General/LevInstDef/LevInstDef_UnPack.c"
#include "../decompile/General/LevInstDef/LevInstDef_RePack.c"

#include "../decompile/General/LibraryOfModels/LibraryOfModels_Clear.c"
#include "../decompile/General/LibraryOfModels/LibraryOfModels_Store.c"

#include "../decompile/General/LIST/LIST_Clear.c"
#include "../decompile/General/LIST/LIST_AddFront.c"
#include "../decompile/General/LIST/LIST_AddBack.c"
#include "../decompile/General/LIST/LIST_GetNextItem.c"
#include "../decompile/General/LIST/LIST_GetFirstItem.c"
#include "../decompile/General/LIST/LIST_RemoveMember.c"
#include "../decompile/General/LIST/LIST_RemoveFront.c"
#include "../decompile/General/LIST/LIST_RemoveBack.c"
#include "../decompile/General/LIST/LIST_Init.c"

#include "../decompile/General/LOAD/LOAD_A01_Callback_Overlay_Generic.c"
#include "../decompile/General/LOAD/LOAD_A02_Callback_Overlay_230.c"
#include "../decompile/General/LOAD/LOAD_A03_Callback_Overlay_231.c"
#include "../decompile/General/LOAD/LOAD_A04_Callback_Overlay_232.c"
#include "../decompile/General/LOAD/LOAD_A05_Callback_Overlay_233.c"
// hole
#include "../decompile/General/LOAD/LOAD_A07_Callback_Podiums.c"
#include "../decompile/General/LOAD/LOAD_A08_Callback_LEV.c"
#include "../decompile/General/LOAD/LOAD_A09_Callback_LEV_Adv.c"
#include "../decompile/General/LOAD/LOAD_A10_Callback_DriverModels.c"
// hole
#include "../decompile/General/LOAD/LOAD_A12_GlobalModelPtrs_MPK.c"
// hole
#include "../decompile/General/LOAD/LOAD_A14_StringToUpper.c" 
#include "../decompile/General/LOAD/LOAD_A15_InitCD.c" 
#include "../decompile/General/LOAD/LOAD_A16_ReadDirectory.c" 
#include "../decompile/General/LOAD/LOAD_A17_DramFileCallback.c"
#include "../decompile/General/LOAD/LOAD_A18_DramFile.c"
#include "../decompile/General/LOAD/LOAD_A19_VramFileCallback.c"
#include "../decompile/General/LOAD/LOAD_A20_VramFile.c" 
#include "../decompile/General/LOAD/LOAD_A21_ReadFileASyncCallback.c"
#include "../decompile/General/LOAD/LOAD_A22_ReadFile.c"
#include "../decompile/General/LOAD/LOAD_A23_ReadFile_NoCallback.c"
#include "../decompile/General/LOAD/LOAD_A24_FindFile.c"
#include "../decompile/General/LOAD/LOAD_A25_HowlHeaderSectors.c"
#include "../decompile/General/LOAD/LOAD_A26_HowlCallback.c"
#include "../decompile/General/LOAD/LOAD_A27_HowlSectorChainStart.c"
#include "../decompile/General/LOAD/LOAD_A28_HowlSectorChainEnd.c"
#include "../decompile/General/LOAD/LOAD_A29_RunPtrMap.c"
#include "../decompile/General/LOAD/LOAD_A30_Robots2P.c"
#include "../decompile/General/LOAD/LOAD_A31_Robots1P.c"
#include "../decompile/General/LOAD/LOAD_A32_DriverMPK.c"
#include "../decompile/General/LOAD/LOAD_A33_LangFile.c"
#include "../decompile/General/LOAD/LOAD_A34_GetBigfileIndex.c"
#include "../decompile/General/LOAD/LOAD_A35_AppendQueue.c"
#include "../decompile/General/LOAD/LOAD_A36_CDRequestCallback.c"
#include "../decompile/General/LOAD/LOAD_A37_NextQueuedFile.c"
// hole
#include "../decompile/General/LOAD/LOAD_A41_OvrLOD.c"
#include "../decompile/General/LOAD/LOAD_A42_OvrEndRace.c"
#include "../decompile/General/LOAD/LOAD_A43_OvrThreads.c"
#include "../decompile/General/LOAD/LOAD_A44_GetAdvPackIndex.c"
#include "../decompile/General/LOAD/LOAD_A45_TenStages.c"

#include "../decompile/General/LOAD/LOAD_A47_LevelFile.c"

#include "../decompile/General/MAIN/MainDB_GetClipSize.c"
#include "../decompile/General/MAIN/MainDB_OTMem.c"
#include "../decompile/General/MAIN/MainDB_PrimMem.c"
#include "../decompile/General/MAIN/MainDrawCb_DrawSync.c"
#include "../decompile/General/MAIN/MainDrawCb_Vsync.c"
#include "../decompile/General/MAIN/MainFrame_GameLogic.c"
#include "../decompile/General/MAIN/MainFrame_RenderFrame.c"
#include "../decompile/General/MAIN/MainFrame_ResetDB.c"
#include "../decompile/General/MAIN/MainInit_Drivers.c"
#include "../decompile/General/MAIN/MainInit_JitPoolsNew.c"
#include "../decompile/General/MAIN/MainInit_JitPoolsReset.c"
#include "../decompile/General/MAIN/MainInit_OTMem.c"
#include "../decompile/General/MAIN/MainInit_PrimMem.c"
#include "../decompile/General/MAIN/MainInit_FinalizeInit.c"
#include "../decompile/General/MAIN/MainInit_VRAMClear.c" 
#include "../decompile/General/MAIN/MainInit_VRAMDisplay.c" 
#include "../decompile/General/MAIN/MainRaceTrack_StartLoad.c"
#include "../decompile/General/MAIN/MainRaceTrack_RequestLoad.c"

#include "../decompile/General/MATH/MATH_Sin.c"
#include "../decompile/General/MATH/MATH_Cos.c"

#include "../decompile/General/MEMCARD/MEMCARD_InitCard.c"

#include "../decompile/General/MEMPACK/MEMPACK_Init.c" 
#include "../decompile/General/MEMPACK/MEMPACK_SwapPacks.c" 
#include "../decompile/General/MEMPACK/MEMPACK_NewPack_StartEnd.c" 
#include "../decompile/General/MEMPACK/MEMPACK_GetFreeBytes.c" 
#include "../decompile/General/MEMPACK/MEMPACK_AllocMem.c" 
#include "../decompile/General/MEMPACK/MEMPACK_AllocHighMem.c" 
#include "../decompile/General/MEMPACK/MEMPACK_ClearHighMem.c" 
#include "../decompile/General/MEMPACK/MEMPACK_ReallocMem.c" 
#include "../decompile/General/MEMPACK/MEMPACK_PushState.c" 
#include "../decompile/General/MEMPACK/MEMPACK_ClearLowMem.c" 
#include "../decompile/General/MEMPACK/MEMPACK_PopState.c" 
#include "../decompile/General/MEMPACK/MEMPACK_PopToState.c"

#include "../decompile/General/MenuBox/MENUBOX_DrawPolyGT4.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawOuterRect_Edge.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawTime.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawRwdBlueRect_Subset.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawRwdBlueRect.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawRwdTriangle.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawOuterRect_LowLevel.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawOuterRect_HighLevel.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawQuip.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawInnerRect.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawFullRect.c"
#include "../decompile/General/MenuBox/MENUBOX_GetHeight.c"
#include "../decompile/General/MenuBox/MENUBOX_GetWidth.c"
#include "../decompile/General/MenuBox/MENUBOX_DrawSelf.c"
#include "../decompile/General/MenuBox/MENUBOX_ClearInput.c"
#include "../decompile/General/MenuBox/MENUBOX_CollectInput.c"
#include "../decompile/General/MenuBox/MENUBOX_ProcessInput.c"
#include "../decompile/General/MenuBox/MENUBOX_ProcessState.c"
#include "../decompile/General/MenuBox/MENUBOX_Show.c"
#include "../decompile/General/MenuBox/MENUBOX_Hide.c"
#include "../decompile/General/MenuBox/MENUBOX_BoolHidden.c"

#include "../decompile/General/TileView/TileView_Init.c"
#include "../decompile/General/TileView/TileView_SetPsyqGeom.c"
#include "../decompile/General/TileView/TileView_SetMatrixVP.c"
#include "../decompile/General/TileView/TileView_SetDrawEnv_Normal.c"

#include "../decompile/General/THREAD/THREAD_DestroyTracker.c"
#include "../decompile/General/THREAD/THREAD_DestroyInstance.c"
#include "../decompile/General/THREAD/THREAD_DestroyObject.c"
#include "../decompile/General/THREAD/THREAD_DestroySelf_AndBloodline.c"
#include "../decompile/General/THREAD/THREAD_CheckBloodlineForDead.c"
#include "../decompile/General/THREAD/THREAD_CheckAllForDead.c"
#include "../decompile/General/THREAD/THREAD_BirthWithObject.c"
#include "../decompile/General/THREAD/THREAD_CollidePointWithSelf.c"
#include "../decompile/General/THREAD/THREAD_CollidePointWithBucket.c"
#include "../decompile/General/THREAD/THREAD_SearchForModel.c"

#include "../decompile/General/TitleBeginTrack_MenuBoxFuncPtr.c"
#include "../decompile/General/TitleBeginTrack_Get_MenuBox.c"

#include "../decompile/General/TitleFlag/TitleFlag_t01_MoveModels.c"
#include "../decompile/General/TitleFlag/TitleFlag_t02_IsFullyOnScreen.c"
#include "../decompile/General/TitleFlag/TitleFlag_t03_IsFullyOffScreen.c"
#include "../decompile/General/TitleFlag/TitleFlag_t04_IsTransitioning.c"
#include "../decompile/General/TitleFlag/TitleFlag_t05_SetDrawOrder.c"
#include "../decompile/General/TitleFlag/TitleFlag_t06_BeginTransition.c"
#include "../decompile/General/TitleFlag/TitleFlag_t07_SetFullyOnScreen.c"
#include "../decompile/General/TitleFlag/TitleFlag_t08_SetFullyOffScreen.c"
#include "../decompile/General/TitleFlag/TitleFlag_t09_SetCanDraw.c"
#include "../decompile/General/TitleFlag/TitleFlag_t10_GetCanDraw.c"
#include "../decompile/General/TitleFlag/TitleFlag_t11_GetOT.c"
#include "../decompile/General/TitleFlag/TitleFlag_t12_ResetTextAnim.c"
#include "../decompile/General/TitleFlag/TitleFlag_t13_DrawLoadingString.c"
#include "../decompile/General/TitleFlag/TitleFlag_t14_DrawSelf.c"

// RCNT (watch namespace, not alphabetical)
#include "../decompile/General/RCNT/RCNT_Init.c"

// UI
#include "../decompile/General/UI/UI_Map_DrawMap.c"

// VEH
#include "../decompile/General/Vehicle/VehInit_Player.c"
#include "../decompile/General/Vehicle/VehInit_NonGhost.c"

// 230
// only put these in the EXE for REBUILD_PC,
// REBUILD_PS1 puts them on BuildList.txt,
// cause R230 and D230 in the symbol table
// go to the overlay
#ifdef REBUILD_PC
#include "../decompile/General/230/R230.c"
#include "../decompile/General/230/D230.c"
#endif

// 230
#include "../decompile/General/230/1_Block1.c"
#include "../decompile/General/230/230_39_MM_AdvNewLoad_GetMenuBox.c"
#include "../decompile/General/230/1_Block2.c"
#include "../decompile/General/230/230_55_MM_TrackSelect_Init.c"
#include "../decompile/General/230/230_56_MM_TrackSelect_MenuBox.c"
#include "../decompile/General/230/230_57_MM_TrackSelect_GetMenuBox.c"
#include "../decompile/General/230/1_Block3.c"