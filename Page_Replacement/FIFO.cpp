#include<iostream>
using namespace std;

int main()
{
    int pages[]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int frames[3]={-1,-1,-1};
    int pageFault=0,nextFrame=0;
    int n = sizeof(pages)/sizeof(pages[0]);

    for(int i=0;i<n;i++)
    {
        bool pageFound=false;

        for(int j=0;j<3;j++)
        {
            if(frames[j] == pages[i])
            {
                pageFound=true;
                cout<<"Page Hit:"<<pages[i]<<endl;
                break;
            }
        }

        if(!pageFound)
        {
            frames[nextFrame]=pages[i];
            nextFrame=(nextFrame+1)%3;
            pageFault++;
            cout<<"Page Fault:"<<pages[i]<<endl;
        }
    }

    cout<<"Total Page Fault = "<<pageFault;
    return 0;
}