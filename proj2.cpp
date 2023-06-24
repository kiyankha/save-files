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
//Converting string into integer
string guess_cor_num(string guess,int index)
{
    string cor_num = guess;
    
    for (int i=0;i<10;i++)
    {
        if(arr_del_nums[i] == 0)
        {
            if(i != int(guess[index])-48)
            {
                guess[index] = char(i+48);
            }
        }
    }
    return cor_num;
}
int main()
{
    int int_guess;
    int_guess = 9752;
    string str_guess="", str_guess_backup="";
    str_guess = int_to_string(int_guess);
    int feed_num, prev_feed_num ;
    int feed_index, prev_feed_index;
    int counter = 0, index_counter;
    int temp1;
    int stage = 1;
    bool first_loop = true;
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
                        if(first_loop = false)
                        {
                            counter = int(str_guess[index_counter-1]) - 48;
                        }
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
                                    cout<<endl<<"-1 Counter: "<<counter;
                                }
                                else if(feed_num - prev_feed_num == 0)
                                {
                                    cout<<endl<<"0 Counter: "<<counter;
                                }
                                else if(feed_num - prev_feed_num == 1)
                                {
                                    dig_is_correct = true;
                                    cout<<endl<<"+1 Counter: "<<counter;
                                    prev_feed_num = feed_num;
                                }
                            }
                            counter--;
                        }
                        index_counter++;
                        first_loop = false;
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
    cout<<endl<<"so this is after finding the correct digits";
    //Updating index matrix
    for(int i= 0;i<4;i++)
    {
        inc_index_mat[0][i] = int(str_guess[i])-48;
    }
    cout<<endl<<"First stage of index mat: ";
    for(int i=0;i<5;i++)
    {
        cout<<endl;
        for(int j=0;j<4;j++)
        {
            cout<<inc_index_mat[i][j]<<' ';
        }
    }
    cout<<endl<<"Turn: "<<stage<<"  Guess: "<<str_guess;
    cout<<endl<<"Number of correct positions: ";
    cin>>feed_index;
    //Phase 2:Finding the correct positions
    // cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
    // cout<<endl<<"Enter the number of correct digits: ";
    int counter_1 = 0,counter_2 = 0;
    bool pos_check[4] = {0};//0 -> Put  1->Don't put
    int pos_num[4] = {0};
    int temp2;
    while(1)
    {
        switch (feed_index) 
        {
            case 0:
                    cout<<endl<<"00000000000000000000000000000000000\nThis is case 0:\n00000000000000000000000000000000000";
                    counter_1 = 0,counter_2 = 0;
                    cout<<endl<<"Now trying to swap nums to get feed two";
                    //Updating index matrix
                    temp1 = 0;
                    for(int str_indx=0;str_indx<4;str_indx++)
                    {
                        while(inc_index_mat[0][temp1] != int(str_guess[str_indx]) - 48)
                        {
                            temp1++;
                        }
                        inc_index_mat[str_indx+1][temp1] = 1;
                    }
                    for(counter_1 = 0;counter_1<3;counter_1++)
                    {
                        cout<<endl<<"This is our index mat: ";
                        for(int i=0;i<5;i++)
                        {
                            cout<<endl;
                            for(int j=0;j<4;j++)
                            {
                                cout<<inc_index_mat[i][j]<<' ';
                            }
                        }
                        cout<<endl<<"First pos counter: "<<counter_1;
                        index_counter = 0;
                        while(inc_index_mat[0][index_counter] != int(str_guess[counter_1]) - 48)
                        {
                            index_counter++;
                        }
                        cout<<endl<<counter_1<<"th num in guess: "<<str_guess[counter_1]<<" and the num in mat: "<<inc_index_mat[0][index_counter];
                        for(counter_2 = counter_1+1;counter_2<4;counter_2++)
                        {
                            cout<<endl<<str_guess[counter_1]<<" to index "<<counter_2<<endl;
                            cout<<endl<<"Second pos counter: "<<counter_2;
                            counter = 0;
                            while(inc_index_mat[0][counter] != int(str_guess[counter_2]) - 48)
                            {
                                counter++;
                            }
                            cout<<endl<<str_guess[counter_2]<<" to index "<<counter_1<<endl;
                            cout<<endl<<"checking conds: for first num: "<<inc_index_mat[counter_2+1][index_counter]<<" for second num: "<<inc_index_mat[counter_1+1][counter];
                            if((inc_index_mat[counter_2+1][index_counter] ==0) && (inc_index_mat[counter_1+1][counter] ==0))
                            {
                                swap(str_guess[counter_1],str_guess[counter_2]);
                                stage++;
                                cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                cout<<endl<<"Number of correct positions: ";
                                cin>>feed_index;
                                
                                if(feed_index != 2)
                                {
                                    if(feed_index == 4)
                                    {
                                        cout<<endl<<"Yooooo I won!!!!!!";
                                        return 1;
                                    }
                                    if(feed_index == 0)
                                    {
                                        cout<<endl<<"Entering the feed index = 0 sec";
                                        //Updating index matrix
                                        temp1 = 0;
                                        cout<<endl<<"Now checking mat update: (temp1: "<<temp1<<")";
                                        for(int str_indx=0;str_indx<4;str_indx++)
                                        {
                                            temp1 = 0;
                                            cout<<endl<<"string index "<<str_indx<<" with value "<<str_guess[str_indx];
                                            while(inc_index_mat[0][temp1] != int(str_guess[str_indx]) - 48)
                                            {
                                                temp1++;
                                            }
                                            cout<<endl<<"temp1: "<<temp1;
                                            inc_index_mat[str_indx+1][temp1] = 1;
                                        }
                                        cout<<endl<<"This is our index mat: ";
                                        for(int i=0;i<5;i++)
                                        {
                                            cout<<endl;
                                            for(int j=0;j<4;j++)
                                            {
                                                cout<<inc_index_mat[i][j]<<' ';
                                            }
                                        }   
                                    }
                                    swap(str_guess[counter_1],str_guess[counter_2]);
                                    cout<<endl<<"Oh man no feed 2 so undoing changes -> "<<str_guess;
                                }
                                else if(feed_index == 2)
                                {
                                    cout<<endl<<"Oh yeah so I just have to change the two other digits!!!";
                                    while(1)
                                    {
                                        int ct1=0,ct2;
                                        while((ct1 == counter_1) || (ct1 == counter_2))
                                        {
                                            ct1++;
                                        }
                                        ct2 = ct1+1;
                                        while((ct2 == counter_1) || (ct2 == counter_2))
                                        {
                                            ct2++;
                                        }
                                        cout<<endl<<"main ind: "<<counter_1<<" & "<<counter_2;
                                        cout<<endl<<"found ind: "<<ct1<<" & "<<ct2;
                                        swap(str_guess[ct1],str_guess[ct2]);
                                        cout<<endl<<str_guess;
                                        cout<<endl<<"Yooooo I won!!!!!!";
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                    break;
            case 1: cout<<endl<<"11111111111111111111111111111111111111111\nThis is case 1\n11111111111111111111111111111111111111111";
                    cout<<endl<<"Now trying to see if it is inc nc dec";
                    counter = 0;
                    index_counter = 1;
                    while(1)
                    {
                        swap(str_guess[counter],str_guess[index_counter]);
                        str_guess_backup = str_guess;
                        cout<<endl<<"In while, after swapping";
                        prev_feed_index = feed_index;
                        stage++;
                        cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                        cout<<endl<<"Number of correct positions: ";
                        cin>>feed_index;
                        //Feedback: dc
                        if(feed_index - prev_feed_index == -1)
                        {
                            cout<<endl<<"This is decrease mode";
                            swap(str_guess[counter],str_guess[index_counter]);
                            swap(str_guess[3-counter],str_guess[3-index_counter]);
                            cout<<endl<<"assuming num["<<counter<<"] is right";
                            for(int str_indx = 0;str_indx<3;str_indx++)
                            {
                                if((str_indx != counter) && (str_indx != index_counter))
                                {
                                    swap(str_guess[index_counter],str_guess[str_indx]);
                                    stage++;
                                    cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                    cout<<endl<<"Number of correct positions: ";
                                    cin>>feed_index;
                                    if(feed_index == 4)
                                    {
                                        win = true;
                                        break;
                                    }
                                    
                                }
                                if(win == true)
                                {
                                    cout<<endl<<"Yooooo I won!!!!!!";
                                    return 1;
                                }
                            }
                        }
                        //Feedback: no change
                        if(feed_index - prev_feed_index == 0)
                        {
                            //Swapping the other two digits (bacd = 0)
                            cout<<endl<<"This is no change mode";
                            if(feed_index ==0)
                            {
                                cout<<endl<<"Undoing changes";
                                swap(str_guess[counter],str_guess[index_counter]);
                                //Assuming num[counter] is right
                                cout<<endl<<"Assuming num["<<counter<<"] is right";
                                for(int str_indx=0;str_indx<4;str_indx++)
                                {
                                    cout<<endl<<"Entering the first for loop";
                                    if((str_indx != counter) && (str_indx != index_counter)) 
                                    {
                                        cout<<endl<<"swapping in the first loop";
                                        swap(str_guess[index_counter],str_guess[str_indx]);
                                        prev_feed_index = feed_index;
                                        stage++;
                                        cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                        cout<<endl<<"Number of correct positions: ";
                                        cin>>feed_index;
                                        if(feed_index==4)
                                        {
                                            cout<<endl<<"received feed 4";
                                            win = true;
                                            break;
                                        }
                                        else
                                        {
                                            cout<<endl<<"no feed 4 so undoing changes";
                                            swap(str_guess[index_counter],str_guess[str_indx]);
                                        }
                                    }
                                    if(win == true)
                                    {
                                        cout<<endl<<"Yooooo I won!!!!!!";
                                        return 1;
                                    }
                                    else
                                    {
                                        
                                        cout<<endl<<"Assuming num["<<index_counter<<"] is in right pos";
                                        for(int str_indx=0;str_indx<4;str_indx++)
                                        {
                                            cout<<endl<<"Entering the second for loop";
                                            if((str_indx != counter) && (str_indx != index_counter)) 
                                            {
                                                swap(str_guess[counter],str_guess[str_indx]);
                                                prev_feed_index = feed_index;
                                                stage++;
                                                cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                                cout<<endl<<"Number of correct positions: ";
                                                cin>>feed_index;
                                                if(feed_index==4)
                                                {
                                                    cout<<endl<<"received feed 4";
                                                    cout<<endl<<"Yooooo I won!!!!!!";
                                                    return 1;
                                                } 
                                                else
                                                {
                                                    cout<<endl<<"no feed 4 so undoing change";
                                                    swap(str_guess[counter],str_guess[str_indx]);
                                                }  
                                            }
                                        }
                                    }
                                }
                            }
                            //checking if badc = 0
                            int ct1=0,ct2;
                            while((ct1 == counter) || (ct1 == index_counter))
                            {
                                ct1++;
                            }
                            ct2 = ct1+1;
                            while((ct2 == counter) || (ct2 == index_counter))
                            {
                                ct2++;
                            }
                            cout<<endl<<"main ind: "<<counter<<" & "<<index_counter;
                            cout<<endl<<"found ind: "<<ct1<<" & "<<ct2;
                            swap(str_guess[ct1],str_guess[ct2]);
                            cout<<endl<<str_guess;
                            stage++;
                            cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                            cout<<endl<<"Number of correct positions: ";
                            cin>>feed_index;
                            //one of them was right
                            if(feed_index == 0)
                            {
                                str_guess = str_guess_backup;
                                swap(str_guess[counter],str_guess[index_counter]);
                                //Assuming num[counter] is right
                                cout<<endl<<"Assuming num["<<counter<<"] is right";
                                for(int str_indx=0;str_indx<4;str_indx++)
                                {
                                    cout<<endl<<"Entering the first for loop";
                                    if((str_indx != counter) && (str_indx != index_counter)) 
                                    {
                                        cout<<endl<<"swapping in the first loop";
                                        swap(str_guess[index_counter],str_guess[str_indx]);
                                        prev_feed_index = feed_index;
                                        stage++;
                                        cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                        cout<<endl<<"Number of correct positions: ";
                                        cin>>feed_index;
                                        if(feed_index==4)
                                        {
                                            cout<<endl<<"received feed 4";
                                            win = true;
                                            break;
                                        }
                                        else
                                        {
                                            cout<<endl<<"no feed 4 so undoing changes";
                                            swap(str_guess[index_counter],str_guess[str_indx]);
                                        }
                                    }
                                    if(win == true)
                                    {
                                        cout<<endl<<"Yooooo I won!!!!!!";
                                        return 1;
                                    }
                                    else
                                    {   
                                        cout<<endl<<"Assuming num["<<index_counter<<"] is in right pos";
                                        for(int str_indx=0;str_indx<4;str_indx++)
                                        {
                                            cout<<endl<<"Entering the second for loop";
                                            if((str_indx != counter) && (str_indx != index_counter)) 
                                            {
                                                swap(str_guess[counter],str_guess[str_indx]);
                                                prev_feed_index = feed_index;
                                                stage++;
                                                cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                                cout<<endl<<"Number of correct positions: ";
                                                cin>>feed_index;
                                                if(feed_index==4)
                                                {
                                                    cout<<endl<<"received feed 4";
                                                    cout<<endl<<"Yooooo I won!!!!!!";
                                                    return 1;
                                                } 
                                                else
                                                {
                                                    cout<<endl<<"no feed 4 so undoing change";
                                                    swap(str_guess[counter],str_guess[str_indx]);
                                                }  
                                            }
                                        }
                                    }
                                }
                            }
                        }   
                        //Feedback: increase by 1   
                        if(feed_index - prev_feed_index == 1)
                        {
                            cout<<endl<<"this is inc mode";
                            //Assuming num[counter] is in the right position -> swapping other digits
                            cout<<endl<<"Assuming num["<<index_counter<<"] is in right pos";
                            for(int str_indx=0;str_indx<4;str_indx++)
                            {
                                cout<<endl<<"Entering the first for loop";
                                if((str_indx != counter) && (str_indx != index_counter)) 
                                {
                                    cout<<endl<<"swapping in the first loop";
                                    swap(str_guess[counter],str_guess[str_indx]);
                                    prev_feed_index = feed_index;
                                    stage++;
                                    cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                    cout<<endl<<"Number of correct positions: ";
                                    cin>>feed_index;
                                    if(feed_index==4)
                                    {
                                        cout<<endl<<"received feed 4";
                                        win = true;
                                        break;
                                    }
                                    else if(feed_index == 0)
                                    {
                                        cout<<endl<<"so num["<<counter<<"] is right";
                                        swap(str_guess[counter],str_guess[str_indx]);
                                        swap(str_guess[index_counter],str_guess[6-(counter+index_counter+str_indx)]);
                                        stage++;
                                        cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                        cout<<endl<<"Number of correct positions: ";
                                        cin>>feed_index;
                                        //break;
                                    }
                                    else
                                    {
                                        cout<<endl<<"no feed 4 so undoing change";
                                        swap(str_guess[counter],str_guess[str_indx]);
                                    }
                                }
                            }
                            if(win == true)
                            {
                                cout<<endl<<"Yooooo I won!!!!!!";
                                return 1;
                            }
                            else
                            {
                                str_guess = str_guess_backup;
                                cout<<endl<<"Assuming num["<<index_counter<<"] is in right pos";
                                for(int str_indx=0;str_indx<4;str_indx++)
                                {
                                    cout<<endl<<"Entering the second for loop";
                                    if((str_indx != counter) && (str_indx != index_counter)) 
                                    {
                                        swap(str_guess[index_counter],str_guess[str_indx]);
                                        prev_feed_index = feed_index;
                                        stage++;
                                        cout<<endl<<"Stage: "<<stage<<"  Guess: "<<str_guess;
                                        cout<<endl<<"Number of correct positions: ";
                                        cin>>feed_index;
                                        if(feed_index==4)
                                        {
                                            cout<<endl<<"received feed 4";
                                            cout<<endl<<"Yooooo I won!!!!!!";
                                            return 1;
                                        } 
                                        else
                                        {
                                            cout<<endl<<"no feed 4 so undoing change";
                                            swap(str_guess[index_counter],str_guess[str_indx]);
                                        }  
                                    }
                                }
                            }
                        }
                        index_counter++;
                        if(index_counter == 4)
                        {
                            index_counter = 2;
                            counter++;
                        }  
                    }
                    break;
            case 4:
                    cout<<endl<<"Yooooo I won!!!!!!";
                    return 1;
                    break;
            default: error_cout("\nWrong feedback!!!\n");
                    break;
        }
    }
    return 0;
}