class SubrectangleQueries {
  private:
  std::vector<std::vector<int>> m;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        m = std::move(rectangle);
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) 
    {
      
        for(int a = row1; a <= row2; a++)

        {

          for(int b = col1; b <= col2;b++)
    
          {

            m[a][b] = newValue;

          }

        }   

    }
    
    int getValue(int row, int col) {
      
      return m[row][col];
      
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
