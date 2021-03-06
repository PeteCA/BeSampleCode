/*
	Copyright 1999, Be Incorporated.   All Rights Reserved.
	This file may be used under the terms of the Be Sample Code License.
*/

#include <stdio.h>
#include "CrayonColorPicker.h"

const color_space kCrayonColorSpace = B_COLOR_8_BIT;
const int32 kCrayonWidth = 20;
const int32 kCrayonHeight = 32;

const unsigned char kCrayonBits [] = {
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0x00,0x00,0x00,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,
	0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,
	0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x00,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0x00,0x1b,0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,0x1b,0x00,0xff,0xff,
	0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xff,0x00,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,
	0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x00,0x00,0x00,0x00,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,
	0x00,0x00,0x00,0x1b,0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,0x1b,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0x00,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b
};

//

rgb_color color(uint8 r, uint8 g, uint8 b)
{
	rgb_color c;
	c.red = r;
	c.green = g;
	c.blue = b;
	c.alpha = 255;
	
	return c;
}

//

TCrayon::TCrayon(BControl* parent, BRect frame, rgb_color color)
{
	fParent = parent;
	fFrame = frame;
	fColor = color;
	
	BRect r(frame);
	r.OffsetTo(0,0);

	fIcon = new BBitmap(r, kCrayonColorSpace, false, false);
	if (fIcon)
		fIcon->SetBits(kCrayonBits, kCrayonWidth*kCrayonHeight, 0, kCrayonColorSpace);
}

TCrayon::~TCrayon()
{
}

void		
TCrayon::DrawCrayon()
{
	fParent->PushState();
	fParent->SetHighColor(fColor);
	fParent->SetLowColor(fParent->ViewColor());
	fParent->FillRect(fFrame);
	if (fIcon) {
		fParent->SetDrawingMode(B_OP_OVER);
		fParent->DrawBitmap(fIcon, fFrame);
	}
	fParent->PopState();
}

rgb_color	
TCrayon::Color() const
{
	return fColor;
}

void
TCrayon::SetColor(rgb_color c)
{
	fColor = c;
}

//

TCrayonColorPicker::TCrayonColorPicker(BPoint pt)
	: BControl(BRect(pt.x, pt.y, pt.x+1, pt.y+1), 
		"crayon collection", "", new BMessage('clch'), B_FOLLOW_NONE, B_WILL_DRAW),
		fCrayonCount(0)
{
	SetViewColor(216, 216, 216, 255);
	fCurrentColor = new TCrayon(this, BRect(2,2, 2+kCrayonWidth-1, 2+kCrayonHeight-1), 
		color(200,100,20));
}

TCrayonColorPicker::~TCrayonColorPicker()
{
}

void
TCrayonColorPicker::Draw(BRect updateRect)
{
	SetHighColor(color(0,0,0));
	SetLowColor(ViewColor());
	StrokeRect(Bounds());
	
	fCurrentColor->DrawCrayon();
	
	for (int32 i=0 ; i<fCrayonCount ; i++) {
		fCrayonList[i]->DrawCrayon();
	}
}

void
TCrayonColorPicker::MouseDown(BPoint loc)
{
	bool hit=false;
	int32 crayonIndex=0;
	for (crayonIndex=0 ; crayonIndex<fCrayonCount ; crayonIndex++) {
		if (fCrayonList[crayonIndex]->Frame().Contains(loc)) {
			hit = true;
			break;
		}
	}
	
	if (hit) {
		fCurrentColor->SetColor(fCrayonList[crayonIndex]->Color());
		fCurrentColor->DrawCrayon();
		Invoke(Message());
	}		
}

void		
TCrayonColorPicker::GetPreferredSize(float* width, float* height) const
{
	*height = kCrayonHeight + 3;
	*width = 4 + kCrayonWidth + 8 + (kCrayonWidth * fCrayonCount);	
}

void		
TCrayonColorPicker::ResizeToPreferred()
{
	float width, height;
	GetPreferredSize(&width, &height);
	ResizeTo(width, height);
}

rgb_color	
TCrayonColorPicker::CurrentColor() const
{
	return fCurrentColor->Color();
}

void
TCrayonColorPicker::SetCurrentColor(rgb_color c)
{
	if (fCurrentColor) {
		fCurrentColor->SetColor(c);
		if (Window())
			Invalidate(fCurrentColor->Frame());
	}
}

void		
TCrayonColorPicker::AddCrayon(rgb_color newColor)
{
	if (fCrayonCount >= kMaxCrayonCount)
		return;
		
	BRect r(2,2,2+kCrayonWidth-1,2+kCrayonHeight-1);
	r.OffsetBy(kCrayonWidth+9, 0);
	if (fCrayonCount>=1) {
		r.OffsetBy((kCrayonWidth*fCrayonCount), 0);
	}
	
	fCrayonList[fCrayonCount] = new TCrayon(this, r, newColor);
	fCrayonCount++;
}
