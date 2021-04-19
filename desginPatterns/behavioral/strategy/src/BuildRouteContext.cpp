#include "BuildRouteContext.h"
#include "RoutingAlgoStrategy.h"

BuildRouteContext::BuildRouteContext(RoutingAlgoStrategy *ptr)
{
 m_ptr = ptr;
}

BuildRouteContext::~BuildRouteContext()
{
  delete m_ptr;
}

void BuildRouteContext::BuildRoute()
{
  m_ptr->BuildMinimumRoute();
}
