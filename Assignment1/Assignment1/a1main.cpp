// Name - Gurkirat Singh Arora : Date - 3rd June 2022
// O-Notation
//PlayList Methods
//Default Constructor - O(1): It takes constant time because we are creating a linked list of size-0
//Destructor          - O(n): If the linked list is of size- n, then it transverse through the entire linked list to delete the dynamic memory associated with every  //                        node on heap by while loop.Operations within the while loop are the critical operations.
//Copy Constructor    - O(n): As the PlayListNode* ptr transverse through the entire linked list, copies data from every node until ptr==nullptr by looping. The //critical operations are the operations within the while loop.
//Overloaded Assignment Operator -O(n): As the PlayListNode* ptr transverse through the entire linked list, copies data from every node until ptr==nullptr by looping. //The critical operations are the operations within the while loop.
//Insert              - O(n): Considering the worst case scenario, if we have to insert a node at the end, we need to transverse through the entire linked list to //reach the end and insert the node. This is the critical operation in the insert function.
//Remove              - O(n): Considering the worst case scenario, if we have to remove a node at the end, we need to transverse through the entire linked list to //reach the end and remove the node. This is the critical operation in the remove function.
//Get                 - O(n): Considering the worst case scenario, if we have to get the song from the last node, we need to transverse through the entire linked list //to reach the end and return the song in that node. This is the critical operation in the get function.
//Size                - O(1): As it return the value of numberOfSongs i.e. size of the linked list. This is the critical operation which takes constant time.
//Swap                - O(n): Considering the worst case scenario to swap last two nodes. In this case, we will iterate though the entire linked list twice, therefore //it will be O(n) +(n) (approximately in case when n is very large) which will ultimately be O(n).
//Main Function Commands
//Enter a song       - O(n): In this case, there is only one critical operation, which is calling the insert function and the Big O-Notation for insert is O(n).
//Remove a song      - O(n): In this case, there is only one critical operation, which is calling the remove function and the Big O-Notation for remove is O(n).
//Swap two songs     - O(n): In this case, there is only one critical operation, which is calling the swap function and the Big O-Notation for swap is O(n).
//Print all the songs- O(n): In this case, it will transverse through the entire linked list by loop to print the data in each node through considering the size of the //                       linked list is n, it will take O(n) time.
#include "PlayList.h"
#include "Song.h"
#include <iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    PlayList A;
    int num;
    cout<<"Menu:"<<endl;
    cout<<"1 - Enter a song in the play list at a given position"<<endl;
    cout<<"2 - Remove a song from the play list at a given position"<<endl;
    cout<<"3 - Swap two songs in the play list"<<endl;
    cout<<"4 - Print all the songs in the play list"<<endl;
    cout<<"5 - Quit"<<endl;
    do
    {
        num=selectComputation();
        if(num==1)
        {
            string name,artist;
            int length;
            int position;
            cout<<"Song name: ";
            getline(cin,name);
            cout<<"Artist: ";
            getline(cin,artist);
            cout<<"Length: ";
            cin>>length;
            position= validposition(A,num);
            Song sng=Song(name, artist, length);
            A.insert(sng, position);
            cout<<"You entered "<<name<<" at position "<<position<<" in the playlist"<<endl;
            cout<<endl;
        }
        else if(num==2)
        {
            unsigned int position;
            position=validposition(A,num);
            Song sng=A.remove(position);
            cout<<"You removed "<<sng.getName()<<" from the play list"<<endl;
            cout<<endl;
        }
        else if(num==3)
        {
            unsigned int pos1;
            unsigned int pos2;
            cout<<"Swap song at position (1 to "<<A.size()<<"): ";
            cin>>pos1;
            do
            {
                if(pos1>A.size())
                {
                    cout<<"Please re-enter a valid position."<<endl;
                    cout<<"Swap song at position (1 to "<<A.size()<<"): ";
                    cin>>pos1;
                }
                else
                {
                    break;
                }
            }while(true);
            cout<<"with the song at position (1 to "<<A.size()<<"): ";
            cin>>pos2;
            do
            {
                if(pos2>A.size())
                {
                    cout<<"Please re-enter a valid position."<<endl;
                    cout<<"with the song at position (1 to "<<A.size()<<"): ";
                    cin>>pos2;
                }
                else
                {
                    break;
                }
            }while(true);
            A.swap(pos1,pos2);
            cout<<"You swapped the songs at positions "<<pos1<<" and "<<pos2<<endl;
            cout<<endl;
        }
        else if(num==4)
        {
            for(int i=0;i<A.size();i++)
            {
                Song sng=A.get(i+1);
                cout<<(i+1)<<" "<<sng.getName()<<" ("<<sng.getArtist()<<") "<<sng.getLength()<<"s"<<endl;
            }
            if(A.size()>1)
            {
                cout<<"There are "<<A.size()<<" songs in the play list. "<<endl;
            }
            else
            {
                cout<<"There is only 1 song in the playlist. "<<endl;
            }
            cout<<endl;
        }
        else if (num==5)
        {
            cout<<"You have chosen to quit the program. "<<endl;
            cout<<endl;
            return 0;
        }
        else
        {
            cout<<"Please enter another command."<<endl;
            cout<<endl;
        }
    }while(true);
    return 0;
}



