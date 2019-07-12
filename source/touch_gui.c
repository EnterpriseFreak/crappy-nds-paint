#include <nds.h>
#include "mspaint.h"

static bool drawBgTex = true;

void requireBgTexRedraw()
{
    drawBgTex = true;
}

void drawOutline(u8 startX, u8 startY, u16 outcol, u16 *vramPointer)
{
    u16 x;
    u16 y;

    //Top line
    for (x = startX; x < startX + 12; x++)
    {
        for (y = startY - 1; y < startY; y++)
        {
            vramPointer[x + y * 256] = outcol;
        }
    }

    //Bottom line
    for (x = startX; x < startX + 12; x++)
    {
        for (y = startY + 12; y < startY + 13; y++)
        {
            vramPointer[x + y * 256] = outcol;
        }
    }

    //Left line
    for (x = startX - 1; x < startX; x++)
    {
        for (y = startY; y < startY + 12; y++)
        {
            vramPointer[x + y * 256] = outcol;
        }
    }

    //Right line
    for (x = startX + 12; x < startX + 13; x++)
    {
        for (y = startY; y < startY + 12; y++)
        {
            vramPointer[x + y * 256] = outcol;
        }
    }
}

void drawTouchGui(u16 *vramPointer)
{
    u16 x;
    u16 y;

    if (drawBgTex) //Drawing area
    {
        for (x = 0; x < 256; x++)
        {
            for (y = 19; y < 192; y++)
            {
                vramPointer[x + y * 256] = ARGB16(1, 31, 31, 31);
            } 
        }

        drawBgTex = false;
    }

    for (x = 0; x < 256; x++) //Color picker bar
    {
        for (y = 0; y < 18; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 26, 26, 26);
        }
    }

    /* Color icons */

    //Black box
    for (x = 2; x < 14; x++) 
    {
        for (y = 3; y < 15; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 0, 0, 0);
        }
    }

    //Outline for the white box
    drawOutline(2, 3, outlineCol_gray, vramPointer);

    //Red box
    for (x = 18; x < 30; x++)
    {
        for (y = 3; y < 15; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 31, 0, 0);
        }
    }

    //Outline for the red box
    drawOutline(18, 3, outlineCol_gray, vramPointer);

    //Green box
    for (x = 34; x < 46; x++)
    {
        for (y = 3; y < 15; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 0, 31, 0);
        }
    }

    //Outline for the green box
    drawOutline(34, 3, outlineCol_gray, vramPointer);

    //Blue box
    for (x = 50; x <62; x++)
    {
        for (y = 3; y < 15; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 0, 0, 31);
        }
    }

    //Outline for the blue box
    drawOutline(50, 3, outlineCol_gray, vramPointer);

    //Yellow box
    for (x = 66; x < 78; x++)
    {
        for (y = 3; y < 15; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 31, 31, 0);
        }
    }

    //Outline for the yellow box
    drawOutline(66, 3, outlineCol_gray, vramPointer);

    //Purple box
    for (x = 82; x < 94; x++)
    {
        for (y = 3; y < 15; y++)
        {
            vramPointer[x + y * 256] = ARGB16(1, 31, 0, 31);
        }
    }

    //Outline for the purple box
    drawOutline(82, 3, outlineCol_gray, vramPointer);

}
