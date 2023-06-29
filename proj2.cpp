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
            break;
        }
    }
}
bool check_if_rep(string str,char num)
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) 
    {
      
         if (str[i] == num) 
         {
            cnt++;
         }
   }
   if(cnt >1)
   {
        return 1;
   }
   else
   {
    return 0;
   }
}
string swap_guess(string guess)
{
    int cnt1=0,cnt2=0;
    while(1)
    {
        if(arr_cor_pos[cnt1]!=1)
        {
            if(arr_cor_pos[cnt2]!=1)
            {
                swap(guess[cnt1],guess[cnt2]);
                break;
            }
            else
            {
                cnt2++;
            }
        }
        else
        {
            cnt1++;
        }
    }
    return guess;
}
int main()
{
    int int_guess;
    //int_guess = 9752;
    string str_guess="", str_guess_backup="", prev_guess = "";
    str_guess = "9752";
    int feed_num, prev_feed_num ;
    int feed_index, prev_feed_index;
    int counter = 0, index_counter = 0, nc_count =0,cnt = 0,pos_cnt = 0;
    int nex_cor = 0;
    char temp1;
    int turn = 1;
    bool first_index = true;
    bool dig_is_correct, digs_are_correct;
    bool prev_guess_cor = false, rep = false, nex_cor_eq = false, change = false;
    bool win = false;
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            inc_index_mat[row][col] = -1;
        }
    }
    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
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
    str_guess_backup = str_guess;
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
                    cnt = 0;
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
                            index_counter++; 
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
                        
                        if(prev_guess_cor == true && prev_guess.length())
                        {
                            cout<<endl<<"oh this prev_guess_cor is working!!!";
                            cout<<endl<<"this is prev_guess:"<<prev_guess<<" and guess before change: "<<str_guess;
                            int str_indx=0;
                            while(str_indx<prev_guess.length() && index_counter < 4)
                            {
                                if(arr_cor_pos[index_counter] != 1)
                                {
                                    cout<<endl<<"now gonna replacing ["<<prev_guess[str_indx]<<"]";
                                    str_guess[index_counter] = prev_guess[str_indx];
                                    index_counter++;
                                }
                                str_indx++;
                            }
                            cout<<endl<<"this is guess after change: "<<str_guess;

                        }
                        if(index_counter == 4)
                        {
                            digs_are_correct = true;
                            prev_feed_num = feed_num;
                            prev_feed_index = feed_index;
                            turn++;
                            cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                            cout<<endl<<"Enter the number of correct digits: ";
                            cin>>feed_num;
                            cout<<endl<<"Number of correct digits with correct position: ";
                            cin>>feed_index;
                            break;
                        }
                        prev_guess_cor = false;
                        prev_guess = "";
                        nc_count=0;
                        if(arr_cor_pos[index_counter] != 1)
                        {
                            while(dig_is_correct == false)
                            {
                                if((arr_del_nums[counter] != 1) && (arr_del_nums[counter] != 3) && (prev_guess.find(char(counter+48)) == -1))
                                {
                                    prev_feed_num = feed_num;
                                    prev_feed_index = feed_index;
                                    temp1 = str_guess[index_counter];
                                    cout<<endl<<"**********************************";
                                    cout<<endl<<"changing index: "<<index_counter;
                                    cout<<endl<<"temp1 is: "<<temp1;
                                    cout<<endl<<"prev_guess is:"<<prev_guess;
                                    cout<<"\n^^^^^\nPrev feed num: "<<prev_feed_num<<"\nPrev feed index: "<<prev_feed_index<<"\n^^^^^";
                                    str_guess_backup = str_guess;
                                    str_guess[index_counter] = char(counter + 48);
                                    if(str_guess != str_guess_backup)
                                    {
                                        cout<<endl<<"backup: "<<str_guess_backup<<" new guess: "<<str_guess;
                                        turn++;
                                        cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                                        cout<<endl<<"Enter the number of correct digits: ";
                                        cin>>feed_num;
                                        cout<<endl<<"Number of correct digits with correct position: ";
                                        cin>>feed_index;
                                        cout<<endl<<"new feeds: f1: "<<feed_num<<" f2: "<<feed_index;
                                        cout<<endl<<"Diff: f1n - f1p: "<<feed_num - prev_feed_num;
                                        //-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
                                        if(feed_num - prev_feed_num == -1)
                                        {
                                            dig_is_correct = true;
                                            cout<<endl<<"f1 change: -1"<<endl;
                                            cout<<"temp1: "<<temp1;
                                            cout<<endl<<"check if: "<<check_if_rep(str_guess,char(counter+48))<<" for counter: "<<counter<<" in guess: "<<str_guess;
                                            if(check_if_rep(str_guess,char(counter+48)) == 1)
                                            {
                                                cout<<endl<<"check rep is: "<<check_if_rep<<" and deleteing counter: "<<counter;
                                                arr_del_nums[counter] = 3;
                                            }
                                            cout<<endl<<"before change: "<<str_guess;
                                            str_guess[index_counter] = temp1;
                                            cout<<endl<<"after change 1: "<<str_guess;
                                            arr_del_nums[int(temp1)-48] = 2;
                                            if(str_guess_backup.find(char(counter+48)) == -1)
                                            {
                                                cout<<endl<<"now this incor num wasn't in org  ->counter: "<<counter;
                                                arr_del_nums[counter] = 1;
                                            }
                                            //Error
                                            if(nc_count > 4-feed_num)
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
                                            cout<<endl<<"this is nc_count: "<<nc_count<<" and prev_guess_cor: "<<prev_guess_cor;
                                            if(feed_index - prev_feed_index == -1)
                                            {
                                                arr_cor_pos[index_counter] = 1;
                                            }
                                            feed_index = prev_feed_index;
                                            feed_num = prev_feed_num;
                                            cnt = 0;
                                            for(int i=0;i<10;i++)
                                            {
                                                if((arr_del_nums[i] != 0) && (arr_del_nums[i] != 1))
                                                {
                                                    cnt++;
                                                }
                                            }
                                            cout<<endl<<"()()()this is cnt: "<<cnt;
                                            if(cnt == prev_feed_num)
                                            {
                                                cout<<endl<<"correct nums are found,now removing wrong ones";
                                                cout<<endl<<"checking for 2: "<<arr_del_nums[2];
                                                for(int str_indx=0;str_indx<4;str_indx++)
                                                {
                                                    if((arr_del_nums[int(str_guess[str_indx])-48] != 2) && (arr_del_nums[int(str_guess[str_indx])-48] != 3))
                                                    {
                                                        cout<<endl<<"this counter: "<<int(str_guess[str_indx])-48<<" for index: "<<str_indx;
                                                        cout<<endl<<"now configuring: "<<str_guess[str_indx];
                                                        arr_del_nums[int(str_guess[str_indx])-48] = 1;
                                                    }
                                                }
                                            }
                                            cout<<endl<<"end -1: "<<str_guess;
                                        }
                                        //00000000000000000000000000000000000000000000000000000
                                        else if(feed_num - prev_feed_num == 0)
                                        {
                                            cout<<endl<<"f1-change: 0";
                                            cout<<endl<<"before change: "<<str_guess;
                                            cout<<endl<<"Counter: "<<counter<<endl;
                                            if((prev_guess.find(temp1) == -1) && (arr_del_nums[int(temp1)-48] != 1))
                                            {
                                                prev_guess.push_back(temp1);
                                                nc_count++;
                                            }
                                            cout<<endl<<"prev_guess: "<<prev_guess<<" nc_count: "<<nc_count<<"\n-------------------"<<endl;
                                            if(nc_count > 4-feed_num)
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
                                                str_guess[index_counter] = temp1;
                                                arr_cor_pos[index_counter] = 1;
                                                arr_del_nums[int(temp1)-48] = 2;
                                                arr_del_nums[counter] = 2;
                                                dig_is_correct = true;
                                                cout<<endl<<"temp1: "<<temp1<<" counter: "<<counter;
                                            }
                                            else if(feed_index - prev_feed_index == 1)
                                            {
                                                cout<<endl<<"f2n - f2p: "<<1;
                                                arr_cor_pos[index_counter] = 1;
                                                if(arr_del_nums[int(temp1)-48] != 1)
                                                {
                                                    arr_del_nums[int(temp1)-48] = 2;
                                                }
                                                arr_del_nums[counter] = 2;
                                                dig_is_correct = true;
                                                rep = check_if_rep(str_guess,char(counter+48));
                                                cout<<endl<<"checking for rep: "<<rep;
                                                if(rep == true)
                                                {
                                                    cout<<endl<<"finding previous counter: "<<counter;
                                                    cout<<endl<<"prev/next index: "<<str_guess.find(char(counter+48))<<" ans arrpos[prev/next]: "<<arr_cor_pos[counter];
                                                    if(arr_cor_pos[str_guess_backup.find(char(counter+48))] == 0)
                                                    {
                                                        index_counter = str_guess_backup.find(char(counter+48))-1;
                                                        cout<<endl<<"now index-counter: "<<index_counter;
                                                    }
                                                }
                                                if(prev_guess.length()>0 && rep == 0)
                                                {
                                                    prev_guess_cor = true;
                                                }
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
                                            cout<<endl<<"oh this is backup: "<<str_guess_backup;
                                            arr_del_nums[counter] = 2;
                                            dig_is_correct = true;
                                            cout<<endl<<"prev pos: "<<str_guess.find(temp1);
                                            if(str_guess.find(temp1) == -1)
                                            {
                                                cout<<endl<<"(:-|_|-:) oh the prev was wrong!!!! now removing: "<<int(temp1)-48;
                                                arr_del_nums[int(temp1)-48] = 1;
                                                cout<<endl<<"oh nooo:"<<endl;
                                                for(int i=0;i<10;i++)
                                                {
                                                    cout<<arr_del_nums[i];
                                                }
                                            }
                                            if(feed_index - prev_feed_index == 1)
                                            {
                                                arr_cor_pos[index_counter] = 1;
                                                rep = check_if_rep(str_guess,char(counter+48));
                                                if(rep == true)
                                                {
                                                    if(arr_cor_pos[str_guess.find(char(counter+48))] == 0)
                                                    {
                                                        index_counter -= 2;
                                                    }
                                                }
                                            }
                                            cout<<endl<<"removing prev_guess: "<<prev_guess;
                                            for(int str_indx=0;str_indx<prev_guess.length();str_indx++)
                                            {
                                                if(str_guess_backup.find(prev_guess[str_indx]) == -1)
                                                {
                                                    arr_del_nums[int(prev_guess[str_indx])-48] = 1;
                                                }
                                            }
                                            cout<<endl<<"end 1: "<<str_guess;
                                            counter++;
                                        }
                                        cout<<endl<<"end of while dig is correct:\narrdelnums: "<<endl;
                                        for(int i=0;i<10;i++)
                                        {
                                            cout<<arr_del_nums[i];
                                        }
                                        cout<<endl<<"arrcospos: "<<endl;
                                        for(int i=0;i<4;i++)
                                        {
                                            cout<<arr_cor_pos[i];
                                        }
                                        cout<<endl<<"**********************************"<<endl;
                                    }
                                    
                                }
                                counter--; 
                            }
                        }
                        index_counter++;
                        first_index = false;
                        if(rep == false)
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
    cout<<endl<<"----------------------\nso this is after finding the correct digits";
    //Phase 2:Finding the correct positions
    int counter_1 = 0,counter_2 = 0;
    int cont__1[4] = {0};
    bool swap_dig = false, swap_oth = false;
    int case_0_cnt = 0;
    str_guess_backup = str_guess;
    counter_2++;
    if(feed_index==4)
    {
        cout<<endl<<"I won!!!!";
        return 0;
    }
    else if(feed_index<4)
    {
       while(1)
        {
            if(arr_cor_pos[counter_1] != 1)
            {
                if((str_guess[counter_1] != str_guess[counter_2]) && arr_cor_pos[counter_2]!=1)
                {
                        swap(str_guess[counter_1],str_guess[counter_2]);
                        break;
                }
                else
                {
                    counter_2++;
                }
            }
            else
            {
                counter_1++;
            }
        }
    }
    prev_feed_index = feed_index;
    turn++;
    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
    cout<<endl<<"Number of correct digits with correct position: ";
    cin>>feed_index;
    while(feed_index<4)
    {
        switch(feed_index - prev_feed_index)
        {
            case -2:
                cout<<endl<<"-2-2-2-2-2-2\nEntering case -2\n-2-2-2-2-2-2\n";
                //Undoing changes
                swap(str_guess[counter_1],str_guess[counter_2]);
                swap(str_guess[3-counter_1],str_guess[3-counter_2]);
                turn++;
                cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                cout<<endl<<"Number of correct digits with correct position: ";
                cin>>feed_index;
                if(feed_index == 4)
                {
                    cout<<endl<<"I won!!!!";
                    return 0;
                }
                break;
            case -1:
                cout<<endl<<"-1-1-1-1-1-1\nEntering case -1\n-1-1-1-1-1-1\n";
                //Undoing changes
                swap(str_guess[counter_1],str_guess[counter_2]);
                //str_guess[counter_1] is right
                cout<<endl<<"now assuming str_guess[counter_1] is right: "<<str_guess[counter_1];
                swap_dig = true;
                while((feed_index != 0) || (feed_index != 4))
                {
                    if(swap_dig == true)
                    {
                        cout<<endl<<"this is swap dig";
                        for(int str_indx=0;str_indx<4;str_indx++)
                        {
                            if((str_indx != counter_1) && (str_indx != counter_2) && (arr_cor_pos[str_indx] != 1))
                            {
                                cout<<endl<<"now swapping counter_2: "<<str_guess[counter_2]<<" with str_indx: "<<str_indx;
                                swap(str_guess[counter_2],str_guess[str_indx]);
                                break;
                            }
                        }
                    }
                    if(swap_oth == true)
                    {
                        cout<<endl<<"now swapping 3-counter_1: "<<str_guess[3-counter_1]<<" with 3-counter_2 "<<str_guess[3-counter_2];
                        swap(str_guess[3-counter_1],str_guess[3-counter_2]);
                    }
                    prev_feed_index = feed_index;
                    turn++;
                    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                    cout<<endl<<"Number of correct digits with correct position: ";
                    cin>>feed_index;
                    str_guess_backup = str_guess;
                    swap_dig = !(swap_dig);
                    swap_oth = !(swap_oth);
                }
                if(feed_index == 4)
                {
                    cout<<endl<<"I won!!!!";
                    return 0;
                }
                //str_guess[counter_2] is right
                cout<<endl<<"now assuming str_guess[counter_2] is right: "<<str_guess[counter_2];
                swap_dig = true;
                swap_oth = false;
                while((feed_index != 0) || (feed_index != 4))
                {
                    if(swap_dig == true)
                    {
                        cout<<endl<<"this is swap dig";
                        for(int str_indx=0;str_indx<4;str_indx++)
                        {
                            if((str_indx != counter_1) && (str_indx != counter_2) && (arr_cor_pos[str_indx] != 1))
                            {
                                cout<<endl<<"now swapping counter_2: "<<str_guess[counter_1]<<" with str_indx: "<<str_indx;
                                swap(str_guess[counter_1],str_guess[str_indx]);
                                break;
                            }
                        }
                    }
                    if(swap_oth == true)
                    {
                        cout<<endl<<"now swapping 3-counter_1: "<<str_guess[3-counter_1]<<" with 3-counter_2 "<<str_guess[3-counter_2];
                        swap(str_guess[3-counter_1],str_guess[3-counter_2]);
                    }
                    prev_feed_index = feed_index;
                    turn++;
                    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                    cout<<endl<<"Number of correct digits with correct position: ";
                    cin>>feed_index;
                    str_guess_backup = str_guess;
                    swap_dig = !(swap_dig);
                    swap_oth = !(swap_oth);
                }
                if(feed_index == 4)
                {
                    cout<<endl<<"I won!!!!";
                    return 0;
                }
                break;
            case 0:
                cout<<endl<<"000000\nEntering case 0\n000000\n";
                if(case_0_cnt == 0)
                {
                    swap(str_guess[counter_1],str_guess[3-counter_1]);
                    swap(str_guess[counter_2],str_guess[3-counter_2]);
                }
                else
                {
                    if((str_guess[counter_1]!= str_guess_backup[3-counter_1]) && (str_guess[counter_1]!= str_guess_backup[3-counter_2]))
                    {
                        swap(str_guess[counter_1],str_guess[6-counter_1 -(3- counter_1 + 3-counter_2)]);
                        swap(str_guess[counter_2],str_guess[6-counter_2 -(3- counter_1 + 3-counter_2)]);
                    }
                }
                prev_feed_index = feed_index;
                turn++;
                cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                cout<<endl<<"Number of correct digits with correct position: ";
                cin>>feed_index;
                break;
            case 1:
                cout<<endl<<"111111\nEntering case 1\n111111\n";
                //str_guess[counter_1] is right
                cout<<endl<<"now assuming str_guess[counter_1] is right: "<<str_guess[counter_1];
                swap_dig = true;
                while((feed_index != 0) && (feed_index != 4))
                {
                    if(swap_dig == true)
                    {
                        cout<<endl<<"this is swap dig";
                        for(int str_indx=0;str_indx<4;str_indx++)
                        {
                            if((str_indx != counter_1) && (str_indx != counter_2) && (arr_cor_pos[str_indx] != 1))
                            {
                                cout<<endl<<"now swapping counter_2: "<<str_guess[counter_2]<<" with str_indx: "<<str_indx;
                                swap(str_guess[counter_2],str_guess[str_indx]);
                                break;
                            }
                        }
                    }
                    if(swap_oth == true)
                    {
                        cout<<endl<<"now swapping 3-counter_1: "<<str_guess[3-counter_1]<<" with 3-counter_2 "<<str_guess[3-counter_2];
                        swap(str_guess[3-counter_1],str_guess[3-counter_2]);
                    }
                    prev_feed_index = feed_index;
                    turn++;
                    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                    cout<<endl<<"Number of correct digits with correct position: ";
                    cin>>feed_index;
                    str_guess_backup = str_guess;
                    swap_dig = !(swap_dig);
                    swap_oth = !(swap_oth);
                }
                if(feed_index == 4)
                {
                    cout<<endl<<"I won!!!!";
                    return 0;
                }
                //str_guess[counter_2] is right
                cout<<endl<<"now assuming str_guess[counter_2] is right: "<<str_guess[counter_2];
                swap_dig = true;
                swap_oth = false;
                while((feed_index != 0) && (feed_index != 4))
                {
                    if(swap_dig == true)
                    {
                        cout<<endl<<"this is swap dig";
                        for(int str_indx=0;str_indx<4;str_indx++)
                        {
                            if((str_indx != counter_1) && (str_indx != counter_2) && (arr_cor_pos[str_indx] != 1))
                            {
                                cout<<endl<<"now swapping counter_2: "<<str_guess[counter_1]<<" with str_indx: "<<str_indx;
                                swap(str_guess[counter_1],str_guess[str_indx]);
                                break;
                            }
                        }
                    }
                    if(swap_oth == true)
                    {
                        
                        cout<<endl<<"now swapping 3-counter_1: "<<str_guess[3-counter_1]<<" with 3-counter_2 "<<str_guess[3-counter_2];
                        swap(str_guess[3-counter_1],str_guess[3-counter_2]);
                    }
                    prev_feed_index = feed_index;
                    turn++;
                    cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                    cout<<endl<<"Number of correct digits with correct position: ";
                    cin>>feed_index;
                    str_guess_backup = str_guess;
                    swap_dig = !(swap_dig);
                    swap_oth = !(swap_oth);
                }
                if(feed_index == 4)
                {
                    cout<<endl<<"I won!!!!";
                    return 0;
                }
                break;
            case 2:
                cout<<endl<<"222222\nEntering case 2\n222222\n";
                swap(str_guess[counter_1],str_guess[counter_2]);
                turn++;
                cout<<endl<<"Turn: "<<turn<<"  Guess: "<<str_guess;
                cout<<endl<<"Number of correct digits with correct position: ";
                cin>>feed_index;
                if(feed_index == 4)
                {
                    cout<<endl<<"I won!!!!";
                    return 0;
                }
                break;
        }
    }
    return 0;
}
