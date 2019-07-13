#include <nds.h>
#include "touch_gui.h"
#include "mspaint.h"

static u8 curColID = 0;
static u16 curColor = ARGB16(1, 0, 0, 0);
touchPosition oldTouch;

void mspaint(u16 *vramPointer)
{
    touchPosition touch;
    touchRead(&touch);

    scanKeys();
    u32 kDown = keysDown();
    u32 kHeld = keysHeld();

    if (kDown & KEY_LEFT && curColID > 0)
        curColID--;

    if (kDown & KEY_RIGHT && curColID < 5)
        curColID++;

    if (kDown & KEY_SELECT)
        requireBgTexRedraw();

    //Place the "selected" marker
    if (curColID == 0)
        drawOutline(2, 3, outlineCol_sel, vramPointer);

    if (curColID == 1)
        drawOutline(18, 3, outlineCol_sel, vramPointer);

    if (curColID == 2)
        drawOutline(34, 3, outlineCol_sel, vramPointer);

    if (curColID == 3)
        drawOutline(50, 3, outlineCol_sel, vramPointer);

    if (curColID == 4)
        drawOutline(66, 3, outlineCol_sel, vramPointer);

    if (curColID == 5)
        drawOutline(82, 3, outlineCol_sel, vramPointer);

    if (kHeld & KEY_TOUCH)
    {
        if (touch.py < 18)
        {
            if (touch.px > 2 && touch.px < 18)
                curColID = 0;
            
            if (touch.px > 18 && touch.px < 30)
                curColID = 1;

            if (touch.px > 34 && touch.px < 46)
                curColID = 2;

            if (touch.px > 50 && touch.px < 62)
                curColID = 3;

            if (touch.px > 66 && touch.px < 78)
                curColID = 4;

            if (touch.px > 82 && touch.px < 92)
                curColID = 5;
        }

        if (touch.py > 19)
        {
            if (curColID == 0)
            {
                vramPointer[(int)touch.px + (int)touch.py * 256] = ARGB16(1, 0, 0, 0);
            }

            if (curColID == 1)
            {
                vramPointer[(int)touch.px + (int)touch.py * 256] = ARGB16(1, 31, 0, 0);
            }

            if (curColID == 2)
            {
                vramPointer[(int)touch.px + (int)touch.py * 256] = ARGB16(1, 0, 31, 0);
            }

            if (curColID == 3)
            {
                vramPointer[(int)touch.px + (int)touch.py * 256] = ARGB16(1, 0, 0, 31);
            }

            if (curColID == 4)
            {
                vramPointer[(int)touch.px + (int)touch.py * 256] = ARGB16(1, 31, 31, 0);
            }

            if (curColID == 5)
            {
                vramPointer[(int)touch.px + (int)touch.py * 256] = ARGB16(1, 31, 0, 31);
            }
        }
    }

}