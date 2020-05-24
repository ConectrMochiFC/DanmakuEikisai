#include "DxLib.h"
#include "Ex.h"
#include <math.h>
#define PI 3.141593
#define PATTERN1SPEED 2.0f

//-----------------------------------------------------------------１発だけ---------------------------------------------------------------//

void ONE_ES1(int i) {//自機狙い5発
	for (int j = 0; j<5; j++) {
		if (enemy[i].flag) {
			if (EnemyShot[i].counter == 30 * j) {
				EnemyShot[i].EnemyShots[j].flag = 1;//発射フラグを立てる
				EnemyShot[i].EnemyShots[j].x = EnemyShot[i].mem_ex;//弾のX座標に敵の座標を代入
				EnemyShot[i].EnemyShots[j].y = EnemyShot[i].mem_ey;//Yも同様
				EnemyShot[i].EnemyShots[0].angle = atan2(EnemyShot[i].mem_py - EnemyShot[i].mem_ey, EnemyShot[i].mem_px - EnemyShot[i].mem_ex);
				//敵とプレイヤーとの角度を計算

				StopSoundMem(sound_enemy_shot[0]);//前のショットの音とダブらないようにショット音を消す
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//ショット音を出す
			}
		}
		EnemyShot[i].EnemyShots[j].x += 3.0*cos(EnemyShot[i].EnemyShots[0].angle);//弾のX座標を増加
		EnemyShot[i].EnemyShots[j].y += 3.0*sin(EnemyShot[i].EnemyShots[0].angle);//弾のY座標を増加
	}
}

void ONE_ES2(int i) {//消えるまで永遠と単発弾(左から右)

	kasoku += 0.0005;

	for (int j = 0; j<10; j++) {

		if (j == 0)
			kasoku = 0;

		if (EnemyShot[i].counter == 40 * j) {
			if (enemy[i].flag == 1) {
				EnemyShot[i].EnemyShots[j].flag = 1;//発射フラグを立てる
				EnemyShot[i].EnemyShots[j].x = enemy[i].x;//弾のX座標に敵の座標を代入
				EnemyShot[i].EnemyShots[j].y = enemy[i].y;//Yも同様
				EnemyShot[i].EnemyShots[0].angle = atan2(EnemyShot[i].mem_py - EnemyShot[i].mem_ey, EnemyShot[i].mem_px - EnemyShot[i].mem_ex);
				//敵とプレイヤーとの角度を計算
			}
			if (enemy[i].flag) {
				StopSoundMem(sound_enemy_shot[0]);//前のショットの音とダブらないようにショット音を消す
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//ショット音を出す
			}
		}

		EnemyShot[i].EnemyShots[j].x += (3.0 + kasoku)*cos(EnemyShot[i].EnemyShots[0].angle);//弾のX座標を増加
		EnemyShot[i].EnemyShots[j].y += (3.0 + kasoku)*sin(EnemyShot[i].EnemyShots[0].angle);//弾のY座標を増加

	}

}

void ONE_ES3(int i) {//消えるまで(右から左)

	kasoku += 0.0005;

	for (int j = 0; j<10; j++) {

		if (j == 0)
			kasoku = 0;

		if (EnemyShot[i].counter == 40 * j) {
			if (enemy[i].flag == 1) {
				EnemyShot[i].EnemyShots[j].flag = 1;//発射フラグを立てる
				EnemyShot[i].EnemyShots[j].x = enemy[i].x;//弾のX座標に敵の座標を代入
				EnemyShot[i].EnemyShots[j].y = enemy[i].y;//Yも同様
				EnemyShot[i].EnemyShots[0].angle = atan2(EnemyShot[i].mem_py - EnemyShot[i].mem_ey, EnemyShot[i].mem_px - EnemyShot[i].mem_ex);
				//敵とプレイヤーとの角度を計算
			}
			if (enemy[i].flag) {
				StopSoundMem(sound_enemy_shot[0]);//前のショットの音とダブらないようにショット音を消す
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//ショット音を出す
			}
		}

		EnemyShot[i].EnemyShots[j].x += (3.0 + kasoku)*cos(EnemyShot[i].EnemyShots[0].angle);//弾のX座標を増加
		EnemyShot[i].EnemyShots[j].y += (3.0 + kasoku)*sin(EnemyShot[i].EnemyShots[0].angle);//弾のY座標を増加

	}

}


void ONE_ES4(int i) {//自機狙いつつの回転弾

	for (int s = 0; s<10; s++) {
		if (enemy[i].flag) {
			if (s == 0)
				kasoku = 0;

			if (EnemyShot[i].counter == 20 * s) {
				for (j = 3 * s; j<3 * (s + 1); j++) {

					EnemyShot[i].EnemyShots[j].x = EnemyShot[i].mem_ex;//座標代入X
					EnemyShot[i].EnemyShots[j].y = EnemyShot[i].mem_ey;//座標代入Y
					EnemyShot[i].EnemyShots[j].flag = 1;//発射フラグを立てる

					if (j == 3 * s)
						EnemyShot[i].EnemyShots[3 * s].angle = atan2(zikiy - EnemyShot[i].mem_ey, zikix - EnemyShot[i].mem_ex);
					else
						EnemyShot[i].EnemyShots[j].angle = EnemyShot[i].EnemyShots[3 * s].angle + PI / 4 * (double)j / 3.0f;
				}
				StopSoundMem(sound_enemy_shot[0]);//出ていた音を消す
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//音を出す
			}
		}
	}

	for (int j = 0; j<30; j++) {//全30個の内、
		if (EnemyShot[i].EnemyShots[j].flag == 1) {//発射されてるものは移動させる
			EnemyShot[i].EnemyShots[j].x += (3.0 + kasoku)*cos(EnemyShot[i].EnemyShots[j].angle)*2.0f;//X座標移動
			EnemyShot[i].EnemyShots[j].y += (3.0 + kasoku)*sin(EnemyShot[i].EnemyShots[j].angle)*2.0f;//Y座標移動
		}
	}

}

//---------------------------------------------------------------ここまで道中-----------------------------------------------------------//



void ONE_ESCon() {
	int i;
	for (i = 0; i<ENEMY_TOTAL_NUM; i++) {
		if (EnemyShot[i].flag == 1) {
			if (EnemyShot[i].pattern == 1)
				ONE_ES1(i);
			if (EnemyShot[i].pattern == 2)
				ONE_ES2(i);
			if (EnemyShot[i].pattern == 3)
				ONE_ES3(i);
			if (EnemyShot[i].pattern == 4)
				ONE_ES4(i);

		}
	}
}

void ONE_ESDisp() {
	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {
		if (EnemyShot[i].flag == 1) {
			EnemyShot[i].counter++;
			for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
				if (EnemyShot[i].EnemyShots[j].flag == 1) {
					DrawRotaGraph((int)EnemyShot[i].EnemyShots[j].x + (int)Shokx, (int)EnemyShot[i].EnemyShots[j].y + (int)Shoky, 1.0f, EnemyShot[i].EnemyShots[j].disp_angle, img_enemy_shot[EnemyShot[i].img], TRUE);
					if (EnemyShot[i].EnemyShots[j].x<0 || EnemyShot[i].EnemyShots[j].x>838.0 || EnemyShot[i].EnemyShots[j].y<0 || EnemyShot[i].EnemyShots[j].y>930)
						EnemyShot[i].EnemyShots[j].flag = 0;
				}
			}
		}
	}
	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {
		if (EnemyShot[i].flag == 1) {
			for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
				if (EnemyShot[i].EnemyShots[j].flag == 1)
					return;
			}
			EnemyShot[i].flag = 0;
		}
	}
}


void ONE_ESAta() {
	if (hidan == 0) {
		if (bombOK == 0) {
			for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {//全ての敵分
				for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {//全ての敵の弾分
					if (EnemyShot[i].EnemyShots[j].flag == 1) {//その弾が発射中なら
						double x, y;
						//int range;
						x = (int)(EnemyShot[i].EnemyShots[j].x - zikix);
						y = (int)(EnemyShot[i].EnemyShots[j].y - zikiy);
						//range=9;

						if ((int)sqrt(x*x + y*y) < (int)(PLAYER_X_SIZE - 42) / 2.0f*1.2) {
							hidan = 1;

							EnemyShot[i].EnemyShots[j].flag = 0;
							if (CheckSoundMem(sound_enemy_death) == 1)
								StopSoundMem(sound_enemy_death);
							PlaySoundMem(sound_enemy_death, DX_PLAYTYPE_BACK);
						}
					}
				}
			}
		}
	}
}