#include "DxLib.h"
#include "Ex.h"
#include <math.h>

int tem1[100], tem2[100], tem3[100], tem4[100], tem5[100];
double tem1x[100], tem2x[100], tem3x[100], tem4x[100], tem5x[100];
double tem1y[100], tem2y[100], tem3y[100], tem4y[100], tem5y[100];

int IMcon = 0, ex = 0, excon = 0;

void Item() {

	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {
		if (item[i].flag == 0 && enix[i] != 0 && ex == 0) {
			item[i].x = enix[i];
			item[i].y = eniy[i];
			item[i].flag = 1;
			item[i].counter = 0;
			kaisyu = 0; enix[i] = 0; eniy[i] = 0;
			tem1[i] = tem2[i] = tem3[i] = tem4[i] = tem5[i] = 1;

			tem1x[i] = item[i].x - 40; tem1y[i] = item[i].y;
			tem2x[i] = item[i].x - 20; tem2y[i] = item[i].y - 30;
			tem3x[i] = item[i].x; tem3y[i] = item[i].y;
			tem4x[i] = item[i].x + 20; tem4y[i] = item[i].y - 30;
			tem5x[i] = item[i].x + 40; tem5y[i] = item[i].y;
		}

		if (item[i].flag && kaisyu == 0) {
			item[i].counter++;
			if (item[i].counter<60) {
				tem1y[i] -= 2;
				tem2y[i] -= 2;
				tem3y[i] -= 2;
				tem4y[i] -= 2;
				tem5y[i] -= 2;
			}
			else {
				tem1y[i] += 4;
				tem2y[i] += 4;
				tem3y[i] += 4;
				tem4y[i] += 4;
				tem5y[i] += 4;
			}
		}

	}

	for (int j = 0; j<ENEMY_TOTAL_NUM; j++) {
		if (item[j].flag == 1) {
			if (tem1[j])
				DrawRotaGraph((int)tem1x[j], (int)tem1y[j], 0.1, 0.0, img_item[0], TRUE);
			if (tem2[j])
				DrawRotaGraph((int)tem2x[j], (int)tem2y[j], 0.1, 0.0, img_item[0], TRUE);
			if (tem3[j])
				DrawRotaGraph((int)tem3x[j], (int)tem3y[j], 0.1, 0.0, img_item[0], TRUE);
			if (tem4[j])
				DrawRotaGraph((int)tem4x[j], (int)tem4y[j], 0.1, 0.0, img_item[0], TRUE);
			if (tem5[j])
				DrawRotaGraph((int)tem5x[j], (int)tem5y[j], 0.1, 0.0, img_item[0], TRUE);

			//-------------------------------------------------画面外処理-------------------------------------------------//

			if (tem1y[j] >= 950) {
				tem1[j] = 0;
				if (tem1[j] == 0 && tem2[j] == 0 && tem3[j] == 0 && tem4[j] == 0 && tem5[j] == 0 && ex == 0) {
					item[j].flag = 0; ex = 1;
				}
			}
			if (tem2y[j] >= 950) {
				tem2[j] = 0;
				if (tem1[j] == 0 && tem2[j] == 0 && tem3[j] == 0 && tem4[j] == 0 && tem5[j] == 0 && ex == 0) {
					item[j].flag = 0; ex = 1;
				}
			}
			if (tem3y[j] >= 950) {
				tem3[j] = 0;
				if (tem1[j] == 0 && tem2[j] == 0 && tem3[j] == 0 && tem4[j] == 0 && tem5[j] == 0 && ex == 0) {
					item[j].flag = 0; ex = 1;
				}
			}
			if (tem4y[j] >= 950) {
				tem4[j] = 0;
				if (tem1[j] == 0 && tem2[j] == 0 && tem3[j] == 0 && tem4[j] == 0 && tem5[j] == 0 && ex == 0) {
					item[j].flag = 0; ex = 1;
				}
			}
			if (tem5y[j] >= 950) {
				tem5[j] = 0;
				if (tem1[j] == 0 && tem2[j] == 0 && tem3[j] == 0 && tem4[j] == 0 && tem5[j] == 0 && ex == 0) {
					item[j].flag = 0; ex = 1;
				}
			}

			//--------------------------------------------------上部回収----------------------------------------------//

			if (kaisyu == 1 && hidan == 0) {
				IMcon++;
				//一個目
				if (tem1x[j]<zikix)
					tem1x[j] += 12;
				if (tem1x[j]>zikix)
					tem1x[j] -= 12;
				if (tem1y[j]<zikiy)
					tem1y[j] += 12;
				if (tem1y[j]>zikiy)
					tem1y[j] -= 12;
				//二個目
				if (tem2x[j]<zikix)
					tem2x[j] += 12;
				if (tem2x[j]>zikix)
					tem2x[j] -= 12;
				if (tem2y[j]<zikiy)
					tem2y[j] += 12;
				if (tem2y[j]>zikiy)
					tem2y[j] -= 12;
				//三個目
				if (tem3x[j]<zikix)
					tem3x[j] += 12;
				if (tem3x[j]>zikix)
					tem3x[j] -= 12;
				if (tem3y[j]<zikiy)
					tem3y[j] += 12;
				if (tem3y[j]>zikiy)
					tem3y[j] -= 12;
				//四個目
				if (tem4x[j]<zikix)
					tem4x[j] += 12;
				if (tem4x[j]>zikix)
					tem4x[j] -= 12;
				if (tem4y[j]<zikiy)
					tem4y[j] += 12;
				if (tem4y[j]>zikiy)
					tem4y[j] -= 12;
				//五個目
				if (tem5x[j]<zikix)
					tem5x[j] += 12;
				if (tem5x[j]>zikix)
					tem5x[j] -= 12;
				if (tem5y[j]<zikiy)
					tem5y[j] += 12;
				if (tem5y[j]>zikiy)
					tem5y[j] -= 12;

				if (IMcon == 120) {
					kaisyu = 0; IMcon = 0;
					item[j].flag = 0;
				}

			}

			//-----------------------------------------------------自機による吸引------------------------------------------//

			if (hidan == 0 && CheckHitKey(KEY_INPUT_LSHIFT) >= 1) {
				if (tem1x[j]>zikix - 50 && tem1x[j]<zikix + 50
					&& tem1y[j]>zikiy - 50 && tem1y[j]<zikiy + 50) {
					//一個目
					if (tem1x[j]<zikix + 50 && tem1x[j]>zikix)
						tem1x[j] -= 2;
					if (tem1x[j]>zikix - 50 && tem1x[j]<zikix)
						tem1x[j] += 2;
					if (tem1y[j]<zikiy + 50 && tem1y[j]>zikiy)
						tem1y[j] -= 2;
					if (tem1y[j]>zikiy - 50 && tem1y[j]<zikiy)
						tem1y[j] += 2;
				}
				if (tem2x[j]>zikix - 50 && tem2x[j]<zikix + 50
					&& tem2y[j]>zikiy - 50 && tem2y[j]<zikiy + 50) {
					//二個目
					if (tem2x[j]<zikix + 50 && tem2x[j]>zikix)
						tem2x[j] -= 2;
					if (tem2x[j]>zikix - 50 && tem2x[j]<zikix)
						tem2x[j] += 2;
					if (tem2y[j]<zikiy + 50 && tem2y[j]>zikiy)
						tem2y[j] -= 2;
					if (tem2y[j]>zikiy - 50 && tem2y[j]<zikiy)
						tem2y[j] += 2;
				}
				if (tem3x[j]>zikix - 50 && tem3x[j]<zikix + 50
					&& tem3y[j]>zikiy - 50 && tem3y[j]<zikiy + 50) {
					//三個目
					if (tem3x[j]<zikix + 50 && tem3x[j]>zikix)
						tem3x[j] -= 2;
					if (tem3x[j]>zikix - 50 && tem3x[j]<zikix)
						tem3x[j] += 2;
					if (tem3y[j]<zikiy + 50 && tem3y[j]>zikiy)
						tem3y[j] -= 2;
					if (tem3y[j]>zikiy - 50 && tem3y[j]<zikiy)
						tem3y[j] += 2;
				}
				if (tem4x[j]>zikix - 50 && tem4x[j]<zikix + 50
					&& tem4y[j]>zikiy - 50 && tem4y[j]<zikiy + 50) {
					//四個目
					if (tem4x[j]<zikix + 50 && tem4x[j]>zikix)
						tem4x[j] -= 2;
					if (tem4x[j]>zikix - 50 && tem4x[j]<zikix)
						tem4x[j] += 2;
					if (tem4y[j]<zikiy + 50 && tem4y[j]>zikiy)
						tem4y[j] -= 2;
					if (tem4y[j]>zikiy - 50 && tem4y[j]<zikiy)
						tem4y[j] += 2;
				}
				if (tem5x[j]>zikix - 50 && tem5x[j]<zikix + 50
					&& tem5y[j]>zikiy - 50 && tem5y[j]<zikiy + 50) {
					//五個目
					if (tem5x[j]<zikix + 50 && tem5x[j]>zikix)
						tem5x[j] -= 2;
					if (tem5x[j]>zikix - 50 && tem5x[j]<zikix)
						tem5x[j] += 2;
					if (tem5y[j]<zikiy + 50 && tem5y[j]>zikiy)
						tem5y[j] -= 2;
					if (tem5y[j]>zikiy - 50 && tem5y[j]<zikiy)
						tem5y[j] += 2;
				}
			}

			//---------------------------------------------------ここまで吸引-------------------------------------------//

		}
	}


	if (hidan == 0) {
		for (int s = 0; s<ENEMY_TOTAL_NUM; s++) {//全てのアイテム分
			if (item[s].flag == 1) {//そのアイテムが出ていたら
				if (tem1[s]) {
					//一個目のアイテム
					if (tem1x[s]>zikix - 20 && tem1x[s]<zikix + 20
						&& tem1y[s]>zikiy - 20 && tem1y[s]<zikiy + 20) {
						score += 200;
						tem1[s] = 0;
						if (tem1[s] == 0 && tem2[s] == 0 && tem3[s] == 0 && tem4[s] == 0 && tem5[s] == 0 && ex == 0) {
							item[s].flag = 0; ex = 1;
						}
						if (CheckSoundMem(sound_item) == 1)
							StopSoundMem(sound_item);
						PlaySoundMem(sound_item, DX_PLAYTYPE_BACK);
					}
				}
				if (tem2[s]) {
					//二個目のアイテム
					if (tem2x[s]>zikix - 20 && tem2x[s]<zikix + 20
						&& tem2y[s]>zikiy - 20 && tem2y[s]<zikiy + 20) {
						score += 200;
						tem2[s] = 0;
						if (tem1[s] == 0 && tem2[s] == 0 && tem3[s] == 0 && tem4[s] == 0 && tem5[s] == 0 && ex == 0) {
							item[s].flag = 0; ex = 1;
						}
						if (CheckSoundMem(sound_item) == 1)
							StopSoundMem(sound_item);
						PlaySoundMem(sound_item, DX_PLAYTYPE_BACK);
					}
				}
				if (tem3[s]) {
					//三個目のアイテム
					if (tem3x[s]>zikix - 20 && tem3x[s]<zikix + 20
						&& tem3y[s]>zikiy - 20 && tem3y[s]<zikiy + 20) {
						score += 200;
						tem3[s] = 0;
						if (tem1[s] == 0 && tem2[s] == 0 && tem3[s] == 0 && tem4[s] == 0 && tem5[s] == 0 && ex == 0) {
							item[s].flag = 0; ex = 1;
						}
						if (CheckSoundMem(sound_item) == 1)
							StopSoundMem(sound_item);
						PlaySoundMem(sound_item, DX_PLAYTYPE_BACK);
					}
				}
				if (tem4[s]) {
					//四個目のアイテム
					if (tem4x[s]>zikix - 20 && tem4x[s]<zikix + 20
						&& tem4y[s]>zikiy - 20 && tem4y[s]<zikiy + 20) {
						score += 200;
						tem4[s] = 0;
						if (tem1[s] == 0 && tem2[s] == 0 && tem3[s] == 0 && tem4[s] == 0 && tem5[s] == 0 && ex == 0) {
							item[s].flag = 0; ex = 1;
						}
						if (CheckSoundMem(sound_item) == 1)
							StopSoundMem(sound_item);
						PlaySoundMem(sound_item, DX_PLAYTYPE_BACK);
					}
				}
				if (tem5[s]) {
					//五個目のアイテム
					if (tem5x[s]>zikix - 20 && tem5x[s]<zikix + 20
						&& tem5y[s]>zikiy - 20 && tem5y[s]<zikiy + 20) {
						score += 200;
						tem5[s] = 0;
						if (tem1[s] == 0 && tem2[s] == 0 && tem3[s] == 0 && tem4[s] == 0 && tem5[s] == 0 && ex == 0) {
							item[s].flag = 0; ex = 1;
						}
						if (CheckSoundMem(sound_item) == 1)
							StopSoundMem(sound_item);
						PlaySoundMem(sound_item, DX_PLAYTYPE_BACK);
					}
				}
			}
		}
	}

	if (ex) {
		excon++;
		if (excon == 20) {
			ex = 0; excon = 0;
		}
	}



}


void RS_5() {

	IMcon = 0; ex = 0; excon = 0; kaisyu = 0; ex = 0; excon = 0;

	for (int i = 0; i<i; i++) {
		tem1[i] = tem2[i] = tem3[i] = tem4[i] = tem5[i] = 0;
		tem1x[i] = tem2x[i] = tem3x[i] = tem4x[i] = tem5x[i] = 0;
		tem1y[i] = tem2y[i] = tem3y[i] = tem4y[i] = tem5y[i] = 0;

		enix[i] = 0; eniy[i] = 0;

		item[i].flag = 0; item[i].counter = 0;
		item[i].x = 0; item[i].y = 0;

	}

}