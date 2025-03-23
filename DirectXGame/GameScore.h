#pragma once

#include <KamataEngine.h>
using namespace KamataEngine;

class GameScore
{
public: // メンバ関数

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScore();

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

	// スコア
	int32_t score_ = 0u;

	// サイズ
	const float sizeX = 32.0f;
	const float sizeY = 64.0f;
};

