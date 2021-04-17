//This is the adapter class which adapts according to the new 
//3rd party class and make it usable for shape target
#pragma once
#include "ShapeTarget.h"
#include "TextEditorLibraryAdaptee.h"

class TextAdapter:public ShapeTarget,private TextEditorLibraryAdaptee
{
  public:
  void MoveShape(const int&x,const int &y) override;
};
