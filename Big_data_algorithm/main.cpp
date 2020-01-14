//
//  main.cpp
//  Big_data_algorithm
//
//  Created by vancasola on 2020/1/14.
//  Copyright © 2020 none. All rights reserved.
// 

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;
int main(){
    time_t ti;
    double epsilon=0.1,delta=0.25,tmp,sum=0;
    
    double t=1/(delta*epsilon*epsilon),m,n=100000;
    for(int i=0;i<t;i++){
        srand((unsigned)time(&ti)+i);
        m=1.0;
        for(int j=0;j<n;j++){
            tmp=rand()/(RAND_MAX+1.0);
            if(tmp<m)m=tmp;
        }
        sum+=m;
    }
    m=sum/t;
    printf("epsilon:%.3lf delta:%.3lf\n",epsilon,delta);
    printf("t==%lf\n",t);
    printf("ground:%.1lf estimate:%.1lf\n",n,1.0/m+1);
    printf("error:%.2lf%%",fabs((n-(1.0/m+1))/n)*100);
    return 0;
}
