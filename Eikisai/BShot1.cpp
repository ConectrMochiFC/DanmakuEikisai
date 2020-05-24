#include "DxLib.h"
#include "Ex.h"
#include "math.h"
#define PI 3.141593

void baku();
double bsize = 1.0;
int DEL_BS = -1, sss = 1, bbflg = 0, bcflg = 0;
int hanflg = 0, hanv = 1;

void ONE_BS1() {

	switch (mode) {
	case 1:
		hakkyou = 8;
		break;
	case 2:
		hakkyou = 5;
		break;
	case 3:
		if(boss.hp>=1650) hakkyou = 4;
		else if (boss.hp >= 1500) hakkyou = 3;
		else hakkyou = 2;
		break;
	case 4:
		if(boss.hp>=1950) hakkyou = 2;
		else if (boss.hp >= 1750) hakkyou = 1;
		else hanflg = 4;
		break;
	case 5:
		if(boss.hp>=2300) hakkyou = 2;
		else if (boss.hp >= 2050) hakkyou = 1;
		else {
			hakkyou = 1; hanflg = 1;
		}
		break;
	default:
		break;
	}

	for (int j = 0; j<12000; j++) {//�v120������
		if (BossShot.counter == hakkyou*j) {//2��Ɉ���������^�ɂ���
			BossShot.BossShots[j].x = BossShot.mem_ex;//�G��X�ɒe��X��
			BossShot.BossShots[j].y = BossShot.mem_ey;//�G��Y�ɒe��Y��
			BossShot.BossShots[j].flag = 1;//���˃t���O�𗧂Ă�
			BossShot.BossShots[j].speed = GetRand(2000) / 1000.0f - 1.0f;
			if (mode >= 4) BossShot.BossShots[j].speed += 0.001;

			BossShot.BossShots[j].angle =
				atan2(zikiy - BossShot.mem_ey, zikix - BossShot.mem_ex) + (double)GetRand(10000) / 10000 * (PI * 2);
			//360�x�̒����烉���_�����쐬
			Kcon++;
			if (BossShot.counter % 24 == 0) {
				StopSoundMem(sound_enemy_shot[0]);
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);
			}
		}
	}
	for (int j = 0; j<12000; j++) {//200�̓��A
		if (BossShot.BossShots[j].flag == 1) {//�t���O�������Ă���͈̂ړ�
			BossShot.BossShots[j].x += (2.0 + BossShot.BossShots[j].speed)*cos(BossShot.BossShots[j].angle)*hanv;//X�̈ړ�
			BossShot.BossShots[j].y += (2.0 + BossShot.BossShots[j].speed)*sin(BossShot.BossShots[j].angle)*hanv;//Y�̈ړ�
			/*if (BossShot.BossShots[j].hf == 1) {
				BossShot.BossShots[j].x += (2.0 + BossShot.BossShots[j].speed)*cos(BossShot.BossShots[j].angle)*-1;//X�̈ړ�
				BossShot.BossShots[j].y += (2.0 + BossShot.BossShots[j].speed)*sin(BossShot.BossShots[j].angle)*-1;//Y�̈ړ�
				BossShot.BossShots[j].hf = 0;
			}*/
		}
	}
}

void ONE_BS2() {

	switch (mode) {
	case 1:
		hakkyou = 5;
		hakkyou_3 = 1.0;
		break;
	case 2:
		hakkyou = 3;
		hakkyou_3 = 0.5;
		break;
	case 3:
		hakkyou = 1;
		if(boss.hp>=1100) hakkyou_3 = 0.2;
		else if (boss.hp >= 950) hakkyou_3 = 0.15;
		else hakkyou_3 = 0.1;
		break;
	case 4:
		hakkyou = 1;
		hanflg = 0;
		if(boss.hp>=1300) hakkyou_3 = 0.12;
		else if (boss.hp >= 1100) hakkyou_3 = 0.06;
		else {
			hakkyou_3 = 0.06;
			hanflg = 4;
		}
		break;
	case 5:
		hakkyou = 1;
		hanflg = 0;
		if (boss.hp >= 1500) hakkyou_3 = 0.05;
		else if (boss.hp >= 1250) hanflg = 4;
		else hanflg = 1;
	}

	for (int j = 0; j<12600; j++) {//���̐�����
		if (BossShot.counter == hakkyou*j) {
			BossShot.BossShots[j].flag = 1;//���˃t���O�𗧂Ă�
			BossShot.BossShots[j].x = BossShot.mem_ex;//�e��X���W�ɓG�̍��W����
			BossShot.BossShots[j].y = BossShot.mem_ey;//�e��Y���W�����l
			if (j == 0)
				BossShot.BossShots[j].angle = atan2(BossShot.mem_py - BossShot.mem_ey, BossShot.mem_px - BossShot.mem_ex);
			//�ŏ������@�_��
			else
				BossShot.BossShots[j].angle = BossShot.BossShots[j - 1].angle + hakkyou_3;
			//�Ԃ͔�������Ƌ����Ȃ�
			Kcon++;
			if (BossShot.counter % 24 == 0) {
				StopSoundMem(sound_enemy_shot[0]);//�o�Ă�����������
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//�V���ɉ����o��
			}
		}
		//angle�ɉ��Z�����ʂ͂ǂ�ǂ񑝂���̂�
		//�����������悤�ɂ���

		BossShot.BossShots[j].x += 2.5f*cos(BossShot.BossShots[j].angle)*hanv;
		BossShot.BossShots[j].y += 2.5f*sin(BossShot.BossShots[j].angle)*hanv;
	}
}

void ONE_BS3() {

	switch (mode) {
	case 1:
		hakkyou = 30;
		hakkyou_3 = 8;
		break;
	case 2:
		hakkyou = 20;
		hakkyou_3 = 15;
		break;
	case 3:
		if (boss.hp>=500) {
			hakkyou = 20;
			hakkyou_3 = 20;
		}
		else if (boss.hp >= 300) {
			hakkyou = 15;
			hakkyou_3 = 25;
		}
		else {
			hakkyou = 30;
			hakkyou_3 = 30;
		}
		break;
	case 4:
		if (boss.hp >= 650) {
			hakkyou = 12; hakkyou_3 = 20;
		}
		else if (boss.hp >= 450) {
			hakkyou = 10; hakkyou_3 = 25;
		}
		else if (boss.hp >= 250) {
			hakkyou = 30; hakkyou_3 = 30; hanflg = 0;
		}
		else {
			hakkyou = 15; hakkyou_3 = 30; hanflg = 4;
		}
		break;
	case 5:
		hanflg = 4;
		if (boss.hp >= 750) {
			hakkyou = 12; hakkyou_3 = 25;
		}
		else if (boss.hp >= 550) {
			hakkyou = 8; hakkyou_3 = 20;
		}
		else if (boss.hp >= 350) {
			hakkyou = 8; hakkyou_3 = 30;
		}
		else if (boss.hp >= 200) {
			hakkyou = 6; hakkyou_3 = 28; hanflg = 4;
		}
		else {
			hakkyou = 10; hakkyou_3 = 30; hanflg = 1;
		}
	default:
		break;
	}

	for (int s = 0; s<5000; s++) {//���ɂ͂P�O����
		if (s == 0)
			bsize = 1.5;
		if (BossShot.counter == hakkyou*s) {//���̃J�E���g�ɂP��
			for (int j = (int)hakkyou_3*s; j < (int)hakkyou_3*(s + 1); j++) {//�S���ʒe�̔z�u����

				BossShot.BossShots[j].x = BossShot.mem_ex;//�e��X���W�ɓG��X���W����
				BossShot.BossShots[j].y = BossShot.mem_ey;//�e��Y���W�ɓG��Y���W����
				BossShot.BossShots[j].flag = 1;//���˃t���O�𗧂Ă�

				if (j == hakkyou_3*s)//��񂾂����@��_��
					BossShot.BossShots[(int)hakkyou_3*s].angle = atan2(zikiy - BossShot.mem_ey, zikix - BossShot.mem_ex);
				else//��������ɓ��Ԋu�ŊԂ��󂯂�
					BossShot.BossShots[j].angle = BossShot.BossShots[(int)hakkyou_3*s].angle + 2.0f*PI * (double)j / hakkyou_3;

				switch (mode) {
				case 1:
					if (boss.hp >= 200) speed[j] = 1.5;
					else if (boss.hp >= 100) speed[j] = 2.0;
					else speed[j] = 2.5;
					break;
				case 2:
					if (boss.hp >= 400) speed[j] = 1.5;
					else if (boss.hp >= 300) speed[j] = 2.0;
					else if (boss.hp >= 200) speed[j] = 2.5;
					else speed[j] = 3.0;
					break;
				case 3:
					if (boss.hp >= 500) speed[j] = 2.0;
					else if (boss.hp >= 300) speed[j] = 1.5;
					else speed[j] = 0.5f + (double)GetRand(2000) / 1000.0f;
					break;
				case 4:
					if (boss.hp >= 600) speed[j] = 2.5;
					else if (boss.hp >= 450) speed[j] = 3.5;
					else speed[j] = 0.5f + (double)GetRand(3000) / 1000.0f;
				case 5:
					if (boss.hp >= 650) speed[j] = 3.0;
					else if (boss.hp >= 350) speed[j] = 2.5;
					else speed[j] = 0.5f + (double)GetRand(2000) / 1000.0f;
					break;
				default:
					break;
				}
				Kcon++;

			}
			if (BossShot.counter % 24 == 0) {
				StopSoundMem(sound_enemy_shot[0]);//��������
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//�V���b�g�����o��
			}
		}
	}
	double old_x[1000*50], old_y[1000*50];
	for (int j = 0; j<1000 * hakkyou_3; j++) {
		old_x[j] = BossShot.BossShots[j].x;
		old_y[j] = BossShot.BossShots[j].y;
		BossShot.BossShots[j].x += speed[j] * cos(BossShot.BossShots[j].angle)*2.0f;//X�̈ړ�
		BossShot.BossShots[j].y += speed[j] * sin(BossShot.BossShots[j].angle)*2.0f;//Y�̈ړ�
		BossShot.BossShots[j].disp_angle = atan2(BossShot.BossShots[j].y - old_y[j], BossShot.BossShots[j].x - old_x[j]) - 1.57;
	}
}

void ONE_BSCon() {
	
	switch (mode) {
	case 1:
		if (boss.hp >= 695 && boss.hp < 700 && bbflg == 0)
			baku();
		if (boss.hp >= 395 && boss.hp < 400 && bcflg == 0) {
			baku();
		}
		break;
	case 2:
		if (boss.hp >= 945 && boss.hp < 950 && bbflg == 0)
			baku();
		if (boss.hp >= 495 && boss.hp < 500 && bcflg == 0) {
			baku();
		}
		break;
	case 3:
		if (boss.hp >= 1245 && boss.hp < 1250 && bbflg == 0)
			baku();
		if (boss.hp >= 695 && boss.hp < 700 && bcflg == 0) {
			baku();
		}
		break;
	case 4:
		if (boss.hp >= 1445 && boss.hp < 1450 && bbflg == 0)
			baku();
		if (boss.hp >= 795 && boss.hp < 800 && bcflg == 0) {
			baku();
		}
		break;
	case 5:
		if (boss.hp >= 1695 && boss.hp < 1700 && bbflg == 0)
			baku();
		if (boss.hp >= 895 && boss.hp < 900 && bcflg == 0) {
			baku();
		}
		break;
	}

	if (BossShot.flag == 1 && gekiha == 0 && stop == 0) {
		if (BossShot.pattern == 1)
			ONE_BS1();
		if (BossShot.pattern == 2) {
			ONE_BS2();
			DEL_BS = -1;
		}
		if (BossShot.pattern == 3) {
			ONE_BS3();
			DEL_BS = -1;
		}
	}
}

void ONE_BSDisp() {
	if (BossShot.flag == 1) {
		BossShot.counter++;
		for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
			if (BossShot.BossShots[j].flag == 1) {
				DrawRotaGraph((int)BossShot.BossShots[j].x + (int)Shokx, (int)BossShot.BossShots[j].y + (int)Shoky, bsize, BossShot.BossShots[j].disp_angle, img_enemy_shot[BossShot.img], TRUE);
				if (hanflg == 4 && BossShot.BossShots[j].y < 0) BossShot.BossShots[j].hf = 1;
				if (BossShot.BossShots[j].hf == 1) {
					BossShot.BossShots[j].angle *= -1; BossShot.BossShots[j].hf = 0;
				}
				else if (BossShot.BossShots[j].x < 0 || BossShot.BossShots[j].x>838 || BossShot.BossShots[j].y < 0 || BossShot.BossShots[j].y>930) {
					if (hanflg == 1 && BossShot.BossShots[j].han < 10) {
						/*hanv *= -1;*/ BossShot.BossShots[j].han++; Han++;
						BossShot.BossShots[j].angle *= -1;
					}
					else BossShot.BossShots[j].flag = 0;
				}
			}
		}
	}
	if (BossShot.flag == 1) {
		for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
			if (BossShot.BossShots[j].flag == 1)
				return;
		}
		BossShot.flag = 0;
	}
}

void ONE_BSAta() {
	if (hidan == 0) {
		if (bombOK == 0) {
			for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {//�S�Ă̓G�̒e��
				if (BossShot.BossShots[j].flag == 1) {//���̒e�����˒��Ȃ�
					double x, y; int co = 0;
					x = (int)(BossShot.BossShots[j].x - zikix);
					y = (int)(BossShot.BossShots[j].y - zikiy);

					if (co == 0) {
						if (BossShot.img == 0)
							x -= 2; y -= 2;
					}

					co++;

					if ((int)sqrt(x*x + y*y) < (int)(PLAYER_X_SIZE - 42) / 2.0f*1.2) {
						if (ModeM == 1) Miss++;
						else hidan = 1;

						BossShot.BossShots[j].flag = 0;
						if (CheckSoundMem(sound_enemy_death) == 1)
							StopSoundMem(sound_enemy_death);
						PlaySoundMem(sound_enemy_death, DX_PLAYTYPE_BACK);
					}

				}
			}
		}
	}
}

void baku() {

	if (DEL_BS == -1)
		stop = 1;

	if (DEL_BS<16)
		DEL_BS++;

	for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
		if (BossShot.BossShots[j].x != 0 && BossShot.BossShots[j].y != 0) {
			if (DEL_BS == 0 && BossShot.BossShots[j].flag)
				score += 21;
			BossShot.BossShots[j].flag = 0;
			DrawRotaGraph((int)BossShot.BossShots[j].x, (int)BossShot.BossShots[j].y, 0.8, 0.0, img_tamabaku[DEL_BS], TRUE);
		}
		if (DEL_BS == 15) {
			BossShot.BossShots[j].x = 0;
			BossShot.BossShots[j].y = 0;
			stop = 0; Kcon = 0;
			if (bbflg == 0) bbflg = 1;
			else {
				switch (mode) {
				case 1:
					if (boss.hp < 400) bcflg = 1;
					break;
				case 2:
					if (boss.hp < 500) bcflg = 1;
					break;
				case 3:
					if (boss.hp < 700) bcflg = 1;
					break;
				case 4:
					if (boss.hp < 800) bcflg = 1;
					break;
				case 5:
					if (boss.hp < 900) bcflg = 1;
					break;
				default:
					break;
				}
			}
		}
	}
	if (DEL_BS == 0)
		PlaySoundMem(sound_shot_del, DX_PLAYTYPE_BACK);

}

void RS_4() {
	bsize = 1.0;
	DEL_BS = -1, sss = 1; stop = 0; bbflg = 0; bcflg = 0;
	hanflg = 0; hanv = 1;
	if (CheckSoundMem(sound_boss) == 1) StopSoundMem(sound_boss);
	if (CheckSoundMem(sound_last) == 1) StopSoundMem(sound_last);
}