
#include <iostream>
#include "TextEditorLibraryAdaptee.h"

TextEditorLibraryAdaptee::TextEditorLibraryAdaptee()
{
  std::cout << "\n Using Library Version For Text \n";
}

void TextEditorLibraryAdaptee::CreateText()
{
  std::cout << "\n Creating A Text Shape \n";
}


void TextEditorLibraryAdaptee::MoveOrEditText(const int &x,const int &y)
{
  std::cout << "\n Moving Text At " << x << "," << y << "\n";
}

