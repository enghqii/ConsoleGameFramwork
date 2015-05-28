#pragma once
#include <Windows.h>

/* Device context */

namespace cgf{

	class RenderTarget;

	class CGFDevice
	{
	public:
		CGFDevice(int width, int height);
		~CGFDevice(void);

		void Present(RenderTarget* target);

	private:
		HANDLE		handleScreenBuffer1;
		HANDLE		handleScreenBuffer2;
		SMALL_RECT	srctWriteRect;
		int			width;
		int			height;
	};

}