#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool signin();
void signup();
void view_tweet();
void add_tweet();

int main() {
	int option;
	cout << "-------------------Login Page-----------------------"<<endl;
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
			cout << "Press 1 for Add Tweet "<<endl;
			cin >> option;

			if (option == 1)
			{
				system("CLS");
				add_tweet();
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
			cout << "Invalid Option "<<endl;
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
		/*cout << "Username is not found " << endl;*/
	}
}
// Signup function
void signup()
{
	bool flag = false;
	fstream myfile, MypasswordFile;
	string username_out, pass_out;
	string line;
	myfile.open("user.txt");
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

		}
		if (flag)
		{
			system("color 4");
			cout << "Username Is taken " << endl;
		}
		else {
			system("color 2");
			myfile << username_out << endl;
			cout << "Username has been saved";
			myfile.close();
			flag = false;
			MypasswordFile.open("password.txt");
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

				}
				if (flag)
				{
					system("color 4");
					cout << "Password Is taken " << endl;
				
				}
				else {
					system("color 2");

					MypasswordFile << pass_out << endl;
					cout << "Your Account has been created";
				}

			}
			MypasswordFile.close();
		}
		

	}
	
	
	return;
}

void view_tweet()
{
	fstream tweet_file;
	string line;
	tweet_file.open("tweet.txt", ios::in);
	if (tweet_file.is_open())
	{
		while (getline(tweet_file, line))
		{
			cout << line << endl;
		}
	}
	tweet_file.close();
}
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
			add_tweet << add[i]<<' ';
		}
	}
}
