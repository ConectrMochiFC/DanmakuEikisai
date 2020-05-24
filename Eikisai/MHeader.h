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

// グローバル宣言
int counter = 0;
int Green, White, Red, Blue,Black;
int Key[256];

int scene;

int backs;
int menmozi, mozimozi;

int ShotLevel = 11;

int tenmetu;
double hakkyou;
double  hakkyou_3, hakkyou_4 = 4.0f;
double speed[60000];

int pattern;
int ata;
int life = LIFE, bomb = BOMB, life_p, bomb_p, hidan, bombOK;

int enex[100], eney[100], bakuha, gekiha, itemOK, RSOK;
double kasoku, Shokx, Shoky;

int dai2, dai3, dai4, frame, bsf = 1;

int dotyufin, bossout, lastout;

int gameover, makkura;

//-----------------------------------------タイトルのデータ-------------------------------------//

double n1, n2, n3, n4, n5, m1, m2, m3, m4, m5;
double x, taihai, x1;

int sentaku;
int owacon;

//---------------------------------------ゲーム画面のデータ------------------------------------//

int zikix, zikiy;
int stage;

int i, n, count2, j;
int count;

int stop, stocon, name, namehai, name2;
int namecon;

int ziki[6];
int kaisyu, enix[100], eniy[100];

double bombsize = 0.3;
int mode=1;

long score = 0, amari;
long hyakuman, juman, man, sen, hyaku, ju, iti;

double Thp = 0, Bhp = 0;

long hiscore = 100, hi_amari;
long hi_hyakuman, hi_juman, hi_man, hi_sen, hi_hyaku, hi_ju, hi_iti;

//--------------------------------------------------------------------------------------------------//

unsigned long Kcon = 0;
unsigned long Han = 0;

int Miss = 0, ModeM = 0;





//画像ファイルハンドル
int img_background[8];
int img_titleph[11];
int img_mode[10];
int img_player[4];

int img_game[12];
int img_tama[3], img_chara[110];
int img_logo[6];
int img_bomb;

int img_mentai[1];

int img_enemy1[5];

int img_tyuboss;
int img_1boss[4];
int img_caution[3];

int img_score[10];
int img_item[2];

int img_clear, img_totitle, img_lose[8], img_anten;

//弾の画像
int img_player_shot[2];
int img_enemy_shot[20];

//エフェクト
int img_hidan[15];
int img_bakuha[16];
int img_tamabaku[16];
int img_bossbaku[16];
int img_bokasi;


//音声ファイルハンドル
int sound_player_shot[2];
int sound_enemy_shot[2];
int sound_enemy_tyakudan;
int sound_enemy_death;
int sound_tb_death;
int sound_keikoku;
int sound_shot_del;
int sound_b_death;
int sound_tame, sound_bom;
int sound_item;
int sound_over;

int sound_dotyu;
int sound_boss;
int sound_last;


//構造体
//プレイヤー
typedef struct {
	double x, y;
	int status, counter;
} BODY_player_t;

BODY_player_t Player;


//敵
typedef struct {
	double x, y, size;
	int flag, counter, hp, pattern, range;
} BODY_enemy_t;

BODY_enemy_t enemy[ENEMY_TOTAL_NUM];//[1000]

									//中ボス
typedef struct {
	double x, y, size, hp;
	int flag, counter, df, range, muteki;
} BODY_tyuboss;

BODY_tyuboss tyuboss;

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

Tyu_Shot TyuShot;

//ボス
typedef struct {
	double x, y, size, hp;
	int flag, counter, df, range, muteki;
} BODY_boss;

BODY_boss boss;

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

Boss_Shot BossShot;


//ショット（プレイヤー）
typedef struct {
	double x, y;
	int flag;
} SHOT_t;

SHOT_t PlayerShot[PLAYER_MAX_SHOT1][PLAYER_MAX_SHOT2];


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

ENEMY_SHOT_t EnemyShot[ENEMY_TOTAL_NUM];//[1000];


										//アイテム
typedef struct {
	double x, y;
	int flag, counter;
} Item_t;

Item_t item[ENEMY_TOTAL_NUM];//[100]