#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int const MAX = 100;

//This program is the smart house program. The user will be able to enter a room and its accessories. The user can control the accessories within the app

//This struct is the accessories data
struct info
{
	char * item_n;
	char * item_c;
	char * item_s;
};
//node2 is the accessories list
struct node2
{
	info * data2;
	node2 * next2;
};
//The room name
struct room
{
	char * room_n;

};
//The lll for the rooms and its accessories
struct node
{
	room * data;
	node2 * head1; 
	node * next;
};

class app //The class for the apt
{
	public:
		app();
		int add_room(char room[]);
		int remove_room(char room[]);
		int add_item(char room[],char item[],char category[],char status[]);
		int remove_item(char room[],char item[]);
		int display_items_in_room(char room[]);
		int display_all_items();
		~app();
	private:
		node * head;
};

