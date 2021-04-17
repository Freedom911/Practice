#include "TextAdapter.h"
#include "TextEditorLibraryAdaptee.h"

void TextAdapter::MoveShape(const int&x,const int &y)
{
  TextEditorLibraryAdaptee::MoveOrEditText(x,y);
}
