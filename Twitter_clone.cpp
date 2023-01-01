#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool signin();
void signup();
void view_tweet();
void add_tweet();
void Follower();

int main() {
		int option;


		cout << "-------------------Login Page-----------------------" << endl;
		cout << "Press 1 For Sign in " << endl;
		cout << "Press 2 For Sign Up" << endl;

		cout << "\nEnter Option ";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			system("CLS");
			cout << "-----------------Signin Page---------------------" << endl;
			if (signin())
			{
				system("CLS");
				view_tweet();
				cout << endl << endl;
				cout << "Press 1 for Add Tweet: " << endl;
				cout << "Press 2 For follow a user: " << endl;
				cout << "\nEnter you choice: ";
				cin >> option;

				if (option == 1)
				{
					system("CLS");
					add_tweet();
				}
				else if (option == 2)
				{
					system("CLS");
					Follower();

				}
			}
		}
		break;

		case 2:
		{
			system("CLS");
			signup();

		}
		break;
		default:
			cout << "Invalid Option " << endl;
			cout << "Try again";
		}
	
}
//Signin Function
bool signin()
{
	string user, pass;
	ifstream myfile, MypasswordFile;

	myfile.open("user.txt", ios::in);
	if (myfile.is_open())
	{
		cout << "Username = ";
		cin >> user;
		string line;
		while (getline(myfile, line))
		{
			if (user == line)
			{
				myfile.close();

				MypasswordFile.open("password.txt", ios::in);
				if (MypasswordFile.is_open())
				{
					cout << "password = ";
					cin >> pass;
					while (getline(MypasswordFile, line))
					{
						if (pass == line)
						{
							
							return true;

						}
					

					}
				}
				MypasswordFile.close();
			}

		}
		cout << "Username is not found " << endl;
	}
}
// Signup function
void signup()
{
	bool flag = false;
	fstream myfile, MypasswordFile;
	string username_out, pass_out;
	string line;
	myfile.open("user.txt", ios::in | ios::app); 
	if (myfile.is_open())
	{
		cout << "------------------Create A New account!-----------------" << endl;
		cout << "Enter username: ";
		cin >> username_out;
		while (getline(myfile, line))
		{
			if (username_out == line)
			{
				flag = true;
			}
			if (!flag)
			{
				system("color 2");
				myfile << username_out << endl;
			}
		}
		if (flag)
		{
			system("color 4");
			cout << "Password Is taken " << endl;

		}
	}
	myfile.close();
	flag = false;
	MypasswordFile.open("password.txt", ios::in | ios::app);
	if (MypasswordFile.is_open())
	{
		cout << "\nEnter Password: ";
		cin >> pass_out;
		while (getline(MypasswordFile, line))
		{
			if (pass_out == line)
			{
				flag = true;
			}
			if (!flag)
			{
				system("color 2");
				MypasswordFile << pass_out << endl;

			}

		}
		if (flag)
		{
			system("color 4");
			cout << "Password Is taken " << endl;
			
		}
	}
	MypasswordFile.close();
	return;
}


void view_tweet()
{
	int count = 0;
	fstream tweet_file;
	string line;
	tweet_file.open("tweet.txt", ios::in);
	if (tweet_file.is_open())
	{
		while (getline(tweet_file, line))
		{
			if (count < 12) {
				cout << line << endl;
			}
			count++;
		}
	}
	tweet_file.close();
}
//Add tweets in to first page function
void add_tweet() {
	fstream add_tweet;
	string add[5];
	int i;

	add_tweet.open("tweet.txt", ios::app);
	if (add_tweet.is_open())
	{
		cout << "Your Tweet Must Be 180 character!" << endl;
		cout << "Type Your Tweet " << endl;
		for (i = 0; i < 5; i++)
		{
			cin >> add[i];
			add_tweet << add[i]<<" ";
		}
		system("pause");
		
	}
}

//this function check username to follow and if the user name exist then add username in the follower file else display error;
void Follower() {
	fstream myfile,followers_file;
	string user_name,line;
	bool flag = false;
	cout << "Enter username you want to follow:  ";
	cin >> user_name;

	myfile.open("user.txt", ios::in);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (user_name == line) {
				flag = true;
			
			}
		}
	}
	myfile.close();

		if (flag)
		{
			cout << "You follow " << user_name;
			followers_file.open("followers.txt", ios::app);
			if (followers_file.is_open())
			{
				followers_file << user_name;
			}

			
		}
		else {
			cout << "Username is not valid";
		}
}
