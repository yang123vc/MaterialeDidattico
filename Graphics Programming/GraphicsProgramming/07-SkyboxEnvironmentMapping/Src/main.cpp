//--------------------------------------------------------------------------------------
// Copyright (c) Luca Giona 2013. Do not distribute. (Master Game Development - University of Verona)
//--------------------------------------------------------------------------------------

#include <Windows.h>

#include "skyboxProgram.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SkyboxProgram app(hInstance, nCmdShow);
	app.setWindowTitle(L"07 - Skybox e Environment Mapping");
	app.setWindowSize(640, 480);

	return app.run();
}