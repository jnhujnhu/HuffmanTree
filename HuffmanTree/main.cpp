//
//  main.cpp
//  HuffmanTree
//
//  Created by 周凯文 on 11/16/14.
//  Copyright (c) 2014 周凯文. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *lch,*rch;
    Node():lch(NULL),rch(NULL) {}
};

void preod(Node *root)
{
    if(root)
    {
        cout<<root->data<<' ';
        preod(root->lch);
        preod(root->rch);
    }
}

int main(int argc, const char * argv[]) {
    int b[]={5,6,3,7,4};
    int num=5;
    Node *a[5];
    bool f[5]={0};
    for(int i=0;i<5;i++)
    {
        Node *p=new Node;
        p->data=b[i];
        a[i]=p;
    }
    Node *root=NULL;
    while(num>1){
        int minl=99999,u=-1,minl2=99999,u2=-1;
        for(int i=0;i<5;i++)
        {
            if(a[i]->data<minl&&!f[i])
            {
                minl=a[i]->data;
                u=i;
            }
        }
        for(int i=0;i<5;i++)
        {
            if(a[i]->data<minl2&&i!=u&&!f[i])
            {
                minl2=a[i]->data;
                u2=i;
            }
        }
        int tt=minl+minl2;
        if(u2!=-1)
        {
            f[u2]=1;
            Node *c=new Node;
            c->data=tt;
            c->lch=a[u];
            c->rch=a[u2];
            a[u]=c;
            
        }
        num--;
        if(num==1) root=a[u];
    }
    preod(root);
    cout<<endl;
    return 0;
    
}
