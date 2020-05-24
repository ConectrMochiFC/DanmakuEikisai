#include "DxLib.h"
#include "Ex.h"
#include <math.h>
#define PI 3.141593

void tamabaku();
int DEL_S = -1;
double size = 1.0;
double t1_f = 4.0;
int t2_z = 6;

int bflg = 0;
int t2cou = 0;
int hanflgT = 0;

void ONE_TS1() {

	switch (mode) {
	case 1:
		t1_f =8.0;
		hakkyou = 30;
		break;
	case 2:
		t1_f = 10.0;
		hakkyou = 20;
		break;
	case 3:
		t1_f = 20.0;
		hakkyou = 12;
		break;
	case 4:
		t1_f = 10.0;
		hakkyou = 5;
		break;
	case 5:
		t1_f = 15.0;
		hakkyou = 3;
		break;
	default:
		break;
	}

	for (int s = 0; s<50000; s++) {
		if (TyuShot.counter == hakkyou * s) {
			for (int j = (int)t1_f * s; j<(int)t1_f * (s + 1); j++) {

				TyuShot.TyuShots[j].x = TyuShot.mem_ex;//�e��X���W�ɓG��X���W����
				TyuShot.TyuShots[j].y = TyuShot.mem_ey;//�e��Y���W�ɓG��Y���W����
				TyuShot.TyuShots[j].flag = 1;//���˃t���O�𗧂Ă�

				if (j == 3 * s)//��񂾂����@��_��
					TyuShot.TyuShots[3 * s].angle = atan2(TyuShot.mem_py - TyuShot.mem_ey, TyuShot.mem_px - TyuShot.mem_ex) - 1.04;
				else//��������ɓ��Ԋu�ŊԂ��󂯂�
					TyuShot.TyuShots[j].angle = TyuShot.TyuShots[3 * s].angle + 2.0f*(90 / 5) * (double)j / t1_f;

			}
			StopSoundMem(sound_enemy_shot[0]);
			PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);
		}
	}
	for (int j = 0; j<50000; j++) {//50�̓�
		if (TyuShot.TyuShots[j].flag == 1) {//���˂���Ă�����͈̂ړ�
			TyuShot.TyuShots[j].x += (3.0 + kasoku)*cos(TyuShot.TyuShots[j].angle)*2.0f;//X�̈ړ�
			TyuShot.TyuShots[j].y += (3.0 + kasoku)*sin(TyuShot.TyuShots[j].angle)*2.0f;//Y�̈ړ�
		}
	}
}

void ONE_TS2() {

	switch (mode) {
	case 1:
		t1_f = 8.0;
		hakkyou = 30;
		break;
	case 2:
		t1_f = 12.0;
		hakkyou = 20;
		break;
	case 3:
		t1_f = 20.0;
		hakkyou = 10;
		break;
	case 4:
		t1_f = 25.0;
		hakkyou = 6; //t2_z = 8;
		break;
	case 5:
		t1_f = 30.0;
		hakkyou = 4; t2_z = 5; hanflgT = 4;
		break;
	default:
		break;
	}

	//t2cou++;

	for (int s = 0; s<1500; s++) {//�P��ɂ͂P�O����
		if (s == 0)
			size = 1.5;
		if (TyuShot.counter == hakkyou * s) {//10�J�E���g�ɂP��
			for (int j = (int)t1_f * s; j<(int)t1_f * (s + 1); j++) {//���͔z��̒��g�̔ԍ��Ȃ̂łO�`�P�X�A�Q�O�`�R�X�Ƃ����悤�Ɍv�Z����

				TyuShot.TyuShots[j].x = TyuShot.mem_ex;//���W���X
				TyuShot.TyuShots[j].y = TyuShot.mem_ey;//���W���Y
				TyuShot.TyuShots[j].flag = 1;//���˃t���O�𗧂Ă�

				//if (t2cou == 180) {
					TyuShot.TyuShots[j].ran = (double)GetRand(10000) / 100;
			//	}

				if (s % t2_z == 0)//�ŏ��̂ЂƂ͎��@�_��
					TyuShot.TyuShots[0].angle = atan2(zikiy - TyuShot.mem_ey, zikix - TyuShot.mem_ex);
				else if (TyuShot.TyuShots[j].ran <= 50 && mode>=3) {
					TyuShot.TyuShots[j].angle = atan2(zikiy - TyuShot.mem_ey, zikix - TyuShot.mem_ex);
				}
				else TyuShot.TyuShots[j].angle = TyuShot.TyuShots[0].angle + 2.0f*PI * (double)j / t1_f;
				if (mode >= 4) {
					if (s % (t2_z - 2))//��͂R�U�O�x��20�������đS���ʒe�ɂ���
					TyuShot.TyuShots[j].angle = TyuShot.TyuShots[0].angle + 2.0f*PI * (double)j / (t1_f*1.5);
					else if (s % (t2_z - 4))
					TyuShot.TyuShots[j].angle = TyuShot.TyuShots[0].angle + 2.0f*PI * (double)j / (t1_f*2);
				}
			}
			StopSoundMem(sound_enemy_shot[0]);//�o�Ă�����������
			PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//�����o��
		}
	}

	double old_x[1500 * 40], old_y[1500 * 40];
	for (int j = 0; j<1500 * t1_f; j++) {
		old_x[j] = TyuShot.TyuShots[j].x;
		old_y[j] = TyuShot.TyuShots[j].y;
		TyuShot.TyuShots[j].x += (3.0 + kasoku)*cos(TyuShot.TyuShots[j].angle)*2.0f;//X�̈ړ�
		TyuShot.TyuShots[j].y += (3.0 + kasoku)*sin(TyuShot.TyuShots[j].angle)*2.0f;//Y�̈ړ�
		TyuShot.TyuShots[j].disp_angle = atan2(TyuShot.TyuShots[j].y - old_y[j], TyuShot.TyuShots[j].x - old_x[j]) - 1.57;
	}
}

void ONE_TSCon() {

	if (tyuboss.hp >= (Thp-5) && tyuboss.hp<Thp && bflg==0) {
		TyuShot.counter = 0;
		tamabaku();
	}
	else if (TyuShot.flag == 1) {
		if (TyuShot.pattern == 1)
			ONE_TS1();
		if (TyuShot.pattern == 2) {
			ONE_TS2();
			DEL_S = -1;
		}
	}


}

void ONE_TSDisp() {
	if (TyuShot.flag == 1) {
		TyuShot.counter++;
		for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
			if (TyuShot.TyuShots[j].flag == 1) {
				DrawRotaGraph((int)TyuShot.TyuShots[j].x + (int)Shokx, (int)TyuShot.TyuShots[j].y + (int)Shoky, size, TyuShot.TyuShots[j].disp_angle, img_enemy_shot[TyuShot.img], TRUE);
				if (hanflgT == 4 && TyuShot.TyuShots[j].y < 0) TyuShot.TyuShots[j].hf = 1;
				if (TyuShot.TyuShots[j].hf == 1) {
					TyuShot.TyuShots[j].angle *= -1; TyuShot.TyuShots[j].hf = 0;
				}
				else if (TyuShot.TyuShots[j].x<0 || TyuShot.TyuShots[j].x>838.0 || TyuShot.TyuShots[j].y < 0 || TyuShot.TyuShots[j].y>930) {
					Han++; TyuShot.TyuShots[j].flag = 0;
				}
			}
		}
	}
	if (TyuShot.flag == 1) {
		for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
			if (TyuShot.TyuShots[j].flag == 1)
				return;
		}
		TyuShot.flag = 0;
	}
}


void ONE_TSAta() {
	if (hidan == 0) {
		if (bombOK == 0) {
			for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {//�S�Ă̓G�̒e��
				if (TyuShot.TyuShots[j].flag == 1) {//���̒e�����˒��Ȃ�
					double x, y;
					//int range;
					x = (int)(TyuShot.TyuShots[j].x - zikix);
					y = (int)(TyuShot.TyuShots[j].y - zikiy);
					//range=9;

					if ((int)sqrt(x*x + y*y) < (int)(PLAYER_X_SIZE - 42) / 2.0f*1.2) {
						if (ModeM == 1) Miss++;
						else hidan = 1;

						TyuShot.TyuShots[j].flag = 0;
						if (CheckSoundMem(sound_enemy_death) == 1)
							StopSoundMem(sound_enemy_death);
						PlaySoundMem(sound_enemy_death, DX_PLAYTYPE_BACK);
					}
				}
			}
		}
	}
}


void tamabaku() {

	if (DEL_S<16)
		DEL_S++;

	for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
		if (TyuShot.TyuShots[j].x != 0 && TyuShot.TyuShots[j].y != 0) {
			if (DEL_S == 0 && TyuShot.TyuShots[j].flag)
				score += 21;
			TyuShot.TyuShots[j].flag = 0;
			DrawRotaGraph((int)TyuShot.TyuShots[j].x, (int)TyuShot.TyuShots[j].y, 0.8, 0.0, img_tamabaku[DEL_S], TRUE);
		}
		if (DEL_S == 15) {
			TyuShot.TyuShots[j].x = 0;
			TyuShot.TyuShots[j].y = 0;
			bflg = 1;
		}
	}
	if (DEL_S == 0)
		PlaySoundMem(sound_shot_del, DX_PLAYTYPE_BACK);


}


void RS_3() {
	DEL_S = -1;
	size = 1.0; bflg = 0;
	t1_f = 4.0; t2_z = 6; t2cou = 0; hanflgT = 0;
	Miss = 0;
}