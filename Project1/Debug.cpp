#include "Debug.h"

void Debug::Main()
{
   DrawFrame();
   Stop();
   Exit();
}

void Debug::DrawFrame()
{
    if(CheckHitKey( KEY_INPUT_SPACE) != 0)
    {
        for(int i=0; i<50; i++)
        {
            for(int j=0; j<50; j++)
            {
                if(j%5 == 0 || i%5 == 0)  color = GetColor(0,0,255);
				else          color = GetColor(255, 0, 0);
                DrawBox(i*32,j*32,i*32+32,j*32+32,color,FALSE);
            }
        }
    }
}

void Debug::Stop()
{
	if (CheckHitKey(KEY_INPUT_A) != 0) flag = true;
	if (CheckHitKey(KEY_INPUT_S) != 0) flag = false;

	if (flag == true) WaitKey();
}

void Debug::Exit()
{
    if(CheckHitKey(KEY_INPUT_ESCAPE) != 0) DxLib_End();
}
    