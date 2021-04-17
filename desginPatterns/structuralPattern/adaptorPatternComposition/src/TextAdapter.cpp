#include "TextAdapter.h"

TextAdapter::TextAdapter()
{
  LibraryPointer = std::unique_ptr<TextEditorLibraryAdaptee>(new TextEditorLibraryAdaptee);
}

void TextAdapter::MoveShape(const int&x,const int &y)
{
  LibraryPointer->MoveOrEditText(x,y);
}
