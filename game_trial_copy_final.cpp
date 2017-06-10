/*Program to simulate The Uncharted Arcade*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>

using namespace std;

//Seed for first card number in card assignment text file//
int cardno;

//Function to read stored card number from file//
void read_cardno()
{
    ifstream file("card_number.txt");
    file>>cardno;
}

//Function to write incremented card number from file//
void write_cardno()
{
    ofstream file1("card_number.txt");
    file1<<cardno;
    file1.close();
}

//Function explained in void game_start()//
void Wait(int waitTime)
{
	for(int i = 0; i < waitTime; i++)
	{
		continue;
	}
}

struct card {
    int time;
    int c_no;
    char type;
};

class game {
     char game_name[30];
     char descript[300];
     int game_time;
     int game_id;
 public:
    void gamedata();
    void showgamedata();
    //Accessors//
    int get_gameid();
    int get_gametime();

};

void game::gamedata() {
    cout<<"Enter game ID: ";
    cin>>game_id;
    cout<<"Enter game title: ";
    /*Code::Blocks has a problem reading strings. This command is used to clear the stream buffer,
    to make space for the incoming string*/
    cin.ignore(1000, '\n');
    cin.getline(game_name, 29);
    cout<<"Enter description: ";
    cin.getline(descript, 300);
    cout<<"Enter game time: ";
    cin>>game_time;
    cout<<endl;
}

void game::showgamedata() {
    cout.setf(ios::left);
    cout<<endl;
    cout<<"ID: ";
    cout<<game_id<<endl;
    cout<<"Game title: ";
    cout<<game_name<<endl;
    cout<<"Description: ";
    cout<<descript<<endl;
    cout<<"Time needed: ";
    cout<<game_time<<endl;
    cout<<endl;
    cout<<endl;
}

int game::get_gameid() {
    return game_id;
}

int game::get_gametime() {
    return game_time;
}

class player {
   char name[30];
   card player_card;
   public:

       //player();
       void getdata();
       void showdata();
       char* get_player_name();
       void update_player_name();
       int getcardno();
       int get_time_left();
       void update_time(int x);
};

void player::getdata() {
    read_cardno();
    cout<<endl;
        cout<<"Enter name: ";
        cin>>name;
        cout<<endl;
        cout<<"The following cards are available: "<<endl;
        cout<<"1. Platinum- Price: $100 Arcade Time: 1 hour."<<endl;
        cout<<"2. Gold- Price: $50 Arcade Time: 30 minutes."<<endl;
        cout<<"3. Silver- Price: $25 Arcade Time: 15 Minutes"<<endl;
        cout<<endl;
        cout<<"Pick you choice (P, G, S): ";
        cin>>player_card.type;
        player_card.c_no = ++cardno;
        cout<<"Your card number is: "<<player_card.c_no<<endl;
        cout<<endl;
        if (player_card.type=='P'||player_card.type=='p')
        {
            player_card.time=60;
            cout<<"You have "<<player_card.time<<" minutes left"<<endl;
        }
        else if (player_card.type=='G'||player_card.type=='g')
            {
               player_card.time=30;
            cout<<"You have "<<player_card.time<<" minutes left"<<endl;
        }
        else if (player_card.type=='S'||player_card.type=='s')
        {
            player_card.time=15;
            cout<<"You have "<<player_card.time<<" minutes left."<<endl;
        }
        cout<<endl;
        write_cardno();
}

void player::showdata() {
    cout<<endl;               //Simply displays data.
       cout<<"Name: "<<name<<endl;
       cout<<"Card Number: "<<player_card.c_no<<endl;
       cout<<"Card Type: "<<player_card.type<<endl;
       cout<<"Time left: "<<player_card.time<<endl;
       cout<<endl;
       cout<<endl;

}

void player::update_player_name() {
    cout<<"Enter name: ";
    char up_name[30];
    cin>>up_name;
    strcpy(name,up_name);

}

int player::getcardno() {
    return player_card.c_no;
}

int player::get_time_left() {
    //cout<<player_card.time<<endl;
    return player_card.time;
}

char* player::get_player_name() {
    return name;
}

void player::update_time(int x) {
    player_card.time = x;
    cout<<"You have "<<player_card.time<<" minutes left."<<endl;
}


void create()                             //Creates a file to store player data.
{
   fstream file("player_details.dat", ios::out|ios::binary|ios::app);
   player p;
   p.getdata();
   file.write((char*)&p, sizeof(p));
   file.close();

}

void display()                          //Displays contents of the file.
{
    player p;
    cout<<endl;
    fstream file("player_details.dat", ios::in|ios::binary);
    while (file.read((char*)&p, sizeof(p))) {
        p.showdata();
    }
    file.close();
}

int main() {
    int ch;
    cout<<setw(56)<<"***WELCOME TO THE UNCHARTED ARCADE***"<<endl;
    do {

        cout << "                 "<<endl;
        cout << "                 "<<endl;
        cout << "                 "<<endl;
        cout << "\t\t\t* * * * * * * * * * * * * "<<endl;
        cout << "\t\t\t*                       *"<<endl;
        cout << "\t\t\t*                       *"<<endl;
        cout<<"\t\t\t*\t1.ADMIN         *"<<endl;
        cout<<"\t\t\t*\t2.USER LOGIN    *"<<endl;
        cout<<"\t\t\t*\t3.EXIT          *"<<endl;
        cout << "\t\t\t*                       *"<<endl;
        cout << "\t\t\t*                       *"<<endl;
        cout << "\t\t\t* * * * * * * * * * * * * "<<endl;
        cout << "                 "<<endl;
        cout<<"Enter your choice: ";
            cin>>ch;
        cout<<endl;
            switch (ch) {
                case 1:
                       void admin();
                       admin();
                       break;
                case 2:
                       void user();
                       user();
                       break;
                case 3:
                       exit(0);

     }   //closing rhe switch
 }while (ch!=3); //closing the loop
 return 0;
} //closing the main.

void admin () {                              //Definition of admin where two function are declared.//
    int ch;                                  //they are defined immediately.//
    player p;
    cout<<endl;
    do
    {
         cout << "\t\t\t# # # # # # # # # # # # # # # # # # # #"<<endl;
         cout << "\t\t\t#                                     #"<<endl;
         cout << "\t\t\t#                                     #"<<endl;
         cout<<"\t\t\t#\t1. Display all members        #"<<endl;
         cout<<"\t\t\t#\t2. Add new member             #"<<endl;
         cout<<"\t\t\t#\t3. Update name                #"<<endl;
         cout<<"\t\t\t#\t4. Delete membership          #"<<endl;
         cout<<"\t\t\t#\t5. Game Options               #"<<endl;
         cout<<"\t\t\t#\t6. Search                     #"<<endl;
         cout<<"\t\t\t#\t7. Back                       #"<<endl;
         cout << "\t\t\t#                                     #"<<endl;
         cout << "\t\t\t#                                     #"<<endl;
         cout << "\t\t\t# # # # # # # # # # # # # # # # # # # #"<<endl;
         cout << "                 "<<endl;
         cout<<endl;
         cout<<"Enter choice: ";
         cin>>ch;
         cout<<endl;
         switch(ch)
         {
         case 1:
             display();
             break;
         case 2:
            create();
            break;
         case 3:
             void update_user();
             update_user();
             break;
         case 4:
            void delete_user();
            delete_user();
            break;
         case 5:
            void game_option();
            game_option();
            break;
         case 6:
             void search_admin();
             search_admin();
             break;
         case 7:
            break;
         } //closes switch//
    }while(ch!=7);
} //closes function//

void update_user() {      //updates player data file//
    player p;
    int sno, cnt = 0, flag = 0;
    cout<<endl;
    fstream file("player_details.dat", ios::in|ios::binary|ios::out);
    cout<<"Enter card number to update: ";
    cin>>sno;
    while (file.read((char*)&p, sizeof(p)))
    {
        if (p.getcardno()==sno)  {
            file.seekp((cnt)*sizeof(p));
           p.update_player_name();
           file.write((char*)&p, sizeof(p));
           flag = 1;
           break;
         }
      cnt++;
    }
      if (flag==1)
          cout<<"Player data updated."<<endl;
      else
          cout<<"Player not found."<<endl;
       file.close();
       cout<<endl;

}

void delete_user() {
    int sno, flag = 0;
    player p;
    cout<<endl;
    fstream file("player_details.dat", ios::in|ios::binary);
    fstream file1("temp.dat", ios::out|ios::binary);
    cout<<"Enter card number to be deleted: ";
    cin>>sno;
    while (!file.eof())
    {
       file.read((char*)&p, sizeof(p));
       if (sno!=p.getcardno()) {
        file1.write((char*)&p, sizeof(p));
        flag = 1;
        }
    }
       if (flag==0)
              cout<<"Player not found.";
       else
              cout<<"Player data deleted."<<endl;
       file.close();
       file1.close();

       remove("player_details.dat");
       rename("temp.dat", "player_details.dat");

       cout<<endl;
}

void search_admin() {
     int ch;
     void search_player();
     void search_game();
     cout<<endl;
     do {
             cout << "\t\t\t------------------------"<<endl;
             cout << "\t\t\t|                      |"<<endl;
             cout << "\t\t\t|                      |"<<endl;
             cout<<"\t\t\t|\tSearch for:    |"<<endl;
             cout<<"\t\t\t|\t1. A player    |"<<endl;
             cout<<"\t\t\t|\t2. A game      |"<<endl;
             cout<<"\t\t\t|\t3. Back        |"<<endl;
             cout << "\t\t\t|                      |"<<endl;
             cout << "\t\t\t|                      |"<<endl;
             cout << "\t\t\t------------------------"<<endl;
             cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch) {
                  case 1:
                        search_player();
		                break;
	             case 2:
                        search_game();
		                break;
                 case 3:
                        break;

                }
        }while(ch!=3);
}
void search_player() {
        player p;
        int sid, flag = 0;
        cout<<endl;
        fstream file1("player_details.dat",ios::in|ios::binary);
        cout<<"Enter card number to be searched: ";
        cin>>sid;
        while(file1.read((char*)&p,sizeof(p)))
	{
		if(p.getcardno()==sid)
		{	flag=1;
            cout<<"Player exists."<<endl;
			p.showdata();
		}
	}
        if (flag==0)
            cout<<"Player does not exist."<<endl;
        file1.close();
        cout<<endl;
}
void search_game() {
        game g;
        int sid, flag = 0;
        cout<<endl;
        fstream file1("video_games.dat",ios::in|ios::binary);
        cout<<"Enter game ID to be searched: ";
        cin>>sid;
        while(file1.read((char*)&g,sizeof(g)))
	{
		if(g.get_gameid()==sid)
		{	flag=1;
		    cout<<"Game exists."<<endl;
			g.showgamedata();
		}
	}
	    if (flag==0)
	    cout<<"Game does not exist."<<endl;
        file1.close();
        cout<<endl;
}
void game_option() {
    int gch;
    do {
            cout << "\t\t\t+ + + + + + + + + + + + + + + + +"<<endl;
            cout << "\t\t\t+                               +"<<endl;
            cout << "\t\t\t+                               +"<<endl;
            cout<<"\t\t\t+\t1. Add games            +"<<endl;
            cout<<"\t\t\t+\t2. Display games        +"<<endl;
            cout<<"\t\t\t+\t3. Delete games         +"<<endl;
            cout<<"\t\t\t+\t4. Back                 +"<<endl;
            cout <<"\t\t\t+                               +"<<endl;
            cout <<"\t\t\t+                               +"<<endl;
            cout <<"\t\t\t+ + + + + + + + + + + + + + + + +"<<endl;
            cout<<"Enter choice: ";
            cin>>gch;
            cout<<endl;
            switch (gch) {
            case 1:
                   void add_games();
                   add_games();
                   break;
            case 2:
                   void display_games();
                   display_games();
                   break;
            case 3:
                   void delete_games();
                   delete_games();
                   break;
            case 4:
                   break;
            default:
                    cout<<"Wrong Choice!";
                    break;
            }

    } while(gch!=4);
}

void add_games() {
    cout<<endl;
    fstream file ("video_games.dat", ios::out|ios::binary|ios::app);
    game g;
    char ch;
    do  {
              g.gamedata();
              file.write((char*)&g, sizeof(g));
              cout.setf(ios::left);
              g.showgamedata();
              cout<<"Have more games to add? Enter 'y' for yes, 'n' for no: ";
              cin>>ch;
            }while(ch!='n');
    file.close();
}

void display_games() {
    game g;
    cout<<endl;
    fstream file("video_games.dat", ios::in|ios::binary);
    while (file.read((char*)&g, sizeof(g)))
        g.showgamedata();
    file.close();
}

void delete_games() {
    int sno, flag = 0;
    game g;
    cout<<endl;
    fstream file("video_games.dat",ios::in|ios::binary);
    fstream file1("temp.dat", ios::out|ios::binary);
    cout<<"Enter game ID be deleted: ";
    cin>>sno;
    while (!file.eof())
    {
       file.read((char*)&g, sizeof(g));
       if (sno!=g.get_gameid()) {
        file1.write((char*)&g, sizeof(g));
        flag = 1;
      }
    }
      if (flag==0)
                  cout<<"Game not found.";
       file.close();
       file1.close();
       remove("video_games.dat");
       rename("temp.dat", "video_games.dat");
       cout<<"Game deleted."<<endl;
       cout<<endl;

}
/*struct time {
    int h, m;
};*/

void user() {
    int uch;
    do{
        cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * "<<endl;
        cout << "\t\t\t*                                         *"<<endl;
        cout << "\t\t\t*                                         *"<<endl;
        cout<<"\t\t\t*\t1. View video game library        *"<<endl;
        cout<<"\t\t\t*\t2. Start Game!                    *"<<endl;
        cout<<"\t\t\t*\t3. Back                           *"<<endl;
        cout << "\t\t\t*                                         *"<<endl;
        cout << "\t\t\t*                                         *"<<endl;
        cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * *"<<endl;
        cout<<"Enter choice: ";
        cin>>uch;
        cout<<endl;
        switch(uch) {
        case 1:
            display_games();
            break;
        case 2:
            void user_start_game();
            user_start_game();
            break;
        case 3:
            break;
        default:
            cout<<"Wrong Choice.";
            break;
        }
    } while(uch!=3);
}

void user_start_game() {
    player p;
    game g;
    void game_start(int );
    int gch, time_required;
    int found = 0;
    fstream file1("player_details.dat", ios::out|ios::in|ios::binary);
    fstream file2("video_games.dat", ios::out|ios::in|ios::binary);
    int sno;
    char ans;
    cout<<"Enter your card number: ";
    cin>>sno;
    cout<<endl;
    cout<<endl;
       while(file1.read((char*)&p, sizeof(p))) {
       if (sno==p.getcardno()) {
         cout<<"\t\t\t\tWelcome "<<p.get_player_name()<<"!"<<endl;
         cout<<"\t\t\t  You have "<<p.get_time_left()<<" minutes left."<<endl;
        display_games();
        found = 1;
        break;
         }
       }
       if (found == 1) {
               cout<<"Enter the game you want to play: ";
               cin>>gch;
       while(file2.read((char*)&g, sizeof(g))) {
             if(gch==g.get_gameid())
             time_required = g.get_gametime();
        }
        if (p.get_time_left()<=time_required) {
        cout<<"You might need to pay extra. Proceed? (y/n)"<<endl;
        cin>>ans;
        if(ans=='y')
        game_start(sno);
        }
        else
        game_start(sno);
    }
   else
          cout<<"Invalid User."<<endl;
  file1.close();
  file2.close();
}

fstream file1;

struct time {
    int h, m;
};

void game_start(int sno) {
    player p;
    file1.open("player_details.dat", ios::in|ios::out|ios::binary);
    time start_time, end_time, difference;
    int player_time, time_left;
    cout<<"Enter start time: ";
    cin>>start_time.h>>start_time.m;
    for (int i=0; i<10; i++) {
    cout<< "*";
	Wait(100000000);
    }
    cout<<endl;
    cout<<"Enter end time: ";
    cin>>end_time.h>>end_time.m;
    difference.h = end_time.h - start_time.h;
    difference.m = end_time.m - start_time.m;
    cout<<"You played for "<<difference.h<<" hours and "<<difference.m<<" minutes"<<endl;
    while (file1.read((char*)&p, sizeof(p))) {
        if (sno==p.getcardno()) {
        file1.seekg(0, ios::cur);
        player_time = p.get_time_left();
        time_left = player_time - difference.m;
        p.update_time(time_left);
        file1.seekp(file1.tellg() - sizeof(p));
        file1.write((char*)&p, sizeof(p));
        break;
        }
    }
    file1.close();
}

