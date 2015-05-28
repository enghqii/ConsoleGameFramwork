#include "CGFDevice.h"
#include "RenderTarget.h"

namespace cgf{

	CGFDevice::CGFDevice(int width, int height)
		:width(width), height(height)
	{
		handleScreenBuffer1 = CreateConsoleScreenBuffer( GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		handleScreenBuffer2 = CreateConsoleScreenBuffer( GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

		srctWriteRect.Left = 0;
		srctWriteRect.Top = 0;
		srctWriteRect.Right = width - 1;
		srctWriteRect.Bottom = height - 1;
		
		COORD coordBufSize = {width, height};

		SetConsoleScreenBufferSize(handleScreenBuffer1, coordBufSize);
		SetConsoleWindowInfo(handleScreenBuffer1, TRUE, &srctWriteRect);
		SetConsoleScreenBufferSize(handleScreenBuffer2, coordBufSize);
		SetConsoleWindowInfo(handleScreenBuffer2, TRUE, &srctWriteRect);
	}

	CGFDevice::~CGFDevice(void)
	{
	}
	
	void CGFDevice::Present(RenderTarget* target) {

		static int counter = 0;
		counter++;

		HANDLE handleCurrentScreen;

		if(counter % 2 == 0){
			handleCurrentScreen = handleScreenBuffer1;
		} else {
			handleCurrentScreen = handleScreenBuffer2;
		}

		COORD offset = {0,0};
		WriteConsoleOutput( 
			handleCurrentScreen,
			target->GetCharInfoBuffer(),
			target->GetSizeCoord(),
			offset,
			&srctWriteRect);

		SetConsoleActiveScreenBuffer(handleCurrentScreen);
	}
}