#ifndef IANIM_H
#define IANIM_H

#include "xMath3.h"

extern U8* giAnimScratch;

void iAnimInit();
F32 iAnimDuration(void* RawData);
U32 iAnimBoneCount(void* RawData);
void iAnimBlend(F32 BlendFactor, F32 BlendRecip, U16* BlendTimeOffset, F32* BoneTable,
                U32 BoneCount, xVec3* Tran1, xQuat* Quat1, xVec3* Tran2, xQuat* Quat2,
                xVec3* TranDest, xQuat* QuatDest);
void iAnimEval(void* RawData, float time, unsigned int flags, class xVec3* tran, class xQuat* quat);

#endif
