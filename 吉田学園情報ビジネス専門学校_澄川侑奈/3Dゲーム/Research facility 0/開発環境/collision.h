//--------------------------------------------------------------------------------
//
//	当たり判定の処理 [collision.h]
//	Author:Yuna Sumikawa
//
//--------------------------------------------------------------------------------
#ifndef  _COLLISION_H_
#define	_COLLISION_H_

#include "main.h"

//--------------------------------------------------------------------------------
// プロトタイプ宣言
//--------------------------------------------------------------------------------
// pPos1 = 動いてるポリゴンの位置,posOld = 動いてるポリゴンの過去の位置,size = 動いてるポリゴンのサイズ
// pPos2 = 動かないポリゴンの位置,size2 = 動かないポリゴンのサイズ
bool SetCollision(D3DXVECTOR3 * pPos1, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 size1, D3DXVECTOR3 * pPos2, D3DXVECTOR3 size2);

#endif