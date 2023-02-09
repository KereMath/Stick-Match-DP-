#include "the3.h"



int recursive_sln(int i, char**& arr, int*& len, int &number_of_calls) { //direct recursive
    number_of_calls+=1;
    int temp=0;
    int max=0;
    int curSize=len[i];
    if(i==0){return len[0];}
    if(number_of_calls==1){
        
        for(int a=i-1;a>=0;a--){
            temp=recursive_sln(a,arr,len,number_of_calls);
            if(temp>max){max=temp;}
        }
        for(int b=i-1;b>=0;b--){
            if(arr[i][0]=='S' && arr[b][1]=='S'){
                temp=curSize+recursive_sln(b,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else if(arr[i][0]=='I' && arr[b][1]=='O'){
                temp=curSize+recursive_sln(b,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else if(arr[i][0]=='O' && arr[b][1]=='I'){
                temp=curSize+recursive_sln(b,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else{continue;}

        }
    }
    else{
        for(int a=i-1;a>=0;a--){
            if(arr[i][1]=='S' && arr[a][1]=='S'){
                temp=recursive_sln(a,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else if(arr[i][1]=='O' && arr[a][1]=='O'){
                temp=recursive_sln(a,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else if(arr[i][1]=='I' && arr[a][1]=='I'){
                temp=recursive_sln(a,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else
             continue;
        }
        for(int b=i-1;b>=0;b--){
            if(arr[i][0]=='S' && arr[b][1]=='S'){
                temp=curSize+recursive_sln(b,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else if(arr[i][0]=='I' && arr[b][1]=='O'){
                temp=curSize+recursive_sln(b,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else if(arr[i][0]=='O' && arr[b][1]=='I'){
                temp=curSize+recursive_sln(b,arr,len,number_of_calls);
                if(temp>max){max=temp;}
                break;
            }
            else{continue;}
        }
        
        
        
        
    }
    
    
    if(len[i]>max){
        max=len[i];
    }
    
    return max; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}



int memoization_sln(int i, char**& arr, int*& len, int**& mem) { //memoization
    int size=i+1;
    
    if(i==-1){return 0;}
    int max=memoization_sln(i-1,arr,len,mem);
    if(i==0){
        mem[i][0]=0;
        mem[i][1]=0;
        mem[i][2]=0;
        char c=arr[0][1];
    char c1,c2;
    if(c=='S'){mem[0][2]=len[0];mem[0][1]=0;mem[0][0]=0;}
    else if(c=='I'){mem[0][0]=len[0];mem[0][1]=0;mem[0][2]=0;}
    else{mem[0][1]=len[0];mem[0][2]=0;mem[0][0]=0;}
    }
    
    int j;
    char c=arr[0][1];
    char c1,c2;
    if(c=='S'){mem[0][2]=len[0];mem[0][1]=0;mem[0][0]=0;}
    else if(c=='I'){mem[0][0]=len[0];mem[0][1]=0;mem[0][2]=0;}
    else{mem[0][1]=len[0];mem[0][2]=0;mem[0][0]=0;}
    for(j=1;j<size;j++){
        c1=arr[j][0];
        c2=arr[j][1];
        if(c1=='S'){
            if(c2=='S'){
                mem[j][2]=len[j]+mem[j-1][2];
                mem[j][0]=mem[j-1][0];
                mem[j][1]=mem[j-1][1];
            }
            else if(c2=='O'){
                if(mem[j-1][1]<=mem[j-1][2]+len[j]){mem[j][1]=mem[j-1][2]+len[j];}
                else{mem[j][1]=mem[j-1][1];}
                mem[j][2]=mem[j-1][2];
                mem[j][0]=mem[j-1][0];
                
            }
            else{
                if(mem[j-1][0]<=mem[j-1][2]+len[j]){mem[j][0]=mem[j-1][2]+len[j];}
                else{mem[j][0]=mem[j-1][0];}
                mem[j][2]=mem[j-1][2];
                mem[j][1]=mem[j-1][1];
            }
        }
        else if(c1=='O'){
            if(c2=='O'){
                if(mem[j-1][1]<=mem[j-1][0]+len[j]){mem[j][1]=mem[j-1][0]+len[j];}
                else{mem[j][1]=mem[j-1][1];}
                mem[j][0]=mem[j-1][0];
                mem[j][2]=mem[j-1][2];
            }
            else if(c2=='S'){
                if(mem[j-1][2]<=mem[j-1][0]+len[j]){mem[j][2]=mem[j-1][0]+len[j];}
                else{mem[j][2]=mem[j-1][2];}
                mem[j][1]=mem[j-1][1];
                mem[j][0]=mem[j-1][0];
                
            }
            else{
                if(mem[j-1][0]<=mem[j-1][0]+len[j]){mem[j][0]=mem[j-1][0]+len[j];}
                else{mem[j][0]=mem[j-1][0];}
                mem[j][1]=mem[j-1][1];
                mem[j][2]=mem[j-1][2];
            }
        }
        else{
            if(c2=='I'){
                if(mem[j-1][0]<=mem[j-1][1]+len[j]){mem[j][0]=mem[j-1][1]+len[j];}
                else{mem[j][0]=mem[j-1][0];}
                mem[j][1]=mem[j-1][1];
                mem[j][2]=mem[j-1][2];
            }
            else if(c2=='S'){
                if(mem[j-1][2]<=mem[j-1][1]+len[j]){mem[j][2]=mem[j-1][1]+len[j];}
                else{mem[j][2]=mem[j-1][2];}
                mem[j][1]=mem[j-1][1];
                mem[j][0]=mem[j-1][0];
                
            }
            else{
                if(mem[j-1][1]<=mem[j-1][1]+len[j]){mem[j][1]=mem[j-1][1]+len[j];}
                else{mem[j][1]=mem[j-1][1];}
                mem[j][0]=mem[j-1][0];
                mem[j][2]=mem[j-1][2];
            }
        }
        
        
    }
    max=mem[size-1][0];
    if (mem[size-1][1]>max){
        max=mem[size-1][1];
    }
    if (mem[size-1][2]>max){
        max=mem[size-1][2];
    }
    
    
    
    return max;
}



int dp_sln(int size, char**& arr, int*& len, int**& mem) { //dynamic programming
    int i;
    char c=arr[0][1];
    char c1,c2;
    if(c=='S'){mem[0][2]=len[0];mem[0][1]=0;mem[0][0]=0;}
    else if(c=='I'){mem[0][0]=len[0];mem[0][1]=0;mem[0][2]=0;}
    else{mem[0][1]=len[0];mem[0][2]=0;mem[0][0]=0;}
    for(i=1;i<size;i++){
        c1=arr[i][0];
        c2=arr[i][1];
        if(c1=='S'){
            if(c2=='S'){
                mem[i][2]=len[i]+mem[i-1][2];
                mem[i][0]=mem[i-1][0];
                mem[i][1]=mem[i-1][1];
            }
            else if(c2=='O'){
                if(mem[i-1][1]<=mem[i-1][2]+len[i]){mem[i][1]=mem[i-1][2]+len[i];}
                else{mem[i][1]=mem[i-1][1];}
                mem[i][2]=mem[i-1][2];
                mem[i][0]=mem[i-1][0];
                
            }
            else{
                if(mem[i-1][0]<=mem[i-1][2]+len[i]){mem[i][0]=mem[i-1][2]+len[i];}
                else{mem[i][0]=mem[i-1][0];}
                mem[i][2]=mem[i-1][2];
                mem[i][1]=mem[i-1][1];
            }
        }
        else if(c1=='O'){
            if(c2=='O'){
                if(mem[i-1][1]<=mem[i-1][0]+len[i]){mem[i][1]=mem[i-1][0]+len[i];}
                else{mem[i][1]=mem[i-1][1];}
                mem[i][0]=mem[i-1][0];
                mem[i][2]=mem[i-1][2];
            }
            else if(c2=='S'){
                if(mem[i-1][2]<=mem[i-1][0]+len[i]){mem[i][2]=mem[i-1][0]+len[i];}
                else{mem[i][2]=mem[i-1][2];}
                mem[i][1]=mem[i-1][1];
                mem[i][0]=mem[i-1][0];
                
            }
            else{
                if(mem[i-1][0]<=mem[i-1][0]+len[i]){mem[i][0]=mem[i-1][0]+len[i];}
                else{mem[i][0]=mem[i-1][0];}
                mem[i][1]=mem[i-1][1];
                mem[i][2]=mem[i-1][2];
            }
        }
        else{
            if(c2=='I'){
                if(mem[i-1][0]<=mem[i-1][1]+len[i]){mem[i][0]=mem[i-1][1]+len[i];}
                else{mem[i][0]=mem[i-1][0];}
                mem[i][1]=mem[i-1][1];
                mem[i][2]=mem[i-1][2];
            }
            else if(c2=='S'){
                if(mem[i-1][2]<=mem[i-1][1]+len[i]){mem[i][2]=mem[i-1][1]+len[i];}
                else{mem[i][2]=mem[i-1][2];}
                mem[i][1]=mem[i-1][1];
                mem[i][0]=mem[i-1][0];
                
            }
            else{
                if(mem[i-1][1]<=mem[i-1][1]+len[i]){mem[i][1]=mem[i-1][1]+len[i];}
                else{mem[i][1]=mem[i-1][1];}
                mem[i][0]=mem[i-1][0];
                mem[i][2]=mem[i-1][2];
            }
        }
        
        
    }
    int max=mem[size-1][0];
    if (mem[size-1][1]>max){
        max=mem[size-1][1];
    }
    if (mem[size-1][2]>max){
        max=mem[size-1][2];
    }
    
    
    
    return max;
}

