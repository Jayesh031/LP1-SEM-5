#include<iostream>
using namespace std;

int main()
{
    int n,avg_wt=0,avg_tat=0;
    cout<<"Enter Number of Process:";
    cin>>n;

    int bt[n],wt[n],tat[n],time,rem[n];

    cout<<"Enter Burst Time:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Burst Time for Process"<<i+1<<" :";
        cin>>bt[i];
        rem[i]=bt[i];
    }

    cout<<"Enter Time Interval:";
    cin>>time;

    int t=0;
    while(true)
    {
        bool done=true;
        for(int i=0;i<n;i++)
        {
            if(rem[i]>0)
            {
                done=false;
                if(rem[i]>time)
                {
                    t=t+time;
                    rem[i]=rem[i]-time;
                }
                else
                {
                    t=t+rem[i];
                    wt[i]=t-bt[i];
                    rem[i]=0;
                }
            }
        }

        if(done)
            break;
    }

    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }

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