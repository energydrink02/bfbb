#include "dolphin/dvd.h"
#include "dolphin/OSRtcPriv.h"

static u32 ErrorTable[] = {
    0,          0x00023A00, 0x00062800, 0x00030200, 0x00031100, 0x00052000,
    0x00052001, 0x00052100, 0x00052400, 0x00052401, 0x00052402, 0x000B5A01,
    0x00056300, 0x00020401, 0x00020400, 0x00040800, 0x00100007, 0,
};

static u8 ErrorCode2Num(u32 errorCode)
{
    u32 i;

    for (i = 0; i < sizeof(ErrorTable) / sizeof(ErrorTable[0]); i++)
    {
        if (ErrorTable[i] == errorCode)
        {
            return (u8)i;
        }
    }

    if ((errorCode >= 0x00100000) && (errorCode <= 0x00100008))
    {
        return 17;
    }

    return 29;
}

inline u8 Convert(u32 error)
{
    u32 statusCode;
    u32 errorCode;
    u8 errorNum;

    if (error == 0x01234567)
        return 255;

    if (error == 0x01234568)
        return 254;

    statusCode = (error & 0xff000000) >> 24;
    errorCode = error & 0x00ffffff;

    errorNum = ErrorCode2Num(errorCode);
    if (statusCode >= 6)
        statusCode = 6;

    return (u8)(statusCode * 30 + errorNum);
}

void __DVDStoreErrorCode(u32 error)
{
    OSSramEx* sram;
    u8 num;

    num = Convert(error);

    sram = __OSLockSramEx();
    sram->dvdErrorCode = num;
    __OSUnlockSramEx(TRUE);
}