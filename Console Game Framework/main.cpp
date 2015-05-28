#include "CGFDevice.h"
#include "RenderTarget.h"

#define WIDTH 120
#define HEIGHT 40

int main(){

	cgf::CGFDevice		device(WIDTH, HEIGHT);
	cgf::RenderTarget	target(WIDTH, HEIGHT);

	float x = 0, y = 0;
	float dx = 0,dy = 0;

	CHAR_INFO ch;
	ch.Char.UnicodeChar = 'A';
	ch.Attributes = FOREGROUND_GREEN;

	while(true){
		// update call
		if(GetAsyncKeyState(VK_LEFT) < 0){
			dx--;
		}

		if(GetAsyncKeyState(VK_RIGHT) < 0 ){
			dx++;
		}

		if(GetAsyncKeyState(VK_UP) < 0){
			dy--;
		}

		if(GetAsyncKeyState(VK_DOWN) < 0 ){
			dy++;
		}

		x += dx;
		y += dy;
		
		dx *= 0.8f;
		dy *= 0.8f;

		// draw call
		target.Clear();
		target.DrawChar(x, y, ch);
		device.Present(&target);

		// and sleep
		Sleep(1.0f / 60.0f * 1000.0f);
	}

	return 0;
}