#pragma once
#include "HashTypeEnum.h"
#include "HashStrategy.h"
#include "StdHash.h"
#include "Djb2Hash.h"
#include <string>

class HashFactory
{
   public:
   virtual HashStrategy *CreateHashFunction(const HashTypeEnum &type)
   {
       if(type == HashTypeEnum::STDHASH)
       {
           return new StdHash();
       }
       else
       {
           return new Djb2Hash();
       }
   }
};
