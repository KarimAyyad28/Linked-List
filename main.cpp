#include <iostream>
#include <string>
using namespace std;
struct LinkedList {
    float data;
    LinkedList *Next;
};
LinkedList* Header= NULL;
void add();
void dlt();
void view();
void edt();
int main() {
    char ch;
    while (1) {
        cout << "Enter your choice: \n 1 Add \n 2 Delete \n 3 View \n 4 Edit \n";
        cin >> ch;
        switch (ch) {
            case '1': {
                add();
                break;
            }
            case '2': {
                dlt();
                break;
            }
            case '3': {
                view();
                break;
            }
            case '4': {
                edt();
                break;
            }
        }
    }
}
void add()
{   int ch;
    float x;
    LinkedList *newNode,*newPtr;
    newNode = new LinkedList;
    cout << "Enter the value : \n" ;
    cin >> x;
    newNode->data = x;
    newNode->Next=NULL;
    if (!Header)
    {Header = newNode; cout << "Done\n";}
    else {
        cout << "Where do you want to add it ?\n 1 in the beginning \n 2 in the middle \n 3 in the end\n";
        cin >> ch;
        switch (ch) {
            case 1: {
                newNode->Next = Header;
                Header = newNode;
                cout << "Adding to the beginning done\n";
                break;
            }
            case 2: {
                int pos;
                cout << "After which node do you like to add ? \n";
                cin >> pos;
                pos--;
                newPtr = Header;
                for (int i = 0; i < pos; i++) { newPtr = newPtr->Next; }
                newNode->Next = newPtr->Next;
                newPtr->Next = newNode;
                cout << "Adding to the centre done\n";
                break;
            }
            case 3: {
                newPtr = Header;
                while (newPtr->Next)
                    newPtr = newPtr->Next;
                newPtr->Next = newNode;
                cout << "Adding to the end done\n";
                break;
            }
        }
    }
  return;
}
void view() {
    LinkedList *newPtr;
    newPtr = Header;
    if (!Header) {
        cout << "The linked list is empty \n";
        return;
    }
    cout << "The LL elements are \n";
    while (newPtr) {
        cout << newPtr->data << "=>";
        newPtr = newPtr->Next;
    }
    cout << endl;
}
void dlt(){
    if (!Header) {cout <<"Linked List is empty \n"; return;}
    LinkedList *newPtr1, *newPtr2;
    cout << "Which node do you want to delete ?\n 1  the beginning \n 2 in the middle \n 3 the last\n";
    int ch;
    cin >> ch;
    switch (ch)
    {case 1 :
            {   newPtr1= Header;
                Header= Header->Next;
                delete newPtr1;
                cout << "Deleting done\n";
                return;
            }
     case 2 :
            {   int pos;
                cout << " Which node do you like to delete ? \n";
                cin >> pos;
                pos--;
                newPtr1 = Header;
                for (int i = 0; i < pos; i++)
                { newPtr2= newPtr1;
                  newPtr1 = newPtr1->Next; }
                newPtr2->Next = newPtr1->Next;
                delete newPtr1;
                cout << "Deleting done\n";
                break;}
     case 3:
            {   newPtr1 = Header;
                while (newPtr1->Next) {
                    newPtr2= newPtr1;
                    newPtr1 = newPtr1->Next;
                }
                newPtr2->Next=NULL;
                delete newPtr1;
                cout << "Deleting to the end done\n";
                break;
            }
    }
return;
}
void edt(){
    if (!Header) {cout <<"Linked List is empty \n"; return;}
    LinkedList *newPtr;
    int value;
    cout <<"Enter the value : \n";
    cin >> value;
    cout << "Which node do you want to edit ?\n 1  the beginning \n 2 in the middle \n 3 the last\n";
    int ch;
    cin >> ch;
    switch (ch)
        {case 1 :
        {   Header->data=value;
            cout << "Editing done\n";
            return;
        }
        case 2:
        {   int pos;
            cout << " Which node do you like to edit ? \n";
            cin >> pos;
            pos--;
            newPtr = Header;
            for (int i = 0; i < pos; i++)
            {newPtr = newPtr->Next; }
            newPtr->data = value;
            cout << "Editing done\n";
            break;}
        case 3:
        {   newPtr = Header;
            while (newPtr->Next) {
                newPtr = newPtr->Next;
            }
            newPtr->data=value;
            cout << "Editing done\n";
            break;
        }
    }
    return;
}
