#include "DxLib.h"
#include "Ex.h"

void RS_1(), RS_2(), RS_3(), RS_4(), RS_5(),RS_6();
void initialization();

void Reset() {

	initialization();
	RS_1();
	RS_2();
	RS_3(); RS_4();
	RS_5(); RS_6();
}