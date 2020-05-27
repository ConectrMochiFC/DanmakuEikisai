#include "DxLib.h"
#include "Ex.h"


void img_sound_load() {

	//------------------------------------------タイトルのデータ---------------------------------------------------//

	img_background[0] = LoadGraph("Graph/Title/Title.jpg");

	img_titleph[0] = LoadGraph("Graph/Title/Start.png");
	img_titleph[1] = LoadGraph("Graph/Title/End.png");
	img_titleph[2] = LoadGraph("Graph/Title/RStart.png");
	img_titleph[3] = LoadGraph("Graph/Title/REnd.png");

	img_titleph[4] = LoadGraph("Graph/Title/MAHO.png");
	img_titleph[5] = LoadGraph("Graph/Title/GameTitle/Dan.png");
	img_titleph[6] = LoadGraph("Graph/Title/GameTitle/Maku.png");
	img_titleph[7] = LoadGraph("Graph/Title/GameTitle/Ei.png");
	img_titleph[8] = LoadGraph("Graph/Title/GameTitle/Ki.png");
	img_titleph[9] = LoadGraph("Graph/Title/GameTitle/Sai.png");
	img_titleph[10] = LoadGraph("Graph/Title/GameTitle/Sub.png");

	img_mode[0] = LoadGraph("Graph/Mode/EasyB.jpg");
	img_mode[1] = LoadGraph("Graph/Mode/NormalB.jpg");
	img_mode[2] = LoadGraph("Graph/Mode/HardB.jpg");
	img_mode[3] = LoadGraph("Graph/Mode/VHardB.jpg");
	img_mode[4] = LoadGraph("Graph/Mode/VVHB.jpg");

	//-----------------------------------------ゲーム画面のデータ-------------------------------------------------//

	img_background[1] = LoadGraph("Graph/PlayGame/Back/StBack.png");

	ziki[0] = LoadGraph("Graph/PlayGame/Player.png");
	ziki[1] = LoadGraph("Graph/PlayGame/Player2.png");


	img_game[0] = LoadGraph("Graph/PlayGame/Back/GameBack.png");
	//img_game[1] = LoadGraph("Graph/PlayGame/BlRm.png");
	img_game[2] = LoadGraph("Graph/PlayGame/Heart.png");
	//img_game[3] = LoadGraph("Graph/PlayGame/キャラクタ01.png");

	img_game[4] = LoadGraph("Graph/PlayGame/Back/Player3.png");
	img_game[5] = LoadGraph("Graph/PlayGame/Back/Bomb.png");
	img_game[6] = LoadGraph("Graph/PlayGame/Back/Power.png");

	img_game[7] = LoadGraph("Graph/PlayGame/Back/Zanki.png");
	img_game[8] = LoadGraph("Graph/PlayGame/Back/ZanBomb.png");
	img_game[9] = LoadGraph("Graph/Font/MAX.png");

	img_game[10] = LoadGraph("Graph/Font/Score/HighScore.png");
	img_game[11] = LoadGraph("Graph/Font/Score/Score.png");

	img_bomb = LoadGraph("Graph/PlayGame/EfectBomb.png");

	img_logo[0] = LoadGraph("Graph/PlayGame/Back/MoziTitle.png");
	img_logo[1] = LoadGraph("Graph/PlayGame/Back/Right.png");
	img_logo[2] = LoadGraph("Graph/PlayGame/Back/Left.png");
	img_logo[3] = LoadGraph("Graph/PlayGame/Back/Tail.png");
	img_logo[4] = LoadGraph("Graph/PlayGame/Back/Hane1.png");
	img_logo[5] = LoadGraph("Graph/PlayGame/Back/Hane2.png");

	img_score[0] = LoadGraph("Graph/Font/Score/0.png");
	img_score[1] = LoadGraph("Graph/Font/Score/1.png");
	img_score[2] = LoadGraph("Graph/Font/Score/2.png");
	img_score[3] = LoadGraph("Graph/Font/Score/3.png");
	img_score[4] = LoadGraph("Graph/Font/Score/4.png");
	img_score[5] = LoadGraph("Graph/Font/Score/5.png");
	img_score[6] = LoadGraph("Graph/Font/Score/6.png");
	img_score[7] = LoadGraph("Graph/Font/Score/7.png");
	img_score[8] = LoadGraph("Graph/Font/Score/8.png");
	img_score[9] = LoadGraph("Graph/Font/Score/9.png");

	LoadDivGraph("Graph/PlayGame/Shot01.png", 3, 3, 1, 14, 16, img_tama);
	LoadDivGraph("Graph/PlayGame/EnemyChara.png", 110, 10, 11, 40, 40, img_chara);

	//		ziki[0] = LoadGraph("Graph/PlayGame/自機/魔法使い.png");

	img_mentai[0] = LoadGraph("Graph/Font/1Do.png");


	img_player_shot[0] = LoadGraph("Sh/img/shot/player/Hari.png");
	img_player_shot[1] = LoadGraph("Sh/img/shot/player/2.png");

	img_item[0] = LoadGraph("Graph/PlayGame/Point.png");

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
	img_tyuboss = LoadGraph("Graph/PlayGame/Boss/TBoss.png");

	img_caution[0] = LoadGraph("Graph/PlayGame/Boss/CAUTION!2.jpg");
	img_caution[1] = LoadGraph("Graph/PlayGame/Boss/Tri.png");
	img_caution[2] = LoadGraph("Graph/PlayGame/Boss/RedBack.png");
	//img_bokasi = LoadGraph("テキストバックアップ/ぼかし.png");

	img_clear = LoadGraph("Graph/Font/StageClear.png");
	img_totitle = LoadGraph("Graph/Font/BackTitle.png");

	img_anten = LoadGraph("Graph/Font/GameOver/Black.png");
	img_lose[0] = LoadGraph("Graph/Font/GameOver/GAME_G.png");
	img_lose[1] = LoadGraph("Graph/Font/GameOver/GAME_A.png");
	img_lose[2] = LoadGraph("Graph/Font/GameOver/GAME_M.png");
	img_lose[3] = LoadGraph("Graph/Font/GameOver/GAME_E.png");
	img_lose[4] = LoadGraph("Graph/Font/GameOver/OVER_O.png");
	img_lose[5] = LoadGraph("Graph/Font/GameOver/OVER_V.png");
	img_lose[6] = LoadGraph("Graph/Font/GameOver/OVER_E.png");
	img_lose[7] = LoadGraph("Graph/Font/GameOver/OVER_R.png");


	LoadDivGraph("Graph/PlayGame/hidan.png", 15, 5, 3, 58, 58, img_hidan);
	LoadDivGraph("Graph/PlayGame/Boss/Fairy.png", 16, 8, 2, 55, 50, img_bakuha);
	LoadDivGraph("Graph/PlayGame/Boss/Boss.png", 4, 4, 1, 64, 64, img_1boss);
	LoadDivGraph("Graph/PlayGame/Boss/ShotB.png", 16, 8, 2, 96, 96, img_tamabaku);
	LoadDivGraph("Graph/PlayGame/Boss/BossB.png", 16, 8, 2, 48, 50, img_bossbaku);


	//音楽
	sound_player_shot[0] = LoadSoundMem("Sh/sound/Player/Shot-Kai.ogg");
	sound_enemy_shot[0] = LoadSoundMem("Sh/sound/enemy/normalshot.ogg");
	sound_enemy_shot[1] = LoadSoundMem("Sh/sound/enemy/shot3.ogg");
	sound_enemy_tyakudan = LoadSoundMem("Sh/sound/enemy/Hit-Kai.ogg");
	sound_enemy_death = LoadSoundMem("Sh/sound/enemy/death.ogg");
	sound_tb_death = LoadSoundMem("Sh/sound/enemy/tbdeath.ogg");

	sound_keikoku = LoadSoundMem("Sound/Cou.ogg");
	sound_shot_del = LoadSoundMem("Sound/ShotB.ogg");
	sound_b_death = LoadSoundMem("Sound/BossB.ogg");
	sound_tame = LoadSoundMem("Sound/tame.ogg");
	sound_bom = LoadSoundMem("Sound/bom.ogg");
	sound_item = LoadSoundMem("Sound/item.ogg");
	sound_over = LoadSoundMem("Sound/GameO.ogg");

	sound_dotyu = LoadSoundMem("Sound/Dotyu.wav");
	sound_boss = LoadSoundMem("Sound/Boss1-1.wav");
	sound_last = LoadSoundMem("Sound/Last.wav");


}