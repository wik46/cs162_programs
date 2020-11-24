/* **************************************************************************************
 * Filename: Zoo.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Description: This file contains the Zoo class. The zoo will start out with
 * 		one empty cage. The user starts out with no animals in the Zoo
 * 		and gets a chance each round to buy at most two animals of the same
 * 		species. This will be handelled by the Auction() methos defined in
 * 		the class. 
 *  
 *
 * **************************************************************************************/

// =======================================================================================
// Note that if using this class.
// =======================================================================================
//  - The destructor will free non-NULL memory. Therefore
//  	you need to store Animal* allocated on the heap
//  	in the zoo.
// ---------------------------------------------------------------------------------------
#include "Animal.h"
#include "Bear.h"
#include "Sea_lion.h"
#include "Tiger.h"
#include "Date.h"
#include "Player.h"
#include "Zoo.h"
#include "Probability.h"

#include <cassert>
#include <iomanip>
#include <iostream>

void swap(Animal*, Animal*);
int search_adult(const Zoo&);

/* ***************************************************************************************
 * Function name: get_num_animals().
 * Description: This function will be used to return the number of animals to the zoo.
 * 		It is a constant function and will not change any variables.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the current size of the Zoo.
 * **************************************************************************************/
int Zoo::get_num_animals() const{
	return m_num_animals;
}
/* ***************************************************************************************
 * Function name: get_food_type().
 * Description: This function will be used to return the food type used by the zoo.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the foood type of the Zoo.
 * **************************************************************************************/
// This will return the food type.
const std::string& Zoo::get_food_type(){
	return m_which_food; 
}

/* ***************************************************************************************
 * Function name: Auction().
 * Description: This function is used to simulate the auction of the Zoo.
 * 		When a user enters an integer, it corresponds to the animal that they 
 * 		want to buy. 
 * 		Bear - 0, Sea_lion - 1, and Tiger - 2. 
 * Parameters: -.
 * Pre-conditions: This function will make sure that the user has sufficient funds
 * 		   before they are allowed to buy the animals.
 * Post-condtions: The user bought at most 2 animals of the same species.
 * **************************************************************************************/
///#####################
int Zoo::Auction(){
	int total_cost = 0;
	// This prompt the user to enter the type of animal that they want to buy.
	std::string msg1 = "Type of animal: Bear - 0, Sea_lion - 1, or Tiger - 2.";
	int which_animal = get_int(msg1);
	// This prompts the user on the number of animals that they want to buy.
	std::string msg2 = "How many: 0, 1, or 2.";
	int num_buy = get_int(msg2);
	// This condition will only be true if the user selected a number between
	// 0 - 2 as the type of animals as well as a number from 0 - 2 for the 
	// amount of animals that he/she purchased.
	if( (which_animal >= 0 && which_animal <= 2)
	&& (num_buy >= 0 && num_buy <= 2)){
		for(int i = 0; i < num_buy; i++){
			// This creates a new empty cage for the animals that is bought.
			++(*this);
			// The user selected to buy a Bear.
			if(which_animal == 0){
				this->m_all_animals[m_num_animals - 1] = new Bear("other", Date());
			// The user selected to buy a Sea_lion.
			}else if(which_animal == 1){
				this->m_all_animals[m_num_animals - 1] = new Sea_lion("other", Date());
			// The user selected to buy a Tiger.
			}else if (which_animal == 2){
				this->m_all_animals[m_num_animals - 1] = new Tiger("other", Date()); /// Remove default dates.
			}
			// This adds the cost of the animal to total cost.
			total_cost += this->m_all_animals[m_num_animals - 1]->get_cost();
		}
		std::cout << "\n*** Total cost of purchase: $ " << total_cost <<  std::endl << std::endl;

	}else{
		std::cout << std::endl;	
		std::cout << "I am sorry " << " [Auction player custom name]" <<
		" can you please enter an integer 0, 1, or 2. You entered " << num_buy
		<< " and " << which_animal << "." << std::endl;
		Auction();
	}
	return total_cost;
}
/* ***************************************************************************************
 * Function name: Income().
 * Description: This function will return the income generated from owning
 * 		the number of animals in the zoo.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the floating point value that is deposited into
 * 		    the player's bank account
 * **************************************************************************************/
float Zoo::Income(){
	float income = 0.0;
	// The case for an empty Zoo.
	if(this->m_all_animals[0] == NULL){
		return income;
	}else{
		for(int i = 0; i < this->m_num_animals; i++){
			// earn_revenue() returns the correct value earned of each animal.
			// The parameter is 0 becuase the bonus is handled elsewhere.
			income += this->m_all_animals[i]->earn_revenue(0);		
		}
		std::cout << std::setprecision(2);
		std::cout << std::endl << std::endl
		<< "Income earned this month excluding any bonusses: $" << income
		<< std::endl;
	}
	// This returns the total income earned by the player per round.
	return income;
}


/* ***************************************************************************************
 * Function name: Expenses().
 * Description: This function will calculate the expenses based on the base cost for the
 * 		month. It will also update the m_base member variable after each month
 * 		so that it is set for the next month. The function will accept a random
 * 		number between 80 - 120 (inclusively) and then divide it by 100 to
 * 		obtains the percentage increase or decrease in monthly food cost. 
 * 		There after it will sum up all the food cost of the animals and return
 * 		the total food cost for the month.
 * Parameters: int.
 * Pre-conditios: Assumes that there are animals inside the Zoo.
 * Post-condtitions: Returns the total food cost for the month as a float.
 * **************************************************************************************/
float Zoo::Expenses(float perc){
	// This stores the new base cost that changed with 80 - 120%.
	m_base_cost *= perc/100.0;
	// This is the float used to stored the total montly food cost.
	float total = 0.0;
	// This will determine which quality food the user buys for his/her animals.
	// The food type starts at regular each round and it will only be changed of the
	// user chooses another food type.
	float fd_type = 1;
	if(m_which_food == "premium"){
		fd_type = 2;
	}else if(m_which_food == "cheap"){
		// This is half the price of the regular food.
		fd_type = 0.5;
	}
	// Gathering the food cost totals for all my animals.
	for(int i = 0; i < m_num_animals; i++){
		//Just making sure that I am not accessing a NULL pointer.
		if((*this)[i] != NULL){
			// fd_type depends on the type of food that the user selected.
			total += ((*this)[i]->m_food_cost_mult * m_base_cost * fd_type);
		}
	}
	// Return by value.
	std::cout << "\n*** This months food cost: $" << total << std::endl << std::endl;

	return total;
}
/* ***************************************************************************************
 * Function name: Hospital()
 * Part I of Random_event().
 * Description: This function will be used when an animal gets sick.
 * 		It will accept the total of the player's bank account,
 * 		determine randomly which animal get's sick and then
 * 		bill the player automatically if he can afford it.
 * 		Else it will return 0 and the animal dies.
 * ParametersL int.
 * Pre-conditions: The function will make sure that there is at least one animal
 * 			in the Zoo.
 * Post-condtions: Returns the medical cost associated with the animal's illness.
 * 			Else return 0 if the user can't afford it.
 * **************************************************************************************/
int Zoo::Hospital(int bank_total){
	std::cout << std::setprecision(2);
	// First determine if there is at least one animal in the Zoo.
	if(this->m_all_animals[0] != NULL){
		// Case if the user can afford the medical cost.
		int i = rand() % m_num_animals;
		int medical_cost = (*this)[i]->get_sick();	
		//if((*this)[i]->is_baby()){
			// If the age is 6 months or less than it is a baby.
			// A baby cost twice ass much when they get sick.
		//	medical_cost *= 2;	
		//}
		// Output to the user.
		std::cout << "[Caution]: A " << (*this)[i]->get_type() << " of age " 
		<< (*this)[i]->get_age_months() << " is unhealthy.\nMedical attention needed!!!" 
		<< std::endl << "[Medical cost]: $ " << medical_cost << std::endl; 
		// Determine if the user can afford it.
		if(bank_total >= medical_cost){
			// The player.bank() function will subtract the expenses.
			std::cout << "[Medical bill sent, the vetenary says that the " 
			<< (*this)[i]->get_type() << " will recover quickly]." << std::endl;
			// The function will return the cost associated.
			return medical_cost;
		}else{
			std::cout << "[The vetenary reported that your  " << (*this)[i]->get_name() 
			<< " - "<< (*this)[i]->get_name() << "- , age "<< (*this)[i]->get_age_months() 
			<< " has died]." << std::endl;
			// Animal removed from the Zoo.
			// ==========================================================================
			// Bug: The function does not swap the animals so that the sick one is at the
			// end.
			swap((*this)[i], (*this)[m_num_animals - 1]);
			// ==========================================================================
			--(*this);
		}
	}
	int no_cost = 0;
	return no_cost;
}
/* ***************************************************************************************
 * Function name: babies_born()
 * Description: This funcion will be called when the second random event occurs.
 * 		It makes use of search_adult() to ensure that there is at least
 * 		one animal in the zoo that is an adult (age > 48 months) since they
 * 		are the only animals allowed to have babies.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: The function inserts the new animals babies in the array of Animal*'s
 * 		    if there is at least one adult in the Zoo. Else it will print out
 * 		    to the user that there is no animals old enough to deliver a baby.
 * ***************************************************************************************/
void Zoo::babies_born(){
	// This get's the index of the random adult selected to give babies.
	// If there is no adults on the zoo, search_adult() will return -1.
	int i = search_adult((*this));
	if(i > -1){
		std::cout << "*** A total of " <<(*this)[i]->give_birth() 
		<< " new babies are born." << std::endl;
		// give_birth() returns the number of babies that the animal delivers.
		for(int j = 0; j < (*this)[i]->give_birth(); j++){
			// This creates space in the Zoo for the new born.
			++(*this);				
			if( (*this)[i]->get_type() == "Bear"){
				// The last element in the array that stores the animals is empty.
				// #### Remove default date and change to current date.
				this->m_all_animals[m_num_animals - 1] = new Bear("zoo", Date());
			}else if( (*this)[i]->get_type() == "Sea lion"){
				// The last element in the array that stores the animals is empty.
				// #### Remove default date and change to current date.
				this->m_all_animals[m_num_animals - 1] = new Sea_lion("zoo", Date());
			}else if( (*this)[i]->get_type() == "Tiger"){
				// The last element in the array that stores the animals is empty.
				// #### Remove default date and change to current date.
				this->m_all_animals[m_num_animals - 1] = new Tiger("zoo", Date());
			}else{
				std::cout << "[babies_born()]: Error, no type for animal exist" 
				<< std::endl;
			}
		}
	}else{
		std::cout << "\n[There is no animal old enough to deliver babies.]\n"<< std::endl;
	
	}
	return;
}

/* ***************************************************************************************
 * Function name: attendence_boom().
 * Part III of Random_event().
 * Description: This function will be called when there is a boom in attendence
 * 		and the Sea lions generate extra profit. It will tell the user
 * 		that there was a boom in attendance but because he/she had no Sea lion,
 * 		the user did not receive additinal funds.
 * Pre-conditions: Will be used inside the Random_events() function.
 * Post-condtions: Returns the number of additional income generated from a
 * 			boom in attendence.
 * **************************************************************************************/
int Zoo::attendance_boom(){
	for(int i = 0; i < m_num_animals; i++){
		// Makes sure that I dont access a NULL pointer.
		if((*this)[i] != NULL){
			// If the animal in the array is a Sea lion.
			if(( (*this)[i]->m_type) == "Sea lion"){
				return (*this)[i]->calc_boom_total();
			}
		}	
	}
	// This is if there are no Sea lions in the Zoo.
	std::cout << std::endl
	<< "You had a boom in the attendance at the Zoo but becuase you do " <<
	"\nnot have any sea lions, you did not receive additional funds." << std::endl;
	return 0;
}

/* ***************************************************************************************
 * Function name: Random_events().
 * Description: This function will make use of a reference to instances of
 * 		the Player class and the Probability class. It will execute the random
 * 		event based on the probability of each one of them. This function will 
 * 		get called once per round and it simulates 4 random events that can occur
 * 		during a single round.
 * 		0 - An animal gets sick and the user needs to pay the medical bill, 
 * 		1 - A randomly selected adult gives birth to the x number of babies,
 * 		2 - An increase in attendance of the Zoo, Sea lions produce more revenue,
 * 		3 - No special event occurs.
 * Parameters: Player&, const Probability&.
 * Pre-conditions: The function will execute once per round.
 * Post-conditions: The funcion will simulate one of the 4 events possible for each 
 * 		    round.
 * **************************************************************************************/
void Zoo::Random_events(Player& player, const Probability& p){
	std::cout << std::setprecision(2);
	std::cout << "************************************************************"<<
	"***********" << std::endl;
	// Returns an integer between 0 - 3, inclusively.
	const int event = p.get_event();
	if(event == 0){	
		// This is when an animal turns ill.
		player.get_bank() -= this->Hospital(player.get_bank());
	}else if(event == 1){
		// This is when a new babies is born in the Zoo.
		this->babies_born();
	}else if(event == 2){
		// This is when there is an increase in attendence and the Sea lions 
		// produce more income.
		std::cout << "There was a great increase in attendance at the Zoo." 
		<< std::endl;
		player.get_bank() += this->attendance_boom();
	}else if(event == 3){	
		// No special event occured.
		std::cout << "\nNothing interesting happend this round.\n" << std::endl;
	}
	std::cout << "[current total:] $ " << player.get_bank() << std::endl;
	std::cout << "************************************************************"<<
	"***********" << std::endl;
	return;
}
/* ***************************************************************************************
 * Function name: x_month_older().
 * Description: This function will increase the age of all the animals in the
 * 		zoo by one the integer specified as as the argument of the function.
 * Parameters: int.
 * Pre-conditions: The function will default to one month increase.
 * 		   The function will determined if there is at least one animal in the
 * 		   zoo before trying to increase the animals' age.
 * Post_conditions: All the animals in the Zoo are x months older.
 * **************************************************************************************/
void Zoo::x_month_older(int num_month){
	// This is so when the Zoo is empty.
	if((*this)[0] == NULL){
		return;
	}
	assert(num_month > 0 && "Make sure that you increase the age by at least one.");
	// Case when the Zoo has at least one animal.
	for(int i = 0; i < this->m_num_animals; i++){
		this->m_all_animals[i]->get_age_months() += num_month;
	}
}


/* ***************************************************************************************
 * Function name: which_food().
 * Description: This function will set the food type that the user selects for its animals.
 * 		- "Cheap": Half of base price.
 * 		- "Regular": Base price.
 * 		- "Preimium": Double of base price.
 * Parameters: -
 * Pre-conditions: This funcion only changes the m_which_food variable.
 * Post-conditions: The type of food used in the Zoo is set.
 * **************************************************************************************/
void Zoo::which_food(){
	std::cout << std::endl
	<< "Please select the type of food that you want to feed your "<< this->m_num_animals
	<< " animals.\n\n" 
	<< "a.) Cheap - 1: Price is half of the base price but it will increase the" <<
	" probability of getting sick animals.\n" 
	<< "b.) Regular - 2: Price is the base price" <<
	" probability of getting sick animals is not affected.\n" 
	<< "c.) Premium - 3: Price is double of the base price but it will decrease the" <<
	" probability of getting sick animals." << std::endl;
	std::string tmp = "";
	std::cin >> tmp;
	if(tmp == "1"){
		m_which_food = "cheap"; 
	}else if(tmp == "2"){
		m_which_food = "regular"; 
	}else if(tmp == "3"){
		m_which_food = "premium"; 
	}else{
		std::cout << std::endl << std::endl
		<< "Please enter an integer between 1 - 3 to select you food choice.\n"
		<< std::endl << std::endl;
		this->which_food();
	}
	return;
}
/* ***************************************************************************************
 * Function name: operator[]().
 * Description: This function will return a reference to an Animal* becuase
 * 		I don't know which inhereted class will be needed by the program.
 * 		This function will be private because if a user does not store
 * 		dynamic memory in the array of animals the destructor will try to
 * 		free it which will lead to a seg fault.
 * Parameters: int.
 * Pre-conditions: Assumes that there are animals in the Zoo but the function
 * 		   will use assert to determine it.
 * Post-conditions: The subscript operator returns a reference to the
 * 		    Animal* at the index specified.
 * **************************************************************************************/
Animal*& Zoo::operator[](int i){
	assert(i >= 0 
	&& "[operator[]()]: The Zoo does not have negative indices");
	// The program should not try to access an animal that is not there.
	//assert(m_all_animals[i] = NULL 
	//&& "[operator[]()]: There is no animal at the index you specified.");
	// m_all_animals is an array of Animal*. Therefore by deferencing the
	// pointer, the function returns a reference to the instance of an Animal.
	return m_all_animals[i];
}
/* ***************************************************************************************
 * Function name: operator[]().
 * Description: This function will return an Animal* becuase
 * 		I don't know which inhereted class will be needed by the program.
 * 		This function will be private because if a user does not store
 * 		dynamic memory in the array of animals the destructor will try to
 * 		free it which will lead to a seg fault.
 * Parameters: int.
 * Pre-conditions: Assumes that there are animals in the Zoo but the function
 * 		   will use assert to determine it.
 * Post-conditions: The subscript operator returns a
 * 		    Animal* at the index specified.
 * **************************************************************************************/
Animal* Zoo::operator[](int i) const{
	assert(i >= 0 
	&& "[operator[]()]: The Zoo does not have negative indices");
	// The program should not try to access an animal that is not there.
	//assert(m_all_animals[i] = NULL 
	//&& "[operator[]()]: There is no animal at the index you specified.");
	// m_all_animals is an array of Animal*. Therefore by deferencing the
	// pointer, the function returns a reference to the instance of an Animal.
	return m_all_animals[i];
}


/* ***************************************************************************************
 * Function name: operator++().
 * Description: This function will increase the size of the Zoo by 1.
 * 		I will only define the pre-increment operator.
 * Parameters: -
 * Input: The user wants one extra cage in the Zoo.
 * Ouput: The Animal** array is increase by a size of 1.
 * **************************************************************************************/
Zoo& Zoo::operator++(){
	// If is is the empty Zoo then there is on need to increment it.
	if(this->m_all_animals[0] == NULL){
		return (*this);
	}
	// We create the new array of size + 1.
	Animal** tmp_ar = new Animal*[m_num_animals + 1];
	// Now we save all the data into the new array.
	for(int i = 0; i < m_num_animals; i++){
		tmp_ar[i] = this->m_all_animals[i];
	}
	// Now we increment the size of the current size of the Zoo.
	m_num_animals++;
	// Now I can free the old memory.
	delete[] this->m_all_animals;
	// And lastly I put all the animals in the Zoo with the extra cage.
	this->m_all_animals = tmp_ar;
	// Let us set the new element equal to NULL so that the destructor won't
	// free it.
	this->m_all_animals[m_num_animals - 1] = NULL;
	// We return the object with an increase of cages/elements of one.
	return (*this);
	
}
/* ***************************************************************************************
 * Function name: operator--().
 * Description: This function will be used to remove the last element
 * 		in the array of Animal*. It will free the memory and
 * 		decrement the size of the array by one.
 * Parameters: -.
 * Pre-conditions: This function makes sure that there is an element in the array before 
 * 			freeing the memory.
 * Post-conditions: - 
 * **************************************************************************************/
Zoo& Zoo::operator--(){
	// The array will always have one element.
	if(this->m_all_animals[0] != NULL){
		Animal** tmp = new Animal*[this->m_num_animals - 1];
		for(int i = 0; i < m_num_animals - 1; i++){
			tmp[i] = this->m_all_animals[i];
		}
		// Now the last element.
		delete m_all_animals[m_num_animals - 1];
		delete[] this->m_all_animals;
		// Now I set the smaller array equal to
		this->m_all_animals = tmp;
		// Decreasing the size of the array by one.
		this->m_num_animals--;
	}else{
		return (*this);
	}
}

/* ***************************************************************************************
 * Function name: operator<<().
 * Description: This is a friend function. Therefore it has access to the private 
 * 		members of the Zoo class but itseld is not a member of the class.
 * Parameters: std::ostream&, const Zoo&.
 * Input: An instace of a Zoo object.
 * Output: All the information currently avalable regarding the Zoo is printed to the 
 * 		screen.
 * **************************************************************************************/
// ##### In progress #####.
std::ostream& operator<<(std::ostream& stream_out, const Zoo& zoo){ 
	stream_out << std::setprecision(3) << std::left;
	stream_out << std::endl;
	stream_out << "-------------------------------------------------------------" 
	<< std::endl;
	stream_out << std::setw(12) << "| Id-number" 
	<< std::setw(12) << "Name " << 
	std::setw(12) << "Type"<< std::setw(7) << "Age" <<
	std::setw(15)<< "Birth Place |" << std::endl;
	stream_out << "-------------------------------------------------------------" 
	<< std::endl;
	for(int i = 0; i < zoo.m_num_animals; i++){
		if(zoo.m_all_animals[i] != NULL){
			std::cout << *(zoo.m_all_animals[i]) << std::endl;	
		}
	}

	stream_out << "-------------------------------------------------------------" 
	<< std::endl;
	return stream_out;
}

/* *******************************************************************************+*******
 * Function name: Zoo().
 * Description: This is the constructor for the Zoo class. An user must create a Zoo of
 * 		at least one empty cage. An empty cage will be represented by a NULL 
 * 		Animal pointer.
 * Parameters: int ( =1 by default).
 * Input: The size of the Zoo that is created.
 * Output: A Zoo that stores an array of Animal*'s is created.
 * **************************************************************************************/
// The initial base cost is $80.
Zoo::Zoo(int size): m_num_animals(size), m_base_cost(80), m_which_food("regular")
{
	// This makes sure that the Zoo is intantiaed with at least one
	// instance in the array/
	assert(m_num_animals > 0
	&& "[Zoo()]: A zoo must be created with at least one empty cage.");
	// Create an array to store different animals.
	m_all_animals = new Animal*[m_num_animals];
	// Set all the Animal* to NULL.
	for(int i = 0; i < m_num_animals; i++){
		// This is so that I freed only non-NULL data.
		m_all_animals[i] = NULL;
	}
}
	
/* *******************************************************************************+*******
 * Function name: ~Zoo().
 * Description: The Zoo class destructor. The purpose of the Zoo class destructor is to
 * 		free the memory used by the Animal** m_all_animals. Not that at each
 * 		element in the array of Animal*, the memory is dynamically allocated.
 * 		Therefore we first need to free all the Animals before freeing the cage.
 * Parameters: -
 * Input: -
 * Output: All dynamic memory used by the program is freed accordingly.
 * **************************************************************************************/
Zoo::~Zoo(){
	// This will clean up all the memory used by the class.
	for(int i = 0; i < m_num_animals; i++){
		// Freeing all the animals.
		if(m_all_animals[i] != NULL){
			delete m_all_animals[i];
		}
	}
	// Then you can delete the cage.
	delete[] m_all_animals;
}

/* ***************************************************************************************
 * Function name: operator=().
 * Description: Because my class makes used of dynamic memory, I need to define
 * 		my own overloaded assignment operator. This will do a deep copy from
 * 		one class to another.
 * Parameters: const Zoo&.
 * Pre-conditions: Assumes that the instance of a Zoo from where the data will be copied
 * 		   is already initialized.
 * Post-conditions: Implements a deep copy.
 * **************************************************************************************/
Zoo& Zoo::operator=(const Zoo& old_z){
	if(this == &old_z){
		// Checking for self assignment.
		return *this;
	}
	if(old_z.m_all_animals != NULL){
		this->m_base_cost = old_z.m_base_cost;
		assert(old_z.m_num_animals > 0);
		this->m_num_animals = old_z.get_num_animals();
		for(int i = 0; i < this->m_num_animals; i++){
			this->m_all_animals[i] = old_z.m_all_animals[i];
		}
	}
	return *this;
}

// =======================
// Non-member functions.
// =======================
/* ***************************************************************************************
 * Function name: swap()
 * Description: This is not a member function but it is used inside the Hospital()
 * 		function to swap around two Animal*'s.
 * Parameters: Animal*, Animal*.
 * Pre-conditions: -
 * Post-conditions: Swaps the position of two Animals*'s in the array.
 * **************************************************************************************/
void swap(Animal* a1, Animal* a2){
	Animal* tmp = a1;
	a1 = a2;
	a2 = tmp;
	return;
}
/* ***************************************************************************************
 * Function name: search_adult()
 * Description: This function will randomly search thorught the Animal* array and return
 * 		the index of an adult. It will return -1 if there is no adult in the Zoo.
 * Parameters: const Zoo&.
 * Pre-condtions: The function makes no assumptions on the animals present in the Zoo.
 * Post-conditions: It returns the index of the Animal* pointer that is an adult.
 * ***************************************************************************************/
int search_adult(const Zoo& zoo){
	// This is when there is an empty Zoo.
	if( (zoo[0]) == NULL){
		return -1;
	}
	// This make sure that there is at least one adult in the Zoo to give birth.
	bool adult_exist = 0;
	for(int i = 0; i < zoo.get_num_animals(); i++){
		if( (zoo[i])->is_adult() ){
			adult_exist = 1;
			break;
		}	
	}
	// This will randomly search for a animal in the Zoo that can give birth.
	int i = -1;
	// The if statement will only execute if there was an adult found.
	if(adult_exist){
		do{
			i = rand() % zoo.get_num_animals();
		// The loop will stop if the randomly selected animal is an adult.	
		}while( !( (zoo[i])->is_adult() ) );
	}
	// The funcion will return -1 if there was no adult to give birth.
	// Otherwise it will return the index of the animal that will give birth.
	return i;
}
