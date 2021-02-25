//--------------------------------------------------------------------------------
//
//	ブロックの処理 [object.h]
//	Author:Yuna Sumikawa
//
//--------------------------------------------------------------------------------
#ifndef  _OBJECT_H_
#define	_OBJECT_H_

#include "main.h"

//--------------------------------------------------------------------------------
//	マクロ定義
//--------------------------------------------------------------------------------
#define MAX_OBJECT		(4)		// 読み込むパーツ数

//--------------------------------------------------------------------------------
// ブロックの構造体
//--------------------------------------------------------------------------------
typedef struct
{
	D3DXVECTOR3 pos;				// 位置
	D3DXVECTOR3 blockVec;			// ブロックとプレイヤーのベクトル
	D3DXVECTOR3 rot;				// 向き
	D3DXVECTOR3 move;				// 移動量
	D3DXVECTOR3 size;				// サイズ
	D3DXMATRIX mtxWorld;			// ワールドマトリックス

	float fWidth;					// 幅
	float fHeight;					// 高さ
	float fLength;					// 長さ
	float fRadius;					// 半径

	bool bUse;						// 使用しているかどうか

}Object;

//--------------------------------------------------------------------------------
// プロトタイプ宣言
//--------------------------------------------------------------------------------
HRESULT InitObject(void);
void UninitObject(void);
void UpdateObject(void);
void DrawObject(void);

Object *Getobject(void);				// オブジェクトの情報

void SetObject(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size);		// オブジェクトの設定

#endif