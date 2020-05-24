#include "Dxlib.h"
#include <math.h>
#include "Ex.h"


void ZakoBomb() {

	for (int s = 0; s<ENEMY_TOTAL_NUM; s++) {//全敵100体分
		for (j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
			if (EnemyShot[s].EnemyShots[j].x>zikix - 150 * bombsize && EnemyShot[s].EnemyShots[j].y>zikiy - 150 * bombsize
				&& EnemyShot[s].EnemyShots[j].x<zikix + 150 * bombsize && EnemyShot[s].EnemyShots[j].y<zikiy + 150 * bombsize) {
				if (EnemyShot[s].EnemyShots[j].flag)
					score += 21;
				EnemyShot[s].EnemyShots[j].flag = 0;
			}
		}
		if (enemy[s].flag == 1) {//その敵が出現中なら

			if (enemy[s].x>zikix - 150 * bombsize && enemy[s].y>zikiy - 150 * bombsize
				&& enemy[s].x<zikix + 150 * bombsize && enemy[s].y<zikiy + 150 * bombsize) {
				if (enemy[s].hp>0) {
					enemy[s].hp--;
					score++;
				}
				if (enemy[s].hp <= 0) {
					enemy[s].flag = 0;
					enex[s] = (int)enemy[s].x;
					eney[s] = (int)enemy[s].y;
					bakuha = 1; score += 50;
					dai2 = 0;
					if (CheckSoundMem(sound_enemy_death) == 1)
						StopSoundMem(sound_enemy_death);
					PlaySoundMem(sound_enemy_death, DX_PLAYTYPE_BACK);
				}

				if (CheckSoundMem(sound_enemy_tyakudan) == 1)
					StopSoundMem(sound_enemy_tyakudan);
				PlaySoundMem(sound_enemy_tyakudan, DX_PLAYTYPE_BACK);
			}
		}
	}

}


void TyuBomb() {
	for (j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
		if (TyuShot.TyuShots[j].x > zikix - 150 * bombsize && TyuShot.TyuShots[j].y > zikiy - 150 * bombsize
			&& TyuShot.TyuShots[j].x < zikix + 150 * bombsize && TyuShot.TyuShots[j].y < zikiy + 150 * bombsize) {
			if (TyuShot.TyuShots[j].flag == 1) {
				if (TyuShot.TyuShots[j].x <= (tyuboss.x - 150) || TyuShot.TyuShots[j].x >= (tyuboss.x + 150) ||
					TyuShot.TyuShots[j].y <= (tyuboss.y - 150) || TyuShot.TyuShots[j].y >= (tyuboss.y + 150)) {
					score += 23;
					TyuShot.TyuShots[j].flag = 0;
				}
			}
		}
	}
	if (tyuboss.flag == 1) {//中ボスが出現中なら

		if (tyuboss.x>zikix - 150 * bombsize && tyuboss.y>zikiy - 150 * bombsize
			&& tyuboss.x<zikix + 150 * bombsize && tyuboss.y<zikiy + 150 * bombsize) {
			if (tyuboss.hp>0) {
				score++;
			}
			if (tyuboss.hp <= 0) {
				tyuboss.flag = 0;
				enex[0] = (int)tyuboss.x;
				eney[0] = (int)tyuboss.y;
				bakuha = 1; dai2 = 0; score += 2200;
				frame = 51; bsf = 1;

				if (CheckSoundMem(sound_tb_death) == 1)
					StopSoundMem(sound_tb_death);
				PlaySoundMem(sound_enemy_death, DX_PLAYTYPE_BACK);
			}

			if (CheckSoundMem(sound_enemy_tyakudan) == 1)
				StopSoundMem(sound_enemy_tyakudan);
			PlaySoundMem(sound_enemy_tyakudan, DX_PLAYTYPE_BACK);
		}
	}
}


void BossBomb() {
	for (j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
		if (BossShot.BossShots[j].x>zikix - 150 * bombsize && BossShot.BossShots[j].y>zikiy - 150 * bombsize
			&& BossShot.BossShots[j].x<zikix + 150 * bombsize && BossShot.BossShots[j].y<zikiy + 150 * bombsize) {
			if (BossShot.BossShots[j].flag == 1) {
				if (BossShot.BossShots[j].x <= (boss.x - 150) || BossShot.BossShots[j].x >= (boss.x + 150) ||
					BossShot.BossShots[j].y <= (boss.y - 150) || BossShot.BossShots[j].y >= (boss.y + 150)) {
					score += 23;
					BossShot.BossShots[j].flag = 0;
				}
			}
		}
	}
	if (boss.flag == 1) {//ボスが出現中なら

		if (boss.x>zikix - 150 * bombsize && boss.y>zikiy - 150 * bombsize
			&& boss.x<zikix + 150 * bombsize && boss.y<zikiy + 150 * bombsize) {
			if (boss.hp >= 120) {
				score++;
			}
			if (boss.hp <= 0) {
				boss.flag = 0;
				gekiha = 1;
				BossShot.flag = 0;

			}

			if (CheckSoundMem(sound_enemy_tyakudan) == 1)
				StopSoundMem(sound_enemy_tyakudan);
			PlaySoundMem(sound_enemy_tyakudan, DX_PLAYTYPE_BACK);
		}
	}
}