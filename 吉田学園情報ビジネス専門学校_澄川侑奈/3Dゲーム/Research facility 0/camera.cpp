//--------------------------------------------------------------------------------
//
//	カメラの処理 [camera.cpp]
//	Author:Yuna Sumikawa
//
//--------------------------------------------------------------------------------
#include "camera.h"				// カメラ
#include "keyboard.h"			// キーボード
#include "player.h"				// プレイヤー
#include "Xcontroller.h"		// Xinput

//--------------------------------------------------------------------------------
//	マクロ定義
//--------------------------------------------------------------------------------
#define NEAR_CAMERA_Z	(100.0f)		// Z軸の手前
#define BACK_CAMERA_Z	(2000.0f)		// Z軸の奥

#define MAX_V			(3)				// カメラ(視点)速さ
#define MAX_LONG		(-200)			// 視点から注視点の長さ

//--------------------------------------------------------------------------------
// グローバル変数
//--------------------------------------------------------------------------------
Camera g_camera;		//カメラの情報

//--------------------------------------------------------------------------------
// 初期化処理
//--------------------------------------------------------------------------------
void InitCamera(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// カメラの情報初期化
	g_camera.posV = D3DXVECTOR3(0.0f, 250.0f, -400.0f);
	//g_camera.posV = D3DXVECTOR3(0.0f, 100.0f, -200.0f);
	g_camera.posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_camera.vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	g_camera.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// ビューポート
	// g_camera.viewport.X = 0;			// 描画する画面の左上X座標
	// g_camera.viewport.Y = 100;			// Y
	// g_camera.viewport.Width = 500;		// 幅
	// g_camera.viewport.Height = 250;		// 高さ
	// g_camera.viewport.MinZ = 0.0f;
	// g_camera.viewport.MinZ = 1.0f;
}

//--------------------------------------------------------------------------------
// 終了処理
//--------------------------------------------------------------------------------
void UninitCamera(void)
{

}

//--------------------------------------------------------------------------------
// 更新処理
//--------------------------------------------------------------------------------
void UpdateCamera(void)
{
	// プレイヤー情報
	Player *pPlayer = GetPlayer();

	// リリースの時に機能させない
#ifdef _DEBUG
		// カメラの移動処理(P視点)
		// Wキーを押した
		if (GetkeyboardPress(DIK_UP) == true)
		{// 上
			g_camera.posV.x += sinf(g_camera.rot.y) * MAX_V;
			g_camera.posR.x += sinf(g_camera.rot.y) * MAX_V;
			g_camera.posR.z += cosf(g_camera.rot.y) * MAX_V;
			g_camera.posV.z += cosf(g_camera.rot.y) * MAX_V;
		}

		// Sキーを押した
		if (GetkeyboardPress(DIK_DOWN) == true)
		{// 下
			g_camera.posV.x -= sinf(g_camera.rot.y) * MAX_V;
			g_camera.posR.x -= sinf(g_camera.rot.y) * MAX_V;
			g_camera.posR.z -= cosf(g_camera.rot.y) * MAX_V;
			g_camera.posV.z -= cosf(g_camera.rot.y) * MAX_V;
		}

		// Aキーを押した
		if (GetkeyboardPress(DIK_LEFT) == true)
		{// 左
			g_camera.posV.x -= cosf(g_camera.rot.y) * MAX_V;
			g_camera.posR.x -= cosf(g_camera.rot.y) * MAX_V;
			g_camera.posR.z += sinf(g_camera.rot.y) * MAX_V;
			g_camera.posV.z += sinf(g_camera.rot.y) * MAX_V;
		}

		// Dキーを押した
		if (GetkeyboardPress(DIK_RIGHT) == true)
		{// 右
			g_camera.posV.x += cosf(g_camera.rot.y) * MAX_V;
			g_camera.posR.x += cosf(g_camera.rot.y) * MAX_V;
			g_camera.posR.z -= sinf(g_camera.rot.y) * MAX_V;
			g_camera.posV.z -= sinf(g_camera.rot.y) * MAX_V;
		}
#endif

	// カメラ(視点)の移動処理
	// Yキーを押した
	if (GetkeyboardPress(DIK_Y) == true)
	{// 上
		g_camera.posV.y += MAX_V;
	}

	// Nキーを押した
	if (GetkeyboardPress(DIK_N) == true)
	{// 下
		g_camera.posV.y -= MAX_V;

	}

	// Zキーを押した
	if (GetkeyboardPress(DIK_Z) == true)
	{// 左
		g_camera.rot.y += 0.05f;		// 角度
		if (g_camera.rot.y > D3DX_PI)
		{
			g_camera.rot.y -= D3DX_PI*2.0f;
		}

	}

	// Cキーを押した
	if (GetkeyboardPress(DIK_C) == true)
	{// 右
		g_camera.rot.y -= 0.05f;		// 角度
		if (g_camera.rot.y < (-D3DX_PI))
		{
			g_camera.rot.y += D3DX_PI * 2.0f;
		}

	}

	// カメラ(注視点)の移動処理

	// Tキーを押した
	if (GetkeyboardPress(DIK_T) == true)
	{// 上
		g_camera.posR.y += MAX_V;
	}

	// Bキーを押した
	if (GetkeyboardPress(DIK_B) == true)
	{// 下
		g_camera.posR.y -= MAX_V;
	}

	// 視点の制御
	g_camera.posVDest.x = pPlayer->pos.x - sinf(g_camera.rot.y + D3DX_PI) * 400.0f;
	g_camera.posVDest.z = pPlayer->pos.z + cosf(g_camera.rot.y - D3DX_PI) * 400.0f;
	g_camera.posVDest.y = pPlayer->pos.y + 250.0f;

	// 注視点の制御
	//g_camera.posRDest.x = pPlayer->pos.x + sinf(pPlayer->rot.y - D3DX_PI) * 250.0f;
	//g_camera.posRDest.z = pPlayer->pos.z + cosf(pPlayer->rot.y - D3DX_PI) * 400.0f;
	//g_camera.posRDest.y = pPlayer->pos.y;

	// 注視点の制御
	g_camera.posRDest.x = pPlayer->pos.x;
	g_camera.posRDest.z = pPlayer->pos.z;
	g_camera.posRDest.y = pPlayer->pos.y;
	// 視点の更新
	g_camera.posV.x += (g_camera.posVDest.x - g_camera.posV.x) * 0.08f;
	g_camera.posV.z += (g_camera.posVDest.z - g_camera.posV.z) * 0.08f;
	g_camera.posV.y += (g_camera.posVDest.y - g_camera.posV.y) * 0.08f;

	// 注視点の更新
	g_camera.posR.x += (g_camera.posRDest.x - g_camera.posR.x) * 0.08f;
	g_camera.posR.z += (g_camera.posRDest.z - g_camera.posR.z) * 0.08f;
	g_camera.posR.y += (g_camera.posRDest.y - g_camera.posR.y) * 0.08f;


	// Qキーを押した
//	if (GetkeyboardPress(DIK_Q) == true) 
//	{// 左
//		g_camera.rot.y -= 0.05f;		// 角度
//		g_camera.posR.x = g_camera.posV.x - sinf(g_camera.rot.y) * MAX_LONG;
//		g_camera.posR.z = g_camera.posV.z - cosf(g_camera.rot.y) * MAX_LONG;
//
//		// カメラの向きの処理
//		if (g_camera.rot.y < -D3DX_PI)
//		{	// -3.14
//			g_camera.rot.y += D3DX_PI * 2.0f;
//
//		}
//	}
//
//	// Eキーを押した
//	if (GetkeyboardPress(DIK_E) == true)
//	{// 右
//		g_camera.rot.y += 0.05f;		// 角度
//		g_camera.posR.x = g_camera.posV.x - sinf(g_camera.rot.y) * MAX_LONG;
//		g_camera.posR.z = g_camera.posV.z - cosf(g_camera.rot.y) * MAX_LONG;
//
//		// カメラの向きの処理
//		if (g_camera.rot.y > D3DX_PI)
//		{	// +3.14
//			g_camera.rot.y -= D3DX_PI * 2.0f;
//
//		}
//	}
//
//	//カメラの位置リセット
//	// スペースキーを押した
//	if (GetkeyboardPress(DIK_M) == true)
//	{
//		g_camera.posV = D3DXVECTOR3(0.0f, 100.0f, -200.0f);
//		g_camera.posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//		g_camera.vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
//		g_camera.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//	}
}

//--------------------------------------------------------------------------------
// カメラの設定
//--------------------------------------------------------------------------------
void SetCamera(int nldx)
{
	// デバイスの取得a
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// ビューポートの設定
//	pDevice->SetViewport(&g_camera.viewport);

	// プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&g_camera.mtxProjection);

	// プロジェクションマトリックスを作成
	D3DXMatrixPerspectiveFovLH(&g_camera.mtxProjection,
		D3DXToRadian(45.0f),								// 画角(これを変えると画面がギュンってなる(マリカのダッシュみたいなやつ))
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,			// 画面比率(フロートにしているから小数点も出ていい感じになる)
	//	(float)500 / (float)250,			// 画面比率(ビューポート)
		NEAR_CAMERA_Z,										// Z軸の手前
		BACK_CAMERA_Z);										// Z軸の奥

	// プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &g_camera.mtxProjection);

	// ビューマトリックスの初期化
	D3DXMatrixIdentity(&g_camera.mtxView);

	// ビューマトリックスの作成
	D3DXMatrixLookAtLH(&g_camera.mtxView,
		&g_camera.posV,
		&g_camera.posR,
		&g_camera.vecU);

	// ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &g_camera.mtxView);
}

//--------------------------------------------------------------------------------
//	カメラの取得
//--------------------------------------------------------------------------------
Camera * GetCamera(void)
{
	return &g_camera;		// カメラの情報の先頭アドレスを返す
}