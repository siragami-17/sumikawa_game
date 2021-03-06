//--------------------------------------------------------------------------------
//
//	ポーズの処理 [pause.h]
//	Author:Yuna Sumikawa
//
//--------------------------------------------------------------------------------
#ifndef  _PAUSE_H_
#define	_PAUSE_H_

#include "main.h"

//--------------------------------------------------------------------------------
//	ポーズの列挙型
//--------------------------------------------------------------------------------
typedef enum
{
	PAUSE_MENU_CONTINOE = 0,	//コンティニュー
	PAUSE_MENU_RETRY,			//リトライ
	PAUSE_MENU_QUIT,			//終了
	PAUSE_MENU_MAX
}PAUSE_MENU;

//-------------------------------------------------------------------------------
//	構造体
//-------------------------------------------------------------------------------
typedef struct
{
	D3DXVECTOR3 pos;
} PAUSE;

//-------------------------------------------------------------------------------
//プロトタイプ宣言
//-------------------------------------------------------------------------------
HRESULT InitPause(void);
void UninitPause(void);
void UpdatePause(void);
void DrawPause(void);

#endif