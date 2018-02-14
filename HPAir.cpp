 #include<iostream>
 #include<fstream>
 #include<string>
 #include<sstream>
 using namespace std;
 int check_path(int,int,int);
 int path[20][20]={{0}};
 int main()
 {
     int nodes=0,i,j,sourse,dest,s,d;
     string city[20];

     //city_names.txt file contain the names of cities that HP Airlines serves.
    ifstream inFile("city_names.txt");
    if (inFile.is_open())
    {
        string word;
        while (getline(inFile,word))
        {
            //creating array called city which stores all cities in text file.
            city[nodes++]=word;

        }
    }
    else
    {
        cout << "Can't open file." << endl;
    }

    //city_graph.txt contain two cities in each line which have direct path connection.
    ifstream gFile("city_graph.txt");
    if (gFile.is_open())
    {
        string word,word1,word2,str,split[3];
        while (getline(gFile,word))
        {

            int k=0;
            istringstream iss(word);
           while(iss >> str)
           {
               //Two cities saved in an array.
              split[k]=str;

                k++;
           }
           word1=split[0];  //word1 is origin city.
           word2=split[1];  //word2 is destination city.
            for(i=0;i<nodes;i++)
            {
                if(word1==city[i])
                {
                    for(j=0;j<nodes;j++)
                    {
                        if(word2==city[j])
                        {
                            //path array indicates 2D graph array.
                            //If path exist the place value become 1.
                            path[i][j]=1;
                            break;
                        }

                    }
                    break;
                }
            }
            split[0]=" ";split[1]=" ";

        }
        //commented code prints 2D array that represents graph.
        for(i=0;i<nodes;i++)
        {
            for(j=0;j<nodes;j++)
            {
                cout<<path[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    else
    {
        cout << "Can't open file." << endl;
    }


    //city_request.txt file contain request to fly some origin to destination.
    ifstream rFile("city_request.txt");
    if (rFile.is_open())
    {
        string word,word1,word2,str,split[3];
        while (getline(rFile,word))
        {
            //cout << word << endl;  //requested city names line
            int k=0;
            istringstream iss(word);
           while(iss >> str)
           {
                split[k]=str;
                k++;
           }
           word1=split[0];
           word2=split[1];
           for(i=0;i<nodes;i++)
           {
               if(word1==city[i])
               {
                   //source indicates with index value of origin city that city array contains.
                   sourse=i;
                   s=1;
               }
               if(word2==city[i])
               {
                   //dest indicates with index value of destination city that city array contains.
                   dest=i;
                   d=1;
               }
           }
           if(s==1 && d==1)  //if city array contains both origin city and destination city.
           {
              // cout<<sourse<<dest<<endl;

              //The check_path() function check the possibility to fly from source to destination.
                int c=check_path(sourse,dest,nodes);
                if(c==1)
                {
                    cout<<"Request is to fly from "<<city[sourse]<<" to "<<city[dest]<<"."<<endl;
                    cout<<"HP Air flies from "<<city[sourse]<<" to "<<city[dest]<<"."<<endl<<endl;
                }
                if(c==-1)
                {
                    cout<<"Request is to fly from "<<city[sourse]<<" to "<<city[dest]<<"."<<endl;
                    cout<<"Sorry. HP Air does not fly from "<<city[sourse]<<" to "<<city[dest]<<"."<<endl<<endl;

                }
           }
           else
            {
                cout<<"Request is to fly from "<<city[sourse]<<" to "<<city[dest]<<"."<<endl;
                    cout<<"Sorry. HP Air does not fly from "<<city[sourse]<<" to "<<city[dest]<<"."<<endl<<endl;

            }
           s=0;d=0;
        }
    }
    else
    {
        cout << "Can't open file." << endl;
    }
 }
 int check_path(int v,int dest,int nodes)
 {
     int visit[20]={0},k,stk[20]={0},top,j,flag=1;
     int visited[20]={0};

     //visited of origin makes 1.
     visited[v]=1;
    k=1;
    while(k<nodes)
    {
        for(j=nodes-1;j>=0;j--)
        if(path[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
        {
            visit[j]=1;
            stk[top]=j;
            top++;
        }
        v=stk[--top];
        cout<<"";
        if(v==dest)
        {
            flag=0;
            break;
        }
        k++;
        visit[v]=0; visited[v]=1;
    }
    if(flag==0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
 }
