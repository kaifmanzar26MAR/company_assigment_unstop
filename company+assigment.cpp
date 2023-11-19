#include<bits/stdc++.h>
using namespace std;
int main(){
    //number of avilable seats
    int avl=80;
    //vector of vector for representing the seats number 
    vector<vector<int>> seats={{1,2,3,4,5,6,7},
                               {8,9,10,11,12,13,14},
                               {15,16,17,18,19,20,21},
                               {22,23,24,25,26,27,28},
                               {29,30,31,32,33,34,35},
                               {36,37,38,39,40,41,42},
                               {43,44,45,46,47,48,49},
                               {50,51,52,53,54,55,56},
                               {57,58,59,60,61,62,63},
                               {64,65,66,67,68,69,70},
                               {71,72,73,74,75,76,77},
                               {78,79,80}};
    int row=0;
    int col=0;
    //loop will apply until the seats are avilable
    while(avl!=0){ 
        //defining vector for storing the seats number we booked
        vector<int> seat_num;
        
        //printing the avilable seats
        cout<<"Available seats "<<avl<<endl;
        //printing the all seats chart 
        for(vector<int> v:seats){
            for(int i:v){
                cout<<i<<" ";
            }cout<<endl;
        }
        //getting permission of booking seat or exiting the lopp
        cout<<"Enter 1 for bokking seat or any num for exit"<<endl;
        int x;
        cin>>x;
        if(x!=1) break;
        
        cout<<"Enter the number of seates you wanna book"<<endl;
        cout<<"Available seats "<<avl<<endl;
        cout<<"No. of seates must be in range of 1 and 7"<<endl;
        //getting the input of the number of seats to book
        int booking;
        cin>>booking;
        if(booking>7 || booking<=0){
            cout<<"You are only elegiable to by atmost 7 ticket at a time.."<<endl;
            continue;
        }
        //checking the avilablity of seats is enough or not
        if(avl<booking){
            cout<<"sorry! Not enough seats available as per your need"<<endl;
            cout<<"only "<<avl<<" are available!"<<endl;
            continue;
        }
        //updating the avilable seats quentity
        avl-=booking;

        //starting loop as the row and col and also check the number of booking
        for(;row<seats.size() && booking>0;row++){
            //doing a snake like traversel for getting the closer seats

            //if number of row is even then it will traverse left to right
            if(row%2==0){
                //checking is the col value is -ve by the prev traversel then update it by 0
                if(col<=0) col=0;
                //starting loop for the rwo element and also check the booking
                for(;col<seats[row].size() && booking>0;col++){  
                    //adding the seat number in seat_num vector 
                    seat_num.push_back(seats[row][col]);
                    //marking seat possition with 0 for representin it as booked
                    seats[row][col]=0;
                    //decreasing the booking value
                    booking--;
                }
            }else{
                //checking is the col value is greater then the width of the matrix by the prev traversel then update it by matrix size -1
                if(col>=seats[row].size()) col=seats[row].size()-1;

                //applying reverse loop and also check the booking
                for(;col>=0 && booking>0;col--){
                    //adding the seat number in seat_num vector 
                    seat_num.push_back(seats[row][col]);
                    //marking seat possition with 0 for representin it as booked
                    seats[row][col]=0;
                    //decreasing the booking value
                    booking--;
                }
            }
            //checking if the all booking done as per the user input i.e booking ==0 
            if(booking==0){
                //checking if the booking ends on start or end then change the row
                if(col==7 || col==-1) row++;
                break;
            }
        }
        cout<<"sets are booked successfully"<<endl;
        cout<<"your seats are "<<endl;
        //printing the booked seats
        for(int ele:seat_num){
            cout<<ele<<" ";
        }
        cout<<endl<<endl;
    }
    cout<<"Thankyou for booking our seats"<<endl;
return 0;
}


