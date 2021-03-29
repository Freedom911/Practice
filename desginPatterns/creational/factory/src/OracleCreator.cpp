#include "OracleCreator.h"
#include "OracleDBConcreteProduct.h"

DBInterfaceProduct *OracleCreator::getProduct()
{
  return new OracleDBConcreteProduct();
}
