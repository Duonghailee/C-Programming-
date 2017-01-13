#include <iostream> // std:cout
#include <list>
#include <vector>
#include <algorithm> //std::search
using namespace std;

//define struct
struct Books
{
    char title[50];
    char author[50];

    //overload == operator to compare books
    bool operator==(const Books &b) const
    {
        return ((strcmp(b.title, title) == 0) && (strcmp(b.author, author) == 0));
    }
};

//intro
void display()
{
    cout << "\n\na. Add a book.\nb. Remove a book.\nc. Empty database.\nd. Show the number of books currently in database.\ne. Quit.\n\n";
}

int main()
{
    //define vector store book struct
    std::vector<Books> v;
    std::vector<Books>::iterator it;

    //display introduction
    cout << "********* Welcom to database ********* " << endl;
    char choice;
    char name[50];
    char author[50];
    do
    {
        //intro database
        display();

        //enter choice from user
        cout << "Please enter a choice: ";
        cin >> choice;

        //switch case a-e
        switch (choice)
        {
        case 'a':
            Books newBook;

            cout << "Please enter the name of the book: ";
            cin >> name;
            strcpy(newBook.title, name);

            cout << "Please enter the author of the book: ";
            cin >> author;
            strcpy(newBook.author, author);

            //adding book
            v.push_back(newBook);
            cout << "The book has been added.";
            break;

        case 'b':
            //check empty database
            if (v.size() == 0)
            {
                cout << "Sorry ther is no book to remove, please add one...\n";
            }

            //now find the book to remove
            else
            {
                Books deleteBook;

                cout << "Please enter the name of the book: ";
                cin >> name;
                strcpy(deleteBook.title, name);

                cout << "Please enter the author of the book: ";
                cin >> author;
                strcpy(deleteBook.author, author);

                it = find(v.begin(), v.end() + 1, deleteBook);
                if (it != v.end()) //book found
                {
                    v.erase(it);
                    cout << "The book has been removed\n";
                }
                else
                {
                    cout << "Book not found\n";
                }
            }

            break;

        case 'c':
            v.clear();
            cout << "Data base emptied\n";
            break;

        case 'd':
            cout << "The number of books currently in the database: ";
            cout << v.size() << "." << endl;
            break;

        case 'e':
            cout << "Bye." << endl;
        }

    } while (choice != 'e');
    return 0;
}