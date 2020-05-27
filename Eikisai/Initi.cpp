#include "DxLib.h"
#include "Ex.h"

void Conf(void) {
	ChangeWindowMode(TRUE);
	SetGraphMode(MAPX, MAPY, 32);
	SetWindowSizeChangeEnableFlag(TRUE);
	SetAlwaysRunFlag(TRUE);
	SetMainWindowText("弾幕影葵彩");
	if (DxLib_Init() == -1) exit(1);
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawArea(0, 0, 1280, 960);
}


void initialization() {

	//-----------------------------------------タイトルのデータ------------------------------------------//

	n1 = n2 = n3 = n4 = n5 = 1.5;
	m1 = m2 = m3 = m4 = m5 = 0.0;

	x1 = -320;
	sentaku = 1;

	//---------------------------------------ゲーム画面のデータ----------------------------------------//
	//背景
	backs = 480;
	menmozi = mozimozi = 0;

	//自機関係
	zikix = 430; zikiy = 840;
	i = n = j = count2  = stop = stocon = name = name2 = 0;
	count = 0;
	namehai = 1; tenmetu = 128;
	//その他細かいもの
	stage = 1; score = 0;
	dai2 = dai3 = dai4 = 0;
	bsf = 0; hakkyou = 0;
	hakkyou_3 = 20.0f;
	pattern = 1; frame = 17; itemOK = 0;

	life = LIFE; bomb = BOMB;
	life_p = bomb_p = hidan = 0;
	gameover = 0; makkura = 0;

	//音楽関係

	dotyufin = bossout = lastout = 255;

	SetLoopPosSoundMem(232, sound_dotyu);
	SetLoopPosSoundMem(5738, sound_boss);
	SetLoopPosSoundMem(3029, sound_last);
	/*
	ChangeVolumeSoundMem(255 * 20 / 100, sound_enemy_shot[0]);
	ChangeVolumeSoundMem(255 * 20 / 100, sound_player_shot[0]);
	ChangeVolumeSoundMem(255 * 30 / 100, sound_enemy_death);
	ChangeVolumeSoundMem(255 * 30 / 100, sound_keikoku);

	ChangeVolumeSoundMem(dotyufin, sound_dotyu);
	ChangeVolumeSoundMem(bossout * 80 / 100, sound_boss);
	ChangeVolumeSoundMem(lastout, sound_last);*/

	//弾幕、敵関係
	kasoku = 0;
	for (int s = 0; s<100; s++) {
		enex[s] = 0; eney[s] = 0;
	}


	for (int sho1 = 0; sho1<PLAYER_MAX_SHOT1; sho1++)
		for (int sho2 = 0; sho2<PLAYER_MAX_SHOT2; sho2++)
			PlayerShot[sho1][sho2].flag = 0;

	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {
		enemy[i].flag = 0;
		enemy[i].counter = 0;
		EnemyShot[i].flag = 0;
		EnemyShot[i].counter = 0;
		for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
			EnemyShot[i].EnemyShots[j].flag = 0;
			EnemyShot[i].EnemyShots[j].disp_angle = 0;
			EnemyShot[i].EnemyShots[j].speed = 0;
			TyuShot.TyuShots[j].flag = 0;
			TyuShot.TyuShots[j].disp_angle = 0;
			TyuShot.TyuShots[j].speed = 0;
			BossShot.BossShots[j].flag = 0;
			BossShot.BossShots[j].disp_angle = 0;
			BossShot.BossShots[j].speed = 0;
		}
	}

	tyuboss.flag = 0;
	tyuboss.counter = 0;
	TyuShot.flag = 0;
	TyuShot.counter = 0;

	boss.flag = 0;
	boss.counter = 0;
	BossShot.flag = 0;
	BossShot.counter = 0;

	//最後にタイトルに戻す

	scene = 0; RSOK = 0;

	//---------------------------------------------------------------------------------------------------//

}

void SetColor() {
	Green = GetColor(0, 255, 0);
	White = GetColor(255, 255, 255);
	Red = GetColor(255, 0, 0);
	Blue = GetColor(0, 0, 255);
	Black = GetColor(0, 0, 0);
}

void Loading() {
	static int lcount = 0;

	lcount++;

	DrawFormatString(100, 350, White, "Now Loading");
	for (int i = 0; i < lcount / 20; i++) DrawFormatString((200 + (i * 5)), 350, White, ".");
	if (lcount > 60) lcount = 0;

	DrawFormatString(100, 400, GetColor(255, 255, 255), "非同期読み込みの数 %d", GetASyncLoadNum());
	if (GetASyncLoadNum() == 0) {
		scene = 1;
		lcount = 0;
	}
}