#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Table{

private:
  map<int,int> table;
  int find(int elm)
  {
    
    for (const auto& [key, value] :table) 
    {
      if(value==elm)
      {
        return key;
      }
    }   
    return 0  ;

  }
  void Replace(int i, int j)
  {
    int temp=table.at(i);
    swap(table.at(i),table.at(j));
  }
public:
  Table( int arr[] )
  {
    for(int i=0;i<9;i++)
    {
        table.insert({i+1,arr[i]});
    }
  }

 void test()
  {
      for (const auto& [key, value] :table) {
        std::cout << key << " has value " << value << std::endl;
      }   
  }
  int moveRight()
  {
    int location=find(0);
    
    if(location==3||location==6||location==9||location==0)
      // cant move it
      return 0;

      Replace(location,location+1);
      return 1;
  }

  int moveLeft()
  {
    int location=find(0);
    
    if(location==1||location==4||location==7||location==0)
      // cant move it
      return 0;

      Replace(location,location-1);
      return 1;
  }

  int moveUp()
  {
    int location=find(0);
    
    if(location==1||location==2||location==3||location==0)
      // cant move it
      return 0;

      Replace(location,location-3);
      return 1;
  }
  int moveDown()
  {
    int location=find(0);
    
    if(location==7||location==8||location==9||location==0)
      // cant move it
      return 0;

      Replace(location,location+3);
      return 1;
  }
  int HFunction( Table t2 )
  {
    int ocur=0;
    vector<int> list;
      for (int i=1;i<=9;i++) 
      {
        if(this->table[i]!=t2.table[i])
          {
              int cnt = count(list.begin(), list.end(), table[i]);
              int cnt2 = count(list.begin(), list.end(), t2.table[i]);
              if(cnt>>0||cnt2>>0)
              {
                  cout<<ocur<<endl;
                  continue;
              }
              list.push_back(table[i]);
              list.push_back(t2.table[i]);
              ocur+=1;
          }
      }
    cout<<ocur<<endl;
    return  ocur;

  }
};


int main()

{
  int arr[]={2,3,4,5,0,6,7,8,9 };
  int arr2[]={2,4,3,5,0,6,7,9,8 };
  Table t(arr);
  Table t2(arr2);
  cout<< t.HFunction(t2)<<endl;
}
