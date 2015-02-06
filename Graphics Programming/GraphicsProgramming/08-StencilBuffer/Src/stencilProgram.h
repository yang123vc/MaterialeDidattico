//--------------------------------------------------------------------------------------
// Copyright (c) Luca Giona 2013. Do not distribute. (Master Game Development - University of Verona)
//--------------------------------------------------------------------------------------

#pragma once

#include "sampleProgram.h"
#include "camera.h"
#include "types.h"

#include "GeometricPrimitive.h"

#include <memory>

namespace mcg
{
	class TextDrawer;
	class TextFont;
}

class StencilProgram : public mcg::SampleProgram
{
public:
	StencilProgram(const HINSTANCE hInstance, const int nCmdShow);

	HRESULT initializeResources();
	void cleanResouces();

	void preRender();
	void render();

	void keyPressed(WPARAM key, LPARAM param);
	void keyReleased(WPARAM key, LPARAM param);
private:
	enum KEY_INDICES
	{
		ROTATE_CAMERA_LEFT = 0,
		ROTATE_CAMERA_RIGHT,
		ROTATE_CAMERA_UP,
		ROTATE_CAMERA_DOWN,
		MOVE_CAMERA_FOREWARD,
		MOVE_CAMERA_BACKWARD,
		MAX_KEY,
	};

	mcg::TextDrawer* mTextDrawer;
	mcg::TextFont* mArialFont;

	mcg::SphericCamera mCamera;

	mcg::Transformations mTransforms;
	mcg::Material mMaterial;
	mcg::Lights mLights;
	DirectX::XMFLOAT4 mOutlineColor;

	ID3D11Buffer* mVertexBuffer;
	ID3D11Buffer* mIndexBuffer;
	ID3D11Buffer* mTranfCBuffer;
	ID3D11Buffer* mMaterialCBuffer;
	ID3D11Buffer* mLightsCBuffer;
	ID3D11Buffer* mOutlineColorCBuffer;
	ID3D11VertexShader* mPhongVS;
	ID3D11PixelShader* mPhongPS;
	ID3D11InputLayout* mPhongInputLayout;
	ID3D11VertexShader* mOutlineVS;
	ID3D11PixelShader* mOutlinePS;
	ID3D11InputLayout* mOutlineInputLayout;
	ID3D11DepthStencilState* mDepthStencilState;
	ID3D11DepthStencilState* mPhongDepthStencilState;
	ID3D11DepthStencilState* mOultineDepthStencilState;

	bool pauseLightsRotation;
	bool keys[MAX_KEY];

	std::unique_ptr<DirectX::GeometricPrimitive> mLightSphere;
};
