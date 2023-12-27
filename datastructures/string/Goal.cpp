	class Solution {
	public:
		string interpret(string command) {
			
			size_t i = 0;
			size_t j = 0;
			size_t len = command.length();
			while(i < len)
			{
			  if(command[i] == 'G')
			  {
				command[j] = 'G';
				j++;
			  }
			  else if(command[i] == '(' && command[i+1] == ')')
			  {
				 command[j] = 'o';
				j++;
			  }
			  else if(command[i] == '(' && command[i+1] == 'a')
			  {
				command[j] = 'a';
				command[j+1] = 'l';
				j+=2;
			  }
			  i++;
			}
			command.erase(j,len);
			return command;
			
		}
	};