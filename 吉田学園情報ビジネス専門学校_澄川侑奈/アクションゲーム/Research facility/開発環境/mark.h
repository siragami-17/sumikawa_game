//-------------------------------------------------------------------
//
// マーカーヘッダー (marker.h)
// Author:Yuna Sumikawa
//
//-------------------------------------------------------------------
#ifndef _MARKER_H_
#define _MARKER_H_

#include "main.h"



//-------------------------------------------------------------------
// ブロックの状態
//-------------------------------------------------------------------
typedef enum
{
	MARKERSTATE_NORMAL = 0,	// 何もしていないとき
	MARKERSTATE_CHACHING,	// 何かつかんでいるとき
	MARKERSTATE_MAX,
}MARKERSTATE;

//-------------------------------------------------------------------
// 構造体の定義
//-------------------------------------------------------------------
typedef struct
{
	D3DXVECTOR3 pos;		// 座標
	D3DXVECTOR3 posOld;		// 前の位置
	D3DXVECTOR3 move;		// 移動量
	float fWidth;			// 幅
	float fHeight;			// 高さ
	MARKERSTATE state;		// ブロックの状態
	int nCntPatternAnim;	// アニメーションカウント
	bool bUse;				// 使用しているかどうか
}MARKER;

//-------------------------------------------------------------------
// プロトタイプ宣言
//-------------------------------------------------------------------
HRESULT InitMarker(void);	// マーカーの初期化処理
void UninitMarker(void);	// マーカーの終了処理
void UpdateMarker(void);	// マーカーの更新処理
void DrawMarker(void);		// マーカーの描画処理
MARKER *GetMarker(void);

#endif
