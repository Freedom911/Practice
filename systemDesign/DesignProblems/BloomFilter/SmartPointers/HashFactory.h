#pragma once
#include "HashTypeEnum.h"
#include "HashStrategy.h"
#include "StdHash.h"
#include "Djb2Hash.h"
#include <string>
#include <memory>

class HashFactory
{
   public:
   virtual std::unique_ptr<HashStrategy> CreateHashFunction(const HashTypeEnum &type)
   {
       if(type == HashTypeEnum::STDHASH)
       {
           return std::make_unique<StdHash>();
       }
       else
       {
           return std::make_unique<Djb2Hash>();
       }
   }
};
