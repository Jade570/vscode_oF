#include "ofMain.h"


class aurora{
	public:
		void Create(int px, int py, int x, int y, int framenum);
		void Reset();
		void Show(int r, int g, int b, int a, float noise, int height);

	int frameNum;
	int opacity;
	int pX, pY;
	int xPos = -1, yPos = -1;
	float Noise;
	bool IsShowing = false;
};