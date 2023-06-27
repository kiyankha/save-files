#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int arr_del_nums[10] = {0,0,0,0,0,0,0,0,0,0};
bool arr_cor_pos[4] = {0,0,0,0};
int inc_index_mat[3][4] = {0};
int index_mat_row_cnt = 0;
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
void index_mat_config(int pos,int num)
{
    for(int col = 0;col<3;col++)
    {
        if(inc_index_mat[col][pos] == -1)
        {
            inc_index_mat[col][pos] = num;
        }
    }
}
bool check_if_rep(string str)
{

    for (int i = 0; i < str.length(); i++) 
    {
      for (int j = i + 1; j < str.length(); j++)
       {
         if (str[i] == str[j]) 
         {
            return 1;
         }
      }
   }
   return 0;
}
int main()
{
    int int_guess;
    int_guess = 9752;
    string str_guess="", str_guess_backup="", prev_guess = "";
    str_guess = int_to_string(int_guess);
    int feed_num, prev_feed_num ;
    int feed_index, prev_feed_index;
    int counter = 0, index_counter = 0, nc_count =0,cnt = 0;
    int nex_cor = 0;
    char temp1 , temp2;
    int turn = 1;
    bool first_index = true;
    bool dig_is_correct, digs_are_correct;
    bool prev_guess_cor = false, cor_dig_to_nxpos = false, nex_cor_eq = false, change = false;
    bool win = false;
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            inc_index_mat[row][col] = -1;
        }
    }
    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<int_guess;
    cout<<endl<<"Number of correct digits: ";
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
    cout<<endl<<"Number of correct digits with correct position: ";
    cin>>feed_index;
    prev_feed_index = feed_index;
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
                        if(arr_del_nums[cnt] != 1)
                        {
                            str_guess[index_counter] = char(cnt + 48);
                            //index_counter++; 
                        }
                        if(cnt == 9)
                        {
                            cnt = 0;
                        }
                        cnt++;

                    }
                    cout<<endl<<"New num: "<<str_guess;
                    turn++;
                    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                    cout<<endl<<"Enter the number of correct digits: ";
                    cin>>feed_num;
                    cout<<endl<<"Number of correct digits with correct position: ";
                    cin>>feed_index;
                    break;
            case 1: case 2: case 3:
                    dig_is_correct = false;
                    counter = 8;
                    index_counter = 0;
                    while(feed_num < 4)
                    {
                        dig_is_correct = false;
                        //cout<<endl<<"this is index:"<<index_counter<<" and counter:"<<counter<<" and first_index:"<<first_index<<endl;
                        // if (cor_dig_to_nxpos == true)
                        // {
                        //     cout<<endl<<"this is when cor_dig_to_nxpos == true with index_counter: "<<index_counter;
                        //     temp2 = str_guess[index_counter];
                        //     //str_guess[index_counter] = char(nex_cor+48);
                        // }
                        if(prev_guess_cor = true)
                        {
                            cout<<endl<<"oh this prev_guess_cor is working!!!";
                            int str_indx=0;
                            while(str_indx<=prev_guess.length() && index_counter < 4)
                            {
                                if(arr_cor_pos[index_counter] != 1)
                                {
                                    str_guess[index_counter] = prev_guess[str_indx];
                                    index_counter++;
                                }
                                str_indx++;
                            }
                        }
                        if(index_counter == 4)
                        {
                            break;
                        }
                        prev_guess_cor = false;
                        prev_guess = "";
                        nc_count=0;
                        //cout<<endl<<"##################################\nCorrect numbers: "<<prev_feed_num<<"\n##################################";
                        if(arr_cor_pos[index_counter] != 1)
                        {
                            while(dig_is_correct == false)
                            {
                                if(feed_num == 0)
                                {
                                    for(int str_indx=0;str_indx<str_guess.length();str_indx++)
                                    {
                                        arr_del_nums[int(str_guess[str_indx]) - 48] = 1;
                                    }
                                }
                                if(arr_del_nums[counter] != 1)
                                {
                                    //cout<<endl<<"---------\nCounter: "<<counter<<"\nIndex counter: "<<index_counter<<"\n---------";
                                    prev_feed_num = feed_num;
                                    prev_feed_index = feed_index;
                                    temp1 = str_guess[index_counter];
                                    cout<<endl<<"**********************************";
                                    cout<<endl<<"changing index: "<<index_counter;
                                    cout<<endl<<"temp1 is: "<<temp1;
                                    cout<<endl<<"Prev feed num: "<<prev_feed_num<<" Prev feed index: "<<prev_feed_index;
                                    str_guess[index_counter] = char(counter + 48);
                                    cout<<endl<<"str_guess before get f: "<<str_guess;
                                    //cout<<endl<<"cor_dig_to_nxpos: "<<cor_dig_to_nxpos;
                                    //cout<<endl<<"nex_cor: "<<nex_cor;
                                    // if(cor_dig_to_nxpos == true)
                                    // {
                                    //     str_guess[index_counter] = char(nex_cor + 48);
                                    //     cor_dig_to_nxpos = false;
                                    // }
                                    turn++;
                                    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                                    cout<<endl<<"Enter the number of correct digits: ";
                                    cin>>feed_num;
                                    cout<<endl<<"Number of correct digits with correct position: ";
                                    cin>>feed_index;
                                    
                                    cout<<endl<<"new feeds: f1: "<<feed_num<<" f2: "<<feed_index;
                                    cout<<endl<<"Diff: f1n - f1p: "<<feed_num - prev_feed_num;
                                    //cout<<endl<<"nex_cor_eq = "<<nex_cor_eq;
                                    
                                        //-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
                                        if(feed_num - prev_feed_num == -1)
                                        {
                                            dig_is_correct = true;
                                            cout<<endl<<"f1 change: -1"<<endl;
                                            cout<<"temp1: "<<temp1;
                                            cout<<endl<<"before change: "<<str_guess;
                                            str_guess[index_counter] = temp1;
                                            cout<<endl<<"after change 1: "<<str_guess;
                                            inc_index_mat[0][index_counter] = int(str_guess[index_counter])-48;
                                            arr_del_nums[int(temp1)-48] = 2;
                                            if(str_guess_backup.find(char(counter+48)) == -1)
                                            {
                                                arr_del_nums[counter] = 1;
                                            }
                                            //Error
                                            if(nc_count+1 > 4-feed_num)
                                            {
                                                error_cout("\nError!!!!\nWrong feedback!!!\n");
                                            }
                                            else
                                            {
                                                for(int str_indx=0;str_indx<prev_guess.length();str_indx++)
                                                {
                                                    arr_del_nums[int(prev_guess[str_indx])-48] = 2;
                                                }
                                                prev_guess_cor = true;
                                            }
                                            if(feed_index - prev_feed_index == 0)
                                            {
                                                index_mat_config(index_counter,int(temp1)-48);
                                            }
                                            else if(feed_index - prev_feed_index == -1)
                                            {
                                                arr_cor_pos[index_counter] = 1;
                                            }
                                            feed_index = prev_feed_index;
                                            feed_num = prev_feed_num;
                                            cout<<endl<<"end -1: "<<str_guess;
                                        }
                                        //00000000000000000000000000000000000000000000000000000
                                        else if(feed_num - prev_feed_num == 0)
                                        {
                                            cout<<endl<<"f1-change: 0"<<endl;
                                            cout<<endl<<"before change: "<<str_guess;
                                            cout<<endl<<"0 Counter: "<<counter<<endl;
                                            prev_guess.push_back(temp1);
                                            nc_count++;
                                            cout<<endl<<"prev_guess: "<<prev_guess<<" nc_count: "<<nc_count<<"\n-------------------"<<endl;
                                            if(nc_count+1 > 4-feed_num)
                                            {
                                                for(int str_indx=0;str_indx<prev_guess.length();str_indx++)
                                                {
                                                    arr_del_nums[int(prev_guess[str_indx]) - 48] = 1;
                                                }
                                            }
                                            if(feed_index - prev_feed_index == -1)
                                            {
                                                cout<<endl<<"f2n - f2p: "<<-1;
                                                cout<<endl<<"change 0: temp1: "<<temp1;
                                                // if(cor_dig_to_nxpos == true)
                                                // {
                                                //     str_guess[index_counter] = temp2;
                                                //     arr_del_nums[int(temp2)-48] = 2;
                                                // }
                                                //else
                                                //{
                                                    str_guess[index_counter] = temp1;
                                                //}
                                                arr_cor_pos[index_counter] = 1;
                                                arr_del_nums[int(temp1)-48] = 2;
                                                arr_del_nums[counter] = 2;
                                                index_mat_config(index_counter,counter);
                                                dig_is_correct = true;
                                                cor_dig_to_nxpos = true;
                                                nex_cor = counter;
                                                cout<<endl<<"temp1: "<<temp1<<" counter: "<<counter;
                                                
                                            }
                                            else if(feed_index - prev_feed_index == 1)
                                            {
                                                cout<<endl<<"f2n - f2p: "<<1;
                                                arr_cor_pos[index_counter] = 1;
                                                index_mat_config(index_counter,int(temp2)-48);
                                                // if(cor_dig_to_nxpos == true)
                                                // {
                                                //     arr_del_nums[int(temp2)-48] = 2;
                                                //     nex_cor = int(temp2)-48;
                                                //     change = 1;
                                                // }
                                                arr_del_nums[int(temp1)-48] = 2;
                                                arr_del_nums[counter] = 2;
                                                dig_is_correct = true;
                                                cor_dig_to_nxpos = true;
                                                //if(change == 0)
                                                //{
                                                    nex_cor = int(temp1)-48;
                                                //}
                                            }
                                            cout<<endl<<"end 0: "<<str_guess;
                                        }
                                        //1111111111111111111111111111111111111111111111111111111111
                                        else if(feed_num - prev_feed_num == 1)
                                        {
                                            cout<<endl<<"f1 change: 1"<<endl;
                                            cout<<endl<<"before change: "<<str_guess;
                                            str_guess[index_counter] = char(counter+48);
                                            cout<<endl<<"after change 1: "<<str_guess;
                                            arr_del_nums[counter] = 2;
                                            dig_is_correct = true;
                                            if(str_guess_backup.find(temp1)==-1)
                                            {
                                                arr_del_nums[int(temp1)-48] == 1;
                                            }
                                            if(feed_index - prev_feed_index == 0)
                                            {
                                                index_mat_config(index_counter,int(temp1)-48);
                                            }
                                            else if(feed_index - prev_feed_index == 1)
                                            {
                                                arr_cor_pos[index_counter] = 1;
                                                index_mat_config(index_counter,int(temp1)-48);
                                            }
                                            for(int str_indx=0;str_indx<prev_guess.length();str_indx++)
                                            {
                                                if(str_guess_backup.find(prev_guess[str_indx]) == -1)
                                                {
                                                    arr_del_nums[int(prev_guess[str_indx])-48] = 1;
                                                }
                                            }
                                            cout<<endl<<"end 1: "<<str_guess;
                                            //cout<<endl<<"**********************************"<<endl;
                                        }
                                        cout<<endl<<"end of while dig is correct: "<<endl;
                                        for(int i=0;i<10;i++)
                                        {
                                            cout<<arr_del_nums[i];
                                        }
                                        cout<<endl<<"**********************************"<<endl;
                                    
                                }
                                counter--; 
                            }
                        }
                        index_counter++;
                        first_index = false;
                        if(cor_dig_to_nxpos == false)
                        {
                            counter = 9;
                        }
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
   /* 
    cout<<endl<<"First stage of index mat: ";
    for(int i=0;i<3;i++)
    {
        cout<<endl;
        for(int j=0;j<4;j++)
        {
            cout<<inc_index_mat[i][j]<<' ';
        }
    }
    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                        for(int i=0;i<3;i++)
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
                                turn++;
                                cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                        turn++;
                        cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                                    turn++;
                                    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                                        turn++;
                                        cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                                                turn++;
                                                cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                            turn++;
                            cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                                        turn++;
                                        cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                                                turn++;
                                                cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                                    turn++;
                                    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                                        turn++;
                                        cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
                                        turn++;
                                        cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
    }*/
    return 0;
}
