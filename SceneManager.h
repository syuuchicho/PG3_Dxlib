#pragma once
class SceneManager final
{
private:
	//�R���X�g���N�^
	SceneManager();
	//�f�X�g���N�^
	~SceneManager();

public:
	//�R�s�[�R���X�g���N�^�𖳌�
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q�𖳌�
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();//�ÓI�����o�[�֐�

	void SceneChange(int &sceneNo);
};

