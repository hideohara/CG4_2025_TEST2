#pragma once

#include <KamataEngine.h>


#include "Particle.h"

using namespace KamataEngine;
using namespace MathUtility;

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene
{
public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

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


private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>

	// テクスチャハンドル プレイヤー 
	uint32_t textureHandlePlayer_ = 0;

	// 3Dモデル プレイヤー 
	Model* modelPlayer_ = nullptr;

	// カメラ
	Camera camera_;

	// 各クラス
	//Particle* particle_ = nullptr;

	// 敵
	std::list<Particle*> particles_;

	// パーティクル移動の速さ
	static inline const float particleSpeed = 0.1f;

	// パーティクル発生
	void ParticleBorn(Vector3 position);
};

