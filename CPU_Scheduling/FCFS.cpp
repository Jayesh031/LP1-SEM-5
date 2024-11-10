#include<iostream>
using namespace std;

int main()
{
    int n,avg_wt=0,avg_tat=0;

    cout<<"Enter Number of Process:"<<endl;
    cin>>n;

    int wt[n],bt[n],tat[n];

    cout<<"Enter Burst Time For all Process:"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Burst Time for Process"<<i+1<<" = ";
        cin>>bt[i];
    }

    wt[0]=0; //waiting time of first process is 0

    // calculating waiting time
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }

    // calculating total turn around time
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }

    // printing all information
    cout<<"Process  Burst Time  Waiting Time  Turn Around Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
        avg_tat=avg_tat+tat[i];
        avg_wt=avg_wt+wt[i];
    }

    cout<<endl;
    cout<<"Average Waiting Time:"<<avg_wt/n<<endl;
    cout<<"Average Turn Around Time:"<<avg_tat/n<<endl;

    return 0;

}