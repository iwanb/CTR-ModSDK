#include <common.h>

void DECOMP_COLL_PerQuadblock_CheckTriangles_NearPlayer(struct QuadBlock *quad, struct ScratchpadStruct *sps)
{
    u_int uVar1;

    (struct QuadBlock *)(sps->unk4C[0x18]) = quad;

    if (
        (
            (
                // quadblock flags
                ((sps->Union.QuadBlockColl.searchFlags & quad->quadFlags) != 0) &&

                // quadblock flags
                ((sps->Union.QuadBlockColl.unk28 & quad->quadFlags) == 0)) &&

            // min[y] less than [???]
            ((quad->bbox.min[0] >> 0x10) - sps->bbox.max[0] < 1)) &&

        ((
            (
                // min[x] less than [???]
                quad->bbox.min[0] - sps->bbox.max[0] < 1 &&

                // max[x] more than [???]
                (sps->bbox.min[0] - (quad->bbox.min[2] >> 0x10) < 1)) &&

            ((
                // min[z] less than [???]
                quad->bbox.min[2] - sps->bbox.max[2] < 1 &&

                // min[z] more than [???]
                (sps->bbox.min[2] - (quad->bbox.max[1] >> 0x10) < 1))))))
    {
        // min[y] more than [???]
        if (sps->bbox.min[1] - quad->bbox.max[1] < 1)
        {
            // if 3P or 4P mode,
            // then use low-LOD quadblock collision (two triangles)
            if ((sps->Union.QuadBlockColl.unk22 & 2) == 0)
            {
                COLL_TestQuadblock_TwoTris(sps, quad);

                // call COLL_TestTriangle_FindClosest two times, one per triangle

                sps->unk4C[0x17] = 0;
                COLL_TestTriangle_FindClosest(0x1f800108, 0x1f8001f8, 0x1f80020c, 0x1f800220); // 0, 1, 2
                uVar1 = quad->index[2];
                sps->unk4C[0x17] = 1;
                if (uVar1 >> 0x10 != (uVar1 & 0xffff))
                {
                    COLL_TestTriangle_FindClosest(0x1f800108, 0x1f80020c, 0x1f800234, 0x1f800220); // 1, 3, 2
                }
            }
            else
            {
                if ((sps->Union.QuadBlockColl.unk22 & 8) == 0)
                {
                    COLL_TestQuadblock_EightTris(sps, quad);
                }

                // call COLL_TestTriangle_FindClosest eight times, one per triangle

                sps->unk4C[0x17] = 2;
                COLL_TestTriangle_FindClosest(0x1f800108, 0x1f8001f8, 0x1f800248, 0x1f80025c); // 0, 4, 5
                sps->unk4C[0x17] = 3;
                COLL_TestTriangle_FindClosest(0x1f800108, 0x1f800248, 0x1f800270, 0x1f80025c); // 4, 6, 5
                sps->unk4C[0x17] = 4;
                COLL_TestTriangle_FindClosest(0x1f800108, 0x1f800270, 0x1f800248, 0x1f80020c); // 6, 4, 1
                sps->unk4C[0x17] = 5;
                COLL_TestTriangle_FindClosest(0x1f800108, 0x1f80025c, 0x1f800270, 0x1f800220); // 5, 6, 2
                uVar1 = quad->index[2];
                sps->unk4C[0x17] = 6;
                if (uVar1 >> 0x10 != (uVar1 & 0xffff))
                {
                    COLL_TestTriangle_FindClosest(0x1f800108, 0x1f800298, 0x1f800270, 0x1f800284); // 8, 6, 7
                    sps->unk4C[0x17] = 7;
                    COLL_TestTriangle_FindClosest(0x1f800108, 0x1f800284, 0x1f800234, 0x1f800298); // 7, 3, 8
                    sps->unk4C[0x17] = 8;
                    COLL_TestTriangle_FindClosest(0x1f800108, 0x1f80020c, 0x1f800284, 0x1f800270); // 1, 7, 6
                    sps->unk4C[0x17] = 9;
                    COLL_TestTriangle_FindClosest(0x1f800108, 0x1f800220, 0x1f800270, 0x1f800298); // 2, 6, 8
                    return;
                }
            }
        }
    }
}
