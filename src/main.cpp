#include <iostream>
#include "Window.h"
#include "Ex01TriangleDraw.h"
#include "Ex02QuadDraw.h"
#include "Ex03QuadIndexDraw.h"

int main() {
	std::cout << "It' Working" << std::endl;

	Window* Win = new Window(800, 600, "OpenGL Window");
	
	float TimeElapsed = 0.f;

	//Ex01TriangleDraw Scene;
	//Ex02QuadDraw Scene;
	Ex03QuadIndexDraw Scene;

	Scene.Start();
	// till Window is not in closing
	while (Win->IsOpened())
	{
		// update fps 1 sec
		TimeElapsed += Win->GetDeltaTime();
		if (TimeElapsed >= 1.f)
		{
			TimeElapsed -= 1.f;
			int Fps = 1.f / Win->GetDeltaTime();
			char Title[50];
			sprintf_s(Title, sizeof(Title), "OpenGL App | DeltaTime: %f - FPS: %d", Win->GetDeltaTime(), Fps);

			Win->SetTitle(Title);
		}
		
		Scene.Update();
		Win->Update();
	}

	Scene.Destroy();
	delete Win;
	return 0;	
}