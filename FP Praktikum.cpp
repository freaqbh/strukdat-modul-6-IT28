#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class Untuk Animalnya
class Animal {
protected:
    string name;
    int age;
    string type;
    string dateAdded;

public:
    Animal(string name, int age, string type, string dateAdded) : name(name), age(age), type(type), dateAdded(dateAdded) {}
    virtual void displayInfo() const = 0; 
    string getName() const { return name; }
    string getType() const { return type; }
    string getDateAdded() const { return dateAdded; }
    virtual ~Animal() {}
};

// Class Untuk Dog
class Dog : public Animal {
private:
    string breed;

public:
    Dog(string name, int age, string breed, string dateAdded) : Animal(name, age, "Dog", dateAdded), breed(breed) {}
    void displayInfo() const override {
        cout << "Type: " << type << ", Name: " << name << ", Age: " << age << ", Breed: " << breed << ", Date Added: " << dateAdded << endl;
    }
    ~Dog() {}
};

//Class Untuk Cat
class Cat : public Animal {
private:
    string color;

public:
    Cat(string name, int age, string color, string dateAdded) : Animal(name, age, "Cat", dateAdded), color(color) {}
    void displayInfo() const override {
        cout << "Type: " << type << ", Name: " << name << ", Age: " << age << ", Color: " << color << ", Date Added: " << dateAdded << endl;
    }
    ~Cat() {}
};

// Class untuk Bird
class Bird : public Animal {
private:
    string species;

public:
    Bird(string name, int age, string species, string dateAdded) : Animal(name, age, "Bird", dateAdded), species(species) {}
    void displayInfo() const override {
        cout << "Type: " << type << ", Name: " << name << ", Age: " << age << ", Species: " << species << ", Date Added: " << dateAdded << endl;
    }
    ~Bird() {}
};

// Class Untuk PetAdoptionSystemnya ada Add,display,delete,update
class PetAdoptionSystem {
private:
    vector<Animal*> pets;

public:
    ~PetAdoptionSystem() {
        for (Animal* pet : pets) {
            delete pet;
        }
    }

    void addPet(Animal* pet) {
        pets.push_back(pet);
    }

    void displayPets() const {
        for (const Animal* pet : pets) {
            pet->displayInfo();
        }
    }

    void displayPetNames() const {
        if (pets.empty()) {
            cout << "No pets available." << endl;
            return;
        }
        cout << "Available pets: ";
        for (const Animal* pet : pets) {
            cout << pet->getName() << " ";
        }
        cout << endl;
    }

    void updatePet(const string& name, Animal* newPet) {
        for (int i = 0; i < pets.size(); ++i) {
            if (pets[i]->getName() == name) {
                delete pets[i];
                pets[i] = newPet;
                cout << "Pet updated successfully!" << endl;
                return;
            }
        }
        cout << "Pet not found!" << endl;
    }

    void deletePet(const string& name) {
        for (int i = 0; i < pets.size(); ++i) {
            if (pets[i]->getName() == name) {
                delete pets[i];
                pets.erase(pets.begin() + i);
                cout << "Pet deleted successfully!" << endl;
                return;
            }
        }
        cout << "Pet not found!" << endl;
    }
};

// Untuk ADD Dog 
void addDog(PetAdoptionSystem& system) {
    string name, breed, dateAdded;
    int age;
    cout << "Enter dog's name: ";
    cin >> name;
    cout << "Enter dog's age: ";
    cin >> age;
    cout << "Enter dog's breed: ";
    cin >> breed;
    cout << "Enter date added (YYYY-MM-DD): ";
    cin >> dateAdded;
    system.addPet(new Dog(name, age, breed, dateAdded));
}
// Untuk ADD Cat
void addCat(PetAdoptionSystem& system) {
    string name, color, dateAdded;
    int age;
    cout << "Enter cat's name: ";
    cin >> name;
    cout << "Enter cat's age: ";
    cin >> age;
    cout << "Enter cat's color: ";
    cin >> color;
    cout << "Enter date added (YYYY-MM-DD): ";
    cin >> dateAdded;
    system.addPet(new Cat(name, age, color, dateAdded));
}
// Untuk ADD Bird
void addBird(PetAdoptionSystem& system) {
    string name, species, dateAdded;
    int age;
    cout << "Enter bird's name: ";
    cin >> name;
    cout << "Enter bird's age: ";
    cin >> age;
    cout << "Enter bird's species: ";
    cin >> species;
    cout << "Enter date added (YYYY-MM-DD): ";
    cin >> dateAdded;
    system.addPet(new Bird(name, age, species, dateAdded));
}
// Yang ini untuk update Dog,Bird,Cat
void updatePet(PetAdoptionSystem& system) {
    system.displayPetNames();
    string name;
    cout << "Enter the name of the pet to update: ";
    cin >> name;
    cout << "1. Update Dog" << endl;
    cout << "2. Update Cat" << endl;
    cout << "3. Update Bird" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string newName, breed, dateAdded;
        int age;
        cout << "Enter dog's new name: ";
        cin >> newName;
        cout << "Enter dog's new age: ";
        cin >> age;
        cout << "Enter dog's new breed: ";
        cin >> breed;
        cout << "Enter date added (YYYY-MM-DD): ";
        cin >> dateAdded;
        system.updatePet(name, new Dog(newName, age, breed, dateAdded));
    } else if (choice == 2) {
        string newName, color, dateAdded;
        int age;
        cout << "Enter cat's new name: ";
        cin >> newName;
        cout << "Enter cat's new age: ";
        cin >> age;
        cout << "Enter cat's new color: ";
        cin >> color;
        cout << "Enter date added (YYYY-MM-DD): ";
        cin >> dateAdded;
        system.updatePet(name, new Cat(newName, age, color, dateAdded));
    } else if (choice == 3) {
        string newName, species, dateAdded;
        int age;
        cout << "Enter bird's new name: ";
        cin >> newName;
        cout << "Enter bird's new age: ";
        cin >> age;
        cout << "Enter bird's new species: ";
        cin >> species;
        cout << "Enter date added (YYYY-MM-DD): ";
        cin >> dateAdded;
        system.updatePet(name, new Bird(newName, age, species, dateAdded));
    } else {
        cout << "Invalid choice!" << endl;
    }
}
// Untuk Delete Animalnya berdasarkan namanya 
void deletePet(PetAdoptionSystem& system) {
    system.displayPetNames();
    string name;
    cout << "Enter the name of the pet to delete: ";
    cin >> name;
    system.deletePet(name);
}
// Untuk memanggil fungsi dari ADD animalnya 
void addAnimal(PetAdoptionSystem& system) {
    int choice;
    cout << "1. Add Dog" << endl;
    cout << "2. Add Cat" << endl;
    cout << "3. Add Bird" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            addDog(system);
            break;
        case 2:
            addCat(system);
            break;
        case 3:
            addBird(system);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

int main() {
    PetAdoptionSystem system;
    int choice;

    do {
        cout << "Pet Adoption Management System" << endl;
        cout << "1. Add Animal" << endl;
        cout << "2. Display All Pets" << endl;
        cout << "3. Update Pet" << endl;
        cout << "4. Delete Pet" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAnimal(system);
                break;

            case 2:
                cout << "All pets available for adoption:" << endl;
                system.displayPets();
                break;

            case 3:
                updatePet(system);
                break;

            case 4:
                deletePet(system);
                break;

            case 5:
                cout << "Exiting the system." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

