#include "DxLib.h"
#include "Ex.h"
#include <math.h>
#define PI 3.141593

int con = 0, conb = 0, idou, move, migi, hidari;
int cau1 = 820, cau2 = -40, gyaku = 0, ED = 0, aka = 0, obi = 0, san = 0, bi = 0, bis = 0;
int P2c, P3c;

void ONE_EP1(int i) {//上から直線で下へ（左側）

	int j;
	enemy[i].y += 3.0f;

	if (enemy[i].counter % 40 == 0) {
		for (j = 0; j<10; j++)
			if (EnemyShot[j].flag == 0)
				break;
		EnemyShot[j].mem_ex = enemy[i].x;
		EnemyShot[j].mem_ey = enemy[i].y;
		EnemyShot[j].mem_px = 838;
		EnemyShot[j].mem_py = 930;
		EnemyShot[j].counter = 0;
		EnemyShot[j].flag = 1;
		EnemyShot[j].pattern = 2;
		EnemyShot[j].img = 0;
	}

}

void ONE_EP2(int i) {//上から下（右側)

	int j;
	enemy[i].y += 3.0f;

	if (enemy[i].counter % 40 == 0) {
		for (j = 0; j<10; j++)
			if (EnemyShot[j].flag == 0)
				break;
		EnemyShot[j].mem_ex = enemy[i].x;
		EnemyShot[j].mem_ey = enemy[i].y;
		EnemyShot[j].mem_px = 0;
		EnemyShot[j].mem_py = 930;
		EnemyShot[j].counter = 0;
		EnemyShot[j].flag = 1;
		EnemyShot[j].pattern = 3;
		EnemyShot[j].img = 0;
	}

}

void ONE_EP3(int i) {//3Way弾を撃たせる

	int j;
	if (enemy[i].counter<50)
		enemy[i].y += 2.0f;
	if (enemy[i].counter == 120) {
		for (j = 0; j<10; j++)
			if (EnemyShot[j].flag == 0)
				break;
		EnemyShot[j].mem_ex = enemy[i].x;
		EnemyShot[j].mem_ey = enemy[i].y;
		EnemyShot[j].mem_px = zikix;
		EnemyShot[j].mem_py = zikiy;
		EnemyShot[j].counter = 0;
		EnemyShot[j].flag = 1;
		EnemyShot[j].pattern = 4;
		EnemyShot[j].img = 0;
	}
	if (enemy[i].counter>300)
		enemy[i].y -= 2.0f;

}

void ONE_EP4(int i) {//上から来て画面上で止まり、上に帰る

	int j;
	if (enemy[i].counter<50)
		enemy[i].y += 3.0f;
	if (enemy[i].counter == 75) {
		for (j = 0; j<10; j++)
			if (EnemyShot[j].flag == 0)
				break;
		EnemyShot[j].mem_ex = enemy[i].x;
		EnemyShot[j].mem_ey = enemy[i].y;
		EnemyShot[j].mem_px = zikix;
		EnemyShot[j].mem_py = zikiy;
		EnemyShot[j].counter = 0;
		EnemyShot[j].flag = 1;
		EnemyShot[j].pattern = pattern;
		EnemyShot[j].img = 0;
	}
	if (enemy[i].counter>235)
		enemy[i].y -= 2.0f;

}

void ONE_TBOSS() {

	if (tyuboss.counter<120) {
		tyuboss.x -= 4;
		tyuboss.y += 2;
		con++;
	}
	DrawRotaGraph((int)tyuboss.x + (int)Shokx, (int)tyuboss.y + (int)Shoky, tyuboss.size, sin(-PI / 2 / 60 * con)*(PI / 12), img_tyuboss, TRUE);
	DrawFormatString((int)tyuboss.x - 20 + (int)Shokx, (int)tyuboss.y - 65 + (int)Shoky, GetColor(0, 0, 0), "LP %.1f", tyuboss.hp);

	if (tyuboss.hp >= Thp) {
		if (tyuboss.counter >= 150) {
			if (tyuboss.counter == 150) {
				TyuShot.mem_px = zikix;
				TyuShot.mem_py = zikiy;
				TyuShot.counter = 0;
				TyuShot.flag = 1;
				TyuShot.pattern = 1;
				TyuShot.img = 0;
			}
			TyuShot.mem_ex = tyuboss.x;
			TyuShot.mem_ey = tyuboss.y;
		}
	}



	if (tyuboss.hp<Thp) {
		if (dai2 == 0) {
			tyuboss.counter = 120;
			dai2 = 1;
		}
		if (tyuboss.counter >= 180) {
			if (tyuboss.counter == 180) {
				TyuShot.mem_px = zikix;
				TyuShot.mem_py = zikiy;
				TyuShot.counter = 0;
				TyuShot.flag = 1;
				TyuShot.pattern = 2;
				TyuShot.img = 2;
				dai2 = 1;
			}
			TyuShot.mem_ex = tyuboss.x;
			TyuShot.mem_ey = tyuboss.y;
		}

	}

}

void ONE_BOSS() {

	idou = 0;

	if (boss.counter == 0) {
		switch (mode) {
		case 1:
			boss.hp = 1000.0;
			P2c = 700;
			P3c = 400;
			break;
		case 2:
			boss.hp = 1400.0;
			P2c = 950;
			P3c = 500;
			break;
		case 3:
			boss.hp = 1800.0;
			P2c = 1250;
			P3c = 700;
			break;
		case 4:
			boss.hp = 2100.0;
			P2c = 1450;
			P3c = 800;
			break;
		case 5:
			boss.hp = 2500.0;
			P2c = 1700;
			P3c = 900;
			break;
		default:
			break;
		}
		if(mode<4)	boss.df = 100;
		else boss.df = 50;
		boss.counter = 0;
		boss.size = 1.8f;
		boss.range = (int)((64 - 8) / 2.0f*boss.size);
		boss.x = 404;
		boss.y = -165;
	}
	DrawRotaGraph((int)boss.x + (int)Shokx, (int)boss.y + (int)Shoky, boss.size, sin(-PI / 2 / 60 * conb)*(PI / 12), img_1boss[boss.counter / 4 % 4], TRUE);
	DrawFormatString((int)boss.x - 30 + (int)Shokx, (int)boss.y - 85 + (int)Shoky, GetColor(0, 0, 0), "LP %.1f", boss.hp);

	if (boss.counter>120 && boss.counter <= 480) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)aka);
		DrawRotaGraph(60, 62, 2.0, 0.0, img_caution[2], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)obi);
		DrawRotaGraph(cau1, 200, 2.0, 0.0, img_caution[0], TRUE);
		DrawRotaGraph(cau2, 800, 2.0, 0.0, img_caution[0], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)san);
		DrawRotaGraph(cau1 - 256, 500, 1.5, 0.0, img_caution[1], TRUE);
		DrawRotaGraph(cau1 + 256, 500, 1.5, 0.0, img_caution[1], TRUE);
		DrawRotaGraph(cau1 + 768, 500, 1.5, 0.0, img_caution[1], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		if (ED == 0) {
			if (aka<180)
				aka += 2;
			if (obi<258)
				obi += 3;

			if (san == 0)
				gyaku = 1;
			if (san == 258)
				gyaku = 0;

			if (gyaku == 1)
				san += 6;
			if (gyaku == 0)
				san -= 6;

			if (aka == 2) {
				PlaySoundMem(sound_keikoku, DX_PLAYTYPE_BACK);
				bis = 1;
			}
			if (bis == 1)
				bi++;
			if (bi % 88 == 0) {
				if (CheckSoundMem(sound_keikoku) == 1)
					StopSoundMem(sound_keikoku);
				PlaySoundMem(sound_keikoku, DX_PLAYTYPE_BACK);
			}
		}
		if (boss.counter>360) {
			if (san == 258)
				ED = 1;
			if (ED == 1) {
				aka -= 4;
				obi -= 6;
				san -= 6;
			}
		}

		cau1 -= 2;
		cau2 += 2;
	}

	if (boss.counter>480 && boss.counter <= 600)
		boss.y += 3;

	if (boss.counter >= 660) {
		if (boss.hp >= P2c) {
			if (boss.counter == 660) {
				StopSoundMem(sound_dotyu);
				PlaySoundMem(sound_boss, DX_PLAYTYPE_LOOP);
				boss.flag = 1;
				stop = 0;
				BossShot.mem_px = zikix;
				BossShot.mem_py = zikiy;
				BossShot.counter = 0;
				BossShot.flag = 1;
				BossShot.pattern = 1;
				BossShot.img = 0;
			}
			BossShot.mem_ex = boss.x;
			BossShot.mem_ey = boss.y;
		}

		else if (boss.hp >= P3c) {
			if (dai2 == 0) {
				boss.counter = 660;
				dai2 = 1;
			}
			if (boss.counter >= 780) {
				if (boss.counter == 780) {
					boss.flag = 1;
					stop = 0;
					BossShot.mem_px = zikix;
					BossShot.mem_py = zikiy;
					BossShot.counter = 0;
					BossShot.flag = 1;
					BossShot.pattern = 2;
					BossShot.img = 0;
				}
				BossShot.mem_ex = boss.x;
				BossShot.mem_ey = boss.y;
			}
		}
		else {
			if (dai3 == 0) {
				boss.counter = 660;
				dai3 = 1;
			}
			if (boss.counter <= 780)
				bossout -= 2;
			if (boss.counter >= 780) {
				if (boss.counter == 780) {
					boss.flag = 1;
					stop = 0; boss.muteki = 0;
					BossShot.mem_px = zikix;
					BossShot.mem_py = zikiy;
					BossShot.counter = 0;
					BossShot.flag = 1;
					BossShot.pattern = 3;
					BossShot.img = 2;
					StopSoundMem(sound_boss);
					PlaySoundMem(sound_last, DX_PLAYTYPE_LOOP);
				}
				BossShot.mem_ex = boss.x;
				BossShot.mem_ey = boss.y;
			}
		}


		if (boss.counter % 400 == 0) {
			move = 1;
			if (zikix - boss.x<0)
				hidari = 1;
			if (zikix - boss.x >= 0)
				migi = 1;
		}
		if (move == 1) {
			if (idou == 0 && hidari && migi == 0) {
				if (conb<120) {
					conb++;
					if(boss.x>=80) boss.x--;
				}
				if (conb >= 119) {
					conb = 0;
					move = 0;
					hidari = 0;
				}
			}
			if (idou == 0 && migi && hidari == 0) {
				if (conb>-120) {
					conb--;
					if(boss.x<=760) boss.x++;
				}
				if (conb <= -119) {
					conb = 0;
					move = 0;
					migi = 0;
				}
			}
		}

		/*if (BossShot.pattern == 1) {
			if (boss.hp >= 1720)
				hakkyou = 4;
			else if (boss.hp >= 1620)
				hakkyou = 3;
			else if (boss.hp >= 1500)
				hakkyou = 2;
			else
				hakkyou = 1;
		}
		if (BossShot.pattern == 2) {
			if (boss.hp >= 1200)
				hakkyou = 0.2f;
			else if (boss.hp >= 1100)
				hakkyou = 0.15f;
			else if (boss.hp >= 1000)
				hakkyou = 0.10f;
			else
				hakkyou = 0.05f;
		}
		if (BossShot.pattern == 3) {
			if (boss.hp >= 680)
				hakkyou = 20;
			else if (boss.hp >= 580)
				hakkyou = 15;
			else if (boss.hp >= 440)
				hakkyou = 10;
			else if (boss.hp >= 320) {
				hakkyou = 15;
				hakkyou_3 = 30.0f;
			}
			else if (boss.hp >= 240)
				hakkyou_3 = 36.0f;
			else if (boss.hp >= 150)
				hakkyou = 10;
			else if (boss.hp >= 120) {
				hakkyou_3 = 36.0f;
				hakkyou = 15;
			}
			else {
				hakkyou = 20;
				hakkyou_3 = 60.0f;
			}
		}*/

	}

	boss.counter++;

	if (boss.counter>410 && boss.counter<540)
		dotyufin -= 2;

}

void ONE_EneCon() {
	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {
		if (enemy[i].flag == 1) {
			if (enemy[i].pattern == 1)
				ONE_EP1(i);
			if (enemy[i].pattern == 2)
				ONE_EP2(i);
			if (enemy[i].pattern == 3)
				ONE_EP3(i);
			if (enemy[i].pattern == 4)
				ONE_EP4(i);
		}
	}
	if (tyuboss.flag == 1) {
		tyuboss.counter++;
		ONE_TBOSS();
	}
	if (bsf == 1)
		ONE_BOSS();
}

void ONE_EneDisp() {

	int i;
	for (i = 0; i<ENEMY_TOTAL_NUM; i++)
		if (enemy[i].flag == 0)
			break;

	switch (count) {
	case 60:
		for (i = 0; i<3; i++) {
			enemy[i].pattern = 4; //どういう軌道を描くか
			enemy[i].flag = 1;   //出現フラグを立てる
			enemy[i].hp = 20;
			enemy[i].counter = 0;//出現して何カウント目か測るカウンター初期化
			enemy[i].size = 0.5f;//敵の大きさ
			enemy[i].range = (int)((MONSTER1_X_SIZE - 60) / 2.0f*enemy[i].size); //※画像サイズから余白の部分60ピクセルを引く
			enemy[i].x = 230.0 + i * 200;  //ｘの初期座標
			enemy[i].y = -10.0;  //ｙの初期座標
		}
		break;

	case 840:
	case 870:
	case 900:
		enemy[i].pattern = 1; //どういう軌道を描くか
		enemy[i].flag = 1;   //出現フラグを立てる
		enemy[i].hp = 20;
		enemy[i].counter = 0;//出現して何カウント目か測るカウンター初期化
		enemy[i].size = 0.5f;//敵の大きさ
		enemy[i].range = (int)((MONSTER1_X_SIZE - 60) / 2.0f*enemy[i].size); //※画像サイズから余白の部分60ピクセルを引く
		enemy[i].x = 180.0;  //ｘの初期座標
		enemy[i].y = -10.0;  //ｙの初期座標
		break;

	case 1260:
	case 1290:
	case 1320:
		enemy[i].pattern = 2; //どういう軌道を描くか
		enemy[i].flag = 1;   //出現フラグを立てる
		enemy[i].hp = 20;
		enemy[i].counter = 0;//出現して何カウント目か測るカウンター初期化
		enemy[i].size = 0.5f;//敵の大きさ
		enemy[i].range = (int)((MONSTER1_X_SIZE - 60) / 2.0f*enemy[i].size); //※画像サイズから余白の部分60ピクセルを引く
		enemy[i].x = 720.0;  //ｘの初期座標
		enemy[i].y = -10.0;  //ｙの初期座標
		break;

	case 1800:
		for (i = 0; i<3; i++) {
			enemy[i].pattern = 3; //どういう軌道を描くか
			enemy[i].flag = 1;   //出現フラグを立てる
			enemy[i].hp = 20;
			enemy[i].counter = 0;//出現して何カウント目か測るカウンター初期化
			enemy[i].size = 0.5f;//敵の大きさ
			enemy[i].range = (int)((MONSTER1_X_SIZE - 60) / 2.0f*enemy[i].size); //※画像サイズから余白の部分60ピクセルを引く
			enemy[i].x = 230.0 + i * 200;  //ｘの初期座標
			enemy[i].y = -10.0;  //ｙの初期座標
		}
		break;

	case 2340:
		tyuboss.flag = 1;
		switch (mode) {
		case 1:
			tyuboss.hp = 350.0;
			break;
		case 2:
			tyuboss.hp = 500.0;
			break;
		case 3:
			tyuboss.hp = 700.0;
			break;
		case 4:
			tyuboss.hp = 1000.0;
			break;
		case 5:
			tyuboss.hp = 1300.0;
			break;
		default:
			break;
		}
		Thp = tyuboss.hp / 2;
		tyuboss.df = 50;
		tyuboss.counter = 0;
		tyuboss.size = 0.8f;
		tyuboss.range = (int)((130 - 34) / 2.0f*tyuboss.size);
		tyuboss.x = 900;
		tyuboss.y = -20;


	default:
		break;

	}

	int enemy_img[8] = { 0,1,2,3,4,3,2,1 };
	for (i = 0; i<ENEMY_TOTAL_NUM; i++) {
		if (enemy[i].flag == 1) {
			enemy[i].counter++;
			DrawRotaGraph((int)enemy[i].x + (int)Shokx, (int)enemy[i].y + (int)Shoky, enemy[i].size, 0.0f, img_enemy1[enemy_img[counter % 32 / 4]], TRUE);
			if (enemy[i].x<0.0 - MONSTER1_X_SIZE / 2.0*enemy[i].size || enemy[i].x>840.0 + MONSTER1_X_SIZE / 2.0*enemy[i].size ||
				enemy[i].y<0.0 - MONSTER1_Y_SIZE / 2.0*enemy[i].size || enemy[i].y>960.0 - MONSTER1_Y_SIZE / 2.0*enemy[i].size)
				enemy[i].flag = 0;
		}
	}

}


void RS_2() {

	con = conb = idou = move = migi = hidari = 0;
	cau1 = 820, cau2 = -40, gyaku = ED = aka = obi = san = bi = bis = 0;
	BossShot.counter = 0;

}