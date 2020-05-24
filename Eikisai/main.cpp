#include "DxLib.h"
#include "MHeader.h"
#include "void.h"
#include <stdio.h>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int RefreshTime = 0;

	SetUseASyncLoadFlag(TRUE);
	Conf();
	initialization();
	SetColor();
	img_sound_load();
	SetUseASyncLoadFlag(FALSE);

//----------------------------------------------------------------------------------------------//

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		RefreshTime = GetNowCount();

		switch (scene) {
		case 0:
			Loading();
			break;
		case 1:
			Title_Calc();
			Background();
			if (CheckHitKey(KEY_INPUT_M) == 1) ModeM = 1;
			if (CheckHitKey(KEY_INPUT_N) == 1) ModeM = 0;
			break;
		case 2:
			if (makkura == 0) {
				//count = 0;
				count++;
				Background3();
				Game_Calc();
				if (hidan == 0) {
					if (bombOK == 0) {
						PlayerShotCalc();
						PlayerShotDisp();
					}
					PlayerControl();
				}

				if (stage == 1) {
					ONE_EneCon();
					ONE_EneDisp();

					if (tyuboss.flag == 0 && bsf == 0) {
						ONE_ESCon();
						ONE_ESDisp();
						ONE_ESAta();
					}
					else if (boss.flag == 0 && bsf == 0) {
						ONE_TSCon();
						ONE_TSDisp();
						ONE_TSAta();
					}
					else {
						ONE_BSCon();
						ONE_BSDisp();
						ONE_BSAta();
					}
				}

				CollisionDetection();

				if (hidan && gameover == 0) {
					if (ModeM==0){
						Life();
						if (ata >= 60) {
							PlayerShotCalc();
							PlayerShotDisp();
						}
					}
				}
				if (bombOK)
					Bomb();
				if (itemOK)
					Item();
				if (bakuha)
					Bakuha();
				if (gekiha)
					Gekiha();

				Background2();
				Score();
			}

			if (RSOK == 1)
				Reset();

			if (gameover == 1)
				GAMEOVER();
			//DrawRotaGraph(300,300,1.0,0,ziki[0],TRUE);
			break;
		case 3:
			ModeSele();
			if (CheckHitKey(KEY_INPUT_M) == 1) ModeM = 1;
			if (CheckHitKey(KEY_INPUT_N) == 1) ModeM = 0;
			break;
		default:
			break;
		}

		if (CheckHitKey(KEY_INPUT_BACK) == 1) Reset();

		FpsTimeFanction();
		counter++;
		if (owacon == 1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
		while (GetNowCount() - RefreshTime < frame);//1周の処理が17ミリ秒になるまで待つ
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}