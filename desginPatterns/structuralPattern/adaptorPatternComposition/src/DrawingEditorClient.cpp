#include "DrawingEditorClient.h"
#include "ShapeTarget.h"
#include "LineShape.h"
#include "TextAdapter.h"

void DrawingEditorClient::StartEditingLine()
{
  ShapeTarget * s = new LineShape();
  s->MoveShape(100,200);
  delete s;
}
void DrawingEditorClient::StartEditingText()
{
  ShapeTarget * s = new TextAdapter();
  s->MoveShape(100,200);
  delete s;

}
