#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

int main()
{
    int w;
    int h=0;
    FILE *plik; 
    int n;
    int matrixS[100][100];
    int matrix[10000];
    plik=fopen("graf.txt","r");
    if(plik==NULL)
        cout<<"Open error"<<endl;
    else
    {
        for(int i=0;i<1000;i++)
             {
               w=fscanf(plik,"%i",&matrix[i]);
               h++;
               if(w==EOF) 
               break;
             }
    }
    fclose(plik);
    cout<<endl;
  
    n=sqrt(h-1);


    int l=0;
    for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
           {
               matrixS[i][j]=matrix[l];
               l++;
           }
    

    int Inf=numeric_limits<int>::max()/2;
    int Pv[100];
    int Dv[100];
    Dv[0]=0;
    for(int k=1;k<n;k++)
    {
        Dv[k]=Inf;
    }

    for(int g=0;g<n-1;g++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(matrixS[i][j]!=0)
                {
                    if(Dv[i]+matrixS[i][j]<Dv[j])
                    {
                        Dv[j]=Dv[i]+matrixS[i][j];
                        Pv[j]=i;
                    }
                }
            }
    cout<<"Pv: ";   
    for(int p=1;p<n;p++)
    {
        cout<<Pv[p]<<" ";
    }
    cout<<endl;
    cout<<"Dv: ";
    for(int p=0;p<n;p++)
    {
        cout<<Dv[p]<<" ";
    }
}