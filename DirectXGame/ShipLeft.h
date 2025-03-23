#pragma once

#include <KamataEngine.h>
using namespace KamataEngine;

class ShipLeft
{
public: // メンバ関数

	/// <summary>
	/// デストラクタ
	/// </summary>
	~ShipLeft();

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
	Sprite* sprite_[5] = {};

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	// ライフ
	float life_ = 5u;

	// サイズ
	const float sizeX = 40.0f;
	const float sizeY = 40.0f;

	// タイマー
	int32_t timer_ = 0;
};

