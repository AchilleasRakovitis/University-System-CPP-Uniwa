#include <iostream>
#include <cstring>

void addString(const char*&, char **&, int& );
void printStrings(char**, const int& );
void deleteString(const char *&, char **&, int& );

using namespace std;

int main(){
	
    char **strng = nullptr;
    int size = 0; // size of the original array 

    // strings for testing
    const char *str1 = "I like Cpp";
    const char *str2 = "Lab Cpp 2025";
    const char *str3 = "Achilleas Rakovitis";
    const char *str4 = "AM 19390200";
    const char *str5 = "Exercise 2 with pointers dynamic memory with new and delete ";

    cout << endl;

    printStrings(strng, size); //call the function that prints the Strings
			    

    cout << endl; 

    addString(str1, strng, size); //call the function that adds a string
    addString(str3, strng, size); 

    cout << "Πρόσθεσα 2 strings:" << endl;
    printStrings(strng , size);

    cout << endl;

    cout << "Προσπάθησα να προσθέσω string που υπάρχει ήδη " << endl;
    addString(str3, strng, size); //here i add a string that already exists 

    addString(str2, strng, size);

    cout << "\nΠρόσθεσα ακόμα ένα string:" << endl; 
    printStrings(strng, size);
	
    cout << endl;

    deleteString(str3, strng, size); // call the function that deletes a string 
    deleteString(str1, strng, size);

    cout << "Διέγραψα 2 Strings:" << endl;
    printStrings(strng, size);

    cout << endl;

    
    addString(str4, strng, size);
    addString(str5, strng, size);

    cout << "Πρόσθεσα 2 νέα strings:" << endl;
    printStrings(strng, size);

    cout << endl;

    cout << "Αφαίρεσα ένα string:" << endl;
    deleteString(str4, strng, size);

    printStrings(strng, size);
    
    //deallocate memory first for each string and then for the 2d array 
    for(unsigned int i = 0; i < size; i++) {
        delete[] strng[i]; 
    }
    delete[] strng;   

    return 0;
}

void addString(const char *&newString, char **&strng, int& size) {
    int flag = 0; // a flag for checking if the string already exists 
    int flag_pos = 0; // index of the already found string
    
    //check if the string already exists
    for(unsigned int i = 0; i < size; i++) {
        if(strcmp(strng[i], newString) == 0) { // if the strings are the same 
            flag = 1; // change flag
            flag_pos = i; // flag_pos gets the value of index i of the string that already exists
        }
    }
    
    if(flag == 1) {
        cout << "Η συμβολοσειρά υπάρχει ήδη στην θέση: " << flag_pos + 1 << endl;
	cout << "Η συμβολοσειρά είναι η εξής: " <<  strng[flag_pos] << endl;
        return; //exit the function without adding the new string
    }
    
    //create a new temp array to copy the existing one
    char **nArray = new char*[size + 1]; 
    
    for(unsigned int i = 0; i < size; i++) {
        nArray[i] = new char[strlen(strng[i]) + 1]; // create the char* that holds each string (compute the size and allocate memory of each string)
        strcpy(nArray[i], strng[i]); // copy each string to the new temp array
    }
    
    nArray[size] = new char[strlen(newString) + 1]; // allocate the memory for the new string to be added
    strcpy(nArray[size], newString); // copy the string to the allocated memory
    
    // deallocate the memory first for each string array and then for the 2d array
    if(strng != nullptr) {
        for(unsigned int i = 0; i < size; i++) {
            delete[] strng[i];
        }
        delete[] strng;
    }
    
    //assign the original array pointer to point to the new array and increment size
    strng = nArray;
    size++;
} 
     
void deleteString(const char *&delString, char **&strng, int&size){

    char **nArray = new char*[size - 1]; // create a new temp array that will hold the new array with the deleted string 

    int copyIndex = 0; // use a new variable to keep track of the indexing while deleting a string

    for(unsigned int i = 0; i < size; i++){
        if(strcmp(strng[i], delString) != 0){ // if the strings are not equal 
            if(copyIndex < size - 1){ // if the new index is not out of bounds 
	        nArray[copyIndex] = new char[strlen(strng[i]) + 1]; // allocate memory for the string to be copied 
                strcpy(nArray[copyIndex], strng[i]); // copy the string to the temp array 
                copyIndex++; // increment index to keep track of the new array index 
            }
	}
    }
    //deallocate memory as before 
    if(strng != nullptr){
        for(unsigned int i = 0; i < size; i++) {
        delete[] strng[i];
    }

    delete[] strng;
  }
  // decrement size and assign the pointer of the original array to the new created array 
  size--;
  strng = nArray;

}

void printStrings(char** strng, const int& size){
    if(strng != nullptr){ // if the array is not empty print each string of the array 
    for(unsigned int i = 0; i < size; i++){
        cout << "Συμβολοσειρά " << i + 1 << ": " << strng[i] << endl;
    }
}else{
    cout << "Ο πίνακας των συμβολοσειρών είναι κενός " << endl; // if its empty print this message
}

}
