#include "GameScene.h"

// デストラクタ
GameScene::GameScene() {}

// コンストラクタ
GameScene::~GameScene() {
	delete modelPlayer_;

	delete particle_;
}

// 初期化
void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// ファイル名を指定してテクスチャを読み込む
	textureHandlePlayer_ = TextureManager::Load("mario.jpg");

	// 3Dモデルの生成
	//modelPlayer_ = Model::Create();
	//modelPlayer_ = Model::CreateFromOBJ("plane",true);
	modelPlayer_ = Model::CreateFromOBJ("deathParticle", true);

	// カメラ初期化
	camera_.Initialize();

	// 各クラス
	particle_ = new Particle();
	particle_->Initialize(modelPlayer_, textureHandlePlayer_, { 3,0,0 });
}

// 更新
void GameScene::Update() {
	// 各クラス
	particle_->Update();
}

// 描画
void GameScene::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	// 各クラス
	particle_->Draw(camera_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
}