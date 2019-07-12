#include <nds.h>

void drawTopscreenBg(u16 *vramPointer)
{
    s16 x;
    s16 y;

    for (x = 0; x < 256; x++)
    {
        for (y = -1; y < 192; y++)
        {
            if (y % 2 == 0)
                vramPointer[x + y * 256] = ARGB16(1, 31, 31, 31);

            if (y % 2 == 1)
                vramPointer[x + y * 256] = ARGB16(1, 28, 28, 28);
        }
    }

    for (x = -1; x < 256; x++)
    {
        for (y = 0; y < 256; y += 16)
        {
            vramPointer[x + y * 256] = ARGB16(1, 24, 24, 24);
        }
    }

    for (x = 0; x < 256; x += 16)
    {
        for (y = 0; y < 256; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 24, 24, 24);
        }
    }

    for (x = 0; x < 256; x++)
    {
        for (y = 0; y < 16; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 4, 2, 31);

            if (y == 15)
                vramPointer[x + y * 256] = ARGB16(1, 0, 0, 0);
        }
    }
}