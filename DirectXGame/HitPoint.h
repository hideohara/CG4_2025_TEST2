#pragma once

#include <KamataEngine.h>
using namespace KamataEngine;

class HitPoint
{
public: // メンバ関数

	/// <summary>
	/// デストラクタ
	/// </summary>
	~HitPoint();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	// スプライト
	Sprite* sprite_ = nullptr;
	Sprite* spriteDark_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	uint32_t textureHandleDark_ = 0u;

	// ライフ
	float life_ = 0u;

	// サイズ
	const float sizeX = 320.0f;
	const float sizeY = 32.0f;

};

