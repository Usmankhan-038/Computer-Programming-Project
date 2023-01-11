#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
bool signin();  
void signup();
void view_tweet();
void add_tweet();
void Follower();
void like_tweet();
int show_account();
int follower = 0, like =  0;
string currentuser, current_user_follow[100],current_user_like_tweet[100];
struct users {        //This Structure is use in signin and signup function
    string username;
    string password;
    string follows;

};

struct usertweet            //This Structure is use in viewtweet and addtweet function
{                       
    string tweets;
    string username;
};

int main() {
    bool main_exit = false;

    while (!main_exit) {
        system("CLS");
        bool tweet_exit = false;
        string option, choice;
        int add_tweet_option = 0, follow_user_option = 0, like_tweet_option = 0, account_option = 0;

        system("color 8e");
        cout << "\n************************************************************************************************************************" << endl;
        cout << "                                                    ---> Login Page <---                                        " << endl;
        cout << "\n************************************************************************************************************************" << endl;
        cout << "\nPress 1 For Signin " << endl;
        cout << "Press 2 to Creat New Account " << endl;
        cout << "Press 3 For Exit " << endl;

        cout << "\nEnter Option ";
        cin >> option;
        
       
        if(option=="1")
        {
            system("CLS");
            cout << "\n************************************************************************************************************************" << endl;
            cout << "                                             ---> Signin Page <---                                       " << endl;
            cout << "\n************************************************************************************************************************" << endl;
            if (signin())
            {
                while (!tweet_exit)
                {
                    bool add_tweet_exit = false, follow_exit = false, like_exit = false, account_exit = false;

                    system("CLS");
                    cout << "\n************************************************************************************************************************" << endl;
                    cout << "                                         ---> WELCOME TO CONSOLE TWITTER <---                                          " << endl;
                    cout << "\n************************************************************************************************************************" << endl;
                    view_tweet();
                    cout << endl;
                    cout << "Press 1 for Add Tweet: " << endl;
                    cout << "Press 2 For follow a user: " << endl;
                    cout << "Press 3 For like a tweet: " << endl;
                    cout << "Press 4 to Show Account: " << endl;
                    cout << "Press 5 for Logout:" << endl;
                    cout << "\nEnter you choice: ";
                    cin >> choice;

                    if (choice == "1")
                    {
                        while (!add_tweet_exit)
                        {
                            system("CLS");
                            cout << "\n************************************************************************************************************************" << endl;
                            cout << "                                          ---> Add Tweet  <---                                      " << endl;
                            cout << "\n************************************************************************************************************************" << endl;
                            add_tweet();
                            cout << "\n1. Back To main menu" << endl;
                            cout << "2. Logout" << endl;
                            cout << "3. To add another tweet" << endl;
                            cout << "Enter Option: ";
                            cin >> add_tweet_option;
                            if (add_tweet_option == 3)
                            {
                                continue;
                            }
                            else
                            {
                                add_tweet_exit = true;
                            }
                        }
                    }
                    else if (choice == "2")
                    {

                        while (!follow_exit)
                        {
                            system("CLS");
                            cout << "\n************************************************************************************************************************" << endl;
                            cout << "                                        ---> Follow Your Favorite Username  <---                                      " << endl;
                            cout << "\n************************************************************************************************************************" << endl;
                            Follower();
                            cout << "\n1. Back To main menu" << endl;
                            cout << "2. Logout" << endl;
                            cout << "3. Follow Other User" << endl;
                            cout << "Enter Option: ";
                            cin >> follow_user_option;
                            if (follow_user_option == 3)
                            {
                                continue;
                            }
                            else
                            {
                                follow_exit = true;
                            }


                        }

                    }
                    else if (choice == "3")
                    {

                        while (!like_exit)
                        {
                            system("CLS");
                            cout << "\n************************************************************************************************************************" << endl;
                            cout << "                                         ---> Like Your Favorite Tweet  <---                                       " << endl;
                            cout << "\n************************************************************************************************************************" << endl;
                            like_tweet();
                            cout << "1. Back To main menu" << endl;
                            cout << "2.  LogOut" << endl;
                            cout << "3. like Other tweets" << endl;
                            cout << "Enter Option: ";
                            cin >> like_tweet_option;
                            if (follow_user_option == 3)
                            {
                                continue;
                            }
                            else
                            {
                                like_exit = true;
                            }

                        }

                    }
                    else if (choice == "4")
                    {
                        while (!account_exit)
                        {

                            system("CLS");
                            cout << "\n************************************************************************************************************************" << endl;
                            cout << "                                              ---> Your Account <---                                      " << endl;
                            cout << "\n************************************************************************************************************************" << endl;
                            if (show_account()){
                                cout << "1. Back To main menu" << endl;
                                    cout << "2. Logout" << endl;
                                    cout << "3. Continue" << endl;
                                    cout << "Enter Option: ";
                                    cin >> account_option;
                                    if (account_option == 3)
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        account_exit = true;
                                    }
                            }
                            else
                            {
                                account_exit = true;
                            }
                        }



                    }
                    else if (choice == "5")
                    {
                        system("CLS");
                        tweet_exit = true;
                    }

                    if (add_tweet_option == 2 || follow_user_option == 2 || like_tweet_option == 2 || account_option == 2)
                    {
                        system("CLS");
                        break;
                    }
                }
            }
        }else if(option=="2")
        {
           
            system("CLS");
            cout << "\n************************************************************************************************************************" << endl;
            cout << "                                         ---> Create Your Account <---                                      " << endl;
            cout << "\n************************************************************************************************************************" << endl;
            signup();
            system("pause");

        }
        else if (option == "3")
        {
            main_exit = true;

        }
        else
        {
            cout << "Invalid Option " << endl;
            cout << "Try again"<<endl;
            system("pause");
        }
        
    }

}


//Signin Function
bool signin()
{
    users pass;
    ifstream myfile;
    int i = 0, choice;
    string line;
    string username_and_pass[100] = { " " };
    myfile.open("user.txt", ios::in);
    if (myfile.is_open())
    {
        while (getline(myfile, line, ','))
        {
            username_and_pass[i] = line;
            i++;
        }



        while (1)
        {
            bool flag_username = false;
            bool flag_password = false;
            int count = 0;
            cin.ignore();
            cout << "Username: ";
            getline(cin, currentuser);
            
            while (count <= i)
            {

                if (username_and_pass[count] == currentuser)
                {

                    cout << "password: ";
                    cin >> pass.password;
                    
                    for (int k = 0; k <= i; k++)
                    {
                        if (pass.password == username_and_pass[k])
                        {
                            flag_password = true;
                        }
                    }

                    flag_username = true;
                }
                count++;
            }
            if (flag_username == true && flag_password == true)
            {
                return true;
            }
            else
            {
                cout << "Password or username is not found " << endl;
                cout << "Do You want to continue or Exit" << endl;
                cout << "1.Continue" << endl;
                cout << "2.Exit" << endl;
                cout << "Enter you Option: ";
                cin >> choice;
                if (choice == 1)
                {
                    continue;
                }
                else if (choice == 2)
                {
                    system("CLS");
                    return false;
                    break;
                }
            }
        }


    }
    myfile.close();
}


// Signup function
void signup()
{

    fstream myfile;
    int choice;
    users obj;
    string line, line1;
    bool flag_user_name = false, flag_pass = false;
    myfile.open("user.txt", ios::in);
    if (myfile.is_open())
    {
        cin.ignore();
        cout << "\nEnter username: ";
        getline(cin, obj.username);
        while (getline(myfile,line, ','))
        {
           
            if (obj.username == line)
            {
                flag_user_name = true;
            }

        }
        if (!flag_user_name)
        {

            cout << "\nEnter Password: ";
            cin >> obj.password;
            while (getline(myfile, line1, ','))
            {
                if (obj.password == line1)
                {
                    flag_pass = true;
                }
            }
            if (flag_pass)
            {
                system("color 4b");
                cout << "Password Is taken" << endl;


            }
            else
            {
                system("color 2b");
                flag_pass = false;
            }

        }
    }
    myfile.close();
    myfile.open("user.txt", ios::app);
    if (myfile.is_open())
    {
        if (flag_user_name)
        {


            system("color 4b");
            cout << "username or password Is taken " << endl;

        }
        else if (flag_user_name == false && flag_pass == false)
        {
            system("color 2b");
            myfile << endl;
            myfile << "," << obj.username << "," << obj.password << ",";
        }



    }
    myfile.close();


    return;
}
// view tweet
void view_tweet()
{
    fstream followers_tweets, user_tweets;
    string line, line1, line4;
    usertweet tweets[100] = { " " };
    users user[10], follow[10];
    int count = 0, i = 0, k = 0, m = 0;

    fstream followers;
    string line3;
    string username, Follow;
    followers.open("followers.txt");
    if (followers.is_open())
    {
        while (!followers.eof())
        {
            getline(followers, line3);
            size_t pos = line3.find(",");
            username = line3.substr(0, pos);
            if (username == ::currentuser)
            {
                Follow = line3.substr(pos + 1);
                current_user_follow[i] = Follow;
                follower++;
                i++;
            }
        }
    }
    followers.close();
    i = 0;
    user_tweets.open("user_tweet.txt", ios::in);
    if (user_tweets.is_open())
    {
        while (getline(user_tweets, line))
        {
            string username, tweet;
            size_t position= line.find(",");
            username = line.substr(0, position);
            tweet = line.substr(position + 1);

            tweets[count].username = username;
            tweets[count].tweets = tweet;
            count++;
        }
        user_tweets.close();
        int tweetnum = 1;
        int j = 0;
        while (j < ::follower)
        {
            
            line4 = current_user_follow[j];
            while (i < count && i <= 10)
            {
                if (tweets[i].username == line4)
                {
                    cout << tweets[i].username << endl;
                    if (tweets[i].tweets.length() <= 60)
                    {
                        string line = tweets[i].tweets.substr(0, 60);
                        cout << line << endl;
                        cout << tweetnum << endl;
                    }
                    else if (tweets[i].tweets.length() > 60 && tweets[i].tweets.length() < 120)
                    {
                        string line = tweets[i].tweets.substr(0, 60);
                        string line1 = tweets[i].tweets.substr(60, 60);
                        cout << line << endl;
                        cout << line1 << endl;
                        cout << tweetnum << endl;
                    }
                    else if (tweets[i].tweets.length() > 120 && tweets[i].tweets.length() < 180)
                    {
                        string line = tweets[i].tweets.substr(0, 60);
                        string line1 = tweets[i].tweets.substr(60, 60);
                        string line2 = tweets[i].tweets.substr(120, 60);
                        cout << line << endl;
                        cout << line1 << endl;
                        cout << line2 << endl;
                        cout << tweetnum << endl;
                    }
                     tweetnum++;
                    cout << endl;
                    m++;
                }

                i++;
            }
            j++;
        }
        i = count-1;
        k=0;
        j = 0;
        /*   tweets[2].tweets = "like " + to_string(like) + " follower " + to_string(followers);*/

        while (k < count && k <= 10 - m )
        {
          

                if (!(tweets[i].username == current_user_follow[j]))
                {
                    cout << tweets[i].username << endl;
                    if (tweets[i].tweets.length() <= 60)
                    {
                        string line = tweets[i].tweets.substr(0, 60);
                        cout << line << endl;
                        cout << tweetnum << endl;
                    }
                    else if (tweets[i].tweets.length() > 60 && tweets[i].tweets.length() < 120)
                    {
                        string line = tweets[i].tweets.substr(0,60);
                        string line1 = tweets[i].tweets.substr(60, 60);
                        cout << line << endl;
                        cout << line1 << endl;
                        cout << tweetnum << endl;
                    }
                    else if (tweets[i].tweets.length() > 120 && tweets[i].tweets.length() < 180)
                    {
                        string line = tweets[i].tweets.substr(0,60);
                        string line1 = tweets[i].tweets.substr(60, 60);
                        string line2 = tweets[i].tweets.substr(120, 60);
                        cout << line << endl;
                        cout << line1 << endl;
                        cout << line2 << endl;
                        cout << tweetnum << endl;
                    }
                    tweetnum++;
                    cout << endl;
                    k++;

                }
                if (current_user_follow[j] == tweets[i].username)
                {
                    j++;
                }
            i--;
           

        }
    }

    user_tweets.close();
}
//Add tweets in to first page function
void add_tweet() {
    fstream add_tweets_file;
    usertweet adding_tweets;
    int i = 1, choice;
    bool exit = false;

    add_tweets_file.open("user_tweet.txt", ios::app);
    if (add_tweets_file.is_open())
    {

        cout << "Your Tweet Must Be 180 character!" << endl;
        while (i >= 1) {
            cin.ignore();
            cout << "Type Your Tweet " << endl;
            getline(cin, adding_tweets.tweets);
            int str_length = adding_tweets.tweets.length();
            if (str_length <= 180) {
                add_tweets_file << currentuser << ",";
                for (int i = 0; i < str_length; i++)
                {
                    add_tweets_file << adding_tweets.tweets[i];
                }
                add_tweets_file << endl;
                break;
            }
            else {
                cout << "Your Tweet Must be 180 character" << endl;
                cout << "Do You Want To Continue or Exit" << endl;
                cout << "1.Continue" << endl;
                cout << "2.Exit" << endl;
                cout << "Enter Option: ";
                cin >> choice;
                if (choice == 1)
                {
                    continue;

                }
                else if (choice == 2)
                {
                    break;
                }
            }

        }
    }
    add_tweets_file.close();
}

//this function check username to follow and if the user name exist then add username in the follower file else display error;
void Follower() {
    fstream user_file, followers_file;
    string line, user_follow;
    bool flag = false;
    string user_file_data[100];
    int i = 0;

    cout << "Enter username you want to follow: ";
    cin >> user_follow;

    user_file.open("user.txt", ios::in);
    if (user_file.is_open())
    {
        while (getline(user_file, line, ','))
        {

            if (user_follow == line) {
                flag = true;

            }

        }
    }

    fstream followers;
    string line3;
    string username, Follow;
    followers.open("followers.txt");
    if (followers.is_open())
    {
        while (!followers.eof())
        {
            getline(followers, line3);
            size_t pos = line3.find(",");
            username = line3.substr(0, pos);
            if (username == ::currentuser)
            {
                Follow = line3.substr(pos + 1);
                current_user_follow[i] = Follow;
                follower++;
                i++;
            }
        }
    }
    int j = 0;
    while (j < follower)
    {
        if (user_follow == current_user_follow[j])
        {
            cout << "\nYou Already Follow This Username" << endl;
            flag = false;

        }
        j++;
    }
    if (user_follow == ::currentuser)
    {
        cout << "You Cannot Follow yourself" << endl;
        flag = false;
    }
    if (flag)
    {
        cout << "You follow " << user_follow;
        followers_file.open("followers.txt", ios::app);
        if (followers_file.is_open())
        {

            followers_file << currentuser << "," << user_follow << endl;
            follower++;
        }
    }
    else {
        cout << "Username is not valid" << endl;
    }
    followers_file.close();
}
void like_tweet()
{
    fstream user_file, like_tweets_file, shows_like_userfile;
    string user_name, line;
    bool flag = false;
    cout << "Enter username you want to like the tweet:  ";
    cin >> user_name;

    user_file.open("user.txt", ios::in);
    if (user_file.is_open())
    {
        while (getline(user_file, line, ','))
        {
            if (user_name == line)
            {
                flag = true;
            }
        }
    }
    user_file.close();

    if (flag)
    {
        cout << "You like " << user_name << " tweet!!";
        like_tweets_file.open("like_tweet.txt", ios::app);
        if (like_tweets_file.is_open())
        {
            like_tweets_file << ::currentuser << "," << user_name << endl;
            like++;
        }

    }
    else {
        cout << "Username is not valid";
    }

}
int show_account()
{
    fstream followers, like_file,user_file;
    usertweet tweets[100] = { " " };
    string line3, line4;
    string username, Follow, like_tweet, current_user_follows[10], current_user_like_tweet[10], current_user_like_tweet_2[10];
    int i = 0, choice, j = 0, following = 0, current_user_followers = 0;
    followers.open("followers.txt");
    if (followers.is_open())
    {
        while (!followers.eof())
        {
            getline(followers, line3);
            size_t comma_position = line3.find(",");
            username = line3.substr(0, comma_position);
            if (username == ::currentuser)
            {
                Follow = line3.substr(comma_position + 1);
                current_user_follow[i] = Follow;

                following++;
                i++;
            }
            if (username != ::currentuser)
            {
                Follow = line3.substr(comma_position + 1);
                if (Follow == ::currentuser)
                {
                    current_user_follows[j] = username;
                    current_user_followers++;
                    j++;
                }

            }
        }
    }
    i = 0;
    j = 0;
    like_file.open("like_tweet.txt", ios::in);
    if (like_file.is_open())
    {
        while (!like_file.eof())
        {
            getline(like_file, line3);
            size_t comma_position = line3.find(",");
            username = line3.substr(0, comma_position);
            if (username == ::currentuser)
            {
                like_tweet = line3.substr(comma_position + 1);
                current_user_like_tweet[i] = like_tweet;

                like++;
                i++;
            }
            if (username != ::currentuser)
            {
               
                like_tweet = line3.substr(comma_position + 1);
                if (Follow == ::currentuser)
                {
                    current_user_like_tweet_2[j] = username;
                    cout << current_user_like_tweet_2[j];
                    j++;
                }

            }

            
        }
    }
    

    j = 0;
    cout <<"Username : " << currentuser << endl;
    cout << "Following  " << following << endl;
    cout << "Follower  " << current_user_followers << endl;
    cout << "Like Tweet " << like << endl;
    cout << "Press 1 to Show Following List: " << endl;
    cout << "Press 2 to Show Follower List: " << endl;
    cout << "Enter Option: ";
    cin >> choice;
    if (follower > 0)
    {
        if (choice == 1)
        {
            cout << endl;
            cout << "You Followed " << endl;
            cout << endl;
            while (j < following)
            {

                cout << current_user_follow[j] << endl;
                j++;
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            j = 0;
            cout << endl;
            cout << "Yours Followers " << endl;
            cout << endl;
            while (j < current_user_followers)
            {
                cout << current_user_follows[j] << endl;
                j++;
            }
            cout << endl;
        }
        
        return 1;
    }
    else
    {
        cout << "You have no followers yet" << endl;
        return 1;
    }
    if (choice == 3)
    {
        return 0;
    }
}
