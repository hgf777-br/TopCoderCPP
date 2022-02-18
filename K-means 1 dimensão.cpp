#include<stdio.h>
#include<iostream>
#include<math.h>
#include<conio.h>
#include<process.h>
#include<time.h>

using namespace std;

void dis();// measure the distance
void neigh();
double result[100][200],output[100][100];
double input[]={6,5.9,5.6,5.5,5.9,5.6,5,5.9,6,6.4,5.2,6.1,5.8,5.8,4,2.8,3.2,4.1,1.2,2.7,6.1,2.7,2.8,8.2,5.3,5,6,2.7, 2.8,8.2,5.3,8.2,6,2.7,2.8,8.2,5.3,2.7,2.4,2.7,2.8,8.2,5.3,6,4,2.7,2.8,8.2,5.3,0.2,6,2.7,2.8,8.2,5.3,8.2, 10,2.7,2.8,8.2,5.3,2.7,12,2.7,2.8,8.2,5.3,6,14,2.7,2.8,8.2,5.3,0.2,16,2.7,2.8,8.2,5.3,0.2,8.2,'\0'};
double c1,c2,c3;
double r1[3][100],r2[3][100],r3[10][50];
double ex1[100],ex2[100],ex3[100];
void distance(); // perform the distnace measure operatrion
void part();
int it=0, nb=80,nc=3;
double t1=0.0;
int main()
{
clock_t st,en;
c1=2.7;c2=5;c3=6.0;
st=clock();
distance();
en=clock();
t1=(double)(en-st)/(double)1000;
cout<<"\n THE TIME COMPLEXITY OF ENTIRE PROCESS:"<<t1;
getch();
}
// measure the distance of set of object to centroid cluuster
void distance()
{
int i,j;
// measuring the distnace of set of objects in to set of centroid clusters
for(i=0;i<80;i++)
{
ex1[i]=(sqrt(pow((c1-input[i]),2)));
ex2[i]=(sqrt(pow((c2-input[i]),2)));
ex3[i]=(sqrt(pow((c3-input[i]),2)));
}
cout<<"\n DISTANCE MEASURED FOR SET OF OBJECT TO THREE CENTROID CLUSTERS\n--------------------------------------------\n";
cout<<"\n INPUT-OBJECTS\t\tC1-"<<c1<<"\t\t C2-"<<c2<<"\t\t C3-"<<c3<<"\n";
// displaying status of the distance measures
for(i=0;i<80;i++)
{
cout<<input[i]<<"\t\t\t"<<ex1[i]<<"\t\t"<<ex2[i]<<"\t\t"<<ex3[i]<<"\n";
}
//getch();
part(); //
}
// partition the set of objects into three centroid clusters
void part()
{
int i,j,k, i1,i2,i3,i4;
double sum1=0,sum2=0,sum3=0;
i2=0;i3=0;i4=0;
if(it==0)
{
for(i1=0;i1<80;i1++) // matching minimu similarity of each object in to centroid clusters
{
if((ex1[i1]<ex2[i1])&&(ex1[i1]<ex3[i1]))
{
r1[0][i2]=input[i1];
//cout<<r1[0][i2]<<"\n";
i2=i2+1;
}
else if((ex2[i1]<ex1[i1]) && (ex2[i1]<ex3[i1]))
{
r1[1][i3]=input[i1];
//cout<<r1[1][i3]<<"\n";
i3=i3+1;
}
else if((ex3[i1]<ex1[i1]) && (ex3[i1]<ex2[i1]))
{
r1[2][i4]=input[i1];
//cout<<r1[2][i4]<<"\n";
i4=i4+1;
}
}
cout<<"\n RESULT OF ITERATION:"<<it<<"\n-----------------------\n";
cout<<"CENTROID:1\n---------------\n";
for(i=0;i<i2;i++)
{
cout<<r1[0][i]<<"\n";
sum1=sum1+r1[0][i];
}
c1=(sum1/(i2)); // updating centroid c1
//getch();
cout<<"CENTROID:2\n---------------\n";
for(j=0;j<i3;j++)
{
cout<<r1[1][j]<<"\n";
sum2=sum2+r1[1][j]; //updating centroid c2
}
c2=(sum2/(i3));
//getch();
cout<<"CENTROID:3\n---------------\n";
for(k=0;k<i4;k++)
{
cout<<r1[2][k]<<"\n";
sum3=sum3+r1[2][k];
}
c3=(sum3/(i4)); //updating centroid c3
//getch();
it=it+1;
distance();
} // end of iteration1 it=0
// iteration2 partitioning the set of objects into three centroid clusters
else if(it==1)
{
for(i1=0;i1<80;i1++) // matching minimu similarity of each object in to centroid clusters
{
if((ex1[i1]<ex2[i1])&&(ex1[i1]<ex3[i1]))
{
r2[0][i2]=input[i1];
//cout<<r1[0][i2]<<"\n";
i2=i2+1;
}
else if((ex2[i1]<ex1[i1]) && (ex2[i1]<ex3[i1]))
{
r2[1][i3]=input[i1];
//cout<<r1[1][i3]<<"\n";
i3=i3+1;
}
else if((ex3[i1]<ex1[i1]) && (ex3[i1]<ex2[i1]))
{
r2[2][i4]=input[i1];
//cout<<r1[2][i4]<<"\n";
i4=i4+1;
}
}
cout<<"\n RESULT OF ITERATION:"<<it<<"\n-----------------------\n";
cout<<"CENTROID:1\n---------------\n";
for(i=0;i<i2;i++)
{
cout<<r2[0][i]<<"\n";
}
//getch();
cout<<"CENTROID:2\n---------------\n";
for(j=0;j<i3;j++)
{
cout<<r2[1][j]<<"\n";
}
//getch();
cout<<"CENTROID:3\n---------------\n";
for(k=0;k<i4;k++)
{
cout<<r2[2][k]<<"\n";
}
//getch();
} // end of the iteration2 it=1
// compare the previous and present partition result
cout<<"\n FINAL RESULT STATUS:\n------------------\n";
cout<<"CENTROID :1\n---------------\n PREVIOUS(C1)\t\tPRESENT(C1)\n";
j=0;
for(i=0;i<i2;i++)
{
if(r1[0][i]==r2[0][i])
{
cout<<r1[0][i]<<"\t\t\t"<<r2[0][i]<<"\n";
j=j+1;
}
}
if(j==i2)
{
cout<<"\n THE PREVIOUS C1 IS EQUAL TO PRESENT C1:";
}
cout<<"\nCENTROID :2\n---------------\n PREVIOUS(C2)\t\tPRESENT(C2)\n";
k=0;
for(i=0;i<i3;i++)
{
//if(r1[1][i]==r2[1][i])
// {
cout<<r1[1][i]<<"\t\t\t"<<r2[1][i]<<"\n";
k=k+1;
//}
}
if(k==i3)
{
cout<<"\n THE PREVIOUS C2 IS EQUAL TO PRESENT C2:";
}
cout<<"\nCENTROID :3\n---------------\n PREVIOUS(C3)\t\tPRESENT(C3)\n";
j=0;
for(i=0;i<i4;i++)
{
//if(r1[2][i]==r2[2][i])
// {
cout<<r1[2][i]<<"\t\t\t"<<r2[2][i]<<"\n";
j=j+1;
//}
}
if(j==i4)
{
cout<<"\n THE PREVIOUS C3 IS EQUAL TO PRESENT C3:";
}
// getch();
//Note: I am not sure this code could run in NS3
//Thanks & Regards
//Sreedhar Kumar Seetharaman
} // end of partition operation
