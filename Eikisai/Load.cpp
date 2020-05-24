#include "DxLib.h"
#include "Ex.h"


void img_sound_load() {

	//------------------------------------------タイトルのデータ---------------------------------------------------//

	img_background[0] = LoadGraph("画像/タイトル/タイトル背景2.jpg");

	img_titleph[0] = LoadGraph("画像/タイトル/ゲームスタート.png");
	img_titleph[1] = LoadGraph("画像/タイトル/おわり.png");
	img_titleph[2] = LoadGraph("画像/タイトル/赤スタート.png");
	img_titleph[3] = LoadGraph("画像/タイトル/赤終わり.png");

	img_titleph[4] = LoadGraph("画像/タイトル/魔法２.png");
	img_titleph[5] = LoadGraph("画像/タイトル/ゲーム名/弾.png");
	img_titleph[6] = LoadGraph("画像/タイトル/ゲーム名/幕.png");
	img_titleph[7] = LoadGraph("画像/タイトル/ゲーム名/影.png");
	img_titleph[8] = LoadGraph("画像/タイトル/ゲーム名/葵.png");
	img_titleph[9] = LoadGraph("画像/タイトル/ゲーム名/彩.png");
	img_titleph[10] = LoadGraph("画像/タイトル/ゲーム名/英語の.png");

	img_mode[0] = LoadGraph("画像/難易度/EasyB.jpg");
	img_mode[1] = LoadGraph("画像/難易度/NormalB.jpg");
	img_mode[2] = LoadGraph("画像/難易度/HardB.jpg");
	img_mode[3] = LoadGraph("画像/難易度/VHardB.jpg");
	img_mode[4] = LoadGraph("画像/難易度/VVHB.jpg");

	//-----------------------------------------ゲーム画面のデータ-------------------------------------------------//

	img_background[1] = LoadGraph("画像/ゲーム画面/背景/背景３.png");

	ziki[0] = LoadGraph("画像/ゲーム画面/自機１.png");
	ziki[1] = LoadGraph("画像/ゲーム画面/自機１－２.png");


	img_game[0] = LoadGraph("画像/ゲーム画面/背景/ゲームの背景２.png");
	img_game[1] = LoadGraph("画像/ゲーム画面/青霊夢_透明.png");
	img_game[2] = LoadGraph("画像/ゲーム画面/ハート.png");
	img_game[3] = LoadGraph("画像/ゲーム画面/キャラクタ01.png");

	img_game[4] = LoadGraph("画像/ゲーム画面/背景/Player3.png");
	img_game[5] = LoadGraph("画像/ゲーム画面/背景/Bomb.png");
	img_game[6] = LoadGraph("画像/ゲーム画面/背景/Power.png");

	img_game[7] = LoadGraph("画像/ゲーム画面/背景/残機数.png");
	img_game[8] = LoadGraph("画像/ゲーム画面/背景/残ボム数.png");
	img_game[9] = LoadGraph("画像/フォント/MAX.png");

	img_game[10] = LoadGraph("画像/フォント/スコア/ハイスコア.png");
	img_game[11] = LoadGraph("画像/フォント/スコア/スコア.png");

	img_bomb = LoadGraph("画像/ゲーム画面/富岡フラッシュ.png");

	img_logo[0] = LoadGraph("画像/ゲーム画面/背景/タイトル文字.png");
	img_logo[1] = LoadGraph("画像/ゲーム画面/背景/右翼.png");
	img_logo[2] = LoadGraph("画像/ゲーム画面/背景/左翼.png");
	img_logo[3] = LoadGraph("画像/ゲーム画面/背景/尻尾.png");
	img_logo[4] = LoadGraph("画像/ゲーム画面/背景/頭の羽右２.png");
	img_logo[5] = LoadGraph("画像/ゲーム画面/背景/頭の羽左２.png");

	img_score[0] = LoadGraph("画像/フォント/スコア/0.png");
	img_score[1] = LoadGraph("画像/フォント/スコア/1.png");
	img_score[2] = LoadGraph("画像/フォント/スコア/2.png");
	img_score[3] = LoadGraph("画像/フォント/スコア/3.png");
	img_score[4] = LoadGraph("画像/フォント/スコア/4.png");
	img_score[5] = LoadGraph("画像/フォント/スコア/5.png");
	img_score[6] = LoadGraph("画像/フォント/スコア/6.png");
	img_score[7] = LoadGraph("画像/フォント/スコア/7.png");
	img_score[8] = LoadGraph("画像/フォント/スコア/8.png");
	img_score[9] = LoadGraph("画像/フォント/スコア/9.png");

	LoadDivGraph("画像/ゲーム画面/弾01.png", 3, 3, 1, 14, 16, img_tama);
	LoadDivGraph("画像/ゲーム画面/敵キャラ.png", 110, 10, 11, 40, 40, img_chara);

	//		ziki[0] = LoadGraph("画像/ゲーム画面/自機/魔法使い.png");

	img_mentai[0] = LoadGraph("画像/フォント/1面名前1.png");


	img_player_shot[0] = LoadGraph("Sh/img/shot/player/バリエーションニードル.png");
	img_player_shot[1] = LoadGraph("Sh/img/shot/player/2.png");

	img_item[0] = LoadGraph("画像/ゲーム画面/Point.png");

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
	img_tyuboss = LoadGraph("画像/ゲーム画面/ボス/中ボス.png");

	img_caution[0] = LoadGraph("画像/ゲーム画面/ボス/CAUTION!2.jpg");
	img_caution[1] = LoadGraph("画像/ゲーム画面/ボス/三角.png");
	img_caution[2] = LoadGraph("画像/ゲーム画面/ボス/危険な背景.png");
	img_bokasi = LoadGraph("テキストバックアップ/ぼかし.png");

	img_clear = LoadGraph("画像/フォント/ステージクリア.png");
	img_totitle = LoadGraph("画像/フォント/タイトルに戻ります….png");

	img_anten = LoadGraph("画像/フォント/ゲームオーバー/暗転.png");
	img_lose[0] = LoadGraph("画像/フォント/ゲームオーバー/GAME_G.png");
	img_lose[1] = LoadGraph("画像/フォント/ゲームオーバー/GAME_A.png");
	img_lose[2] = LoadGraph("画像/フォント/ゲームオーバー/GAME_M.png");
	img_lose[3] = LoadGraph("画像/フォント/ゲームオーバー/GAME_E.png");
	img_lose[4] = LoadGraph("画像/フォント/ゲームオーバー/OVER_O.png");
	img_lose[5] = LoadGraph("画像/フォント/ゲームオーバー/OVER_V.png");
	img_lose[6] = LoadGraph("画像/フォント/ゲームオーバー/OVER_E.png");
	img_lose[7] = LoadGraph("画像/フォント/ゲームオーバー/OVER_R.png");


	LoadDivGraph("画像/ゲーム画面/hidan.png", 15, 5, 3, 58, 58, img_hidan);
	LoadDivGraph("画像/ゲーム画面/ボス/妖精爆破.png", 16, 8, 2, 55, 50, img_bakuha);
	LoadDivGraph("画像/ゲーム画面/ボス/1面ボス.png", 4, 4, 1, 64, 64, img_1boss);
	LoadDivGraph("画像/ゲーム画面/ボス/弾爆破.png", 16, 8, 2, 96, 96, img_tamabaku);
	LoadDivGraph("画像/ゲーム画面/ボス/ボス爆破.png", 16, 8, 2, 48, 50, img_bossbaku);


	//音楽
	sound_player_shot[0] = LoadSoundMem("Sh/sound/Player/ショット音改.ogg");
	sound_enemy_shot[0] = LoadSoundMem("Sh/sound/enemy/normalshot.ogg");
	sound_enemy_shot[1] = LoadSoundMem("Sh/sound/enemy/shot3.ogg");
	sound_enemy_tyakudan = LoadSoundMem("Sh/sound/enemy/ヒット音改.ogg");
	sound_enemy_death = LoadSoundMem("Sh/sound/enemy/death.ogg");
	sound_tb_death = LoadSoundMem("Sh/sound/enemy/tbdeath.ogg");

	sound_keikoku = LoadSoundMem("サウンド/警告.ogg");
	sound_shot_del = LoadSoundMem("サウンド/弾爆破音.ogg");
	sound_b_death = LoadSoundMem("サウンド/ボス爆破音.ogg");
	sound_tame = LoadSoundMem("サウンド/tame.ogg");
	sound_bom = LoadSoundMem("サウンド/bom.ogg");
	sound_item = LoadSoundMem("サウンド/item.ogg");
	sound_over = LoadSoundMem("サウンド/ゲームオーバー.ogg");

	sound_dotyu = LoadSoundMem("サウンド/道中.wav");
	sound_boss = LoadSoundMem("サウンド/ボス1-1.wav");
	sound_last = LoadSoundMem("サウンド/ラスペ１.wav");


}