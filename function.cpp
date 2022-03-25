#include "header.h"
//Mohamed Al-zadjali	
app::app() //constructor
{
	head = NULL;
}

//Adding a room
int app::add_room(char uroom[])
{
	node * current = head;
	node * temp; //If a room exist

	if(!head){	//If no room exist
		head = new node;
		head -> data = new room;
		head -> data -> room_n = new char(strlen(uroom) + 1);
		strcpy(head -> data -> room_n,uroom);
		head -> next = NULL;
    cout<<"\tRoom number #"<<head -> data -> room_n<<" is added!";
		return 1;
	}
	//Check if a room already exist

	while(current){
		if(strcmp(current -> data -> room_n, uroom) == 0)
			return 0;
		current = current -> next;
	}
	current = head;
	while(current->next)
		current = current -> next;
	// Add the new room to the list
	temp = new node;
	temp -> data = new room;
	temp -> data -> room_n = new char(strlen(uroom) + 1);
	strcpy(temp -> data -> room_n,uroom);
	temp -> next = NULL;
	current -> next = temp;
  cout<<"\tRoom number #"<<temp -> data -> room_n<<" is added!";


	return 1;
}
// Removing a room
int app::remove_room(char uroom[]){
	node * current = head;
	node * temp;
	node * perv;
	if(!head) //Nothing to remove
		return 0;
	//traversing and checking if the room exist
	while(current){
		if(strcmp(current -> data -> room_n, uroom) == 0){	//Check the cases
			if(current == head){
				head = head -> next;
				delete current;
				current = NULL;
				return 1;
			}
			if(current -> next == NULL && current != head){
				perv -> next = NULL;
				delete current;
				current = NULL;
				return 1;		
			}
			temp = current -> next;
			if(current -> next){
				perv -> next = temp;
				delete current;
				current = NULL;
				return 1;
			}
		}
		perv = current;
		current = current -> next;
	}
	return 0;
}
 	//Adding an item
int app::add_item(char uroom[],char item[],char category[],char status[]){
	node * current = head;
	node2 * temp = new node2;
	node2 * current2;
	if(!head)//If there is no room
		return 0;
	while(current){
		//Finding the room
		if(strcmp(current -> data -> room_n, uroom) == 0){

			temp -> data2 = new info;
			temp -> data2 -> item_n = new char[strlen(item)+1];
			strcpy(temp -> data2 -> item_n, item);
			temp -> data2 -> item_c = new char[strlen(category)+1];
			strcpy(temp -> data2 -> item_c, category);
			temp -> data2 -> item_s = new char[strlen(status)+1];
			strcpy(temp -> data2 -> item_s, status);
			current2 = current -> head1;
			if(current2){ //If wasn't the first item to be added
				
				temp -> next2 = current -> head1;
				current -> head1 -> next2 = temp;
				
			}
			else{	//The first item
				current->head1 = temp;
				current->head1->next2 = NULL;
			}


			return 1;
		}
		current = current -> next;

	}
	return 0;
}
	// removing an item
int app::remove_item(char uroom[], char item[]){
	node * current = head;
	node2 * prev;
	node2 * temp1;
	node2 * current2 = current -> head1;
	if(!head)//No rooms
		return 0;
	while(current){ //Finding the room
		if(strcmp(current -> data -> room_n, uroom) == 0){
			while(current2){	//if found the room
				current2 = current -> head1;
				if(strcmp(current2 -> data2 -> item_n,item) ==0){ //The cases when removing
					if(current2 == current -> head1){
						delete current2;
						current2 = NULL;
						return 1;
					}
					if(current2 -> next2 == NULL && current2 != head -> head1){
						current2 -> next2 = NULL;
						delete current2;
						current2 = NULL;
						return 1;
					}
					temp1 = current2 -> next2;
					if(current2 -> next2){
						prev -> next2 = temp1;
						delete current2;
						current2 = NULL;
						return 1;
					}
					
				}
				prev = current2;
			}
			
		}
	
		current = current -> next;
	}
	return 0;

}
//Displaying by room
int app::display_items_in_room(char uroom[]){
	node*current = head;
	if(!head)//No room exist
		return 0;
	while(current){//Finding the room
		if(strcmp(current -> data -> room_n,uroom)){
			node2*current2 = current->head1;
			while(current2){//Traversing through accessories list

				cout<<"Accessory: "<<current2 -> data2 -> item_n<<'\n'<<"Category: "<<current2 -> data2 ->item_c<<'\n'<<"Status: "<<current2 -> data2 ->item_s<<'\n';
				current2 = current2 -> next2;
				return 1;
			}
		}
		current = current -> next;
		}
	return 0;
	
}
//Display all items in all rooms
int app::display_all_items(){
	node*current = head;
	node2*current2 = NULL;
	if(!head)//No room exist
		return 0;
	while(current){//Traversing through the rooms
		if(current -> head1)
			current2 = current -> head1;
		while(current2){//Traversing through the accressories list
			cout<<"Accessory: "<<current2 -> data2 -> item_n<<'\n'<<"Category: "<<current2 -> data2 -> item_c <<'\n'<<"Status: "<<current2 -> data2 ->item_s<<'\n';
			current2 = current2 -> next2;
		}
		current = current -> next;
	}
	return 1;


}



app::~app()	//Accessories list 
{
	node * temp;
	node2 * temp1;
	while(head){
		if(head -> data -> room_n){
			temp = head;
			while(head->head1){
				temp1 =	head->head1;
				delete head->head1->data2->item_n;
				head->head1->data2->item_n = NULL;
				delete head->head1->data2->item_c;
				head->head1->data2->item_c = NULL;
				delete head->head1->data2->item_s;
				head->head1->data2->item_s = NULL;
				head->head1 = head->head1->next2;
				delete temp1;
				temp1 = NULL;
			}
			delete head->data->room_n;
			head->data->room_n = NULL;
			head = head->next;
			delete temp;
			temp = NULL;			
		}


	}
	if(head->head1){
		delete head->head1;
		head->head1 = NULL;
		delete head;
		head = NULL;
	}
}
