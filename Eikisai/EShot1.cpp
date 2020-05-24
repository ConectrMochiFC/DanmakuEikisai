#include "DxLib.h"
#include "Ex.h"
#include <math.h>
#define PI 3.141593
#define PATTERN1SPEED 2.0f

//-----------------------------------------------------------------�P������---------------------------------------------------------------//

void ONE_ES1(int i) {//���@�_��5��
	for (int j = 0; j<5; j++) {
		if (enemy[i].flag) {
			if (EnemyShot[i].counter == 30 * j) {
				EnemyShot[i].EnemyShots[j].flag = 1;//���˃t���O�𗧂Ă�
				EnemyShot[i].EnemyShots[j].x = EnemyShot[i].mem_ex;//�e��X���W�ɓG�̍��W����
				EnemyShot[i].EnemyShots[j].y = EnemyShot[i].mem_ey;//Y�����l
				EnemyShot[i].EnemyShots[0].angle = atan2(EnemyShot[i].mem_py - EnemyShot[i].mem_ey, EnemyShot[i].mem_px - EnemyShot[i].mem_ex);
				//�G�ƃv���C���[�Ƃ̊p�x���v�Z

				StopSoundMem(sound_enemy_shot[0]);//�O�̃V���b�g�̉��ƃ_�u��Ȃ��悤�ɃV���b�g��������
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//�V���b�g�����o��
			}
		}
		EnemyShot[i].EnemyShots[j].x += 3.0*cos(EnemyShot[i].EnemyShots[0].angle);//�e��X���W�𑝉�
		EnemyShot[i].EnemyShots[j].y += 3.0*sin(EnemyShot[i].EnemyShots[0].angle);//�e��Y���W�𑝉�
	}
}

void ONE_ES2(int i) {//������܂ŉi���ƒP���e(������E)

	kasoku += 0.0005;

	for (int j = 0; j<10; j++) {

		if (j == 0)
			kasoku = 0;

		if (EnemyShot[i].counter == 40 * j) {
			if (enemy[i].flag == 1) {
				EnemyShot[i].EnemyShots[j].flag = 1;//���˃t���O�𗧂Ă�
				EnemyShot[i].EnemyShots[j].x = enemy[i].x;//�e��X���W�ɓG�̍��W����
				EnemyShot[i].EnemyShots[j].y = enemy[i].y;//Y�����l
				EnemyShot[i].EnemyShots[0].angle = atan2(EnemyShot[i].mem_py - EnemyShot[i].mem_ey, EnemyShot[i].mem_px - EnemyShot[i].mem_ex);
				//�G�ƃv���C���[�Ƃ̊p�x���v�Z
			}
			if (enemy[i].flag) {
				StopSoundMem(sound_enemy_shot[0]);//�O�̃V���b�g�̉��ƃ_�u��Ȃ��悤�ɃV���b�g��������
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//�V���b�g�����o��
			}
		}

		EnemyShot[i].EnemyShots[j].x += (3.0 + kasoku)*cos(EnemyShot[i].EnemyShots[0].angle);//�e��X���W�𑝉�
		EnemyShot[i].EnemyShots[j].y += (3.0 + kasoku)*sin(EnemyShot[i].EnemyShots[0].angle);//�e��Y���W�𑝉�

	}

}

void ONE_ES3(int i) {//������܂�(�E���獶)

	kasoku += 0.0005;

	for (int j = 0; j<10; j++) {

		if (j == 0)
			kasoku = 0;

		if (EnemyShot[i].counter == 40 * j) {
			if (enemy[i].flag == 1) {
				EnemyShot[i].EnemyShots[j].flag = 1;//���˃t���O�𗧂Ă�
				EnemyShot[i].EnemyShots[j].x = enemy[i].x;//�e��X���W�ɓG�̍��W����
				EnemyShot[i].EnemyShots[j].y = enemy[i].y;//Y�����l
				EnemyShot[i].EnemyShots[0].angle = atan2(EnemyShot[i].mem_py - EnemyShot[i].mem_ey, EnemyShot[i].mem_px - EnemyShot[i].mem_ex);
				//�G�ƃv���C���[�Ƃ̊p�x���v�Z
			}
			if (enemy[i].flag) {
				StopSoundMem(sound_enemy_shot[0]);//�O�̃V���b�g�̉��ƃ_�u��Ȃ��悤�ɃV���b�g��������
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//�V���b�g�����o��
			}
		}

		EnemyShot[i].EnemyShots[j].x += (3.0 + kasoku)*cos(EnemyShot[i].EnemyShots[0].angle);//�e��X���W�𑝉�
		EnemyShot[i].EnemyShots[j].y += (3.0 + kasoku)*sin(EnemyShot[i].EnemyShots[0].angle);//�e��Y���W�𑝉�

	}

}


void ONE_ES4(int i) {//���@�_���̉�]�e

	for (int s = 0; s<10; s++) {
		if (enemy[i].flag) {
			if (s == 0)
				kasoku = 0;

			if (EnemyShot[i].counter == 20 * s) {
				for (j = 3 * s; j<3 * (s + 1); j++) {

					EnemyShot[i].EnemyShots[j].x = EnemyShot[i].mem_ex;//���W���X
					EnemyShot[i].EnemyShots[j].y = EnemyShot[i].mem_ey;//���W���Y
					EnemyShot[i].EnemyShots[j].flag = 1;//���˃t���O�𗧂Ă�

					if (j == 3 * s)
						EnemyShot[i].EnemyShots[3 * s].angle = atan2(zikiy - EnemyShot[i].mem_ey, zikix - EnemyShot[i].mem_ex);
					else
						EnemyShot[i].EnemyShots[j].angle = EnemyShot[i].EnemyShots[3 * s].angle + PI / 4 * (double)j / 3.0f;
				}
				StopSoundMem(sound_enemy_shot[0]);//�o�Ă�����������
				PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);//�����o��
			}
		}
	}

	for (int j = 0; j<30; j++) {//�S30�̓��A
		if (EnemyShot[i].EnemyShots[j].flag == 1) {//���˂���Ă���͈̂ړ�������
			EnemyShot[i].EnemyShots[j].x += (3.0 + kasoku)*cos(EnemyShot[i].EnemyShots[j].angle)*2.0f;//X���W�ړ�
			EnemyShot[i].EnemyShots[j].y += (3.0 + kasoku)*sin(EnemyShot[i].EnemyShots[j].angle)*2.0f;//Y���W�ړ�
		}
	}

}

//---------------------------------------------------------------�����܂œ���-----------------------------------------------------------//



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
			for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {//�S�Ă̓G��
				for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {//�S�Ă̓G�̒e��
					if (EnemyShot[i].EnemyShots[j].flag == 1) {//���̒e�����˒��Ȃ�
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