#include "PSQLCreator.h"
#include "PSQLDBConcreteProduct.h"

DBInterfaceProduct *PSQLCreator::getProduct()
{
  return new PSQLDBConcreteProduct();
}
