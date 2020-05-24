#include "Dxlib.h"
#include "Ex.h"


void Score() {

	//スコアの計算

	hyakuman = score / 1000000;
	amari = score % 1000000;

	juman = amari / 100000;
	amari = amari % 100000;

	man = amari / 10000;
	amari = amari % 10000;

	sen = amari / 1000;
	amari = amari % 1000;

	hyaku = amari / 100;
	amari = amari % 100;

	ju = amari / 10;
	amari = amari % 10;

	iti = amari;

	//スコアの表示

	DrawRotaGraph(990, 180, 0.85, 0.0, img_score[hyakuman], TRUE);
	DrawRotaGraph(1010, 180, 0.85, 0.0, img_score[juman], TRUE);
	DrawRotaGraph(1030, 180, 0.85, 0.0, img_score[man], TRUE);
	DrawRotaGraph(1050, 180, 0.85, 0.0, img_score[sen], TRUE);
	DrawRotaGraph(1070, 180, 0.85, 0.0, img_score[hyaku], TRUE);
	DrawRotaGraph(1090, 180, 0.85, 0.0, img_score[ju], TRUE);
	DrawRotaGraph(1110, 180, 0.85, 0.0, img_score[iti], TRUE);


	//ハイスコアの計算

	hi_hyakuman = hiscore / 1000000;
	hi_amari = hiscore % 1000000;

	hi_juman = hi_amari / 100000;
	hi_amari = hi_amari % 100000;

	hi_man = hi_amari / 10000;
	hi_amari = hi_amari % 10000;

	hi_sen = hi_amari / 1000;
	hi_amari = hi_amari % 1000;

	hi_hyaku = hi_amari / 100;
	hi_amari = hi_amari % 100;

	hi_ju = hi_amari / 10;
	hi_amari = hi_amari % 10;

	hi_iti = hi_amari;

	if (score >= hiscore)
		hiscore = score;


	//ハイスコアの表示

	DrawRotaGraph(990, 140, 0.85, 0.0, img_score[hi_hyakuman], TRUE);
	DrawRotaGraph(1010, 140, 0.85, 0.0, img_score[hi_juman], TRUE);
	DrawRotaGraph(1030, 140, 0.85, 0.0, img_score[hi_man], TRUE);
	DrawRotaGraph(1050, 140, 0.85, 0.0, img_score[hi_sen], TRUE);
	DrawRotaGraph(1070, 140, 0.85, 0.0, img_score[hi_hyaku], TRUE);
	DrawRotaGraph(1090, 140, 0.85, 0.0, img_score[hi_ju], TRUE);
	DrawRotaGraph(1110, 140, 0.85, 0.0, img_score[hi_iti], TRUE);

}