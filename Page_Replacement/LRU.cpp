#include<iostream>
using namespace std;

int main()
{
    int pages[]={};
    int n = sizeof(pages)/sizeof(pages[0]);
    int pageFault=0;
    int frameSize=3;
    int frames[frameSize]={-1,-1,-1};

    for(int i=0;i<n;i++)
    {
        bool pageFound=false;
        for(int j=0;j<frameSize;j++)
        {
            if(frames[j]==pages[i])
            {
                pageFound=true;
                cout<<"Page Hit:"<<pages[i]<<endl;
                break;
            }
        }


        if(!pageFault)
        {
            int index=0;
            for(int j=0;j<frameSize;j++)
            {
                if(frames[j]==-1 || frames[j]==pages[i])
                {
                    index=j;
                    break;
                }
            }

            frames[index]=pages[i];
            pageFault++;
            cout<<"Page fault:"<<pages[i]<<endl;
        }
    }

    cout<<"Total Page Fault:"<<pageFault;
    return 0;
}