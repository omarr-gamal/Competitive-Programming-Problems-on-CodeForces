#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;
struct Point{
    double x;
    double y;
};
struct Radiator{
    double x;
    double y;
    double r;
};

int main(){
    struct Point pointa, pointb, pointc;
    struct Radiator radiatorc;
    vector<Point> genlocations;
    vector<Radiator> radiators;

    double tableXa, tableYa, tableXb, tableYb;
    double radNum, genNum = 0, blankets=0;
    double rx, ry, rr;
    double dist = 0;

    cin>>tableXa>>tableYa>>tableXb>>tableYb;
    cin>>radNum;
    for(double i=0; i<radNum; i++){
        cin>>rx>>ry>>rr;
        radiatorc.x=rx;
        radiatorc.y=ry;
        radiatorc.r=rr;
        radiators.push_back(radiatorc);
    }

    pointa.x=tableXa;
    pointa.y=tableYa;
    pointb.x=tableXb;
    pointb.y=tableYb;

    if (pointa.x < pointb.x){
        for(double x=pointa.x; x<=pointb.x; x++){
        pointc.x=x;
        pointc.y=pointa.y;
        genlocations.push_back(pointc);
        //cout<<"1";
        }
        for(double x=pointa.x; x<=pointb.x; x++){
            pointc.x=x;
            pointc.y=pointb.y;
            genlocations.push_back(pointc);
            //cout<<"2";
        }
    }else if (pointa.x > pointb.x){
        for(double x=pointb.x; x<=pointa.x; x++){
        pointc.x=x;
        pointc.y=pointa.y;
        genlocations.push_back(pointc);
        //cout<<"1";
        }
        for(double x=pointb.x; x<=pointa.x; x++){
            pointc.x=x;
            pointc.y=pointb.y;
            genlocations.push_back(pointc);
            //cout<<"2";
        }
    }

    if (pointb.y < pointa.y){
        for(double y=pointb.y+1; y<pointa.y; y++){
        pointc.x=pointa.x;
        pointc.y=y;
        genlocations.push_back(pointc);
        //cout<<"3";
        }

        for(double y=pointb.y+1; y<pointa.y; y++){
            pointc.x=pointb.x;
            pointc.y=y;
            genlocations.push_back(pointc);
            //cout<<"4";
        }
    }else if (pointb.y > pointa.y){
        for(double y=pointa.y+1; y<pointb.y; y++){
        pointc.x=pointa.x;
        pointc.y=y;
        genlocations.push_back(pointc);
        //cout<<"3";
        }

        for(double y=pointa.y+1; y<pointb.y; y++){
            pointc.x=pointb.x;
            pointc.y=y;
            genlocations.push_back(pointc);
            //cout<<"4";
        }

    }


    for(double i=0; i<genlocations.size(); i++){
        for(double j=0; j<radiators.size(); j++){
            dist = sqrt( pow((genlocations[i].x - radiators[j].x),2) + pow( (genlocations[i].y - radiators[j].y) ,2) );
            //cout<<"distance between general: "<<genlocations[i].x<<", "<<genlocations[i].y<<" -- and radiator"<<radiators[j].x<<", "<<radiators[j].y<<" is "<<dist<<endl;
            if (dist <= radiators[j].r)
                goto there;
        }
        blankets++;
        there:;
    }
    cout<<blankets<<endl;

    return 0;
}
