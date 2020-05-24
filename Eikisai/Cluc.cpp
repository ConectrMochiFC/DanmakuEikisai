#include "DxLib.h"
#include "Ex.h"


void Title_Calc() {
	static int ren = 0;
	if (count >= 180) {

		if (CheckHitKey(KEY_INPUT_UP) == 1 && ren==0) {
			sentaku--; ren = 1;
		}

		if (CheckHitKey(KEY_INPUT_DOWN) == 1 && ren==0) {
			sentaku++; ren = 1;
		}
		if (CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0) ren = 0;

		if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
			if (sentaku == 1) {
				scene = 3;

				count = 2100; taihai = 0; x = 0; x1 = -320;
				n1 = n2 = n3 = n4 = n5 = 1.5;
				m1 = m2 = m3 = m4 = m5 = 0;

			}

			if (sentaku == 2)
				owacon = 1;

		}
	}

	count++;

	if (sentaku == 0)	sentaku = 2;

	if (sentaku == 3)	sentaku = 1;


	//+++++++++++++++++++++++++++++++++++++++++拡大設定++++++++++++++++++++++++++++++++++++++++++//

	if (count >= 10 && count<20) {
		if (n1 >= 0.5)	n1 -= 0.1;
	}

	if (count >= 20 && count<30) {
		if (n2 >= 0.5)	n2 -= 0.1;
	}

	if (count >= 30 && count<40) {
		if (n3 >= 0.5)	n3 -= 0.1;
	}

	if (count >= 40 && count<50) {
		if (n4 >= 0.5)	n4 -= 0.1;
	}

	if (count >= 50 && count<60) {
		if (n5 >= 0.5)	n5 -= 0.1;
	}

	//++++++++++++++++++++++++++++++++++++++++回転設定++++++++++++++++++++++++++++++++++++++++++++//

	if (count >= 10 && count<120) {
		if (m1 <= 6.4)	m1 += 0.2;
	}

	if (count >= 20 && count<120) {
		if (m2 <= 6.4)	m2 += 0.2;
	}

	if (count >= 30 && count<120) {
		if (m3 <= 6.4)	m3 += 0.2;
	}

	if (count >= 40 && count<120) {
		if (m4 <= 6.4)	m4 += 0.2;
	}

	if (count >= 50 && count<120) {
		if (m5 <= 6.4)	m5 += 0.2;
	}


}



void Game_Calc() {

	//--------------------------------------------自機の移動設定---------------------------------------//

	if (CheckHitKey(KEY_INPUT_RIGHT) >= 1) {

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1)	zikix += 3;
		else if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)	zikix += 3;
		else if (CheckHitKey(KEY_INPUT_LSHIFT) == 0 && CheckHitKey(KEY_INPUT_RSHIFT) == 0)	zikix += 5;
	}

	if (CheckHitKey(KEY_INPUT_LEFT) >= 1) {

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1)	zikix -= 3;
		else if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)	zikix -= 3;
		else if (CheckHitKey(KEY_INPUT_LSHIFT) == 0 && CheckHitKey(KEY_INPUT_RSHIFT) == 0)	zikix -= 5;
	}

	if (CheckHitKey(KEY_INPUT_DOWN) >= 1) {

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1)	zikiy += 3;
		else if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)	zikiy += 3;
		else if (CheckHitKey(KEY_INPUT_LSHIFT) == 0 && CheckHitKey(KEY_INPUT_RSHIFT) == 0)	zikiy += 5;
	}

	if (CheckHitKey(KEY_INPUT_UP) >= 1) {

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1)	zikiy -= 3;
		else if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)	zikiy -= 3;
		else if (CheckHitKey(KEY_INPUT_LSHIFT) == 0 && CheckHitKey(KEY_INPUT_RSHIFT) == 0)	zikiy -= 5;
	}

	if (CheckHitKey(KEY_INPUT_UP) >= 1 && CheckHitKey(KEY_INPUT_RIGHT) >= 1 && CheckHitKey(KEY_INPUT_LEFT) >= 1) {

		if (CheckHitKey(KEY_INPUT_LSHIFT) >= 1)	zikiy -= 3;
		else if (CheckHitKey(KEY_INPUT_RSHIFT) >= 1)	zikiy -= 3;

		else if (CheckHitKey(KEY_INPUT_LSHIFT) == 0 && CheckHitKey(KEY_INPUT_RSHIFT) == 0)	zikiy -= 5;

	}


	//------------------------------自機に滑らかーになってもらう！！---------------------------------//


	if (CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
		if (name<2 * name2) {
			name++;
		}
	}
	else {

		if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1) {
			if (name<2 * name2) {
				name++;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) >= 1) {

			if (name >= 30) {
				name = name - 30;
				name = 30 - name;
			}

			if (name<30) {
				name++;
			}
			namehai = 2;
			name2 = name;
		}

		if (CheckHitKey(KEY_INPUT_RIGHT) >= 1) {

			if (name >= 30) {
				name = name - 30;
				name = 30 - name;
			}

			if (name<30) {
				name++;
			}
			namehai = 1;
			name2 = name;
		}
	}


	//--------------------------------------------------------------------------------------------------//


	//--------------------------------------壁にいるか確認する-----------------------------------//

	if (zikix >= 808)	zikix = 808;

	if (zikix <= 60)	zikix = 60;

	if (zikiy >= 890)	zikiy = 890;

	if (zikiy <= 62)	zikiy = 62;

}