#include "DxLib.h"
#include "Ex.h"


void img_sound_load() {

	//------------------------------------------�^�C�g���̃f�[�^---------------------------------------------------//

	img_background[0] = LoadGraph("�摜/�^�C�g��/�^�C�g���w�i2.jpg");

	img_titleph[0] = LoadGraph("�摜/�^�C�g��/�Q�[���X�^�[�g.png");
	img_titleph[1] = LoadGraph("�摜/�^�C�g��/�����.png");
	img_titleph[2] = LoadGraph("�摜/�^�C�g��/�ԃX�^�[�g.png");
	img_titleph[3] = LoadGraph("�摜/�^�C�g��/�ԏI���.png");

	img_titleph[4] = LoadGraph("�摜/�^�C�g��/���@�Q.png");
	img_titleph[5] = LoadGraph("�摜/�^�C�g��/�Q�[����/�e.png");
	img_titleph[6] = LoadGraph("�摜/�^�C�g��/�Q�[����/��.png");
	img_titleph[7] = LoadGraph("�摜/�^�C�g��/�Q�[����/�e.png");
	img_titleph[8] = LoadGraph("�摜/�^�C�g��/�Q�[����/��.png");
	img_titleph[9] = LoadGraph("�摜/�^�C�g��/�Q�[����/��.png");
	img_titleph[10] = LoadGraph("�摜/�^�C�g��/�Q�[����/�p���.png");

	img_mode[0] = LoadGraph("�摜/��Փx/EasyB.jpg");
	img_mode[1] = LoadGraph("�摜/��Փx/NormalB.jpg");
	img_mode[2] = LoadGraph("�摜/��Փx/HardB.jpg");
	img_mode[3] = LoadGraph("�摜/��Փx/VHardB.jpg");
	img_mode[4] = LoadGraph("�摜/��Փx/VVHB.jpg");

	//-----------------------------------------�Q�[����ʂ̃f�[�^-------------------------------------------------//

	img_background[1] = LoadGraph("�摜/�Q�[�����/�w�i/�w�i�R.png");

	ziki[0] = LoadGraph("�摜/�Q�[�����/���@�P.png");
	ziki[1] = LoadGraph("�摜/�Q�[�����/���@�P�|�Q.png");


	img_game[0] = LoadGraph("�摜/�Q�[�����/�w�i/�Q�[���̔w�i�Q.png");
	img_game[1] = LoadGraph("�摜/�Q�[�����/�얲_����.png");
	img_game[2] = LoadGraph("�摜/�Q�[�����/�n�[�g.png");
	img_game[3] = LoadGraph("�摜/�Q�[�����/�L�����N�^01.png");

	img_game[4] = LoadGraph("�摜/�Q�[�����/�w�i/Player3.png");
	img_game[5] = LoadGraph("�摜/�Q�[�����/�w�i/Bomb.png");
	img_game[6] = LoadGraph("�摜/�Q�[�����/�w�i/Power.png");

	img_game[7] = LoadGraph("�摜/�Q�[�����/�w�i/�c�@��.png");
	img_game[8] = LoadGraph("�摜/�Q�[�����/�w�i/�c�{����.png");
	img_game[9] = LoadGraph("�摜/�t�H���g/MAX.png");

	img_game[10] = LoadGraph("�摜/�t�H���g/�X�R�A/�n�C�X�R�A.png");
	img_game[11] = LoadGraph("�摜/�t�H���g/�X�R�A/�X�R�A.png");

	img_bomb = LoadGraph("�摜/�Q�[�����/�x���t���b�V��.png");

	img_logo[0] = LoadGraph("�摜/�Q�[�����/�w�i/�^�C�g������.png");
	img_logo[1] = LoadGraph("�摜/�Q�[�����/�w�i/�E��.png");
	img_logo[2] = LoadGraph("�摜/�Q�[�����/�w�i/����.png");
	img_logo[3] = LoadGraph("�摜/�Q�[�����/�w�i/�K��.png");
	img_logo[4] = LoadGraph("�摜/�Q�[�����/�w�i/���̉H�E�Q.png");
	img_logo[5] = LoadGraph("�摜/�Q�[�����/�w�i/���̉H���Q.png");

	img_score[0] = LoadGraph("�摜/�t�H���g/�X�R�A/0.png");
	img_score[1] = LoadGraph("�摜/�t�H���g/�X�R�A/1.png");
	img_score[2] = LoadGraph("�摜/�t�H���g/�X�R�A/2.png");
	img_score[3] = LoadGraph("�摜/�t�H���g/�X�R�A/3.png");
	img_score[4] = LoadGraph("�摜/�t�H���g/�X�R�A/4.png");
	img_score[5] = LoadGraph("�摜/�t�H���g/�X�R�A/5.png");
	img_score[6] = LoadGraph("�摜/�t�H���g/�X�R�A/6.png");
	img_score[7] = LoadGraph("�摜/�t�H���g/�X�R�A/7.png");
	img_score[8] = LoadGraph("�摜/�t�H���g/�X�R�A/8.png");
	img_score[9] = LoadGraph("�摜/�t�H���g/�X�R�A/9.png");

	LoadDivGraph("�摜/�Q�[�����/�e01.png", 3, 3, 1, 14, 16, img_tama);
	LoadDivGraph("�摜/�Q�[�����/�G�L����.png", 110, 10, 11, 40, 40, img_chara);

	//		ziki[0] = LoadGraph("�摜/�Q�[�����/���@/���@�g��.png");

	img_mentai[0] = LoadGraph("�摜/�t�H���g/1�ʖ��O1.png");


	img_player_shot[0] = LoadGraph("Sh/img/shot/player/�o���G�[�V�����j�[�h��.png");
	img_player_shot[1] = LoadGraph("Sh/img/shot/player/2.png");

	img_item[0] = LoadGraph("�摜/�Q�[�����/Point.png");

	img_enemy_shot[0] = LoadGraph("Sh/img/shot/enemy/shot1.png");
	img_enemy_shot[1] = LoadGraph("Sh/img/shot/enemy/0.png");
	img_enemy_shot[2] = LoadGraph("Sh/img/shot/enemy/1.png");
	img_enemy_shot[3] = LoadGraph("Sh/img/shot/enemy/2.png");
	img_enemy_shot[4] = LoadGraph("Sh/img/shot/enemy/3.png");
	img_enemy_shot[5] = LoadGraph("Sh/img/shot/enemy/4.png");
	img_enemy_shot[6] = LoadGraph("Sh/img/shot/enemy/5.png");


	img_enemy1[0] = LoadGraph("Sh/img/mons/mons1_0.png");
	img_enemy1[1] = LoadGraph("Sh/img/mons/mons1_1.png");
	img_enemy1[2] = LoadGraph("Sh/img/mons/mons1_2.png");
	img_enemy1[3] = LoadGraph("Sh/img/mons/mons1_3.png");
	img_enemy1[4] = LoadGraph("Sh/img/mons/mons1_4.png");
	img_tyuboss = LoadGraph("�摜/�Q�[�����/�{�X/���{�X.png");

	img_caution[0] = LoadGraph("�摜/�Q�[�����/�{�X/CAUTION!2.jpg");
	img_caution[1] = LoadGraph("�摜/�Q�[�����/�{�X/�O�p.png");
	img_caution[2] = LoadGraph("�摜/�Q�[�����/�{�X/�댯�Ȕw�i.png");
	img_bokasi = LoadGraph("�e�L�X�g�o�b�N�A�b�v/�ڂ���.png");

	img_clear = LoadGraph("�摜/�t�H���g/�X�e�[�W�N���A.png");
	img_totitle = LoadGraph("�摜/�t�H���g/�^�C�g���ɖ߂�܂��c.png");

	img_anten = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/�Ó].png");
	img_lose[0] = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/GAME_G.png");
	img_lose[1] = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/GAME_A.png");
	img_lose[2] = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/GAME_M.png");
	img_lose[3] = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/GAME_E.png");
	img_lose[4] = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/OVER_O.png");
	img_lose[5] = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/OVER_V.png");
	img_lose[6] = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/OVER_E.png");
	img_lose[7] = LoadGraph("�摜/�t�H���g/�Q�[���I�[�o�[/OVER_R.png");


	LoadDivGraph("�摜/�Q�[�����/hidan.png", 15, 5, 3, 58, 58, img_hidan);
	LoadDivGraph("�摜/�Q�[�����/�{�X/�d�����j.png", 16, 8, 2, 55, 50, img_bakuha);
	LoadDivGraph("�摜/�Q�[�����/�{�X/1�ʃ{�X.png", 4, 4, 1, 64, 64, img_1boss);
	LoadDivGraph("�摜/�Q�[�����/�{�X/�e���j.png", 16, 8, 2, 96, 96, img_tamabaku);
	LoadDivGraph("�摜/�Q�[�����/�{�X/�{�X���j.png", 16, 8, 2, 48, 50, img_bossbaku);


	//���y
	sound_player_shot[0] = LoadSoundMem("Sh/sound/Player/�V���b�g����.ogg");
	sound_enemy_shot[0] = LoadSoundMem("Sh/sound/enemy/normalshot.ogg");
	sound_enemy_shot[1] = LoadSoundMem("Sh/sound/enemy/shot3.ogg");
	sound_enemy_tyakudan = LoadSoundMem("Sh/sound/enemy/�q�b�g����.ogg");
	sound_enemy_death = LoadSoundMem("Sh/sound/enemy/death.ogg");
	sound_tb_death = LoadSoundMem("Sh/sound/enemy/tbdeath.ogg");

	sound_keikoku = LoadSoundMem("�T�E���h/�x��.ogg");
	sound_shot_del = LoadSoundMem("�T�E���h/�e���j��.ogg");
	sound_b_death = LoadSoundMem("�T�E���h/�{�X���j��.ogg");
	sound_tame = LoadSoundMem("�T�E���h/tame.ogg");
	sound_bom = LoadSoundMem("�T�E���h/bom.ogg");
	sound_item = LoadSoundMem("�T�E���h/item.ogg");
	sound_over = LoadSoundMem("�T�E���h/�Q�[���I�[�o�[.ogg");

	sound_dotyu = LoadSoundMem("�T�E���h/����.wav");
	sound_boss = LoadSoundMem("�T�E���h/�{�X1-1.wav");
	sound_last = LoadSoundMem("�T�E���h/���X�y�P.wav");


}