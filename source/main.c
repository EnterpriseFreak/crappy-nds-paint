#include <nds.h>
#include <stdio.h>
#include "touch_gui.h"
#include "topscreen_bg.h"
#include "mspaint.h"

int main(void)
{
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);

    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    int mainBg = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
    int subBg = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

    u16* vramMain = bgGetGfxPtr(mainBg);
    u16* vramSub = bgGetGfxPtr(subBg);

    drawTopscreenBg(vramMain);

    while(true) //Application main loop
    {
        drawTouchGui(vramSub);
        mspaint(vramSub);

        scanKeys();
        u32 kdown = keysDown();

        if (kdown & KEY_START)
            break;

        swiWaitForVBlank();
    }
    
    exit(0);
}
