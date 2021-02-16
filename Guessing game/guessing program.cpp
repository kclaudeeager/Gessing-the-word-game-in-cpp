/*
REG NO                            NAMES
219003851                         KWIZERA CLAUDE
219001792                         IRADUKUNDA Mia Benitha
219010410                         URAKAZA    Feza

*/

#include<iostream>//including input and output stream
#include<fstream>//including file library
#include<vector> //including vector library
#include<random>//including randomisation
#include<string>//including strings
#include<ctime>//including c string library
using namespace std;//
vector<string> get_text(ifstream& get)//a funtion that puts the file into a vector and returns the vector
{
	vector<string> strings;
	string d;
	while (get >> d) {
		strings.push_back(d);
	}
	return strings;
}
string select(vector<string> s)//a funtion that returns the randomly selected word in all file
{
	srand(time(0));//initialition of time as zero to allow different random selection
	int random;
	string line;
	random = rand() % s.size();
	line = s[random];
	//cout<<random<<line <<endl;
	return line;


}
check_true(string k)//the function that takes the word and allows the user to guess
{
	char a;//the character guessed
	string word;
	vector<string> d;
	string array;
	string line1;
	line1 = k;
	int i;
	int j;
	for (i = 0; i < line1.size(); i++)
	{
		array[i] = '*';//hiding then word as stars
		cout << array[i];
	}
	cout << endl;
	for (j = 0; j < 2 * line1.size(); j++)//the loop which allows to guess 2 timess the length of the word
	{

		word = "";
		cout << "\n keep guessing\n";
		cin >> a;

		//the guessed character

		//system(CLs);
		/*if(cin.bad())
		{
			cout << "one char please";
			continue;
		}*/
		int f = 0;//variable to count the occurance of the letter

		for (i = 0; i < line1.length(); i++)//a loop that checks whether the letter guessed includes in the hiden word a nd replaces that letter into the word where that letter should be 
		{
			if (a == line1[i]) {
				f++;
				if (a == array[i])//the condition to check if the character already used
				{
					cout << "char already used \n";
					system("cls");
					break;

				}


				array[i] = a;

			}


		}
		if (f == 0)//the condition to check if the letter includes in the picked word
		{
			system("cls");
			cout << "char not found try again \n";

			for (int i = 0; i < line1.size(); i++)
				cout << array[i];
			continue;
		}
		for (i = 0; i < line1.length(); i++)//the loop that adds all the letters to make a word if the guesed letter are in the word
		{
			cout << array[i];
			word += array[i];
		}

		if (word == line1)//condition that checks whether the word has been fully discorved
		{
			system("cls");
			cout << "\n you got it!!";
			exit(0);
		}

	}
	if (j == line1.length() * 2)//the condition that stops a user to guesse after the trial chance has finished
	{
		cout << "\n you lost! have a break" << endl;
		cout << "The word was :";

		cout << line1;

		exit(1);
	}
}
int main()//main function to call all functions
{

	cout << endl << "ENTER THE LETTERS YOU THINK CAN MAKE THE HIDEN WORD BELOW \n";
	vector<string> strings;
	ifstream ff;//reading the file
	ff.open("file1.txt");//openning the file
	string d;
	if (!ff)//checking if the file exists
	{

		cout << "loss of allocation \n";
	}
	strings = get_text(ff);//called functions
	string h = select(strings);
	check_true(h);
}
