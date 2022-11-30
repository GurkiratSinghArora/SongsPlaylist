// Name - Gurkirat Singh Arora : Date - 3rd June 2022
#include "PlayList.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// PlayList method implementations go here
PlayList::PlayList()
{
    top= nullptr;
    numberOfSongs=0;
}
PlayList::PlayList(const PlayList& pl)
{
    numberOfSongs=pl.numberOfSongs;
    top = nullptr;
    PlayListNode* ptr= pl.top;
    if(ptr!=nullptr)
    {
        top= new PlayListNode(ptr->song);
        top->next=nullptr;
        ptr=ptr->next;
        PlayListNode* copy =top;
        while(ptr!=nullptr)
        {
            PlayListNode* ptr1= new PlayListNode(ptr->song);
            copy->next= ptr1;
            copy=copy->next;
            ptr=ptr->next;
        }
    }
}
PlayList::~PlayList()
{
    while(top!=nullptr)
    {
        PlayListNode* temp= top;
        top=top->next;
        delete temp;
    }
    numberOfSongs=0;
}
PlayList& PlayList:: operator=(const PlayList & pl)
{
    if(this!= &pl)
    {
        this->~PlayList();
        numberOfSongs=pl.numberOfSongs;
        top = nullptr;
        PlayListNode* ptr= pl.top;
        if(ptr!=nullptr)
        {
            top= new PlayListNode(ptr->song);
            ptr=ptr->next;
            PlayListNode* copy =top;
            while(ptr!=nullptr)
            {
                PlayListNode* ptr1= new PlayListNode(ptr->song);
                copy->next= ptr1;
                copy=copy->next;
                ptr=ptr->next;
            }
        }
    }
    return *this;
}
void PlayList::insert(Song sng, unsigned int pos)
{
    int position=pos-1;
    PlayListNode* head= new PlayListNode(sng);
    head->next=nullptr;
    if(position==0)
    {
        head->next=top;
        top=head;
    }
    else
    {
        PlayListNode* temp= top;
        for(int i=0;i<position-1;i++)
        {
            if(temp!=NULL)
            {
                temp=temp->next;
            }
        }
        if(temp!=NULL)
        {
            head->next=temp->next;
            temp->next=head;
        }
    }
    numberOfSongs++;
}

Song PlayList::remove(unsigned int pos)
{
    int position=pos-1;
    if(top->next==nullptr && position==0)
    {
        Song sng= top->song;
        delete top;
        top=nullptr;
        numberOfSongs--;
        return sng;
    }
    else if(position==0)
    {
        PlayListNode* temp=top;
        Song sng=temp->song;
        top=top->next;
        delete temp;
        numberOfSongs--;
        return sng;
    }
    else
    {
        unsigned int i=0;
        PlayListNode* temp= top;
        while(i<position-1)
        {
            temp=temp->next;
            i++;
        }
        PlayListNode* head= temp->next;
        temp->next=head->next;
        Song sng=head->song;
        delete head;
        numberOfSongs--;
        return sng;
    }
}
unsigned int PlayList:: size() const
{
    return numberOfSongs;
}
Song PlayList::get(unsigned int pos) const
{
    int position=pos-1;
    unsigned int i=0;
    PlayListNode* temp= top;
    while(i<position)
    {
        temp=temp->next;
        i++;
    }
    return temp->song;
}
void PlayList::swap(unsigned int pos1, unsigned int pos2)
{
    int position1=(pos1<=pos2)?(pos1-1):(pos2-1);
    int position2=(pos1<=pos2)?(pos2-1):(pos1-1);
    if(position1==position2)
    {
        return;
    }
    if(position1==0 && position2==1)
    {
        PlayListNode* temp1=top;
        PlayListNode* temp2=temp1->next;
        temp1->next=temp2->next;
        temp2->next=temp1;
        top=temp2;
    }
    else if(position1==position2+1 || position1+1==position2)
    {
        unsigned int i=0;
        PlayListNode* temp1= top;
        while(i<position1-1)
        {
            temp1=temp1->next;
            i++;
        }
        PlayListNode* temp2=temp1->next;
        PlayListNode* temp3=temp2->next;
        temp1->next=temp3;
        temp2->next=temp3->next;
        temp3->next=temp2;
    }
    else if(position1==0)
    {
        PlayListNode* temp1=top;
        PlayListNode* temp2=top;
        temp2=temp2->next;
        PlayListNode* temp3=top;
        PlayListNode* temp4=top;
        int i=0;
        while(i<position2-1)
        {
            temp3=temp3->next;
            i++;
        }
        temp4=temp3->next;
        temp1->next=temp4->next;
        temp3->next=temp1;
        temp4->next=temp2;
        top=temp4;
    }
    else
    {
        PlayListNode* temp1= top;
        PlayListNode* temp2= top;
        PlayListNode* temp3= top;
        PlayListNode* temp4= top;
        int i=0,j=0;
        while(i<position1-1)
        {
            temp1=temp1->next;
            temp3=temp3->next;
            i++;
        }
        temp3=temp3->next;
        temp3=temp3->next;
        while(j<position2-1)
        {
            temp2=temp2->next;
            temp4=temp4->next;
            j++;
        }
        temp4=temp4->next;
        temp4=temp4->next;
        PlayListNode* ptr1=temp1->next;
        PlayListNode* ptr2=temp2->next;
        temp1->next=ptr2;
        ptr2->next=temp3;
        temp2->next=ptr1;
        ptr1->next=temp4;
    }
}

int selectComputation()
{
    int selection;
    cout<<"Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): ";
    cin>>selection;
    cin.clear();
    cin.ignore(1000,'\n');
    while(selection<1 || selection>5)
    {
        cout<<"Please enter a correct choice: ";
        cin>>selection;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    return selection;
}

int validposition(const PlayList& A, int option)
{
    if(option==1)
    {
        int num;
        if(A.size()==0)
        {
            cout<<"Position (1) : ";
            cin>>num;
        }
        else
        {
            cout<<"Position (1 to "<<A.size()+1<<"): ";
            cin>>num;
        }
        while(num> A.size()+1)
        {
            cout<<"Please re-enter a valid position ";
            cin>>num;
        }
        return num;
    }
    else
    {
        int num;
        {
            cout<<"Position (1 to "<<A.size()<<"): ";
            cin>>num;
        }
        while(num> A.size())
        {
            cout<<"Please re-enter a valid position "<<endl;
            cout<<"Position (1 to "<<A.size()<<"): ";
            cin>>num;
        }
        return num;
    }
}
