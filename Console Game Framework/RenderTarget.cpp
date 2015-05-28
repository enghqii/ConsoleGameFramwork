#include "RenderTarget.h"

namespace cgf{

	RenderTarget::RenderTarget(int width, int height)
		:width(width), height(height)
	{
		chiBuffer = new CHAR_INFO[width * height];
	}


	RenderTarget::~RenderTarget(void)
	{
		delete [] chiBuffer;
	}

	const COORD RenderTarget::GetSizeCoord(){
		COORD coordSize;
		coordSize.X = width;
		coordSize.Y = height;
		return coordSize;
	}
	
	void RenderTarget::Clear(){
		for (int y = 0; y < this->height; ++y)
		{
			for (int x = 0; x < this->width; ++x)
			{
				chiBuffer[x + this->width * y].Char.UnicodeChar = ' ';
				chiBuffer[x + this->width * y].Attributes = BACKGROUND_INTENSITY;
			}
		}
	}

	void RenderTarget::DrawChar(int x, int y, CHAR_INFO ch){

		if( 0 < x && x < width ) {
			if( 0 < y && y < height ) {
				chiBuffer[x + this->width * y] = ch;
			}
		}
	}
}