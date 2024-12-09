#include <iostream>
#include <string>

using namespace std;

// makes key the same length as the input text
string makeKey(const string& text, const string& key)
{
    string modifiedKey = key;      
    while (modifiedKey.size() < text.size())
    {
        modifiedKey += key;                     
    }
    return modifiedKey.substr(0, text.size()); 
}

//encrypts message
string encrypt(const string& text, const string& key)
{
 
    string encryptedText = "";     
    string modifiedKey = makeKey(text, key);

    for (size_t i = 0; i < text.size(); i++)        
    {
        if (text[i] == ' ')
        {
            encryptedText.push_back(' ');
            continue;
        }

		int x = (text[i] + modifiedKey[i]) % 26;
		x += 'A';

		encryptedText.push_back(x);
    }
    return encryptedText;
}

// function to decrypt
string decrypt(const string& encryptedText, const string& key)
{
    string originalText = "";
    string modifiedKey = makeKey(encryptedText, key);

    for (size_t i = 0; i < encryptedText.size(); i++)
    {
        if (encryptedText[i] == ' ')
        {
            originalText.push_back(' ');
            continue;
        }
        int x = (encryptedText[i] - modifiedKey[i] + 26) % 26;
		x += 'A';

        originalText.push_back(x);
    }
    return originalText;
}

int main()
{
    string text;
    string keyword;
    int choice;
     
	string encryptedText = "";

    cout << "welcome to the this viginere cipher program\n";
    cout << "please chose one of the following by entering 1, 2, or 3  \n";
    cout << "1. Encrypt a message\n";
    cout << "2. Decrypt a message\n";
    cout << "3. Exit\n";

        cin >> choice;
        do
        {
            if (choice == 1) // encrypts
            {
                cout << "Enter the text you want to encrypt using (uppercase letters): ";
                cin.ignore();
                getline(cin, text);
                cout << "Enter the keyword (upppercase letters): ";
                getline(cin, keyword);
                cout << "Encrypted Text: " << encrypt(text, keyword) << endl << endl;

                cout << "please choose again by entering 1, 2, or 3  \n";
				cin >> choice;
            }
            else if (choice == 2) // decrypts
            {
                cout << "Enter the text you want to decrypt (uppercase letters): ";
                cin.ignore();
                getline(cin, encryptedText);
                cout << "Enter the keyword (uppercase letters): ";
                getline(cin, keyword);
                cout << "Decrypted Text: " << decrypt(encryptedText, keyword) << endl << endl;

                cout << "please choose again by entering 1, 2, or 3  \n";
				cin >> choice;
            }
            else if (choice == 3) // exit
            {
                cout << "Goodbye\n";
               
            }
            else
            {
                cout << "Invalid choice, please try again\n";
				cin >> choice;
            }
        } while (choice !=3);
}