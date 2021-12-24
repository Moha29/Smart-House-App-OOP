#include "header.h"
//Mohamed Alzasjali

int main()
{
	char uroom[MAX];	//arrays to insert in the functions
	char item[MAX];
	char category[MAX];
	char status[MAX];
	int choice;		//The user's choice of the menu
  int t_f; //True or false for the functions
	app my_app;	

	cout<<"Hello! Welcome to your smart house app!"<<'\n';
	//Menu 
	while(choice != 7){
    t_f = 0;
		cout<<"|                   MENU                   |"<<'\n'<<"(1) Add a new room."<<'\n'<<"(2) Remove a room."<<'\n'<<"(3) Add a new accessory to a room."<<'\n'<<"(4) Remove an accessory from a room."<<'\n'<<"(5) Display accessories in a room."<<'\n'<<"(6) Display all accessories in all the rooms."<<'\n'<<"(7) Quit the program."<<'\n'; 
		cout<<"By entering the number of the option. What do you want to do: "; //Displaying the menu to the user
    cin>>choice;
    cin.ignore(100,'\n');
	//Adding a room
    if (choice == 1){
      cout<<"Please enter the room name: ";
      cin.get(uroom,MAX,'\n');
      cin.ignore(100,'\n');
      t_f = my_app.add_room(uroom);
      if(t_f)
        cout<<'\n'<<'\n'<<"                               SAVED!        "<<'\n'<<'\n';
      else
        cout<<'\n'<<'\n'<<"                               Room Exist!                 "<<'\n'<<'\n';
	//Removing a room
    }
    if (choice == 2){
      cout<<"Please enter the room name: ";
      cin.get(uroom,MAX,'\n');
      cin.ignore(100,'\n');
      t_f = my_app.remove_room(uroom);
      if(t_f)
        cout<<'\n'<<'\n'<<"                               REMOVED!        "<<'\n'<<'\n';
      else
        cout<<'\n'<<'\n'<<"                         Room Doesn't Exist!                 "<<'\n'<<'\n';

    }	//Ading an item
    if (choice == 3){
      cout<<"Please enter the room name: ";
      cin.get(uroom,MAX,'\n');
      cin.ignore(100,'\n');
      cout<<"Please enter name of the accessory: ";
      cin.get(item,MAX,'\n');
      cin.ignore(100,'\n');
      cout<<"Please enter the category of the accessory: ";
      cin.get(category,MAX,'\n');
      cin.ignore(100,'\n');
      cout<<"Please enter the status of the accessory: ";
      cin.get(status,MAX,'\n');
      cin.ignore(100,'\n');
      t_f = my_app.add_item(uroom,item,category,status);
      if(t_f)
        cout<<'\n'<<'\n'<<"                               SAVED!        "<<'\n'<<'\n';
      else
        cout<<'\n'<<'\n'<<"                         Room Doesn't Exist!                 "<<'\n'<<'\n';
    } //Removing an item
    if (choice == 4){
      cout<<"Please enter the name of the room: ";
      cin.get(uroom,MAX,'\n');
      cin.ignore(100,'\n');
      cout<<"Please enter the name of the accessory: ";
      cin.get(item,MAX,'\n');
      cin.ignore(100,'\n');
      t_f = my_app.remove_item(uroom,item);
      if(t_f)
        cout<<'\n'<<'\n'<<"                                REMOVED!       "<<'\n'<<'\n';
      else
	cout<<'\n'<<'\n'<<"                                Item or room doesn't exist!         "<<'\n'<<'\n';
      
    }	//Displaying items by room
    if (choice == 5){
      cout<<"Enter the room name: ";
      cin.get(uroom,MAX,'\n');
      cin.ignore(100,'\n');
      t_f = my_app.display_items_in_room(uroom);
      if(t_f ==0)
	cout<<'\n'<<'\n'<<"                         Room Doesn't Exist!                   "<<'\n'<<'\n';

    }
    if (choice == 6){ // Displaying all items
	cout<<'\n'<<"|||Displaying all accessories|||"<<'\n';
	t_f = my_app.display_all_items();
	if(t_f == 0)
		cout<<"                            No Accessories Exist!                  "<<'\n'<<'\n';
      
    }
    

  }


  return 0;
}
