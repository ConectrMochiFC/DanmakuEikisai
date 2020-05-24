#include "DxLib.h"
#include "Ex.h"
#include "math.h"
#define PI 3.141592654

static int w, count22 = -1, old_zikix, old_zikiy;
int sarch, count3 = -1, concon, count33[100];
int count11 = -1, con28 = -1, count123, tyucon = 0, clear = 0, totitle = 0, bounas = 0;

int conover = 0, black = 0, mozi2, mozi3, mozi4, mozi5, mozi6, mozi7, mozi8;
int mozi1 = mozi2 = mozi3 = mozi4 = mozi5 = mozi6 = mozi7 = mozi8 = -30;

void Bhantei();
void ZakoBomb();
void TyuBomb();
void BossBomb();


void PlayerControl() {

	ata = 0; count22 = 0, tenmetu = 128;

	if (count % 15 == 0) {
		w = 0;
	}
	else if (count % 7 == 0) {
		w = 1;
	}
	if (hidan == 0 && bomb>0) {
		if (CheckHitKey(KEY_INPUT_X) == 1)
			bombOK = 1;
	}
	if (zikiy<200 && CheckHitKey(KEY_INPUT_LSHIFT) >= 1)
		kaisyu = 1;


	if (CheckHitKey(KEY_INPUT_LEFT) >= 1 && CheckHitKey(KEY_INPUT_RIGHT) == 0) {
		DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, 0 + sin(PI / 2 / 30 * name)*(PI / 8)*-1, ziki[w], TRUE);//自機の画像

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky + 1, 0.9, 0.0, img_game[2], TRUE);//判定の画像

		if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky + 1, 0.9, 0.0, img_game[2], TRUE);//右シフト用判定画像

	}

	if (CheckHitKey(KEY_INPUT_RIGHT) >= 1 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
		DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, 0 + sin(PI / 2 / 30 * name)*PI / 8, ziki[w], TRUE);

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky + 1, 0.9, 0.0, img_game[2], TRUE);

		if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky + 1, 0.9, 0.0, img_game[2], TRUE);

	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {

		if (name2 == 0)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, 0.0, ziki[w], TRUE);

		if (namehai == 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, sin(PI / 2 / name2*name)*PI / 8, ziki[w], TRUE);
		if (namehai == 2)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, sin(PI / 2 / name2*name)*(PI / 8)*-1, ziki[w], TRUE);

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1) {
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky + 1, 0.9, 0.0, img_game[2], TRUE);
		}

		if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky + 1, 0.9, 0.0, img_game[2], TRUE);

	}

	if (CheckHitKey(KEY_INPUT_RIGHT) >= 1 && CheckHitKey(KEY_INPUT_LEFT) >= 1) {

		if (name2 == 0)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, 0.0, ziki[w], TRUE);

		if (namehai == 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, sin(PI / 2 / name2*name)*PI / 8, ziki[w], TRUE);
		if (namehai == 2)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, sin(PI / 2 / name2*name)*(PI / 8)*-1, ziki[w], TRUE);

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky + 1, 0.9, 0.0, img_game[2], TRUE);

		if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky + 1, 0.9, 0.0, img_game[2], TRUE);

	}

}


void PlayerShotCalc() {
	int sho1, sho2;
	int positionx[11] = { 0,-10,10,-10,10,-15,15,-10,10,-10,10 }, positiony[11] = { -15,-2,-2,6,6,-6,-6,2,2,10,10 };

	if (CheckHitKey(KEY_INPUT_Z) >= 1 && counter % 8 == 0) {
		for (sho1 = 0; sho1<ShotLevel; sho1++) {
			for (sho2 = 0; sho2<PLAYER_MAX_SHOT2; sho2++) {
				if (PlayerShot[sho1][sho2].flag == 0) {
					PlayerShot[sho1][sho2].flag = 1;
					PlayerShot[sho1][sho2].x = zikix + (double)positionx[sho1];
					PlayerShot[sho1][sho2].y = zikiy + (double)positiony[sho1];

					if (CheckSoundMem(sound_player_shot[0]) == 1)  //現在ショット音が再生されていなければ
						StopSoundMem(sound_player_shot[0]);
					PlaySoundMem(sound_player_shot[0], DX_PLAYTYPE_BACK);  //ショット音を再生する
					break;
				}
			}
		}
	}
	int sab[11] = { 0,-1,1,-3,3,0,0,-2,2,-5,5 };
	for (sho1 = 0; sho1<PLAYER_MAX_SHOT1; sho1++) {
		for (sho2 = 0; sho2<PLAYER_MAX_SHOT2; sho2++) {
			if (PlayerShot[sho1][sho2].flag == 1) {
				PlayerShot[sho1][sho2].x += (double)sab[sho1];
				PlayerShot[sho1][sho2].y -= 10;
				if (PlayerShot[sho1][sho2].y<-20)
					PlayerShot[sho1][sho2].flag = 0;
			}
		}
	}
}

void PlayerShotDisp() {
	int sho1, sho2;
	for (sho1 = 0; sho1<PLAYER_MAX_SHOT1; sho1++) {
		for (sho2 = 0; sho2<PLAYER_MAX_SHOT2; sho2++) {
			if (PlayerShot[sho1][sho2].flag == 1) {
				switch (sho1) {
				case 0:
				case 5:
				case 6:
					DrawGraph((int)PlayerShot[sho1][sho2].x - 2, (int)PlayerShot[sho1][sho2].y - 33, img_player_shot[0], TRUE);
					break;
				default:
					DrawGraph((int)PlayerShot[sho1][sho2].x - 8, (int)PlayerShot[sho1][sho2].y - 10, img_player_shot[1], TRUE);
					break;
				}
			}
		}
	}
}



void CollisionDetection() {
	if (tyuboss.flag == 0) {
		for (int i = 0; i<PLAYER_MAX_SHOT1; i++) {//ショットの全列分
			for (int j = 0; j<PLAYER_MAX_SHOT2; j++) {//1列全弾分
				if (PlayerShot[i][j].flag == 1) {//その弾が発射中なら
					for (int s = 0; s<ENEMY_TOTAL_NUM; s++) {//全敵100体分
						if (enemy[s].flag == 1) {//その敵のショットが出現中なら
							double x, y;
							int range;
							x = (int)(PlayerShot[i][j].x - enemy[s].x);
							y = (int)(PlayerShot[i][j].y - enemy[s].y);
							switch (i) {
							case 0:
							case 5:
							case 6:
								range = 12;
								break;
							default:
								range = 9;
								break;
							}
							if ((int)sqrt(x*x + y*y) < range + enemy[s].range) {
								enemy[s].hp--;
								score += 11;
								if (enemy[s].hp == 0) {
									enemy[s].flag = 0;
									enex[s] = (int)enemy[s].x; eney[s] = (int)enemy[s].y;
									enix[s] = (int)enemy[s].x; eniy[s] = (int)enemy[s].y;
									score += 100;
									bakuha = 1; itemOK = 1;
									dai2 = 0;
									if (CheckSoundMem(sound_enemy_death) == 1)
										StopSoundMem(sound_enemy_death);
									PlaySoundMem(sound_enemy_death, DX_PLAYTYPE_BACK);
								}

								PlayerShot[i][j].flag = 0;
								if (CheckSoundMem(sound_enemy_tyakudan) == 1)
									StopSoundMem(sound_enemy_tyakudan);
								PlaySoundMem(sound_enemy_tyakudan, DX_PLAYTYPE_BACK);
							}
						}
					}
				}
			}
		}
	}
	if (tyuboss.flag) {
		if (tyuboss.muteki == 0) {
			for (int i = 0; i<PLAYER_MAX_SHOT1; i++) {//ショットの全列分
				for (int j = 0; j<PLAYER_MAX_SHOT2; j++) {//1列全弾分
					if (PlayerShot[i][j].flag == 1) {//その弾が発射中なら
						if (tyuboss.flag == 1) {//その敵のショットが出現中なら
							double x, y;
							int range;
							x = (int)(PlayerShot[i][j].x - tyuboss.x);
							y = (int)(PlayerShot[i][j].y - tyuboss.y);
							switch (i) {
							case 0:
							case 5:
							case 6:
								range = 12;
								break;
							default:
								range = 9;
								break;
							}
							if ((int)sqrt(x*x + y*y) < range + tyuboss.range) {
								if (tyuboss.hp>0) {
									tyuboss.hp -= 0.5;
									score += 21;
								}
								if (tyuboss.hp <= 0) {
									tyuboss.flag = 0;
									enex[0] = (int)tyuboss.x; eney[0] = (int)tyuboss.y;
									enix[0] = (int)tyuboss.x; eniy[0] = (int)tyuboss.y;
									bakuha = 1; dai2 = 0;
									frame = 51;
									bsf = 1; score += 3000;

									if (CheckSoundMem(sound_tb_death) == 1)
										StopSoundMem(sound_tb_death);
									PlaySoundMem(sound_tb_death, DX_PLAYTYPE_BACK);
								}

								PlayerShot[i][j].flag = 0;
								if (CheckSoundMem(sound_enemy_tyakudan) == 1)
									StopSoundMem(sound_enemy_tyakudan);
								PlaySoundMem(sound_enemy_tyakudan, DX_PLAYTYPE_BACK);
							}
						}
					}
				}
			}
		}

	}

	if (boss.flag) {
		if (boss.muteki == 0) {
			for (int i = 0; i<PLAYER_MAX_SHOT1; i++) {//ショットの全列分
				for (int j = 0; j<PLAYER_MAX_SHOT2; j++) {//1列全弾分
					if (PlayerShot[i][j].flag == 1) {//その弾が発射中なら
						if (boss.flag == 1) {//その敵のショットが出現中なら
							double x, y;
							int range;
							x = (int)(PlayerShot[i][j].x - boss.x);
							y = (int)(PlayerShot[i][j].y - boss.y);
							switch (i) {
							case 0:
							case 5:
							case 6:
								range = 12;
								break;
							default:
								range = 9;
								break;
							}
							if ((int)sqrt(x*x + y*y) < range + boss.range) {
								if (boss.hp<120 && boss.hp>0) {
									boss.hp -= 0.25;
									score += 31;
								}
								else {
									boss.hp -= 0.5;
									score += 21;
								}

								if (boss.hp <= 0) {
									boss.flag = 0;
									gekiha = 1;
									BossShot.flag = 0;
								}

								PlayerShot[i][j].flag = 0;
								if (CheckSoundMem(sound_enemy_tyakudan) == 1)
									StopSoundMem(sound_enemy_tyakudan);
								PlaySoundMem(sound_enemy_tyakudan, DX_PLAYTYPE_BACK);
							}
						}
					}
				}
			}
		}

	}

}



void Life() {

	if (ata == 0) {
		old_zikix = zikix;
		old_zikiy = zikiy;
		switch (mode) {
		case 1:
			bomb = 3;
			break;
		case 2:
			bomb = 3;
			break;
		case 3:
			bomb = 0;
			break;
		case 4:
			bomb = 0;
			break;
		default:
			break;
		}
		for (int sho1 = 0; sho1<PLAYER_MAX_SHOT1; sho1++)
			for (int sho2 = 0; sho2<PLAYER_MAX_SHOT2; sho2++)
				PlayerShot[sho1][sho2].flag = 0;
	}

	if (count % 15 == 0)
		w = 0;
	else if (count % 7 == 0)
		w = 1;


	if (ata == 0)
		life--;

	if (life <= 0 && count22 == 15)
		gameover = 1;

	if (count22 == 240)
		hidan = 0;
	if (count22 >= 120) {
		if (ata % 40 == 0) {
			tenmetu = 128;
		}
		else if (ata % 20 == 0)
			tenmetu = 255;

	}

	if (count22 <= 14)
		DrawRotaGraph((int)old_zikix, (int)old_zikiy, 2.0, 0.0, img_hidan[(int)count22], TRUE);

	ata++;
	if (ata % 2)
		count22++;

	if (ata >= 60) {

		if (ata == 60) {
			zikix = old_zikix;
			zikiy = old_zikiy;
		}


		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)tenmetu);


		if (CheckHitKey(KEY_INPUT_LEFT) >= 1 && CheckHitKey(KEY_INPUT_RIGHT) == 0)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, 0 + sin(PI / 2 / 30 * name)*(PI / 8)*-1, ziki[w], TRUE);//自機の画像

		if (CheckHitKey(KEY_INPUT_RIGHT) >= 1 && CheckHitKey(KEY_INPUT_LEFT) == 0)
			DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, 0 + sin(PI / 2 / 30 * name)*PI / 8, ziki[w], TRUE);

		if (CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {

			if (name2 == 0)
				DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, 0.0, ziki[w], TRUE);

			if (namehai == 1)
				DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, sin(PI / 2 / name2*name)*PI / 8, ziki[w], TRUE);
			if (namehai == 2)
				DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, sin(PI / 2 / name2*name)*(PI / 8)*-1, ziki[w], TRUE);


		}

		if (CheckHitKey(KEY_INPUT_RIGHT) >= 1 && CheckHitKey(KEY_INPUT_LEFT) >= 1) {

			if (name2 == 0)
				DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, 0.0, ziki[w], TRUE);

			if (namehai == 1)
				DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, sin(PI / 2 / name2*name)*PI / 8, ziki[w], TRUE);
			if (namehai == 2)
				DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, 1.2, sin(PI / 2 / name2*name)*(PI / 8)*-1, ziki[w], TRUE);


		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}


}

void Bomb() {
	if (concon >= 100) {
		if (concon == 100) {
			Shokx = 8.0; Shoky = 8.0;
			if (CheckSoundMem(sound_tame) == 1)
				StopSoundMem(sound_tame);
			PlaySoundMem(sound_bom, DX_PLAYTYPE_BACK);
		}
		Shokx = Shokx*-0.95;
		Shoky = Shoky*-0.95;
	}

	if (concon == 0) {

		bomb--;

		for (int sho1 = 0; sho1<PLAYER_MAX_SHOT1; sho1++)
			for (int sho2 = 0; sho2<PLAYER_MAX_SHOT2; sho2++)
				PlayerShot[sho1][sho2].flag = 0;
		if (CheckSoundMem(sound_tame) == 1)
			StopSoundMem(sound_tame);
		PlaySoundMem(sound_tame, DX_PLAYTYPE_BACK);
	}

	concon++;

	DrawRotaGraph((int)zikix + (int)Shokx, (int)zikiy + (int)Shoky, bombsize, 0.0, img_bomb, TRUE);

	if (concon<180 && bombsize<2.2)
		bombsize += 0.02;

	if (tyuboss.flag == 0 && bsf == 0)
		ZakoBomb();
	if (tyuboss.flag == 1)
		TyuBomb();
	if (bsf == 1 && boss.hp >= 120)
		BossBomb();

	if (concon >= 180 && bombsize>0)
		bombsize -= 0.02;

	if (concon == 360) {
		bombOK = 0;
		bombsize = 0;
		concon = 0;
	}




}


void Bakuha() {

	count3++;

	for (sarch = 0; sarch<ENEMY_TOTAL_NUM; sarch++) {
		if (enex[sarch] != 0 && eney[sarch] != 0) {

			if (count3 % 2 == 0)
				count33[sarch]++;

			DrawRotaGraph((int)enex[sarch], (int)eney[sarch], 2.0, 0.0, img_bakuha[(int)count33[sarch]], TRUE);
		}
		if (count33[sarch] == 15) {
			count33[sarch] = 0;
			enex[sarch] = 0; eney[sarch] = 0;
			bakuha = 0; count3 = -1;
			frame = 17;
		}
	}

	if (count >= 2300) {

		if (count3 % 2 == 0)
			tyucon++;

		for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {

			if (TyuShot.TyuShots[j].x != 0 && TyuShot.TyuShots[j].y != 0) {
				if (count3 == 1 && TyuShot.TyuShots[j].flag)
					score += 23;
				TyuShot.TyuShots[j].flag = 0;
				DrawRotaGraph((int)TyuShot.TyuShots[j].x, (int)TyuShot.TyuShots[j].y, 0.8, 0.0, img_tamabaku[tyucon], TRUE);
			}
			if (tyucon == 15) {
				TyuShot.TyuShots[j].x = 0;
				TyuShot.TyuShots[j].y = 0;
				bakuha = 0; count3 = -1; tyucon = 0; frame = 17;
			}
		}
	}


}


void Gekiha() {

	frame = 34;

	if (count11 <= 30)
		count11++;

	count123++;

	for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
		if (BossShot.BossShots[j].x != 0 && BossShot.BossShots[j].y != 0) {
			if (count11 == 1 && BossShot.BossShots[j].flag)
				score += 31;
			BossShot.BossShots[j].flag = 0;
			DrawRotaGraph((int)BossShot.BossShots[j].x, (int)BossShot.BossShots[j].y, 0.8, 0.0, img_tamabaku[count11 / 2], TRUE);
		}
		if (count11 / 2 == 15) {
			BossShot.BossShots[j].x = 0;
			BossShot.BossShots[j].y = 0;
		}
	}
	if (count11 == 0)
		PlaySoundMem(sound_shot_del, DX_PLAYTYPE_BACK);

	if (count123 >= 60) {
		if (con28 <= 30)
			con28++;
		if (count123 == 60) {
			PlaySoundMem(sound_b_death, DX_PLAYTYPE_BACK);
			bsf = 0;
			Shokx = 10.0;
			Shoky = 10.0;
		}
		if (count123<90)
			DrawRotaGraph((int)boss.x + (int)Shokx, (int)boss.y + (int)Shoky, 4.0, 0.0, img_bossbaku[con28 / 2], TRUE);
		Shokx = Shokx*-0.95;
		Shoky = Shoky*-0.95;
	}

	if (count123 >= 120) {
		frame = 17;
		if (count123 >= 240) {
			clear += 3;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)clear);
			DrawRotaGraph(401, 350, 1.0, 0.0, img_clear, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (bounas<30000) {
				score += 200;
				bounas += 200;
			}
		}
		if (count123 >= 350)
			lastout -= 2;
		if (count123 >= 360) {
			totitle += 8;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)totitle);
			DrawRotaGraph(680, 900, 1.0, 0.0, img_totitle, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		if (count123 == 480) {
			RSOK = 1; gekiha = 0;
			StopSoundMem(sound_last);
		}
	}

}

void GAMEOVER() {

	conover++;

	if (conover >= 50) {
		black += 3;
		if (CheckSoundMem(sound_dotyu) == 1)
			dotyufin -= 2;
		if (CheckSoundMem(sound_boss) == 1)
			bossout -= 2;
		if (CheckSoundMem(sound_last) == 1)
			lastout -= 2;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)black);
	DrawRotaGraph(640, 480, 1.0, 0.0, img_anten, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (conover == 180) {
		makkura = 1;
		if (CheckSoundMem(sound_dotyu) == 1)
			StopSoundMem(sound_dotyu);
		if (CheckSoundMem(sound_boss) == 1)
			StopSoundMem(sound_boss);
		if (CheckSoundMem(sound_last) == 1)
			StopSoundMem(sound_last);
	}

	if (conover >= 240) {
		DrawRotaGraph(488, mozi1, 1.5, 0.0, img_lose[0], TRUE);
		DrawRotaGraph(523, mozi2, 1.5, 0.0, img_lose[1], TRUE);
		DrawRotaGraph(563, mozi3, 1.5, 0.0, img_lose[2], TRUE);
		DrawRotaGraph(603, mozi4, 1.5, 0.0, img_lose[3], TRUE);
		DrawRotaGraph(668, mozi5, 1.5, 0.0, img_lose[4], TRUE);
		DrawRotaGraph(708, mozi6, 1.5, 0.0, img_lose[5], TRUE);
		DrawRotaGraph(748, mozi7, 1.5, 0.0, img_lose[6], TRUE);
		DrawRotaGraph(788, mozi8, 1.5, 0.0, img_lose[7], TRUE);

		if (mozi1<420)
			mozi1 += 15;
		else if (mozi2<420)
			mozi2 += 15;
		else if (mozi3<420)
			mozi3 += 15;
		else if (mozi4<420)
			mozi4 += 15;
		else if (mozi5<420)
			mozi5 += 15;
		else if (mozi6<420)
			mozi6 += 15;
		else if (mozi7<420)
			mozi7 += 15;
		else if (mozi8<420)
			mozi8 += 15;

	}

	if (conover == 510) {
		PlaySoundMem(sound_over, DX_PLAYTYPE_BACK);
	}

	if (conover >= 630) {
		totitle += 3;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)totitle);
		DrawRotaGraph(900, 800, 1.2, 0.0, img_totitle, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (conover == 900)
		RSOK = 1;

}


void RS_1() {

	w = 0; count22 = -1; old_zikix = 0; old_zikiy = 0;
	sarch = 0; count3 = -1; concon = 0, tyucon = 0;
	count11 = -1; con28 = -1; count123 = 0;
	ata = 0; count22 = 0; clear = 0; totitle = 0;

	Shokx = Shoky = bombOK = bakuha = gekiha = 0; bounas = 0;

	for (int i = 0; i<100; i++)
		count33[i] = 0;

	conover = 0; black = 0;
	mozi1 = mozi2 = mozi3 = mozi4 = mozi5 = mozi6 = mozi7 = mozi8 = -30;

}