#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main() {
	string username, password;
	int option;
	fstream myfile;

	cout << "Press 1 For Sign in " << endl;
	cout << "Press 2 For Sign Up" << endl;

	cout << "\n Enter Option ";
	cin >> option;
	switch (option)
	{
		case 1:
		{
		system("CLS");
		myfile.open("user.txt", ios::in);
		if (myfile.is_open())
		{
			cout << "Username = ";
			cin >> username;
			string line;
			while (getline(myfile, line))
			{
				if (username == line)
				{
					cout << "password = ";
					cin >> password;
					while (getline(myfile, line))
					{
						if (password == line)
						{
							system("CLS");
							cout << "Welcome To console Based Twitter";
						}
						else
						{
							cout << "Invalid Password ";
						}
					}
				}

			}
			cout << "Username is not found " << endl;

		}
		
		}
		break;
		
		case 2:
		{
			system("CLS");
		}
	}


}