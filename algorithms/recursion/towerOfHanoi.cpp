//Program For Brahmaji ka Tower of Hanoi
#include <iostream>

//Hypothesis
void moveChakra(int totalChakras,int sourcePillar,int destinationPillar,int helperPillar)
{
  //Base Conditon
  if(totalChakras == 1)
  {
    std::cout << "\n Moving Chakara " << totalChakras << " to " << destinationPillar << "\n";
    return;
  }

  //Induction
  //Move chakra from source to helper pillar using helper as destination. Cant use
  //use destination direct as this will violatate brahma ji condition of having bigger chakra below
  //than smaller chakra
  moveChakra(totalChakras - 1,sourcePillar,helperPillar,destinationPillar);
  std::cout << "\n Moving " << totalChakras << " Chakra to " << destinationPillar << "\n";
  //Now Move remaining n- 1 chakra to destination
  moveChakra(totalChakras - 1,helperPillar,destinationPillar,sourcePillar);

}

int main()
{
  moveChakra(3,1,3,2);
}
