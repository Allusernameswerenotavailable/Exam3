#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <Windows.h>
#include <iomanip>
#include "input.h"
#include "Rational.h"
using namespace std;

char menuOption();//////All function
void image1();//////////prototypes
void VectorPartV();//
void ListpartL();//
void StackpartS();//
void QueuepartQ();//

//Oscar Gallardo
//Date: 06/05/23

int main()
{
	system("cls");
	image1();//image1 will be called to display the vector, stack, list and queue color display


	do//we will use do while loop to loop between all parts of this exam
	{
		switch (toupper(menuOption()))///////////////
		{////////////////////////////////////////////Do switch will switch between all parts of the exam
		case 'V': VectorPartV(); break;/////
		case 'L': ListpartL(); break;//
		case 'S': StackpartS(); break;
		case 'Q': QueuepartQ(); break;
		case 'X': exit(0); break;


		}


	} while (true);

	system("pause");

	return 0;

}



char menuOption()//with this menu we will display the menu that will allow the user to choose what part of this program they want to select
{
	

	cout << endl;
	cout << "\n\tSTL (Standard Template Library) Containers & Container Adaptors by Oscar Gallardo 06/05/23";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\tV. VECTOR CONTAINER";//for vector container we will create a vector with integer input data 
	cout << "\n\tL. LIST CONTAINER";//for list container we will create a list with integer input data 
	cout << "\n\tS. STACK CONTAINER ADAPTOR";//for stack container we will create a stack with integer input data 
	cout << "\n\tQ. QUEUE CONTAINER ADAPTOR";//for queue container we will create a queue with integer input data 
	cout << "\n\t" << string(80, char(205));
	cout << "\n\tX.EXIT THE PROGRAM";//case X will allow the user to exit the program
	cout << "\n\t" << string(80, char(205));
	cout << "\n";

	return inputChar("\n\tOPTION: ", static_cast<string>("VLSQX"));


}

//Precondition none
//Postcondition: For this part of the program we will create a vector object that will take user integer input data
//We will make use of Rational class that will help us create rational numbers in our vector
//After the user inputs all data we will do data manipulation that will include displaying the data, sorting the rational numbers in ascending order
//We will remove elements from the vector and insert elements as well
void VectorPartV()
{

	system("cls");

	Rational vector1;//we will create/instantiate a Rational class object that will create our rational numbers
	vector<Rational> vector2;//we will create/instantiate a vector object that will hold our rational numbers
	


	do//we will use this do while loop in order to perform all cases of the queue section of our exam
	{

		beginning:

		system("cls");

		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);//we will call Handle function in order to add color to our vector description paragraph

		SetConsoleTextAttribute(color, 4); cout << " " << endl;
		cout << "\tVECTORS ARE SAME AS DYNAMIC ARRAYS WITH THE ABILITY TO RESIZE ITSELF AUTOMATICALLY WHEN AN\n" <<
			"\t" << "ELEMENT IS INSERTED OR DELETED, WITH THEIR STORAGE BEING BEING HANDLED AUTOMATICALLY BY THE CONTAINER.\n" <<
			"\t" << "VECTOR ELEMENTS ARE PLACED IN CONTIGUOUS STORAGE SO THAT THEY CAN BE ACCESSED AND TRAVERSED\n" <<
			"\t" << "USING ITERATORS OR INDEXES.\n";
		SetConsoleTextAttribute(color, 7); 

		if (vector2.empty())//with this if statement we will do validation in order to allow the user to know when the vector is empty  
		{

			cout << "\n\tTHE CURRENT VECTOR IS EMPTY\n\n\n";

		}
		else//if the vector is not empty then we will display how many elements the vector contains 
		{
			cout << endl;
			cout << "\tTHE CURRENT VECTOR CONTAINS " << vector2.size() << " ELEMENTS\n\t\t ";//we will display the size of the vector

			for (int i = 0; i < vector2.size(); i++)//with this for loop we will display the entire elements of the vector  
			{

				cout << vector2[i] << " ";

			}

			cout << "\n\tINDEX: ";

			for (int t = 0; t < vector2.size(); t++)//with this for loop we will display the index of all elements in the vector 
			{

				cout << setw(4) << right << t;

			}

			//getting the address
			cout << "\n\tADDRESS: " << vector2.data();//with this we will display the vector's addrress every single time another element is added to the vector

		}


		
		cout << "\n\t" << string(70, char(205));
		cout << "\n\tVECTOR MENU OPTION";
		cout << "\n\t" << string(70, char(205));
		cout << "\n\t1. ADD AN ELEMENT TO THE BACK";/////////////Vector Main Menu
		cout << "\n\t2. INSERT AN ELEMENT AT AN INDEX";//////////
		cout << "\n\t3. RETRIEVE AN ELEMENT AT AN INDEX";////////
		cout << "\n\t4. ERASE ELEMENT(S)";///////////////////////
		cout << "\n\t5. SORT THE ELEMENTS IN ASCENDING ORDER";///
		cout << "\n\t6. CLEAR ALL ELEMENTS";/////////////////////
		cout << "\n\t" << string(70, char(205));
		cout << "\n\t0. RETURN";
		cout << "\n\t" << string(70, char(205));


		switch(inputInteger("\n\tOPTION: ", 0, 6))//with this switch function we will switch through all of the cases in the vector program of this exam
		{
		case 0: return; break;//in case 0 we will return to the exam main menu


		case 1://for case 1 we will allow the user to add elements to the vector
		{
			

			cout << "\tINPUT A RATIONAL NUMBER TO BE ADDED...\n";

			try//try and catch will be used to throw an exception when the user inputs a zero denominator 
			{

				vector1.setNumerator(inputInteger("\n\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow user to input the numerator
				vector1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow user to input the denominator

				
				vector2.push_back(vector1);//we will call the push_back function in order to push elements into our vector

				cout << "\n\t" << vector1.toString() << " WILL BE ADDED TO THE BACK OF THE VECTOR.\n";//we will call toString in order to tell the user when an element has been added to the vector

			}
			catch (Rational::ZeroDenominator)//if the user inputs a zero denominator the message below will be displayed 
			{

				cout << "\n\tEXCEPTIONAL ERROR: CANNOT ADD A RATIONAL NUMBER, " << vector1.toString() << ", WITH A ZERO DENOMINATOR VALUE.\n";
			
			}


			cout << endl;

			system("pause");

			system("cls");
		
		
		}
		break;

		case 2://for case 2 we will insert elements into the vector at an index that the user will also choose 
		{

			int index = 0;//index will hold index data inputs from the user

			int size = vector2.size() - 1;//int size will be used to validate the index in order for the user not to enter an index thats out of bounds from the vector
		
			if (vector2.empty())//if statement will tell the user when the vector is empty 
			{

				cout << "\n\tTHE CURRENT VECTOR IS EMPTY\n\n\n";
			
			}

			cout << endl;

			cout << "\tINPUT A RATIONAL NUMBER TO INSERT...\n";

			try//try and catch will be used to throw an exception when the user inputs a zero denominator
			{

				vector1.setNumerator(inputInteger("\n\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow user to input the numerator
				vector1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow user to input the denominator

				index = inputInteger("\n\tENTER AN INDEX TO INSERT YOUR NUMBER: ", 0, size);//we will allow the user to input the index that they want to insert the new rational number

				if(index == 0)//if the user inputs 0 for the index then we will input the new rational number into the 0 index
				{
					auto it = vector2.begin();
					vector2.insert(it, vector1);//we will insert new element into our vector
				
				}
				else//if the user inputs any other index other than 0 then our program will insert the new rational number into that index
				{
					auto it = vector2.begin() + index;
					vector2.insert(it, vector1);//we will insert new element into our vector
				
				}


				cout << "\n\t" << vector1.toString() << " WILL BE ADDED AT INDEX: " << index;//we will tell the user when the new rational number is inserted
				cout << endl;

			}
			catch (Rational::ZeroDenominator)//if the user inputs a zero denominator the message below will be displayed
			{

				cout << "\n\tEXCEPTIONAL ERROR: CANNOT ADD A RATIONAL NUMBER, " << vector1.toString() << ", WITH A ZERO DENOMINATOR VALUE.\n";

			}

			system("pause");

			system("cls");
		
		
		}
		break;

		case 3://for case 3 we will allow the user to retrieve a rational number from the vector based on the index of choice 
		{
			if (vector2.empty())//if the vector is empty then the program will display the message below and the program will return to the vector menu 
			{

				cout << "\n\tRETRIEVE OPERATION CANNOT BE PERFORMED FROM AN EMPTY VECTOR.\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

			int index = vector2.size() - 1;//index will hold index data inputs
			cout << "\n\tENTER AN INDEX (0..." << vector2.size() - 1 << ") OF RATIONAL NUMBER TO BE RETRIEVED: ";//we will display the index of the vector
			int option = inputInteger("", 0, index);//we will allow the user to input the index of choice

			cout << "\n\t" << vector2[option].toString() << " IS LOCATED AT INDEX " << option << " FROM THE VECTOR.\n";//we will display what rational number is found at the index the user inputted

			cout << endl;
			system("pause");
			system("cls");
			
		}
		break;

		case 4://for case 4 the user will be able to remove rational numbers from the vector 
		{
			
			if (vector2.empty())//if the vector is empty then the program will display the message below and the program will return to the vector menu 
			{

				cout << "\n\tERASE OPERATION CANNOT BE PERFORMED ONTO AN EMPTY VECTOR.\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

			cout << "\n\tINPUT A RATIONAL NUMBER TO BE REMOVED...\n";

			try//try and catch will be used to throw an exception when the user inputs a zero denominator 
			{

				vector1.setNumerator(inputInteger("\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow the user to input the numerator
				vector1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow the user to input the denominator

				
				auto it = find(vector2.begin(), vector2.end(), vector1);//we will traverse the vector from beginning to the end in order to find the rational number to be removed

				
				if (it != vector2.end())//with this if statement we will check until the end of the vector for the rational number that will be removed 
				{


					switch (inputChar("\n\tDO YOU WANT TO REMOVE (O - ONE or A - ALL) ELEMENTS: ", static_cast<string>("OA")))
					{//with this switch statement we will allow the user to switch between erasing only one rational number or all elements in the vector which are the rational number of choice to removed

					case 'O'://for case O only one rational number will be removed 
					{

						vector2.erase(it);//we will call erase function in order to remove an element from the vector
						cout << "\n\t" << vector1.toString() << " WILL BE REMOVED FROM THE VECTOR.\n";

					}
					break;

					case 'A'://for case A we will be able to remove multiple elements from the vector 
					{

						 
						int count = 0;//int count will be used in order to keep track of all elements in the vector that match the rational number that the user inputs

						
						for (auto it = vector2.begin(); it != vector2.end();)//with this if statment we will traverse our vector frim beginning to the end in order to find all rational numbers to be removed 
						{

							
							if (*it == vector1)//this if statement will be used to find all elements that match the rational number input
							{

								it = vector2.erase(it);//we will find all elements that match the rational number and we will erase them
								count++;

							}
							else 
							{

								++it;//we will keep traversing our vector

							}
						}

						cout << "\n\t" << vector1.toString() << " WILL BE REMOVED FROM THE VECTOR.\n";//we will tell the user when all elements are finished being removed

					}

							break;
					}
				}
				
				else//if the rational number the user inputs is not found in the vector then message below will be displayed 
				{

					cout << "\n\t" << vector1.toString() << " CANNOT BE FOUND IN THE VECTOR.\n";

				}
			}
			catch (Rational::ZeroDenominator)//if the user inputs a zero denominator the message below will be displayed 
			{

				cout << "\n\tEXCEPTIONAL ERROR: CANNOT ADD A RATIONAL NUMBER, " << vector1.toString() << ", WITH A ZERO DENOMINATOR VALUE.\n";

			}

			cout << endl;
			system("pause");
			system("cls");
			

		}
		break;

		case 5://for case 5 we will sort all vector rational numbers in ascending order 
		{
			
			if (vector2.empty())//if the vector is empty then the program will display the message below and the program will return to the vector menu 
			{

				cout << "\n\tTHE CURRENT VECTOR IS EMPTY\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

			
			sort(vector2.begin(), vector2.end());//we will call the sort function in order to sort all rational numbers in ascending order

			cout << "\n\tTHE VECTOR WILL BE SORTED IN ASCENDING ORDER.\n";

			cout << endl;

			system("pause");

			system("cls");
		
		
		}
		break;

		case 6://For case 6 we will remove all elements from our vector
		{

			if (vector2.empty())//if the vector is empty then the program will display the message below and the program will return to the vector menu
			{

				cout << "\n\tTHE CURRENT VECTOR IS EMPTY\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

			vector2.clear();//we will call clear function in order to clear vector from all elements

			cout << "\n\tTHE VECTOR WILL BE CLEARED OF ALL ELEMENTS.\n";

			cout << endl;

			system("pause");

			system("cls");
		
		
		}
		break;

				
		}
	
		
	} while (true);

}

//Precondition none
//Postcondition: For this part of the exam we will create/instantiate a list object that will integer data inputs
//We will use a Rational class object in order to create rational numbers that will be inputted into our list
//Our program will allow the user to add elements to the lise, it will also allow the user to insert, remove and display elements from the list
void ListpartL()
{

	system("cls");
	Rational list1;//we will create/instantiate a Rational list1 object 
	list<Rational> list2;//we will create/instantiate a list object

	do //we will use this do while loop in order to perform all cases of the list section of our exam
	{

	beginning:

		system("cls");
		

		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);//we will call Handle function in order to add color to our list description paragraph

		SetConsoleTextAttribute(color, 5); cout << " " << endl;
		cout << "\tLISTS ARE SEQUENCE CONTAINERS THAT ALLOW NON-CONTIGUOUS MEMORY ALLOCATION. AS COMPARED TO\n" <<
			"\t" << "VECTOR, THE LIST HAS SLOW TRAVERSAL, BUT ONCE A POSITION HAS BEEN FOUND, INSERTION AND\n" <<
			"\t" << "DELETION ARE QUICKER\n";
		SetConsoleTextAttribute(color, 7);

		if (list2.empty())//if the list is empty then the message below will be displayed 
		{

			cout << "\n\tTHE CURRENT LIST IS EMPTY\n\n\n";

		}
		else//if the list is not empty then we will display the elements in the list along with the address of the list 
		{

			cout << endl;

			cout << "\tTHE CURRENT LIST CONTAINS " << list2.size() << " ELEMENTS:\n\t ";

			for (auto& value : list2)//with this for loop we will acquire the address of our list 
			{

				cout << value << " ";

			}
			
			cout << "\n\tADDRESS: " << &list2;//we will get and display the address of our list

		}

		cout << "\n\n\tLIST MENU OPTION\n";/////////////////////This is the list main menu
		cout << "\t" << string(85, char(205)) << "\n";//////////
		cout << "\t1. ADD AN ELEMENT\n";////////////////////////
		cout << "\t2. INSERT AN ELEMENT AFTER\n";///////////////
		cout << "\t3. REMOVE ELEMENT(S)\n";/////////////////////
		cout << "\t4. SORT THE ELEMENTS IN ASCENDING ORDER\n";//
		cout << "\t5. CLEAR ALL ELEMENTS\n";////////////////////
		cout << "\t" << string(85, char(205)) << "\n";//////////
		cout << "\t0. RETURN TO MAIN MENU\n";///////////////////
		cout << "\t" << string(85, char(205)) << "\n";


		switch (inputInteger("\tOPTION: ", 0, 5))//we will use this switch function to switch between all cases of our list program
		{

		case 1://For case 1 the user will be able to add new elements to the list 
		{

			cout << "\n\tINPUT A RATIONAL NUMBER TO BE ADDED...\n";

			try//try and catch will be used to throw an exception when the user inputs a zero denominator 
			{

				
				if (list2.empty())//if the list is empty we will allow the user to input elements into the list 
				{

					list1.setNumerator(inputInteger("\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will the allow user to input the numerator
					list1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow the user to input the denominator
					
					list2.push_back(list1);//we will call the push_back function to push rational numbers into the list
					cout << "\n\t" << list1 << " WILL BE ADDED TO THE EMPTY LIST.\n";//we will display this message once a rational number is added to the list

				}
				else//if the list is not empty then we will allow user to keep entering data into the list 
				{

					list1.setNumerator(inputInteger("\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will the allow user to input the numerator
					list1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow the user to input the denominator
					
					//char insert1 will be used to allow the user to choose if they want to add new elements into the list from the front or the back of the list
					char insert1 = inputChar("\tADD TO THE (F-FRONT) OR FROM THE (B-BACK): ", static_cast<string>("FB"));

					switch (insert1)//with this switch we will swutch between adding new elements from the front of the list or the back of the list 
					{

					case 'F'://if the user chooses F then we will push the new element from the front
					{
					
						list2.push_front(list1);//we will call push_front to insert new data into the front of the list

						cout << "\n\t" << list1 << " WILL BE PUSHED TO THE FRONT OF THE LIST.\n";//we will display the new list with new data
					}
					break;

					case 'B'://if the user chooses B then we will push the new elements from the back 
					{
						
						list2.push_back(list1);//We will call the push_back function in order to push data from the back of the list

						cout << "\n\t" << list1 << " WILL BE PUSHED TO THE BACK OF THE LIST.\n";//We will display the new list with new data


					}
					break;

					}

				}

			}
			catch (Rational::ZeroDenominator)//if the user inputs a zero denominator the message below will be displayed 
			{

				cout << "\n\tEXCEPTIONAL ERROR: CANNOT ADD A RATIONAL NUMBER, " << list1 << ", WITH A ZERO DENOMINATOR VALUE.\n";

			}

			cout << endl;
			system("pause");
			system("cls");

		}
		break;

		case 2://For case 2 the user will be able to insert new elements into the list before certain elements from the list or after 
		{

			cout << "\n\tINPUT A RATIONAL TO BE INSERTED...\n";
			
			if (list2.empty())//if the list empty then we will allow the user to input new data into the list 
			{

				list1.setNumerator(inputInteger("\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow the useer to input the numerator
				list1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow the user to input the denominator
				
				list2.push_back(list1);//we will call the push_back function to push new elements into the list

				cout << "\n\t" << list1 << " WILL BE INSERTED TO THE EMPTY LIST.\n";//we will display the new list with new data

				cout << endl;
				system("pause");
				system("cls");
				break;

			}

			try//try and catch will be used to throw an exception when the user inputs a zero denominator 
			{

				list1.setNumerator(inputInteger("\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow the user to input the numerator
				list1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow the user to input the denominator
				

				cout << "\n\tINPUT AN EXISTING RATIONAL NUMBER AS THE INSERT POSITION TO BE ADDED...\n";
				list1.setNumerator(inputInteger("\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow the user to input the numerator of an existing element in the list
				list1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow the user to input the denominator of an existing element in the list

				
				auto it = find(list2.begin(), list2.end(), list1);//we will traverse the list from beginning to end to find the existing element that will have a new element before it or after it

				
				if (it != list2.end())//we will use this if statement to traverse until the end of the list 
				{
					//we will allow the user to choose if they want to insert a new elment before or after an existing element from the list
					//char insert1 = inputChar("\tINSERT (B-BEFORE) or (A-AFTER) THE EXISTING ELEMENT: ", static_cast<string>("BA"));

					switch (inputChar("\tINSERT (B-BEFORE) or (A-AFTER) THE EXISTING ELEMENT: ", static_cast<string>("BA")))//with this switch function we will switch between adding the new element before or after an existing element from the list 
					{//

					case 'B'://if the user chooses B then we will display the new element before the existing element 
					{

						cout << "\n\t" << list1 << " WILL BE INSERTED BEFORE THE EXISTING ELEMENT FROM THE LIST.\n";

					}
					break;

					case 'A'://if the user chooses A then we will display the new element after the existing element 
					{

						cout << "\n\t" << list1 << " WILL BE INSERTED AFTER THE EXISTING ELEMENT FROM THE LIST.\n";

					}
					break;

					}


				}
				else//if the user input a rational number that does not exist then the message below will be displayed 
				{

					cout << "\n\t" << list1 << " CANNOT BE FOUND FROM THE IN THE LIST.\n";

				}

			

			}
			catch (Rational::ZeroDenominator)//if the user inputs a zero denominator the message below will be displayed 
			{
				cout << "\n\tEXCEPTIONAL ERROR: CANNOT ADD A RATIONAL NUMBER, " << list1 << ", WITH A ZERO DENOMINATOR VALUE.\n";

			}

			cout << endl;
			system("pause");
			system("cls");


		}
		break;

		case 3://For case 3 the user will be able to remov an element from the list 
		{
			
			if (list2.empty())//if the current list is empty then the message below will be displayed 
			{

				cout << "\n\tDELETE OPERATION CANNOT BE PERFORMED ON AN EMPTY LIST.\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

			cout << "\n\tINPUT A RATIONAL NUMBER TO BE REMOVED...\n";

			try//try and catch will be used to throw an exception when the user inputs a zero denominator 
			{

				list1.setNumerator(inputInteger("\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow the user to enter the numerator
				list1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow the user to enter the denominator

				
				auto it = find(list2.begin(), list2.end(), list1);//we will traverse the list from beginning to end to find the existing element that will be removed from the list

		
				if (it != list2.end())//we will use this if statement to traverse until the end of the list 
				{

					

					switch (inputChar("\n\tDO YOU WANT TO REMOVE (O-ONE or A-ALL) ELEMENT(S): ", static_cast<string>("OA")))
					{//we will use switch statement to switch between removing one existing or removing all existing elements that match the input of the user

					case 'O'://if the user chooses O then they will be able to remove one element from the list 
					{

						
						list2.erase(it);//we will call the erase function to delete one element from the list
						cout << "\n\t" << list1 << " WILL BE REMOVED FROM THE LIST.\n";//we will display the new list with a new element

					}
					break;

					case 'A'://if the user chooses A then they will be able to remove all existing elements from the list 
					{

						 
						int count = 0;//int count will be used in order to keep track of all elements in the vector that match the rational number that the user inputs
						
						for (auto it = list2.begin(); it != list2.end();)//we will use for loop to traverse through the entire list until the elements of choice is found 
						{
							
							if (*it == list1)//with this if statement we will find the existing element that matches the element the user inputs 
							{

								it = list2.erase(it);//if there are multiple elements that equal the input element then we will delete them all
								count++;

							}
							else 
							{

								++it;//we will keep traversing our vector

							}

						}

						cout << "\n\t" << list1 << " WILL BE REMOVED FROM THE LIST.\n";//we will display the element that will be removed from the list

					}
					break;

					}

				}
				else//if the rational number the user inputs does not exist in the list then the message below will be displayed 
				{

					cout << "\n\t" << list1 << " CANNOT BE FOUND IN THE LIST.\n";

				}

			}
			catch (Rational::ZeroDenominator)//if the user inputs a zero denominator the message below will be displayed 
			{

				cout << "\n\tEXCEPTIONAL ERROR: CANNOT A RATIONAL NUMBER, " << list1 << ", WITH A ZERO DENOMINATOR VALUE.\n";

			}

			cout << endl;
			system("pause");
			system("cls");

		}
		break;

		case 4://For case 4 the user will be able to sort all elements in ascending order 
		{

			
			if (list2.empty())//if the list empty then the message below will be displayed 
			{

				cout << "\n\tSORT OPERATION CANNOT BE PERFORMED ON AN EMPTY LIST.\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

			
			list2.sort();//we will call sort function in order to sort all elements in ascending order

			cout << "\n\tTHE LIST HAS BEEN SORTED IN ASCENDING ORDER\n";

			cout << endl;
			system("pause");
			system("cls");

		}
		break;

		case 5://For case 5 the user will be able to remove all elements from the list 
		{
			
			if (list2.empty())//if the list empty then the message below will be displayed 
			{

				cout << "\n\tCLEAR OPERATION CANNOT BE PERFORMED ON AN EMPTY LIST.\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}
			
			list2.clear();//we will call clear function in order to erase all elements from the list

			cout << "\n\tTHE LIST HAS BEEN CLEARED OF ALL ELEMENTS.\n";

			cout << endl;
			system("pause");
			system("cls");

		}
		break;

		case 0://For case 0 we will return to exam main menu 
		{

			return;

		}


		}


	} while (true);


}

//Precondition none
//Postcondition: For this part of the exam we will create a stack that will hold integer data inputs
//We will also use a Rational class object that will create our rational numbers that will go into the stack
//Our program will push and pop elements into our stack and will also display the element that is found at the top of the stack
void StackpartS()
{

	system("cls");

	Rational stack1;//we will create/instantiate a Rational stack1 class object
	stack<Rational> stack2;//we will create/instantiate a stack object
	stack<Rational> tempstack3;//we will create this second stack object which will be used to display the elements from our first stack


	do//we will use this do while loop in order to perform all cases of the stack section of our exam
	{

	begginning:

		system("cls");

		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);//we will call Handle function in order to add color to our stack description paragraph

		SetConsoleTextAttribute(color, 9); cout << " " << endl;
		cout << "\tSTACKS ARE A TYPE OF CONTAINER ADAPTORS WITH LIFO(LAST IN FIRST OUT) TYPE OF WORKING, WHERE A NEW ELEMENT\n" <<
			"\t" << "IS ADDED (PUSH) AT ONE END (TOP) AND AN ELEMENT IS REMOVED (POP) FROM THAT END ONLY. STACKS USES AN\n" <<
			"\t" << "ENCAPSULATED OBJECT OF EITHER VECTOR OR DEQUE (BY DEFAULT) OF LIST (SEQUENTIAL CONTAINER CLASS) AS IT'S \n" <<
			"\t" << "UNDERLYING CONTAINER, PROVIDING A SPECIFIC SET OF MEMBER FUNCTIONS TO ACCESS IT'S ELEMENTS\n";
		SetConsoleTextAttribute(color, 7);

		if (stack2.empty())//if the stack is empty then the message below will be displayed 
		{

			cout << "\n\tTHE CURRENT LIST IS EMPTY\n\n\n";

		}
		else//if the stack is not empty then we will display all elements from the stack 
		{

			cout << endl;
			tempstack3 = stack2;//we will set our stack2 equal to our third tempstack in order to display all elements from the stack
			
			if (stack2.size() - 1 == 0)//we will use this if statement in order to determine how many elements are in the stack 
			{

				cout << "\tTHE CURRENT STACK CONTAINS " << stack2.size() << " ELEMENTS:\n\t ";
				cout << "TOP->";
				while (!tempstack3.empty())//if the stack is not empty 
				{

					cout << " " << tempstack3.top();//we will display the top element of the stack
					tempstack3.pop();//we will call the pop function to be able to pop elements from the top of the stack

				}

			}
			

			else//if the stack contains one element or more then all elements from the stack will be displayed 
			{

				cout << "\tTHE CURRENT STACK CONTAINS " << stack2.size() << " ELEMENTS:\n\t ";
				cout << "TOP->";
				while (!tempstack3.empty())//if the stack is not empty 
				{

					cout << " " << tempstack3.top();//we will display the top element of the stack
					tempstack3.pop();//we will call the pop function to be able to pop elements from the top of the stack

				}

			}

		}


		cout << "\n\t" << string(70, char(205));
		cout << "\n\tSTACK MENU OPTION";
		cout << "\n\t" << string(70, char(205));
		cout << "\n\t1. PUSH";///////////////////Stack Main Menu
		cout << "\n\t2. TOP";////////////////////
		cout << "\n\t3. POP";////////////////////
		cout << "\n\t" << string(70, char(205));
		cout << "\n\t0. RETURN";
		cout << "\n\t" << string(70, char(205));


		switch (inputInteger("\n\tOPTION: ", 0, 6))//with this switch statement we will switch between all cases of the stack program
		{
		case 0: return; break;//for case 0 we will return to the exam main menu


		case 1://for case 1 we will push elements into our stack
		{

			cout << endl;
			cout << "\tINPUT A RATIONAL NUMBER TO BE ADDED...\n";

			try//try and catch will be used to throw an exception when the user inputs a zero denominator
			{

				stack1.setNumerator(inputInteger("\n\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow the user to input the numerator
				stack1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow the user to input the denominator

				
				stack2.push(stack1);//we will call the push function in order to push elements into our stack

				cout << "\n\t" << stack1.toString() << " WILL BE PUSHED TO THE TOP OF THE STACK.\n";//after pushing the elements into our stack we will call toString in order to display the element we are pushing into our stack

			}
			catch (Rational::ZeroDenominator)//if the user inputs a zero denominator the message below will be displayed
			{

				cout << "\n\tEXCEPTIONAL ERROR: CANNOT ADD A RATIONAL NUMBER, " << stack1.toString() << ", WITH A ZERO DENOMINATOR VALUE.\n";

			}


			cout << endl;

			system("pause");

			system("cls");


		}
		break;

		case 2://For case 2 we will display the element that is found in the top of the stack
		{


			if (stack2.empty())//if the stack is empty then the message below will be displayed
			{

				cout << "\n\tTHE CURRENT STACK IS EMPTY\n\n\n";

			}

			cout << endl;
			cout << "         " << stack2.top() << " IS AT THE TOP OF THE STACK";//we will call the top function in order to display the rational number that is found at the top of the stack
			
			cout << endl;
			cout << endl;

			system("pause");

			system("cls");


		}
		break;

		case 3://For case 3 we will pop elements from our stack
		{

			if (stack2.empty())//if the stack is empty then the message below will be displayed
			{

				cout << "\n\tTHE CURRENT STACK IS EMPTY\n\n\n";

			}

		
			stack2.pop();//we will call the pop function in order to remove elements from the top of the stack

			cout << "\n\t" << stack1.toString() << " WILL BE POPPED FROM THE STACK.\n";//we will display the rational number that id being removed


			cout << endl;

			system("pause");

			system("cls");


		}
		break;


		}


	} while (true);

}

//Precondition none
//Postcondition: For this part of the exam we will create a queue that will hold integer data inputs
//We will also use a Rational class object that will create our rational numbers that will go into the queue
//With our queue we will be able to enqueue and dequeue elements into our queue and we will display all elements from the queue
void QueuepartQ()
{

	system("cls");
	Rational queue1;//we will create/instantiate a Rational class object

	queue<Rational> queue2;//we will create/instantiate a queue object
	
	queue<Rational> queuetemp;//we will create this second queue object which will be used to display the elements from our first queue

	do //we will use this do while loop in order to perform all cases of the queue section of our exam
	{

	beginning:

		system("cls");
		

		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);//we will call Handle function in order to add color to our queue description paragraph

		SetConsoleTextAttribute(color, 2); cout << " " << endl;
		cout << "\tQUEUES ARE A TYPE OF CONTAINER ADAPTORS THAT OPERATE IN A FIRST IN FIRST OUT (FIFO) TYPE OF ARRANGEMENT.\n" <<
			"\t" << "ELEMENTS ARE INSERTED (ENQUEUED) AT THE BACK AND ARE DELETED (DEQUEUED) FROM THE FRONT. QUEUES USE AN\n" <<
			"\t" << "ENCAPSULATED OBJECT OF DEQUEUE OR LIST (SEQUENTIAL CONTAINER CLASS) AS IT'S UNDERLYING CONTAINER,\n" <<
			"\t" << "PROVIDING A SPECIFIC SET OF MEMBER FUNCTIONS TO ACCESS ELEMENTS.\n";
		SetConsoleTextAttribute(color, 7);

		if (queue2.empty())//if the queue is empty then the message below will be displayed  
		{

			cout << "\n\tTHE CURRENT QUEUE IS EMPTY\n\n\n";

		}
		else//if the queue is not empty then we will display all elements from the queue 
		{

			cout << endl;
			queuetemp = queue2;//we will set our stack2 equal to our third tempstack in order to display all elements from the stack
			
			if (queue2.size() - 1 == 0)//we will use this if statement in order to determine how many elements are in the queue 
			{

				cout << "\tTHE CURRENT QUEUE CONTAINS " << queue2.size() << " ELEMENTS:\n\t ";//we will display how many elements exist in the queue
				cout << "FRONT-> ";

				while (!queuetemp.empty())//if the queue is not empty 
				{

					cout << queuetemp.front() << " ";//we will display the front element of the queue
					queuetemp.pop();//we will call the pop function to be able to pop element from the front of the queue

				}

				cout << "<-BACK";

			}
			else 
			{

				cout << "\tTHE CURRENT QUEUE CONTAINS " << queue2.size() << " ELEMENTS:\n\t ";//we will display all elements in the queue
				cout << "FRONT-> ";

				while (!queuetemp.empty())//if the queue is not empty 
				{

					cout << queuetemp.front() << " ";//we will display the front element of the queue
					queuetemp.pop();//we will call the pop function to be able to pop element from the front of the queue

				}

				cout << "<-BACK";

			}

		}

		cout << "\n\n\tQUEUE MENU OPTIONS\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t1. ENQUEUE (PUSH FROM THE BACK)\n";////Queue Main Menu
		cout << "\t2. FRONT\n";///////////////////////////
		cout << "\t3. BACK\n";////////////////////////////
		cout << "\t4. DEQUEUED (POP FROM THE FRONT)\n";///
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t0. RETURN TO MAIN MENU\n";
		cout << "\t" << string(85, char(205)) << "\n";


		switch (inputInteger("\tOPTION: ", 0, 4))//with this switch function we will switch between all cases of our exam
		{

		case 1://for case 1 the user will be able to enqueue elements from the back into the queue 
		{

			cout << "\n\tINPUT A RATIONAL NUMBER TO BE EQUEUED...\n";

			try//try and catch will be used to throw an exception when the user inputs a zero denominator 
			{

				queue1.setNumerator(inputInteger("\tENTER A NUMERATOR(-9...9): ", -9, 9));//we will allow user to input the numerator
				queue1.setDenominator(inputInteger("\tENTER A DENOMINATOR(-9...9): ", -9, 9));//we will allow user to input the denominator
				
				queue2.push(queue1);//we will call the push function to enqueue elements into the queue
				cout << "\n\t" << queue1 << " WILL BE ENQUEUED (PUSHED) ONTO THE QUEUE.\n";//we will display the new elements in the list

			}
			catch (Rational::ZeroDenominator)//if the user inputs a zero denominator the message below will be displayed 
			{

				cout << "\n\tEXCEPTIONAL ERROR: CANNOT ADD A RATIONAL NUMBER, " << queue1 << ", WITH A ZERO DENOMINATOR VALUE.\n";

			}

			cout << endl;
			system("pause");
			system("cls");

		}
		break;

		case 2://For case 2 the user will be able to retrieve and display the element at the front of the queue 
		{

			
			if (queue2.empty())//if the queue is empty then the message below will be displayed 
			{

				cout << "\n\tNO FRONT ELEMENT CAN BE RETRIEVED FROM AN EMPTY QUEUE.\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

			
			cout << "\n\t" << queue2.front() << " IS AT THE FRONT OF THE QUEUE.\n";//we will call the front function in order to retrieve and display the front element of the queue
			cout << endl;
			system("pause");
			system("cls");

		}
		break;

		case 3://For case 3 the user will be able to retrieve and display the element at the back of the queue  
		{
			
			if (queue2.empty())//if the queue is empty then the message below will be displayed 
			{

				cout << "\n\tNO BACK ELEMENTS CAN BE RETRIEVED FROM AN EMPTY QUEUE.\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

			//going to retreive the top
			cout << "\n\t" << queue2.back() << " IS AT THE BACK OF THE QUEUE.\n";//we will call the back function in order to retrieve and display the back element of the queue
			cout << endl;
			system("pause");
			system("cls");

		}
		break;

		case 4://For case 4 the user will be able to pop/remove elements from the queue 
		{
			
			if (queue2.empty())//if the queue is empty then the message below will be displayed 
			{

				cout << "\n\tNO DEQUEUE (POP) OPERATION CAN BE PERFORMED ON AN EMPTY QUEUE.\n\n";
				system("pause");
				system("cls");
				goto beginning;

			}

		
			queue2.pop();//we will call the pop function in order to pop/remove or dequeue elements from the queue

			cout << "\n\t" << queue1 << " WILL BE DEQUEUED (POPPED) FROM THE QUEUE.\n";//we will display the new queue with removed elements

			cout << endl;
			system("pause");
			system("cls");

		}
		break;


		case 0://For case 0 we will return to the exam main menu 
		{

			return;

		}


		}


	} while (true);


}

//Precondition none
//Postcondition: We will create this image1 function in order to display the main menu designs
//The function will display designs of vectors, lists, stacks and queues in color
void image1()
{
	system("cls");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(color, 7); cout << " " << endl;
	SetConsoleTextAttribute(color, 11); cout << "\t\t\t\t\t\t\t\t    " << string(1, char(186)) << " IN/OUT " << string(1, char(186));
	SetConsoleTextAttribute(color, 10); cout << "\t\t   " << string(1, char(186)) << "   IN   " << string(1, char(186)) << endl;

	SetConsoleTextAttribute(color, 11); cout << "\t\t\t\t\t\t\t\t    " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(218)) << string(4, char(196)) << string(1, char(191)); SetConsoleTextAttribute(color, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(color, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(218)) << string(4, char(196)) << string(1, char(191)); SetConsoleTextAttribute(color, 10); cout << " " << string(1, char(186)) << endl;

	SetConsoleTextAttribute(color, 11); cout << "\t\t\t\t\t\t\t\tTOP" << string(1, char(175)) << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(179)) << " 1/2" << string(1, char(179)); SetConsoleTextAttribute(color, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(color, 10); cout << "\t      REAR" << string(1, char(175)) << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(179)) << " 5/6" << string(1, char(179)); SetConsoleTextAttribute(color, 10); cout << " " << string(1, char(186)) << endl;


	SetConsoleTextAttribute(color, 11); cout << "\t\t\t\t\t\t\t\t    " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(195)) << string(4, char(196)) << string(1, char(180)); SetConsoleTextAttribute(color, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(color, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(195)) << string(4, char(196)) << string(1, char(180)); SetConsoleTextAttribute(color, 10); cout << " " << string(1, char(186)) << endl;


	SetConsoleTextAttribute(color, 7); cout << " \t" << string(1, char(218)) << string(4, char(196)) << string(1, char(194)) << string(4, char(196)) << string(1, char(194)) << string(4, char(196)) << string(1, char(191));
	SetConsoleTextAttribute(color, 7); cout << "\t" << "  " << string(1, char(218)) << string(4, char(196)) << string(1, char(191)) << " " << string(1, char(218)) << string(4, char(196)) << string(1, char(191)) << " " << string(1, char(218)) << string(4, char(196)) << string(1, char(191));
	SetConsoleTextAttribute(color, 11); cout << "\t\t    " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(179)) << " 3/4" << string(1, char(179)); SetConsoleTextAttribute(color, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(color, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(179)) << " 3/4" << string(1, char(179)); SetConsoleTextAttribute(color, 10); cout << " " << string(1, char(186));

	SetConsoleTextAttribute(color, 7); cout << "\n\t" << string(1, char(179)) << " 1/2" << string(1, char(179)) << " 3/4" << string(1, char(179)) << " 5/6" << string(1, char(179));
	SetConsoleTextAttribute(color, 14); cout << "\t" << string(1, char(218)) << string(1, char(175)); SetConsoleTextAttribute(color, 7); cout << string(1, char(179)) << " 1/2" << string(1, char(179)); SetConsoleTextAttribute(color, 14); cout << string(1, char(175)); SetConsoleTextAttribute(color, 7); cout << string(1, char(179)) << " 3/4" << string(1, char(179)); SetConsoleTextAttribute(color, 14); cout << string(1, char(175)); SetConsoleTextAttribute(color, 7); cout << string(1, char(179)) << " 5/6" << string(1, char(179));
	SetConsoleTextAttribute(color, 11); cout << "\t\t    " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(195)) << string(4, char(196)) << string(1, char(180)); SetConsoleTextAttribute(color, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(color, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(195)) << string(4, char(196)) << string(1, char(180)); SetConsoleTextAttribute(color, 10); cout << " " << string(1, char(186));

	SetConsoleTextAttribute(color, 7); cout << "\n\t" << string(1, char(192)) << string(4, char(196)) << string(1, char(193)) << string(4, char(196)) << string(1, char(193)) << string(4, char(196)) << string(1, char(217));
	SetConsoleTextAttribute(color, 7); cout << "\t" << string(1, char(179)) << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217)) << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217)) << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217));
	SetConsoleTextAttribute(color, 11); cout << "\t\t    " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(179)) << " 5/6" << string(1, char(179)); SetConsoleTextAttribute(color, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(color, 10); cout << "\t     FRONT" << string(1, char(175)) << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(179)) << " 1/2" << string(1, char(179)); SetConsoleTextAttribute(color, 10); cout << " " << string(1, char(186));


	SetConsoleTextAttribute(color, 12); cout << "\n\t0    1    2"; SetConsoleTextAttribute(color, 14); cout << "\t\tHEAD";
	SetConsoleTextAttribute(color, 11); cout << "\t\t\t\t    " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217)); SetConsoleTextAttribute(color, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(color, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(color, 7); cout << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217)); SetConsoleTextAttribute(color, 10); cout << " " << string(1, char(186));




	SetConsoleTextAttribute(color, 12); cout << "\n\t(INDEX)"; SetConsoleTextAttribute(color, 14); cout << "\t\t\t(POINTER)"; SetConsoleTextAttribute(color, 11); cout << "\t\t\t    " << string(1, char(200)) << string(8, char(205)) << string(1, char(188));	SetConsoleTextAttribute(color, 10); cout << "\t\t   " << string(1, char(186)) << "  OUT   " << string(1, char(186)) << endl;


	SetConsoleTextAttribute(color, 12); cout << "\n\tVECTOR (LIST ARRAY)";  SetConsoleTextAttribute(color, 14); cout << "\t    LINKED LIST"; SetConsoleTextAttribute(color, 11); cout << "\t\t\t       STACK"; SetConsoleTextAttribute(color, 10); cout << "\t\t     QUEUE" << endl;
	SetConsoleTextAttribute(color, 7);

	cout << "\n\tA CONTAINER IS A HOLDER OBJECT THAT STORES A COLLECTION OF OTHER OBJECTS (IT'S ELEMENTS). THEY";
	cout << "\n\tARE IMPLEMENTED AS CLASS TEMPLATES, WHICH ALLOWS GREAT FLEXIBILITY IN THE TYPES SUPPORTED AS";
	cout << "\n\tELEMENTS. THE CONTAINER MANAGES THE STORAGE SPACE FOR IT'S ELEMENTS AND PROVIDES MEMBER FUNCTIONS";
	cout << "\n\tTO ACCESS THEM, EITHER DIRECTLY OR THROUGH ITERATORS (REFERENCE OBJECTS WITH SIMILAR PROPERTIES";
	cout << "\n\tTO POINTERS).\n";

}


