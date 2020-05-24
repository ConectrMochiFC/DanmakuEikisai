#pragma once


/* 定義 */
#define PLAYER_MAX_SHOT1 11 
#define PLAYER_MAX_SHOT2 15

#define ENEMY_TOTAL_NUM 100
#define ENEMY_TOTAL_SHOT_NUM 70000

#define MONSTER1_X_SIZE 140.0
#define MONSTER1_Y_SIZE 128.0

#define PLAYER_X_SIZE 60.0
#define PLAYER_Y_SIZE 60.0

#define LIFE 3
#define BOMB 3

#define MAPX 1280
#define MAPY 960
//元は1280*960

// extern 宣言
extern int counter;
extern int Green, White, Red, Blue,Black;
extern int Key[256];//ゲーム上ではなく、プログラム上のキー設定

extern int scene;

extern int backs;
extern int menmozi, mozimozi;


extern int ShotLevel;

extern int tenmetu;
extern double hakkyou;
extern double hakkyou_3, hakkyou_4;
extern double speed[60000];


extern int pattern;
extern int ata;
extern int life, bomb, life_p, bomb_p, hidan, bombOK;

extern int enex[100], eney[100], bakuha, gekiha, itemOK, RSOK;
extern double kasoku, Shokx, Shoky;

extern int dai2, dai3, dai4, frame, bsf;

extern int dotyufin, bossout, lastout;

extern int gameover, makkura;

//-----------------------------------------タイトルのデータ-------------------------------------//

extern double n1, n2, n3, n4, n5, m1, m2, m3, m4, m5;
extern double x, taihai, x1;

extern int sentaku;
extern int owacon;

//---------------------------------------ゲーム画面のデータ------------------------------------//

extern int zikix, zikiy;
extern int stage;

extern int i, n, count2, j;
extern int count;

extern int stop, stocon, name, namehai, name2;
extern int namecon;

extern int ziki[6];
extern int kaisyu, enix[100], eniy[100];

extern double bombsize;
extern int mode;

extern long score, amari;
extern long hyakuman, juman, man, sen, hyaku, ju, iti;

extern double Thp, Bhp;

extern long hiscore, hi_amari;
extern long hi_hyakuman, hi_juman, hi_man, hi_sen, hi_hyaku, hi_ju, hi_iti;

//--------------------------------------------------------------------------------------------------//

extern unsigned long Kcon;
extern unsigned long Han;

extern int Miss, ModeM;




//画像ファイルハンドル
extern int img_background[8];
extern int img_titleph[11];
extern int img_mode[10];
extern int img_player[4];

extern int img_game[10];
extern int img_tama[3], img_chara[110];
extern int img_logo[6];
extern int img_bomb;

extern int img_mentai[1];

extern int img_enemy1[5];

extern int img_tyuboss;
extern int img_1boss[4];
extern int img_caution[3];

extern int img_score[10];
extern int img_item[2];

extern int img_clear, img_totitle, img_lose[8], img_anten;

//弾
extern int img_player_shot[2];
extern int img_enemy_shot[20];

//エフェクト
extern int img_hidan[15];
extern int img_bakuha[16];
extern int img_tamabaku[16];
extern int img_bossbaku[16];
extern int img_bokasi;


//音声ファイルハンドル
extern int sound_player_shot[2];
extern int sound_enemy_shot[2];
extern int sound_enemy_tyakudan;
extern int sound_enemy_death;
extern int sound_tb_death;
extern int sound_keikoku;
extern int sound_shot_del;
extern int sound_b_death;
extern int sound_tame, sound_bom;
extern int sound_item;
extern int sound_over;

extern int sound_dotyu;
extern int sound_boss;
extern int sound_last;


//構造体
typedef struct {
	double x, y;
	int status, counter;
	int shot[11][15];
} BODY_player_t;

extern BODY_player_t Player;


//敵
typedef struct {
	double x, y, size;
	int flag, counter, hp, pattern, range;
} BODY_enemy_t;

extern BODY_enemy_t enemy[1000];

//中ボス
typedef struct {
	double x, y, size, hp;
	int flag, counter, df, range, muteki;
} BODY_tyuboss;

extern BODY_tyuboss tyuboss;

//中ボスショット

typedef struct {
	int flag,hf;
	double x, y, angle, disp_angle, speed,ran;
} TyuShots;

typedef struct {
	int flag, counter, img, pattern;
	double mem_ex, mem_ey, mem_px, mem_py, Tbx[6000], Tby[6000];//[200];
	TyuShots TyuShots[ENEMY_TOTAL_SHOT_NUM];//[200];
} Tyu_Shot;

extern Tyu_Shot TyuShot;


//ボス
typedef struct {
	double x, y, size, hp;
	int flag, counter, df, range, muteki;
} BODY_boss;

extern BODY_boss boss;

//ボスショット
typedef struct {
	int flag,han,hf;
	double x, y, angle, disp_angle, speed;
} BossShots;

typedef struct {
	int flag, counter, img, pattern;
	double mem_ex, mem_ey, mem_px, mem_py, Bsx[6000], Bsy[6000];//[200];
	BossShots BossShots[ENEMY_TOTAL_SHOT_NUM];//[200];
} Boss_Shot;

extern Boss_Shot BossShot;


//ショット（プレイヤー）
typedef struct {
	double x, y;
	int flag;
} SHOT_t;

extern SHOT_t PlayerShot[PLAYER_MAX_SHOT1][PLAYER_MAX_SHOT2];


typedef struct {
	int flag;
	double x, y, angle, disp_angle, speed;
} ENEMY_SHOTS_t;

//敵ショット
typedef struct {
	int flag, pattern, counter, img;
	double mem_ex, mem_ey, mem_px, mem_py, Enx[60000], Eny[60000];//[200];
	ENEMY_SHOTS_t EnemyShots[ENEMY_TOTAL_SHOT_NUM];//[200];
} ENEMY_SHOT_t;

extern ENEMY_SHOT_t EnemyShot[ENEMY_TOTAL_NUM];//[100];



											   //アイテム
typedef struct {
	double x, y;
	int flag, counter;
} Item_t;

extern Item_t item[ENEMY_TOTAL_NUM];//[100]