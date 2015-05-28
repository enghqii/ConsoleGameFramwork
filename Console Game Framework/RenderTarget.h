#pragma once
#include<Windows.h>

namespace cgf{

	class RenderTarget
	{
	public:
		RenderTarget(int width, int height);
		~RenderTarget(void);

		const CHAR_INFO*	GetCharInfoBuffer(){ return this->chiBuffer; }
		const COORD			GetSizeCoord();

		void				Clear();
		void				DrawChar(int x, int y, CHAR_INFO ch);

	private:
		CHAR_INFO*	chiBuffer;

		int			width;
		int			height;
	};

}