//Flood fill a pixel means recursively replace a pixel and 4 directions with new color
//Input would be a 2d grid ,source row and column from which we can derive the color that needs
//to be replaced and we wold be given a new color which we will replace in the grid
//So we can use BFS/DFS and we start with the source row and column and keep updating the pixel

#include <iostream>
#include <vector>
#include <queue>


void BFS(int sr,int sc,int origColor,int newColor,std::vector<std::vector<int>> &pixelMap)
{
    std::queue<std::pair<int,int>>q;
    q.push({sr,sc});
    pixelMap[sr][sc] = newColor;
    int tr = pixelMap.size();
    int tc = pixelMap[0].size();

    while(q.empty() == false)
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        int deltaRow[4]= {-1,0,1,0};
        int deltaCol[4]= {0,1,0,-1};
        pixelMap[row][col] = newColor;


        for(int i = 0; i < 4; i++)
        {
            int actRow = row + deltaRow[i];
            int actCol = col + deltaCol[i];

            //validityCheck 
            //the last condition act as visited
            if(actRow >= 0 && actCol >=0 && actRow < tr && actCol < tc  && 
                    pixelMap[actRow][actCol] == origColor && pixelMap[actRow][actCol] != newColor)
            {
                q.push({actRow,actCol});
            }

        }
    }
}

void DFS(int sr,int sc,int origColor,int newColor,std::vector<std::vector<int>> &pixelMap)
{ 
   pixelMap[sr][sc] = newColor;
   
   //adjacent list will be all 4 directions
   //                          (0,1)
   //                            |
   //                (-1,0) -- (0,0) -- (1,0)
   //                            |
   //                          (0,-1)
   int tr = pixelMap.size();
   int tc = pixelMap[0].size();
   int deltaRow[4]= {-1,0,1,0};
   int deltaCol[4]= {0,1,0,-1};
   for(int i = 0; i < 4; i++)
   {
       int actRow = sr + deltaRow[i];
       int actCol = sc + deltaCol[i];

       //validityCheck 
       //the last condition act as visited
       if(actRow >= 0 && actCol >=0 && actRow < tr && actCol < tc  && 
          pixelMap[actRow][actCol] == origColor && pixelMap[actRow][actCol] != newColor)
       {
         DFS(actRow,actCol,origColor,newColor,pixelMap);
       }
   }

}


std::vector<std::vector<int>> FloodFill(const std::vector<std::vector<int>> &pixelMap,
                                        const int &sr,const int &sc,const int &newColor)
{
    int tr = pixelMap.size();
    int tc = pixelMap[0].size();

    if(tr == 0 || tc == 0 || sr >= tr || sc >= tc)
    {
        return{};
    }

    int origColor = pixelMap[sr][sc];
    std::vector<std::vector<int>> pixelMapCopy = pixelMap;


    //dpont require explicit visited aray as we can check with pixel map whether it has already been replaced
    //DFS(sr,sc,origColor,newColor,pixelMapCopy);
    BFS(sr,sc,origColor,newColor,pixelMapCopy);
    return pixelMapCopy;

}

int main()
{
    std::vector<std::vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};

    std::vector<std::vector<int>> ans = FloodFill(image, 1, 1, 2);
	for(auto i: ans)
    {
        for(auto j: i)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}
