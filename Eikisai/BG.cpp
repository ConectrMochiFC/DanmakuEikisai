#include "DxLib.h"
#include "Ex.h"

void ModeLife();

int sosu = 0;
int Eflag = 0, Vflag = 0;
int onicon = 0, onif;

void Background() {//É^ÉCÉgÉãâÊñ ÇÃÉOÉâÉtÉBÉbÉNìô

				   //++++++++++++++++++++++++++++++++++++å„ÇÎÇÃÉtÉFÅ[ÉhÉCÉì+++++++++++++++++++++++++++++++++++++//

	if (count >= 120) {

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)taihai);
		DrawRotaGraph(640, 480, 1.0, 0.0, img_background[0], TRUE);//É^ÉCÉgÉãÇÃîwåi
		DrawRotaGraph(390, 680, 0.6, 0.0, img_titleph[10], TRUE);//âpåÍÇÃÉ^ÉCÉgÉãñº

		if (sentaku == 1) {
			DrawRotaGraph(950, 400, 0.65, 0.0, img_titleph[2], TRUE);//ê‘ï∂éöÉXÉ^Å[Ég
			DrawRotaGraph(950, 500, 1.0, 0.0, img_titleph[1], TRUE);//èIÇÌÇË
		}
		if (sentaku == 2) {
			DrawRotaGraph(950, 400, 1.0, 0.0, img_titleph[0], TRUE);//ÉQÅ[ÉÄÉXÉ^Å[Ég
			DrawRotaGraph(950, 500, 0.8, 0.0, img_titleph[3], TRUE);//ê‘ï∂éöèIÇÌÇË
		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		taihai += 2;

	}

	if (count >= 60) {
		DrawRotaGraph((int)x1, 400, 1.0, (double)x, (int)img_titleph[4], TRUE);//ñÇñ@êw

		x += 0.03;
		if (x1 <= 320) {
			x1 += 15;
		}

	}


	//-----------------------------------------ÉQÅ[ÉÄñº------------------------------------------//

	if (count >= 10) {
		DrawRotaGraph(210, 250, n1, m1, img_titleph[5], TRUE);//íe

		if (count >= 20) {
			DrawRotaGraph(480, 260, n2, m2, img_titleph[6], TRUE);//ñã
		}

		if (count >= 30) {
			DrawRotaGraph(130, 590, n3, m3, img_titleph[7], TRUE);//âe
		}

		if (count >= 40) {
			DrawRotaGraph(335, 600, n4, m4, img_titleph[8], TRUE);//à®
		}

		if (count >= 50) {
			DrawRotaGraph(540, 600, n5, m5, img_titleph[9], TRUE);//ç 
		}
	}
}

void Background2() {

	DrawRotaGraph(640, 480, 1.0, 0.0, img_game[0], TRUE);
	DrawRotaGraph(910, 260, 1.0, 0.0, img_game[4], TRUE);
	DrawRotaGraph(910, 315, 1.0, 0.0, img_game[5], TRUE);
	DrawRotaGraph(905, 380, 1.0, 0.0, img_game[6], TRUE);
	DrawRotaGraph(995, 380, 0.8, 0.0, img_game[9], TRUE);
	DrawRotaGraph(895, 140, 0.9, 0.0, img_game[10], TRUE);
	DrawRotaGraph(910, 180, 0.95, 0.0, img_game[11], TRUE);

	if (ModeM == 0) {
		for (life_p = 0; life_p < life - 1; life_p++)
			DrawRotaGraph(980 + life_p * 40, 260, 0.8, 0.0, img_game[7], TRUE);
		for (bomb_p = 0; bomb_p < bomb; bomb_p++)
			DrawRotaGraph(980 + bomb_p * 40, 320, 0.8, 0.0, img_game[8], TRUE);
	}

	DrawRotaGraph(1058, 750, 1.2, 0.0, img_logo[0], TRUE);
	DrawRotaGraph(1208, 710, 0.65, 0.0, img_logo[1], TRUE);
	DrawRotaGraph(908, 708, 0.65, 0.0, img_logo[2], TRUE);

	//DrawRotaGraph(1180,825,0.8,0.43,img_logo[3],TRUE);
	//25ìx*3.14/180=0.43

	DrawRotaGraph(1150, 588, 1.2, 6.01, img_logo[4], TRUE);
	//345ìx
	DrawRotaGraph(950, 593, 1.2, 0.26, img_logo[5], TRUE);
	//15ìx

	int ShotCon = 0;
	for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {
		if (BossShot.BossShots[j].flag == 1) {
			ShotCon++;
		}
		sosu = ShotCon;
	}
	//DrawFormatString(800, 600, White, "%d", ShotCon);
	//DrawFormatString(1100, 500, White, "%ld", Kcon);
	if(ModeM==1)
		DrawFormatString(zikix, zikiy-50, Black, "%d", Miss);

}

void Background3() {

	ChangeVolumeSoundMem(dotyufin, sound_dotyu);
	ChangeVolumeSoundMem(bossout * 80 / 100, sound_boss);
	ChangeVolumeSoundMem(lastout, sound_last);


	if (boss.counter<600)
		backs++;

	if (backs - 2150 == 480) {
		backs = 480;
	}

	if (count == 300) {
		mozimozi = 1;
		if (CheckSoundMem(sound_dotyu) == 1)
			StopSoundMem(sound_dotyu);
		PlaySoundMem(sound_dotyu, DX_PLAYTYPE_LOOP);
	}
	if (menmozi == 800)
		mozimozi = 2;

	if (mozimozi == 1)
		menmozi += 4;
	if (mozimozi == 2)
		menmozi -= 6;
	if (menmozi<0)
		mozimozi = 0;


	DrawRotaGraph(370 + (int)Shokx, backs + (int)Shoky, 1.8, 0.0, img_background[1], TRUE);
	DrawRotaGraph(370 + (int)Shokx, backs - 2150 + (int)Shoky, 1.8, 0.0, img_background[1], TRUE);


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)menmozi);
	DrawRotaGraph(430, 450, 1.5, 0.0, img_mentai[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void ModeSele() {

	//DrawRotaGraph(640, 480, 2.0, 0, img_mode, TRUE);

	SetFontSize(36);
	switch (mode) {
	case 1:
		DrawRotaGraph(640, 480, 2.0, 0, img_mode[0], TRUE);
		DrawFormatString(200, 200, Red, "ÇPEasy:ódê∏ãâ");
		DrawFormatString(200, 350, White, "ÇQNormal:óHóÏãâ");
		DrawFormatString(200, 500, White, "ÇRHard:ñÇèóãâ");
		DrawFormatString(200, 650, White, "ÇSVeryHard:ëŒñÇîEãâ");
		if(onif) DrawFormatString(200, 800, White, "ÇTUltraBeast:ãzååãSãâ");
		break;
	case 2:
		DrawRotaGraph(640, 480, 2.0, 0, img_mode[1], TRUE);
		DrawFormatString(200, 200, White, "ÇPEasy:ódê∏ãâ");
		DrawFormatString(200, 350, Red, "ÇQNormal:óHóÏãâ");
		DrawFormatString(200, 500, White, "ÇRHard:ñÇèóãâ");
		DrawFormatString(200, 650, White, "ÇSVeryHard:ëŒñÇîEãâ");
		if (onif) DrawFormatString(200, 800, White, "ÇTUltraBeast:ãzååãSãâ");
		break;
	case 3:
		DrawRotaGraph(640, 480, 2.0, 0, img_mode[2], TRUE);
		DrawFormatString(200, 200, White, "ÇPEasy:ódê∏ãâ");
		DrawFormatString(200, 350, White, "ÇQNormal:óHóÏãâ");
		DrawFormatString(200, 500, Red, "ÇRHard:ñÇèóãâ");
		DrawFormatString(200, 650, White, "ÇSVeryHard:ëŒñÇîEãâ");
		if (onif) DrawFormatString(200, 800, White, "ÇTUltraBeast:ãzååãSãâ");
		break;
	case 4:
		DrawRotaGraph(640, 480, 2.0, 0, img_mode[3], TRUE);
		DrawFormatString(200, 200, White, "ÇPEasy:ódê∏ãâ");
		DrawFormatString(200, 350, White, "ÇQNormal:óHóÏãâ");
		DrawFormatString(200, 500, White, "ÇRHard:ñÇèóãâ");
		DrawFormatString(200, 650, Red, "ÇSVeryHard:ëŒñÇîEãâ");
		if (onif) DrawFormatString(200, 800, White, "ÇTUltraBeast:ãzååãSãâ");
		break;
	case 5:
		DrawRotaGraph(640, 480, 2.0, 0, img_mode[4], TRUE);
		DrawFormatString(200, 200, White, "ÇPEasy:ódê∏ãâ");
		DrawFormatString(200, 350, White, "ÇQNormal:óHóÏãâ");
		DrawFormatString(200, 500, White, "ÇRHard:ñÇèóãâ");
		DrawFormatString(200, 650, White, "ÇSVeryHard:ëŒñÇîEãâ");
		if (onif) DrawFormatString(200, 800, Red, "ÇTUltraBeast:ãzååãSãâ");
		break;
	}
	SetFontSize(16);

	if (CheckHitKey(KEY_INPUT_UP) == 1 && Vflag == 0) {
		mode--; Vflag = 1;
	}

	if (CheckHitKey(KEY_INPUT_DOWN) == 1 && Vflag == 0) {
		if (Vflag==0 && mode == 4) onicon++;
		mode++; Vflag = 1;
	}

	if (onicon >= 10) onif = 1;

	if (CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0) Vflag = 0;

	if (mode <= 0) {
		if(onif==0) mode = 4;
		else mode = 5;
	}
	if (mode > 4) {
		if(onif==0) mode = 4;
		else if (mode > 5) mode = 1;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) == 0) Eflag = 1;
	if (Eflag == 1 && CheckHitKey(KEY_INPUT_RETURN) == 1) {
		scene = 2; Eflag = 0; Vflag = 0;
		ModeLife();
		
	}
}

void ModeLife() {

	switch (mode) {
	case 1:
		if (ModeM == 1) {
			life = 9999; bomb = 0;
		}
		else life = 5; bomb = 3;
		break;
	case 2:
		if (ModeM == 1) {
			life = 9999; bomb = 0;
		}
		else life = 3; bomb = 3;
		break;
	case 3:
		if (ModeM == 1) {
			life = 9999; bomb = 0;
		}
		else life = 3; bomb = 0;
		break;
	case 4:
		if (ModeM == 1) {
			life = 9999; bomb = 0;
		}
		else life = 2; bomb = 0; //ShotLevel = 5;
		break;
	case 5:
		if (ModeM == 1) {
			life = 9999; bomb = 0;
		}
		else life = 1; bomb = 0;
	default:
		break;
	}

}

void RS_6() {
	Vflag = 0; sosu = 0; Eflag = 0; mode = 1;
	onicon = 0; onif = 0;
}