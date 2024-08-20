#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// User profile structure
struct User {
  string name;
  vector<string> friends;
};

// Hash table to store users
unordered_map<string, User> users;

// Function to create a new user profile
void createUser(const string& name) {
  if (users.count(name) > 0) {
    cout << "User with name '" << name << "' already exists." << endl;
    return;
  }

  users[name] = {name, {}};
  cout << "User '" << name << "' created successfully." << endl;
}

// Function to add a friend connection
void addFriend(const string& user1, const string& user2) {
  if (users.count(user1) == 0 || users.count(user2) == 0) {
    cout << "One or both users don't exist." << endl;
    return;
  }

  users[user1].friends.push_back(user2);
  users[user2].friends.push_back(user1);
  cout << user1 << " and " << user2 << " are now friends." << endl;
}

// Function to view a user's profile
void viewProfile(const string& name) {
  if (users.count(name) == 0) {
    cout << "User '" << name << "' not found." << endl;
    return;
  }

  const User& user = users[name];
  cout << "Name: " << user.name << endl;
  if (user.friends.empty()) {
    cout << "No friends yet." << endl;
  } else {
    cout << "Friends:" << endl;
    for (const string& friendName : user.friends) {
      cout << "- " << friendName << endl;
    }
  }
}

// Function to search for users based on name (simple prefix search)
void searchUsers(const string& prefix) {
  cout << "Search results for '" << prefix << "':" << endl;
  for (const auto& userPair : users) {
    if (userPair.first.find(prefix) == 0) {
      cout << "- " << userPair.first << endl;
    }
  }
}

int main() {
  int choice;

  while (true) {
    cout << "\nMenu:" << endl;
    cout << "1. Create User" << endl;
    cout << "2. Add Friend" << endl;
    cout << "3. View Profile" << endl;
    cout << "4. Search Users" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        string name;
        cout << "Enter username: ";
        cin >> name;
        createUser(name);
        break;
      }
      case 2: {
        string user1, user2;
        cout << "Enter username of first user: ";
        cin >> user1;
        cout << "Enter username of second user: ";
        cin >> user2;
        addFriend(user1, user2);
        break;
      }
      case 3: {
        string name;
        cout << "Enter username to view profile: ";
        cin >> name;
        viewProfile(name);
        break;
      }
      case 4: {
        string prefix;
        cout << "Enter username prefix to search: ";
        cin >> prefix;
        searchUsers(prefix);
        break;
      }
      case 5:
        cout << "Exiting..." << endl;
        return 0;
      default:
        cout << "Invalid choice." << endl;
    }
  }

  return 0;
}
