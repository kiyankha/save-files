#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
bool arr_del_nums[10] = {0,0,0,0,0,0,0,0,0,0};
//Cout error with red
void error_cout(string inp_err)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            cout<<inp_err;
            SetConsoleTextAttribute(hConsole, 15);
}
//Converting integer into string
string int_to_string(int input)
{
    string converted_num = "";
    while(input != 0)
    {
        converted_num += char(input%10 +48);
        input = (input - input%10)/10;
    }
    reverse(converted_num.begin(),converted_num.end());
    return converted_num;
}

int main()
{
    int int_guess;
    int_guess = 9752;
    string str_guess="", str_guess_backup="", prev_guess = "";
    str_guess = int_to_string(int_guess);
    int feed_num, prev_feed_num ;
    int feed_index, prev_feed_index;
    int counter = 0, index_counter, nc_count =0;
    int temp1;
    int stage = 1;
    bool first_index = true;
    bool dig_is_correct, digs_are_correct;
    bool win = false;
    int inc_index_mat[5][4];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            inc_index_mat[i][j] = 0;
        }
    }
    cout<<endl<<"Stage: "<<stage<<"  Guess: "<<int_guess;
    cout<<endl<<"Enter the number of correct digits: ";
    cin>>feed_num;
    if((feed_num >=0) && (feed_num<4))
    {
        digs_are_correct = false;
    }
    else
    {
        digs_are_correct = true;
    }
    prev_feed_num = feed_num;
    // cout<<endl<<"number of correct numbers with correct position: ";
    // cin>>feed_index;
    //Phase 1: Finding the correct digits
    while(digs_are_correct == false)
    {
        switch (feed_num)
        {
            case 0:
                    counter = 0;
                    index_counter = 0;
                    dig_is_correct = false;
                    for(int i=0;i<4;i++)
                    {
                        arr_del_nums[int(str_guess[i]) - 48] = 1;
                    }
                    while(index_counter < 4)
                    {
                        if(arr_del_nums[counter] == 0)
                        {
                            str_guess[index_counter] = char(counter + 48);
                            index_counter++; 
                        }
                        counter++;
                    }
                    cout<<endl<<"New num: "<<str_guess;
                    stage++;
                    cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                    cout<<endl<<"Enter the number of correct digits: ";
                    cin>>feed_num;
                    break;
            case 1: case 2: case 3:
                    dig_is_correct = false;
                    counter = 8;
                    index_counter = 0;
                    while(prev_feed_num < 4)
                    {
                        dig_is_correct = false;
                        cout<<endl<<"this is index:"<<index_counter<<" and counter:"<<counter<<" and first_index:"<<first_index<<endl;
                        
                        //cout<<endl<<"##################################\nCorrect numbers: "<<prev_feed_num<<"\n##################################";
                        while(dig_is_correct == false)
                        {
                            if(arr_del_nums[counter] == 0)
                            {
                                //cout<<endl<<"---------\nCounter: "<<counter<<"\nIndex counter: "<<index_counter<<"\n---------";
                                prev_feed_num = feed_num;
                                temp1 = str_guess[index_counter];
                                str_guess[index_counter] = char(counter + 48);
                                stage++;
                                cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                cout<<endl<<"Enter the number of correct digits: ";
                                cin>>feed_num;
                                //cout<<endl<<"First cor dig feed: "<<prev_feed_num;
                                //cout<<endl<<"Second cor dig feed: "<<feed_num;
                                if(feed_num - prev_feed_num == -1)
                                {
                                    arr_del_nums[counter] = 1;
                                    dig_is_correct = true;
                                    str_guess[index_counter] = temp1;
                                    feed_num++;
                                    cout<<endl<<"-1 Counter: "<<counter<<endl;
                                    if(nc_count+1 >= 4-prev_feed_num)
                                    {
                                        for(int str_indx=0;str_indx<prev_guess.length();str_indx++)
                                        {
                                            arr_del_nums[int(prev_guess[str_indx]) - 48] = 1;
                                        }
                                        nc_count = 0;
                                        prev_guess = "";
                                        for(int p=0;p<10;p++)
                                        {
                                            cout<<arr_del_nums[p]<<' ';
                                        }
                                    }
                                }
                                else if(feed_num - prev_feed_num == 0)
                                {
                                    cout<<endl<<"0 Counter: "<<counter<<endl;
                                    prev_guess.push_back(char(counter+1 +48));
                                    nc_count++;
                                    cout<<endl<<"prev_guess: "<<prev_guess<<" nc_count: "<<nc_count<<"\n-------------------"<<endl;
                                    
                                }
                                else if(feed_num - prev_feed_num == 1)
                                {
                                    dig_is_correct = true;
                                    cout<<endl<<"+1 Counter: "<<counter<<endl;
                                    prev_feed_num = feed_num;
                                    if(nc_count+1 >= 4-prev_feed_num)
                                    {
                                        prev_guess.push_back(char(counter+1+48));
                                        for(int str_indx=0;str_indx<prev_guess.length();str_indx++)
                                        {
                                            arr_del_nums[int(prev_guess[str_indx]) - 48] = 1;
                                        }
                                        nc_count = 0;
                                        prev_guess = "";
                                        for(int p=0;p<10;p++)
                                        {
                                            cout<<arr_del_nums[p]<<' ';
                                        }
                                    }
                                }
                            }
                            counter--;
                        }
                        index_counter++;
                        first_index = false;
                        counter = 9;
                    }
                    digs_are_correct = true;
                    break;   
                    
            case 4:
                    digs_are_correct = true;
                    break;
            default: error_cout("\nWrong feedback!!!\n");
                    break;
        }
    }
return 0;
}
